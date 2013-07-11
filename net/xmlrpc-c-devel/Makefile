# Created by: Ying-Chieh Liao <ijliao@FreeBSD.org>
# $FreeBSD$

PORTNAME=	xmlrpc-c
PORTVERSION=	1.33.2
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	LOCAL/garga/xmlrpc-c
PKGNAMESUFFIX=	-devel

MAINTAINER=	garga@FreeBSD.org
COMMENT=	XML-RPC library for C and C++

LICENSE=	BSD

OPTIONS_DEFINE=	DEBUG CURL LIBWWW CPLUSPLUS
OPTIONS_DEFAULT=CURL LIBWWW CPLUSPLUS

LIBWWW_DESC=	 Compile with libwww support
CPLUSPLUS_DESC=	 Build xmlrpc-c c++ libs and tools

CONFLICTS=	xmlrpc-epi-0.* xmlrpc-c-[0-9]*

USE_XZ=		yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
MAKEFILE=	GNUmakefile
MAKE_JOBS_UNSAFE=	yes
USE_LDCONFIG=	yes

.include <bsd.port.pre.mk>

.if empty(PORT_OPTIONS:MDEBUG)
CFLAGS+=	-DNDEBUG
.endif

.if ${PORT_OPTIONS:MCURL}
LIB_DEPENDS+=	curl:${PORTSDIR}/ftp/curl
CONFIGURE_ARGS+=	--enable-curl-client
.else
CONFIGURE_ARGS+=	--disable-curl-client
.endif

.if ${PORT_OPTIONS:MLIBWWW}
LIB_DEPENDS+=	wwwcore:${PORTSDIR}/www/libwww
CONFIGURE_ARGS+=	--enable-libwww-client --with-libwww-ssl
.else
CONFIGURE_ARGS+=	--disable-libwww-client
.endif

.if ${PORT_OPTIONS:MCPLUSPLUS}
CONFIGURE_ARGS+=	--enable-cplusplus
PLIST_SUB+=	CPLUSPLUS=""
.else
CONFIGURE_ARGS+=	--disable-cplusplus
PLIST_SUB+=	CPLUSPLUS="@comment "
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
	@${GREP} -lR '\-lpthread' ${WRKSRC} | ${XARGS} ${REINPLACE_CMD} -e \
		's|-lpthread|${PTHREAD_LIBS}|g'
	@${REINPLACE_CMD} -e '/#include.*features.h/ s/features.h/sys\/cdefs.h/' \
		${WRKSRC}/tools/xmlrpc_pstream/xmlrpc_pstream.cpp
	@${REINPLACE_CMD} -e '/define _XOPEN_SOURCE 600/ s,^,//,' \
		${WRKSRC}/src/xmlrpc_server_abyss.c
	@${REINPLACE_CMD} -e 's,sys/unistd.h,unistd.h,' \
		${WRKSRC}/test/cpp/server_abyss.cpp

.include <bsd.port.post.mk>
