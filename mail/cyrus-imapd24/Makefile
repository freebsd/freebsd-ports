# New ports collection makefile for:		cyrus-imapd
# Date created:					Jan 4th 2001
# Whom:						ume@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	cyrus-imapd
PORTVERSION= 	2.2.7
#PORTREVISION=	0
CATEGORIES=	mail ipv6
MASTER_SITES=	ftp://ftp.andrew.cmu.edu/pub/cyrus-mail/ \
		ftp://ftp.hanse.de/sites/transit/mirror/ftp.andrew.cmu.edu/pub/cyrus-mail/ \
		${MASTER_SITE_RINGSERVER:S,%SUBDIR%,net/mail/cyrus-mail/&,}

MAINTAINER=	ume@FreeBSD.org
COMMENT=	The cyrus mail server, supporting POP3 and IMAP4 protocols

LIB_DEPENDS=	sasl2.2:${PORTSDIR}/security/cyrus-sasl2
BUILD_DEPENDS=	makedepend:${PORTSDIR}/devel/makedepend

CONFLICTS=	cyrus-1.* cyrus-imapd-2.[^2].*

LATEST_LINK=	${PORTNAME}22

USE_RC_SUBR=	yes
USE_OPENSSL=	yes
USE_PERL5=	yes
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--sysconfdir=${PREFIX}/etc \
		--with-cyrus-prefix=${PREFIX}/cyrus \
		--with-cyrus-user=${CYRUS_USER} \
		--with-cyrus-group=${CYRUS_GROUP} \
		--with-sasl=${LOCALBASE} \
		--with-bdb-libdir=${LOCALBASE}/lib \
		--with-com_err \
		--with-openssl=${OPENSSLBASE} \
		--with-perl=${PERL5}

.if defined(WITH_BDB_VER)
USE_BDB_VER=	${WITH_BDB_VER}
.else
USE_BDB_VER=	3
.endif
.if ${USE_BDB_VER} == 3
OPTIONS=	BDB_3		"Use BerkeleyDB v3"	on \
		BDB_4		"Use BerkeleyDB v4"	off \
		BDB_41		"Use BerkeleyDB v4.1"	off \
		BDB_42		"Use BerkeleyDB v4.2"	off
.elif ${USE_BDB_VER} == 4
OPTIONS=	BDB_3		"Use BerkeleyDB v3"	off \
		BDB_4		"Use BerkeleyDB v4"	on \
		BDB_41		"Use BerkeleyDB v4.1"	off \
		BDB_42		"Use BerkeleyDB v4.2"	off
.elif ${USE_BDB_VER} == 41
OPTIONS=	BDB_3		"Use BerkeleyDB v3"	off \
		BDB_4		"Use BerkeleyDB v4"	off \
		BDB_41		"Use BerkeleyDB v4.1"	on \
		BDB_42		"Use BerkeleyDB v4.2"	off
.elif ${USE_BDB_VER} == 42
OPTIONS=	BDB_3		"Use BerkeleyDB v3"	off \
		BDB_4		"Use BerkeleyDB v4"	off \
		BDB_41		"Use BerkeleyDB v4.1"	off \
		BDB_42		"Use BerkeleyDB v4.2"	on
.else
BROKEN=		"WITH_BDB_VER must be 3, 4, 41 or 42"
.endif

OPTIONS+=	DRAC		"Enable DRAC support"			off
OPTIONS+=	IDLE_IDLED	"Enable IMAP IDLE method idled"		off \
		IDLE_POLL	"Enable IMAP IDLE method idle-polling"	on
OPTIONS+=	LDAP_PTLOADER	"Enable LDAP ptloader (experimantal)"	off
OPTIONS+=	LISTEXT		"Enable IMAP List extensions"		off
OPTIONS+=	MURDER		"Enable IMAP Murder support"		off
OPTIONS+=	NETSCAPEHACK	"Enable X-NETSCAPE extensions"		off
OPTIONS+=	NNTP		"Enable NNTP support"			off
OPTIONS+=	SNMP_4		"Enable SNMP support using net-snmp v4"	off \
		SNMP_5		"Enable SNMP support using net-snmp v5"	off

.include <bsd.port.pre.mk>

.if !defined(WITH_BDB_3) && !defined(WITH_BDB_4) && \
	!defined(WITH_BDB_41) && !defined(WITH_BDB_42)
.if defined(WITHOUT_BDB_3) && defined(WITHOUT_BDB_4) && \
	defined(WITHOUT_BDB_41) && defined(WITHOUT_BDB_42)
BROKEN=		"You need to select one BDB version.  Run 'make config' again!"
.endif
.if ${USE_BDB_VER} == 3
WITH_BDB_3=	yes
.elif ${USE_BDB_VER} == 4
WITH_BDB_4=	yes
.elif ${USE_BDB_VER} == 41
WITH_BDB_41=	yes
.elif ${USE_BDB_VER} == 42
WITH_BDB_42=	yes
.endif
.endif
.if (defined(WITH_BDB_3) && defined(WITH_BDB_4)) || \
	(defined(WITH_BDB_3) && defined(WITH_BDB_41)) || \
	(defined(WITH_BDB_3) && defined(WITH_BDB_42)) || \
	(defined(WITH_BDB_4) && defined(WITH_BDB_41)) || \
	(defined(WITH_BDB_4) && defined(WITH_BDB_42)) || \
	(defined(WITH_BDB_41) && defined(WITH_BDB_42))
BROKEN=		"Multiple BDB versions selected.  Run 'make config' again!"
.endif
.if defined(WITH_BDB_3)
LIB_DEPENDS+=	db3.3:${PORTSDIR}/databases/db3
CONFIGURE_ARGS+=--with-bdb-incdir=${LOCALBASE}/include/db3 --with-bdb=db3
.elif defined(WITH_BDB_4)
LIB_DEPENDS+=	db4.0:${PORTSDIR}/databases/db4
CONFIGURE_ARGS+=--with-bdb-incdir=${LOCALBASE}/include/db4 --with-bdb=db4
.elif defined(WITH_BDB_41)
LIB_DEPENDS+=	db41.1:${PORTSDIR}/databases/db41
CONFIGURE_ARGS+=--with-bdb-incdir=${LOCALBASE}/include/db41 --with-bdb=db41
.elif defined(WITH_BDB_42)
LIB_DEPENDS+=	db-4.2.2:${PORTSDIR}/databases/db42
CONFIGURE_ARGS+=--with-bdb-incdir=${LOCALBASE}/include/db42 --with-bdb=db-4.2
.endif

.if defined(WITH_NNTP)
CONFIGURE_ARGS+=--enable-nntp
PLIST_SUB+=	NNTP=""
.else
PLIST_SUB+=	NNTP="@comment "
.endif

.if defined(WITH_MURDER)
CONFIGURE_ARGS+=--enable-murder
CFLAGS+=	${PTHREAD_CFLAGS}
MAKE_ENV+=	PTHREAD_LIBS=${PTHREAD_LIBS}
PLIST_SUB+=	MURDER=""
.else
PLIST_SUB+=	MURDER="@comment "
.endif

.if defined(WITH_IDLE_IDLED) && defined(WITH_IDLE_POLL)
BROKEN=		"Multiple IDLE methods selected.  Run 'make config' again!"
.endif
.if defined(WITH_IDLE_IDLED)
CONFIGURE_ARGS+=--with-idle=idled
PLIST_SUB+=	IDLED=""
.elif defined(WITH_IDLE_POLL)
CONFIGURE_ARGS+=--with-idle=poll
PLIST_SUB+=	IDLED="@comment "
.elif defined(WITHOUT_IDLE_IDLED) && defined(WITHOUT_IDLE_POLL)
CONFIGURE_ARGS+=--with-idle=no
PLIST_SUB+=	IDLED="@comment "
.else
PLIST_SUB+=	IDLED="@comment "
.endif

.if defined(WITH_LISTEXT)
CONFIGURE_ARGS+=--enable-listext
.endif

.if defined(WITH_NETSCAPEHACK)
CONFIGURE_ARGS+=--enable-netscapehack
.endif

.if defined(WITH_DRAC)
EXTRA_PATCHES+=	${WRKSRC}/contrib/drac_auth.patch
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-aclocal.m4 \
		${FILESDIR}/extra-patch-configure.in
USE_AUTOCONF_VER=259
USE_AUTOHEADER_VER=259
CONFIGURE_ARGS+=--with-drac=${LOCALBASE}
BUILD_DEPENDS+=	${LOCALBASE}/lib/libdrac.a:${PORTSDIR}/mail/drac
.endif

.if defined(WITH_SNMP_4) && defined(WITH_SNMP_5)
BROKEN=		"Multiple net-snmp versions selected.  Run 'make config' again!"
.endif
.if defined(WITH_SNMP_4)
LIB_DEPENDS+=	snmp.4:${PORTSDIR}/net-mgmt/net-snmp4
.elif defined(WITH_SNMP_5)
LIB_DEPENDS+=	netsnmp.6:${PORTSDIR}/net-mgmt/net-snmp
.endif
.if defined(WITH_SNMP_4) || defined(WITH_SNMP_5)
CONFIGURE_ARGS+=--with-snmp=${LOCALBASE}
.else
CONFIGURE_ARGS+=--with-snmp=no
.endif

.if defined(WITH_LDAP_PTLOADER)
USE_OPENLDAP=	yes
CONFIGURE_ARGS+=--with-auth=pts --with-pts=ldap --with-ldap=${LOCALBASE}
PLIST_SUB+=	LDAP_PTLOADER=""
.else
CONFIGURE_ARGS+=--with-auth=unix
PLIST_SUB+=	LDAP_PTLOADER="@comment "
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

.if ${PERL_LEVEL} < 500800
RUN_DEPENDS+=	${SITE_PERL}/File/Temp.pm:${PORTSDIR}/devel/p5-File-Temp
.endif
.if ${PERL_LEVEL} < 500600
RUN_DEPENDS+=	${SITE_PERL}/Pod/Parser.pm:${PORTSDIR}/textproc/p5-PodParser
.endif

RC_SCRIPTS_SUB=	PREFIX=${PREFIX} \
		RC_SUBR=${RC_SUBR}

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
.if ${PERL_LEVEL} < 500600
		@${REINPLACE_CMD} -e "s|exec perl -x|exec perl -I${SITE_PERL} -x|" \
			${WRKSRC}/perl/sieve/scripts/sieveshell.pl
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
.if !defined(NOPORTDOCS)
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
		@${SED} ${RC_SCRIPTS_SUB:S/$/!g/:S/^/ -e s!%%/:S/=/%%!/} \
			${FILESDIR}/imapd.sh > ${PREFIX}/etc/rc.d/imapd.sh
		@${CHMOD} 755 ${PREFIX}/etc/rc.d/imapd.sh
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
