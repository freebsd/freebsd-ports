# New ports collection makefile for: 	pmacct
# Date created:				Thu May  8 16:03:11 CEST 2003
# Whom:					Kirill Ponomarew <ponomarew@oberon.net>
#
# $FreeBSD$
#

PORTNAME=	pmacct
PORTVERSION=	0.10.2
CATEGORIES=	net-mgmt
MASTER_SITES=	http://www.pmacct.net/

MAINTAINER=	krion@FreeBSD.org
COMMENT=	Accounting and aggregation tool for IPv4 and IPv6 traffic

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
USE_GETOPT_LONG=yes

OPTIONS=	MYSQL "Enable MySQL support." Off \
		PGSQL "Enable PostgreSQL support." Off \
		SQLITE "Enable SQLite support." Off \
		MMAP  "Enable mmap(2) support." On \
		LAYER2 "Enable Layer-2 support: MAC Adresses and VLANs" On

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64" || ${ARCH} == "sparc64"
CONFIGURE_ARGS+=	--enable-64bit
.endif

.if defined(WITH_MYSQL)
USE_MYSQL=	yes
CONFIGURE_ARGS+=--enable-mysql
PLIST_SUB+=	WITH_MYSQL=""
.else
CONFIGURE_ARGS+=	--disable-mysql
PLIST_SUB+=	WITH_MYSQL="@comment "
.endif

.if defined(WITH_PGSQL)
USE_PGSQL=	yes
CONFIGURE_ARGS+=--enable-pgsql
PLIST_SUB+=	WITH_PGSQL=""
.else
CONFIGURE_ARGS+=	--disable-pgsql
PLIST_SUB+=	WITH_PGSQL="@comment "
.endif

.if defined(WITH_SQLITE)
LIB_DEPENDS+=	sqlite3.8:${PORTSDIR}/databases/sqlite3
CONFIGURE_ARGS+=--enable-sqlite3 \
		--with-sqlite3-includes=${LOCALBASE}/include
.else
CONFIGURE_ARGS+=--disable-sqlite3
.endif

.if defined(WITHOUT_MMAP)
CONFIGURE_ARGS+=--disable-mmap
.else
CONFIGURE_ARGS+=--enable-mmap
.endif

.if defined(WITHOUT_LAYER2)
CONFIGURE_ARGS+=--disable-l2
.else
CONFIGURE_ARGS+=--enable-l2
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-O2||g' ${WRKSRC}/configure

post-install:
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/* ${EXAMPLESDIR}
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for i in ChangeLog EXAMPLES FAQS README
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
