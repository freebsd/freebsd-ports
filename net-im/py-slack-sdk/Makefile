PORTNAME=	slack-sdk
PORTVERSION=	3.15.2
DISTVERSIONPREFIX=	v
CATEGORIES=	net-im python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Slack SDK for several API

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}aiohttp>3.5.2:www/py-aiohttp@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>0:devel/py-pytest@${PY_FLAVOR}

USES=		python:3.6+
# PyPi sdist do not have tests
USE_GITHUB=	yes
GH_ACCOUNT=	slackapi
GH_PROJECT=	python-${PORTNAME}
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

OPTIONS_DEFINE=		ASYNCDNS
OPTIONS_DEFAULT=	ASYNCDNS

ASYNCDNS_DESC=	Asyncronous DNS support

ASYNCDNS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}aiodns>1.0:dns/py-aiodns@${PY_FLAVOR}

do-test:
	@cd ${WRKSRC} && ${PYTHON_CMD} -m pytest -v -rs

.include <bsd.port.mk>
