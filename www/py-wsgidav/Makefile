# $FreeBSD$

PORTNAME=	WsgiDAV
PORTVERSION=	1.2.0
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ultima1252@gmail.com
COMMENT=	WSGI based WebDAV server for sharing resources

LICENSE=	MIT

NO_ARCH=	yes
USES=		python:2 zip
USE_PYTHON=	distutils autoplist

post-extract:
	${RM} -r ${WRKSRC}/tests

.include <bsd.port.mk>
