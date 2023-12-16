PORTNAME=	breeze
DISTVERSION=	${KDE_PLASMA_VERSION}
CATEGORIES=	x11-themes kde kde-plasma

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Artwork, styles and assets for the Breeze visual style for the Plasma Desktop

USES=		cmake gettext gl kde:6 qt:6 tar:xz xorg
USE_GL=		gl opengl
USE_KDE=	colorscheme config configwidgets coreaddons decoration \
		guiaddons i18n iconthemes kcmutils kirigami2 widgetsaddons \
		windowsystem \
		ecm:build
USE_QT=		base declarative
USE_XORG=	x11

CMAKE_OFF=	BUILD_QT5
CMAKE_ON=	BUILD_QT6
CMAKE_ARGS=	-DQT_MAJOR_VERSION=6

.include <bsd.port.mk>
