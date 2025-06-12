PORTNAME=	websocket-client
DISTVERSION=	1.8.0
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	websocket_client-${DISTVERSION}

MAINTAINER=	alfred@FreeBSD.org
COMMENT=	Websocket client for python
WWW=		https://github.com/websocket-client/websocket-client

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		python
USE_PYTHON=	autoplist distutils pytest

TEST_ENV=	LOCAL_WS_SERVER_PORT=8765

NO_ARCH=	yes

OPTIONS_DEFINE=		OPTIONAL TEST
OPTIONS_DEFAULT=	OPTIONAL TEST

OPTIONAL_DESC=	SOCKS proxy support and performance boost
TEST_DESC=	Run unit tests using a local echo server

OPTIONAL_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}python-socks>0:net/py-python-socks@${PY_FLAVOR}
TEST_TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}websockets>0:devel/py-websockets@${PY_FLAVOR}

pre-test-TEST-on:
	@(cd ${TEST_WRKSRC} && ${SETENVI} ${WRK_ENV} ${TEST_ENV} timeout 60 ${PYTHON_CMD} websocket/tests/echo-server.py &)

.include <bsd.port.mk>
