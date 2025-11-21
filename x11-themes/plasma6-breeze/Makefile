PORTNAME=	breeze
DISTVERSION=	${KDE_PLASMA_VERSION}
PORTREVISION=	1
CATEGORIES=	x11-themes kde kde-plasma
PATCH_SITES=	https://invent.kde.org/plasma/breeze/-/commit/
PATCHFILES=	4a8a46aba6b9e39bfb02c7f46933079b5a50eff5.patch:-p1 \
		2cd5b37dad8f213aab4029b6d3b80ca7f159ea50.patch:-p1

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Artwork, styles and assets for the Breeze visual style for the Plasma Desktop

FLAVORS=	qt6 qt5
FLAVOR?=	qt6

USES=		cmake gettext gl tar:xz xorg
USES+=		${${FLAVOR}_USES}
USE_GL=		gl opengl
USE_KDE=	${${FLAVOR}_USE_KDE}
USE_QT=		${${FLAVOR}_USE_QT}
USE_XORG=	x11

CMAKE_ON=	${${FLAVOR}_CMAKE_ON}
CMAKE_OFF=	${${FLAVOR}_CMAKE_OFF}

# Qt6 flavor
qt6_USES=	kde:6 qt:6
qt6_USE_KDE=	colorscheme config configwidgets coreaddons decoration \
		frameworkintegration guiaddons i18n iconthemes kcmutils \
		kirigami2 widgetsaddons windowsystem \
		ecm:build
qt6_USE_QT=	base declarative
qt6_CMAKE_ON=	BUILD_QT6
qt6_CMAKE_OFF=	BUILD_QT5

# Qt5 flavor
qt5_USES=	kde:5 localbase qt:5
qt5_USE_KDE=	config configwidgets coreaddons frameworkintegration \
		guiaddons iconthemes kirigami2 windowsystem \
		ecm:build
qt5_USE_QT=	core gui quickcontrols widgets x11extras \
		buildtools:build qmake:build
qt5_CMAKE_ON=	BUILD_QT5
qt5_CMAKE_OFF=	BUILD_QT6

.if ${FLAVOR:Mqt5}
KDE_PLASMA_VERSION=	${KDE_PLASMA6_VERSION}
PKGNAMEPREFIX=	plasma6-
PKGNAMESUFFIX=	-qt5
COMMENT=	Plasma Breeze visual style for Qt5
DESCR=		${.CURDIR:H:H}/x11/plasma6-plasma/pkg-descr
PLIST=		# none
PLIST_FILES=	${QT_PLUGINDIR}/styles/breeze5.so

post-patch:
# Avoid clash with Qt6 flavor
	${REINPLACE_CMD} '/^build_colors_and_cursors/d' ${WRKSRC}/CMakeLists.txt
	${REINPLACE_CMD}  '/^install(FILES breeze.themerc/d' ${WRKSRC}/kstyle/CMakeLists.txt
.endif

.include <bsd.port.mk>
