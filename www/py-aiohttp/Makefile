# Created by: Kubilay Kocak <koobs@FreeBSD.org>
# $FreeBSD$

PORTNAME=	aiohttp
PORTVERSION=	2.1.0
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	koobs@FreeBSD.org
COMMENT=	HTTP client/server for asyncio

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	cython:lang/cython
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}chardet>0:textproc/py3-chardet \
		${PYTHON_PKGNAMEPREFIX}multidict>0:www/py-multidict \
		${PYTHON_PKGNAMEPREFIX}yarl>0:www/py-yarl \
		${PYTHON_PKGNAMEPREFIX}async_timeout>0:devel/py-async_timeout
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>0:devel/py-pytest \
		${PYTHON_PKGNAMEPREFIX}pytest-timeout>0:devel/py-pytest-timeout \
		${PYTHON_PKGNAMEPREFIX}gunicorn>0:www/py-gunicorn

USES=		python:3.4+
USE_PYTHON=	autoplist distutils

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/aiohttp/*.so

do-test:
	@cd ${WRKSRC} && ${PYTHON_CMD} ${PYDISTUTILS_SETUP} test

.include <bsd.port.mk>
