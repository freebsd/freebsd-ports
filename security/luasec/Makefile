# Created by: Andrew Lewis <freeghb@gmail.com>
# $FreeBSD$

PORTNAME=	luasec
PORTVERSION=	0.9
DISTVERSIONPREFIX=	v
CATEGORIES=	security
PKGNAMEPREFIX=	${LUA_PKGNAMEPREFIX}

MAINTAINER=	lx@FreeBSD.org
COMMENT=	Lua binding for the OpenSSL library to provide TLS/SSL communication

LICENSE=	MIT

.if !defined(SLAVE_PORT)
USES=		lua ssl
.endif

USE_GITHUB=	yes
GH_ACCOUNT=	brunoos

ALL_TARGET=	bsd
MAKE_ENV+=	LUAPATH=${LUA_MODSHAREDIR} LUACPATH=${LUA_MODLIBDIR} \
		INC_PATH=-I${LUA_INCDIR} LIB_PATH=-L${LUA_LIBDIR} \
		DESTDIR=${STAGEDIR}
CFLAGS+=	-I${OPENSSLINC} -DOPENSSL_NO_SSL3
LDFLAGS+=	-L${OPENSSLLIB}

.include <bsd.port.mk>
