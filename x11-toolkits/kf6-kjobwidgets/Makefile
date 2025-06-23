PORTNAME=	kjobwidgets
DISTVERSION=	${KDE_FRAMEWORKS_VERSION}
CATEGORIES=	x11-toolkits kde kde-frameworks

COMMENT=	Widgets for showing progress of asynchronous jobs
MAINTAINER=	kde@FreeBSD.org

LIB_DEPENDS=	libxkbcommon.so:x11/libxkbcommon

USES=		cmake gl kde:6 qt:6 tar:xz
USE_GL=		gl opengl
USE_KDE=	coreaddons notifications widgetsaddons \
		ecm:build
USE_QT=		base

CMAKE_OFF=	BUILD_PYTHON_BINDINGS

.include <bsd.port.mk>
