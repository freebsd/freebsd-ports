# Created by: Andrew Lewis <freeghb@gmail.com>
# $FreeBSD$

PORTNAME=	luasec
PORTVERSION=	0.5
CATEGORIES=	security
MASTER_SITES=	https://github.com/brunoos/${PORTNAME}/archive/
PKGNAMEPREFIX=	${LUA_PKGNAMEPREFIX}

MAINTAINER=	lx@FreeBSD.org
COMMENT=	Lua binding for the OpenSSL library to provide TLS/SSL communication

FETCH_ARGS=	-Fpr
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTNAME}-${PORTVERSION}

ALL_TARGET=	bsd
LIBDIR=		-L${LUA_LIBDIR} -L${WRKSRC}/src/luasocket
MAKE_ENV+=	INCDIR="-I${LUA_INCDIR} -I${WRKSRC}/src" LUAPATH=${LUA_MODSHAREDIR} \
		CPATH=${LUA_MODLIBDIR}
USES=		lua:51
USE_OPENSSL=	yes

post-patch:	.SILENT
	${REINPLACE_CMD} -Ee '/\(INSTALL\)/s/-D //' \
		-e '/^LDFLAGS/s/\+=/=/' \
		-e 's/LUAPATH/LUA_MODSHAREDIR/' \
		-e 's/LUACPATH/LUA_MODLIBDIR/' \
		${WRKSRC}/src/Makefile
	${REINPLACE_CMD} -Ee '/^(INC|LIB)DIR/s/[^?]=/?=/' \
		${WRKSRC}/Makefile

.include <bsd.port.mk>
