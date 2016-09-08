# Created by: Jan Hornyak <pav@oook.cz>
# $FreeBSD$

PORTNAME=	luasocket
PORTVERSION=	3.0r1
PORTREVISION=	2
CATEGORIES=	net
PKGNAMEPREFIX=	${LUA_PKGNAMEPREFIX}

MAINTAINER=	lx@FreeBSD.org
COMMENT=	IPv4 and IPv6 socket support for the Lua language

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	diegonehab
GH_TAGNAME=	v3.0-rc1

MAKE_ARGS=	LUA_VER=${LUA_VER}
USES=		gmake lua:51 pkgconfig
INSTALL_TARGET=	install-unix

CFLAGS+=	`pkgconf --cflags lua-${LUA_VER}`
LDFLAGS+=	-shared  `pkgconf --libs lua-${LUA_VER}`

OPTIONS_DEFINE=	DOCS

post-extract:
	@${MV} ${WRKSRC}/makefile ${WRKSRC}/Makefile
	@${MV} ${WRKSRC}/src/makefile ${WRKSRC}/src/Makefile
	@${REINPLACE_CMD} -e 's|gcc|${CC}|g' ${WRKSRC}/src/Makefile
	@${REINPLACE_CMD} -e 's|CFLAGS=|CFLAGS\+=|g' ${WRKSRC}/src/Makefile
	@${REINPLACE_CMD} -e 's|LDFLAGS=|LDFLAGS\+=|g' ${WRKSRC}/src/Makefile
	@${REINPLACE_CMD} -e 's/prefix/PREFIX/g' ${WRKSRC}/src/Makefile

post-install:
	@${STRIP_CMD} ${STAGEDIR}${LUA_MODLIBDIR:S|^${LOCALBASE}|${PREFIX}|}/*/*.so

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}/${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/* ${STAGEDIR}/${DOCSDIR}

.include <bsd.port.mk>
