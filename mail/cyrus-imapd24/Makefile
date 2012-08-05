# New ports collection makefile for:		cyrus-imapd
# Date created:					Dec 10th 2005
# Whom:						ume@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	cyrus-imapd
PORTVERSION=	2.4.16
#PORTREVISION=	0
CATEGORIES=	mail ipv6
MASTER_SITES=	ftp://ftp.cyrusimap.org/cyrus-imapd/ \
		http://cyrusimap.org/releases/

MAINTAINER=	ume@FreeBSD.org
COMMENT=	The cyrus mail server, supporting POP3 and IMAP4 protocols

LICENSE=	BSD
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

LIB_DEPENDS=	sasl2.2:${PORTSDIR}/security/cyrus-sasl2 \
		pcre.1:${PORTSDIR}/devel/pcre

CONFLICTS=	cyrus-1.* cyrus-imapd-2.[^4].*

LATEST_LINK=	${PORTNAME}24

USE_RC_SUBR=	imapd
USE_OPENSSL=	yes
USE_PERL5=	yes
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

OPTIONS_DEFINE=		AUTOCREATE AUTOSIEVE BDB DRAC IDLED LDAP MURDER MYSQL \
			NETSCAPEHACK NNTP PGSQL REPLICATION SNMP SQLITE
OPTIONS_DEFAULT=	BDB
AUTOCREATE_DESC=	Use autocreate INBOX patch (UoA)
AUTOSIEVE_DESC=		Use autosievefolder patch (UoA)
DRAC_DESC=		Enable DRAC support
IDLED_DESC=		Enable IMAP idled support
LDAP_DESC=		Enable LDAP support (experimental)
MURDER_DESC=		Enable IMAP Murder support
NETSCAPEHACK_DESC=	Enable X-NETSCAPE extensions
NNTP_DESC=		Enable NNTP support
REPLICATION_DESC=	Enable replication (experimental)

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
USE_BDB=	yes
INVALID_BDB_VER=2
CONFIGURE_ARGS+=--with-bdb-incdir=${BDB_INCLUDE_DIR} \
		--with-bdb-libdir=${LOCALBASE}/lib
.else
BDB_LIB_NAME=	no
.endif

.if ${PORT_OPTIONS:MNNTP}
CONFIGURE_ARGS+=--enable-nntp
PLIST_SUB+=	NNTP=""
.else
PLIST_SUB+=	NNTP="@comment "
.endif

.if ${PORT_OPTIONS:MMURDER}
CONFIGURE_ARGS+=--enable-murder
CFLAGS+=	${PTHREAD_CFLAGS}
MAKE_ENV+=	PTHREAD_LIBS=${PTHREAD_LIBS}
PLIST_SUB+=	MURDER=""
.else
PLIST_SUB+=	MURDER="@comment "
.endif

.if ${PORT_OPTIONS:MIDLED}
CONFIGURE_ARGS+=--enable-idled
PLIST_SUB+=	IDLED=""
.else
PLIST_SUB+=	IDLED="@comment "
.endif

.if ${PORT_OPTIONS:MMYSQL}
USE_MYSQL=	yes
CONFIGURE_ARGS+=--with-mysql=yes \
		--with-mysql-libdir=${LOCALBASE}/lib/mysql \
		--with-mysql-incdir=${LOCALBASE}/include/mysql
.endif

.if ${PORT_OPTIONS:MPGSQL}
USE_PGSQL=	yes
CONFIGURE_ARGS+=--with-pgsql=${LOCALBASE}
.endif

.if ${PORT_OPTIONS:MSQLITE}
USE_SQLITE=	yes
CONFIGURE_ARGS+=--with-sqlite=${LOCALBASE}
.endif

.if ${PORT_OPTIONS:MREPLICATION}
CONFIGURE_ARGS+=--enable-replication
PLIST_SUB+=	REPLICATION=""
.else
PLIST_SUB+=	REPLICATION="@comment "
.endif

.if ${PORT_OPTIONS:MNETSCAPEHACK}
CONFIGURE_ARGS+=--enable-netscapehack
.endif

.if ${PORT_OPTIONS:MDRAC}
.if ${OSVERSION} >= 800037
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-cmulocal::sasl2.m4
.endif
USE_AUTOTOOLS=	autoconf autoheader
CONFIGURE_ARGS+=--with-drac=${LOCALBASE}
BUILD_DEPENDS+=	${LOCALBASE}/lib/libdrac.a:${PORTSDIR}/mail/drac
.endif

.if ${PORT_OPTIONS:MSNMP}
LIB_DEPENDS+=	netsnmp.30:${PORTSDIR}/net-mgmt/net-snmp
CONFIGURE_ARGS+=--with-snmp=${LOCALBASE}
.else
CONFIGURE_ARGS+=--with-snmp=no
.endif

.if ${PORT_OPTIONS:MLDAP}
USE_OPENLDAP=	yes
CONFIGURE_ARGS+=--with-ldap=${LOCALBASE}
PLIST_SUB+=	LDAP=""
.else
PLIST_SUB+=	LDAP="@comment "
.endif

.if !exists(/usr/lib/libkrb5.a)
CONFIGURE_ARGS+=--disable-gssapi
.endif

.if ${OSVERSION} >= 800037
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-configure
.endif

CYRUS_USER?=	cyrus
CYRUS_GROUP?=	cyrus

MAN1=		cyradm.1 imtest.1 installsieve.1 lmtptest.1 mupdatetest.1 \
		nntptest.1 pop3test.1 sieveshell.1 sivtest.1 smtptest.1
MAN3=		imclient.3
MAN5=		cyrus.conf.5 imapd.conf.5 krb.equiv.5
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
.if ${PORT_OPTIONS:MDRAC}
		@${RM} -rf ${WRKSRC}/autom4te.cache
.endif

post-install:
.for f in ${CYRUS_MAN3}
		@${GZIP_CMD} ${PREFIX}/lib/perl5/${PERL_VERSION}/man/man3/${f}
		@${ECHO_CMD} lib/perl5/${PERL_VERSION}/man/man3/${f}.gz \
			>>${TMPPLIST}
.endfor
.for f in ${CYRUS_MAN8}
		@${GZIP_CMD} ${PREFIX}/cyrus/man/man8/${f}
		@${ECHO_CMD} cyrus/man/man8/${f}.gz >>${TMPPLIST}
.endfor
		@${ECHO_CMD} "@dirrm cyrus/man/man8" >>${TMPPLIST}
		@${ECHO_CMD} "@dirrm cyrus/man" >>${TMPPLIST}
		@${ECHO_CMD} "@dirrm cyrus" >>${TMPPLIST}
.if ${PORT_OPTIONS:MDOCS}
		@${MKDIR} ${DOCSDIR}/man
		@${MKDIR} ${DOCSDIR}/text
.for f in ${DOCS}
		@${INSTALL_DATA} ${WRKSRC}/doc/${f}.html ${DOCSDIR}
		@${ECHO_CMD} share/doc/${PORTNAME}/${f}.html >>${TMPPLIST}
.endfor
.for f in ${MAN1} ${MAN3} ${MAN5} ${CYRUS_MAN8}
		@if [ -f ${WRKSRC}/doc/man/${f}.html ]; then \
		${INSTALL_DATA} ${WRKSRC}/doc/man/${f}.html \
			${DOCSDIR}/man/${f}.html; \
		${ECHO_CMD} share/doc/${PORTNAME}/man/${f}.html \
			>>${TMPPLIST}; \
		fi
.endfor
.for f in cyrusv2.mc murder.fig murder.png netnews.fig netnews.png
		@${INSTALL_DATA} ${WRKSRC}/doc/${f} ${DOCSDIR}
		@${ECHO_CMD} share/doc/${PORTNAME}/${f} >>${TMPPLIST}
.endfor
.for f in ${DOCS}
		@${INSTALL_DATA} ${WRKSRC}/doc/text/${f} ${DOCSDIR}/text
		@${ECHO_CMD} share/doc/${PORTNAME}/text/${f} >>${TMPPLIST}
.endfor
		@${ECHO_CMD} "@dirrm share/doc/${PORTNAME}/text" >>${TMPPLIST}
		@${ECHO_CMD} "@dirrm share/doc/${PORTNAME}/man" >>${TMPPLIST}
		@${ECHO_CMD} "@dirrm share/doc/${PORTNAME}" >>${TMPPLIST}
.endif
		@${MKDIR} ${EXAMPLESDIR}
		@${INSTALL_DATA} ${FILESDIR}/imapd.conf ${EXAMPLESDIR}
.for f in ${CONFS}
		@${INSTALL_DATA} ${WRKSRC}/master/conf/${f} ${EXAMPLESDIR}
		@${ECHO_CMD} ${EXAMPLESDIR:S,^${PREFIX}/,,}/${f} >>${TMPPLIST}
.endfor
		@${ECHO_CMD} @dirrm ${EXAMPLESDIR:S,^${PREFIX}/,,} \
			>>${TMPPLIST}
		@${INSTALL_SCRIPT} ${WRKSRC}/tools/mkimap \
			${PREFIX}/cyrus/bin/mkimap
		@${INSTALL_SCRIPT} ${WRKSRC}/tools/masssievec \
			${PREFIX}/cyrus/bin/masssievec
		@PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} \
			POST-INSTALL
		@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
