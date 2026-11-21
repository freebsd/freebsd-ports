PORTNAME=	kjobwidgets
DISTVERSION=	${KDE_FRAMEWORKS_VERSION}
CATEGORIES=	x11-toolkits kde kde-frameworks

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Widgets for showing progress of asynchronous jobs

LIB_DEPENDS=	libxkbcommon.so:x11/libxkbcommon

USES=		cmake gl kde:6 qt:6 tar:xz
USE_GL=		opengl
USE_KDE=	coreaddons notifications widgetsaddons \
		ecm:build
USE_QT=		base \
		tools:build

CMAKE_OFF=	BUILD_PYTHON_BINDINGS

.include <bsd.port.mk>
