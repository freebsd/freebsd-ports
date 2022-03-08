# Created by: Kubilay Kocak <koobs@FreeBSD.org>

PORTNAME=	praw
PORTVERSION=	6.2.0
DISTVERSIONPREFIX=v
CATEGORIES=	www python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Python Reddit API Wrapper

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}prawcore>=1.0.1,<2.0:www/py-prawcore@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}update_checker>=0.16:devel/py-update_checker@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}websocket-client>=0.54.0.0:www/py-websocket-client@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}mock>=0.8:devel/py-mock@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest>=2.7.3:devel/py-pytest@${PY_FLAVOR}
# to be ported	betamax >=0.8, <0.9
#		betamax-matchers >=0.3.0, <0.5
#		betamax-serializers >=0.2, <0.3

USES=		python:3.6+
USE_GITHUB=	yes # missing test data files
USE_PYTHON=	autoplist concurrent distutils

GH_ACCOUNT=	praw-dev

NO_ARCH=	yes

do-test:
	@cd ${WRKSRC} && ${PYTHON_CMD} ${PYDISTUTILS_SETUP} test

.include <bsd.port.mk>
