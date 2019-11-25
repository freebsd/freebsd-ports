# $FreeBSD$

PROG=	fixrtf
SRCS=	fixrtf.l

PREFIX?=	/usr/local
BINDIR=	${PREFIX}/bin
CFLAGS+=-I${PREFIX}/include
LDADD=	-L${PREFIX}/lib -lpng
MAN=

.include <bsd.prog.mk>
