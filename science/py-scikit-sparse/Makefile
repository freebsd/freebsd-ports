PORTNAME=	scikit-sparse
DISTVERSION=	0.4.8
PORTREVISION=	6
CATEGORIES=	science python
MASTER_SITES=	PYPI
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
		${PYTHON_PKGNAMEPREFIX}scipy>0:science/py-scipy@${PY_FLAVOR}

USES=		fortran python
USE_PYTHON=	distutils cython autoplist

CFLAGS+=	-I${LOCALBASE}/include/suitesparse
LDFLAGS+=	-shared

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/sksparse/cholmod*.so

.include <bsd.port.mk>
