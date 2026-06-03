PORTNAME=	oxygen
DISTVERSION=	${KDE_PLASMA_VERSION}
CATEGORIES=	x11-themes kde kde-plasma

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Oxygen Style for Qt/KDE Applications

LIB_DEPENDS=	libxkbcommon.so:x11/libxkbcommon

USES=		cmake gettext gl kde:6 qt:6 tar:xz xorg
USE_GL=		gl opengl
USE_KDE=	colorscheme completion config configwidgets coreaddons \
		decoration frameworkintegration guiaddons i18n iconthemes \
		kcmutils libplasma service widgetsaddons windowsystem \
		ecm:build
USE_QT=		base declarative
USE_XORG=	x11 xcb

CMAKE_ON=	BUILD_QT6
CMAKE_OFF=	BUILD_QT5

.include <bsd.port.mk>
