/*
 * Copyright (c) 2000, 2001, 2002
 * Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 * $FreeBSD
 */


#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#ifdef HAVE_SYS_PARAM_H
#  include <sys/param.h>
#endif

#include <stdlib.h>

#  include <pthread.h>

/*
 * Use a mutex under BSD systems to avoid problems with semaphores
 * blocking all the threads since BSD have MIT pthreads user space
 * threads. If not BSD, use some stubs that do nothing. Since these
 * stubs are empty, most modern compilers will simply add a NOP at
 * the calling point.
 */
#  if (defined(BSD) && (BSD >= 199103))
int
lp_mutex_init_ (pthread_mutex_t ** mutex, 
		const pthread_mutexattr_t *attr)
{
	pthread_mutex_t	* mutex_temp;
	
	if ( (mutex_temp = \
			(pthread_mutex_t *) malloc (sizeof(pthread_mutex_t))) ) {
	
		if ( (pthread_mutex_init(mutex_temp, attr)) == 0) {

			(*mutex) = mutex_temp;
			return (1);
		} else {
			return (0);
		}
	} else {
		/* Not enough memory */
		return (-1);
	}
}

int
lp_mutex_lock_ (pthread_mutex_t	* mutex)
{
	if ( (pthread_mutex_lock(mutex)) == 0) {
		return (1);
	} else {
		return (0);
	}
}

int
lp_mutex_unlock_ (pthread_mutex_t * mutex)
{
	if ( (pthread_mutex_unlock(mutex)) == 0) {
		return (1);
	} else {
		return (0);
	}
}

int
lp_mutex_destroy_ (pthread_mutex_t ** mutex)
{
	if ( (pthread_mutex_destroy(*mutex)) == 0) {
		free (*mutex);
		return (1);
	} else {
		return (0);
	}
}

#  else	/* !(defined(BSD) && (BSD >= 199103)) */

int
lp_mutex_init_ (pthread_mutex_t ** mutex, 
		const pthread_mutexattr_t *attr) {}

int
lp_mutex_lock_ (pthread_mutex_t	* mutex) {}

int
lp_mutex_unlock_ (pthread_mutex_t * mutex) {}

int
lp_mutex_destroy_ (pthread_mutex_t ** mutex) {}

#  endif	/* (defined(BSD) && (BSD >= 199103)) */
