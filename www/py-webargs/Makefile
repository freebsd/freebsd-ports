PORTNAME=	webargs
DISTVERSION=	8.7.1
CATEGORIES=	www devel python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	meka@tilda.center
COMMENT=	Python library for parsing and validating HTTP request objects
WWW=		https://github.com/marshmallow-code/webargs

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}flit-core>0:devel/py-flit-core@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}marshmallow>2.15.2:devel/py-marshmallow@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packaging>=0:devel/py-packaging@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}bottle>0:www/py-bottle@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}django*>=1.11.16:www/py-django42@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}falcon>=2.0:www/py-falcon@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}flask>=0.12.2:www/py-flask@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mock>0:devel/py-mock@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyramid>0:www/py-pyramid@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-asyncio>0:devel/py-pytest-asyncio@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tornado>=4.5.2:www/py-tornado@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}webtest>0:www/py-webtest@${PY_FLAVOR}

USES=		cpe python
CPE_VENDOR=	${PORTNAME}_project
USE_GITHUB=	yes # tests not packaged with PyPI sdist
GH_ACCOUNT=	marshmallow-code
USE_PYTHON=	autoplist concurrent pep517 pytest
TEST_ARGS=	--ignore-glob='*test_bottleparser*' \
		--ignore-glob='*test_aiohttpparser*' \
		--ignore-glob='*test_tornadoparser*'

TEST_ENV=	PYTHONPATH=${WRKSRC}/src

NO_ARCH=	yes

.include <bsd.port.mk>
