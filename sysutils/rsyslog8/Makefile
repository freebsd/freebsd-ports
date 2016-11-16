# $FreeBSD$

PORTNAME=	rsyslog
PORTVERSION=	8.23.0
CATEGORIES=	sysutils
MASTER_SITES=	http://www.rsyslog.com/files/download/rsyslog/

MAINTAINER=	matthew@FreeBSD.org
COMMENT=	Syslogd supporting SQL, TCP, and TLS

LICENSE=	GPLv3 LGPL3 APACHE20
LICENSE_COMB=	multi

LIB_DEPENDS=	libee.so:devel/libee \
		libestr.so:devel/libestr \
		libfastjson.so:devel/libfastjson \
		liblogging-stdlog.so:devel/liblogging \
		libuuid.so:misc/e2fsprogs-libuuid

BUILD_DEPENDS=	rst2man:textproc/py-docutils

PORTSCOUT=	limit:^8\.

USE_LDCONFIG=	yes

OPTIONS_DEFINE=	DBI DOCS GCRYPT GNUTLS GSSAPI MYSQL PGSQL RELP \
		SNMP NORMALIZE
OPTIONS_DEFAULT=GCRYPT
OPTIONS_SUB=	yes

DBI_DESC=	LibDBI output module for rsyslog
GCRYPT_DESC=	Enable support for encrypted logfiles
GNUTLS_DESC=	GNUTLS module for rsyslog
GSSAPI_DESC=	GSS API input/output module for rsyslog
MYSQL_DESC=	MySQL output module for rsyslog
PGSQL_DESC=	PostgreSQL output module for rsyslog
RELP_DESC=	RELP input/output module for rsyslog
SNMP_DESC=	SNMP trap sender for rsyslog
NORMALIZE_DESC=	Message normalization module for rsyslog

USES=		libtool pkgconfig autoreconf

DBI_LIB_DEPENDS=	libdbi.so:databases/libdbi
DBI_CONFIGURE_ENABLE=	libdbi
DBI_PLIST_FILES=	lib/rsyslog/omlibdbi.so

GCRYPT_CONFIGURE_ENABLE=libgcrypt
GCRYPT_LIB_DEPENDS=	libgcrypt.so:security/libgcrypt \
			libgpg-error.so:security/libgpg-error
GCRYPT_BUILD_DEPENDS=	libgcrypt-config:security/libgcrypt

GNUTLS_LIB_DEPENDS=	libgnutls.so:security/gnutls
GNUTLS_IMPLIES=		GCRYPT
GNUTLS_CONFIGURE_ENABLE=gnutls
GNUTLS_PLIST_FILES=	lib/rsyslog/lmnsd_gtls.so

GSSAPI_CONFIGURE_ENABLE=gssapi-krb5
GSSAPI_PLIST_FILES=	lib/rsyslog/imgssapi.so \
			lib/rsyslog/lmgssutil.so \
			lib/rsyslog/omgssapi.so

MYSQL_USE=		MYSQL=yes
MYSQL_CONFIGURE_ENABLE=	mysql
MYSQL_PLIST_FILES=	lib/rsyslog/ommysql.so

PGSQL_USES=		pgsql
PGSQL_CONFIGURE_ENABLE=	pgsql
PGSQL_PLIST_FILES=	lib/rsyslog/ompgsql.so

RELP_LIB_DEPENDS=	librelp.so:devel/librelp
RELP_CONFIGURE_ENABLE=	relp
RELP_PLIST_FILES=	lib/rsyslog/imrelp.so \
			lib/rsyslog/omrelp.so

SNMP_LIB_DEPENDS=	libnetsnmp.so:net-mgmt/net-snmp
SNMP_CONFIGURE_ENABLE=	snmp
SNMP_PLIST_FILES=	lib/rsyslog/omsnmp.so

NORMALIZE_LIB_DEPENDS=	liblognorm.so:devel/liblognorm
NORMALIZE_CONFIGURE_ENABLE=	mmnormalize
NORMALIZE_PLIST_FILES=	lib/rsyslog/mmnormalize.so

.include <bsd.port.options.mk>

.ifdef WITH_MYSQL_MICROSECONDS
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-mysql-microseconds
.endif

.ifdef WITH_SANE_HOSTNAME
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-sane-hostname
.endif

CFLAGS+=	-I${LOCALBASE}/include
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

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

CONFIGURE_ARGS+=	--enable-imdiag --enable-imfile --enable-impstats --enable-mail --enable-omprog --enable-omstdout --enable-omuxsock --enable-rfc3195 --disable-testbench

post-patch:
	@${REINPLACE_CMD} -e 's|/lib/rsyslog/|${PREFIX}/lib/rsyslog/|'\
		${WRKSRC}/tools/syslogd.c
	@${GREP} -rl '/etc/rsyslog.conf' ${WRKSRC}|${XARGS} ${REINPLACE_CMD} -e\
		's|/etc/rsyslog.conf|${PREFIX}/etc/rsyslog.conf|'
	@${REINPLACE_CMD} -e 's,/lib/rsyslog,${PREFIX}/lib/rsyslog,' ${WRKSRC}/tools/syslogd.c
.if ${OPSYS} == FreeBSD && ${OSVERSION} < 1100504
	@${REINPLACE_CMD} -e 's,recvmmsg ,,' ${WRKSRC}/configure.ac
.endif
	@${FIND} ${WRKSRC} -name '*.bak' -delete

.include <bsd.port.post.mk>
