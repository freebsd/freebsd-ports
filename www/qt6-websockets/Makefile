PORTNAME=	websockets
DISTVERSION=	${QT6_VERSION}
CATEGORIES=	www
PKGNAMEPREFIX=	qt6-

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt implementation of WebSocket protocol

BUILD_DEPENDS=	vulkan-headers>0:graphics/vulkan-headers \
		${PYTHON_PKGNAMEPREFIX}cyclonedx-python-lib>0:textproc/py-cyclonedx-python-lib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}spdx-tools>=0.8.3:misc/py-spdx-tools@${PY_FLAVOR}

USES=		cmake compiler:c++17-lang pkgconfig python:build qt-dist:6
USE_LDCONFIG=	${PREFIX}/${QT_LIBDIR_REL}
USE_QT=		base declarative

.include <bsd.port.mk>
