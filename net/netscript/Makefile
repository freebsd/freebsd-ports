# ex:ts=8
# New ports collection makefile for:	netscript
# Date created:			May 30, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	netscript
PORTVERSION=	1.6.3
CATEGORIES=	net
MASTER_SITES=	http://www.realhalo.org/netscript/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org

ALL_TARGET=	bsd

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/netscript ${PREFIX}/bin
	${MKDIR} ${PREFIX}/share/examples/netscript
	(cd ${WRKSRC}/examples ; \
	 ${INSTALL_DATA} * ${PREFIX}/share/examples/netscript)

.include <bsd.port.mk>
