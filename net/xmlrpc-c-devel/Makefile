# Created by: Ying-Chieh Liao <ijliao@FreeBSD.org>
# $FreeBSD$

PORTNAME=	xmlrpc-c
PORTVERSION=	1.36.0
CATEGORIES=	net
MASTER_SITES=	LOCAL/garga/xmlrpc-c
PKGNAMESUFFIX=	-devel

MAINTAINER=	garga@FreeBSD.org
COMMENT=	XML-RPC library for C and C++

LICENSE=	BSD

OPTIONS_DEFINE=	DEBUG CURL LIBWWW CPLUSPLUS
OPTIONS_DEFAULT=CURL LIBWWW CPLUSPLUS
OPTIONS_SUB=	CPLUSPLUS

LIBWWW_DESC=	 Compile with libwww support
CPLUSPLUS_DESC=	 Build xmlrpc-c c++ libs and tools

CONFLICTS=	xmlrpc-epi-0.* xmlrpc-c-[0-9]*

USES=		gmake
USE_XZ=		yes
GNU_CONFIGURE=	yes
MAKEFILE=	GNUmakefile
MAKE_JOBS_UNSAFE=	yes
USE_LDCONFIG=	yes

CURL_LIB_DEPENDS=	libcurl.so:${PORTSDIR}/ftp/curl
CURL_CONFIGURE_ENABLE=	curl-client
LIBWWW_LIB_DEPENDS=	libwwwcore.so:${PORTSDIR}/www/libwww
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
	@${GREP} -lR '\-lpthread' ${WRKSRC} | ${XARGS} ${REINPLACE_CMD} -e \
		's|-lpthread|${PTHREAD_LIBS}|g'
	@${REINPLACE_CMD} -e '/#include.*features.h/ s/features.h/sys\/cdefs.h/' \
		${WRKSRC}/tools/xmlrpc_pstream/xmlrpc_pstream.cpp
	@${REINPLACE_CMD} -e '/define _XOPEN_SOURCE 600/ s,^,//,' \
		${WRKSRC}/src/xmlrpc_server_abyss.c
	@${REINPLACE_CMD} -e 's,sys/unistd.h,unistd.h,' \
		${WRKSRC}/test/cpp/server_abyss.cpp

.include <bsd.port.post.mk>
