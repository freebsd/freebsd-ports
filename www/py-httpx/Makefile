# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	httpx
PORTVERSION=	0.17.0
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Next generation HTTP client

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.md

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}certifi>=0:security/py-certifi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}httpcore>=0.12<0.13:www/py-httpcore@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}idna>=0:dns/py-idna@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rfc3986>=1.3<2:www/py-rfc3986@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sniffio>=0:devel/py-sniffio@${PY_FLAVOR}

USES=		python:3.7+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

OPTIONS_DEFINE=	BROTLI HTTP2
OPTIONS_DEFAULT=HTTP2
BROTLI_DESC=	Brotli support
HTTP2_DESC=	HTTP/2 support

BROTLI_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}brotlipy>=0.7<0.8:archivers/py-brotlipy@${PY_FLAVOR}
HTTP2_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}h2>=3<5:www/py-h2@${PY_FLAVOR}

.include <bsd.port.mk>
