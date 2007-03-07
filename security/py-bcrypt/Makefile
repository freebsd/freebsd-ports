# ex:ts=8
# Ports collection makefile for:	py-bcrypt
# Date created:			07 maerch, 2007
# Whom:				Martin Wilke <miwi@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	bcrypt
PORTVERSION=	0.1
CATEGORIES=	security python
MASTER_SITES=	http://www.mindrot.org/files/py-bcrypt/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	py-${PORTNAME}-${PORTVERSION}

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	Python bcrypt module

USE_PYTHON=	yes
USE_PYDISTUTILS=yes

CFLAGS+=	-I${LOCALBASE}/include
MAKE_ENV=	"LDFLAGS=-L${LOCALBASE}/lib"

.include <bsd.port.mk>
