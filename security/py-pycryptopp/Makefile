# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	pycryptopp
PORTVERSION=	0.5.29
PORTREVISION=	2
CATEGORIES=	security python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Python Wrappers for the Crypto++ Library

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}darcsver>0:${PORTSDIR}/devel/py-darcsver \
		${PYTHON_PKGNAMEPREFIX}setuptools_darcs>0:${PORTSDIR}/devel/py-setuptools_darcs
RUN_DEPENDS:=	${BUILD_DEPENDS}

USE_GCC=	yes
USES=		python
USE_PYTHON=	distutils autoplist

post-extract:
	@${REINPLACE_CMD} -e 's#<malloc.h>#<stdlib.h>#g' \
		${WRKSRC}/embeddedcryptopp/rijndael.cpp \
		${WRKSRC}/embeddedcryptopp/config.h \
		${WRKSRC}/embeddedcryptopp/secblock.h

.include <bsd.port.mk>
