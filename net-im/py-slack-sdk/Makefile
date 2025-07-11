PORTNAME=	slack-sdk
DISTVERSIONPREFIX=	v
DISTVERSION=	3.36.0
CATEGORIES=	net-im python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Slack SDK for several API
WWW=		https://slack.dev/python-slack-sdk/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}aiohttp>=3.7.3:www/py-aiohttp@${PY_FLAVOR}

USES=		python
# PyPi sdist do not have tests
USE_GITHUB=	yes
GH_ACCOUNT=	slackapi
GH_PROJECT=	python-${PORTNAME}
USE_PYTHON=	autoplist pep517 pytest

NO_ARCH=	yes

OPTIONS_DEFINE=		ASYNCDNS
OPTIONS_DEFAULT=	ASYNCDNS

ASYNCDNS_DESC=	Asyncronous DNS support

ASYNCDNS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}aiodns>1.0:dns/py-aiodns@${PY_FLAVOR}

.include <bsd.port.mk>
