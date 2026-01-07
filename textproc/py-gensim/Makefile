PORTNAME=	gensim
DISTVERSION=	4.3.3
PORTREVISION=	1
CATEGORIES=	textproc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Python framework for fast Vector Space Modelling
WWW=		https://radimrehurek.com/gensim/

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}scipy>=1.7.0:science/py-scipy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}smart-open>=1.8.1:net/py-smart-open@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest-cov>0:devel/py-pytest-cov@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}testfixtures>0:devel/py-testfixtures@${PY_FLAVOR}

USES=		compiler:c++11-lang python
USE_PYTHON=	pep517 cython autoplist pytest # tests fail unde PyTest, see https://github.com/RaRe-Technologies/gensim/issues/3561

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
TEST_WRKSRC=	${WRKSRC}/gensim/test

# python setup.py build_ext --inplace
xPYDISTUTILS_BUILD_TARGET=	build_ext

post-install:
	${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR} -name "*.so" | ${XARGS} ${STRIP_CMD}

.include <bsd.port.mk>
