# ex:ts=8
# Ports collection makefile for:  unix2tcp
# Date created:                Thu Jan 30, 2003
# Whom:                        Michael L. Hostbaek (mich@freebsdcluster.org)
#
# $FreeBSD$
#

PORTNAME=	unix2tcp
PORTVERSION=	0.7.2
CATEGORIES=	net
MASTER_SITES=	http://ahriman.bucharest.roedu.net/unix2tcp/

MAINTAINER=	mich@FreeBSD.org
COMMENT=	A connection forwarder that converts Unix sockets into TCP sockets

do-build:
	cd ${WRKSRC} && \
	${CC} -I. ${PORTNAME}.c -c &&\
	${CC} -I. list.c -c && \
	${CC} ${PORTNAME}.o list.o -o ${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/sbin

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}/README
.endif

.include <bsd.port.mk>
