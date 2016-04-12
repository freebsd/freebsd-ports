# Created by: Kubilay Kocak <koobs@FreeBSD.org>
# $FreeBSD$

PORTNAME=	praw
PORTVERSION=	3.4.0
DISTVERSIONPREFIX=	v
CATEGORIES=	www python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	koobs@FreeBSD.org
COMMENT=	Python Reddit API Wrapper

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}decorator>=4.0.9:devel/py-decorator \
		${PYTHON_PKGNAMEPREFIX}requests>=2.3.0:www/py-requests \
		${PYTHON_PKGNAMEPREFIX}six>=1.10:devel/py-six \
		${PYTHON_PKGNAMEPREFIX}update_checker>=0.11:devel/py-update_checker
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}mock>=1.0.1:devel/py-mock

# TEST_DEPENDS to be ported
# betamax >=0.5.1
# betamax-matchers >=0.2.0
# betamax-serializers >=0.1.1

USES=		python
USE_GITHUB=	yes
USE_PYTHON=	autoplist concurrent distutils

GH_ACCOUNT=	praw-dev

do-test:
	@cd ${WRKSRC} && ${PYTHON_CMD} ${PYDISTUTILS_SETUP} test

.include <bsd.port.mk>
