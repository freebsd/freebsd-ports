# Created by: Ying-Chieh Liao <ijliao@FreeBSD.org>
# $FreeBSD$

PORTNAME=	xmlrpc-c
PORTVERSION=	1.36.0
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	LOCAL/garga/xmlrpc-c
PKGNAMESUFFIX=	-devel

MAINTAINER=	garga@FreeBSD.org
COMMENT=	XML-RPC library for C and C++

LICENSE=	BSD3CLAUSE

OPTIONS_DEFINE=	DEBUG CURL LIBWWW CPLUSPLUS
OPTIONS_DEFAULT=CURL LIBWWW CPLUSPLUS

LIBWWW_DESC=	 Compile with libwww support
CPLUSPLUS_DESC=	 Build xmlrpc-c c++ libs and tools

CONFLICTS=	xmlrpc-epi-0.* xmlrpc-c-[0-9]*

USES=		gmake tar:xz
OPTIONS_SUB=	yes
GNU_CONFIGURE=	yes
MAKEFILE=	GNUmakefile
MAKE_JOBS_UNSAFE=	yes
MAKE_ENV+=	INSTALL_SHLIB="${INSTALL_LIB}" \
		INSTALL_SCRIPT="${INSTALL_SCRIPT}"
USE_LDCONFIG=	yes

CURL_LIB_DEPENDS=	libcurl.so:ftp/curl
CURL_CONFIGURE_ENABLE=	curl-client
LIBWWW_LIB_DEPENDS=	libwwwcore.so:www/libwww
LIBWWW_CONFIGURE_ENABLE=libwww-client
LIBWWW_CONFIGURE_WITH=	libwww-ssl
CPLUSPLUS_CONFIGURE_ENABLE=	cplusplus

.include <bsd.port.pre.mk>

.if empty(PORT_OPTIONS:MDEBUG)
CFLAGS+=	-DNDEBUG
.endif

.if empty(PORT_OPTIONS:MLIBWWW) && empty(PORT_OPTIONS:MCURL)
PLIST_SUB+=	CLIENT="@comment "
.else
PLIST_SUB+=	CLIENT=""
.endif

post-extract:
	@${FIND} ${WRKSRC} -type l -name blddir -delete
	@${FIND} ${WRKSRC} -type l -name srcdir -delete

post-patch:
	@${REINPLACE_CMD} -e '/#include.*features.h/ s/features.h/sys\/cdefs.h/' \
		${WRKSRC}/tools/xmlrpc_pstream/xmlrpc_pstream.cpp
	@${REINPLACE_CMD} -e '/define _XOPEN_SOURCE 600/ s,^,//,' \
		${WRKSRC}/src/xmlrpc_server_abyss.c
	@${REINPLACE_CMD} -e 's,sys/unistd.h,unistd.h,' \
		${WRKSRC}/test/cpp/server_abyss.cpp
	@${REINPLACE_CMD} -e '/^INSTALL_/s/=/\?=/' \
		${WRKSRC}/config.mk.in

.include <bsd.port.post.mk>
