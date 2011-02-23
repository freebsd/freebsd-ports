# ex:ts=8
# New ports collection makefile for:	xmlrpc-c
# Date created:			Mar 8, 2001
# Whom:				Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	xmlrpc-c
PORTVERSION=	1.25.3
CATEGORIES=	net
MASTER_SITES=	LOCAL/garga/xmlrpc-c
PKGNAMESUFFIX=	-devel

MAINTAINER=	garga@FreeBSD.org
COMMENT=	XML-RPC library for C and C++

OPTIONS=	DEBUG "Compile with debugging information" off \
		CURL "Compile with curl support" on \
		LIBWWW "Compile with libwww support" on \
		TOOLS "Build xmlrpc-c tools" on

CONFLICTS=	xmlrpc-epi-0.* xmlrpc-c-[0-9]*

USE_GNOME=	gnometarget
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

LICENSE=	BSD

.include <bsd.port.pre.mk>

.if !defined(WITH_DEBUG)
CFLAGS+=	-DNDEBUG
.endif

.if defined(WITH_CURL)
LIB_DEPENDS+=	curl.6:${PORTSDIR}/ftp/curl
CONFIGURE_ARGS+=	--enable-curl-client
.else
CONFIGURE_ARGS+=	--disable-curl-client
.endif

.if defined(WITH_LIBWWW)
LIB_DEPENDS+=	wwwcore.1:${PORTSDIR}/www/libwww
CONFIGURE_ARGS+=	--enable-libwww-client
.else
CONFIGURE_ARGS+=	--disable-libwww-client
.endif

.if defined(WITH_TOOLS)
CONFIGURE_ARGS+=	--enable-tools
PLIST_SUB+=		TOOLS=""
MAN1+=			xml-rpc-api2cpp.1 xml-rpc-api2txt.1
.else
CONFIGURE_ARGS+=	--disable-tools
PLIST_SUB+=		TOOLS="@comment "
.endif

.if defined(WITHOUT_LIBWWW) && defined(WITHOUT_CURL)
. if defined(WITH_TOOLS)
IGNORE=		xmlrpc-c tools requires CURL or LIBWWW support enabled
. endif
PLIST_SUB+=	CLIENT="@comment "
.else
PLIST_SUB+=	CLIENT=""
.endif

post-extract:
	@${FIND} ${WRKSRC} -type l -name blddir | ${XARGS} ${RM}
	@${FIND} ${WRKSRC} -type l -name srcdir | ${XARGS} ${RM}

post-patch:
	@${GREP} -lR '\-lpthread' ${WRKSRC} | ${XARGS} ${REINPLACE_CMD} -e \
		's|-lpthread|${PTHREAD_LIBS}|g'
	@${REINPLACE_CMD} -e '/#include.*features.h/d' \
		${WRKSRC}/tools/xmlrpc_pstream/xmlrpc_pstream.cpp

.include <bsd.port.post.mk>
