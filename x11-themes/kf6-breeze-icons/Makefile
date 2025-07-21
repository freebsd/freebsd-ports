PORTNAME=	breeze-icons
DISTVERSION=	${KDE_FRAMEWORKS_VERSION}
PORTREVISION=	2
CATEGORIES=	x11-themes kde kde-frameworks

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Default KDE icon theme

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}lxml5>=4.9.3:devel/py-lxml5@${PY_FLAVOR}

USES=		cmake gl kde:6 qt:6 shebangfix tar:xz \
		python:build
USE_GL=		opengl
USE_KDE=	ecm:build
USE_LDCONFIG=	yes
USE_QT=		base

SHEBANG_FILES=	generate-24px-versions.py \
		svg-xml-script-template.py

CMAKE_ON=	BINARY_ICONS_RESOURCE \
		WITH_ICON_GENERATION

.include <bsd.port.mk>
