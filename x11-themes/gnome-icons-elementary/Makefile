# Created by: Nicole Reid <root@cooltrainer.org>

PORTNAME=	elementary
DISTVERSION=	6.1.0
CATEGORIES=	x11-themes gnome
PKGNAMEPREFIX=	gnome-icons-

MAINTAINER=	duchateau.olivier@gmail.com
COMMENT=	Elementary icon set

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	xcursorgen:x11/xcursorgen

USES=		gettext gnome meson python:3.6+,build

USE_GITHUB=	yes
GH_PROJECT=	icons

USE_GNOME=	librsvg2

MESON_ARGS=	-Dpalettes=false \
		-Dvolume_icons=false

NO_ARCH=	yes

.include <bsd.port.mk>
