# Created by: Stas Timokhin <stast@bsdportal.ru>
# $FreeBSD$

PORTNAME=	eiskaltdcpp-lib
PORTVERSION=	2.2.4
PORTREVISION=	7
CATEGORIES=	net-p2p
MASTER_SITES=	GOOGLE_CODE
DISTNAME=	eiskaltdcpp-${DISTVERSION}

MAINTAINER=	fjoe@FreeBSD.org
COMMENT=	A Direct Connect client shared library

LICENSE=	GPLv3

LIB_DEPENDS=	libboost_system.so:${PORTSDIR}/devel/boost-libs
BUILD_DEPENDS+=	chrpath:${PORTSDIR}/devel/chrpath

PROJECTHOST=	eiskaltdc

USE_XZ=		yes
USE_GCC=	yes
USES=		cmake gettext
USE_OPENSSL=	yes
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	LUA PCRE IDN DHT
OPTIONS_DEFAULT=	IDN DHT
DHT_DESC=	DHT support

.include <bsd.port.options.mk>

CMAKE_ARGS+=	-DINSTALL_HEADERS:BOOL=ON
CMAKE_ARGS+=	-DUSE_QT:BOOL=OFF
CMAKE_ARGS+=	-DUSE_GTK:BOOL=OFF
CMAKE_ARGS+=	-DUSE_ASPELL:BOOL=OFF
CMAKE_ARGS+=	-DUSE_MINIUPNP:BOOL=OFF
CMAKE_ARGS+=	-DCMAKE_SKIP_RPATH:BOOL=ON

.if ${PORT_OPTIONS:MLUA}
USE_LUA=	5.1
CMAKE_ARGS+=	-DLUA_SCRIPT:BOOL=ON
IGNORE=	crashes on connect attempt if built with Lua support
.else
CMAKE_ARGS+=	-DLUA_SCRIPT:BOOL=OFF
.endif

.if ${PORT_OPTIONS:MPCRE}
LIB_DEPENDS+=	libpcre.so:${PORTSDIR}/devel/pcre
CMAKE_ARGS+=	-DPERL_REGEX:BOOL=ON
.else
CMAKE_ARGS+=	-DPERL_REGEX:BOOL=OFF
.endif

.if ${PORT_OPTIONS:MIDN}
LIB_DEPENDS+=	libidn.so:${PORTSDIR}/dns/libidn
CMAKE_ARGS+=	-DUSE_IDNA:BOOL=ON
.else
CMAKE_ARGS+=	-DUSE_IDNA:BOOL=OFF
.endif

.if ${PORT_OPTIONS:MDHT}
CMAKE_ARGS+=	-DWITH_DHT:BOOL=ON
.else
CMAKE_ARGS+=	-DWITH_DHT:BOOL=OFF
.endif

post-build:
	${LOCALBASE}/bin/chrpath -r "${_GCC_RUNTIME}" "${WRKSRC}/dcpp/libeiskaltdcpp.so.2.2"

.include <bsd.port.mk>
