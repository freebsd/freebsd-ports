# $FreeBSD$

PORTNAME=	breeze
DISTVERSION=	${KDE_PLASMA_VERSION}
PORTREVISION=	2
CATEGORIES=	x11-themes kde kde-plasma

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Plasma5 artwork, styles and assets for the Breeze visual style

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cmake:outsource compiler:c++11-lib cpe \
		gettext kde:5 pkgconfig qt:5 tar:xz
USE_KDE=	auth breeze-icons codecs config configwidgets coreaddons \
		decoration ecm frameworkintegration guiaddons i18n kcmutils \
		plasma-framework service wayland widgetsaddons windowsystem
USE_QT=		core dbus declarative gui network widgets x11extras xml \
		buildtools_build qmake_build
USE_XORG=	xcb

.include <bsd.port.mk>
