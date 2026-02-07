PORTNAME=	kliff
DISTVERSION=	0.4.4
PORTREVISION=	1
CATEGORIES=	science python # chemistry
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	KIM-based Learning-Integrated Fitting Framework
WWW=		https://kliff.readthedocs.io/en/latest/ \
		https://github.com/openkim/kliff

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pybind11>0:devel/py-pybind11@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}loguru>0:devel/py-loguru@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}monty>0:devel/py-monty@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>0:science/py-scipy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyyaml>0:devel/py-pyyaml@${PY_FLAVOR}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}emcee>0:math/py-emcee@${PY_FLAVOR} \
		${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}kimpy>0:science/py-kimpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytorch>0:misc/py-pytorch@${PY_FLAVOR} \

USES=		compiler:c++11-lang python
USE_PYTHON=	distutils autoplist pytest # tests fail to run, see https://github.com/openkim/kliff/issues/81, and https://github.com/openkim/kliff/issues/197

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
TEST_WRKSRC=	${WRKSRC}/tests

post-install:
	@${FIND} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR} -name "*.so" | ${XARGS} ${STRIP_CMD}

# tests as of 0.4.4: 17 failed, 29 passed, 16 errors in 14.58s, see https://github.com/openkim/kliff/issues/210

.include <bsd.port.mk>
