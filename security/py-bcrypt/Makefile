# Created by: Martin Wilke <miwi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	bcrypt
PORTVERSION=	0.4
PORTREVISION=	2
CATEGORIES=	security python
MASTER_SITES=	http://www.mindrot.org/files/py-bcrypt/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	py-${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Python bcrypt module

LICENSE=	MIT BSD3CLAUSE BSD4CLAUSE
LICENSE_COMB=	multi
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		python
USE_PYTHON=	distutils autoplist

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PROJECTHOST=	py-bcrypt

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/bcrypt/_bcrypt.so

.include <bsd.port.mk>
