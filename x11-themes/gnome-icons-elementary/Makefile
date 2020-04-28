# Created by: Nicole Reid <root@cooltrainer.org>
# $FreeBSD$

PORTNAME=	elementary
PORTVERSION=	5.2.0
CATEGORIES=	x11-themes gnome
PKGNAMEPREFIX=	gnome-icons-

MAINTAINER=	root@cooltrainer.org
COMMENT=	Elementary icon set

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	xcursorgen:x11/xcursorgen

USES=		gettext gnome meson python:3.5+,build

USE_GITHUB=	yes
GH_PROJECT=	icons

USE_GNOME=	librsvg2
INSTALLS_ICONS=	yes

NO_ARCH=	yes
MESON_ARGS=	-Dpalettes=false \
		-Dvolume_icons=false

.include <bsd.port.mk>
