PORTNAME=	tweepy
PORTVERSION=	4.10.0
DISTVERSIONPREFIX=	v
CATEGORIES=	net python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Twitter API library for Python

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}aiohttp>=3.7.3:www/py-aiohttp@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oauthlib>=3.2.0:security/py-oauthlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests-oauthlib>=1.2.0:www/py-requests-oauthlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.27.0:www/py-requests@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}vcrpy>=1.10.3:devel/py-vcrpy@${PY_FLAVOR}

USES=		cpe python:3.7+
CPE_VENDOR=	josh_roesslein
USE_GITHUB=	yes
USE_PYTHON=	autoplist distutils

TEST_ENV=	USE_REPLAY=1

NO_ARCH=	yes

do-test:
	@cd ${WRKSRC} && ${SETENV} ${TEST_ENV} nosetests-${PYTHON_VER} -v tests.test_cursors tests.test_api tests.test_utils

.include <bsd.port.mk>
