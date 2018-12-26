# Created by: Stefan Hagen <ports@textmail.me>
# $FreeBSD$

PORTNAME=	luakit
PORTVERSION=	2017.08.10
PORTREVISION=	1
CATEGORIES=	www

MAINTAINER=	ports@textmail.me
COMMENT=	Fast, small, webkit2 based browser framework extensible with Lua

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING.GPLv3

NOT_FOR_ARCHS=	sparc64
NOT_FOR_ARCHS_REASON_sparc64=	Does not install on sparc64

BUILD_DEPENDS=	help2man:misc/help2man \
		${LUA_MODLIBDIR}/lfs.so:devel/luafilesystem-51
LIB_DEPENDS=	libdbus-glib-1.so:devel/dbus-glib \
		libsoup-2.4.so:devel/libsoup \
		libfreetype.so:print/freetype2 \
		libwebkit2gtk-4.0.so:www/webkit2-gtk3 \
		libfontconfig.so:x11-fonts/fontconfig
RUN_DEPENDS=	${LUA_PKGNAMEPREFIX}luafilesystem>=0:devel/luafilesystem-51

USES=		compiler:c++11-lang desktop-file-utils gettext-runtime gmake \
		lua:51 pkgconfig sqlite
USE_GITHUB=	yes
USE_GNOME=	cairo gdkpixbuf2 glib20 gtk30

MAKE_ARGS+=	DEVELOPMENT_PATHS=0

OPTIONS_DEFINE=	DOCS LUAJIT
LUAJIT_DESC=	Use the Just-In-Time compiler for lua
LUAJIT_LIB_DEPENDS=	libluajit-5.1.so:lang/luajit
LUAJIT_MAKE_ARGS=	USE_LUAJIT=1
LUAJIT_MAKE_ARGS_OFF=	USE_LUAJIT=0

post-patch:
	@${REINPLACE_CMD} -e \
		's|share/man|man| ; s|luakit/doc|doc/luakit| ; \
		s|/etc/xdg|${PREFIX}/etc/xdg| ; /MANPREFIX */s|?=|=|' \
		${WRKSRC}/config.mk
	@${REINPLACE_CMD} -e 's|bin/env lua|&${LUA_VER_STR}|' \
		${WRKSRC}/build-utils/gentokens.lua
	@${REINPLACE_CMD} -e 's|bin/env lua|&${LUA_VER_STR}|' \
		${WRKSRC}/lib/markdown.lua
	@${REINPLACE_CMD} -e 's|/usr/share|${LOCALBASE}/share|' \
		${WRKSRC}/config/window.lua

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/luakit

.include <bsd.port.mk>
