# New ports collection makefile for:    luasec
# Date created:				25 June 2009
# Whom:					Andrew Lewis <freeghb@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	luasec
PORTVERSION=	0.3.2
CATEGORIES=	security
MASTER_SITES=	http://luaforge.net/frs/download.php/4059/
PKGNAMEPREFIX=	${LUA_PKGNAMEPREFIX}

MAINTAINER=	freeghb@gmail.com
COMMENT=	A Lua binding for the OpenSSL library to provide TLS/SSL communication

RUN_DEPENDS+=	${LUA_MODLIBDIR}/socket/core.so:${PORTSDIR}/net/luasocket

ALL_TARGET=	bsd
LIBDIR=		-L${LUA_LIBDIR}
MAKE_ENV+=	INCDIR=-I${LUA_INCDIR}
USE_LUA=	5.1
WANT_LUA_VER=	5.1

.include <bsd.port.mk>
