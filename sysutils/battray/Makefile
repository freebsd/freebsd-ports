# Created by: Martin Tournoij <martin@arp242.net>
# $FreeBSD$

PORTNAME=	battray
PORTVERSION=	2.1
CATEGORIES=	sysutils python
MASTER_SITES=	http://code.arp242.net/${BB_PROJECT}/get/${BB_COMMIT}.tar.gz?dummy=/
DISTNAME=	${BB_ACCOUNT}-${BB_PROJECT}-${BB_COMMIT}

MAINTAINER=	tz@FreeBSD.org
COMMENT=	Display notebook battery status in tray

LICENSE=	MIT

USE_GNOME=	py3gobject3
USES=		python:3.3+
USE_PYTHON=	autoplist distutils


BB_ACCOUNT=	Carpetsmoker
BB_PROJECT=	${PORTNAME}
BB_COMMIT=	011402fbc2a3

.include <bsd.port.mk>
