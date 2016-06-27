# $FreeBSD$

PORTNAME=	rsyslog
PORTVERSION=	7.6.7
PORTREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	http://www.rsyslog.com/files/download/rsyslog/
PKGNAMESUFFIX=	7

MAINTAINER=	brd@FreeBSD.org
COMMENT=	Syslogd supporting SQL, TCP, and TLS

BUILD_DEPENDS=	libgcrypt-config:security/libgcrypt \
		rst2man:textproc/py-docutils

LIB_DEPENDS=	libee.so:devel/libee \
		libestr.so:devel/libestr \
		libjson-c.so:devel/json-c \
		liblogging-stdlog.so:devel/liblogging

USE_LDCONFIG=	yes
USE_AUTOTOOLS=	autoconf

DEPRECATED=	Upgrade to rsyslog 8
EXPIRATION_DATE=2016-08-23

PORTSCOUT=	limit:^7\.4
PORTDOCS=	*
PORTEXAMPLES=	*

OPTIONS_DEFINE=	DBI DOCS GNUTLS GSSAPI MYSQL PGSQL RELP RFC3195 SNMP UUID

DBI_DESC=	LibDBI output module for rsyslog
GNUTLS_DESC=	GNUTLS module for rsyslog
GSSAPI_DESC=	GSS API input/output module for rsyslog
MYSQL_DESC=	MySQL output module for rsyslog
PGSQL_DESC=	PostgreSQL output module for rsyslog
RELP_DESC=	RELP input/output module for rsyslog
RFC3195_DESC=	RFC3195 input support for rsyslog
SNMP_DESC=	SNMP trap sender for rsyslog
UUID_DESC=	Support for generating a UUID per log message

USES=		alias libtool pkgconfig

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDBI}
LIB_DEPENDS+=	libdbi.so:databases/libdbi
CONFIGURE_ARGS+=--enable-libdbi
PLIST_FILES+=	lib/rsyslog/omlibdbi.so
.else
CONFIGURE_ARGS+=--disable-libdbi
.endif

.if ${PORT_OPTIONS:MGNUTLS}
LIB_DEPENDS+=	libgnutls.so:security/gnutls
CONFIGURE_ARGS+=--enable-gnutls
PLIST_FILES+=	lib/rsyslog/lmnsd_gtls.so
.else
CONFIGURE_ARGS+=--disable-gnutls
.endif

.if ${PORT_OPTIONS:MGSSAPI}
CONFIGURE_ARGS+=--enable-gssapi-krb5
PLIST_FILES+=	lib/rsyslog/imgssapi.so \
		lib/rsyslog/lmgssutil.so \
		lib/rsyslog/omgssapi.so
.else
CONFIGURE_ARGS+=--disable-gssapi-krb5
.endif

.if ${PORT_OPTIONS:MMYSQL}
USE_MYSQL=	yes
CONFIGURE_ARGS+=--enable-mysql
PLIST_FILES+=	lib/rsyslog/ommysql.so
.else
CONFIGURE_ARGS+=--disable-mysql
.endif

.if ${PORT_OPTIONS:MPGSQL}
USES+=		pgsql
CONFIGURE_ARGS+=--enable-pgsql
PLIST_FILES+=	lib/rsyslog/ompgsql.so
.else
CONFIGURE_ARGS+=--disable-pgsql
.endif

.if ${PORT_OPTIONS:MRELP}
LIB_DEPENDS+=	librelp.so:devel/librelp
CONFIGURE_ARGS+=--enable-relp
PLIST_FILES+=	lib/rsyslog/imrelp.so \
		lib/rsyslog/omrelp.so
.else
CONFIGURE_ARGS+=--disable-relp
.endif

.if ${PORT_OPTIONS:MRFC3195}
LIB_DEPENDS+=	liblogging.so:devel/liblogging
CONFIGURE_ARGS+=--enable-rfc3195
PLIST_FILES+=	lib/rsyslog/im3195.so
.else
CONFIGURE_ARGS+=--disable-rfc3195
.endif

.if ${PORT_OPTIONS:MSNMP}
LIB_DEPENDS+=	libnetsnmp.so:net-mgmt/net-snmp
CONFIGURE_ARGS+=--enable-snmp
PLIST_FILES+=	lib/rsyslog/omsnmp.so
.else
CONFIGURE_ARGS+=--disable-snmp
.endif

.if ${PORT_OPTIONS:MUUID}
LIB_DEPENDS+=	libuuid.so:misc/e2fsprogs-libuuid
.else
CONFIGURE_ARGS+=--disable-uuid
.endif

.ifdef WITH_MYSQL_MICROSECONDS
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-mysql-microseconds
.endif

.ifdef WITH_SANE_HOSTNAME
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-sane-hostname
.endif

CONFLICTS=	rsyslog6-[1-9]* rsyslog-devel-[0-9]*
CFLAGS+=	-I${LOCALBASE}/include
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
GNU_CONFIGURE=	yes

.ifdef WITH_DEBUG
CONFIGURE_ARGS+=--enable-rtinst --enable-debug
.endif

.include <bsd.port.pre.mk>

.if ${ARCH} == "i386"
CPPFLAGS+=-march=i686
.endif

CONFIGURE_ENV+=	LIBESTR_CFLAGS="${CFLAGS}" LIBESTR_LIBS="${LDFLAGS} -lestr" LIBEE_CFLAGS="${CFLAGS}" LIBEE_LIBS="${LDFLAGS} -lee -lkvm"
CFLAGS+=	${CPPFLAGS}

USE_RC_SUBR=	${PORTNAME}d
SUB_FILES=	pkg-message

CONFIGURE_ARGS+=	--enable-imfile --enable-mail --enable-imdiag --enable-impstats --enable-omstdout --enable-cached-man-pages --disable-testbench

post-patch:
	@${REINPLACE_CMD} -e 's|/lib/rsyslog/|${PREFIX}/lib/rsyslog/|'\
		${WRKSRC}/tools/syslogd.c
	@${GREP} -rl '/etc/rsyslog.conf' ${WRKSRC}|${XARGS} ${REINPLACE_CMD} -e\
		's|/etc/rsyslog.conf|${PREFIX}/etc/rsyslog.conf|'
	@${REINPLACE_CMD} -e 's,/lib/rsyslog,${PREFIX}/lib/rsyslog,' ${WRKSRC}/tools/syslogd.c
	@${FIND} ${WRKSRC} -name '*.bak' -delete

post-install:
	@${INSTALL} -d ${STAGEDIR}${DOCSDIR}/
	@${INSTALL_DATA} ${WRKSRC}/doc/*html ${STAGEDIR}${DOCSDIR}/
	@${INSTALL_DATA} ${WRKSRC}/doc/*png ${STAGEDIR}${DOCSDIR}/
	@${INSTALL} -d ${STAGEDIR}${EXAMPLESDIR}
	@${INSTALL_DATA} ${WRKSRC}/doc/rsyslog-example.conf ${STAGEDIR}${EXAMPLESDIR}
.for l in lmregexp lmzlibw lmnet lmnetstrms lmstrmsrv lmnsd_ptcp lmcry_gcry lmtcpsrv lmtcpclt immark imuxsock imtcp imudp omtesting imklog impstats omstdout imfile imdiag ommail omruleset
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/rsyslog/${l}.so
.endfor

.include <bsd.port.post.mk>
