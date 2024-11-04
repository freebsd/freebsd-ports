PORTNAME=	praw
DISTVERSION=	7.8.1
DISTVERSIONPREFIX=v
CATEGORIES=	www python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Python Reddit API Wrapper
WWW=		https://praw.readthedocs.io

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}flit-core>0:devel/py-flit-core@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}prawcore>=2.4:www/py-prawcore@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}update_checker>=0.18:devel/py-update_checker@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}websocket-client>=0.54.0.0:www/py-websocket-client@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}prawcore>=2.4:www/py-prawcore@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}update_checker>=0.18:devel/py-update_checker@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}websocket-client>=0.54.0.0:www/py-websocket-client@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}betamax>=0.8:devel/py-betamax@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.20.1:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}urllib3>=1.21.1:net/py-urllib3@${PY_FLAVOR}
# to be ported	betamax >=0.8, <0.9
#		betamax-matchers >=0.3.0, <0.5

USES=		python
USE_GITHUB=	yes # missing test data files
USE_PYTHON=	autoplist concurrent pep517 pytest

GH_ACCOUNT=	praw-dev

NO_ARCH=	yes

.include <bsd.port.mk>
