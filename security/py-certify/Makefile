# New ports collection makefile for: py-certifi
# Date created:		2012-01-02
# Whom:		Olivier Duchateau <duchateau.olivier@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	certifi
PORTVERSION=	0.0.6
CATEGORIES=	security python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	duchateau.olivier@gmail.com
COMMENT=	Mozilla's SSL certificates

USE_PYTHON=	2.6+
USE_PYDISTUTILS=	yes

post-install:
	@${REINPLACE_CMD} -e 's|    include_|   #include_|' ${WRKSRC}/setup.py

.include <bsd.port.mk>
