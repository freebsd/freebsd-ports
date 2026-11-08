PORTNAME=	xmlrpc-c
PORTVERSION=	1.64.03
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	SF/${PORTNAME}/Xmlrpc-c%20Super%20Stable/${PORTVERSION}
DISTNAME=	xmlrpc-${DISTVERSIONPREFIX}${DISTVERSION}${DISTVERSIONSUFFIX}

MAINTAINER=	garga@FreeBSD.org
COMMENT=	XML-RPC library for C and C++
WWW=		https://xmlrpc-c.sourceforge.io/

LICENSE=	BSD3CLAUSE

USES=		gmake pkgconfig ssl tar:tgz
USE_CXXSTD=	c++11
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes

MAKEFILE=	GNUmakefile

MAKE_ENV+=	INSTALL_SCRIPT="${INSTALL_SCRIPT}" \
		INSTALL_SHLIB="${INSTALL_LIB}"
MAKE_JOBS_UNSAFE=	yes

CFLAGS+=	-I${OPENSSLINC}
LDFLAGS+=	-L${OPENSSLLIB} -lm

CONFLICTS=	xmlrpc-epi-0.*

OPTIONS_DEFINE=	CPLUSPLUS CURL DEBUG LIBWWW
OPTIONS_DEFAULT=	CPLUSPLUS CURL LIBWWW
OPTIONS_SUB=	yes

CPLUSPLUS_DESC=	Build xmlrpc-c C++ wrapper classes and tools
CURL_DESC=	Build the curl client transport
LIBWWW_DESC=	Build the libwww client transport

CPLUSPLUS_CONFIGURE_ENABLE=	cplusplus
CURL_LIB_DEPENDS=	libcurl.so:ftp/curl
CURL_CONFIGURE_ENABLE=	curl-client
DEBUG_CFLAGS=	-DNDEBUG
LIBWWW_LIB_DEPENDS=	libexpat.so:textproc/expat2 \
			libwwwcore.so:www/libwww
LIBWWW_CONFIGURE_ENABLE=	libwww-client
LIBWWW_CONFIGURE_WITH=	libwww-ssl

post-patch:
	@${REINPLACE_CMD} -e '/define _XOPEN_SOURCE 600/ s,^,//,' \
		${WRKSRC}/src/xmlrpc_server_abyss.c

.include <bsd.port.options.mk>

.if empty(PORT_OPTIONS:MLIBWWW) && empty(PORT_OPTIONS:MCURL)
PLIST_SUB+=	CLIENT="@comment "
.else
PLIST_SUB+=	CLIENT=""
.endif

.include <bsd.port.mk>
