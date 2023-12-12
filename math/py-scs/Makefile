PORTNAME=	scs
DISTVERSION=	3.2.0
PORTREVISION=	2
CATEGORIES=	math python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Splitting conic solver for Python
WWW=		https://github.com/cvxgrp/scs

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYNUMPY}
RUN_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}scipy>=0.13.2:science/py-scipy@${PY_FLAVOR}

USES=		python blaslapack:openblas fortran # fortran is for openblas
USE_PYTHON=	distutils autoplist

CONFIGURE_ENV=	BLAS_LAPACK_LIBS="openblas"
MAKE_ENV=	${CONFIGURE_ENV}

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/_scs_*.so

.include <bsd.port.mk>
