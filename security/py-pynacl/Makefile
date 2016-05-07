# Created by: Yuri Victorovich <yuri@rawbw.com>
# $FreeBSD$

PORTNAME=	pynacl
PORTVERSION=	1.0.1
PORTREVISION=	1
CATEGORIES=	security python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	PyNaCl-${PORTVERSION}

MAINTAINER=	yuri@rawbw.com
COMMENT=	PyNaCl is a Python binding to the Networking and Cryptography library

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cffi>0:devel/py-cffi \
		${PYTHON_PKGNAMEPREFIX}six>0:devel/py-six
BUILD_DEPENDS=	${RUN_DEPENDS}
LIB_DEPENDS=	libsodium.so:security/libsodium

USES=		python
USE_PYTHON=	autoplist distutils
MAKE_ENV+=	SODIUM_INSTALL=system
CFLAGS+=	-I ${LOCALBASE}/include

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/nacl/_sodium.so

.include <bsd.port.mk>
