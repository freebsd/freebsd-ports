# $FreeBSD$

PORTNAME=	cyrus-imapd
PORTVERSION=	2.5.11
#PORTREVISION=	0
CATEGORIES=	mail ipv6
MASTER_SITES=	ftp://ftp.cyrusimap.org/cyrus-imapd/ \
		http://cyrusimap.org/releases/
PKGNAMESUFFIX=	25

MAINTAINER=	ume@FreeBSD.org
COMMENT=	The cyrus mail server, supporting POP3 and IMAP4 protocols

LICENSE=	BSD4CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libsasl2.so:security/cyrus-sasl2 \
		libpcre.so:devel/pcre

BROKEN_armv6=		fails to build: ./tools/config2header: Error code 1
BROKEN_armv7=		fails to build: ./tools/config2header: Error code 1

CONFLICTS_INSTALL=	cyrus-imapd-2.[^5].* cyrus-imapd2[^5]-2.[^5].* \
			cyrus-imapd3*

USE_RC_SUBR=	imapd

USES=		cpe libtool perl5 ssl
GNU_CONFIGURE=	yes
CYRUS_PREFIX=	${PREFIX}/cyrus
CONFIGURE_ARGS=	--sysconfdir=${PREFIX}/etc \
		--with-cyrus-prefix=${CYRUS_PREFIX} \
		--with-cyrus-user=${CYRUS_USER} \
		--with-cyrus-group=${CYRUS_GROUP} \
		--with-sasl=${LOCALBASE} \
		--with-bdb=${BDB_LIB_NAME} \
		--with-com_err \
		--with-openssl=${OPENSSLBASE} \
		--with-perl=${PERL}
CONFIGURE_ENV+=	LIBS="-L${LOCALBASE}/lib"
CPPFLAGS+=	-I${LOCALBASE}/include
MAKE_JOBS_UNSAFE=	yes

CPE_VENDOR=	cmu
CPE_PRODUCT=	cyrus_imap_server

OPTIONS_DEFINE=		AUTOCREATE BDB HTTP IDLED LDAP MURDER MYSQL \
			NETSCAPEHACK NNTP PGSQL REPLICATION SNMP SQLITE DOCS \
			EXAMPLES
#OPTIONS_DEFINE+=	CLAMAV DRAC
OPTIONS_DEFAULT=	BDB IDLED
OPTIONS_SUB=		yes
AUTOCREATE_DESC=	Enable autocreate support
AUTOCREATE_CONFIGURE_ENABLE=	autocreate
BDB_USES=		bdb
BDB_CONFIGURE_ON=	--with-bdb-incdir=${BDB_INCLUDE_DIR} \
			--with-bdb-libdir=${LOCALBASE}/lib
CLAMAV_DESC=		Use ClamAV
CLAMAV_CONFIGURE_WITH=	clamav
CLAMAV_LIB_DEPENDS=	libclamav.so:security/clamav
DRAC_DESC=		Enable DRAC support
DRAC_CONFIGURE_ON=	--with-drac=${LOCALBASE}
DRAC_BUILD_DEPENDS=	${LOCALBASE}/lib/libdrac.a:mail/drac
HTTP_DESC=		Enable HTTP (beta quality)
HTTP_CONFIGURE_ENABLE=	http
HTTP_LIB_DEPENDS=	libjansson.so:devel/jansson \
			libical.so:devel/libical
HTTP_USES=		pkgconfig
HTTP_USE=		GNOME=libxml2
IDLED_DESC=		Enable IMAP idled support
IDLED_CONFIGURE_ENABLE=	idled
LDAP_DESC=		Enable LDAP support (experimental)
LDAP_USE=		OPENLDAP=yes
LDAP_CONFIGURE_ON=	--with-ldap=${LOCALBASE}
MURDER_DESC=		Enable IMAP Murder support
MURDER_CONFIGURE_ENABLE=murder
MURDER_MAKE_ENV=	PTHREAD_LIBS="-lpthread"
MYSQL_USES=		mysql
MYSQL_CONFIGURE_ON=	--with-mysql=yes \
			--with-mysql-libdir=${LOCALBASE}/lib/mysql \
			--with-mysql-incdir=${LOCALBASE}/include/mysql
NETSCAPEHACK_DESC=	Enable X-NETSCAPE extensions
NETSCAPEHACK_CONFIGURE_ENABLE=netscapehack
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

UNAMER!=	uname -r
OSMAJOR=	${UNAMER:C/[.-].*//}

OPTIONS_RADIO=			GSSAPI
OPTIONS_RADIO_GSSAPI=		GSSAPI_HEIMDAL GSSAPI_MIT
.if exists(/usr/lib/libkrb5.a)
OPTIONS_RADIO_GSSAPI+=		GSSAPI_BASE
.if ${OSMAJOR} >= 9
OPTIONS_DEFAULT+=		GSSAPI_BASE
.endif
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

MANDIRS=	${CYRUS_PREFIX}/man

PORTDOCS=	*

SUB_FILES=	pkg-message pkg-install pkg-deinstall cyrus-imapd-man.conf

SUB_LIST=	CYRUS_USER=${CYRUS_USER} CYRUS_GROUP=${CYRUS_GROUP}

CYRUS_USER?=	cyrus
CYRUS_GROUP?=	cyrus

MAN_MAN1=	imtest installsieve lmtptest mupdatetest nntptest pop3test \
		sieveshell sivtest smtptest
MAN_MAN3=	imclient
MAN_MAN5=	cyrus.conf imapd.conf krb.equiv

CYRUS_MAN8=	arbitron chk_cyrus ctl_cyrusdb ctl_deliver ctl_mboxlist \
		cvt_cyrusdb cyr_dbtool cyr_deny cyr_df cyr_expire cyr_info \
		cyr_synclog deliver fud idled imapd ipurge lmtpd master \
		mbexamine mbpath notifyd pop3d quota reconstruct rmnews \
		smmapd squatter sync_client sync_reset sync_server timsieved \
		tls_prune unexpunge

CYRUS_PERL_MAN1=cyradm
CYRUS_PERL_MAN3=Cyrus::Annotator::Daemon Cyrus::Annotator::Message \
		Cyrus::IMAP Cyrus::IMAP::Admin Cyrus::IMAP::IMSP \
		Cyrus::IMAP::Shell Cyrus::SIEVE::managesieve

CONFS=		cmu-backend.conf cmu-frontend.conf normal.conf prefork.conf \
		small.conf

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MBDB}
INVALID_BDB_VER=2
.else
BDB_LIB_NAME=	no
.endif

.if ${PORT_OPTIONS:MCLAMAV}
IGNORE=		CLAMAV is not available yet
.endif
PLIST_SUB+=	CLAMAV="@comment "

.if ${PORT_OPTIONS:MDRAC}
IGNORE=		DRAC is not available
# EXTRA_PATCHES+=	${FILESDIR}/extra-patch-cmulocal__sasl2.m4
.endif

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

.if ${PORT_OPTIONS:MDRAC}
pre-patch:
	${PATCH} -d ${PATCH_WRKSRC} --forward --quiet -E -p1 \
		< ${WRKSRC}/contrib/drac_auth.patch
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

post-patch-DRAC-on:
	@${RM} -r ${WRKSRC}/autom4te.cache

post-install:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${FILESDIR}/imapd.conf \
		${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/master/conf/normal.conf \
		${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/tools/mkimap \
		${STAGEDIR}${CYRUS_PREFIX}/bin/mkimap
	${INSTALL_SCRIPT} ${WRKSRC}/tools/masssievec \
		${STAGEDIR}${CYRUS_PREFIX}/bin/masssievec
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
	cd ${WRKSRC}/doc && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}

# there are already files in EXAMPLESDIR at that point, so no
# need to create it.
post-install-EXAMPLES-on:
.for f in ${CONFS:Nnormal.conf}
	@${INSTALL_DATA} ${WRKSRC}/master/conf/${f} \
		${STAGEDIR}${EXAMPLESDIR}
	@${ECHO_CMD} ${EXAMPLESDIR:S,^${PREFIX}/,,}/${f} >>${TMPPLIST}
.endfor

.include <bsd.port.mk>
