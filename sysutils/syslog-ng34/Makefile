# Created by: Ivan Lago <ivan.lago@ifom-ieo-campus.it>
# $FreeBSD$

PORTNAME=	syslog-ng
PORTVERSION=	3.4.8
PORTREVISION=	9
CATEGORIES=	sysutils
DISTVERSION=	$(PORTVERSION:S/a/alpha/:S/b/beta/:S/r/rc/)
.if !defined(MASTERDIR)
PKGNAMESUFFIX=	34
.endif
DISTFILES=	syslog-ng_${DISTVERSION}.tar.gz
MASTER_SITES=	http://www.balabit.com/downloads/files/syslog-ng/open-source-edition/${DISTVERSION}/source/

MAINTAINER=	cy@FreeBSD.org
COMMENT=	Powerful syslogd replacement

BROKEN_powerpc64=	Does not build

DEPRECATED=	EOL, no longer supported by bababit.hu
EXPIRATION_DATE=	2016-06-30

LIB_DEPENDS=	libevtlog.so:sysutils/eventlog

CONFLICTS?=	syslog-ng-[0-9]* syslog-ng[0-9]-[0-9]* \
		syslog-ng[0-9][0-9]-[0-9]* \
		syslog-ng-devel-[0-9]*
WRKSRC=		$(WRKDIR)/$(PORTNAME)-$(DISTVERSION)

OPTIONS_DEFINE=	TCP_WRAPPERS SQL SPOOF IPV6 PCRE SMTP JSON GEOIP DOCS OPENSSL
OPTIONS_DEFAULT=	OPENSSL PCRE
TCP_WRAPPERS_DESC=	Build with TCP Wrappers
SQL_DESC=		Build with database (libdbi) support
SPOOF_DESC=		Build with spoof source support
IPV6_DESC=		Build with IPV6 support
PCRE_DESC=		Build with PCRE support
SMTP_DESC=		Build with SMTP support
JSON_DESC=		Build with JSON-C support
GEOIP_DESC=		Build with GeoIP support

USES=		gmake libtool pathfix pkgconfig
USE_LDCONFIG=	yes
USE_RC_SUBR=	syslog-ng
GNU_CONFIGURE=	yes
USE_GNOME=	glib20
SUB_FILES=	pkg-message

CONFIGURE_ARGS=	--sysconfdir=${LOCALBASE}/etc --localstatedir=/var/db \
		--enable-dynamic-linking \
		--enable-debug --disable-linux-caps

BROKEN_sparc64=	Does not compile on sparc64: gcc core dump

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MOPENSSL}
USE_OPENSSL=		yes
WITH_OPENSSL_PORT=	yes
CONFIGURE_ARGS+=	--enable-ssl
CONFIGURE_ENV+=		OPENSSL_CFLAGS="${OPENSSL_CFLAGS}" \
			OPENSSL_LIBS="${OPENSSL_LDFLAGS} -lcrypto -lssl"
PLIST_FILES+=		lib/syslog-ng/libafsocket-tls.so
.else
CONFIGURE_ARGS+=	--disable-ssl
.endif

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

.if ${PORT_OPTIONS:MPCRE}
CONFIGURE_ARGS+=	--enable-pcre
LIB_DEPENDS+=		libpcre.so:devel/pcre
.else
CONFIGURE_ARGS+=	--disable-pcre
.endif

.if ${PORT_OPTIONS:MGEOIP}
CONFIGURE_ARGS+=	--enable-geoip
LIB_DEPENDS+=		libGeoIP.so:net/GeoIP
CONFIGURE_ENV+=		GEOIP_LIBS="-lGeoIP"
PLIST_FILES+=		lib/syslog-ng/libtfgeoip.so
.else
CONFIGURE_ARGS+=	--disable-geoip
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
CONFIGURE_ENV+=		LIBDBI_LIBS="-L${LOCALBASE}/lib -ldbi"
CONFIGURE_ARGS+=	--enable-sql
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

post-patch:
	@${LN} ${WRKSRC}/scl/syslog-ng.conf ${WRKSRC}/scl/syslog-ng.conf.sample
	@${LN} ${WRKSRC}/scl/scl.conf ${WRKSRC}/scl/scl.conf.sample

post-install:
	${INSTALL_DATA} ${FILESDIR}/syslog-ng.conf.sample ${STAGEDIR}${PREFIX}/etc
	${INSTALL_DATA} ${WRKSRC}/scl/syslog-ng.conf.sample ${STAGEDIR}${PREFIX}/etc
	${INSTALL_DATA} ${WRKSRC}/scl/scl.conf.sample ${STAGEDIR}${PREFIX}/etc

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/AUTHORS ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/COPYING ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/NEWS ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
