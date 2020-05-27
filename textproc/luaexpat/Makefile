# Created by: Andrew Lewis <freeghb@gmail.com>
# $FreeBSD$

PORTNAME=	luaexpat
PORTVERSION=	1.3.0
PORTREVISION=	5
CATEGORIES=	textproc
MASTER_SITES=	http://matthewwild.co.uk/projects/luaexpat/ \
				http://redundancy.redundancy.org/mirror/
PKGNAMEPREFIX=	${LUA_PKGNAMEPREFIX}

MAINTAINER=	lx@FreeBSD.org
COMMENT=	SAX XML parser based on Expat library

LICENSE=	MIT

LIB_DEPENDS=	libexpat.so:textproc/expat2

USES=		lua:module
USES+=		gmake
ALL_TARGET=	lib

CFLAGS+=	-fPIC
LDFLAGS+=	-L${LOCALBASE}/lib
MAKE_ARGS+=	COMMON_CFLAGS="-Wall"
MAKE_ENV=	LUA_CDIR=${LUA_MODLIBDIR} LUA_LDIR=${LUA_MODSHAREDIR} LUA_INC="-I${LUA_INCDIR}" EXPAT_INC="-I${LOCALBASE}/include"

.include <bsd.port.mk>
