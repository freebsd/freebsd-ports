# Created by: Cheng-Lung Sung <clsung@FreeBSD.org>
# $FreeBSD$

PORTNAME=	tweepy
PORTVERSION=	3.5.0
DISTVERSIONPREFIX=	v
CATEGORIES=	net python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	koobs@FreeBSD.org
COMMENT=	Twitter API library for Python

LICENSE=	MIT

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pip>0:devel/py-pip@${FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}requests>=2.4.3:www/py-requests@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests-oauthlib>=0.4.1:www/py-requests-oauthlib@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=1.7.3:devel/py-six@${FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}nose>0:devel/py-nose@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mock>=1.0.1:devel/py-mock@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}vcrpy>=1.1.2:devel/py-vcrpy@${FLAVOR}

USES=		python
USE_GITHUB=	yes
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

TEST_ENV=	USE_REPLAY=1

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 3000
TEST_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}unittest2>0:devel/py-unittest2@${FLAVOR}
.endif

do-test:
	@cd ${WRKSRC} && ${SETENV} ${TEST_ENV} nosetests-${PYTHON_VER} -v tests.test_cursors tests.test_api tests.test_utils

.include <bsd.port.post.mk>
