# Created by: Martin Wilke <miwi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	bcrypt
PORTVERSION=	0.4
PORTREVISION=	1
CATEGORIES=	security python
MASTER_SITES=	GOOGLE_CODE \
		http://www.mindrot.org/files/py-bcrypt/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	py-${PORTNAME}-${PORTVERSION}

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	Python bcrypt module

USES=		python
USE_PYTHON=	distutils autoplist

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PROJECTHOST=	py-bcrypt

.include <bsd.port.mk>
