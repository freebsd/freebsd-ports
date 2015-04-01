# $FreeBSD$

PREFIX?=	/usr/local
BINDIR?=	${PREFIX}/bin

MAN=

.PATH: ${.CURDIR}/..

CFLAGS+=	-I${.CURDIR}/.. -I${.CURDIR}
LDADD=	${.CURDIR}/../libpd/libpd.a -lpthread -lpcap
