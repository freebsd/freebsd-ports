#	$NetBSD: Makefile,v 1.6 2001/03/29 08:42:14 agc Exp $
#	$FreeBSD$

# When adding new digest algorithms, please use rmd160 as the template,
# and bump the version definition in the package Makefile

PROG= digest
SRCS= digest.c
CFLAGS+= -I${.CURDIR} -DVERSION="${VERSION}"
#WARNS= 2

SRCS+= rmd160.c rmd160hl.c

SRCS+= sha1.c sha1hl.c

.if !exists(/usr/include/sha2.h)
SRCS+= sha2.c sha2hl.c
.endif

.if !exists(/usr/include/md5.h) || (${OPSYS} == SunOS)
SRCS+= md5c.c md5hl.c
.else
LDADD+= -lmd
.endif

# use definition for correct endian.h header file
.if exists(/usr/include/sys/endian.h)
CPPFLAGS+= -DHAVE_SYS_ENDIAN_H_
.endif
.if exists(/usr/include/machine/endian.h)
CPPFLAGS+= -DHAVE_MACHINE_ENDIAN_H_
.endif

.if (${OPSYS} == SunOS)
NOMAN=		YES
.else
LDSTATIC?=      -static
.endif

.include <bsd.prog.mk>
