PORTNAME=	luakit
DISTVERSION=	2.4.0
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	www

MAINTAINER=	mew14930xvi@inbox.lv
COMMENT=	Fast, small, webkit2 based browser framework extensible with Lua
WWW=		https://luakit.github.io

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING.GPLv3

BUILD_DEPENDS=	${LUA_MODLIBDIR}/lfs.so:devel/luafilesystem@${LUA_FLAVOR}
LIB_DEPENDS=	libharfbuzz.so:print/harfbuzz \
		libsoup-3.0.so:devel/libsoup3 \
		libwebkit2gtk-4.1.so:www/webkit2-gtk@41
RUN_DEPENDS=	${LUA_PKGNAMEPREFIX}luafilesystem>=0:devel/luafilesystem@${LUA_FLAVOR}

USES=		compiler:c++11-lang desktop-file-utils gettext-runtime gmake \
		gnome lua:51 pkgconfig shebangfix sqlite
USE_GITHUB=	yes
USE_GNOME=	glib20 gtk30
SHEBANG_FILES=	build-utils/gentokens.lua

CONFLICTS_INSTALL=	luakit-devel

PORTSCOUT=	limit:^[2-9]\..*

PORTDATA=	*
PORTDOCS=	*

OPTIONS_DEFINE=		DOCS LUAJIT GSTREAMER
OPTIONS_DEFAULT=	LUAJIT
LUAJIT_DESC=		Use the Just-In-Time compiler for lua
LUAJIT_USES=		luajit
LUAJIT_MAKE_ARGS=	USE_LUAJIT=1
LUAJIT_MAKE_ARGS_OFF=	USE_LUAJIT=0
GSTREAMER_USES=		gstreamer
GSTREAMER_USE=		GSTREAMER=good,libav

post-patch:
	@${REINPLACE_CMD} -e 's|luakit/doc|doc/luakit| ; \
		s|/etc/xdg|${PREFIX}/etc/xdg| ; s|-ggdb||' \
		${WRKSRC}/config.mk

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/luakit \
		${STAGEDIR}${PREFIX}/lib/luakit/luakit.so

.include <bsd.port.mk>
