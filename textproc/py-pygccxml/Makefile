PORTNAME=	pygccxml
DISTVERSIONPREFIX=	v
DISTVERSION=	3.0.0
CATEGORIES=	textproc python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Python package for easy C++ declarations navigation
WWW=		https://github.com/CastXML/pygccxml

LICENSE=	BSL
LICENSE_FILE=	${WRKSRC}/LICENSE.rst

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	castxml:textproc/castxml
py39_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}importlib-metadata>=4.6:devel/py-importlib-metadata@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}coverage>0:devel/py-coverage@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}coveralls>0:devel/py-coveralls@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pycodestyle>0:devel/py-pycodestyle@${PY_FLAVOR}
TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

USES=		python
USE_PYTHON=	pep517 autoplist pytest # 3 tests fail, see https://github.com/CastXML/pygccxml/issues/182

USE_GITHUB=	yes
GH_ACCOUNT=	CastXML

NO_ARCH=	yes

# tests as of 3.0.0: 1 failed, 283 passed in 4253.52s (1:10:53) (1 test fails because 'python' isn't found)

.include <bsd.port.mk>
