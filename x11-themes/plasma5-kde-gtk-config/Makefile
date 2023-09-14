PORTNAME=	kde-gtk-config
DISTVERSION=	${KDE_PLASMA_VERSION}
PORTREVISION=	1
CATEGORIES=	x11-themes kde kde-plasma

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Plasma5 GTK2 and GTK3 configurator
WWW=		https://www.kde.org/plasma-desktop

LICENSE=	GPLv2 LGPL21
LICENSE_COMB=	multi

BUILD_DEPENDS=	gsettings-desktop-schemas>=0:devel/gsettings-desktop-schemas \
		sassc:textproc/sassc
RUN_DEPENDS=	gsettings-desktop-schemas>=0:devel/gsettings-desktop-schemas \
		xsettingsd:x11/xsettingsd
LIB_DEPENDS=	libharfbuzz.so:print/harfbuzz

USES=		cmake compiler:c++11-lib gettext gnome kde:5 pkgconfig qt:5 \
		tar:xz xorg
USE_GNOME=	cairo gdkpixbuf2 glib20 gtk20 gtk30
USE_KDE=	auth codecs config configwidgets \
		coreaddons dbusaddons decoration guiaddons \
		service widgetsaddons \
		windowsystem \
		ecm:build
USE_QT=		core dbus gui svg widgets xml \
		buildtools:build qmake:build testlib:build
USE_XORG=	x11 xcursor

.include <bsd.port.mk>
