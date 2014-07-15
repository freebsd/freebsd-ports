# $FreeBSD$

PREFIX?=	/usr/local
BINDIR?=	${PREFIX}/bin

MAN=

.PATH: ${.CURDIR}/..

CFLAGS+=	-I${.CURDIR}/.. -I${.CURDIR} ${PTHREAD_CFLAGS}
PTHREAD_LIBS?=	-pthread
LDADD=	${.CURDIR}/../libpd/libpd.a ${PTHREAD_LIBS} -lpcap
