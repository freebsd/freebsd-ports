# Created by: Andrew Lewis <freeghb@gmail.com>

PORTNAME=	luaexpat
PORTVERSION=	1.3.0
PORTREVISION=	5
CATEGORIES=	textproc
MASTER_SITES=	https://matthewwild.co.uk/projects/luaexpat/
PKGNAMEPREFIX=	${LUA_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	SAX XML parser based on Expat library

LICENSE=	MIT

LIB_DEPENDS=	libexpat.so:textproc/expat2

USES=		gmake lua:module

ALL_TARGET=	lib
CFLAGS+=	-fPIC
LDFLAGS+=	-L${LOCALBASE}/lib
MAKE_ARGS=	COMMON_CFLAGS="-Wall"
MAKE_ENV=	EXPAT_INC=-I${LOCALBASE}/include LUA_CDIR=${LUA_MODLIBDIR} LUA_INC=-I${LUA_INCDIR} LUA_LDIR=${LUA_MODSHAREDIR}

.include <bsd.port.mk>
