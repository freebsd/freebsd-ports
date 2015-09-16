# $FreeBSD$

PORTNAME=	cyrus-imapd
PORTVERSION=	2.3.19
#PORTREVISION=	10
CATEGORIES=	mail ipv6
MASTER_SITES=	ftp://ftp.cyrusimap.org/cyrus-imapd/
PKGNAMESUFFIX=	23

MAINTAINER=	ume@FreeBSD.org
COMMENT=	The cyrus mail server, supporting POP3 and IMAP4 protocols

LICENSE=	BSD4CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

LIB_DEPENDS=	libsasl2.so:${PORTSDIR}/security/cyrus-sasl2 \
		libpcre.so:${PORTSDIR}/devel/pcre

CONFLICTS=	cyrus-1.* cyrus-imapd-2.[^3].* cyrus-imapd2[^3]-2.[^3].*

PERLMAN=	${SITE_PERL_REL:S/site_perl\///}

USE_RC_SUBR=	imapd

USES=		cpe perl5
USE_OPENSSL=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--sysconfdir=${PREFIX}/etc \
		--with-cyrus-prefix=${PREFIX}/cyrus \
		--with-cyrus-user=${CYRUS_USER} \
		--with-cyrus-group=${CYRUS_GROUP} \
		--with-sasl=${LOCALBASE} \
		--with-bdb=${BDB_LIB_NAME} \
		--with-com_err \
		--with-openssl=${OPENSSLBASE} \
		--with-perl=${PERL5}
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib
MAKE_JOBS_UNSAFE=	yes

CPE_VENDOR=	cmu
CPE_PRODUCT=	cyrus_imap_server

OPTIONS_DEFINE=		AUTOCREATE AUTOSIEVE BDB DRAC IDLED \
			LDAP_PTLOADER LISTEXT MURDER MYSQL \
			NETSCAPEHACK NNTP PGSQL REPLICATION SNMP_5 \
			SQLITE DOCS EXAMPLES
OPTIONS_DEFAULT=	BDB
OPTIONS_SUB=		yes
AUTOCREATE_DESC=	Use autocreate INBOX patch (UoA)
AUTOSIEVE_DESC=		Use autosievefolder patch (UoA)
BDB_USE=		BDB=yes
BDB_CONFIGURE_ON=	--with-bdb-incdir=${BDB_INCLUDE_DIR} \
			--with-bdb-libdir=${LOCALBASE}/lib
DRAC_DESC=		Enable DRAC support
DRAC_CONFIGURE_ON=	--with-drac=${LOCALBASE}
DRAC_BUILD_DEPENDS=	${LOCALBASE}/lib/libdrac.a:${PORTSDIR}/mail/drac
IDLED_DESC=		Enable IMAP idled support
IDLED_CONFIGURE_ENABLE=	idled
LDAP_PTLOADER_DESC=	Enable LDAP ptloader
LDAP_PTLOADER_USE=	OPENLDAP=yes
LDAP_PTLOADER_CONFIGURE_ON=--with-ldap=${LOCALBASE}
LISTEXT_DESC=		Enable IMAP List extensions
LISTEXT_CONFIGURE_ENABLE=listext
MURDER_DESC=		Enable IMAP Murder support
MURDER_CONFIGURE_ENABLE=murder
MURDER_CFLAGS=
MURDER_MAKE_ENV=	PTHREAD_LIBS="-lpthread"
MYSQL_USE=		MYSQL=yes
MYSQL_CONFIGURE_ON=	--with-mysql=yes \
			--with-mysql-libdir=${LOCALBASE}/lib/mysql \
			--with-mysql-incdir=${LOCALBASE}/include/mysql
NETSCAPEHACK_DESC=	Enable X-NETSCAPE extensions
NETSCAPEHACK_CONFIGURE_ENABLE=netscapehack
NNTP_DESC=		Enable NNTP support
NNTP_CONFIGURE_ENABLE=	nntp
PGSQL_DESC=		Enable PostgreSQL backend (experimental)
PGSQL_USES=		pgsql
PGSQL_CONFIGURE_ON=	--with-pgsql=${LOCALBASE}
REPLICATION_DESC=	Enable replication
REPLICATION_CONFIGURE_ENABLE=replication
SNMP_5_DESC=		Enable SNMP support
SNMP_5_LIB_DEPENDS=	libnetsnmp.so:${PORTSDIR}/net-mgmt/net-snmp
SNMP_5_CONFIGURE_ON=	--with-snmp=${LOCALBASE}
SNMP_5_CONFIGURE_OFF=	--with-snmp=no
SQLITE_DESC=		Enable SQLite backend (experimental)
SQLITE_USE=		SQLITE=yes
SQLITE_CONFIGURE_ON=	--with-sqlite=${LOCALBASE}

.include <bsd.port.pre.mk>

# Autocreate Inbox and Autosieve patches from UoA
# WWW: http://email.uoa.gr/projects/cyrus/

.if ${PORT_OPTIONS:MAUTOCREATE} || ${PORT_OPTIONS:MAUTOSIEVE}
PATCH_DIST_STRIP=	-p1
PATCH_SITES+=	http://email.uoa.gr/download/cyrus/${PORTNAME}-2.3.16/
.endif

.if ${PORT_OPTIONS:MAUTOCREATE}
AUTOCREATE_VERSION=	0.10-0
PATCHFILES+=	${PORTNAME}-2.3.16-autocreate-${AUTOCREATE_VERSION}.diff
.endif

.if ${PORT_OPTIONS:MAUTOSIEVE}
AUTOSIEVE_VERSION=	0.6.0
PATCHFILES+=	${PORTNAME}-2.3.16-autosieve-${AUTOSIEVE_VERSION}.diff
.endif

.if ${PORT_OPTIONS:MBDB}
INVALID_BDB_VER=2
.else
BDB_LIB_NAME=	no
.endif

.if ${PORT_OPTIONS:MDRAC}
EXTRA_PATCHES+=	${WRKSRC}/contrib/drac_auth.patch
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-configure.in \
		${FILESDIR}/extra-patch-cmulocal::ucdsnmp.m4
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-cmulocal::sasl2.m4
USE_AUTOTOOLS=	autoconf autoheader
.endif

.if ${OSVERSION} >= 900022
PLIST_SUB+=	MANCONF=""
.else
PLIST_SUB+=	MANCONF="@comment "
.endif

.if !exists(/usr/lib/libkrb5.a)
CONFIGURE_ARGS+=--disable-gssapi
.endif

CYRUS_USER?=	cyrus
CYRUS_GROUP?=	cyrus

MAN_MAN1=	cyradm.1 imtest.1 installsieve.1 lmtptest.1 mupdatetest.1 \
		nntptest.1 pop3test.1 sieveshell.1 sivtest.1 smtptest.1
MAN_MAN3=	imclient.3
MAN_MAN5=	cyrus.conf.5 imapd.conf.5 krb.equiv.5
CYRUS_MAN3=	Cyrus::IMAP.3 Cyrus::IMAP::Admin.3 Cyrus::IMAP::IMSP.3 \
		Cyrus::IMAP::Shell.3 Cyrus::SIEVE::managesieve.3
CYRUS_MAN8=	arbitron.8 chk_cyrus.8 ctl_cyrusdb.8 ctl_deliver.8 \
		ctl_mboxlist.8 cvt_cyrusdb.8 cyr_dbtool.8 cyr_df.8 \
		cyr_expire.8 cyr_synclog.8 deliver.8 fetchnews.8 fud.8 \
		idled.8 imapd.8 ipurge.8 lmtpd.8 make_md5.8 make_sha1.8 \
		master.8 mbexamine.8 mbpath.8 nntpd.8 notifyd.8 pop3d.8 \
		quota.8 reconstruct.8 rmnews.8 smmapd.8 squatter.8 \
		sync_client.8 sync_reset.8 sync_server.8 syncnews.8 \
		timsieved.8 tls_prune.8 unexpunge.8

DOCS=		altnamespace anoncvs bugs changes faq feedback index \
		install-admin-mb install-auth install-compile \
		install-configure install-murder install-netnews \
		install-perf install-prereq install-replication \
		install-sieve install-snmpmon install-testing \
		install-upgrade install-virtdomains install mailing-list \
		man notes os overview questions readme sieve-protocol \
		sieve specs

CONFS=		cmu-frontend.conf prefork.conf cmu-backend.conf normal.conf \
		small.conf

PKGDEINSTALL=	${WRKDIR}/pkg-deinstall
PKGINSTALL=	${WRKDIR}/pkg-install

post-patch:
	@${SED} -e "s|%%CYRUS_USER%%|${CYRUS_USER}|g" \
		-e "s|%%PREFIX%%|${PREFIX}|g" \
		-e "s|%%EXAMPLESDIR%%|${EXAMPLESDIR}|g" \
		${.CURDIR}/pkg-install > ${PKGINSTALL}
	@${SED} -e "s|%%CYRUS_USER%%|${CYRUS_USER}|g" \
		-e "s|%%PREFIX%%|${PREFIX}|g" \
		-e "s|%%EXAMPLESDIR%%|${EXAMPLESDIR}|g" \
		${.CURDIR}/pkg-deinstall > ${PKGDEINSTALL}
	@${REINPLACE_CMD} -e "s|/etc/|${PREFIX}/etc/|" \
			  -e "s|%%CYRUS_USER%%|${CYRUS_USER}|g" \
			  -e "s|%%CYRUS_GROUP%%|${CYRUS_GROUP}|g" \
		${WRKSRC}/tools/mkimap
	@${REINPLACE_CMD} -e "s|/etc/|${PREFIX}/etc/|g" \
			  -e "s|/usr/sieve|/var/imap/sieve|g" \
		${WRKSRC}/tools/masssievec
	@${SED} -e "s|%%PREFIX%%|${PREFIX}|g;" \
		${FILESDIR}/cyrus-imapd-man.conf \
		> ${WRKDIR}/cyrus-imapd-man.conf
.if ${PORT_OPTIONS:MDRAC}
	@${RM} -rf ${WRKSRC}/autom4te.cache
.endif

post-install:
.for f in ${CYRUS_MAN3}
	@${GZIP_CMD} ${STAGEDIR}${PREFIX}/${PERLMAN}/man/man3/${f}
	@${ECHO_CMD} ${PERLMAN}/man/man3/${f}.gz >>${TMPPLIST}
.endfor
.for f in ${CYRUS_MAN8}
	@${GZIP_CMD} ${STAGEDIR}${PREFIX}/cyrus/man/man8/${f}
	@${ECHO_CMD} cyrus/man/man8/${f}.gz >>${TMPPLIST}
.endfor
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/man
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/text
.for f in ${DOCS}
	@${INSTALL_DATA} ${WRKSRC}/doc/${f}.html ${STAGEDIR}${DOCSDIR}
	@${ECHO_CMD} share/doc/${PORTNAME}/${f}.html >>${TMPPLIST}
.endfor
.for f in ${MAN_MAN1} ${MAN_MAN3} ${MAN_MAN5} ${CYRUS_MAN8}
	@if [ -f ${WRKSRC}/doc/man/${f}.html ]; then \
		${INSTALL_DATA} ${WRKSRC}/doc/man/${f}.html \
			${STAGEDIR}${DOCSDIR}/man/${f}.html; \
		${ECHO_CMD} share/doc/${PORTNAME}/man/${f}.html \
			>>${TMPPLIST}; \
	fi
.endfor
.for f in cyrusv2.mc murder.fig murder.png netnews.fig netnews.png
	@${INSTALL_DATA} ${WRKSRC}/doc/${f} ${STAGEDIR}${DOCSDIR}
	@${ECHO_CMD} share/doc/${PORTNAME}/${f} >>${TMPPLIST}
.endfor
.for f in ${DOCS}
	@${INSTALL_DATA} ${WRKSRC}/doc/text/${f} \
		${STAGEDIR}${DOCSDIR}/text
	@${ECHO_CMD} share/doc/${PORTNAME}/text/${f} >>${TMPPLIST}
.endfor
.endif
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	@${INSTALL_DATA} ${FILESDIR}/imapd.conf \
		${STAGEDIR}${EXAMPLESDIR}
.for f in ${CONFS}
	@${INSTALL_DATA} ${WRKSRC}/master/conf/${f} \
		${STAGEDIR}${EXAMPLESDIR}
	@${ECHO_CMD} ${EXAMPLESDIR:S,^${PREFIX}/,,}/${f} >>${TMPPLIST}
.endfor
	@${INSTALL_SCRIPT} ${WRKSRC}/tools/mkimap \
		${STAGEDIR}${PREFIX}/cyrus/bin/mkimap
	@${INSTALL_SCRIPT} ${WRKSRC}/tools/masssievec \
		${STAGEDIR}${PREFIX}/cyrus/bin/masssievec
.if ${OSVERSION} >= 900022
	@${INSTALL_DATA} ${WRKDIR}/cyrus-imapd-man.conf \
		${STAGEDIR}${PREFIX}/etc/man.d/cyrus-imapd.conf
.endif

.include <bsd.port.post.mk>
