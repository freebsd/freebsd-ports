# $FreeBSD$

PORTNAME=	rsyslog
PORTVERSION=	7.2.4
PORTREVISION?=	0
CATEGORIES=	sysutils
MASTER_SITES=	http://www.rsyslog.com/files/download/rsyslog/

MAINTAINER=	brd@FreeBSD.org
COMMENT?=	Syslogd supporting SQL, TCP, and TLS

USE_LDCONFIG=	yes

LIB_DEPENDS+=	ee:${PORTSDIR}/devel/libee \
		estr:${PORTSDIR}/devel/libestr \
		sysinfo:${PORTSDIR}/devel/libsysinfo \
		json.0:${PORTSDIR}/devel/json-c/ \
		uuid:${PORTSDIR}/misc/e2fsprogs-libuuid

PORTSCOUT=	limit:^6

OPTIONS_DEFINE=	DBI GNUTLS GSSAPI MYSQL PGSQL RELP RFC3195 SNMP

DBI_DESC=	LibDBI output module for rsyslog
GNUTLS_DESC=	GNUTLS module for rsyslog
GSSAPI_DESC=	GSS API input/output module for rsyslog
MYSQL_DESC=	MySQL output module for rsyslog
PGSQL_DESC=	PostgreSQL output module for rsyslog
RELP_DESC=	RELP input/output module for rsyslog
RFC3195_DESC=	RFC3195 input support for rsyslog
SNMP_DESC=	SNMP trap sender for rsyslog

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDBI}
LIB_DEPENDS+=	dbi.1:${PORTSDIR}/databases/libdbi
USE_PKGCONFIG=	yes
CONFIGURE_ARGS+=--enable-libdbi
PLIST_FILES+=	lib/rsyslog/omlibdbi.la \
		lib/rsyslog/omlibdbi.so
.endif

.if ${PORT_OPTIONS:MGNUTLS}
LIB_DEPENDS+=	gnutls.47:${PORTSDIR}/security/gnutls \
		gcrypt.18:${PORTSDIR}/security/libgcrypt
USE_PKGCONFIG=	yes
CONFIGURE_ARGS+=--enable-gnutls
PLIST_FILES+=	lib/rsyslog/lmnsd_gtls.la \
		lib/rsyslog/lmnsd_gtls.so
.endif

.if ${PORT_OPTIONS:MGSSAPI}
CONFIGURE_ARGS+=--enable-gssapi-krb5
PLIST_FILES+=	lib/rsyslog/imgssapi.la \
		lib/rsyslog/imgssapi.so \
		lib/rsyslog/lmgssutil.la \
		lib/rsyslog/lmgssutil.so \
		lib/rsyslog/omgssapi.la \
		lib/rsyslog/omgssapi.so
.endif

.if ${PORT_OPTIONS:MMYSQL}
USE_MYSQL=	yes
CONFIGURE_ARGS+=--enable-mysql
PLIST_FILES+=	lib/rsyslog/ommysql.so \
					lib/rsyslog/ommysql.la
.endif

.if ${PORT_OPTIONS:MPGSQL}
USE_PGSQL=	yes
CONFIGURE_ARGS+=--enable-pgsql
PLIST_FILES+=	lib/rsyslog/ompgsql.so \
					lib/rsyslog/ompgsql.la
.endif

.if ${PORT_OPTIONS:MRELP}
LIB_DEPENDS+=	relp.0:${PORTSDIR}/devel/librelp
USE_PKGCONFIG=	yes
CONFIGURE_ARGS+=--enable-relp
PLIST_FILES+=	lib/rsyslog/imrelp.la \
		lib/rsyslog/imrelp.so \
		lib/rsyslog/omrelp.la \
		lib/rsyslog/omrelp.so
.endif

.if ${PORT_OPTIONS:MRFC3195}
LIB_DEPENDS+=	logging.0:${PORTSDIR}/devel/liblogging
USE_PKGCONFIG=	yes
CONFIGURE_ARGS+=--enable-rfc3195
PLIST_FILES+=	lib/rsyslog/im3195.la \
		lib/rsyslog/im3195.so
.endif

.if ${PORT_OPTIONS:MSNMP}
LIB_DEPENDS+=	netsnmp.30:${PORTSDIR}/net-mgmt/net-snmp
CONFIGURE_ARGS+=--enable-snmp
PLIST_FILES+=	lib/rsyslog/omsnmp.la \
		lib/rsyslog/omsnmp.so
.endif


.ifdef WITH_MYSQL_MICROSECONDS
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-mysql-microseconds
.endif

.ifdef WITH_SANE_HOSTNAME
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-sane-hostname
.endif

CONFLICTS=	rsyslog-[56].[0-9]*
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

CONFIGURE_ENV+=	LIBESTR_CFLAGS="${CFLAGS}" LIBESTR_LIBS="${LDFLAGS} -lestr" LIBEE_CFLAGS="${CFLAGS}" LIBEE_LIBS="${LDFLAGS} -lee -lsysinfo -lkvm"
CFLAGS+=	${CPPFLAGS}

MAN8=	rsyslogd.8
MAN5=	rsyslog.conf.5

USE_RC_SUBR=	${PORTNAME}d
SUB_FILES=	pkg-message

CONFIGURE_ARGS+=	--enable-imfile --enable-mail --enable-imdiag --enable-impstats --enable-omstdout

post-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|/lib/rsyslog/|${PREFIX}/lib/rsyslog/|'\
		${WRKSRC}/tools/syslogd.c
	@${GREP} -rl '/etc/rsyslog.conf' ${WRKSRC}|${XARGS} ${REINPLACE_CMD} -e\
		's|/etc/rsyslog.conf|${PREFIX}/etc/rsyslog.conf|'
	@${REINPLACE_CMD} -e 's,/lib/rsyslog,${PREFIX}/lib/rsyslog,' ${WRKSRC}/tools/syslogd.c
	@${FIND} ${WRKSRC} -name '*.bak' -delete

post-install:
.ifndef NOPORTDOCS
	@${INSTALL} -d ${DOCSDIR}/
	@${INSTALL_DATA} ${WRKSRC}/doc/*html ${DOCSDIR}/
	@${INSTALL_DATA} ${WRKSRC}/doc/*jpg ${DOCSDIR}/
.endif
.ifndef NOPORTEXAMPLES
	@${INSTALL} -d ${EXAMPLESDIR}
	@${INSTALL_DATA} ${WRKSRC}/doc/rsyslog-example.conf ${EXAMPLESDIR}
.endif
	@${CAT} ${PKGMESSAGE}

.if ${OSVERSION} < 700042
USE_GCC=	4.2+
.endif

.include <bsd.port.post.mk>
