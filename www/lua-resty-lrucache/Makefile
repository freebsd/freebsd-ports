# $FreeBSD$

PORTNAME=	lua-resty-lrucache
PORTVERSION=	0.10
DISTVERSIONPREFIX=v
CATEGORIES=	www

MAINTAINER=	dmitry.wagin@ya.ru
COMMENT=	Lua-land LRU cache based on the LuaJIT FFI

LICENSE=	BSD2CLAUSE

RUN_DEPENDS=	luajit-openresty>=2.1:lang/luajit-openresty

USE_GITHUB=	yes
GH_ACCOUNT=	openresty

NO_ARCH=	yes
NO_BUILD=	yes

LUA_MODSHAREDIR=${LOCALBASE}/share/lua/5.1

PLIST_FILES+=	${LUA_MODSHAREDIR}/resty/lrucache.lua \
		${LUA_MODSHAREDIR}/resty/lrucache/pureffi.lua

do-install:
	@${MKDIR} ${STAGEDIR}${LUA_MODSHAREDIR}
	@(cd ${WRKSRC}/lib && ${COPYTREE_SHARE} . ${STAGEDIR}${LUA_MODSHAREDIR} "-name *\.lua")

.include <bsd.port.mk>
