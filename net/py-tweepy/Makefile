PORTNAME=	tweepy
DISTVERSIONPREFIX=	v
DISTVERSION=	4.16.0
CATEGORIES=	net python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Library for accessing the X API (Twitter)
WWW=		https://github.com/tweepy/tweepy

LICENSE=	MIT

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}flit-core>=0:devel/py-flit-core@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}oauthlib>=3.2.0:security/py-oauthlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests-oauthlib>=1.2.0:www/py-requests-oauthlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.27.0:www/py-requests@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}vcrpy>=1.10.3:devel/py-vcrpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}urllib3<2:net/py-urllib3@${PY_FLAVOR}

USES=		cpe python
CPE_VENDOR=	josh_roesslein
USE_GITHUB=	yes
USE_PYTHON=	autoplist pep517

TEST_ENV=	USE_REPLAY=1

NO_ARCH=	yes

OPTIONS_DEFINE=	ASYNC
OPTIONS_DEFAULT=ASYNC

ASYNC_DESC=	Enable async support

ASYNC_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}aiohttp>=3.7.3:www/py-aiohttp@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}async-lru>=1.0.3:devel/py-async-lru@${PY_FLAVOR}

do-test:
	@cd ${WRKSRC} && ${SETENV} ${TEST_ENV} nosetests-${PYTHON_VER} -v tests.test_cursors tests.test_api tests.test_utils

.include <bsd.port.mk>
