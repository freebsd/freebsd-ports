PORTNAME=	slack-sdk
PORTVERSION=	3.26.1
DISTVERSIONPREFIX=	v
CATEGORIES=	net-im python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Slack SDK for several API
WWW=		https://slack.dev/python-slack-sdk/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}aiohttp>=3.7.3:www/py-aiohttp@${PY_FLAVOR}

USES=		python
# PyPi sdist do not have tests
USE_GITHUB=	yes
GH_ACCOUNT=	slackapi
GH_PROJECT=	python-${PORTNAME}
USE_PYTHON=	autoplist distutils pytest

NO_ARCH=	yes

OPTIONS_DEFINE=		ASYNCDNS
OPTIONS_DEFAULT=	ASYNCDNS

ASYNCDNS_DESC=	Asyncronous DNS support

ASYNCDNS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}aiodns>1.0:dns/py-aiodns@${PY_FLAVOR}

.include <bsd.port.mk>
