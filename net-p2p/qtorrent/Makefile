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

MAINTAINER=	ports@FreeBSD.org
COMMENT=	BitTorrent client that uses the Qt widget-set

BUILD_DEPENDS=	pyuic:${PORTSDIR}/x11-toolkits/py-qt
RUN_DEPENDS=	pyuic:${PORTSDIR}/x11-toolkits/py-qt

USE_BZIP2=	yes
USE_PYTHON=	2.3
USE_PYDISTUTILS=yes

pre-everything::
	@${ECHO_MSG} "===>"
	@${ECHO_MSG} "===> For qtorrent to work you need to compile"
	@${ECHO_MSG} "===> python WITH_THREADS defined, it is default"
	@${ECHO_MSG} "===>"

.include <bsd.port.mk>
