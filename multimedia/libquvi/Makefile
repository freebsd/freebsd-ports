# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/multimedia/libquvi/Makefile 19822 2014-08-20 08:57:46Z gusi $

PORTNAME=	libquvi
PORTVERSION=	0.9.4
PORTREVISION=	1
CATEGORIES=	multimedia devel
MASTER_SITES=	SF/quvi/${PORTVERSION:R}/${PORTNAME}/

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Cross-platform library for parsing flash media stream URLs

LICENSE=	AGPLv3

BUILD_DEPENDS=	libquvi-scripts>=0.9:${PORTSDIR}/multimedia/libquvi-scripts
LIB_DEPENDS=	libcurl.so:${PORTSDIR}/ftp/curl \
		libproxy.so:${PORTSDIR}/net/libproxy \
		libgcrypt.so:${PORTSDIR}/security/libgcrypt
RUN_DEPENDS:=	${BUILD_DEPENDS}

OPTIONS_DEFINE=	DOCS LUAJIT
LUAJIT_DESC=	Use LuaJIT instead of Lua

PORTSCOUT=	limit:0.4.[0-9]*

CPPFLAGS+=	-I${LOCALBASE}/include
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USES=		iconv libtool pathfix pkgconfig tar:xz
USE_LDCONFIG=	yes
USE_GNOME=	glib20
CPPFLAGS+=	-I${LOCALBASE}/include
INSTALL_TARGET=	install-strip

QUVI_VER=	0.9
PLIST_SUB+=	VERSION=${QUVI_VER}

PORTDOCS=	*

LUAJIT_LIB_DEPENDS=	libluajit-5.1.so:${PORTSDIR}/lang/luajit
LUAJIT_USES_OFF=	lua

.include <bsd.port.options.mk>

post-patch:
.if ${PORT_OPTIONS:MLUAJIT}
	@${REINPLACE_CMD} 's|lua >= 5.1|luajit|g' ${WRKSRC}/configure
.else
	@${REINPLACE_CMD} 's|lua-5.1|lua-${LUA_VER}|g' ${WRKSRC}/configure
.endif

.include <bsd.port.mk>
