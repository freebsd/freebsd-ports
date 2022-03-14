# Created by: Kubilay Kocak <koobs@FreeBSD.org>

PORTNAME=	slackclient
PORTVERSION=	2.9.3
CATEGORIES=	net-im python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Slack API clients for Web API and RTM API

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

DEPRECATED=	Use net-im/py-slack-sdk
EXPIRATION_DATE=	2022-06-30

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest-runner>0:devel/py-pytest-runner@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}aiohttp>3.5.2:www/py-aiohttp@${PY_FLAVOR}
#TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>0:devel/py-pytest@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

OPTIONS_DEFINE=		ASYNCDNS
OPTIONS_DEFAULT=	ASYNCDNS

ASYNCDNS_DESC=	Asyncronous DNS support

ASYNCDNS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}aiodns>1.0:dns/py-aiodns@${PY_FLAVOR}

# slackclient has been moved to slack-sdk and GH repo is unavailable
# do-test:
#	@cd ${WRKSRC} && ${PYTHON_CMD} -m pytest -v -rs

.include <bsd.port.mk>
