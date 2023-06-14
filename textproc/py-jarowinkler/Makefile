PORTNAME=	jarowinkler
DISTVERSION=	1.2.3
CATEGORIES=	textproc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Library for fast approximate string matching
WWW=		https://github.com/maxbachmann/JaroWinkler

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	cmake:devel/cmake-core \
		${PYTHON_PKGNAMEPREFIX}rapidfuzz-capi>0:devel/py-rapidfuzz-capi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scikit-build>0:devel/py-scikit-build@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils cython autoplist pytest # tests fail to run, see https://github.com/maxbachmann/JaroWinkler/issues/7

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/jarowinkler/_initialize_cpp.cpython-${PYTHON_SUFFIX}.so

.include <bsd.port.mk>
