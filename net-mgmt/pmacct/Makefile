# Created by: Kirill Ponomarew <ponomarew@oberon.net>
# $FreeBSD$

PORTNAME=	pmacct
DISTVERSION=	1.7.4p1
CATEGORIES=	net-mgmt
MASTER_SITES=	http://www.pmacct.net/

MAINTAINER=	pi@FreeBSD.org
COMMENT=	Accounting and aggregation tool for IPv4 and IPv6 traffic

LICENSE=	GPLv2

USES=		libtool
USE_RC_SUBR=	pmacctd nfacctd sfacctd
SUB_FILES=	pkg-message
GNU_CONFIGURE=	yes
CPPFLAGS+=	"-I${LOCALBASE}/include"
LDFLAGS+=	"-L${LOCALBASE}/lib"

WRKSRC=		${WRKDIR}/pmacct-1.7.4

OPTIONS_DEFINE=	MYSQL PGSQL SQLITE3 THREADS LAYER2 IPV6 DEBUG GEOIP2 \
		DOCS PLABEL RABBITMQ KAFKA JANSSON AVRO EXAMPLES
OPTIONS_DEFAULT=MMAP LAYER2 THREADS SHARED

AVRO_DESC=	Enable avro support
GEOIP2_DESC=	Enable GeoIPv2 (libmaxminddb) support
JANSSON_DESC=	Enable Jansson support
KAFKA_DESC=	Enable Kafka support
LAYER2_DESC=	Enable Layer-2 support: MAC addresses and VLANs
# Requires libnetfilter_log port/package
# NFLOG_DESC=	Enable NFLOG support
# Requires legacy mongo-c-driver version 0.8 which is not available
# MONGO_DESC=	Enable MongoDB support
PLABEL_DESC=	Enable IP prefix labels
RABBITMQ_DESC=	Enable RabbitMQ/AMQP support
SQLITE3_DESC=	Enable SQLite3 support

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MMYSQL}
USES+=		mysql
CONFIGURE_ARGS+=--enable-mysql
PLIST_SUB+=	WITH_MYSQL=""
PLIST_SUB+=	SQLDOC=""
.else
CONFIGURE_ARGS+=--disable-mysql
PLIST_SUB+=	WITH_MYSQL="@comment "
PLIST_SUB+=	SQLDOC="@comment "
.endif

.if ${PORT_OPTIONS:MPGSQL}
USES+=		pgsql
WANT_PGSQL=	client
CONFIGURE_ARGS+=--enable-pgsql
PLIST_SUB+=	WITH_PGSQL=""
PLIST_SUB+=	SQLDOC=""
.else
CONFIGURE_ARGS+=--disable-pgsql
PLIST_SUB+=	WITH_PGSQL="@comment "
PLIST_SUB+=	SQLDOC="@comment "
.endif

.if ${PORT_OPTIONS:MSQLITE3}
USES+=		pkgconfig sqlite
CONFIGURE_ARGS+=--enable-sqlite3 \
		--with-sqlite3-includes=${LOCALBASE}/include
PLIST_SUB+=	WITH_SQLITE3=""
PLIST_SUB+=	SQLDOC=""
.else
CONFIGURE_ARGS+=--disable-sqlite3
PLIST_SUB+=	WITH_SQLITE3="@comment "
PLIST_SUB+=	SQLDOC="@comment "
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

.if ${PORT_OPTIONS:MPLABEL}
CONFIGURE_ARGS+=--enable-plabel
.else
CONFIGURE_ARGS+=--disable-plabel
.endif

.if ${PORT_OPTIONS:MTHREADS}
CONFIGURE_ARGS+=--enable-threads
.else
CONFIGURE_ARGS+=--disable-threads
.endif

.if ${PORT_OPTIONS:MDEBUG}
CONFIGURE_ARGS+=--enable-debug
.endif

.if ${PORT_OPTIONS:MMONGO}
#CONFIGURE_ARGS+=--enable-mongodb
.else
CONFIGURE_ARGS+=--disable-mongodb
.endif

.if ${PORT_OPTIONS:MRABBITMQ}
.if ${PORT_OPTIONS:MJANSSON}
USES+=	pkgconfig
LIB_DEPENDS+=	libjansson.so:devel/jansson
CONFIGURE_ARGS+=--enable-jansson
.else
IGNORE=		RabbitMQ support requires enabled Jansson support
.endif
LIB_DEPENDS+=	librabbitmq.so:net/rabbitmq-c-devel
CONFIGURE_ARGS+=--enable-rabbitmq
.endif

.if ${PORT_OPTIONS:MKAFKA}
.if ${PORT_OPTIONS:MJANSSON}
USES+=	pkgconfig
LIB_DEPENDS+=	libjansson.so:devel/jansson
CONFIGURE_ARGS+=--enable-jansson
.else
IGNORE=		Kafaka support requires enabled Jansson support
.endif
LIB_DEPENDS+=	librdkafka.so:net/librdkafka
CONFIGURE_ARGS+=--enable-kafka
PLIST_SUB+=WITH_KAFKA=""
.else
PLIST_SUB+=WITH_KAFKA="@comment "
.endif

.if ${PORT_OPTIONS:MAVRO}
LIB_DEPENDS+=	libavro.so:devel/avro-c
CONFIGURE_ARGS+=--enable-avro
.endif

.if ${PORT_OPTIONS:MNFLOG}
#CONFIGURE_ARGS+=--enable-nflog
#PLIST_SUB+=WITH_NFLOG=""
.else
CONFIGURE_ARGS+=--disable-nflog
PLIST_SUB+=WITH_NFLOG="@comment "
.endif

.if ${PORT_OPTIONS:MGEOIP2}
LIB_DEPENDS+=	libmaxminddb.so:net/libmaxminddb
CONFIGURE_ARGS+=--enable-geoipv2
.endif

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64" || ${ARCH} == "sparc64"
CONFIGURE_ARGS+=--enable-64bit
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-O2||g' ${WRKSRC}/configure

post-install:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR})
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/[A-Z]* ${STAGEDIR}${DOCSDIR}
.for i in AUTHORS CONFIG-KEYS COPYING ChangeLog FAQS INSTALL QUICKSTART UPGRADE
	${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}
.endfor
	${MKDIR} ${STAGEDIR}${DATADIR}

.include <bsd.port.post.mk>
