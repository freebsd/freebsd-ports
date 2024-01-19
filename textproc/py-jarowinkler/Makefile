PORTNAME=	jarowinkler
DISTVERSION=	2.0.1
CATEGORIES=	textproc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Library for fast approximate string matching
WWW=		https://github.com/maxbachmann/JaroWinkler

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	cmake:devel/cmake-core \
		${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}rapidfuzz-capi>0:devel/py-rapidfuzz-capi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scikit-build>0:devel/py-scikit-build@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}rapidfuzz>=3.5.2:devel/py-rapidfuzz@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 cython autoplist pytest # tests fail to run, see https://github.com/maxbachmann/JaroWinkler/issues/7

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

.include <bsd.port.mk>
