# New ports collection makefile for: 	ffproxy
# Date created:				Jul 20 2003
# Whom:                			Kirill Ponomarew <ponomarew@oberon.net>
#
# $FreeBSD$
#

PORTNAME=	ffproxy
PORTVERSION=	1.4
CATEGORIES=	www
MASTER_SITES=	http://faith.eu.org/${PORTNAME}/

MAINTAINER=	krion@FreeBSD.org	
COMMENT=	Filtering HTTP proxy server

MAN8=	${PORTNAME}.8

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.8 \
		${PREFIX}/man/man8
	${INSTALL_DATA} ${WRKSRC}/sample.config \
		${PREFIX}/etc/ffproxy.conf.sample
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${MKDIR} ${DOCSDIR}/db
	${MKDIR} ${DOCSDIR}/html
	${INSTALL_DATA} ${WRKSRC}/html/* ${DOCSDIR}/html
	${INSTALL_DATA} ${WRKSRC}/db/* ${DOCSDIR}/db
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
