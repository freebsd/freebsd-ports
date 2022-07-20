PORTNAME=	pmacct
DISTVERSION=	1.7.7
CATEGORIES=	net-mgmt
MASTER_SITES=	http://www.pmacct.net/

MAINTAINER=	pi@FreeBSD.org
COMMENT=	Accounting and aggregation tool for IPv4 and IPv6 traffic

LICENSE=	GPLv2

USES=		gmake libtool pkgconfig localbase autoreconf
USE_RC_SUBR=	pmacctd nfacctd sfacctd
SUB_FILES=	pkg-message
GNU_CONFIGURE=	yes

OPTIONS_DEFINE=	MYSQL PGSQL SQLITE3 LAYER2 DEBUG GEOIP2 \
		DOCS RABBITMQ REDIS KAFKA AVRO EXAMPLES
OPTIONS_DEFAULT=LAYER2
OPTIONS_SUB=	yes

AVRO_DESC=	Enable avro support
GEOIP2_DESC=	Enable GeoIPv2 (libmaxminddb) support
KAFKA_DESC=	Enable Kafka support
LAYER2_DESC=	Enable Layer-2 support: MAC addresses and VLANs
RABBITMQ_DESC=	Enable RabbitMQ/AMQP support
REDIS_DESC=	Enable Redis support
SQLITE3_DESC=	Enable SQLite3 support

SQLDOC=		"@comment "

MYSQL_USES=		mysql
MYSQL_CONFIGURE_ENABLE=	mysql
MYSQL_VARS+=	SQLDOC=""

PGSQL_USES=		pgsql
PGSQL_CONFIGURE_ENABLE=	pgsql
PGSQL_VARS+=		WANT_PGSQL=client
PGSQL_VARS+=		SQLDOC=""

SQLITE3_USES=		sqlite
SQLITE3_CONFIGURE_ENABLE=	sqlite3
SQLITE3_VARS=		SQLDOC=""

LAYER2_CONFIGURE_ENABLE=	l2
DEBUG_CONFIGURE_ENABLE=		debug

RABBITMQ_LIB_DEPENDS=		librabbitmq.so:net/rabbitmq-c-devel
RABBITMQ_CONFIGURE_ENABLE=	rabbitmq

REDIS_LIB_DEPENDS=		libhiredis.so:databases/hiredis
REDIS_CONFIGURE_ENABLE=		redis

KAFKA_LIB_DEPENDS=		librdkafka.so:net/librdkafka
KAFKA_CONFIGURE_ENABLE=		kafka

AVRO_LIB_DEPENDS=		libavro.so:devel/avro-c
AVRO_CONFIGURE_ENABLE=		avro

GEOIP2_LIB_DEPENDS=		libmaxminddb.so:net/libmaxminddb
GEOIP2_CONFIGURE_ENABLE=	geoipv2

.include <bsd.port.options.mk>

.include <bsd.port.pre.mk>

.if ${ARCH} == "i386"
EXTRA_PATCHES+= ${FILESDIR}/extra-patch-i386
.endif

PLIST_SUB+=	SQLDOC=${SQLDOC}

.if ${PORT_OPTIONS:MRABBITMQ} || ${PORT_OPTIONS:MKAFKA}
LIB_DEPENDS+=	libjansson.so:devel/jansson
CONFIGURE_ARGS+=--enable-jansson
.endif

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
