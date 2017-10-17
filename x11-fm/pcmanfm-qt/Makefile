# Created by: Olivier Duchateau
# $FreeBSD$

PORTNAME=	pcmanfm-qt
PORTVERSION=	0.11.3
PORTREVISION=	2
CATEGORIES=	x11-fm
MASTER_SITES=	LXQT/${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	LXQt file manager

LICENSE=	GPLv2

LIB_DEPENDS=	libmenu-cache.so:x11/menu-cache \
	libfm.so:x11/libfm

USES=	cmake:outsource compiler:c++11-lib desktop-file-utils \
	gettext-runtime localbase:ldflags lxqt pkgconfig tar:xz
USE_QT5=	buildtools_build qmake_build core dbus gui linguisttools \
	widgets x11extras
USE_LXQT=	buildtools libfmqt
USE_GNOME=	glib20
USE_XORG=	xcb

.include <bsd.port.mk>
