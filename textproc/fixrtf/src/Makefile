# $FreeBSD$

PROG=	fixrtf
SRCS=	fixrtf.l

PREFIX?=	/usr/local
BINDIR=	${PREFIX}/bin
CFLAGS+=-I${PREFIX}/include
LDADD=	-L${PREFIX}/lib -lpng
NO_MAN=
NOMAN=

.include <bsd.prog.mk>
