# Created by: Ivan Lago <ivan.lago@ifom-ieo-campus.it>
# $FreeBSD$

PORTNAME=	syslog-ng
PORTVERSION=	3.3.11
PORTREVISION=	4
CATEGORIES=	sysutils
MASTER_SITES=	http://www.balabit.com/downloads/files/syslog-ng/sources/$(PORTVERSION)/source/
PKGNAMESUFFIX=	33
DISTFILES=	$(PORTNAME)_$(PORTVERSION).tar.gz

MAINTAINER=	cy@FreeBSD.org
COMMENT=	Powerful syslogd replacement

LIB_DEPENDS=	libevtlog.so:${PORTSDIR}/sysutils/eventlog

CONFLICTS?=	syslog-ng-[0-9]* syslog-ng[0-9]-[0-9]* \
		syslog-ng-devel-[0-9]*
WRKSRC=		$(WRKDIR)/$(PORTNAME)-$(PORTVERSION)

OPTIONS_RADIO=	SSL JSON
OPTIONS_RADIO_SSL=	SYS_SSL PORTS_SSL
OPTIONS_RADIO_JSON=	JSON_C JSON_GLIB
OPTIONS_DEFINE=	TCP_WRAPPERS SQL SPOOF IPV6 PCRE SYSLOG2NG DOCS
OPTIONS_DEFAULT=	PORTS_SSL PCRE
SYS_SSL_DESC=		Build with OpenSSL support (from system)
PORTS_SSL_DESC=		Build with OpenSSL support (from ports)
TCP_WRAPPERS_DESC=	Build with TCP Wrappers
SQL_DESC=		Build with database (libdbi) support
SPOOF_DESC=		Build with spoof source support
IPV6_DESC=		Build with IPV6 support
PCRE_DESC=		Build with PCRE support
JSON_C_DESC=		Build with JSON-C support
JSON_GLIB_DESC=		Build with JSON-GLIB support
SYSLOG2NG_DESC=		Install syslog2ng script

USE_LDCONFIG=	yes
USE_RC_SUBR=	syslog-ng
GNU_CONFIGURE=	yes
USES=		gmake libtool pathfix pkgconfig
USE_GNOME=	glib20
SUB_FILES=	pkg-message

CONFIGURE_ARGS=	--sysconfdir=${LOCALBASE}/etc --localstatedir=/var/db \
		--enable-dynamic-linking

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
CFLAGS+=		-g `${LIBNET_CONFIG} --cflags` -I${LOCALBASE}/include
LDFLAGS+=		-g `${LIBNET_CONFIG} --libs`
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
LIB_DEPENDS+=		libpcre.so:${PORTSDIR}/devel/pcre
.else
CONFIGURE_ARGS+=	--disable-pcre
.endif

.if ${PORT_OPTIONS:MSQL}
LIB_DEPENDS+=		libdbi.so:${PORTSDIR}/databases/libdbi
CONFIGURE_ENV+=		LIBDBI_LIBS="-L${LOCALBASE}/lib -ldbi"
CONFIGURE_ARGS+=	--enable-sql
PLIST_FILES+=		lib/syslog-ng/libafsql.so
.else
CONFIGURE_ARGS+=	--disable-sql
.endif

.if ${PORT_OPTIONS:MJSON_GLIB}
LIB_DEPENDS+=		libjson-glib-1.0.so:${PORTSDIR}/devel/json-glib
CONFIGURE_ARGS+=	--enable-json --with-json=json-glib
PLIST_FILES+=		lib/syslog-ng/libtfjson.so
.elif ${PORT_OPTIONS:MJSON_C}
LIB_DEPENDS+=		libjson-c.so:${PORTSDIR}/devel/json-c
CONFIGURE_ARGS+=	--enable-json --with-json=json-c
PLIST_FILES+=		lib/syslog-ng/libtfjson.so
.else
CONFIGURE_ARGS+=	--disable-json
.endif

.if ${OSVERSION} >= 900034
CONFIGURE_ARGS+=        --disable-linux-caps
.endif

.if ${PORT_OPTIONS:MSYSLOG2NG}
PLIST_FILES+=		sbin/syslog2ng
.endif

post-patch:
	@${REINPLACE_CMD} -e 's:libnet-config:libnet11-config:g' ${WRKSRC}/configure
	@${LN} ${WRKSRC}/scl/syslog-ng.conf ${WRKSRC}/scl/syslog-ng.conf.dist
	@${FIND} ${WRKSRC} -name "*.orig" -delete

post-install:
.if ${PORT_OPTIONS:MSYSLOG2NG}
	${INSTALL_SCRIPT} ${WRKSRC}/contrib/syslog2ng ${STAGEDIR}${PREFIX}/sbin
.endif
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/doc/syslog-ng
	${INSTALL_DATA} ${WRKSRC}/AUTHORS ${STAGEDIR}${PREFIX}/share/doc/syslog-ng
	${INSTALL_DATA} ${WRKSRC}/COPYING ${STAGEDIR}${PREFIX}/share/doc/syslog-ng
	${INSTALL_DATA} ${WRKSRC}/ChangeLog ${STAGEDIR}${PREFIX}/share/doc/syslog-ng
	${INSTALL_DATA} ${WRKSRC}/NEWS ${STAGEDIR}${PREFIX}/share/doc/syslog-ng
	${INSTALL_DATA} ${FILESDIR}/syslog-ng.conf.sample ${STAGEDIR}${PREFIX}/etc
	${INSTALL_DATA} ${WRKSRC}/scl/syslog-ng.conf.dist ${STAGEDIR}${PREFIX}/etc

.include <bsd.port.mk>
