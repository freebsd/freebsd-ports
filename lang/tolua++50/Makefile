# New ports collection makefile for:    tolua++
# Date created:         18 Jan 2006
# Whom:                 aaron@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	tolua++
PORTVERSION=	1.0.92
CATEGORIES=	lang devel
MASTER_SITES=	http://www.codenix.com/~tolua/

MAINTAINER=	aaron@FreeBSD.org
COMMENT=	An extended version of tolua, a tool to integrate C/C++ code with Lua

LIB_DEPENDS=	lua:${PORTSDIR}/lang/lua50

USE_BZIP2=	yes
USE_LDCONFIG=	yes
USE_SCONS=	yes
SCONS_ARGS=	prefix=${PREFIX}

CFLAGS+=	-I/usr/local/include/lua50
LDFLAGS+=	-L/usr/local/lib/lua50

.include <bsd.port.mk>
