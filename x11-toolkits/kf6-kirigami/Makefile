PORTNAME=	kirigami
DISTVERSION=	${KDE_FRAMEWORKS_VERSION}
CATEGORIES=	x11-toolkits kde kde-frameworks
PATCH_SITES=	https://invent.kde.org/frameworks/kirigami/-/commit/
PATCHFILES=	19127672cd812d177192cf84da4107f9abed2934.patch:-p1

COMMENT=	QtQuick components for building adaptable UIs
MAINTAINER=	kde@FreeBSD.org

LIB_DEPENDS=	libxkbcommon.so:x11/libxkbcommon

USES=		cmake gl kde:6 qt:6 tar:xz
USE_GL=		gl opengl
USE_KDE=	ecm:build
USE_QT=		base declarative shadertools svg tools

.include <bsd.port.mk>
