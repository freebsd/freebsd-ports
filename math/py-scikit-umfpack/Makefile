PORTNAME=	scikit-umfpack
DISTVERSION=	0.3.2
PORTREVISION=	3
CATEGORIES=	math python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Python interface to UMFPACK sparse direct solver

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}scipy>0:science/py-scipy@${PY_FLAVOR} \
		swig:devel/swig
LIB_DEPENDS=	libumfpack.so:math/suitesparse-umfpack
RUN_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}scipy>0:science/py-scipy@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	distutils cython autoplist

post-extract: # workaround for https://github.com/scikit-umfpack/scikit-umfpack/issues/53
	@truncate -s 0 ${WRKSRC}/README.rst

.include <bsd.port.mk>
