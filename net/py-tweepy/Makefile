# Created by: Cheng-Lung Sung <clsung@FreeBSD.org>

PORTNAME=	tweepy
PORTVERSION=	3.10.0
DISTVERSIONPREFIX=	v
CATEGORIES=	net python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	koobs@FreeBSD.org
COMMENT=	Twitter API library for Python

LICENSE=	MIT

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pip>0:devel/py-pip@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}requests>=2.11.1:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests-oauthlib>0:www/py-requests-oauthlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=1.10.0:devel/py-six@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}nose>=1.3.3:devel/py-nose@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mock>=1.0.1:devel/py-mock@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}vcrpy>=1.10.3:devel/py-vcrpy@${PY_FLAVOR}

USES=		python
USE_GITHUB=	yes
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

TEST_ENV=	USE_REPLAY=1

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 30000
TEST_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}unittest2>0:devel/py-unittest2@${PY_FLAVOR}
.endif

do-test:
	@cd ${WRKSRC} && ${SETENV} ${TEST_ENV} nosetests-${PYTHON_VER} -v tests.test_cursors tests.test_api tests.test_utils

.include <bsd.port.post.mk>
