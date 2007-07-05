# New ports collection makefile for:	verlihub-plugins-luascript
# Date created:				3 May 2007
# Whom:					Skylord
#
# $FreeBSD$
#

PORTNAME=	luascript
PORTVERSION=	1.6
CATEGORIES=	net-p2p

MAINTAINER=	skylord@vt.net.ru
COMMENT=	LuaScript plugin for the VerliHub - a Direct Connect protocol server (Hub)

PLUGIN_NAME=	lua

USE_LUA=	5.1
CONFIGURE_ENV=	CXXFLAGS="${LDFLAGS}" CPPFLAGS="${CPPFLAGS}"
CPPFLAGS=	-I${LUA_INCDIR}
LDFLAGS=	-L${LUA_LIBDIR}

PLIST_FILES=	share/verlihub/scripts/google.lua \
		share/verlihub/scripts/lua4to5.lua.inc \
		share/verlihub/scripts/ptokax.lua.inc \
		share/verlihub/scripts/ptokaxtest.lua \
		share/verlihub/scripts/script.lua \
		share/verlihub/scripts/trivia.lua
PLIST_DIRS=	share/verlihub/scripts

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/net-p2p/verlihub-plugins/Makefile.plugins"
.include <bsd.port.post.mk>
