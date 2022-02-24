PORTNAME=	cyipopt
DISTVERSIONPREFIX=	v
DISTVERSION=	1.1.0
PORTREVISION=	1
CATEGORIES=	math python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Cython interface for the interior point optimizer IPOPT

LICENSE=	EPL

BUILD_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}six>0:devel/py-six@${PY_FLAVOR}
LIB_DEPENDS=	libblas.so:math/blas \
		libcoinmetis.so:math/ipopt \
		liblapack.so:math/lapack
RUN_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}future>0:devel/py-future@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>0:science/py-scipy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>0:devel/py-six@${PY_FLAVOR}

USES=		fortran python:3.6+ pkgconfig # fortran because ipopt's pkg-config returns gcc libs
USE_GITHUB=	yes
GH_ACCOUNT=	matthias-k
USE_PYTHON=	distutils cython autoplist

.include <bsd.port.mk>
