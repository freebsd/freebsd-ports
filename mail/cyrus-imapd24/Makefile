# $FreeBSD$

PORTNAME=	cyrus-imapd
PORTVERSION=	2.4.17
PORTREVISION=	4
CATEGORIES=	mail ipv6
MASTER_SITES=	ftp://ftp.cyrusimap.org/cyrus-imapd/ \
		http://cyrusimap.org/releases/
PKGNAMESUFFIX=	24

MAINTAINER=	ume@FreeBSD.org
COMMENT=	The cyrus mail server, supporting POP3 and IMAP4 protocols

LICENSE=	BSD
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

LIB_DEPENDS=	libsasl2.so:${PORTSDIR}/security/cyrus-sasl2 \
		libpcre.so:${PORTSDIR}/devel/pcre

CONFLICTS=	cyrus-1.* cyrus-imapd-2.[^4].* cyrus-imapd2[^4]-2.[^4].*

PERLMAN=	${SITE_PERL_REL:S/site_perl\///}

USE_RC_SUBR=	imapd

USES=		perl5
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
CONFIGURE_ENV+=	LIBS="-L${LOCALBASE}/lib"
CPPFLAGS+=	-I${LOCALBASE}/include
MAKE_JOBS_UNSAFE=	yes

OPTIONS_DEFINE=		AUTOCREATE AUTOSIEVE BDB DRAC IDLED LDAP \
			MURDER MYSQL NETSCAPEHACK NNTP PGSQL \
			REPLICATION SNMP SQLITE
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
LDAP_DESC=		Enable LDAP support (experimental)
LDAP_USE=		OPENLDAP=yes
LDAP_CONFIGURE_ON=	--with-ldap=${LOCALBASE}
MURDER_DESC=		Enable IMAP Murder support
MURDER_CONFIGURE_ENABLE=murder
MURDER_CFLAGS=		${PTHREAD_CFLAGS}
MURDER_MAKE_ENV=	PTHREAD_LIBS=${PTHREAD_LIBS}
MYSQL_USE=		MYSQL=yes
MYSQL_CONFIGURE_ON=	--with-mysql=yes \
			--with-mysql-libdir=${LOCALBASE}/lib/mysql \
			--with-mysql-incdir=${LOCALBASE}/include/mysql
NETSCAPEHACK_DESC=	Enable X-NETSCAPE extensions
NETSCAPEHACK_CONFIGURE_ENABLE=netscapehack
NNTP_DESC=		Enable NNTP support
NNTP_CONFIGURE_ENABLE=	nntp
PGSQL_USE=		PGSQL=yes
PGSQL_CONFIGURE_ON=	--with-pgsql=${LOCALBASE}
REPLICATION_DESC=	Enable replication (experimental)
REPLICATION_CONFIGURE_ENABLE=replication
SNMP_LIB_DEPENDS=	libnetsnmp.so:${PORTSDIR}/net-mgmt/net-snmp
SNMP_CONFIGURE_ON=	--with-snmp=${LOCALBASE}
SNMP_CONFIGURE_OFF=	--with-snmp=no
SQLITE_USE=		SQLITE=yes
SQLITE_CONFIGURE_ON=	--with-sqlite=${LOCALBASE}

.include <bsd.port.pre.mk>

# Autocreate Inbox and Autosieve patches from UoA
# http://email.uoa.gr/projects/cyrus/
# http://blog.vx.sk/archives/13-Cyrus-IMAP-UoA.html

.if ${PORT_OPTIONS:MAUTOCREATE} || ${PORT_OPTIONS:MAUTOSIEVE}
PATCH_DIST_STRIP=	-p1
PATCH_SITES+=		${MASTER_SITE_LOCAL}
PATCH_SITE_SUBDIR=	mm
.endif

.if ${PORT_OPTIONS:MAUTOCREATE}
AUTOCREATE_VERSION=	0.10-0
PATCHFILES+=	${PORTNAME}-2.4.4-autocreate-${AUTOCREATE_VERSION}.patch
PLIST_FILES+=	cyrus/bin/compile_sieve
.endif

.if ${PORT_OPTIONS:MAUTOSIEVE}
AUTOSIEVE_VERSION=	0.6.0
PATCHFILES+=	${PORTNAME}-2.4.12-autosieve-${AUTOSIEVE_VERSION}.patch
.endif

.if ${PORT_OPTIONS:MBDB}
INVALID_BDB_VER=2
.else
BDB_LIB_NAME=	no
.endif

.if ${PORT_OPTIONS:MDRAC}
.if ${OSVERSION} >= 800037
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-cmulocal::sasl2.m4
.endif
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

.if ${OSVERSION} >= 800037
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-configure
.endif

CYRUS_USER?=	cyrus
CYRUS_GROUP?=	cyrus

CYRUS_MAN3=	Cyrus::IMAP.3 Cyrus::IMAP::Admin.3 Cyrus::IMAP::IMSP.3 \
		Cyrus::IMAP::Shell.3 Cyrus::SIEVE::managesieve.3
CYRUS_MAN8=	arbitron.8 chk_cyrus.8 nntpd.8 ctl_cyrusdb.8 ctl_deliver.8 \
		cyr_dbtool.8 cyr_df.8 cyr_expire.8 cyr_synclog.8 \
		ctl_mboxlist.8 cvt_cyrusdb.8 deliver.8 fetchnews.8 fud.8 \
		idled.8 imapd.8 ipurge.8 lmtpd.8 master.8 mbexamine.8 \
		mbpath.8 notifyd.8 pop3d.8 quota.8 reconstruct.8 rmnews.8 \
		smmapd.8 squatter.8 sync_client.8 sync_reset.8 sync_server.8 \
		syncnews.8 timsieved.8 tls_prune.8 unexpunge.8

DOCS=		ag altnamespace anoncvs bugs changes faq feedback index \
		install install-admin-mb install-auth install-compile \
		install-configure install-murder install-netnews \
		install-perf install-prereq install-replication \
		install-sieve install-snmpmon install-testing \
		install-upgrade install-virtdomains mailing-list man \
		notes os overview questions readme sieve sieve-protocol \
		specs

CONFS=		cmu-frontend.conf prefork.conf cmu-backend.conf normal.conf \
		small.conf

PKGDEINSTALL=	${WRKDIR}/pkg-deinstall
PKGINSTALL=	${WRKDIR}/pkg-install

.if ${PORT_OPTIONS:MDRAC}
pre-patch:
	${PATCH} -d ${PATCH_WRKSRC} --forward --quiet -E -p1 \
		< ${WRKSRC}/contrib/drac_auth.patch
.endif

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
	@${REINPLACE_CMD} -e "s|-lpthread|\$$(PTHREAD_LIBS)|g" \
		${WRKSRC}/imap/Makefile.in
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
	@${ECHO_CMD} "@dirrm cyrus/man/man8" >>${TMPPLIST}
	@${ECHO_CMD} "@dirrm cyrus/man" >>${TMPPLIST}
	@${ECHO_CMD} "@dirrm cyrus" >>${TMPPLIST}
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/man
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/text
.for f in ${DOCS}
	@${INSTALL_DATA} ${WRKSRC}/doc/${f}.html ${STAGEDIR}${DOCSDIR}
	@${ECHO_CMD} share/doc/${PORTNAME}/${f}.html >>${TMPPLIST}
.endfor
.for f in ${MAN1} ${MAN3} ${MAN5} ${CYRUS_MAN8}
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
	@${ECHO_CMD} "@dirrm share/doc/${PORTNAME}/text" >>${TMPPLIST}
	@${ECHO_CMD} "@dirrm share/doc/${PORTNAME}/man" >>${TMPPLIST}
	@${ECHO_CMD} "@dirrm share/doc/${PORTNAME}" >>${TMPPLIST}
.endif
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	@${INSTALL_DATA} ${FILESDIR}/imapd.conf \
		${STAGEDIR}${EXAMPLESDIR}
.for f in ${CONFS}
	@${INSTALL_DATA} ${WRKSRC}/master/conf/${f} \
		${STAGEDIR}${EXAMPLESDIR}
	@${ECHO_CMD} ${EXAMPLESDIR:S,^${PREFIX}/,,}/${f} >>${TMPPLIST}
.endfor
	@${ECHO_CMD} @dirrm ${EXAMPLESDIR:S,^${PREFIX}/,,} \
		>>${TMPPLIST}
	@${INSTALL_SCRIPT} ${WRKSRC}/tools/mkimap \
		${STAGEDIR}${PREFIX}/cyrus/bin/mkimap
	@${INSTALL_SCRIPT} ${WRKSRC}/tools/masssievec \
		${STAGEDIR}${PREFIX}/cyrus/bin/masssievec
.if ${OSVERSION} >= 900022
	@${INSTALL_DATA} ${WRKDIR}/cyrus-imapd-man.conf \
		${STAGEDIR}${PREFIX}/etc/man.d/cyrus-imapd.conf
.endif

.include <bsd.port.post.mk>
