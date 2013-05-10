# Created by: Skylord
# $FreeBSD$

PORTNAME=	luascript
PORTVERSION=	1.8.1
CATEGORIES=	net-p2p
PKGNAMEPREFIX=	verlihub-plugins-
MASTER_SITES=	SF/verlihub/VH_Lua/${DISTVERSION}

MAINTAINER=	me@skylord.ru

PLUGIN_NAME=	lua
PLUGIN_DESC=	LuaScript

USE_LUA=	5.1

WRKSRC=		${WRKDIR}/${DISTNAME}
CXXFLAGS+=	${LDFLAGS}
CPPFLAGS+=	-I${LUA_INCDIR}
LDFLAGS+=	-L${LUA_LIBDIR}

OPTIONS_DEFINE=	SOCKET
SOCKET_DESC=	Build with LuaSocket support

PLIST_FILES=	share/verlihub/scripts/ptokax.lua.inc \
		share/verlihub/scripts/ptokaxtest.lua \
		share/verlihub/scripts/script.lua
PLIST_DIRS=	share/verlihub/scripts

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSOCKET}
LUA_COMPS+=	socket:lib
CONFIGURE_ARGS+=	--with-luasocket

post-patch::
	@${REINPLACE_CMD} -e 's|-lluasocket|${LUA_MODLIBDIR}/socket/core.so|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|-lluamime|${LUA_MODLIBDIR}/mime/core.so|g' ${WRKSRC}/configure
.endif

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/net-p2p/verlihub-plugins/Makefile.plugins"

post-patch::
	@${REINPLACE_CMD} -e 's|for libpath in /|for libpath in ${PREFIX} /|g' ${WRKSRC}/config_lua

.include <bsd.port.post.mk>
