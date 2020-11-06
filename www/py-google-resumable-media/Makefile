# $FreeBSD$

PORTNAME=	google-resumable-media
PORTVERSION=	1.1.0
PORTREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Utilities for Google Media Downloads and Resumable Uploads

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}six>=0:devel/py-six@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

OPTIONS_DEFINE=	AIOHTTP REQUESTS
OPTIONS_DEFAULT=AIOHTTP REQUESTS
AIOHTTP_DESC=	Use aiohttp
REQUESTS_DESC=	Use requests

REQUESTS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}requests>=2.18.0:www/py-requests@${PY_FLAVOR}

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 3000
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}crcmod>=1.7:devel/py-crcmod@${PY_FLAVOR}
.endif

.if ${PYTHON_REL} >= 3500
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}google-crc32c>=1.0<2.0:devel/py-google-crc32c@${PY_FLAVOR}
.endif

.if ${PORT_OPTIONS:MAIOHTTP} && ${PYTHON_REL} >= 3600
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}aiohttp>=3.6.2<4.0.0:www/py-aiohttp@${PY_FLAVOR}
.endif

.include <bsd.port.post.mk>
