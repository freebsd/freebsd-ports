PORTNAME=	rsyslog
PORTVERSION=	8.2506.0
PORTREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	http://www.rsyslog.com/files/download/rsyslog/

MAINTAINER=	matthew@FreeBSD.org
COMMENT=	Syslogd supporting SQL, TCP, and TLS
WWW=		https://www.rsyslog.com/

PATCH_SITES=	https://github.com/rgerhards/${PORTNAME}/commit/
PATCHFILES=	72b8bcc05318f0a72ec828d1a5329fa98c021eb8.patch:-p1

LICENSE=	GPLv3 LGPL3 APACHE20
LICENSE_COMB=	multi

LIB_DEPENDS=	libestr.so:devel/libestr \
		libfastjson.so:devel/libfastjson \
		liblogging-rfc3195.so:devel/liblogging \
		libuuid.so:misc/libuuid \
		libcurl.so:ftp/curl
BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}docutils>0:textproc/py-docutils@${PY_FLAVOR}

USES=		cpe libtool pkgconfig autoreconf python:env

PORTSCOUT=	limit:^8\.

OPTIONS_DEFINE=	DBI DOCS DTLS ELASTIC GCRYPT GSSAPI HTTP JSONPARSE KAFKA \
		MYSQL NORMALIZE PGSQL RABBITMQ RELP SNMP
OPTIONS_RADIO=	SSLLIB
OPTIONS_RADIO_SSLLIB=	GNUTLS OPENSSL
OPTIONS_DEFAULT=GCRYPT
OPTIONS_SUB=	yes

DBI_DESC=		LibDBI output module for rsyslog
DBI_LIB_DEPENDS=	libdbi.so:databases/libdbi
DBI_CONFIGURE_ENABLE=	libdbi
DBI_PLIST_FILES=	lib/rsyslog/omlibdbi.so

DTLS_DESC=		DTLS input/output modules
DTLS_CONFIGURE_ENABLE=	imdtls omdtls
DTLS_PLIST_FILES=	lib/rsyslog/imdtls.so \
			lib/rsyslog/omdtls.so

ELASTIC_DESC=		Elasticsearch module for rsyslog
ELASTIC_CONFIGURE_ENABLE=	elasticsearch
ELASTIC_PLIST_FILES=	lib/rsyslog/omelasticsearch.so

GCRYPT_DESC=		Enable support for encrypted logfiles
GCRYPT_CONFIGURE_ENABLE=libgcrypt
GCRYPT_LIB_DEPENDS=	libgcrypt.so:security/libgcrypt \
			libgpg-error.so:security/libgpg-error
GCRYPT_BUILD_DEPENDS=	libgcrypt-config:security/libgcrypt
GCRYPT_PLIST_FILES=	lib/rsyslog/lmcry_gcry.so

GNUTLS_DESC=		GNUTLS module for rsyslog
GNUTLS_LIB_DEPENDS=	libgnutls.so:security/gnutls
GNUTLS_IMPLIES=		GCRYPT
GNUTLS_CONFIGURE_ENABLE=gnutls
GNUTLS_PLIST_FILES=	lib/rsyslog/lmnsd_gtls.so

GSSAPI_DESC=		GSS API input/output module for rsyslog
GSSAPI_CONFIGURE_ENABLE=gssapi-krb5
GSSAPI_PLIST_FILES=	lib/rsyslog/imgssapi.so \
			lib/rsyslog/lmgssutil.so \
			lib/rsyslog/omgssapi.so

HTTP_DESC=		HTTP output module for rsyslog
HTTP_CONFIGURE_ENABLE=	omhttp
HTTP_PLIST_FILES=	lib/rsyslog/omhttp.so

JSONPARSE_DESC=		JSONPARSE module for rsyslog
JSONPARSE_CONFIGURE_ENABLE=	mmjsonparse
JSONPARSE_PLIST_FILES=	lib/rsyslog/mmjsonparse.so

KAFKA_DESC=		Kafka input/output module for rsyslog
KAFKA_LIB_DEPENDS=	librdkafka.so:net/librdkafka
KAFKA_CONFIGURE_ENABLE=	imkafka omkafka
KAFKA_PLIST_FILES=	lib/rsyslog/imkafka.so \
			lib/rsyslog/omkafka.so

MYSQL_DESC=		MySQL output module for rsyslog
MYSQL_USES=		mysql
MYSQL_CONFIGURE_ENABLE=	mysql
MYSQL_PLIST_FILES=	lib/rsyslog/ommysql.so
MYSQL_PORTDOCS=		plugins/ommysql/createDB.sql

NORMALIZE_DESC=		Message normalization module for rsyslog
NORMALIZE_LIB_DEPENDS=	liblognorm.so:devel/liblognorm
NORMALIZE_CONFIGURE_ENABLE=	mmnormalize
NORMALIZE_PLIST_FILES=	lib/rsyslog/mmnormalize.so

OPENSSL_USES=		ssl
OPENSSL_CONFIGURE_ENABLE=	openssl
OPENSSL_CONFIGURE_ENV=	OPENSSL_LIBS="-L${OPENSSLLIB} -lssl -lcrypto" \
			OPENSSL_CFLAGS="-I ${OPENSSLINC}"
OPENSSL_PLIST_FILES=	lib/rsyslog/lmnsd_ossl.so

PGSQL_DESC=		PostgreSQL output module for rsyslog
PGSQL_USES=		pgsql
PGSQL_CONFIGURE_ENABLE=	pgsql
PGSQL_PLIST_FILES=	lib/rsyslog/ompgsql.so
PGSQL_PORTDOCS=		plugins/ompgsql/createDB.sql

RABBITMQ_DESC=		RabbitMQ output module for rsyslog
RABBITMQ_LIB_DEPENDS=	librabbitmq.so:net/rabbitmq-c
RABBITMQ_CONFIGURE_ENABLE=	omrabbitmq
RABBITMQ_PLIST_FILES=	lib/rsyslog/omrabbitmq.so

RELP_DESC=		RELP input/output module for rsyslog
RELP_LIB_DEPENDS=	librelp.so:devel/librelp
RELP_CONFIGURE_ENABLE=	relp
RELP_PLIST_FILES=	lib/rsyslog/imrelp.so \
			lib/rsyslog/omrelp.so

SNMP_DESC=		SNMP trap sender for rsyslog
SNMP_LIB_DEPENDS=	libnetsnmp.so:net-mgmt/net-snmp
SNMP_CONFIGURE_ENABLE=	snmp
SNMP_PLIST_FILES=	lib/rsyslog/omsnmp.so

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
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share
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

CONFIGURE_ARGS+=	--enable-imdiag --enable-imfile --enable-impstats \
			--enable-mail --enable-omprog --enable-omstdout \
			--enable-omuxsock --enable-rfc3195 --disable-testbench \
			--enable-pmciscoios \
			ac_cv_func_inotify_init=no ac_cv_header_sys_inotify_h=no

post-patch:
	@${GREP} -rl '/etc/rsyslog.conf' ${WRKSRC}|${XARGS} ${REINPLACE_CMD} -e\
		's|/etc/rsyslog.conf|${PREFIX}/etc/rsyslog.conf|'
	@${FIND} ${WRKSRC} -name '*.bak' -delete

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/rsyslog.d
	${INSTALL_DATA} ${FILESDIR}/rsyslog.conf ${STAGEDIR}${PREFIX}/etc/rsyslog.conf.sample

post-install-DOCS-on:
.for SQL in ${PORTDOCS:M*.sql}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/${SQL:H}
	${INSTALL_DATA} ${WRKSRC}/${SQL} ${STAGEDIR}${DOCSDIR}/${SQL}
.endfor

.include <bsd.port.post.mk>
