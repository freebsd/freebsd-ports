PORTNAME=	breeze
DISTVERSION=	${KDE_PLASMA_VERSION}
CATEGORIES=	x11-themes kde kde-plasma

PATCH_SITES=	https://invent.kde.org/plasma/breeze/-/commit/
PATCHFILES+=	098ad3facb3d76fe4476424f1b7bf3c9c2c1b142.patch:-p1 # Add missing headers for Qt 6.9
PATCHFILES+=	e2f16562b64c63b623def44476eadc635a82c7de.patch:-p1 # Add missing headers for Qt 6.9

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Artwork, styles and assets for the Breeze visual style for the Plasma Desktop

USES=		cmake gettext gl kde:6 qt:6 tar:xz xorg
USE_GL=		gl opengl
USE_KDE=	colorscheme config configwidgets coreaddons decoration \
		frameworkintegration guiaddons i18n iconthemes kcmutils \
		kirigami2 widgetsaddons windowsystem \
		ecm:build
USE_QT=		base declarative
USE_XORG=	x11

CMAKE_OFF=	BUILD_QT5
CMAKE_ON=	BUILD_QT6
CMAKE_ARGS=	-DQT_MAJOR_VERSION=6

.include <bsd.port.mk>
