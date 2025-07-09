PORTNAME=	luakit
DISTVERSION=	2.3.6-7
DISTVERSIONSUFFIX=	-g0bc0e39
PORTREVISION=	3
PORTEPOCH=	2
CATEGORIES=	www
PKGNAMESUFFIX=	-devel

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Fast, small, webkit2 based browser framework extensible with Lua
WWW=		https://luakit.github.io

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING.GPLv3

BUILD_DEPENDS=	${LUA_MODLIBDIR}/lfs.so:devel/luafilesystem@${LUA_FLAVOR}
LIB_DEPENDS=	libharfbuzz.so:print/harfbuzz \
		libsoup-2.4.so:devel/libsoup \
		libwebkit2gtk-4.0.so:www/webkit2-gtk@40
RUN_DEPENDS=	${LUA_PKGNAMEPREFIX}luafilesystem>=0:devel/luafilesystem@${LUA_FLAVOR}

USES=		compiler:c++11-lang desktop-file-utils gmake \
		gnome lua:51 pkgconfig sqlite
USE_GITHUB=	yes
GH_ACCOUNT=	luakit
GH_PROJECT=	luakit
USE_GNOME=	cairo gdkpixbuf glib20 gtk30

MAKE_ARGS=	MANPREFIX=${PREFIX}/share/man
CONFLICTS_INSTALL=	luakit

PORTDATA=	*
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS LUAJIT
OPTIONS_DEFAULT=	LUAJIT
LUAJIT_DESC=	Use the Just-In-Time compiler for lua
LUAJIT_USES=		luajit
LUAJIT_MAKE_ARGS=	USE_LUAJIT=1
LUAJIT_MAKE_ARGS_OFF=	USE_LUAJIT=0

post-extract:
	@${REINPLACE_CMD} -e \
		's|luakit/doc|doc/luakit| ; \
		s|/etc/xdg|${PREFIX}/etc/xdg| ; \
		s|-ggdb||' \
		${WRKSRC}/config.mk
	@${REINPLACE_CMD} -e 's|bin/env lua|&${LUA_VER_STR}|' \
		${WRKSRC}/build-utils/gentokens.lua

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/luakit \
		${STAGEDIR}${PREFIX}/lib/luakit/luakit.so

.include <bsd.port.mk>
