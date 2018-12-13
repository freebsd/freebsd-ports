# Created by: Andrew Lewis <freeghb@gmail.com>
# $FreeBSD$

PORTNAME=	luasec
PORTVERSION=	0.7
DISTVERSIONPREFIX=	${PORTNAME}-
CATEGORIES=	security
PKGNAMEPREFIX=	${LUA_PKGNAMEPREFIX}

MAINTAINER=	lx@FreeBSD.org
COMMENT=	Lua binding for the OpenSSL library to provide TLS/SSL communication

LICENSE=	MIT

USE_GITHUB=	yes
GH_ACCOUNT=	brunoos

ALL_TARGET=	bsd
LIBDIR=		-L${LUA_LIBDIR} -L${WRKSRC}/src/luasocket
MAKE_ENV+=	INCDIR="-I${LUA_INCDIR} -I${WRKSRC}/src" LUAPATH=${LUA_MODSHAREDIR} \
		CPATH=${LUA_MODLIBDIR} LD=${CC}
.if !defined(SLAVE_PORT)
USES=		lua ssl
.endif
CFLAGS+=	-I${OPENSSLINC} -DOPENSSL_NO_SSL3
LDFLAGS+=	-L${OPENSSLLIB}

post-patch:	.SILENT
	${REINPLACE_CMD} -Ee '/\(INSTALL\)/s/-D //' \
		-e '/^LDFLAGS/s/\+=/=/' \
		-e 's/LUAPATH/LUA_MODSHAREDIR/' \
		-e 's/LUACPATH/LUA_MODLIBDIR/' \
		${WRKSRC}/src/Makefile
	${REINPLACE_CMD} -Ee '/^(INC|LIB)DIR/s/[^?]=/?=/' \
		${WRKSRC}/Makefile

do-install:
	${MKDIR} ${STAGEDIR}${LUA_MODSHAREDIR}/ssl ${STAGEDIR}${LUA_MODLIBDIR}
	${INSTALL_LIB} ${WRKSRC}/src/ssl.so ${STAGEDIR}${LUA_MODLIBDIR}
	${INSTALL_DATA} ${WRKSRC}/src/ssl.lua ${STAGEDIR}${LUA_MODSHAREDIR}
	${INSTALL_DATA} ${WRKSRC}/src/https.lua ${STAGEDIR}${LUA_MODSHAREDIR}/ssl

.include <bsd.port.mk>
