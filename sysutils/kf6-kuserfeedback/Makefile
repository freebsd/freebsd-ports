PORTNAME=	kuserfeedback
DISTVERSION=	${KDE_FRAMEWORKS_VERSION}
CATEGORIES=	sysutils kde kde-frameworks

COMMENT=	Framework for collecting feedback from application users
MAINTAINER=	kde@FreeBSD.org

USES=		cmake gl kde:6 qt:6 tar:xz
USE_GL=		gl opengl
USE_KDE=	ecm:build
USE_QT=		base charts declarative svg tools

CMAKE_ARGS=	-DQT_MAJOR_VERSION=6
CMAKE_OFF=	ENABLE_DOCS

.include <bsd.port.mk>
