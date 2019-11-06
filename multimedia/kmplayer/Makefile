# Created by: Kris Moore
# $FreeBSD$

PORTNAME=	kmplayer
PORTVERSION=	0.12.0b
PORTREVISION=	3
PORTEPOCH=	3
CATEGORIES=	multimedia audio kde

MAINTAINER=	jhale@FreeBSD.org
COMMENT=	KDE frontend to Phonon / KDE5

LICENSE=	GPLv2 LGPL21
LICENSE_COMB=	multi

NOT_FOR_ARCHS=		aarch64
NOT_FOR_ARCHS_REASON=	prcpucfg.h:764:2: error: "Unknown CPU architecture"

LIB_DEPENDS=	libdbus-1.so:devel/dbus \
		libdbus-glib-1.so:devel/dbus-glib \
		libfreetype.so:print/freetype2 \
		libfontconfig.so:x11-fonts/fontconfig \
		libxcb-cursor.so:x11/xcb-util-cursor \
		libxcb-ewmh.so:x11/xcb-util-wm \
		libxcb-icccm.so:x11/xcb-util-wm \
		libxcb-image.so:x11/xcb-util-image \
		libxcb-keysyms.so:x11/xcb-util-keysyms \
		libxcb-render-util.so:x11/xcb-util-renderutil \
		libxcb-util.so:x11/xcb-util
RUN_DEPENDS=	mplayer:multimedia/mplayer

USES=		cmake compiler:c++11-lang desktop-file-utils gettext-runtime \
		gnome kde:5 pkgconfig qt:5 xorg
USE_GNOME=	cairo gdkpixbuf2 gtk20
USE_QT=		concurrent core dbus gui network phonon4 printsupport \
		svg widgets x11extras xml \
		buildtools_build qmake_build
USE_KDE=	auth bookmarks codecs completion config configwidgets \
		coreaddons crash ecm guiaddons i18n iconthemes itemviews \
		jobwidgets mediaplayer notifications parts service \
		textwidgets unitconversion widgetsaddons windowsystem \
		xmlgui kdelibs4support kio solid sonnet
USE_XORG=	x11 xcb
USE_GITHUB=	yes
GH_ACCOUNT=	KDE

.include <bsd.port.mk>
