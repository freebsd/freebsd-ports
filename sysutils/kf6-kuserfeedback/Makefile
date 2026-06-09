PORTNAME=	kuserfeedback
DISTVERSION=	${KDE_FRAMEWORKS_VERSION}
CATEGORIES=	sysutils kde kde-frameworks

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Framework for collecting feedback from application users

USES=		bison cmake gl kde:6 qt:6 tar:xz
USE_GL=		gl opengl
USE_KDE=	ecm:build
USE_QT=		base charts declarative svg tools

CMAKE_BOOL_OFF=		ENABLE_PHP ENABLE_PHP_UNIT

.include <bsd.port.mk>
