# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>

PORTNAME=	aioquic
PORTVERSION=	0.9.19
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Implementation of QUIC and HTTP/3

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}certifi>=0:security/py-certifi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cryptography>=3.1:security/py-cryptography@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pylsqpack>=0.3.3<0.4.0:www/py-pylsqpack@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}openssl>=20:security/py-openssl@${PY_FLAVOR}

USES=		python:3.7+ ssl
USE_PYTHON=	autoplist concurrent distutils

post-install:
	${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR} -name '*.so' -exec ${STRIP_CMD} {} +

.include <bsd.port.mk>
