PORTNAME=	breeze-gtk
DISTVERSION=	${KDE_PLASMA_VERSION}
CATEGORIES=	x11-themes kde kde-plasma

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Breeze widget theme for GTK 2 and 3

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cairo>0:graphics/py-cairo@${PY_FLAVOR} \
		sassc:textproc/sassc
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cairo>0:graphics/py-cairo@${PY_FLAVOR}

USES=		cmake kde:6 python qt:6 tar:xz
USE_KDE=	breeze \
		ecm:build
USE_QT=		base

CMAKE_ARGS=	-DPython3_EXECUTABLE:PATH=${PYTHON_CMD} \
		-DQT_MAJOR_VERSION=6

BINARY_ALIAS=	python3=${PYTHON_CMD}
NO_ARCH=	yes

.include <bsd.port.mk>
