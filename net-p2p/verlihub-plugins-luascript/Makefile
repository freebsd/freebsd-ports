# Created by: Mikle Davidkin <skylord@vt.net.ru>
# $FreeBSD$

PORTNAME=	luascript
PORTVERSION=	1.8.1
PORTREVISION=	4
CATEGORIES=	net-p2p
PKGNAMEPREFIX=	verlihub-plugins-
MASTER_SITES=	SF/verlihub/VH_Lua/${DISTVERSION}

MAINTAINER=	me@skylord.ru

PLUGIN_NAME=	lua
PLUGIN_DESC=	LuaScript

USES=		lua:51

WRKSRC=		${WRKDIR}/${DISTNAME}
CXXFLAGS+=	${LDFLAGS}
CPPFLAGS+=	-I${LUA_INCDIR}
LDFLAGS+=	-L${LUA_LIBDIR}

PLIST_FILES=	share/verlihub/scripts/ptokax.lua.inc \
		share/verlihub/scripts/ptokaxtest.lua \
		share/verlihub/scripts/script.lua

OPTIONS_DEFINE=	SOCKET
SOCKET_DESC=	Build with LuaSocket support

.include "../verlihub-plugins/Makefile.plugins"
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSOCKET}
BUILD_DEPENDS+=	${LUA_MODLIBDIR}/socket/core.so:net/luasocket
RUN_DEPENDS+=	${LUA_MODLIBDIR}/socket/core.so:net/luasocket
CONFIGURE_ARGS+=	--with-luasocket
.endif

post-patch::
.if ${PORT_OPTIONS:MSOCKET}
	@${REINPLACE_CMD} -e 's|-lluasocket|${LUA_MODLIBDIR}/socket/core.so|g' \
		-e 's|-lluamime|${LUA_MODLIBDIR}/mime/core.so|g' \
		${WRKSRC}/configure
.endif
	@${REINPLACE_CMD} -e 's|llua5\.1|llua-${LUA_VER}|g' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|for libpath in /|for libpath in ${PREFIX} /|g' ${WRKSRC}/config_lua

.include <bsd.port.mk>
