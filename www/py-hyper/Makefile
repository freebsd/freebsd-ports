# Created by: Kubilay Kocak <koobs@FreeBSD.org>
# $FreeBSD$

PORTNAME=	hyper
PORTVERSION=	0.3.1
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	koobs@FreeBSD.org
COMMENT=	HTTP/2 Client for Python

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		python
USE_PYTHON=	autoplist distutils

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} == 330 || (${PYTHON_VER} == 2.7 && ${PYTHON_REL} < 279)
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}openssl>=0.14:${PORTSDIR}/security/py-openssl
.endif

.include <bsd.port.post.mk>
