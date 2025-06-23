PORTNAME=	xmlrpc-c
PORTVERSION=	1.60.05
CATEGORIES=	net
MASTER_SITES=	SF/${PORTNAME}/Xmlrpc-c%20Super%20Stable/${PORTVERSION}

MAINTAINER=	garga@FreeBSD.org
COMMENT=	XML-RPC library for C and C++
WWW=		https://xmlrpc-c.sourceforge.net/

LICENSE=	BSD3CLAUSE

USES=		gmake pkgconfig ssl tar:tgz
USE_CXXSTD=	c++11
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes

MAKEFILE=	GNUmakefile
MAKE_ENV+=	INSTALL_SHLIB="${INSTALL_LIB}" \
		INSTALL_SCRIPT="${INSTALL_SCRIPT}"
CFLAGS+=	-I${OPENSSLINC}
LDFLAGS+=	-L${OPENSSLLIB} -lm

CONFLICTS=	xmlrpc-epi-0.*

OPTIONS_DEFINE=	DEBUG CURL LIBWWW CPLUSPLUS
OPTIONS_DEFAULT=CURL LIBWWW CPLUSPLUS
OPTIONS_SUB=	yes

CPLUSPLUS_DESC=	Build xmlrpc-c C++ wrapper classes and tools
CURL_DESC=	Build the curl client transport
LIBWWW_DESC=	Build the libwww client transport

CPLUSPLUS_CONFIGURE_ENABLE=	cplusplus
CURL_LIB_DEPENDS=	libcurl.so:ftp/curl
CURL_CONFIGURE_ENABLE=	curl-client
DEBUG_CFLAGS=		-DNDEBUG
LIBWWW_LIB_DEPENDS=	libwwwcore.so:www/libwww \
			libexpat.so:textproc/expat2
LIBWWW_CONFIGURE_ENABLE=libwww-client
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
