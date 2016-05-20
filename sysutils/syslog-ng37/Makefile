# Created by: Ivan Lago <ivan.lago@ifom-ieo-campus.it>
# $FreeBSD$

PORTNAME=	syslog-ng
PORTVERSION=	3.7.3
PORTREVISION=	3
.if !defined(MASTERDIR)
PKGNAMESUFFIX=	37
.endif
CATEGORIES=	sysutils
DISTVERSION=	$(PORTVERSION:S/a/alpha/:S/b/beta/:S/r/rc/)
DISTFILES=	syslog-ng-${DISTVERSION}.tar.gz
MASTER_SITES=	https://github.com/balabit/syslog-ng/releases/download/syslog-ng-${DISTVERSION}/

MAINTAINER=	cy@FreeBSD.org
COMMENT=	Powerful syslogd replacement

BROKEN_powerpc64=	Does not build

LIB_DEPENDS=	libevtlog.so:sysutils/eventlog \
		libpcre.so:devel/pcre
BUILD_DEPENDS=		xsltproc:textproc/libxslt \

CONFLICTS?=	syslog-ng-[0-9]* syslog-ng[0-9]-[0-9]* \
		syslog-ng[0-9][0-9]-[0-9]* \
		syslog-ng-devel-[0-9]*
WRKSRC=		$(WRKDIR)/$(PORTNAME)-$(DISTVERSION)

MAKE_JOBS_UNSAFE=	yes
OPTIONS_DEFINE=	TCP_WRAPPERS SQL SPOOF IPV6 SMTP JSON GEOIP DOCS REDIS JAVA PYTHON
OPTIONS_DEFAULT=	JSON
TCP_WRAPPERS_DESC=	Build with TCP Wrappers
SQL_DESC=		Build with database (libdbi) support
SPOOF_DESC=		Build with spoof source support
IPV6_DESC=		Build with IPV6 support
SMTP_DESC=		Build with SMTP support
JSON_DESC=		Build with JSON-C support
GEOIP_DESC=		Build with GeoIP support
REDIS_DESC=		Build with Redis support
JAVA_DESC=		Build with Java support (and modules, like Elastic)
PYTHON_DESC=		Build with Python 2.7 support

USES=		gmake libtool pathfix pkgconfig
USE_LDCONFIG=	yes
USE_RC_SUBR=	syslog-ng
GNU_CONFIGURE=	yes
USE_GNOME=	glib20
SUB_FILES=	pkg-message
USE_OPENSSL=	yes
INSTALL_TARGET=	install-strip

CONFIGURE_ARGS=	--sysconfdir=${LOCALBASE}/etc --localstatedir=/var/db \
		--enable-dynamic-linking --enable-manpages \
		--disable-linux-caps \
		--datadir=${PREFIX}/share/syslog-ng/ \
		--with-docbook-dir=${LOCALBASE}/share/xsl/docbook/manpages/docbook.xsl

BROKEN_sparc64=	Does not compile on sparc64: gcc core dump

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
BUILD_DEPENDS+=		${LOCALBASE}/share/xsl/docbook/manpages/docbook.xsl:textproc/docbook-xsl
.endif

CONFIGURE_ENV+=		OPENSSL_CFLAGS="-I${OPENSSLINC}" \
			OPENSSL_LIBS="-L${OPENSSLLIB} -lcrypto -lssl"

.if ${PORT_OPTIONS:MTCP_WRAPPERS}
CONFIGURE_ARGS+=	--enable-tcp-wrapper
.else
CONFIGURE_ARGS+=	--disable-tcp-wrapper
.endif

.if ${PORT_OPTIONS:MSPOOF}
LIB_DEPENDS+=		libnet.so:net/libnet
CONFIGURE_ARGS+=	--enable-spoof-source
.else
CONFIGURE_ARGS+=	--disable-spoof-source
.endif

.if ${PORT_OPTIONS:MIPV6}
CONFIGURE_ARGS+=	--enable-ipv6
.else
CONFIGURE_ARGS+=	--disable-ipv6
.endif

.if ${PORT_OPTIONS:MGEOIP}
CONFIGURE_ARGS+=	--enable-geoip
LIB_DEPENDS+=		libGeoIP.so:net/GeoIP
CONFIGURE_ENV+=		GEOIP_LIBS="-L${LOCALBASE}/lib -lGeoIP"
PLIST_FILES+=		lib/syslog-ng/libgeoip-plugin.so
.else
CONFIGURE_ARGS+=	--disable-geoip
.endif

.if ${PORT_OPTIONS:MREDIS}
CONFIGURE_ARGS+=        --enable-redis
LIB_DEPENDS+=           libhiredis.so:databases/hiredis
PLIST_FILES+=           lib/syslog-ng/libredis.so
.else
CONFIGURE_ARGS+=        --disable-redis
.endif

.if ${PORT_OPTIONS:MSMTP}
CONFIGURE_ARGS+=	--with-libesmtp=/usr/local/
LIB_DEPENDS+=		libesmtp.so:mail/libesmtp
PLIST_FILES+=		lib/syslog-ng/libafsmtp.so
.else
CONFIGURE_ARGS+=	--disable-smtp
.endif

.if ${PORT_OPTIONS:MSQL}
LIB_DEPENDS+=		libdbi.so:databases/libdbi
CONFIGURE_ENV+=		LIBDBI_LIBS="-ldbi"
CONFIGURE_ARGS+=	--enable-sql
LDFLAGS+=		-L${LOCALBASE}/lib
PLIST_FILES+=		lib/syslog-ng/libafsql.so
.else
CONFIGURE_ARGS+=	--disable-sql
.endif

.if ${PORT_OPTIONS:MJSON}
LIB_DEPENDS+=		libjson-c.so:devel/json-c
CONFIGURE_ARGS+=	--enable-json
PLIST_FILES+= 		lib/syslog-ng/libjson-plugin.so
.else
CONFIGURE_ARGS+=        --disable-json
.endif

.if ${PORT_OPTIONS:MJAVA}
CONFIGURE_ARGS+=	--enable-java
USE_JAVA=	yes
BUILD_DEPENDS+=		gradle:devel/gradle
BUILD_DEPENDS+=		bash:shells/bash
PLIST_FILES+= 		lib/syslog-ng/libmod-java.so \
			lib/syslog-ng/java-modules/syslog-ng-core.jar \
			lib/syslog-ng/java-modules/log4j-1.2.16.jar \
			lib/syslog-ng/java-modules/elastic.jar \
			lib/syslog-ng/java-modules/http.jar \
			lib/syslog-ng/java-modules/kafka.jar \
			lib/syslog-ng/java-modules/java-modules.jar \
			lib/syslog-ng/java-modules/hdfs.jar \
			lib/syslog-ng/java-modules/syslog-ng-common.jar \
			lib/syslog-ng/java-modules/dummy.jar
.else
CONFIGURE_ARGS+=        --disable-java
.endif

.if ${PORT_OPTIONS:MPYTHON}
CONFIGURE_ARGS+=	--enable-python --with-python=2.7
USES+=			python:2.7
PLIST_FILES+= 		lib/syslog-ng/libmod-python.so
.else
CONFIGURE_ARGS+=        --disable-python
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

.include <bsd.port.mk>
