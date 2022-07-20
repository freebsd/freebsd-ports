PORTNAME=	xmlrpc-c
PORTVERSION=	1.54.05
CATEGORIES=	net
MASTER_SITES=	SF/${PORTNAME}/Xmlrpc-c%20Super%20Stable/${PORTVERSION}

MAINTAINER=	garga@FreeBSD.org
COMMENT=	XML-RPC library for C and C++

LICENSE=	BSD3CLAUSE

USES=		gmake pkgconfig tar:tgz
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes

MAKEFILE=	GNUmakefile
MAKE_ENV+=	INSTALL_SHLIB="${INSTALL_LIB}" \
		INSTALL_SCRIPT="${INSTALL_SCRIPT}"
MAKE_JOBS_UNSAFE=	yes
LDFLAGS+=	-lm

CONFLICTS=	xmlrpc-epi-0.*

OPTIONS_DEFINE=	DEBUG CURL LIBWWW CPLUSPLUS
OPTIONS_DEFAULT=CURL LIBWWW CPLUSPLUS
OPTIONS_SUB=	yes

CPLUSPLUS_DESC=	Build xmlrpc-c c++ libs and tools
LIBWWW_DESC=	Compile with libwww support

CPLUSPLUS_CONFIGURE_ENABLE=	cplusplus
CURL_LIB_DEPENDS=	libcurl.so:ftp/curl
CURL_CONFIGURE_ENABLE=	curl-client
LIBWWW_LIB_DEPENDS=	libwwwcore.so:www/libwww \
		libexpat.so:textproc/expat2
LIBWWW_USES=	ssl
LIBWWW_CONFIGURE_ENABLE=libwww-client
LIBWWW_CONFIGURE_WITH=	libwww-ssl

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
	@${REINPLACE_CMD} -e '/define _XOPEN_SOURCE 600/ s,^,//,' \
		${WRKSRC}/src/xmlrpc_server_abyss.c

.include <bsd.port.post.mk>
