# Created by: Kubilay Kocak <koobs@FreeBSD.org>

PORTNAME=	libnacl
PORTVERSION=	1.6.1
CATEGORIES=	security python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Python bindings for libsodium based on ctypes

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libsodium.so:security/libsodium

USES=		python:3.6+
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

do-test:
	@cd ${WRKSRC} && ${PYTHON_CMD} -m unittest discover --start-directory tests -v

.include <bsd.port.mk>
