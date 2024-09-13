PORTNAME=	luasocket
PORTVERSION=	3.1.0
DISTVERSIONPREFIX=	v
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	net
PKGNAMEPREFIX=	${LUA_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Socket support for the Lua language
WWW=		https://lunarmodules.github.io/luasocket/ \
		https://github.com/lunarmodules/luasocket

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		gmake lua:module pkgconfig

CFLAGS+=	-DLUA_COMPAT_APIINTCASTS `pkgconf --cflags lua-${LUA_VER}`
INSTALL_TARGET=	install-unix
LDFLAGS+=	-shared `pkgconf --libs lua-${LUA_VER}`
MAKE_ARGS=	LUAV=${LUA_VER} PLAT=freebsd
MAKEFILE=	makefile

USE_GITHUB=	yes
GH_ACCOUNT=	lunarmodules

DOCSDIR=	${LUA_DOCSDIR}

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's|gcc|${CC}|g' ${WRKSRC}/src/makefile
	@${REINPLACE_CMD} -e 's|CFLAGS=|CFLAGS\+=|g' ${WRKSRC}/src/makefile
	@${REINPLACE_CMD} -e 's|LDFLAGS=|LDFLAGS\+=|g' ${WRKSRC}/src/makefile
	@${REINPLACE_CMD} -e 's/prefix/PREFIX/g' ${WRKSRC}/src/makefile

post-install:
	${STRIP_CMD} ${STAGEDIR}${LUA_MODLIBDIR}/*/*.so

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/* ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
