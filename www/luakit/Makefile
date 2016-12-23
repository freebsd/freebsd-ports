# Created by: gugabsd <gugabsd@mundounix.com.br>
# $FreeBSD$

PORTNAME=	luakit
PORTVERSION=	2012.09.13r1
PORTREVISION=	7
CATEGORIES=	www

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Fast, small, webkit based browser framework extensible by Lua

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING.GPLv3

BUILD_DEPENDS=	help2man:misc/help2man
LIB_DEPENDS=	libdbus-glib-1.so:devel/dbus-glib \
		libsoup-2.4.so:devel/libsoup \
		libfreetype.so:print/freetype2 \
		libwebkitgtk-1.0.so:www/webkit-gtk2 \
		libfontconfig.so:x11-fonts/fontconfig \
		libunique-1.0.so:x11-toolkits/unique
RUN_DEPENDS=	${LUA_PKGNAMEPREFIX}luafilesystem>=0:devel/luafilesystem-51

USE_GITHUB=	yes
GH_TAGNAME=	${PORTVERSION:C/r/-r/}

USES=		desktop-file-utils gettext-runtime gmake lua:51 pkgconfig sqlite
USE_GNOME=	cairo gdkpixbuf2 glib20 gtk20
MAKE_ARGS+=	USE_UNIQUE=1 NO_JAVASCRIPTCORE=1

BROKEN_sparc64=	Does not install on sparc64

OPTIONS_DEFINE=	LUAJIT
LUAJIT_DESC=	Use the Just-In-Time compiler for lua
LUAJIT_LIB_DEPENDS=	libluajit-5.1.so:lang/luajit
LUAJIT_MAKE_ARGS=	USE_LUAJIT=1
LUAJIT_MAKE_ARGS_OFF=	USE_LUAJIT=0

post-patch:
	@${REINPLACE_CMD} -e 's|(DESTDIR)/usr|(INSTALLDIR)|' \
		-e 's|(DESTDIR)|(INSTALLDIR)|' ${WRKSRC}/Makefile
	@${SED} -I "" 's|/etc/xdg/luakit|${LOCALBASE}&|' \
		${WRKSRC}/lib/lousy/util.lua
	@${REINPLACE_CMD} -e \
		's|share/man|man| ; s|luakit/docs|doc/luakit| ; \
		/MANPREFIX */s|?=|=|' \
		${WRKSRC}/config.mk
	@${REINPLACE_CMD} -e 's|bin/env lua|&${LUA_VER_STR}|' \
		${WRKSRC}/build-utils/gentokens.lua
	@${REINPLACE_CMD} -e 's|/usr/share|${LOCALBASE}/share|' \
		${WRKSRC}/config/window.lua

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/luakit

.include <bsd.port.mk>
