PORTNAME=	breeze-icons
DISTVERSION=	${KDE_FRAMEWORKS_VERSION}
CATEGORIES=	x11-themes kde kde-frameworks

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Breeze icon theme for KDE

LICENSE=	LGPL3+
LICENSE_FILE=	${WRKSRC}/COPYING-ICONS

BUILD_DEPENDS=	bash:shells/bash

USES=		compiler:c++11-lang cmake kde:5 python:3.5+,build qt:5 shebangfix tar:xz
USE_KDE=	ecm:build
USE_QT=		buildtools:build qmake:build testlib:build

SHEBANG_FILES=	 svg-xml-script-template.py generate-24px-versions.py

NO_ARCH=	yes
CMAKE_ARGS=	-DXMLLINT_EXE:PATH='' \
		-DPython3_EXECUTABLE:PATH=${PYTHON_CMD}
CMAKE_ON=	WITH_ICON_GENERATION

.include <bsd.port.options.mk>

CMAKE_BUILD_TYPE=Release
# Depend on lxml from PYTHON_SITELIBDIR to allow to use a pre-installed hybrid
# ABI version.
BUILD_DEPENDS+=	${PYTHON_SITELIBDIR}/lxml:devel/py-lxml@${PY_FLAVOR}

.include <bsd.port.mk>
