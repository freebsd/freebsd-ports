PORTNAME=	webargs
DISTVERSION=	8.2.0
CATEGORIES=	www devel python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	meka@tilda.center
COMMENT=	Python library for parsing and validating HTTP request objects

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}marshmallow>2.15.2:devel/py-marshmallow@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}bottle>0:www/py-bottle@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}django*>=1.11.16:www/py-django32@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}falcon>=2.0:www/py-falcon@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Flask>=0.12.2:www/py-flask@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mock>0:devel/py-mock@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyramid>0:www/py-pyramid@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tornado>=4.5.2:www/py-tornado@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}WebTest>0:www/py-WebTest@${PY_FLAVOR}

USES=		cpe python:3.6+
CPE_VENDOR=	${PORTNAME}_project
USE_GITHUB=	yes # tests not packaged with PyPI sdist
GH_ACCOUNT=	marshmallow-code
USE_PYTHON=	autoplist concurrent distutils pytest

TEST_ENV=	PYTHONPATH=${WRKSRC}/src

NO_ARCH=	yes

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHON_CMD} -m pytest -v -rs -o addopts= \
		--ignore-glob='*test_bottleparser*' \
		--ignore-glob='*test_aiohttpparser*' \
		--ignore-glob="*test_tornadoparser*"

.include <bsd.port.mk>
