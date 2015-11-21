# Created by: Muhammad Moinur Rahman <bofh@FreeBSD.org>
# $FreeBSD$

PORTNAME=	aiohttp
PORTVERSION=	0.16.3
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	HTTP client/server for asyncio

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}chardet>0:${PORTSDIR}/textproc/py3-chardet
TEST_DEPENDS:=	${RUN_DEPENDS} \
		${PYTHON_PKGNAMEPREFIX}nose>0:${PORTSDIR}/devel/py-nose \
		${PYTHON_PKGNAMEPREFIX}gunicorn>0:${PORTSDIR}/www/py-gunicorn

OPTIONS_DEFINE=		TESTS
TESTS_DESC=		Install test suite requirements
TESTS_BUILD_DEPENDS=	${TEST_DEPENDS}

USES=		python:3
USE_PYTHON=	autoplist distutils

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/aiohttp/_websocket.so
	${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/aiohttp/_multidict.so

regression-test: build
	@cd ${WRKSRC} && ${PYTHON_CMD} ${PYDISTUTILS_SETUP} test

.include <bsd.port.mk>
