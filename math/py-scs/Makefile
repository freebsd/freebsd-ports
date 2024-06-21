PORTNAME=	scs
DISTVERSION=	3.2.4.post3
CATEGORIES=	math python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Splitting conic solver for Python
WWW=		https://github.com/cvxgrp/scs

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}meson-python>0:devel/meson-python@${PY_FLAVOR} \
		${PYNUMPY}
LIB_DEPENDS=	libopenblas.so:math/openblas
RUN_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}scipy>=0.13.2:science/py-scipy@${PY_FLAVOR}

USES=		python blaslapack:openblas fortran localbase:ldflags pkgconfig # fortran is for openblas
USE_PYTHON=	pep517 autoplist pytest # 2 tests fail, see https://github.com/cvxgrp/scs/issues/273

CONFIGURE_ENV=	BLAS_LAPACK_LIBS="openblas"
MAKE_ENV=	${CONFIGURE_ENV}

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/_scs_*.so

.include <bsd.port.mk>
