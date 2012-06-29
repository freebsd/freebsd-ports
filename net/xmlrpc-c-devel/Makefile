# ex:ts=8
# New ports collection makefile for:	xmlrpc-c
# Date created:			Mar 8, 2001
# Whom:				Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	xmlrpc-c
PORTVERSION=	1.29.2
CATEGORIES=	net
MASTER_SITES=	LOCAL/garga/xmlrpc-c
PKGNAMESUFFIX=	-devel

MAINTAINER=	garga@FreeBSD.org
COMMENT=	XML-RPC library for C and C++

LICENSE=	BSD

OPTIONS_DEFINE=	DEBUG CURL LIBWWW TOOLS
OPTIONS_DEFAULT=CURL LIBWWW TOOLS

LIBWWW_DESC=	 Compile with libwww support
TOOLS_DESC=	 Build xmlrpc-c tools

CONFLICTS=	xmlrpc-epi-0.* xmlrpc-c-[0-9]*

USE_PERL5=	yes
USE_GMAKE=	yes
USE_BZIP2=	yes
USE_AUTOTOOLS=	libtool:env
GNU_CONFIGURE=	yes
MAKEFILE=	GNUmakefile
MAKE_ARGS=	LIBTOOL="${LIBTOOL}" \
		CFLAGS_COMMON="${CFLAGS}"
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
CONFIGURE_ARGS+=	--enable-libwww-client
.else
CONFIGURE_ARGS+=	--disable-libwww-client
.endif

.if ${PORT_OPTIONS:MTOOLS}
CONFIGURE_ARGS+=	--enable-tools
PLIST_SUB+=		TOOLS=""
MAN1+=			xml-rpc-api2cpp.1 xml-rpc-api2txt.1
.else
CONFIGURE_ARGS+=	--disable-tools
PLIST_SUB+=		TOOLS="@comment "
.endif

.if empty(PORT_OPTIONS:MLIBWWW) && empty(PORT_OPTIONS:MCURL)
. if ${PORT_OPTIONS:MTOOLS}
IGNORE=		xmlrpc-c tools requires CURL or LIBWWW support enabled
. endif
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
	@${REINPLACE_CMD} -e '/#include.*features.h/d' \
		${WRKSRC}/tools/xmlrpc_pstream/xmlrpc_pstream.cpp
	@${REINPLACE_CMD} -e 's/s6_addr16/s6_addr/g' \
		${WRKSRC}/lib/abyss/src/socket_unix.c

.include <bsd.port.post.mk>
