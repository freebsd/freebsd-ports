PORTNAME=	triangle
DISTVERSIONPREFIX=	v
DISTVERSION=	20250106
CATEGORIES=	math python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	db@FreeBSD.org
COMMENT=	Python interface to triangle
WWW=		https://rufat.be/triangle

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/LICENSE
BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=61:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR} \
		triangle>0:math/triangle
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>0:math/py-numpy@${PY_FLAVOR}

USES=		compiler:c++11-lang python

USE_GITHUB=	yes
GH_ACCOUNT=	drufat
GH_TUPLE=	drufat:triangle-c:8b9e104:triangle/c
USE_PYTHON=	autoplist concurrent cython pep517

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/triangle/core*.so

.include <bsd.port.mk>
