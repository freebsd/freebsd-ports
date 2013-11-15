# Created by: Ivan Lago <ivan.lago@ifom-ieo-campus.it>
# $FreeBSD$

PORTNAME=	syslog-ng
PORTVERSION=	3.3.11
CATEGORIES=	sysutils
MASTER_SITES=	http://www.balabit.com/downloads/files/syslog-ng/sources/$(PORTVERSION)/source/
PKGNAMESUFFIX=	33
DISTFILES=	$(PORTNAME)_$(PORTVERSION).tar.gz

MAINTAINER=	cy@FreeBSD.org
COMMENT=	A powerful syslogd replacement

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

NO_STAGE=	yes
.include <bsd.port.options.mk>

LIB_DEPENDS=	evtlog.0:${PORTSDIR}/sysutils/eventlog

MAN1=		loggen.1 pdbtool.1 syslog-ng-ctl.1
MAN5=		syslog-ng.conf.5
MAN8=		syslog-ng.8

USE_LDCONFIG=	yes
USE_RC_SUBR=	syslog-ng
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GNOME=	glib20 gnomehack
SUB_FILES=	pkg-message

CONFIGURE_ARGS=	--sysconfdir=${LOCALBASE}/etc --localstatedir=/var/db \
		--enable-dynamic-linking

.if ${PORT_OPTIONS:MSYS_SSL} || ${PORT_OPTIONS:MPORTS_SSL}
USE_OPENSSL=		yes
CONFIGURE_ARGS+=	--enable-ssl
CONFIGURE_ENV+=		OPENSSL_CFLAGS="${OPENSSL_CFLAGS}" \
			OPENSSL_LIBS="${OPENSSL_LDFLAGS} -lcrypto -lssl"
PLIST_FILES+=		lib/syslog-ng/libafsocket-tls.la lib/syslog-ng/libafsocket-tls.so
.else
CONFIGURE_ARGS+=	--disable-ssl
.endif

.if ${PORT_OPTIONS:MPORTS_SSL}
WITH_OPENSSL_PORT=	yes
.endif

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MTCP_WRAPPERS}
CONFIGURE_ARGS+=	--enable-tcp-wrapper
.else
CONFIGURE_ARGS+=	--disable-tcp-wrapper
.endif

.if ${PORT_OPTIONS:MSPOOF}
LIB_DEPENDS+=		net:${PORTSDIR}/net/libnet
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
LIB_DEPENDS+=		pcre:${PORTSDIR}/devel/pcre
.else
CONFIGURE_ARGS+=	--disable-pcre
.endif

.if ${PORT_OPTIONS:MSQL}
LIB_DEPENDS+=		dbi.1:${PORTSDIR}/databases/libdbi
CONFIGURE_ENV+=		LIBDBI_LIBS="-ldbi"
CONFIGURE_ARGS+=	--enable-sql
PLIST_FILES+=		lib/syslog-ng/libafsql.la lib/syslog-ng/libafsql.so
.else
CONFIGURE_ARGS+=	--disable-sql
.endif

.if ${PORT_OPTIONS:MJSON_GLIB}
LIB_DEPENDS+=		json-glib-1.0.0:${PORTSDIR}/devel/json-glib
CONFIGURE_ARGS+=	--enable-json --with-json=json-glib
PLIST_FILES+=		lib/syslog-ng/libtfjson.la lib/syslog-ng/libtfjson.so
.elif ${PORT_OPTIONS:MJSON_C}
LIB_DEPENDS+=		json:${PORTSDIR}/devel/json-c
CONFIGURE_ARGS+=	--enable-json --with-json=json-c
PLIST_FILES+=		lib/syslog-ng/libtfjson.la lib/syslog-ng/libtfjson.so
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
	${INSTALL_SCRIPT} ${WRKSRC}/contrib/syslog2ng ${PREFIX}/sbin
.endif
.if ${PORT_OPTIONS:MDOCS}
	${INSTALL} -d -o ${SHAREOWN} -g ${SHAREGRP} \
			${PREFIX}/share/doc/syslog-ng
	${INSTALL_DATA} ${WRKSRC}/AUTHORS ${PREFIX}/share/doc/syslog-ng
	${INSTALL_DATA} ${WRKSRC}/COPYING ${PREFIX}/share/doc/syslog-ng
	${INSTALL_DATA} ${WRKSRC}/ChangeLog ${PREFIX}/share/doc/syslog-ng
	${INSTALL_DATA} ${WRKSRC}/NEWS ${PREFIX}/share/doc/syslog-ng
.endif
	@if [ ! -f ${PREFIX}/etc/syslog-ng.conf.sample ]; then \
		${INSTALL_DATA} ${FILESDIR}/syslog-ng.conf.sample ${PREFIX}/etc; \
	fi
	@if [ ! -f ${PREFIX}/etc/syslog-ng.conf.dist ]; then \
		${INSTALL_DATA} ${WRKSRC}/scl/syslog-ng.conf.dist ${PREFIX}/etc; \
	fi
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
