PORTNAME=	cyrus-imapd
PORTVERSION=	3.0.15
PORTREVISION=	2
CATEGORIES=	mail
MASTER_SITES=	https://github.com/cyrusimap/cyrus-imapd/releases/download/${PORTNAME}-${PORTVERSION}/
PKGNAMESUFFIX=	30

MAINTAINER=	ume@FreeBSD.org
COMMENT=	Cyrus mail server, supporting POP3 and IMAP4 protocols

LICENSE=	BSD4CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

BROKEN_riscv64=		fails to build: lib/imapopts.c: Error 1

LIB_DEPENDS=	libsasl2.so:security/cyrus-sasl2 \
		libicuuc.so:devel/icu \
		libjansson.so:devel/jansson \
		libpcre.so:devel/pcre

CONFLICTS_INSTALL=	cyrus-imapd-2.* cyrus-imapd2*

USES=		compiler:c11 cpe gmake libtool perl5 pkgconfig ssl
USE_RC_SUBR=	imapd
GNU_CONFIGURE=	yes
CYRUS_PREFIX=	${PREFIX}/cyrus
CONFIGURE_ARGS=	--libexecdir=${CYRUS_PREFIX}/libexec \
		--sbindir=${CYRUS_PREFIX}/sbin \
		--sysconfdir=${PREFIX}/etc \
		--with-cyrus-user=${CYRUS_USER} \
		--with-cyrus-group=${CYRUS_GROUP} \
		--with-sasl=${LOCALBASE} \
		--with-com_err \
		--with-openssl=${OPENSSLBASE} \
		--with-perl=${PERL}
CONFIGURE_ENV+=	LIBS="-L${LOCALBASE}/lib"
CPPFLAGS+=	-I${LOCALBASE}/include
MAKE_JOBS_UNSAFE=	yes

CPE_VENDOR=	cmu
CPE_PRODUCT=	cyrus_imap_server

OPTIONS_DEFINE=		AUTOCREATE BACKUP CLAMAV HTTP IDLED LDAP LMDB MURDER \
			MYSQL NNTP PGSQL REPLICATION SNMP SQLITE SQUAT XAPIAN \
			DOCS
OPTIONS_DEFAULT=	AUTOCREATE IDLED SQLITE SQUAT
OPTIONS_SUB=		yes
AUTOCREATE_DESC=	Enable autocreate support
AUTOCREATE_CONFIGURE_ENABLE=	autocreate
BACKUP_DESC=		Enable backup support (experimental)
BACKUP_CONFIGURE_ENABLE=backup
CLAMAV_DESC=		Use ClamAV
CLAMAV_CONFIGURE_WITH=	clamav
CLAMAV_LIB_DEPENDS=	libclamav.so:security/clamav
HTTP_DESC=		Enable HTTP support
HTTP_CONFIGURE_ENABLE=	http
HTTP_LIB_DEPENDS=	libical.so:devel/libical \
			libnghttp2.so:www/libnghttp2 \
			libshp.so:devel/shapelib \
			libbrotlidec.so:archivers/brotli
# Need additional patch to opendkim
#HTTP_LIB_DEPENDS+=	libopendkim.so:mail/opendkim
#HTTP_CPPFLAGS+=	-I${LOCALBASE}/include/opendkim
HTTP_USES=		gnome
HTTP_USE=		GNOME=libxml2
IDLED_DESC=		Enable IMAP idled support
IDLED_CONFIGURE_ENABLE=	idled
LDAP_DESC=		Enable LDAP support (experimental)
LDAP_USE=		OPENLDAP=yes
LDAP_CONFIGURE_ON=	--with-ldap=${LOCALBASE}
LMDB_DESC=		Use LMDB backend
LMDB_LIB_DEPENDS=	liblmdb.so:databases/lmdb
LMDB_CONFIGURE_WITH=	lmdb
MURDER_DESC=		Enable IMAP Murder support
MURDER_CONFIGURE_ENABLE=murder
MURDER_MAKE_ENV=	PTHREAD_LIBS="-lpthread"
MYSQL_USES=		mysql
MYSQL_CONFIGURE_WITH=	mysql
NNTP_DESC=		Enable NNTP support
NNTP_CONFIGURE_ENABLE=	nntp
PGSQL_USES=		pgsql
PGSQL_CONFIGURE_ON=	--with-pgsql=${LOCALBASE}
REPLICATION_DESC=	Enable replication (experimental)
REPLICATION_CONFIGURE_ENABLE=replication
SNMP_LIB_DEPENDS=	libnetsnmp.so:net-mgmt/net-snmp
SNMP_CONFIGURE_ON=	--with-snmp=${LOCALBASE}
SNMP_CONFIGURE_OFF=	--with-snmp=no
SQLITE_CONFIGURE_ON=	--with-sqlite=${LOCALBASE}
SQLITE_BROKEN_OFF=	SQLITE is required
SQUAT_DESC=		Enable Squat support
SQUAT_CONFIGURE_OFF=	--disable-squat
XAPIAN_DESC=		Enable Xapian support
XAPIAN_CONFIGURE_ENABLE=xapian
XAPIAN_LIB_DEPENDS=	libxapian.so:databases/xapian-core
XAPIAN_BUILD_DEPENDS=	rsync:net/rsync
XAPIAN_RUN_DEPENDS=	${XAPIAN_BUILD_DEPENDS}

OPTIONS_RADIO=			GSSAPI READLINE
OPTIONS_RADIO_GSSAPI=		GSSAPI_HEIMDAL GSSAPI_MIT
.if exists(/usr/lib/libkrb5.a)
OPTIONS_RADIO_GSSAPI+=		GSSAPI_BASE
OPTIONS_DEFAULT+=		GSSAPI_BASE
.endif
GSSAPI_BASE_USES=		gssapi
GSSAPI_BASE_CONFIGURE_ON=	--enable-gssapi="${GSSAPIBASEDIR}" \
				--with-gss_impl=heimdal
GSSAPI_HEIMDAL_USES=		gssapi:heimdal,flags
GSSAPI_HEIMDAL_CONFIGURE_ON=	--enable-gssapi="${GSSAPIBASEDIR}" \
				--with-gss_impl=heimdal
GSSAPI_MIT_USES=		gssapi:mit
GSSAPI_MIT_CONFIGURE_ON=	--enable-gssapi="${GSSAPIBASEDIR}" \
				--with-gss_impl=mit

OPTIONS_RADIO_READLINE=		READLINE_GNU READLINE_PERL
READLINE_GNU_DESC=		Use Term::Readline::GNU for cyradm
READLINE_GNU_RUN_DEPENDS=	p5-Term-ReadLine-Gnu>=0:devel/p5-Term-ReadLine-Gnu
READLINE_PERL_DESC=		Use Term::Readline::Perl for cyradm
READLINE_PERL_RUN_DEPENDS=	p5-Term-ReadLine-Perl>=0:devel/p5-Term-ReadLine-Perl

MANDIRS=	${CYRUS_PREFIX}/man

PORTDOCS=	*

SUB_FILES=	pkg-message pkg-install pkg-deinstall cyrus-imapd-man.conf

SUB_LIST=	CYRUS_USER=${CYRUS_USER} CYRUS_GROUP=${CYRUS_GROUP}

CYRUS_USER?=	cyrus
CYRUS_GROUP?=	cyrus

MAN_MAN1=	httptest imtest installsieve lmtptest mupdatetest nntptest \
		pop3test sieveshell sivtest smtptest
MAN_MAN3=	imclient
MAN_MAN5=	cyrus.conf imapd.conf krb.equiv

CYRUS_MAN8=	arbitron backupd chk_cyrus ctl_backups ctl_conversationsdb \
		ctl_cyrusdb ctl_deliver ctl_mboxlist cvt_cyrusdb cyr_backup \
		cyr_buildinfo cyr_dbtool cyr_deny cyr_df cyr_expire cyr_info \
		cyr_synclog cyr_virusscan deliver fud idled imapd ipurge lmtpd \
		master mbexamine mbpath mbtool notifyd pop3d quota reconstruct \
		restore smmapd timsieved tls_prune unexpunge
CYRUS_PERL_MAN1=cyradm
CYRUS_PERL_MAN3=Cyrus::Annotator::Daemon Cyrus::Annotator::Message \
		Cyrus::IMAP Cyrus::IMAP::Admin Cyrus::IMAP::IMSP \
		Cyrus::IMAP::Shell Cyrus::SIEVE::managesieve

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MHTTP} || ${PORT_OPTIONS:MSQLITE}
USES+=	sqlite
.endif

.if !${PORT_OPTIONS:MGSSAPI_BASE} && !${PORT_OPTIONS:MGSSAPI_HEIMDAL} && \
    !${PORT_OPTIONS:MGSSAPI_MIT}
CONFIGURE_ARGS+=--disable-gssapi
.endif

.if ${PORT_OPTIONS:MHTTP}
CYRUS_MAN8+=	ctl_zoneinfo httpd
.endif
.if ${PORT_OPTIONS:MNNTP}
CYRUS_MAN8+=	fetchnews nntpd
.endif
.if ${PORT_OPTIONS:MREPLICATION}
CYRUS_MAN8+=	sync_client sync_reset sync_server
.endif
.if ${PORT_OPTIONS:MSQUAT} || ${PORT_OPTIONS:MXAPIAN}
CYRUS_MAN8+=	squatter
PLIST_SUB+=	SQUATTER=""
.else
PLIST_SUB+=	SQUATTER="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e "s|/etc/|${PREFIX}/etc/|" \
			  -e "s|%%CYRUS_USER%%|${CYRUS_USER}|g" \
			  -e "s|%%CYRUS_GROUP%%|${CYRUS_GROUP}|g" \
		${WRKSRC}/tools/mkimap
	@${REINPLACE_CMD} -e "s|/etc/|${PREFIX}/etc/|g" \
			  -e "s|/usr/sieve|/var/imap/sieve|g" \
		${WRKSRC}/tools/masssievec
	@${REINPLACE_CMD} \
		-e 's|$$(libdir)/\(pkgconfig\)|${PREFIX}/libdata/\1|g' \
		-e 's|$$(mandir)/\(man[8]\)|${PREFIX}/cyrus/man/\1|g' \
		${WRKSRC}/Makefile.in

post-install:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${FILESDIR}/imapd.conf \
		${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/examples/cyrus_conf/normal.conf \
		${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/tools/mkimap \
		${STAGEDIR}${CYRUS_PREFIX}/sbin/mkimap
	${INSTALL_SCRIPT} ${WRKSRC}/tools/masssievec \
		${STAGEDIR}${CYRUS_PREFIX}/sbin/masssievec
	${INSTALL_DATA} ${WRKDIR}/cyrus-imapd-man.conf \
		${STAGEDIR}${PREFIX}/etc/man.d/cyrus-imapd.conf
.for s in 1 3 5
.  for m in ${MAN_MAN${s}}
	@${ECHO_CMD} man/man${s}/${m}.${s}.gz >> ${TMPPLIST}
.  endfor
.endfor
.for s in 1 3
.  for m in ${CYRUS_PERL_MAN${s}}
	@${ECHO_CMD} ${SITE_MAN${s}}/${m}.${s}.gz >> ${TMPPLIST}
.  endfor
.endfor
.for m in ${CYRUS_MAN8}
	@${ECHO_CMD} ${CYRUS_PREFIX}/man/man8/${m}.8.gz >> ${TMPPLIST}
.endfor

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/doc && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR} \
		"! ( -path */html/_sources* -o -name .buildinfo )"
	${RM} -r ${STAGEDIR}${DOCSDIR}/rst ${STAGEDIR}${DOCSDIR}/source

.include <bsd.port.mk>
