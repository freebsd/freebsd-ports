# Created by: Matthias Petermann <matthias@petermann-it.de>
# $FreeBSD$

PORTNAME=	elementary
PORTVERSION=	0.13.1
DISTVERSIONPREFIX=v
CATEGORIES=	x11-themes xfce
PKGNAMEPREFIX=	xfce-icons-

MAINTAINER=	matthias@petermann-it.de
COMMENT=	Elementary icons, extended and maintained for Xfce

LICENSE=	GPLv2

BUILD_DEPENDS=	optipng:graphics/optipng

USES=		gnome pkgconfig
USE_GNOME=	gdkpixbuf2:build gtk30:build

HAS_CONFIGURE=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	shimmerproject
GH_PROJECT=	elementary-xfce

NO_ARCH=	yes
INSTALLS_ICONS=	yes

.include <bsd.port.mk>
