# New ports collection makefile for:	luakit
# Date created:		2012-03-23
# Whom:			gugabsd <gugabsd@mundounix.com.br>
#
# $FreeBSD$
#

PORTNAME=	luakit
PORTVERSION=	2011.07.22
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	https://github.com/mason-larobina/${PORTNAME}/tarball/${PORTVERSION}-r1/

MAINTAINER=	gugabsd@mundounix.com.br
COMMENT=	Fast, small, webkit based browser framework extensible by Lua

LICENSE=	GPLv3

BUILD_DEPENDS=	${LOCALBASE}/bin/help2man:${PORTSDIR}/misc/help2man
LIB_DEPENDS=	webkitgtk-1.0.0:${PORTSDIR}/www/webkit-gtk2 \
		sqlite3.8:${PORTSDIR}/databases/sqlite3 \
		unique-1.0.2:${PORTSDIR}/x11-toolkits/unique
RUN_DEPENDS=	${LUA_MODLIBDIR}/lfs.so:${PORTSDIR}/devel/luafilesystem

GITVERSION=	b1fb7fa
FETCH_ARGS=	-pRr
WRKSRC=		${WRKDIR}/mason-larobina-${PORTNAME}-${GITVERSION}

USE_GMAKE=	yes
USE_GNOME=	glib20 gtk20 pkgconfig
USE_LUA=	5.1+

MAN1=		luakit.1

OPTIONS=	LUAJIT "Use the Just-In-Time compiler for lua" off

.include <bsd.port.options.mk>

.if ${ARCH} == "sparc64"
BROKEN=		Does not install on sparc64
.endif

.if defined(WITH_LUAJIT)
LIB_DEPENDS+=	luajit:${PORTSDIR}/lang/luajit
CONFIGURE_ARGS+=USE_LUAJIT=1
.else
CONFIGURE_ARGS+=USE_LUAJIT=0
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|(DESTDIR)/usr|(INSTALLDIR)|' \
		-e 's|(DESTDIR)|(INSTALLDIR)|' ${WRKSRC}/Makefile
	@${SED} -I "" 's|/etc/xdg/luakit|${LOCALBASE}&|' \
		${WRKSRC}/lib/lousy/util.lua

.include <bsd.port.mk>
