# ex:ts=8
# New ports collection makefile for:	xmlpp
# Date created:			May 22, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	xmlpp
PORTVERSION=	0.6
CATEGORIES=	textproc
MASTER_SITES=	http://www.vividos.de/projekte/xmlpp/files/

MAINTAINER=	ports@FreeBSD.org

USE_GMAKE=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/libxmlpp.a ${PREFIX}/lib

.include <bsd.port.mk>
