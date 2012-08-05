# New ports collection makefile for:		cyrus-imapd
# Date created:					Jan 4th 2001
# Whom:						ume@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	cyrus-imapd
PORTVERSION=	2.2.13p1
PORTREVISION=	3
CATEGORIES=	mail ipv6
MASTER_SITES=	ftp://ftp.andrew.cmu.edu/pub/cyrus-mail/ \
		http://www.transit.hanse.de/mirror/ftp.andrew.cmu.edu/pub/cyrus-mail/ \
		${MASTER_SITE_RINGSERVER:S,%SUBDIR%,net/mail/cyrus-mail/&,}

MAINTAINER=	ume@FreeBSD.org
COMMENT=	The cyrus mail server, supporting POP3 and IMAP4 protocols

LIB_DEPENDS=	sasl2.2:${PORTSDIR}/security/cyrus-sasl2

CONFLICTS=	cyrus-1.* cyrus-imapd-2.[^2].*

LATEST_LINK=	${PORTNAME}22

USE_RC_SUBR=	imapd
USE_OPENSSL=	yes
USE_PERL5=	yes
USE_BDB=	yes
INVALID_BDB_VER=2 45+
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--sysconfdir=${PREFIX}/etc \
		--with-cyrus-prefix=${PREFIX}/cyrus \
		--with-cyrus-user=${CYRUS_USER} \
		--with-cyrus-group=${CYRUS_GROUP} \
		--with-sasl=${LOCALBASE} \
		--with-bdb-incdir=${BDB_INCLUDE_DIR} \
		--with-bdb-libdir=${LOCALBASE}/lib \
		--with-bdb=${BDB_LIB_NAME} \
		--with-com_err \
		--with-openssl=${OPENSSLBASE} \
		--with-perl=${PERL5}

OPTIONS_DEFINE=		DRAC IDLE_IDLED IDLE_POLL LDAP_PTLOADER LISTEXT \
			MURDER NETSCAPEHACK NNTP SNMP_5 PASS8BITHACK
OPTIONS_DEFAULT=	IDLE_POLL
DRAC_DESC=		Enable DRAC support
IDLE_IDLED_DESC=	Enable IMAP IDLE method idled
IDLE_POLL_DESC=		Enable IMAP IDLE method idle-polling
LDAP_PTLOADER_DESC=	Enable LDAP ptloader (experimantal)
LISTEXT_DESC=		Enable IMAP List extensions
MURDER_DESC=		Enable IMAP Murder support
NETSCAPEHACK_DESC=	Enable X-NETSCAPE extensions
NNTP_DESC=		Enable NNTP support
SNMP_5_DESC=		Enable SNMP support
PASS8BITHACK_DESC=	Add pass8bit option (not recommended)

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} >= 501400
IGNORE=		does not build with Perl 5.14+, use mail/cyrus-imapd23 instead 
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

.if ${PORT_OPTIONS:MIDLE_IDLED} && ${PORT_OPTIONS:MIDLE_POLL}
BROKEN=		Multiple IDLE methods selected.  Run 'make config' again!
.endif
.if ${PORT_OPTIONS:MIDLE_IDLED}
CONFIGURE_ARGS+=--with-idle=idled
PLIST_SUB+=	IDLED=""
.elif ${PORT_OPTIONS:MIDLE_POLL}
CONFIGURE_ARGS+=--with-idle=poll
PLIST_SUB+=	IDLED="@comment "
.elif !${PORT_OPTIONS:MIDLE_IDLED} && !${PORT_OPTIONS:MIDLE_POLL}
CONFIGURE_ARGS+=--with-idle=no
PLIST_SUB+=	IDLED="@comment "
.else
PLIST_SUB+=	IDLED="@comment "
.endif

.if ${PORT_OPTIONS:MLISTEXT}
CONFIGURE_ARGS+=--enable-listext
.endif

.if ${PORT_OPTIONS:MNETSCAPEHACK}
CONFIGURE_ARGS+=--enable-netscapehack
.endif

.if ${PORT_OPTIONS:MDRAC}
#EXTRA_PATCHES+=	${WRKSRC}/contrib/drac_auth.patch
EXTRA_PATCHES+=	${FILESDIR}/drac_auth.patch
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-cmulocal::berkdb.m4 \
		${FILESDIR}/extra-patch-cmulocal::ucdsnmp.m4 \
		${FILESDIR}/extra-patch-configure.in
USE_AUTOTOOLS=	autoconf autoheader
CONFIGURE_ARGS+=--with-drac=${LOCALBASE}
BUILD_DEPENDS+=	${LOCALBASE}/lib/libdrac.a:${PORTSDIR}/mail/drac
.endif

.if ${PORT_OPTIONS:MSNMP_5}
LIB_DEPENDS+=	netsnmp.30:${PORTSDIR}/net-mgmt/net-snmp
CONFIGURE_ARGS+=--with-snmp=${LOCALBASE}
.else
CONFIGURE_ARGS+=--with-snmp=no
.endif

.if ${PORT_OPTIONS:MLDAP_PTLOADER}
USE_OPENLDAP=	yes
CONFIGURE_ARGS+=--with-ldap=${LOCALBASE}
PLIST_SUB+=	LDAP_PTLOADER=""
.else
PLIST_SUB+=	LDAP_PTLOADER="@comment "
.endif

.if ${PORT_OPTIONS:MPASS8BITHACK}
EXTRA_PATCHES+=	${FILESDIR}/pass8bit.diff
.endif

.if !exists(/usr/lib/libkrb5.a) || ${OSVERSION} >= 800037
CONFIGURE_ARGS+=--disable-gssapi
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
		cyr_expire.8 ctl_mboxlist.8 cvt_cyrusdb.8 deliver.8 \
		fetchnews.8 fud.8 idled.8 imapd.8 ipurge.8 lmtpd.8 \
		master.8 mbexamine.8 mbpath.8 notifyd.8 pop3d.8 quota.8 \
		reconstruct.8 rmnews.8 smmapd.8 squatter.8 syncnews.8 \
		timsieved.8 tls_prune.8

DOCS=		altnamespace anoncvs bugs changes faq feedback index \
		install install-admin-mb install-auth install-compile \
		install-configure install-murder install-netnews \
		install-perf install-prereq install-sieve install-snmpmon \
		install-testing install-upgrade install-virtdomains \
		mailing-list man notes os overview questions readme sieve \
		sieve-protocol specs

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
