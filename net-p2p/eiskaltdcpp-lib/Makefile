# Created by: Stas Timokhin <stast@bsdportal.ru>
# $FreeBSD$

PORTNAME=	eiskaltdcpp-lib
PORTVERSION=	2.2.4
PORTREVISION=	4
CATEGORIES=	net-p2p
MASTER_SITES=	GOOGLE_CODE
DISTNAME=	eiskaltdcpp-${DISTVERSION}

MAINTAINER=	gelraen.ua@gmail.com
COMMENT=	A Direct Connect client shared library

LICENSE=	GPLv3

LIB_DEPENDS=	boost_system:${PORTSDIR}/devel/boost-libs
BUILD_DEPENDS+=	chrpath:${PORTSDIR}/devel/chrpath

PROJECTHOST=	eiskaltdc

USE_XZ=		yes
USE_GCC=	4.6+
USE_CMAKE=	yes
USE_GETTEXT=	yes
USE_OPENSSL=	yes
USE_LDCONFIG=	yes
MAKE_JOBS_SAFE=	yes

OPTIONS=	LUA	"Lua scripting support"	off \
		PCRE	"PCRE support in ADL Search" off \
		IDN	"IDN support" on \
		DHT	"DHT support" on

.include <bsd.port.options.mk>

CMAKE_ARGS+=	-DINSTALL_HEADERS:BOOL=ON
CMAKE_ARGS+=	-DUSE_QT:BOOL=OFF
CMAKE_ARGS+=	-DUSE_GTK:BOOL=OFF
CMAKE_ARGS+=	-DUSE_ASPELL:BOOL=OFF
CMAKE_ARGS+=	-DUSE_MINIUPNP:BOOL=OFF
CMAKE_ARGS+=	-DCMAKE_SKIP_RPATH:BOOL=ON

.if defined(WITH_LUA) && !defined(WITHOUT_LUA)
USE_LUA=	5.1
CMAKE_ARGS+=	-DLUA_SCRIPT:BOOL=ON
IGNORE=	crashes on connect attempt if built with Lua support
.else
CMAKE_ARGS+=	-DLUA_SCRIPT:BOOL=OFF
.endif

.if defined(WITH_PCRE) && !defined(WITHOUT_PCRE)
LIB_DEPENDS+=	pcre:${PORTSDIR}/devel/pcre
CMAKE_ARGS+=	-DPERL_REGEX:BOOL=ON
.else
CMAKE_ARGS+=	-DPERL_REGEX:BOOL=OFF
.endif

.if defined(WITH_IDN) && !defined(WITHOUT_IDN)
LIB_DEPENDS+=	idn:${PORTSDIR}/dns/libidn
CMAKE_ARGS+=	-DUSE_IDNA:BOOL=ON
.else
CMAKE_ARGS+=	-DUSE_IDNA:BOOL=OFF
.endif

.if defined(WITH_DHT) && !defined(WITHOUT_DHT)
CMAKE_ARGS+=	-DWITH_DHT:BOOL=ON
.else
CMAKE_ARGS+=	-DWITH_DHT:BOOL=OFF
.endif

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 700024
USE_OPENSSL_PORT=yes
.endif

post-build:
	${LOCALBASE}/bin/chrpath -r "${_GCC_RUNTIME}" "${WRKSRC}/dcpp/libeiskaltdcpp.so.2.2"

.include <bsd.port.post.mk>
