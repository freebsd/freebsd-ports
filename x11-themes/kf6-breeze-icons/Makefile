PORTNAME=	breeze-icons
DISTVERSION=	${KDE_FRAMEWORKS_VERSION}
CATEGORIES=	x11-themes kde kde-frameworks

COMMENT=	freedesktop.org compatible icon theme
MAINTAINER=	kde@FreeBSD.org

BUILD_DEPENDS=	bash:shells/bash
USES=		cmake kde:6 qt:6 shebangfix tar:xz \
		python:build
USE_KDE=	ecm:build
USE_QT=		base

CMAKE_ARGS=	-DPython3_EXECUTABLE:PATH=${PYTHON_CMD} \
		-DXMLLINT_EXE:PATH=''
CMAKE_ON=	WITH_ICON_GENERATION

SHEBANG_FILES=	generate-24px-versions.py svg-xml-script-template.py
NO_ARCH=	yes

.include <bsd.port.mk>
