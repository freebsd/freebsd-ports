PORTNAME=	breeze
DISTVERSION=	${KDE_PLASMA_VERSION}
PORTREVISION=	1
CATEGORIES=	x11-themes kde kde-plasma

PATCH_SITES=	https://invent.kde.org/plasma/breeze/commit/
PATCHFILES=	40d558e96d607419b9bfaa9a706621a906bab3e9.diff:-p1

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Plasma5 artwork, styles and assets for the Breeze visual style

LICENSE=	GPLv2

LIB_DEPENDS=	libfftw3_threads.so:math/fftw3

USES=		cmake compiler:c++11-lib cpe \
		gettext kde:5 pkgconfig qt:5 tar:xz xorg
USE_KDE=	auth breeze-icons codecs config configwidgets coreaddons \
		decoration ecm frameworkintegration guiaddons i18n iconthemes \
		kcmutils plasma-framework service wayland widgetsaddons windowsystem
USE_QT=		core dbus declarative gui network widgets x11extras xml \
		buildtools_build qmake_build
USE_XORG=	xcb

.include <bsd.port.mk>
