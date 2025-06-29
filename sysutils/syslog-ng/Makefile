PORTNAME=	syslog-ng
DISTVERSION=	4.8.2
PORTREVISION=	3
CATEGORIES=	sysutils
# official master site:
MASTER_SITES=	https://github.com/balabit/syslog-ng/releases/download/syslog-ng-${DISTVERSION}/
# for development snapshots:
# MASTER_SITES=	https://peter.czanik.hu/freebsd/

MAINTAINER=	cy@FreeBSD.org
COMMENT=	Powerful syslogd replacement
WWW=		https://www.syslog-ng.org/

LICENSE=	GPLv2+ LGPL21+
LICENSE_COMB=	multi
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libpcre2-8.so:devel/pcre2 \
		libuuid.so:misc/libuuid \
		libivykis.so:devel/ivykis

USES=		autoreconf:build compiler:c11 cpe gettext-runtime gmake gnome \
		libtool pathfix pkgconfig python:build shebangfix ssl

CPE_VENDOR=	oneidentity

CONFLICTS?=	syslog-ng syslog-ng[0-9] \
		syslog-ng[0-9][0-9] \
		syslog-ng-devel eventlog*
WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION}

MAKE_JOBS_UNSAFE=	yes
OPTIONS_DEFINE=	TCP_WRAPPERS SQL SPOOF IPV6 SMTP JSON GEOIP2 DOCS REDIS JAVA PYTHON PYTHON_MOD MONGO CURL JAVA_MOD AMQP RIEMANN KAFKA SNMPDEST GRPC MQTT
OPTIONS_DEFAULT=	CURL JSON
TCP_WRAPPERS_DESC=	Build with TCP Wrappers
SQL_DESC=		Build with database (libdbi) support
SPOOF_DESC=		Build with spoof source support
SMTP_DESC=		Build with SMTP support
JSON_DESC=		Build with JSON-C support
GEOIP2_DESC=		Build with geoip2 (MaxMindDB) support
REDIS_DESC=		Build with Redis support
JAVA_DESC=		Build with Java support (no modules)
JAVA_MOD_DESC=		Build with Java modules (needs Maven / Internet access)
PYTHON_DESC=		Build with Python ${PYTHON_VER} support
PYTHON_MOD_DESC=	Build with Python modules (Kubernetes, Hyper, etc.)
CURL_DESC=		Build with Curl HTTP support
AMQP_DESC=		Build with AMQP support
RIEMANN_DESC=		Build with Riemann support
KAFKA_DESC=		Build with Kafka (librdkafka) support
SNMPDEST_DESC=		Build with SNMP destination (net-snmp) support
GRPC_DESC=		Build with experimental GRPC-based modules (OpenTelemetry, Loki, etc.)
MQTT_DESC=		Build with MQTT support

USE_LDCONFIG=	yes
USE_RC_SUBR=	syslog-ng
SHEBANG_FILES=	lib/merge-grammar.py
GNU_CONFIGURE=	yes
# Note: Even if PYTHON is deselected, glib20 will install python.
USE_GNOME=	glib20
SUB_FILES=	pkg-message
INSTALL_TARGET=	install-strip

CONFIGURE_ARGS=	--sysconfdir=${LOCALBASE}/etc --localstatedir=/var/db \
		--enable-dynamic-linking --disable-manpages-install \
		--disable-linux-caps \
		--datadir=${PREFIX}/share/ --with-ivykis=system \
		--with-python=${PYTHON_VER} --with-python-packages=none

CONFIGURE_ENV+=		OPENSSL_CFLAGS="-I${OPENSSLINC}" \
			OPENSSL_LIBS="-L${OPENSSLLIB} -lcrypto -lssl"

TCP_WRAPPERS_CONFIGURE_ENABLE=	tcp-wrapper

SPOOF_LIB_DEPENDS=		libnet.so:net/libnet
SPOOF_CONFIGURE_ENABLE=		spoof-source
SPOOF_CONFIGURE_ON=		--with-libnet=${LOCALBASE}/bin
SPOOF_CONFIGURE_ENV=		LIBNET_CFLAGS="-I${LOCALBASE}/include" \
				LIBNET_LIBS="-L${LOCALBASE}/lib -lnet"

IPV6_CONFIGURE_ENABLE=		ipv6

AMQP_CONFIGURE_ENABLE=		amqp
AMQP_PLIST_FILES=		lib/syslog-ng/libafamqp.so
AMQP_LIB_DEPENDS=		librabbitmq.so:net/rabbitmq-c

GEOIP2_CONFIGURE_ENABLE=	geoip2
GEOIP2_LIB_DEPENDS=		libmaxminddb.so:net/libmaxminddb
GEOIP2_LDFLAGS=			-L${LOCALBASE}/lib
GEOIP2_PLIST_FILES=		lib/syslog-ng/libgeoip2-plugin.so

REDIS_CONFIGURE_ENABLE=		redis
REDIS_LIB_DEPENDS=		libhiredis.so:databases/hiredis
REDIS_PLIST_FILES=		lib/syslog-ng/libredis.so

SNMPDEST_CONFIGURE_ENABLE=	afsnmp
SNMPDEST_LIB_DEPENDS=		libnetsnmp.so:net-mgmt/net-snmp
SNMPDEST_PLIST_FILES=		lib/syslog-ng/libafsnmp.so

SMTP_CONFIGURE_ON=		--with-libesmtp=${LOCALBASE} --enable-smtp
SMTP_CONFIGURE_OFF=		--without-libesmtp --disable-smtp
SMTP_LIB_DEPENDS=		libesmtp.so:mail/libesmtp
SMTP_PLIST_FILES=		lib/syslog-ng/libafsmtp.so

SQL_CONFIGURE_ENABLE=		sql
SQL_LIB_DEPENDS=		libdbi.so:databases/libdbi
SQL_CONFIGURE_ENV=		LIBDBI_LIBS="-L${LOCALBASE}/lib -ldbi"
SQL_PLIST_FILES=		lib/syslog-ng/libafsql.so

MONGO_CONFIGURE_ENABLE=		mongodb
MONGO_CONFIGURE_ON=		--with-mongoc=system
MONGO_LIB_DEPENDS=		libmongoc-1.0.so:devel/mongo-c-driver
MONGO_LIB_DEPENDS+=		libbson-1.0.so:devel/libbson
MONGO_PLIST_FILES=		lib/syslog-ng/libafmongodb.so

JSON_CONFIGURE_ENABLE=		json
JSON_LIB_DEPENDS=		libjson-c.so:devel/json-c
JSON_PLIST_FILES=		lib/syslog-ng/libjson-plugin.so \
				share/syslog-ng/include/scl/cim/template.conf

JAVA_CONFIGURE_ENABLE=		java
JAVA_USES=			java
JAVA_PLIST_FILES=		lib/syslog-ng/libmod-java.so \
				lib/syslog-ng/java-modules/syslog-ng-core.jar

JAVA_MOD_IMPLIES=		JAVA
JAVA_MOD_CONFIGURE_ENABLE=	java-modules
JAVA_MOD_USE=			JAVA=yes
JAVA_MOD_BUILD_DEPENDS=		gradle:devel/gradle \
				bash:shells/bash
JAVA_MOD_PLIST_DIRS=		lib/syslog-ng/java-modules/elastic-jest-client
JAVA_MOD_PLIST_FILES=		lib/syslog-ng/java-modules/log4j-api-2.17.2.jar \
				lib/syslog-ng/java-modules/log4j-core-2.17.2.jar \
				lib/syslog-ng/java-modules/elastic-jest-client/jest-2.0.2.jar \
				lib/syslog-ng/java-modules/elastic-jest-client/jest-common-2.0.2.jar \
				lib/syslog-ng/java-modules/elastic-jest-client/httpcore-nio-4.4.4.jar \
				lib/syslog-ng/java-modules/elastic-jest-client/httpclient-4.5.2.jar \
				lib/syslog-ng/java-modules/elastic-jest-client/httpasyncclient-4.1.1.jar \
				lib/syslog-ng/java-modules/elastic-jest-client/slf4j-api-1.7.13.jar \
				lib/syslog-ng/java-modules/elastic-jest-client/guava-19.0.jar \
				lib/syslog-ng/java-modules/elastic-jest-client/gson-2.6.2.jar \
				lib/syslog-ng/java-modules/elastic-jest-client/commons-lang3-3.4.jar \
				lib/syslog-ng/java-modules/elastic-jest-client/httpcore-4.4.4.jar \
				lib/syslog-ng/java-modules/elastic-jest-client/commons-logging-1.2.jar \
				lib/syslog-ng/java-modules/elastic-jest-client/commons-codec-1.9.jar \
				lib/syslog-ng/java-modules/elastic-jest-client/slf4j-simple-1.7.13.jar \
				lib/syslog-ng/java-modules/hdfs.jar \
				lib/syslog-ng/java-modules/elastic-v2.jar \
				lib/syslog-ng/java-modules/kafka.jar \
				lib/syslog-ng/java-modules/dummy.jar \
				lib/syslog-ng/java-modules/http.jar \
				lib/syslog-ng/java-modules/syslog-ng-common.jar

PYTHON_BUILD_DEPENDS=		${PY_SETUPTOOLS}
PYTHON_USES=			python
PYTHON_CONFIGURE_ON=		--enable-python
PYTHON_CONFIGURE_OFF=		--disable-python
PYTHON_PLIST_FILES=		lib/syslog-ng/libmod-python.so \
		etc/python/README.md \
		lib/syslog-ng/python/requirements.txt \
		lib/syslog-ng/python/syslogng/__pycache__/confgen%%PYTHON_TAG%%.pyc \
		lib/syslog-ng/python/syslogng/confgen.py \
		lib/syslog-ng/python/syslogng-1.0-py%%PYTHON_VER%%.egg-info/PKG-INFO \
		lib/syslog-ng/python/syslogng-1.0-py%%PYTHON_VER%%.egg-info/SOURCES.txt \
		lib/syslog-ng/python/syslogng-1.0-py%%PYTHON_VER%%.egg-info/dependency_links.txt \
		lib/syslog-ng/python/syslogng-1.0-py%%PYTHON_VER%%.egg-info/top_level.txt \
		lib/syslog-ng/python/syslogng/__pycache__/dest%%PYTHON_TAG%%.pyc \
		lib/syslog-ng/python/syslogng/__pycache__/logger%%PYTHON_TAG%%.pyc \
		lib/syslog-ng/python/syslogng/__pycache__/message%%PYTHON_TAG%%.pyc \
		lib/syslog-ng/python/syslogng/__pycache__/parser%%PYTHON_TAG%%.pyc \
		lib/syslog-ng/python/syslogng/__pycache__/persist%%PYTHON_TAG%%.pyc \
		lib/syslog-ng/python/syslogng/__pycache__/source%%PYTHON_TAG%%.pyc \
		lib/syslog-ng/python/syslogng/__pycache__/template%%PYTHON_TAG%%.pyc \
                lib/syslog-ng/python/syslogng/__pycache__/reloc%%PYTHON_TAG%%.pyc \
		lib/syslog-ng/python/syslogng/dest.py \
		lib/syslog-ng/python/syslogng/logger.py \
		lib/syslog-ng/python/syslogng/message.py \
		lib/syslog-ng/python/syslogng/parser.py \
		lib/syslog-ng/python/syslogng/persist.py \
		lib/syslog-ng/python/syslogng/source.py \
		lib/syslog-ng/python/syslogng/template.py \
                lib/syslog-ng/python/syslogng/reloc.py \
		lib/syslog-ng/python/syslogng/__init__.py \
		lib/syslog-ng/python/syslogng/__pycache__/__init__.cpython-${PYTHON_SUFFIX}.pyc \
		lib/syslog-ng/python/syslogng/debuggercli/__init__.py \
		lib/syslog-ng/python/syslogng/debuggercli/__pycache__/__init__.cpython-${PYTHON_SUFFIX}.pyc \
		lib/syslog-ng/python/syslogng/debuggercli/choicecompleter.py \
		lib/syslog-ng/python/syslogng/debuggercli/__pycache__/choicecompleter.cpython-${PYTHON_SUFFIX}.pyc \
		lib/syslog-ng/python/syslogng/debuggercli/commandlinelexer.py \
		lib/syslog-ng/python/syslogng/debuggercli/__pycache__/commandlinelexer.cpython-${PYTHON_SUFFIX}.pyc \
		lib/syslog-ng/python/syslogng/debuggercli/completer.py  \
		lib/syslog-ng/python/syslogng/debuggercli/__pycache__/completer.cpython-${PYTHON_SUFFIX}.pyc \
		lib/syslog-ng/python/syslogng/debuggercli/completerlang.py  \
		lib/syslog-ng/python/syslogng/debuggercli/__pycache__/completerlang.cpython-${PYTHON_SUFFIX}.pyc \
		lib/syslog-ng/python/syslogng/debuggercli/debuggercli.py \
		lib/syslog-ng/python/syslogng/debuggercli/__pycache__/debuggercli.cpython-${PYTHON_SUFFIX}.pyc \
		lib/syslog-ng/python/syslogng/debuggercli/debuglang.py \
		lib/syslog-ng/python/syslogng/debuggercli/__pycache__/debuglang.cpython-${PYTHON_SUFFIX}.pyc \
		lib/syslog-ng/python/syslogng/debuggercli/getoptlexer.py \
		lib/syslog-ng/python/syslogng/debuggercli/__pycache__/getoptlexer.cpython-${PYTHON_SUFFIX}.pyc \
		lib/syslog-ng/python/syslogng/debuggercli/langcompleter.py \
		lib/syslog-ng/python/syslogng/debuggercli/__pycache__/langcompleter.cpython-${PYTHON_SUFFIX}.pyc \
		lib/syslog-ng/python/syslogng/debuggercli/lexer.py \
		lib/syslog-ng/python/syslogng/debuggercli/__pycache__/lexer.cpython-${PYTHON_SUFFIX}.pyc \
		lib/syslog-ng/python/syslogng/debuggercli/lexertoken.py \
		lib/syslog-ng/python/syslogng/debuggercli/__pycache__/lexertoken.cpython-${PYTHON_SUFFIX}.pyc \
		lib/syslog-ng/python/syslogng/debuggercli/macrocompleter.py \
		lib/syslog-ng/python/syslogng/debuggercli/__pycache__/macrocompleter.cpython-${PYTHON_SUFFIX}.pyc \
		lib/syslog-ng/python/syslogng/debuggercli/readline.py \
		lib/syslog-ng/python/syslogng/debuggercli/__pycache__/readline.cpython-${PYTHON_SUFFIX}.pyc \
		lib/syslog-ng/python/syslogng/debuggercli/syslognginternals.py \
		lib/syslog-ng/python/syslogng/debuggercli/__pycache__/syslognginternals.cpython-${PYTHON_SUFFIX}.pyc \
		lib/syslog-ng/python/syslogng/debuggercli/tablexer.py \
		lib/syslog-ng/python/syslogng/debuggercli/__pycache__/tablexer.cpython-${PYTHON_SUFFIX}.pyc \
		lib/syslog-ng/python/syslogng/debuggercli/templatelang.py \
		lib/syslog-ng/python/syslogng/debuggercli/__pycache__/templatelang.cpython-${PYTHON_SUFFIX}.pyc \
		lib/syslog-ng/python/syslogng/debuggercli/templatelexer.py \
		lib/syslog-ng/python/syslogng/debuggercli/__pycache__/templatelexer.cpython-${PYTHON_SUFFIX}.pyc \
		lib/syslog-ng/python/syslogng/debuggercli/__pycache__/editline.cpython-${PYTHON_SUFFIX}.pyc \
		lib/syslog-ng/python/syslogng/debuggercli/editline.py \
		lib/syslog-ng/python/syslogng/debuggercli/tflang.py \
		lib/syslog-ng/python/syslogng/debuggercli/__pycache__/tflang.cpython-${PYTHON_SUFFIX}.pyc

PYTHON_MOD_IMPLIES=		PYTHON
PYTHON_MOD_CONFIGURE_ON=	--enable-python-modules
PYTHON_MOD_CONFIGURE_OFF=	--disable-python-modules
PYTHON_MOD_PLIST_FILES=		lib/syslog-ng/python/syslogng-1.0-py%%PYTHON_VER%%.egg-info/requires.txt \
		lib/syslog-ng/python/syslogng/modules/kubernetes/__init__.py \
		lib/syslog-ng/python/syslogng/modules/kubernetes/__pycache__/__init__%%PYTHON_TAG%%.pyc \
		lib/syslog-ng/python/syslogng/modules/kubernetes/scl/kubernetes.conf \
		lib/syslog-ng/python/syslogng/modules/example/__init__.py \
		lib/syslog-ng/python/syslogng/modules/example/__pycache__/__init__%%PYTHON_TAG%%.pyc \
		lib/syslog-ng/python/syslogng/modules/example/scl/example.conf \
		lib/syslog-ng/python/syslogng/modules/hypr/__init__.py \
		lib/syslog-ng/python/syslogng/modules/hypr/__pycache__/__init__%%PYTHON_TAG%%.pyc \
		lib/syslog-ng/python/syslogng/modules/hypr/scl/hypr.conf \
                lib/syslog-ng/python/syslogng/modules/s3/__init__.py \
                lib/syslog-ng/python/syslogng/modules/s3/__pycache__/__init__%%PYTHON_TAG%%.pyc \
                lib/syslog-ng/python/syslogng/modules/s3/__pycache__/compressable_file_buffer%%PYTHON_TAG%%.pyc \
                lib/syslog-ng/python/syslogng/modules/s3/__pycache__/s3_destination%%PYTHON_TAG%%.pyc \
                lib/syslog-ng/python/syslogng/modules/s3/__pycache__/s3_object_buffer%%PYTHON_TAG%%.pyc \
                lib/syslog-ng/python/syslogng/modules/s3/__pycache__/s3_session_handler%%PYTHON_TAG%%.pyc \
                lib/syslog-ng/python/syslogng/modules/s3/s3_object_buffer.py \
                lib/syslog-ng/python/syslogng/modules/s3/s3_session_handler.py \
                lib/syslog-ng/python/syslogng/modules/s3/compressable_file_buffer.py \
                lib/syslog-ng/python/syslogng/modules/s3/s3_destination.py \
                lib/syslog-ng/python/syslogng/modules/s3/scl/s3.conf


CURL_CONFIGURE_OFF=		--with-libcurl=off
CURL_CONFIGURE_ON=		--enable-http
CURL_LIB_DEPENDS=		libcurl.so:ftp/curl
CURL_PLIST_FILES=		lib/syslog-ng/libhttp.so \
				include/syslog-ng/modules/http/http-signals.h

RIEMANN_CONFIGURE_ON=		--enable-riemann
RIEMANN_CONFIGURE_OFF=		--disable-riemann
RIEMANN_LIB_DEPENDS=		libriemann-client-gnutls.so:net-mgmt/riemann-c-client
RIEMANN_PLIST_FILES=		lib/syslog-ng/libriemann.so

KAFKA_CONFIGURE_ON=		--enable-kafka
KAFKA_CONFIGURE_OFF=		--disable-kafka
KAFKA_LIB_DEPENDS=		librdkafka.so:net/librdkafka
KAFKA_PLIST_FILES=		lib/syslog-ng/libkafka.so

GRPC_CONFIGURE_ON=		--enable-cpp
GRPC_CONFIGURE_OFF=		--disable-cpp
GRPC_LIB_DEPENDS=		libgrpc.so:devel/grpc
GRPC_PLIST_FILES=		lib/libgrpc-protos.so \
 				lib/libgrpc-protos.so.0 \
 				lib/libgrpc-protos.so.0.0.0 \
 				lib/syslog-ng/libloki.so \
 				lib/syslog-ng/libotel.so \
 				lib/syslog-ng/libbigquery.so \
				lib/syslog-ng/libcloud_auth.so

MQTT_CONFIGURE_ON=		--enable-mqtt --with-libpaho-mqtt=${PREFIX}
MQTT_CONFIGURE_OFF=		--disable-mqtt
MQTT_LIB_DEPENDS=		libpaho-mqtt3cs.so:net/libpaho-mqtt3
MQTT_PLIST_FILES=		lib/syslog-ng/libmqtt.so



.include <bsd.port.pre.mk>

.if !${PORT_OPTIONS:MJSON}
BROKEN=		Default configuration does not currently support non-JSON builds
.endif

post-patch:
	@${CP} ${WRKSRC}/scl/syslog-ng.conf ${WRKSRC}/scl/syslog-ng.conf.dist
	touch -r ${WRKSRC}/lib/cfg-grammar.y ${WRKSRC}/lib/merge-grammar.py

post-patch-JAVA_MOD-on:
	@${REINPLACE_CMD} 's,$$(GRADLE),& --no-daemon,g' ${WRKSRC}/Makefile.in

post-install:
.if ${PORT_OPTIONS:MDOCS}
	${INSTALL} -d ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/AUTHORS ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/COPYING ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/NEWS.md ${STAGEDIR}${DOCSDIR}
.endif
	${INSTALL_MAN} ${WRKSRC}/doc/man/*.1 ${STAGEDIR}${PREFIX}/share/man/man1/
	${INSTALL_MAN} ${WRKSRC}/doc/man/*.5 ${STAGEDIR}${PREFIX}/share/man/man5/
	${INSTALL_MAN} ${WRKSRC}/doc/man/*.7 ${STAGEDIR}${PREFIX}/share/man/man7/
	${INSTALL_MAN} ${WRKSRC}/doc/man/*.8 ${STAGEDIR}${PREFIX}/share/man/man8/
	${INSTALL_DATA} ${FILESDIR}/syslog-ng.conf.sample \
		${STAGEDIR}${PREFIX}/etc
	${INSTALL_DATA} ${WRKSRC}/scl/syslog-ng.conf.dist \
		${STAGEDIR}${PREFIX}/etc
	${INSTALL_DATA} ${WRKSRC}/lib/ivykis/src/include/iv*.h \
		${STAGEDIR}${PREFIX}/include/syslog-ng/

.include <bsd.port.post.mk>
