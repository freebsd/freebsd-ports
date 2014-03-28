# Created by: gugabsd <gugabsd@mundounix.com.br>
# $FreeBSD$

PORTNAME=	luakit
PORTVERSION=	2012.09.13r1
CATEGORIES=	www

MAINTAINER=	gugabsd@mundounix.com.br
COMMENT=	Fast, small, webkit based browser framework extensible by Lua

LICENSE=	GPLv3

BUILD_DEPENDS=	help2man:${PORTSDIR}/misc/help2man
LIB_DEPENDS=	dbus-glib-1:${PORTSDIR}/devel/dbus-glib \
		sqlite3:${PORTSDIR}/databases/sqlite3 \
		webkitgtk-1:${PORTSDIR}/www/webkit-gtk2 \
		unique-1:${PORTSDIR}/x11-toolkits/unique
RUN_DEPENDS=	${LUA_PKGNAMEPREFIX}luafilesystem>=0:${PORTSDIR}/devel/luafilesystem

USE_GITHUB=	yes
GH_ACCOUNT=	mason-larobina
GH_PROGECT=	${PORTNAME}
GH_TAGNAME=	${PORTVERSION:C/r/-r/}
GH_COMMIT=	0d5f4ab

USES=		pkgconfig gmake
USE_GNOME=	glib20 gtk20
USE_LUA=	5.1
MAKE_ARGS+=	USE_UNIQUE=1 NO_JAVASCRIPTCORE=1

MAN1=		luakit.1

OPTIONS_DEFINE=	LUAJIT
LUAJIT_DESC=	Use the Just-In-Time compiler for lua

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${ARCH} == "sparc64"
BROKEN=		Does not install on sparc64
.endif

.if ${PORT_OPTIONS:MLUAJIT}
LIB_DEPENDS+=	luajit:${PORTSDIR}/lang/luajit
MAKE_ARGS+=	USE_LUAJIT=1
.else
MAKE_ARGS+=	USE_LUAJIT=0
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|(DESTDIR)/usr|(INSTALLDIR)|' \
		-e 's|(DESTDIR)|(INSTALLDIR)|' ${WRKSRC}/Makefile
	@${SED} -I "" 's|/etc/xdg/luakit|${LOCALBASE}&|' \
		${WRKSRC}/lib/lousy/util.lua
	@${REINPLACE_CMD} -e \
		's|share/man|man| ; s|luakit/docs|doc/luakit| ; \
		/MANPREFIX */s|?=|=|' \
		${WRKSRC}/config.mk
	@${REINPLACE_CMD} -e 's|bin/env lua|&-${LUA_VER}|' \
		${WRKSRC}/build-utils/gentokens.lua

.include <bsd.port.mk>
