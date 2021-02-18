# $FreeBSD$

PORTNAME=	luakit-devel
DISTVERSION=	2.2.1-16
DISTVERSIONSUFFIX=	-g61d0dc4
PORTEPOCH=	1
CATEGORIES=	www

MAINTAINER=	mbeis@xs4all.nl
COMMENT=	Fast, small, webkit2 based browser framework extensible with Lua

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING.GPLv3

NOT_FOR_ARCHS=	sparc64
NOT_FOR_ARCHS_REASON_sparc64=	Does not install on sparc64

BUILD_DEPENDS=	help2man:misc/help2man \
		${LUA_MODLIBDIR}/lfs.so:devel/luafilesystem@${LUA_FLAVOR}
LIB_DEPENDS=	libdbus-glib-1.so:devel/dbus-glib \
		libsoup-2.4.so:devel/libsoup \
		libfreetype.so:print/freetype2 \
		libwebkit2gtk-4.0.so:www/webkit2-gtk3 \
		libfontconfig.so:x11-fonts/fontconfig
RUN_DEPENDS=	${LUA_PKGNAMEPREFIX}luafilesystem>=0:devel/luafilesystem@${LUA_FLAVOR}

USES=		compiler:c++11-lang desktop-file-utils gettext-runtime gmake \
		gnome lua:51 pkgconfig sqlite
USE_GITHUB=	yes
GH_ACCOUNT=	luakit
GH_PROJECT=	luakit
USE_GNOME=	cairo gdkpixbuf2 glib20 gtk30

CONFLICTS_INSTALL=	luakit

OPTIONS_DEFINE=	DOCS LUAJIT
LUAJIT_DESC=	Use the Just-In-Time compiler for lua
LUAJIT_LIB_DEPENDS=	libluajit-5.1.so:lang/luajit
LUAJIT_MAKE_ARGS=	USE_LUAJIT=1
LUAJIT_MAKE_ARGS_OFF=	USE_LUAJIT=0

post-extract:
	@${REINPLACE_CMD} -e \
		's|share/man|man| ; s|luakit/doc|doc/luakit| ; \
		s|/etc/xdg|${PREFIX}/etc/xdg| ; /MANPREFIX */s|?=|=| ; \
		s|gnu99|gnu11| ; s|-ggdb||' \
		${WRKSRC}/config.mk
	@${REINPLACE_CMD} -e 's|bin/env lua|&${LUA_VER_STR}|' \
		${WRKSRC}/build-utils/gentokens.lua

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/luakit \
		${STAGEDIR}${PREFIX}/lib/luakit/luakit.so

.include <bsd.port.mk>
