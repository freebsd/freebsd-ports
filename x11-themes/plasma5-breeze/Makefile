PORTNAME=	breeze
DISTVERSION=	${KDE_PLASMA_VERSION}
PORTREVISION=	1
CATEGORIES=	x11-themes kde kde-plasma

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Plasma5 artwork, styles and assets for the Breeze visual style
WWW=		https://www.kde.org/plasma-desktop

LICENSE=	GPLv2

USES=		cmake compiler:c++11-lib gettext kde:5 pkgconfig qt:5 tar:xz \
		xorg
USE_KDE=	auth breeze-icons codecs config configwidgets coreaddons \
		decoration frameworkintegration guiaddons i18n iconthemes \
		kcmutils kirigami2 service widgetsaddons windowsystem \
		ecm:build
USE_QT=		core dbus declarative gui network widgets x11extras xml \
		buildtools:build qmake:build
USE_XORG=	x11 xcb

.include <bsd.port.mk>
