# New ports collection makefile for: pycryptopp
# Date created:		30 August 2008
# Whom:			Wen Heping <wenheping@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	pycryptopp
PORTVERSION=	0.5.19
CATEGORIES=	security python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Python Wrappers for the Crypto++ Library

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}darcsver>0:${PORTSDIR}/devel/py-darcsver \
		${PYTHON_PKGNAMEPREFIX}setuptools_darcs>0:${PORTSDIR}/devel/py-setuptools_darcs
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_PYTHON=	yes
USE_PYDISTUTILS=easy_install
PYEASYINSTALL_ARCHDEP=	yes

post-extract:
	@${REINPLACE_CMD} -e 's#<malloc.h>#<stdlib.h>#g' \
		${WRKSRC}/cryptopp/rijndael.cpp \
		${WRKSRC}/cryptopp/config.h \
		${WRKSRC}/cryptopp/secblock.h

.include <bsd.port.mk>
