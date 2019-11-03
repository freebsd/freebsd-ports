# $FreeBSD$

PORTNAME=	breeze
DISTVERSION=	${KDE_PLASMA_VERSION}
CATEGORIES=	x11-themes kde kde-plasma

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Plasma5 artwork, styles and assets for the Breeze visual style

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libfftw3_threads.so:math/fftw3

USES=		cmake compiler:c++11-lib cpe \
		gettext kde:5 pkgconfig qt:5 tar:xz xorg
USE_KDE=	auth breeze-icons codecs config configwidgets coreaddons \
		decoration ecm frameworkintegration guiaddons i18n kcmutils \
		plasma-framework service wayland widgetsaddons windowsystem
USE_QT=		core dbus declarative gui network widgets x11extras xml \
		buildtools_build qmake_build
USE_XORG=	xcb

.include <bsd.port.mk>
