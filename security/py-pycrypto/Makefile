# New ports collection makefile for: pycrypto
# Date created:		25 Oct 2002
# Whom:			nbm
#
# $FreeBSD$
#

PORTNAME=	pycrypto
PORTVERSION=	2.0.1
PORTREVISION=	4
CATEGORIES=	security python
MASTER_SITES=	http://www.amk.ca/files/python/crypto/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	kmgaughan@eircom.net
COMMENT=	The Python Cryptography Toolkit

USE_PYTHON=	yes
USE_PYDISTUTILS=yes

LIB_DEPENDS+=	gmp.8:${PORTSDIR}/math/libgmp4

pre-configure:
	@${REINPLACE_CMD} -e "s|%%LOCALBASE%%|${LOCALBASE}|" ${WRKSRC}/setup.py

.include <bsd.port.pre.mk>

.if (${PYTHON_REL} >= 250)
EXTRA_PATCHES+=	${FILESDIR}/python25+.txt
.endif

.include <bsd.port.post.mk>
