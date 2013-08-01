/*
 * This file is in the public domain.
 *
 * $FreeBSD$
 */

#ifndef SA_LEN
# define SA_LEN(x)	((x)->sa_len)
#endif

#ifndef EAI_NODATA
# define EAI_NODATA	EAI_NONAME
#endif

#ifndef __dead
# define __dead
#endif

#undef HAVE_SENSORS

/* adjfreq.c */
int			adjfreq(const int64_t *, int64_t *);
