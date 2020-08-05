# Created by: Kirill Ponomarew <ponomarew@oberon.net>
# $FreeBSD$

PORTNAME=	pmacct
DISTVERSION=	1.7.5
CATEGORIES=	net-mgmt
MASTER_SITES=	http://www.pmacct.net/

MAINTAINER=	pi@FreeBSD.org
COMMENT=	Accounting and aggregation tool for IPv4 and IPv6 traffic

LICENSE=	GPLv2

USES=		libtool pkgconfig localbase
USE_RC_SUBR=	pmacctd nfacctd sfacctd
SUB_FILES=	pkg-message
GNU_CONFIGURE=	yes

OPTIONS_DEFINE=	MYSQL PGSQL SQLITE3 LAYER2 DEBUG GEOIP2 \
		DOCS PLABEL RABBITMQ REDIS KAFKA AVRO EXAMPLES
OPTIONS_DEFAULT=LAYER2
OPTIONS_SUB=	1

AVRO_DESC=	Enable avro support
GEOIP2_DESC=	Enable GeoIPv2 (libmaxminddb) support
KAFKA_DESC=	Enable Kafka support
LAYER2_DESC=	Enable Layer-2 support: MAC addresses and VLANs
PLABEL_DESC=	Enable IP prefix labels
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
PLABEL_CONFIGURE_ENABLE=	plabel
DEBUG_CONFIGURE_ENABLE=		debug

RABBITMQ_VARS=			LIB_DEPENDS+=librabbitmq.so:net/rabbitmq-c-devel
RABBITMQ_CONFIGURE_ENABLE=	rabbitmq

REDIS_VARS=			LIB_DEPENDS+=libhiredis.so:databases/hiredis
REDIS_CONFIGURE_ENABLE=		redis

KAFKA_VARS=			LIB_DEPENDS+=librdkafka.so:net/librdkafka
KAFKA_CONFIGURE_ENABLE==	kafka

AVRO_VARS=			LIB_DEPENDS+=libavro.so:devel/avro-c
AVRO_CONFIGURE_ENABLE=		avro

GEOIP2_VARS=			LIB_DEPENDS+=libmaxminddb.so:net/libmaxminddb
GEOIP2_CONFIGURE_ENABLE=	geoipv2

.include <bsd.port.options.mk>

PLIST_SUB+=	SQLDOC=${SQLDOC}

.if ${PORT_OPTIONS:MRABBITMQ} || ${PORT_OPTIONS:MKAFKA}
LIB_DEPENDS+=	libjansson.so:devel/jansson
CONFIGURE_ARGS+=--enable-jansson
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
