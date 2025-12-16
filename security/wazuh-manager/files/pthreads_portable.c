/*-
 * SPDX-License-Identifier: BSD-2-Clause
 *
 * Copyright (c) 2025 J. Cardenas Marquez <acm@FreeBSD.org>
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
 */

#include "pthreads_portable.h"

int portable_rwlock_init(portable_rwlock_t *rw) {
    if (pthread_mutex_init(&rw->lock, NULL) != 0) return -1;
    if (pthread_cond_init(&rw->readers_ok, NULL) != 0) return -1;
    if (pthread_cond_init(&rw->writers_ok, NULL) != 0) return -1;
    rw->active_readers = 0;
    rw->waiting_writers = 0;
    rw->writer_active = 0;
    return 0;
}

int portable_rwlock_rdlock(portable_rwlock_t *rw) {
    if (pthread_mutex_lock(&rw->lock) != 0) return -1;
    while (rw->writer_active || rw->waiting_writers > 0) {
        if (pthread_cond_wait(&rw->readers_ok, &rw->lock) != 0) {
            pthread_mutex_unlock(&rw->lock);
            return -1;
        }
    }
    rw->active_readers++;
    return pthread_mutex_unlock(&rw->lock);
}

int portable_rwlock_rdunlock(portable_rwlock_t *rw) {
    if (pthread_mutex_lock(&rw->lock) != 0) return -1;
    rw->active_readers--;
    if (rw->active_readers == 0 && rw->waiting_writers > 0)
        pthread_cond_signal(&rw->writers_ok);
    return pthread_mutex_unlock(&rw->lock);
}

int portable_rwlock_wrlock(portable_rwlock_t *rw) {
    if (pthread_mutex_lock(&rw->lock) != 0) return -1;
    rw->waiting_writers++;
    while (rw->writer_active || rw->active_readers > 0) {
        if (pthread_cond_wait(&rw->writers_ok, &rw->lock) != 0) {
            rw->waiting_writers--;
            pthread_mutex_unlock(&rw->lock);
            return -1;
        }
    }
    rw->waiting_writers--;
    rw->writer_active = 1;
    return pthread_mutex_unlock(&rw->lock);
}

int portable_rwlock_wrunlock(portable_rwlock_t *rw) {
    if (pthread_mutex_lock(&rw->lock) != 0) return -1;
    rw->writer_active = 0;
    if (rw->waiting_writers > 0)
        pthread_cond_signal(&rw->writers_ok);
    else
        pthread_cond_broadcast(&rw->readers_ok);
    return pthread_mutex_unlock(&rw->lock);
}

int portable_rwlock_destroy(portable_rwlock_t *rw) {
    if (pthread_mutex_destroy(&rw->lock) != 0) return -1;
    if (pthread_cond_destroy(&rw->readers_ok) != 0) return -1;
    if (pthread_cond_destroy(&rw->writers_ok) != 0) return -1;
    return 0;
}
