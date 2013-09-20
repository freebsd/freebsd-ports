# Created by: Andrew Lewis <freeghb@gmail.com>
# $FreeBSD$

PORTNAME=	luasec
PORTVERSION=	0.4
CATEGORIES=	security
MASTER_SITES=	http://www.inf.puc-rio.br/~brunoos/luasec/download/
PKGNAMEPREFIX=	${LUA_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Lua binding for the OpenSSL library to provide TLS/SSL communication

RUN_DEPENDS+=	${LUA_MODLIBDIR}/socket/core.so:${PORTSDIR}/net/luasocket

ALL_TARGET=	bsd
LIBDIR=		-L${LUA_LIBDIR}
MAKE_ENV+=	INCDIR=-I${LUA_INCDIR} LUAPATH=${LUA_MODSHAREDIR} \
		CPATH=${LUA_MODLIBDIR}
USE_LUA=	5.1
WANT_LUA_VER=	5.1
USE_OPENSSL=	yes

NO_STAGE=	yes
.include <bsd.port.options.mk>

# NOTE: OSVERSION is already defined here, and USE_OPENSSL_PORT
# should be defined before pre.mk, that's why options.mk is used

.if ${OSVERSION} < 700024
USE_OPENSSL_PORT=yes
.endif

post-patch:	.SILENT
	${REINPLACE_CMD} -Ee '/^CC/s/=/?=/' \
		-e '/^LD/s/gcc/$$(CC)/' \
		-e '/^(C|LD)FLAGS/s/=/+=/' \
		-e '/^BSD/{s/-O[0-3]?//;}' \
		${WRKSRC}/src/Makefile

.include <bsd.port.mk>
