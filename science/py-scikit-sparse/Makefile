# Created by: Yuri Victorovich <yuri@rawbw.com>

PORTNAME=	scikit-sparse
DISTVERSION=	0.4.5
CATEGORIES=	science python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Sparse matrix package

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${RUN_DEPENDS}
LIB_DEPENDS=	libumfpack.so:math/suitesparse-umfpack
RUN_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}scipy>0:science/py-scipy@${PY_FLAVOR}

USES=		fortran python:3.6+
USE_PYTHON=	distutils cython autoplist

CFLAGS+=	-I${LOCALBASE}/include/suitesparse
LDFLAGS+=	-shared

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/sksparse/cholmod*.so

.include <bsd.port.mk>
