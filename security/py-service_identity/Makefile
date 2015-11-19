# Created by: Axel Rau <axel.rau@chaos1.de>
# $FreeBSD$

PORTNAME=	service_identity
PORTVERSION=	14.0.0
PORTREVISION=	2
CATEGORIES=	security python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	axel.rau@chaos1.de
COMMENT=	Service identity verification for pyOpenSSL

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}openssl>=0.14:${PORTSDIR}/security/py-openssl \
		${PYTHON_PKGNAMEPREFIX}pyasn1>=0.1.7:${PORTSDIR}/devel/py-pyasn1 \
		${PYTHON_PKGNAMEPREFIX}pyasn1-modules>=0.0.5:${PORTSDIR}/devel/py-pyasn1-modules \
		${PYTHON_PKGNAMEPREFIX}characteristic>=14.0.0:${PORTSDIR}/devel/py-characteristic

USES=		python
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
