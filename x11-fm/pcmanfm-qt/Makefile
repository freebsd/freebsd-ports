# Created by: Olivier Duchateau
# $FreeBSD$

PORTNAME=	pcmanfm-qt
PORTVERSION=	0.13.0
PORTREVISION=	2
CATEGORIES=	x11-fm
MASTER_SITES=	LXQT

MAINTAINER=	mbeis@xs4all.nl
COMMENT=	LXQt file manager

LICENSE=	GPLv2

LIB_DEPENDS=	libmenu-cache.so:x11/menu-cache \
		libfm.so:x11/libfm \
		libexif.so:graphics/libexif

USES=		cmake compiler:c++11-lib desktop-file-utils \
		gettext-runtime localbase:ldflags lxqt pkgconfig kde:5 qt:5 tar:xz
USE_QT=		buildtools_build qmake_build core dbus gui linguisttools \
		widgets x11extras
USE_KDE=	oxygen-icons5
USE_LXQT=	buildtools libfmqt
USE_GNOME=	glib20
USE_XORG=	xcb

.include <bsd.port.mk>
