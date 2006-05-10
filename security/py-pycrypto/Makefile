# New ports collection makefile for: pycrypto
# Date created:		25 Oct 2002
# Whom:			nbm
#
# $FreeBSD$
#

PORTNAME=	pycrypto
PORTVERSION=	2.0.1
PORTREVISION=	1
CATEGORIES=	security python
MASTER_SITES=	http://www.amk.ca/files/python/crypto/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The Python Cryptography Toolkit

USE_PYTHON=	yes
USE_PYDISTUTILS=yes
USE_REINPLACE=	yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 500000
LIB_DEPENDS+=	gmp.7:${PORTSDIR}/math/libgmp4
.endif

pre-configure:
	@${REINPLACE_CMD} -e "s|%%LOCALBASE%%|${LOCALBASE}|" ${WRKSRC}/setup.py

.include <bsd.port.post.mk>
