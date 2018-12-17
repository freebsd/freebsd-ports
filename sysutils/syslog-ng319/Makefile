# Created by: Ivan Lago <ivan.lago@ifom-ieo-campus.it>
# $FreeBSD$

PORTNAME=	syslog-ng
DISTVERSION=	3.19.1
CATEGORIES=	sysutils
DISTFILES=	syslog-ng-${DISTVERSION}.tar.gz
MASTER_SITES=	https://github.com/balabit/syslog-ng/releases/download/syslog-ng-${DISTVERSION}/
.if !defined(MASTERDIR)
PKGNAMESUFFIX=	319
.endif

MAINTAINER=	cy@FreeBSD.org
COMMENT=	Powerful syslogd replacement

LIB_DEPENDS=	libpcre.so:devel/pcre \
		libuuid.so:misc/e2fsprogs-libuuid

BROKEN_sparc64=		fails to link: Internal error: Segmentation fault (program ld)

CONFLICTS?=	syslog-ng-[0-9]* syslog-ng[0-9]-[0-9]* \
		syslog-ng[0-9][0-9]-[0-9]* \
		syslog-ng-devel-[0-9]* eventlog*
WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION}

MAKE_JOBS_UNSAFE=	yes
OPTIONS_DEFINE=	TCP_WRAPPERS SQL SPOOF IPV6 SMTP JSON GEOIP GEOIP2 DOCS REDIS JAVA PYTHON MONGO CURL JAVA_MOD AMQP
OPTIONS_DEFAULT=	JSON
TCP_WRAPPERS_DESC=	Build with TCP Wrappers
SQL_DESC=		Build with database (libdbi) support
SPOOF_DESC=		Build with spoof source support
SMTP_DESC=		Build with SMTP support
JSON_DESC=		Build with JSON-C support
GEOIP_DESC=		Build with GeoIP support (deprecated)
GEOIP2_DESC=		Build with geoip2 (MaxMindDB) support
REDIS_DESC=		Build with Redis support
JAVA_DESC=		Build with Java support (no modules)
JAVA_MOD_DESC=		Build with Java modules (needs Maven / Internet access)
PYTHON_DESC=		Build with Python 3.6 support
CURL_DESC=		Build with Curl HTTP support
AMQP_DESC=		Build with AMQP support

USES=		autoreconf:build gmake libtool pathfix pkgconfig ssl \
		gettext-runtime python:3.6,build shebangfix
USE_LDCONFIG=	yes
USE_RC_SUBR=	syslog-ng
SHEBANG_FILES=	lib/merge-grammar.py
SHEBANG_LANG=	python3
GNU_CONFIGURE=	yes
USE_GNOME=	glib20
SUB_FILES=	pkg-message
INSTALL_TARGET=	install-strip

CONFIGURE_ARGS=	--sysconfdir=${LOCALBASE}/etc --localstatedir=/var/db \
		--enable-dynamic-linking --enable-manpages \
		--disable-linux-caps \
		--datadir=${PREFIX}/share/

CONFIGURE_ENV+=		OPENSSL_CFLAGS="-I${OPENSSLINC}" \
			OPENSSL_LIBS="-L${OPENSSLLIB} -lcrypto -lssl"

TCP_WRAPPERS_CONFIGURE_ENABLE=	tcp-wrapper

SPOOF_LIB_DEPENDS=		libnet.so:net/libnet
SPOOF_CONFIGURE_ENABLE=		spoof-source
SPOOF_CONFIGURE_ON=		--with-libnet=/usr/local/bin
SPOOF_CONFIGURE_ENV=		LIBNET_CFLAGS="-I/usr/local/include" \
				LIBNET_LIBS="-L/usr/local/lib -lnet"

IPV6_CONFIGURE_ENABLE=		ipv6

AMQP_CONFIGURE_ENABLE=		amqp
AMQP_PLIST_FILES=		lib/syslog-ng/libafamqp.so
AMQP_LIB_DEPENDS=		librabbitmq.so:net/rabbitmq-c

GEOIP_CONFIGURE_ENABLE=		geoip
GEOIP_LIB_DEPENDS=		libGeoIP.so:net/GeoIP
GEOIP_CONFIGURE_ENV=		GEOIP_LIBS="-L${LOCALBASE}/lib -lGeoIP"
GEOIP_PLIST_FILES=		lib/syslog-ng/libgeoip-plugin.so

GEOIP2_CONFIGURE_ENABLE=	geoip2
GEOIP2_LIB_DEPENDS=		libmaxminddb.so:net/libmaxminddb                                
GEOIP2_LDFLAGS=			-L${LOCALBASE}/lib
GEOIP2_PLIST_FILES=		lib/syslog-ng/libgeoip2-plugin.so

REDIS_CONFIGURE_ENABLE=		redis
REDIS_LIB_DEPENDS=		libhiredis.so:databases/hiredis
REDIS_PLIST_FILES=		lib/syslog-ng/libredis.so

SMTP_CONFIGURE_ON=		--with-libesmtp=${LOCALBASE} --enable-smtp
SMTP_CONFIGURE_OFF=		--without-libesmtp --disable-smtp
SMTP_LIB_DEPENDS=		libesmtp.so:mail/libesmtp
SMTP_PLIST_FILES=		lib/syslog-ng/libafsmtp.so

SQL_CONFIGURE_ENABLE=		sql
SQL_LIB_DEPENDS=		libdbi.so:databases/libdbi
SQL_CONFIGURE_ENV=		LIBDBI_LIBS="-ldbi"
SQL_LDFLAGS=			-L${LOCALBASE}/lib
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
JAVA_USE=			JAVA=yes
JAVA_PLIST_FILES=		lib/syslog-ng/libmod-java.so \
				lib/syslog-ng/java-modules/syslog-ng-core.jar

JAVA_MOD_CONFIGURE_ENABLE=	java-modules
JAVA_MOD_USE=			JAVA=yes
JAVA_MOD_BUILD_DEPENDS=		gradle:devel/gradle \
				bash:shells/bash
JAVA_MOD_PLIST_DIRS=		lib/syslog-ng/java-modules/elastic-jest-client
JAVA_MOD_PLIST_FILES=		lib/syslog-ng/java-modules/log4j-1.2.16.jar \
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
				lib/syslog-ng/java-modules/elastic.jar \
				lib/syslog-ng/java-modules/elastic-v2.jar \
				lib/syslog-ng/java-modules/kafka.jar \
				lib/syslog-ng/java-modules/dummy.jar \
				lib/syslog-ng/java-modules/http.jar \
				lib/syslog-ng/java-modules/syslog-ng-common.jar

PYTHON_CONFIGURE_ON=		--enable-python
PYTHON_CONFIGURE_OFF=		--disable-python --with-python=3.6
PYTHON_CONFIGURE_WITH=		python=3.6
PYTHON_PLIST_FILES=		lib/syslog-ng/libmod-python.so \
                   %%PYTHON_SITELIBDIR%%/syslogng-1.0-py%%PYTHON_VER%%.egg-info \
                   %%PYTHON_SITELIBDIR%%/syslogng/__init__.py \
                   %%PYTHON_SITELIBDIR%%/syslogng/__pycache__/__init__.cpython-36.pyc \
                   %%PYTHON_SITELIBDIR%%/syslogng/debuggercli/__init__.py \
                   %%PYTHON_SITELIBDIR%%/syslogng/debuggercli/__pycache__/__init__.cpython-36.pyc \
                   %%PYTHON_SITELIBDIR%%/syslogng/debuggercli/choicecompleter.py \
                   %%PYTHON_SITELIBDIR%%/syslogng/debuggercli/__pycache__/choicecompleter.cpython-36.pyc \
                   %%PYTHON_SITELIBDIR%%/syslogng/debuggercli/commandlinelexer.py \
                   %%PYTHON_SITELIBDIR%%/syslogng/debuggercli/__pycache__/commandlinelexer.cpython-36.pyc \
                   %%PYTHON_SITELIBDIR%%/syslogng/debuggercli/completer.py  \
                   %%PYTHON_SITELIBDIR%%/syslogng/debuggercli/__pycache__/completer.cpython-36.pyc \
                   %%PYTHON_SITELIBDIR%%/syslogng/debuggercli/completerlang.py  \
                   %%PYTHON_SITELIBDIR%%/syslogng/debuggercli/__pycache__/completerlang.cpython-36.pyc \
                   %%PYTHON_SITELIBDIR%%/syslogng/debuggercli/debuggercli.py \
                   %%PYTHON_SITELIBDIR%%/syslogng/debuggercli/__pycache__/debuggercli.cpython-36.pyc \
                   %%PYTHON_SITELIBDIR%%/syslogng/debuggercli/debuglang.py \
                   %%PYTHON_SITELIBDIR%%/syslogng/debuggercli/__pycache__/debuglang.cpython-36.pyc \
                   %%PYTHON_SITELIBDIR%%/syslogng/debuggercli/getoptlexer.py \
                   %%PYTHON_SITELIBDIR%%/syslogng/debuggercli/__pycache__/getoptlexer.cpython-36.pyc \
                   %%PYTHON_SITELIBDIR%%/syslogng/debuggercli/langcompleter.py \
                   %%PYTHON_SITELIBDIR%%/syslogng/debuggercli/__pycache__/langcompleter.cpython-36.pyc \
                   %%PYTHON_SITELIBDIR%%/syslogng/debuggercli/lexer.py \
                   %%PYTHON_SITELIBDIR%%/syslogng/debuggercli/__pycache__/lexer.cpython-36.pyc \
                   %%PYTHON_SITELIBDIR%%/syslogng/debuggercli/lexertoken.py \
                   %%PYTHON_SITELIBDIR%%/syslogng/debuggercli/__pycache__/lexertoken.cpython-36.pyc \
                   %%PYTHON_SITELIBDIR%%/syslogng/debuggercli/macrocompleter.py \
                   %%PYTHON_SITELIBDIR%%/syslogng/debuggercli/__pycache__/macrocompleter.cpython-36.pyc \
                   %%PYTHON_SITELIBDIR%%/syslogng/debuggercli/readline.py \
                   %%PYTHON_SITELIBDIR%%/syslogng/debuggercli/__pycache__/readline.cpython-36.pyc \
                   %%PYTHON_SITELIBDIR%%/syslogng/debuggercli/syslognginternals.py \
                   %%PYTHON_SITELIBDIR%%/syslogng/debuggercli/__pycache__/syslognginternals.cpython-36.pyc \
                   %%PYTHON_SITELIBDIR%%/syslogng/debuggercli/tablexer.py \
                   %%PYTHON_SITELIBDIR%%/syslogng/debuggercli/__pycache__/tablexer.cpython-36.pyc \
                   %%PYTHON_SITELIBDIR%%/syslogng/debuggercli/templatelang.py \
                   %%PYTHON_SITELIBDIR%%/syslogng/debuggercli/__pycache__/templatelang.cpython-36.pyc \
                   %%PYTHON_SITELIBDIR%%/syslogng/debuggercli/templatelexer.py \
                   %%PYTHON_SITELIBDIR%%/syslogng/debuggercli/__pycache__/templatelexer.cpython-36.pyc \
                   %%PYTHON_SITELIBDIR%%/syslogng/debuggercli/tflang.py \
                   %%PYTHON_SITELIBDIR%%/syslogng/debuggercli/__pycache__/tflang.cpython-36.pyc

CURL_CONFIGURE_OFF=		--with-libcurl=off
CURL_LIB_DEPENDS=		libcurl.so:ftp/curl
CURL_PLIST_FILES=		lib/syslog-ng/libhttp.so


.include <bsd.port.pre.mk>

.if !${PORT_OPTIONS:MJSON}
BROKEN=           Default configuration does not currently support non-JSON builds
.endif

post-patch:
	@${CP} ${WRKSRC}/scl/syslog-ng.conf ${WRKSRC}/scl/syslog-ng.conf.dist
	@${CP} ${WRKSRC}/scl/scl.conf ${WRKSRC}/scl/scl.conf.sample

post-install:
.if ${PORT_OPTIONS:MDOCS}
	${INSTALL} -d -o ${SHAREOWN} -g ${SHAREGRP} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/AUTHORS ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/COPYING ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/NEWS.md ${STAGEDIR}${DOCSDIR}
.endif
	${INSTALL_MAN} ${WRKSRC}/doc/man/*.1 ${STAGEDIR}${PREFIX}/man/man1/
	${INSTALL_MAN} ${WRKSRC}/doc/man/*.5 ${STAGEDIR}${PREFIX}/man/man5/
	${INSTALL_MAN} ${WRKSRC}/doc/man/*.8 ${STAGEDIR}${PREFIX}/man/man8/
	${INSTALL_DATA} ${FILESDIR}/syslog-ng.conf.sample \
		${STAGEDIR}${PREFIX}/etc
	${INSTALL_DATA} ${WRKSRC}/scl/syslog-ng.conf.dist \
		${WRKSRC}/scl/scl.conf.sample ${STAGEDIR}${PREFIX}/etc
	${INSTALL_DATA} ${WRKSRC}/lib/ivykis/src/include/iv*.h \
		${STAGEDIR}${PREFIX}/include/syslog-ng/

.include <bsd.port.post.mk>
