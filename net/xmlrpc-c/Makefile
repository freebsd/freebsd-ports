# Created by: Ying-Chieh Liao <ijliao@FreeBSD.org>
# $FreeBSD$

PORTNAME=	xmlrpc-c
PORTVERSION=	1.25.26
CATEGORIES=	net
MASTER_SITES=	SF/${PORTNAME}/Xmlrpc-c%20Super%20Stable/${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	garga@FreeBSD.org
COMMENT=	XML-RPC library for C and C++

LICENSE=	BSD

OPTIONS_DEFINE=	DEBUG CURL LIBWWW
OPTIONS_DEFAULT=CURL LIBWWW

LIBWWW_DESC=	Compile with libwww support

CONFLICTS=	xmlrpc-epi-0.* xmlrpc-c-devel-[0-9]*

USES=		gmake perl5
USE_AUTOTOOLS=	libtool:env
GNU_CONFIGURE=	yes
MAKEFILE=	GNUmakefile
MAKE_ARGS=	LIBTOOL="${LIBTOOL}" \
		CFLAGS_COMMON="${CFLAGS}"
MAKE_JOBS_UNSAFE=	yes
USE_LDCONFIG=	yes

CURL_LIB_DEPENDS=	libcurl.so:${PORTSDIR}/ftp/curl
CURL_CONFIGURE_ENABLE=	curl-client
LIBWWW_LIB_DEPENDS=	libwwwcore.so:${PORTSDIR}/www/libwww
LIBWWW_CONFIGURE_ENABLE=libwww-client

.include <bsd.port.pre.mk>

.if empty(PORT_OPTIONS:MDEBUG)
CFLAGS+=	-DNDEBUG
.endif

post-extract:
	@${FIND} ${WRKSRC} -type l -name blddir -delete
	@${FIND} ${WRKSRC} -type l -name srcdir -delete

post-patch:
	@${GREP} -lR '\-lpthread' ${WRKSRC} 2>/dev/null | \
		${XARGS} ${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g'
	@${REINPLACE_CMD} -e '/#include.*features.h/d' \
		${WRKSRC}/tools/xmlrpc_pstream/xmlrpc_pstream.cpp
	@${REINPLACE_CMD} -e '/<curl\/types.h>/d' \
		${WRKSRC}/lib/curl_transport/curltransaction.c \
		${WRKSRC}/lib/curl_transport/xmlrpc_curl_transport.c \
		${WRKSRC}/lib/curl_transport/curlmulti.c

.include <bsd.port.post.mk>
