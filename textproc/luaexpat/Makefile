# New ports collection makefile for:    luaexpat
# Date created:				25 June 2009
# Whom:					Andrew Lewis <dru@silenceisdefeat.net>
#
# $FreeBSD$
#

PORTNAME=	luaexpat
PORTVERSION=	1.1
CATEGORIES=	textproc
MASTER_SITES=	http://luaforge.net/frs/download.php/2469/
PKGNAMEPREFIX=	${LUA_PKGNAMEPREFIX}

MAINTAINER=	dru@silenceisdefeat.net
COMMENT=	LuaExpat is a SAX XML parser based on the Expat library

LIB_DEPENDS=	expat.6:${PORTSDIR}/textproc/expat2

ONLY_FOR_ARCHS=	i386

MAKEFILE=	makefile
ALL_TARGET=	lib
USE_LUA=	5.0-5.1
WANT_LUA_VER=	5.1

CFLAGS+=	-fPIC

.if ${USE_LUA} == 5.0
BUILD_DEPENDS+=	${NONEXISTENT}:${PORTSDIR}/devel/lua50-compat51:build
.endif

.include <bsd.port.mk>
