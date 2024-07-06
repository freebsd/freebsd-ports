PORTNAME=	luaexpat
PORTVERSION=	1.5.2
CATEGORIES=	textproc
PKGNAMEPREFIX=	${LUA_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	SAX XML parser based on the Expat library
WWW=		https://lunarmodules.github.io/luaexpat/ \
		https://github.com/lunarmodules/luaexpat

LICENSE=	MIT

LIB_DEPENDS=	libexpat.so:textproc/expat2

USES=		gmake lua:module

USE_GITHUB=	yes
GH_ACCOUNT=	lunarmodules

ALL_TARGET=	lib
CFLAGS+=	-fPIC
LDFLAGS+=	-L${LOCALBASE}/lib
MAKE_ARGS=	COMMON_CFLAGS=-Wall
MAKE_ENV=	EXPAT_INC=-I${LOCALBASE}/include LUA_CDIR=${LUA_MODLIBDIR} LUA_INC=-I${LUA_INCDIR} LUA_LDIR=${LUA_MODSHAREDIR} LUA_V=${LUA_VER}

post-install:
	${STRIP_CMD} ${STAGEDIR}${LUA_MODLIBDIR}/lxp.so

.include <bsd.port.mk>
