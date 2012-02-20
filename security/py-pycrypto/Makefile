# New ports collection makefile for: pycrypto
# Date created:		25 Oct 2002
# Whom:			nbm
#
# $FreeBSD$
#

PORTNAME=	pycrypto
PORTVERSION=	2.5
CATEGORIES=	security python
MASTER_SITES=	http://ftp.dlitz.net/pub/dlitz/crypto/pycrypto/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	k@stereochro.me
COMMENT=	The Python Cryptography Toolkit

USE_PYTHON=	yes
USE_PYDISTUTILS=yes
HAS_CONFIGURE=	yes
USE_AUTOTOOLS=	autoconf
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

LIB_DEPENDS+=	gmp.10:${PORTSDIR}/math/gmp

pre-patch:
	@${REINPLACE_CMD} -e "s|%%LOCALBASE%%|${LOCALBASE}|" ${WRKSRC}/setup.py

.include <bsd.port.mk>
