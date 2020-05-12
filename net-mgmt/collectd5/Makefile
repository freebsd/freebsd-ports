# Created by: Matt Peterson <matt@peterson.org>
# $FreeBSD$

PORTNAME=	collectd
PORTVERSION=	5.11.0
CATEGORIES=	net-mgmt
MASTER_SITES=	https://storage.googleapis.com/collectd-tarballs/
PKGNAMESUFFIX=	5

MAINTAINER=	ports@bsdserwis.com
COMMENT=	Systems & network statistics collection daemon

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		autoreconf gmake libtool pkgconfig shebangfix tar:bzip2

GNU_CONFIGURE=	yes

OPTIONS_DEFINE=		CGI GCRYPT JAVA LOGGING LOGSTASH VIRT
OPTIONS_GROUP=		INPUT OUTPUT
OPTIONS_GROUP_OUTPUT=	INFLUXDB KAFKA MONGODB NOTIFYDESKTOP NOTIFYEMAIL PROMETHEUS \
			RIEMANN RRDTOOL TSDB
OPTIONS_GROUP_INPUT=	CHRONY CURL CURL_JSON CURL_XML DBI IPMI JSON \
			MEMCACHEC MODBUS MQTT MYSQL NUTUPS OLSRD ONEWIRE OPENLDAP \
			PERL PGSQL PINBA PING PYTHON RABBITMQ REDIS SIGROK \
			SLURM SNMP STATSD TOKYOTYRANT VARNISH XML ZOOKEEPER

OPTIONS_DEFAULT=	GCRYPT LOGGING PING

CGI_DESC=		Install collection.cgi (requires rrdtool)
CHRONY_DESC=		Enable chronyd plugin
CURL_DESC=		Enable curl-based plugins (apache, nginx, etc)
CURL_JSON_DESC=		Enable curl_json plugin (implies curl and json)
CURL_XML_DESC=		Enable ascent, bind, curl_xml plugins (implies curl and xml)
DBI_DESC=		Enable dbi plugin
GCRYPT_DESC=		Build with libgcrypt
INFLUXDB_DESC=		Enable write_influxdb_udp plugin
IPMI_DESC=		Enable OpenIPMI plugin
JSON_DESC=		Enable JSON plugins
KAFKA_DESC=		Enable write_kafka plugin
LOGGING_DESC=		Enable debug logging
LOGSTASH_DESC=		Enable log_logstash plugin (requires json)
MEMCACHEC_DESC=		Enable memcachec plugin
MODBUS_DESC=		Enable modbus plugin
MONGODB_DESC=		Enable write_mongodb plugin (BROKEN)
MQTT_DESC=		Enable MQTT broker metrics
MYSQL_DESC=		Enable mysql-based plugins
NOTIFYDESKTOP_DESC=	Enable desktop notifications
NOTIFYEMAIL_DESC=	Enable notifications via email
NUTUPS_DESC=		Enable nut (ups) plugin
OLSRD_DESC=		Enable olsrd plugin
ONEWIRE_DESC=		Eanble onewire plugin (via owfs)
OPENLDAP_DESC=		Enable OpenLDAP plugin
PERL_DESC=		Enable libperl plugin and binding
PGSQL_DESC=		Enable postgresql-based plugins
PINBA_DESC=		Enable pinba plugin (via protobuf-c)
PING_DESC=		Enable ping plugin
PROMETHEUS_DESC=	Enable write prometheus plugin
PYTHON_DESC=		Enable python-based plugins
RABBITMQ_DESC=		Enable rabbitmq-based plugins
REDIS_DESC=		Enable redis-based plugins
RIEMANN_DESC=		Enable write_riemann plugin (via riemann-c-client)
RRDTOOL_DESC=		Enable rrdtool plugin (also rrdcached plugin)
SIGROK_DESC=		Enable sigrok plugin
SLURM_DESC=		Enable slurm plugin
SNMP_DESC=		Enable SNMP plugin
STATSD_DESC=		Enable statsd plugin
TOKYOTYRANT_DESC=	Enable tokyotyrant plugin
TSDB_DESC=		Enable write_tsdb plugin
VARNISH_DESC=		Enable varnish 4.x cache statistics
VIRT_DESC=		Enable libvirt plugin (requires XML)
XML_DESC=		Enable XML plugins
ZOOKEEPER_DESC=		Enable zookeeper plugin

OPTIONS_SUB=	yes

USE_RC_SUBR=	collectd collectdmon

USE_LDCONFIG=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib

# NOTE: Plugins without dependencies are defined further down.
CONFIGURE_ARGS=	--disable-all-plugins \
		--disable-amqp \
		--disable-ceph \
		--disable-cgroups \
		--disable-fhcount \
		--disable-lvm \
		--disable-static \
		--disable-turbostat \
		--enable-disk \
		--localstatedir=/var \
		--without-libaquaero5 \
		--without-libganglia \
		--without-libiptc \
		--without-libldap \
		--without-liblvm2app \
		--without-libmnl \
		--without-libnetapp \
		--without-libowcapi \
		--without-libsensors \
		--without-mic \
		--without-oracle

CGI_RUN_DEPENDS=	p5-CGI>=0:www/p5-CGI \
			p5-HTML-Parser>=0:www/p5-HTML-Parser \
			p5-URI>=0:net/p5-URI
CGI_IMPLIES=		RRDTOOL

CHRONY_CONFIGURE_ENABLE=	chrony

CURL_LIB_DEPENDS=	libcurl.so:ftp/curl
CURL_CONFIGURE_ENABLE=	apache curl nginx write_http
CURL_CONFIGURE_WITH=	libcurl=${LOCALBASE}

CURL_JSON_IMPLIES=		CURL JSON
CURL_JSON_CONFIGURE_ENABLE=	curl_json

CURL_XML_IMPLIES=		CURL XML
CURL_XML_CONFIGURE_ENABLE=	ascent bind curl_xml

JAVA_USE=		java
JAVA_CONFIGURE_ENABLE=	java
JAVA_CONFIGURE_WITH=	java=${LOCALBASE} libjvm

DBI_LIB_DEPENDS=	libdbi.so:databases/libdbi
DBI_CONFIGURE_ENABLE=	dbi
DBI_CFLAGS=		-Wno-deprecated-declarations

GCRYPT_LIB_DEPENDS=	libgcrypt.so:security/libgcrypt \
			libgpg-error.so:security/libgpg-error
GCRYPT_CONFIGURE_WITH=	libgcrypt=${LOCALBASE}
GCRYPT_LIBS=		-lgcrypt

INFLUXDB_CONFIGURE_ENABLE=	write_influxdb_udp

IPMI_LIB_DEPENDS=	libOpenIPMI.so:sysutils/openipmi
IPMI_CONFIGURE_ENABLE=	ipmi

JSON_LIB_DEPENDS=	libyajl.so:devel/yajl
JSON_CONFIGURE_WITH=	libyajl=${LOCALBASE}

KAFKA_LIB_DEPENDS=	librdkafka.so:net/librdkafka
KAFKA_CONFIGURE_ENABLE=	write_kafka

LOGGING_CONFIGURE_ENABLE=	debug

LOGSTASH_CONFIGURE_ENABLE=	log_logstash
LOGSTASH_IMPLIES=		JSON

MEMCACHEC_LIB_DEPENDS=		libmemcached.so:databases/libmemcached
MEMCACHEC_CONFIGURE_ENABLE=	memcachec
MEMCACHEC_CONFIGURE_WITH=	libmemcached=${LOCALBASE}

MODBUS_LIB_DEPENDS=		libmodbus.so:comms/libmodbus
MODBUS_CONFIGURE_ENABLE=	modbus
MODBUS_CONFIGURE_WITH=		libmodbus=use_pkgconfig

MONGODB_LIB_DEPENDS+=		libbson-1.0.so:devel/libbson \
				libmongoc-1.0.so:devel/mongo-c-driver
MONGODB_CONFIGURE_ENABLE=	write_mongodb
MONGODB_CONFIGURE_WITH=		libmongoc=${LOCALBASE}
MONGODB_BROKEN=			fails to configure with write_mongodb option

MQTT_LIB_DEPENDS=	libmosquitto.so:net/mosquitto
MQTT_CONFIGURE_ENABLE=	mqtt
MQTT_CONFIGURE_WITH=	libmosquitto=${LOCALBASE}

MYSQL_USES=		mysql ssl
MYSQL_CONFIGURE_ENABLE=	mysql
MYSQL_CONFIGURE_WITH=	libmysql=${LOCALBASE}

NOTIFYDESKTOP_LIB_DEPENDS=	libnotify.so:devel/libnotify
NOTIFYDESKTOP_CONFIGURE_ENABLE=	notify_desktop
NOTIFYDESKTOP_CONFIGURE_WITH=	libnotify=${LOCALBASE}
NOTIFYDESKTOP_USE=		GNOME=gdkpixbuf2
NOTIFYDESKTOP_USES=		gettext-runtime gnome

NOTIFYEMAIL_LIB_DEPENDS=	libesmtp.so:mail/libesmtp
NOTIFYEMAIL_CONFIGURE_ENABLE=	notify_email
NOTIFYEMAIL_CONFIGURE_WITH=	libesmtp=${LOCALBASE}

NUTUPS_LIB_DEPENDS=		libupsclient.so:sysutils/nut
NUTUPS_CONFIGURE_ENABLE=	nut
NUTUPS_CONFIGURE_WITH=		upsclient=${LOCALBASE}

OLSRD_CONFIGURE_ENABLE=	olsrd

ONEWIRE_LIB_DEPENDS=		libow.so:comms/owfs
ONEWIRE_CONFIGURE_ENABLE=	onewire
ONEWIRE_CONFIGURE_WITH=		libowcapi=${LOCALBASE}

OPENLDAP_USE=			OPENLDAP=yes
OPENLDAP_CONFIGURE_ENABLE=	openldap
OPENLDAP_CONFIGURE_WITH=	libldap=${LOCALBASE}

PERL_USES=		perl5
PERL_CONFIGURE_ENABLE=	perl
PERL_CONFIGURE_WITH=	libperl perl-bindings perl=${PERL}

PGSQL_USES=		pgsql
PGSQL_CONFIGURE_ENABLE=	postgresql
PGSQL_CONFIGURE_WITH=	libpq postgresql=${LOCALBASE}

PINBA_LIB_DEPENDS=	libprotobuf-c.so:devel/protobuf-c
PINBA_CONFIGURE_ENABLE=	pinba

PING_LIB_DEPENDS=	liboping.so:net/liboping
PING_CONFIGURE_ENABLE=	ping
PING_CONFIGURE_WITH=	liboping=${LOCALBASE}

PROMETHEUS_LIB_DEPENDS+=	libmicrohttpd.so:www/libmicrohttpd \
				libprotobuf-c.so:devel/protobuf-c \
				libprotoc.so:devel/protobuf
PROMETHEUS_CONFIGURE_ENABLE=	write_prometheus

PYTHON_USES=			python
PYTHON_CONFIGURE_ENABLE=	python
PYTHON_CONFIGURE_WITH=		python=${PYTHON_CMD}
PYTHON_CONFIGURE_ENV=		PYTHON_CONFIG=${PYTHON_CMD}-config

RABBITMQ_LIB_DEPENDS=		librabbitmq.so:net/rabbitmq-c
RABBITMQ_CONFIGURE_ENABLE=	rabbitmq
RABBITMQ_CONFIGURE_WITH=	librabbitmq=${LOCALBASE}

REDIS_LIB_DEPENDS=	libhiredis.so:databases/hiredis
REDIS_CONFIGURE_ENABLE=	redis write_redis
REDIS_CONFIGURE_WITH=	libhiredis=${LOCALBASE}

RIEMANN_LIB_DEPENDS=		libltdl.so:devel/libltdl \
				libriemann-client.so:net-mgmt/riemann-c-client
RIEMANN_CONFIGURE_ENABLE=	write_riemann

RRDTOOL_LIB_DEPENDS=		librrd.so:databases/rrdtool
RRDTOOL_CONFIGURE_ENABLE=	rrdcached rrdtool
RRDTOOL_CONFIGURE_WITH=		librrd=${LOCALBASE}

SIGROK_USE=			GNOME=glib20
SIGROK_CFLAGS=			`pkg-config --cflags glib-2.0`
SIGROK_LIB_DEPENDS=		libsigrok.so:devel/libsigrok
SIGROK_CONFIGURE_ENABLE=	sigrok
SIGROK_CONFIGURE_WITH=		libsigrok=${LOCALBASE}
SIGROK_USES=			gettext-runtime
SIGROK_BROKEN=			fails to configure with sigrok option

SLURM_LIB_DEPENDS=		libslurm.so:sysutils/slurm-wlm
SLURM_CONFIGURE_ENABLE=		slurm
SLURM_CONFIGURE_WITH=		libslurm=${LOCALBASE}

SNMP_LIB_DEPENDS=	libnetsnmp.so:net-mgmt/net-snmp
SNMP_CONFIGURE_ENABLE=	snmp
SNMP_CONFIGURE_WITH=	libnetsnmp

STATSD_CONFIGURE_ENABLE=	statsd

TOKYOTYRANT_LIB_DEPENDS=	libtokyocabinet.so:databases/tokyocabinet \
				libtokyotyrant.so:databases/tokyotyrant
TOKYOTYRANT_CONFIGURE_ENABLE=	tokyotyrant
TOKYOTYRANT_CONFIGURE_WITH=	libtokyotyrant=${LOCALBASE}

TSDB_CONFIGURE_ENABLE=	write_tsdb

VARNISH_LIB_DEPENDS=		libvarnishapi.so:www/varnish4
VARNISH_CONFIGURE_ENABLE=	varnish

VIRT_IMPLIES=		XML
VIRT_LIB_DEPENDS=	libgcrypt.so:security/libgcrypt \
			libgpg-error.so:security/libgpg-error \
			libvirt.so:devel/libvirt
VIRT_CONFIGURE_ENABLE=	virt
VIRT_CONFIGURE_WITH=	virt=${LOCALBASE}

XML_CFLAGS=		`pkg-config --cflags libxml-2.0`
XML_LIB_DEPENDS=	libxml2.so:textproc/libxml2
XML_CONFIGURE_WITH=	libxml2

ZOOKEEPER_LIB_DEPENDS=		libzookeeper_mt.so:devel/libzookeeper
ZOOKEEPER_CONFIGURE_ENABLE=	zookeeper
ZOOKEEPER_CONFIGURE_WITH=	libzookeeper=${LOCALBASE}

# NOTE: Plugins without external dependencies
CONFIGURE_ARGS+=	--enable-aggregation \
			--enable-apcups \
			--enable-contextswitch \
			--enable-cpu \
			--enable-csv \
			--enable-df \
			--enable-dns \
			--enable-email \
			--enable-exec \
			--enable-filecount \
			--enable-interface \
			--enable-ipstats \
			--enable-load \
			--enable-logfile \
			--enable-logparser \
			--enable-match_empty_counter \
			--enable-match_hashed \
			--enable-match_regex \
			--enable-match_timediff \
			--enable-match_value \
			--enable-mbmon \
			--enable-memcached \
			--enable-memory \
			--enable-network \
			--enable-ntpd \
			--enable-openvpn \
			--enable-pf \
			--enable-powerdns \
			--enable-processes \
			--enable-statsd \
			--enable-swap \
			--enable-syslog \
			--enable-table \
			--enable-tail \
			--enable-tail_csv \
			--enable-target_notification \
			--enable-target_replace \
			--enable-target_scale \
			--enable-target_set \
			--enable-target_v5upgrade \
			--enable-tcpconns \
			--enable-teamspeak2 \
			--enable-ted \
			--enable-threshold \
			--enable-unixsock \
			--enable-uptime \
			--enable-users \
			--enable-uuid \
			--enable-write_graphite \
			--enable-write_log \
			--enable-zfs_arc
INSTALL_TARGET=		install-strip
SHEBANG_FILES=		contrib/collection.cgi

post-patch:
	@${REINPLACE_CMD} 's/-Werror//' \
		${WRKSRC}/configure.ac
	@${REINPLACE_CMD} \
		-e 's;@prefix@/var/;/var/;' \
		-e 's;/var/lib/;/var/db/;' \
		-e 's;@localstatedir@/lib/;/var/db/;' \
		${WRKSRC}/src/collectd.conf.in \
		${WRKSRC}/src/collectd.conf.5 \
		${WRKSRC}/src/collectd.conf.pod
	@${REINPLACE_CMD} \
		-e 's;/etc/collection\.conf;${WWWDIR}/collection.conf;' \
		${WRKSRC}/contrib/collection.cgi
	@${REINPLACE_CMD} \
		-e 's;/opt/collectd/var/lib;/var/db;' \
		-e 's;/opt/collectd/lib;${PREFIX}/lib;' \
		${WRKSRC}/contrib/collection.conf

post-install:
	${MKDIR} ${STAGEDIR}/var/db/collectd

post-install-CGI-on:
	${MKDIR} ${STAGEDIR}${WWWDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/contrib/collection.cgi ${STAGEDIR}${WWWDIR}/
	${INSTALL_DATA} ${WRKSRC}/contrib/collection.conf \
		${STAGEDIR}${WWWDIR}/collection.conf.sample

.include <bsd.port.mk>
