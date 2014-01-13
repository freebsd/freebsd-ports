# Created by: Olivier Duchateau <duchateau.olivier@gmail.com>
# $FreeBSD$

PORTNAME=	bjoern
PORTVERSION=	1.3.4
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	olivierd@FreeBSD.org
COMMENT=	Fast Python WSGI server

LICENSE=	BSD

LIB_DEPENDS=	ev:${PORTSDIR}/devel/libev

USE_PYTHON=	2
USE_PYDISTUTILS=	yes

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -lc

PLIST_FILES=	%%PYTHON_SITELIBDIR%%/${PORTNAME}.so

NO_STAGE=	yes
.include <bsd.port.mk>
