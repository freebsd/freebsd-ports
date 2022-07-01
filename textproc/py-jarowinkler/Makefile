PORTNAME=	jarowinkler
PORTVERSION=	1.0.5
CATEGORIES=	textproc python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Library for fast approximate string matching

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	cmake:devel/cmake \
		${PYTHON_PKGNAMEPREFIX}rapidfuzz-capi>0:devel/py-rapidfuzz-capi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scikit-build>0:devel/py-scikit-build@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	distutils cython autoplist pytest # tests fail to run, see https://github.com/maxbachmann/JaroWinkler/issues/7

TEST_ENV=      ${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/jarowinkler/_initialize.*.so

.include <bsd.port.mk>
