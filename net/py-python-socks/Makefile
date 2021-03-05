# Created by: Emanuel Haupt <ehaupt@FreeBSD.org>
# $FreeBSD$

PORTNAME=	python-socks
PORTVERSION=	1.2.2
CATEGORIES=	net python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Core proxy (SOCKS4, SOCKS5, HTTP tunneling) functionality for Python

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}asyncio>=3.0.1:devel/py-asyncio@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}curio>=1.4:devel/py-curio@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}trio>=0.16.0:net/py-trio@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
