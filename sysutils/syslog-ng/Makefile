# Created by: Ivan Lago <ivan.lago@ifom-ieo-campus.it>
# $FreeBSD$

PORTNAME=	syslog-ng
PORTVERSION=	3.6.1
PORTREVISION=	1
CATEGORIES=	sysutils
DISTVERSION=	$(PORTVERSION:S/a/alpha/:S/b/beta/:S/r/rc/)
DISTFILES=	syslog-ng_${DISTVERSION}.tar.gz
MASTER_SITES=	http://www.balabit.com/downloads/files/syslog-ng/open-source-edition/${DISTVERSION}/source/

MAINTAINER=	cy@FreeBSD.org
COMMENT=	Powerful syslogd replacement

LIB_DEPENDS=	libevtlog.so:${PORTSDIR}/sysutils/eventlog \
		libpcre.so:${PORTSDIR}/devel/pcre

CONFLICTS?=	syslog-ng-[0-9]* syslog-ng[0-9]-[0-9]* \
		syslog-ng[0-9][0-9]-[0-9]* \
		syslog-ng-devel-[0-9]*
WRKSRC=		$(WRKDIR)/$(PORTNAME)-$(DISTVERSION)

MAKE_JOBS_UNSAFE=	yes
OPTIONS_RADIO=	SSL
OPTIONS_RADIO_SSL=	SYS_SSL PORTS_SSL
OPTIONS_DEFINE=	TCP_WRAPPERS SQL SPOOF IPV6 SMTP JSON GEOIP DOCS REDIS
OPTIONS_DEFAULT=	PORTS_SSL JSON
SYS_SSL_DESC=		Build with OpenSSL support (from system)
PORTS_SSL_DESC=		Build with OpenSSL support (from ports)
TCP_WRAPPERS_DESC=	Build with TCP Wrappers
SQL_DESC=		Build with database (libdbi) support
SPOOF_DESC=		Build with spoof source support
IPV6_DESC=		Build with IPV6 support
SMTP_DESC=		Build with SMTP support
JSON_DESC=		Build with JSON-C support
GEOIP_DESC=		Build with GeoIP support
REDIS_DESC=		Build with Redis support

USES=		gmake libtool pathfix pkgconfig
USE_LDCONFIG=	yes
USE_RC_SUBR=	syslog-ng
GNU_CONFIGURE=	yes
USE_GNOME=	glib20
SUB_FILES=	pkg-message
INSTALL_TARGET=	install-strip

CONFIGURE_ARGS=	--sysconfdir=${LOCALBASE}/etc --localstatedir=/var/db \
		--enable-dynamic-linking \
		--enable-debug \
		--datadir=${PREFIX}/share/syslog-ng/

BROKEN_sparc64=	Does not compile on sparc64: gcc core dump

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSYS_SSL} || ${PORT_OPTIONS:MPORTS_SSL}
USE_OPENSSL=		yes
CONFIGURE_ARGS+=	--enable-ssl
CONFIGURE_ENV+=		OPENSSL_CFLAGS="${OPENSSL_CFLAGS}" \
			OPENSSL_LIBS="${OPENSSL_LDFLAGS} -lcrypto -lssl"
PLIST_FILES+=		lib/syslog-ng/libafsocket-tls.so
.else
CONFIGURE_ARGS+=	--disable-ssl
.endif

.if ${PORT_OPTIONS:MPORTS_SSL}
WITH_OPENSSL_PORT=	yes
.endif

.if ${PORT_OPTIONS:MTCP_WRAPPERS}
CONFIGURE_ARGS+=	--enable-tcp-wrapper
.else
CONFIGURE_ARGS+=	--disable-tcp-wrapper
.endif

.if ${PORT_OPTIONS:MSPOOF}
LIB_DEPENDS+=		libnet.so:${PORTSDIR}/net/libnet
LIBNET_CONFIG?=		${LOCALBASE}/bin/libnet11-config
CONFIGURE_ARGS+=	--enable-spoof-source --with-libnet=${LOCALBASE}/bin
CFLAGS+=		`${LIBNET_CONFIG} --cflags` -I${LOCALBASE}/include
LDFLAGS+=		`${LIBNET_CONFIG} --libs`
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
LIB_DEPENDS+=		libGeoIP.so:${PORTSDIR}/net/GeoIP
CONFIGURE_ENV+=		GEOIP_LIBS="-L${LOCALBASE}/lib -lGeoIP"
PLIST_FILES+=		lib/syslog-ng/libtfgeoip.so
.else
CONFIGURE_ARGS+=	--disable-geoip
.endif

.if ${PORT_OPTIONS:MREDIS}
CONFIGURE_ARGS+=        --enable-redis
LIB_DEPENDS+=           libhiredis.so:${PORTSDIR}/databases/hiredis
PLIST_FILES+=           lib/syslog-ng/libredis.so
.else
CONFIGURE_ARGS+=        --disable-redis
.endif

.if ${PORT_OPTIONS:MSMTP}
CONFIGURE_ARGS+=	--with-libesmtp=/usr/local/
LIB_DEPENDS+=		libesmtp.so:${PORTSDIR}/mail/libesmtp
PLIST_FILES+=		lib/syslog-ng/libafsmtp.so
.else
CONFIGURE_ARGS+=	--disable-smtp
.endif

.if ${PORT_OPTIONS:MSQL}
LIB_DEPENDS+=		libdbi.so:${PORTSDIR}/databases/libdbi
CONFIGURE_ENV+=		LIBDBI_LIBS="-ldbi"
CONFIGURE_ARGS+=	--enable-sql
LDFLAGS+=		-L${LOCALBASE}/lib
PLIST_FILES+=		lib/syslog-ng/libafsql.so
.else
CONFIGURE_ARGS+=	--disable-sql
.endif

.if ${PORT_OPTIONS:MJSON}
LIB_DEPENDS+=		libjson-c.so:${PORTSDIR}/devel/json-c
CONFIGURE_ARGS+=	--enable-json
PLIST_FILES+= 		lib/syslog-ng/libjson-plugin.so
.else
CONFIGURE_ARGS+=        --disable-json
.endif

.if ${OSVERSION} >= 900034
CONFIGURE_ARGS+=        --disable-linux-caps
.endif

post-patch:
	@${REINPLACE_CMD} -e 's:libnet-config:libnet11-config:g' \
		${WRKSRC}/configure
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
