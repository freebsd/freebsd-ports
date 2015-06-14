# Created by: Kubilay Kocak <koobs@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libnacl
PORTVERSION=	1.4.2
PORTREVISION=	1
CATEGORIES=	security python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	koobs@FreeBSD.org
COMMENT=	Python bindings for libsodium/tweetnacl based on ctypes

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libsodium.so:${PORTSDIR}/security/libsodium

USES=		python
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
