PORTNAME=	luasec
PORTVERSION=	1.3.2
DISTVERSIONPREFIX=	v
CATEGORIES=	security
PKGNAMEPREFIX=	${LUA_PKGNAMEPREFIX}

MAINTAINER=	twm@pdp11.pw
COMMENT=	Lua binding for the OpenSSL library to provide TLS/SSL communication
WWW=		https://github.com/brunoos/luasec

LICENSE=	MIT

USES=		lua:module ssl

USE_GITHUB=	yes
GH_ACCOUNT=	brunoos

MAKE_ENV+=	LUAPATH=${LUA_MODSHAREDIR} LUACPATH=${LUA_MODLIBDIR} \
		INC_PATH=-I${LUA_INCDIR} LIB_PATH=-L${LUA_LIBDIR} \
		DESTDIR=${STAGEDIR}
ALL_TARGET=	bsd
CFLAGS+=	-I${OPENSSLINC}
LDFLAGS+=	-L${OPENSSLLIB}

post-install:
	${STRIP_CMD} ${STAGEDIR}${LUA_MODLIBDIR}/ssl.so

.include <bsd.port.mk>
