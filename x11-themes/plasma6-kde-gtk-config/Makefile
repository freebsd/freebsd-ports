PORTNAME=	kde-gtk-config
DISTVERSION=	${KDE_PLASMA_VERSION}
PORTREVISION=	1
CATEGORIES=	x11-themes kde kde-plasma

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Syncs KDE settings to GTK applications

BUILD_DEPENDS=	gsettings-desktop-schemas>=0:devel/gsettings-desktop-schemas \
		sassc:textproc/sassc
LIB_DEPENDS=	libharfbuzz.so:print/harfbuzz
RUN_DEPENDS=	gsettings-desktop-schemas>=0:devel/gsettings-desktop-schemas \
		xsettingsd:x11/xsettingsd

USES=		cmake gnome kde:6 pkgconfig qt:6 tar:xz
USE_GNOME=	cairo gdkpixbuf glib20 gtk30
USE_KDE=	colorscheme config coreaddons dbusaddons \
		guiaddons windowsystem \
		ecm:build
# KDE Plasma
USE_KDE+=	decoration
USE_QT=		base svg

.include <bsd.port.mk>
