PORTNAME=	praw
PORTVERSION=	7.7.0
DISTVERSIONPREFIX=v
CATEGORIES=	www python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Python Reddit API Wrapper
WWW=		https://praw.readthedocs.io

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}prawcore>=2.1:www/py-prawcore@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}update_checker>=0.18:devel/py-update_checker@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}websocket-client>=0.54.0.0:www/py-websocket-client@${PY_FLAVOR}
# to be ported	betamax >=0.8, <0.9
#		betamax-matchers >=0.3.0, <0.5
#		betamax-serializers >=0.2, <0.3

USES=		python
USE_GITHUB=	yes # missing test data files
USE_PYTHON=	autoplist concurrent distutils pytest

GH_ACCOUNT=	praw-dev

NO_ARCH=	yes

.include <bsd.port.mk>
