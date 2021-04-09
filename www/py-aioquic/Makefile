# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>

PORTNAME=	aioquic
PORTVERSION=	0.9.11
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Implementation of QUIC and HTTP/3

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}certifi>=0:security/py-certifi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cryptography>=2.5:security/py-cryptography@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pylsqpack>=0.3.3<0.4.0:www/py-pylsqpack@${PY_FLAVOR}

USES=		python:3.6+ ssl
USE_PYTHON=	autoplist concurrent distutils

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 30700
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}dataclasses>=0:devel/py-dataclasses@${PY_FLAVOR}
.endif

.include <bsd.port.post.mk>
