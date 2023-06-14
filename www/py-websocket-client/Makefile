PORTNAME=	websocket-client
PORTVERSION=	1.4.2
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	alfred@FreeBSD.org
COMMENT=	Websocket client for python
WWW=		https://github.com/websocket-client/websocket-client

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>0:devel/py-pytest@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

OPTIONS_DEFINE=		OPTIONAL TEST
OPTIONS_DEFAULT=	OPTIONAL TEST
OPTIONAL_DESC=		SOCKS proxy support and performance boost
TEST_DESC=		Run unit tests using a local echo server

OPTIONAL_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}python-socks>0:net/py-python-socks@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}wsaccel>0:www/py-wsaccel@${PY_FLAVOR}

TEST_TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}websockets>0:devel/py-websockets@${PY_FLAVOR}

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MTEST}
TEST_ENV=	LOCAL_WS_SERVER_PORT=8765
.endif

do-test:
.if ${PORT_OPTIONS:MTEST}
	@(cd ${TEST_WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHON_CMD} websocket/tests/echo-server.py &)
.endif
	@(cd ${TEST_WRKSRC} && ${SETENV} ${TEST_ENV} pytest -v -ra)

.include <bsd.port.mk>
