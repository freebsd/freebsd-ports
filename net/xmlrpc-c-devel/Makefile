# ex:ts=8
# New ports collection makefile for:	xmlrpc-c
# Date created:			Mar 8, 2001
# Whom:				Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	xmlrpc-c
PORTVERSION=	1.31.05
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

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
MAKEFILE=	GNUmakefile
MAKE_JOBS_UNSAFE=	yes
USE_LDCONFIG=	yes

WRKSRC=		${WRKDIR}/advanced

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

.include <bsd.port.post.mk>
