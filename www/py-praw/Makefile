PORTNAME=	praw
DISTVERSION=	8.0.0
DISTVERSIONPREFIX=v
CATEGORIES=	www python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Python Reddit API Wrapper
WWW=		https://praw.readthedocs.io

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>=0:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}defusedxml>=0.7.1:devel/py-defusedxml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}prawcore>=4:www/py-prawcore@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}update_checker>=1.0:devel/py-update_checker@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}websocket-client>=0.54.0.0:www/py-websocket-client@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}coverage>=7.14.1:devel/py-coverage@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.20.1:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}vcrpy>=8.1.1:devel/py-vcrpy@${PY_FLAVOR}

USES=		python
USE_GITHUB=	yes # missing test data files
USE_PYTHON=	autoplist concurrent pep517 pytest

GH_ACCOUNT=	praw-dev

NO_ARCH=	yes

.include <bsd.port.mk>
