#	$NetBSD: Makefile,v 1.1.1.1 2001/03/06 11:21:04 agc Exp $
#	$FreeBSD$

# When adding new digest algorithms, please use rmd160 as the template,
# and bump the version definition in the package Makefile

PROG= digest
SRCS= digest.c
CPPFLAGS+= -I${.CURDIR}
LDFLAGS= -L${LOCALBASE}/lib -lmd
WARNS= 2

.if !exists(/usr/include/rmd160.h)
SRCS+= rmd160.c rmd160hl.c
.endif

.if !exists(/usr/include/sha1.h)
SRCS+= sha1.c sha1hl.c
.endif

.if !exists(/usr/include/md5.h)
SRCS+= md5c.c md5hl.c
.endif

# use definition for correct endian.h header file
.if exists(/usr/include/sys/endian.h)
CPPFLAGS+= -DHAVE_SYS_ENDIAN_H_
.endif
.if exists(/usr/include/machine/endian.h)
CPPFLAGS+= -DHAVE_MACHINE_ENDIAN_H_
.endif

LDSTATIC?=      -static

.include <bsd.prog.mk>
