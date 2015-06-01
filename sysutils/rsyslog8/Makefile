# $FreeBSD$

PORTNAME=	rsyslog
PORTVERSION=	8.10.0
CATEGORIES=	sysutils
MASTER_SITES=	http://www.rsyslog.com/files/download/rsyslog/

MAINTAINER=	brd@FreeBSD.org
COMMENT=	Syslogd supporting SQL, TCP, and TLS

BUILD_DEPENDS=	libgcrypt-config:${PORTSDIR}/security/libgcrypt \
		rst2man:${PORTSDIR}/textproc/py-docutils

LIB_DEPENDS=	libee.so:${PORTSDIR}/devel/libee \
		libestr.so:${PORTSDIR}/devel/libestr \
		libjson-c.so:${PORTSDIR}/devel/json-c \
		liblogging-stdlog.so:${PORTSDIR}/devel/liblogging \
		libuuid.so:${PORTSDIR}/misc/e2fsprogs-libuuid

USE_LDCONFIG=	yes
USE_AUTOTOOLS=	autoconf

PORTSCOUT=	limit:^8\.8
PKGNAMESUFFIX=	8

OPTIONS_DEFINE=	DBI DOCS GNUTLS GSSAPI MYSQL PGSQL RELP SNMP

DBI_DESC=	LibDBI output module for rsyslog
GNUTLS_DESC=	GNUTLS module for rsyslog
GSSAPI_DESC=	GSS API input/output module for rsyslog
MYSQL_DESC=	MySQL output module for rsyslog
PGSQL_DESC=	PostgreSQL output module for rsyslog
RELP_DESC=	RELP input/output module for rsyslog
SNMP_DESC=	SNMP trap sender for rsyslog

USES=		libtool pkgconfig

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDBI}
LIB_DEPENDS+=	libdbi.so:${PORTSDIR}/databases/libdbi
CONFIGURE_ARGS+=--enable-libdbi
PLIST_FILES+=	lib/rsyslog/omlibdbi.so
.else
CONFIGURE_ARGS+=--disable-libdbi
.endif

.if ${PORT_OPTIONS:MGNUTLS}
LIB_DEPENDS+=	libgnutls.so:${PORTSDIR}/security/gnutls \
		libgcrypt.so:${PORTSDIR}/security/libgcrypt
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
LIB_DEPENDS+=	librelp.so:${PORTSDIR}/devel/librelp
CONFIGURE_ARGS+=--enable-relp
PLIST_FILES+=	lib/rsyslog/imrelp.so \
		lib/rsyslog/omrelp.so
.else
CONFIGURE_ARGS+=--disable-relp
.endif

.if ${PORT_OPTIONS:MSNMP}
LIB_DEPENDS+=	libnetsnmp.so:${PORTSDIR}/net-mgmt/net-snmp
CONFIGURE_ARGS+=--enable-snmp
PLIST_FILES+=	lib/rsyslog/omsnmp.so
.else
CONFIGURE_ARGS+=--disable-snmp
.endif

.ifdef WITH_MYSQL_MICROSECONDS
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-mysql-microseconds
.endif

.ifdef WITH_SANE_HOSTNAME
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-sane-hostname
.endif

CONFLICTS=	rsyslog6-* rsyslog-[0-9].*
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

CONFIGURE_ARGS+=	--enable-cached-man-pages --enable-imdiag --enable-imfile --enable-impstats --enable-mail --enable-omprog --enable-omstdout --enable-omuxsock --enable-rfc3195 --disable-testbench

post-patch:
	@${REINPLACE_CMD} -e 's|/lib/rsyslog/|${PREFIX}/lib/rsyslog/|'\
		${WRKSRC}/tools/syslogd.c
	@${GREP} -rl '/etc/rsyslog.conf' ${WRKSRC}|${XARGS} ${REINPLACE_CMD} -e\
		's|/etc/rsyslog.conf|${PREFIX}/etc/rsyslog.conf|'
	@${REINPLACE_CMD} -e 's,/lib/rsyslog,${PREFIX}/lib/rsyslog,' ${WRKSRC}/tools/syslogd.c
	@${FIND} ${WRKSRC} -name '*.bak' -delete

post-install:
.for l in im3195 imdiag imfile imklog immark impstats imtcp imudp imuxsock lmcry_gcry lmnet lmnetstrms lmnsd_ptcp lmregexp lmstrmsrv lmtcpclt lmtcpsrv lmzlibw mmexternal ommail omprog omstdout omtesting omuxsock
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/rsyslog/${l}.so
.endfor

.include <bsd.port.post.mk>
