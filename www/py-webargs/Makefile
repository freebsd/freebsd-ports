# $FreeBSD$

PORTNAME=	webargs
PORTVERSION=	6.1.0
CATEGORIES=	www devel python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	meka@tilda.center
COMMENT=	Python library for parsing and validating HTTP request objects

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}marshmallow>2.15.2:devel/py-marshmallow@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>0:devel/py-pytest@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mock>0:devel/py-mock@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}WebTest>0:www/py-WebTest@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}bottle>0:www/py-bottle@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tornado>=4.5.2:www/py-tornado@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Flask>=0.12.2:www/py-flask@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}falcon>=2.0:www/py-falcon@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}django*>=1.11.16:www/py-django22@${PY_FLAVOR}

# To be updated
# TEST_DEPENDS+= 	${PYTHON_PKGNAMEPREFIX}pyramid>=1.9.1:www/py-django22@${PY_FLAVOR}
# To be ported
# TEST_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}webapp2>=3.0.0b1:www/py-webapp2@${PY_FLAVOR}
#			${PYTHON_PKGNAMEPREFIX}webtest_aiohttp>=2.0.0:www/py-webtest_aiohttp@${PY_FLAVOR}

# Supports 2/3 but marshmallow 3.x is Python 3 only
# Requires a marshmallow2 (2.x) port
USES=		python:3.5+
USE_GITHUB=	yes # tests not packaged with PyPI sdist
USE_PYTHON=	autoplist concurrent distutils

GH_ACCOUNT=	marshmallow-code

TEST_ENV=	PYTHONPATH=${WRKSRC}/src

NO_ARCH=	yes

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHON_CMD} -m pytest -v -rs -o addopts= \
		--ignore-glob='*webapp2*' \
		--ignore-glob='*pyramid*' \
		--ignore-glob='*test_bottleparser*' \
		--ignore-glob='*test_aiohttpparser*'

.include <bsd.port.pre.mk>

.if ${PYTHON_VER} < 3
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}simplejson>=2.1.0:devel/py-simplejson@${PY_FLAVOR}
.endif

.include <bsd.port.post.mk>
