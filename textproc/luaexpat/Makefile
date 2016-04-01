# Created by: Andrew Lewis <freeghb@gmail.com>
# $FreeBSD$

PORTNAME=	luaexpat
PORTVERSION=	1.3.0
CATEGORIES=	textproc
MASTER_SITES=	http://matthewwild.co.uk/projects/luaexpat/ \
				http://redundancy.redundancy.org/mirror/
PKGNAMEPREFIX=	${LUA_PKGNAMEPREFIX}

MAINTAINER=	lx@FreeBSD.org
COMMENT=	LuaExpat is a SAX XML parser based on the Expat library

LIB_DEPENDS=	libexpat.so:textproc/expat2

USES=		gmake lua:51
ALL_TARGET=	lib
CFLAGS+=	-DLUA_INT_LONG

CFLAGS+=	-fPIC
LDFLAGS+=	-L${LOCALBASE}/lib
MAKE_ENV=	LUA_CDIR=${LUA_MODLIBDIR} LUA_LDIR=${LUA_MODSHAREDIR} LUA_INC="-I${LUA_INCDIR}" EXPAT_INC="-I${LOCALBASE}/include"

.include <bsd.port.mk>
