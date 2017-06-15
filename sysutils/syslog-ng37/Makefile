# Created by: Ivan Lago <ivan.lago@ifom-ieo-campus.it>
# $FreeBSD$

PORTNAME=	syslog-ng
PORTVERSION=	3.7.3
PORTREVISION=	7
.if !defined(MASTERDIR)
PKGNAMESUFFIX=	37
.endif
CATEGORIES=	sysutils
DISTVERSION=	${PORTVERSION:S/a/alpha/:S/b/beta/:S/r/rc/}
#DISTFILES=	syslog-ng-${DISTVERSION}.tar.gz
#MASTER_SITES=	https://github.com/balabit/syslog-ng/releases/download/syslog-ng-${DISTVERSION}/
DISTFILES=      syslog-ng-${DISTVERSION}_with_man.tar.gz
MASTER_SITES=   http://peter.czanik.hu/freebsd/

MAINTAINER=	cy@FreeBSD.org
COMMENT=	Powerful syslogd replacement

BROKEN_sparc64=		Does not compile on sparc64: gcc core dump

LIB_DEPENDS=	libevtlog.so:sysutils/eventlog \
		libpcre.so:devel/pcre \
		libuuid.so:misc/e2fsprogs-libuuid
BUILD_DEPENDS=		xsltproc:textproc/libxslt \

CONFLICTS?=	syslog-ng-[0-9]* syslog-ng[0-9]-[0-9]* \
		syslog-ng[0-9][0-9]-[0-9]* \
		syslog-ng-devel-[0-9]*
WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION}

MAKE_JOBS_UNSAFE=	yes
OPTIONS_DEFINE=	TCP_WRAPPERS SQL SPOOF IPV6 SMTP JSON GEOIP DOCS REDIS JAVA PYTHON MONGO
OPTIONS_DEFAULT=	JSON
TCP_WRAPPERS_DESC=	Build with TCP Wrappers
SQL_DESC=		Build with database (libdbi) support
SPOOF_DESC=		Build with spoof source support
SMTP_DESC=		Build with SMTP support
JSON_DESC=		Build with JSON-C support
GEOIP_DESC=		Build with GeoIP support
REDIS_DESC=		Build with Redis support
JAVA_DESC=		Build with Java support (and modules, like Elastic)
PYTHON_DESC=		Build with Python 2.7 support

USES=		gmake libtool pathfix pkgconfig ssl gettext-runtime
USE_LDCONFIG=	yes
USE_RC_SUBR=	syslog-ng
GNU_CONFIGURE=	yes
USE_GNOME=	glib20
SUB_FILES=	pkg-message
INSTALL_TARGET=	install-strip

CONFIGURE_ARGS=	--sysconfdir=${LOCALBASE}/etc --localstatedir=/var/db \
		--enable-dynamic-linking --enable-manpages \
		--disable-linux-caps \
		--datadir=${PREFIX}/share/syslog-ng/ 

CONFIGURE_ENV+=		OPENSSL_CFLAGS="-I${OPENSSLINC}" \
			OPENSSL_LIBS="-L${OPENSSLLIB} -lcrypto -lssl"

TCP_WRAPPERS_CONFIGURE_ENABLE=	tcp-wrapper

SPOOF_CONFIGURE_ENABLE=		spoof-source
SPOOF_LIB_DEPENDS=		libnet.so:net/libnet

IPV6_CONFIGURE_ENABLE=		ipv6

GEOIP_CONFIGURE_ENABLE=		geoip
GEOIP_LIB_DEPENDS=		libGeoIP.so:net/GeoIP
GEOIP_CONFIGURE_ENV=		GEOIP_LIBS="-L${LOCALBASE}/lib -lGeoIP"
GEOIP_PLIST_FILES=		lib/syslog-ng/libgeoip-plugin.so

REDIS_CONFIGURE_ENABLE=		redis
REDIS_LIB_DEPENDS=		libhiredis.so:databases/hiredis
REDIS_PLIST_FILES=		lib/syslog-ng/libredis.so

SMTP_CONFIGURE_ON=		--with-libesmtp=/usr/local/
SMTP_CONFIGURE_OFF=		--disable-smtp
SMTP_LIB_DEPENDS=		libesmtp.so:mail/libesmtp
SMTP_PLIST_FILES=		lib/syslog-ng/libafsmtp.so

SQL_CONFIGURE_ENABLE=		sql
SQL_LIB_DEPENDS=		libdbi.so:databases/libdbi
SQL_CONFIGURE_ENV=		LIBDBI_LIBS="-ldbi"
SQL_LDFLAGS=			-L${LOCALBASE}/lib
SQL_PLIST_FILES=		lib/syslog-ng/libafsql.so

MONGO_CONFIGURE_ENABLE=		mongodb
MONGO_BUILD_DEPENDS=		mongo:databases/mongodb
MONGO_RUN_DEPENDS=		mongo:databases/mongodb
MONGO_PLIST_FILES=		lib/syslog-ng/libafmongodb.so

JSON_CONFIGURE_ENABLE=		json
JSON_LIB_DEPENDS=		libjson-c.so:devel/json-c
JSON_PLIST_FILES= 		lib/syslog-ng/libjson-plugin.so

JAVA_CONFIGURE_ENABLE=		java
JAVA_BROKEN=			Unsupported maven downloads.
JAVA_USE_JAVA=			yes
JAVA_BUILD_DEPENDS=		gradle:devel/gradle
JAVA_BUILD_DEPENDS=		bash:shells/bash
JAVA_PLIST_FILES= 		lib/syslog-ng/libmod-java.so \
			lib/syslog-ng/java-modules/syslog-ng-core.jar \
			lib/syslog-ng/java-modules/log4j-1.2.16.jar \
			lib/syslog-ng/java-modules/elastic.jar \
			lib/syslog-ng/java-modules/http.jar \
			lib/syslog-ng/java-modules/kafka.jar \
			lib/syslog-ng/java-modules/java-modules.jar \
			lib/syslog-ng/java-modules/hdfs.jar \
			lib/syslog-ng/java-modules/syslog-ng-common.jar \
			lib/syslog-ng/java-modules/dummy.jar

PYTHON_CONFIGURE_ON=		--enable-python --with-python=2.7
PYTHON_CONFIGURE_OFF=		--disable-python
PYTHON_USES=			python:2.7
PYTHON_PLIST_FILES= 		lib/syslog-ng/libmod-python.so

.include <bsd.port.pre.mk>

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
