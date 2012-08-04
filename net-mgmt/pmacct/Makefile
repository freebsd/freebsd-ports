# New ports collection makefile for: 	pmacct
# Date created:				Thu May  8 16:03:11 CEST 2003
# Whom:					Kirill Ponomarew <ponomarew@oberon.net>
#
# $FreeBSD$
#

PORTNAME=	pmacct
DISTVERSION=	0.14.1
CATEGORIES=	net-mgmt
MASTER_SITES=	http://www.pmacct.net/ \
		http://mirrors.rit.edu/zi/

MAINTAINER=	zi@FreeBSD.org
COMMENT=	Accounting and aggregation tool for IPv4 and IPv6 traffic

LICENSE=	GPLv2

USE_RC_SUBR=	pmacctd
SUB_FILES=	pkg-message
GNU_CONFIGURE=	yes
CPPFLAGS+=	"-I${LOCALBASE}/include"
LDFLAGS+=	"-L${LOCALBASE}/lib"

OPTIONS_DEFINE=	MYSQL PGSQL SQLITE THREADS MMAP LAYER2 IPV6 SHARED DEBUG
OPTIONS_DEFAULT=MMAP LAYER2 IPV6 SHARED

SQLITE_DESC=	Enable SQLite support
MMAP_DESC=	Enable mmap(2) support
LAYER2_DESC=	Enable Layer-2 support: MAC addresses and VLANs
SHARED_DESC=	Enable shared objects

.include <bsd.port.options.mk>

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64" || ${ARCH} == "sparc64"
CONFIGURE_ARGS+=--enable-64bit
.endif

.if ${PORT_OPTIONS:MMYSQL}
USE_MYSQL=	yes
CONFIGURE_ARGS+=--enable-mysql
PLIST_SUB+=	WITH_MYSQL=""
.else
CONFIGURE_ARGS+=--disable-mysql
PLIST_SUB+=	WITH_MYSQL="@comment "
.endif

.if ${PORT_OPTIONS:MPGSQL}
USE_PGSQL=	yes
CONFIGURE_ARGS+=--enable-pgsql
PLIST_SUB+=	WITH_PGSQL=""
.else
CONFIGURE_ARGS+=--disable-pgsql
PLIST_SUB+=	WITH_PGSQL="@comment "
.endif

.if ${PORT_OPTIONS:MSQLITE}
USE_SQLITE=	yes
CONFIGURE_ARGS+=--enable-sqlite3 \
		--with-sqlite3-includes=${LOCALBASE}/include
.else
CONFIGURE_ARGS+=--disable-sqlite3
.endif

.if ${PORT_OPTIONS:MMMAP}
CONFIGURE_ARGS+=--enable-mmap
.else
CONFIGURE_ARGS+=--disable-mmap
.endif

.if ${PORT_OPTIONS:MLAYER2}
CONFIGURE_ARGS+=--enable-l2
.else
CONFIGURE_ARGS+=--disable-l2
.endif

.if ${PORT_OPTIONS:MIPV6}
CONFIGURE_ARGS+=--enable-ipv6
.else
CONFIGURE_ARGS+=--disable-ipv6
.endif

.if ${PORT_OPTIONS:MTHREADS}
CONFIGURE_ARGS+=--enable-threads
.else
CONFIGURE_ARGS+=--disable-threads
.endif

.if empty(PORT_OPTIONS:MSHARED)
CONFIGURE_ARGS+=--disable-so
.endif

.if ${PORT_OPTIONS:MDEBUG}
CONFIGURE_ARGS+=--enable-debug
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-O2||g' ${WRKSRC}/configure

post-install:
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/* ${EXAMPLESDIR}
.endif
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/* ${DOCSDIR}
.for i in ChangeLog FAQS README TOOLS CONFIG-KEYS KNOWN-BUGS
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif
	@${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/sql/* ${DATADIR}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
