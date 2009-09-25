# New ports collection makefile for:	py-sympy
# Date created:		2008-08-09
# Whom:			Wen Heping <wenheping@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	sympy
PORTVERSION=	0.6.5
CATEGORIES=	math python
MASTER_SITES=	GOOGLE_CODE \
		CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	A Python Library For Symbolic Mathematics

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

MAN1=	isympy.1

post-patch:
	@${REINPLACE_CMD} -e "s#share/man/man1#man/man1#" ${WRKSRC}/setup.py

.include <bsd.port.mk>
