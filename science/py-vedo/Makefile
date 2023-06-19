PORTNAME=	vedo
DISTVERSION=	2023.4.5
CATEGORIES=	science graphics python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Python module for scientific analysis and visualization of 3D objects
WWW=		https://vedo.embl.es/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}deprecated>0:devel/py-deprecated@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pygments>0:textproc/py-pygments@${PY_FLAVOR} \
		${PYNUMPY} \
		vtk${VTK_VER:R}>0:math/vtk${VTK_VER:R} \
		bash:shells/bash

USES=		python:3.6+ shebangfix
USE_PYTHON=	distutils autoplist

SHEBANG_GLOB=	*.sh

NO_ARCH=	yes

.include <../../math/vtk9/Makefile.version>
.include <bsd.port.mk>
