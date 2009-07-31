# New ports collection makefile for:    luasec
# Date created:				25 June 2009
# Whom:					Andrew Lewis <freeghb@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	luasec
PORTVERSION=	0.3.3
CATEGORIES=	security
MASTER_SITES=	http://luaforge.net/frs/download.php/4160/
PKGNAMEPREFIX=	${LUA_PKGNAMEPREFIX}

MAINTAINER=	kelly.hays@jkhfamily.org
COMMENT=	A Lua binding for the OpenSSL library to provide TLS/SSL communication

RUN_DEPENDS+=	${LUA_MODLIBDIR}/socket/core.so:${PORTSDIR}/net/luasocket

ALL_TARGET=	bsd
LIBDIR=		-L${LUA_LIBDIR}
MAKE_ENV+=	INCDIR=-I${LUA_INCDIR} LUAPATH=${LUA_MODSHAREDIR} \
		CPATH=${LUA_MODLIBDIR}
USE_LUA=	5.1
WANT_LUA_VER=	5.1
USE_OPENSSL=	yes

.include <bsd.port.options.mk>

# NOTE: OSVERSION is already defined here, and USE_OPENSSL_PORT
# should be defined before pre.mk, that's why options.mk is used

.if ${OSVERSION} < 700024
USE_OPENSSL_PORT=yes
.endif

.include <bsd.port.mk>
