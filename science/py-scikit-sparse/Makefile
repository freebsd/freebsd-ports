PORTNAME=	scikit-sparse
DISTVERSIONPREFIX=	v
DISTVERSION=	0.4.16
PORTREVISION=	1
CATEGORIES=	science python
#MASTER_SITES=	PYPI # missing files under tests/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Sparse matrix package
WWW=		https://github.com/scikit-sparse/scikit-sparse

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${RUN_DEPENDS}
LIB_DEPENDS=	libumfpack.so:math/suitesparse-umfpack	\
		libcholmod.so:math/suitesparse-cholmod
RUN_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}scipy>=0.19:science/py-scipy@${PY_FLAVOR}

USES=		fortran python
USE_PYTHON=	distutils cython autoplist pytest
USE_GITHUB=	yes

CFLAGS+=	-I${LOCALBASE}/include/suitesparse
LDFLAGS+=	-shared

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
TEST_WRKSRC=	${WRKSRC}/tests

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/sksparse/cholmod*.so

# tests as of 0.4.16: 10 passed, 400 warnings in 27.47

.include <bsd.port.mk>
