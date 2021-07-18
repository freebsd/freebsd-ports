PORTNAME=	qdldl
PORTVERSION=	0.1.5.post0
CATEGORIES=	math python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	QDLDL free LDL factorization routine for linear systems: Ax = b

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_i386=	error: no matching function for call to 'amd_l_order', see https://github.com/oxfordcontrol/qdldl-python/issues/15

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pybind11>0:devel/py-pybind11@${PY_FLAVOR} \
		cmake:devel/cmake
RUN_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}scipy>=0.13.2:science/py-scipy@${PY_FLAVOR}

USES=		compiler:c++11-lang python:3.6+
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
