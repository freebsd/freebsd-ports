# Created by: Alexander Vereeken <Alexander88207@protonmail.com>
# $FreeBSD$

PORTNAME=	pop-gtk-themes
DISTVERSIONPREFIX=	v
DISTVERSION=	5.3.1
CATEGORIES=	x11-themes

MAINTAINER=	Alexander88207@protonmail.com
COMMENT=	System76 Pop GTK+ Theme

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	bash>0:shells/bash \
		coreutils>0:sysutils/coreutils \
		sassc>0:textproc/sassc

USES=		gnome meson python shebangfix pkgconfig
USE_GNOME=	glib20:build
USE_GITHUB=	yes
GH_ACCOUNT=	pop-os
GH_PROJECT=	gtk-theme
NO_ARCH=	yes

BINARY_ALIAS=	realpath=grealpath

SHEBANG_LANG=	${PYTHON_CMD}
SHEBANG_FILES=	gnome-shell/gresources-xml-parser.py \
		gnome-shell/copy-and-rename.py

.include <bsd.port.mk>
