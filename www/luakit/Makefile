PORTNAME=	luakit
DISTVERSION=	2.3.6
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
		libsoup-2.4.so:devel/libsoup \
		libwebkit2gtk-4.0.so:www/webkit2-gtk3
RUN_DEPENDS=	${LUA_PKGNAMEPREFIX}luafilesystem>=0:devel/luafilesystem@${LUA_FLAVOR}

USES=		compiler:c++11-lang desktop-file-utils gettext-runtime gmake \
		gnome lua:51 pkgconfig sqlite
USE_GITHUB=	yes
USE_GNOME=	cairo gdkpixbuf2 glib20 gtk30

CONFLICTS_INSTALL=	luakit-devel

PORTSCOUT=	limit:^[2-9]\..*

PORTDATA=	*
PORTDOCS=	*

OPTIONS_DEFINE=		DOCS LUAJIT
OPTIONS_DEFAULT=	LUAJIT
LUAJIT_DESC=		Use the Just-In-Time compiler for lua
LUAJIT_USES=		luajit
LUAJIT_MAKE_ARGS=	USE_LUAJIT=1
LUAJIT_MAKE_ARGS_OFF=	USE_LUAJIT=0

post-patch:
	@${REINPLACE_CMD} -e 's|luakit/doc|doc/luakit| ; \
		s|/etc/xdg|${PREFIX}/etc/xdg| ; \
		s|-ggdb|| ; s|gtk-4.1|gtk-4.0|' \
		${WRKSRC}/config.mk
	@${REINPLACE_CMD} -e 's|bin/env lua|&${LUA_VER_STR}|' \
		${WRKSRC}/build-utils/gentokens.lua
	@${REINPLACE_CMD} -e 's|expr substr|echo| ; \
		s/ARCHIVE 1 /ARCHIVE | cut -b1-/' \
		${WRKSRC}/build-utils/getversion.sh

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/luakit \
		${STAGEDIR}${PREFIX}/lib/luakit/luakit.so

.include <bsd.port.mk>
