# ex:ts=8
# Ports collection makefile for:  unix2tcp
# Date created:                Thu Jan 30, 2003
# Whom:                        Michael L. Hostbaek (mich@freebsdcluster.org)
#
# $FreeBSD$
#

PORTNAME=	unix2tcp
PORTVERSION=	0.8.2
CATEGORIES=	net
MASTER_SITES=	http://ahriman.bucharest.roedu.net/unix2tcp/

MAINTAINER=	mich@FreeBSD.org
COMMENT=	A connection forwarder that converts Unix sockets into TCP sockets

CFLAGS+=	-DHAVE_CONFIG_H -I.
GNU_CONFIGURE=	yes

do-build:
	cd ${WRKSRC} && \
	${CC} ${CFLAGS} -c ${PORTNAME}.c -o ${PORTNAME}.o &&\
	${CC} ${CFLAGS} -c server.c -o server.o &&\
	${CC} ${CFLAGS} -c mylog.c -o mylog.o &&\
	${CC} ${CFLAGS} -c list.c -o list.o &&\
	${CC} ${PORTNAME}.o server.o mylog.o list.o -o ${PORTNAME} && \
	${CC} ${CFLAGS} -c utelnet.c -o utelnet.o

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/sbin

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}/README
.endif

.include <bsd.port.mk>
