# New ports collection makefile for:	qtorrent
# Date created:		2004-03-31
# Whom:			michael johnson <ahze@ahze.net>
#
# $FreeBSD$
#

PORTNAME=	qtorrent
PORTVERSION=	0.9.6.1
CATEGORIES=	net python
MASTER_SITES=	http://thegraveyard.org/files/

MAINTAINER=	ahze@ahze.net
COMMENT=	BitTorrent client that uses the Qt widget-set

BUILD_DEPENDS=	pyuic:${PORTSDIR}/x11-toolkits/py-qt
RUN_DEPENDS=	pyuic:${PORTSDIR}/x11-toolkits/py-qt

USE_BZIP2=	yes
USE_PYTHON=	yes
USE_PYDISTUTILS=yes

.include <bsd.port.mk>
