# New ports collection makefile for:	verlihub-plugins-luascript
# Date created:				3 May 2007
# Whom:					Skylord
#
# $FreeBSD$
#

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
CONFIGURE_ENV=	CXXFLAGS="${LDFLAGS}" CPPFLAGS="${CPPFLAGS}"
CPPFLAGS=	-I${LUA_INCDIR}
LDFLAGS=	-L${LUA_LIBDIR}

OPTIONS=	SOCKET "Build with LuaSocket support" Off

PLIST_FILES=	share/verlihub/scripts/ptokax.lua.inc \
		share/verlihub/scripts/ptokaxtest.lua \
		share/verlihub/scripts/script.lua
PLIST_DIRS=	share/verlihub/scripts

.include <bsd.port.options.mk>

.if defined(WITH_SOCKET)
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
