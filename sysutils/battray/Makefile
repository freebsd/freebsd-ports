# Created by: Martin Tournoij <martin@arp242.net>
# $FreeBSD$

PORTNAME=	battray
DISTVERSIONPREFIX=	version-
DISTVERSION=	2.3
PORTREVISION=	1
CATEGORIES=	sysutils python

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Display notebook battery status in tray

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		gnome python:3.3+
USE_GNOME=	pygobject3
USE_PYTHON=	autoplist distutils optsuffix

USE_GITHUB=	yes
GH_ACCOUNT=	arp242
NO_ARCH=	yes

.include <bsd.port.mk>
