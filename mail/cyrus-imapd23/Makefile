# New ports collection makefile for:		cyrus-imapd
# Date created:					Jan 4th 2001
# Whom:						ume@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	cyrus-imapd
PORTVERSION= 	2.2.3
#PORTREVISION=	0
CATEGORIES=	mail ipv6
MASTER_SITES=	ftp://ftp.andrew.cmu.edu/pub/cyrus-mail/ \
		ftp://ftp.hanse.de/sites/transit/mirror/ftp.andrew.cmu.edu/pub/cyrus-mail/ \
		${MASTER_SITE_RINGSERVER:S,%SUBDIR%,net/mail/cyrus-mail/&,}

MAINTAINER=	ume@FreeBSD.org
COMMENT=	The cyrus mail server, supporting POP3 and IMAP4 protocols

CONFLICTS=	cyrus-1.* cyrus-imapd-2.[^2].*

LIB_DEPENDS=	sasl2.2:${PORTSDIR}/security/cyrus-sasl2
BUILD_DEPENDS=	makedepend:${PORTSDIR}/devel/makedepend

USE_RC_SUBR=	YES

USE_OPENSSL=	yes
USE_PERL5=	yes
USE_REINPLACE=	YES
GNU_CONFIGURE=	YES
CONFIGURE_ARGS=	--sysconfdir=${PREFIX}/etc \
		--with-cyrus-prefix=${PREFIX}/cyrus \
		--with-cyrus-user=${CYRUS_USER} \
		--with-cyrus-group=${CYRUS_GROUP} \
		--with-sasl=${LOCALBASE} \
		--with-bdb-libdir=${LOCALBASE}/lib \
		--with-auth=unix \
		--with-com_err \
		--with-openssl=${OPENSSLBASE} \
		--with-perl=${PERL5}

.if defined(WITH_BDB_VER)
USE_BDB_VER=	${WITH_BDB_VER}
.else
USE_BDB_VER=	3
.endif
.if ${USE_BDB_VER} == 3
LIB_DEPENDS+=	db3.3:${PORTSDIR}/databases/db3
CONFIGURE_ARGS+=--with-bdb-incdir=${LOCALBASE}/include/db3 --with-bdb=db3
.elif ${USE_BDB_VER} == 4
LIB_DEPENDS+=	db4.0:${PORTSDIR}/databases/db4
CONFIGURE_ARGS+=--with-bdb-incdir=${LOCALBASE}/include/db4 --with-bdb=db4
.elif ${USE_BDB_VER} == 41
LIB_DEPENDS+=	db41.1:${PORTSDIR}/databases/db41
CONFIGURE_ARGS+=--with-bdb-incdir=${LOCALBASE}/include/db41 --with-bdb=db41
.elif ${USE_BDB_VER} == 42
LIB_DEPENDS+=	db-4.2.2:${PORTSDIR}/databases/db42
CONFIGURE_ARGS+=--with-bdb-incdir=${LOCALBASE}/include/db42 --with-bdb=db-4.2
.else
BROKEN=		"WITH_BDB_VER must be 3, 4, 41 or 42"
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

.if defined(WITH_IDLE)
.if ${WITH_IDLE} != poll && ${WITH_IDLE} != idled && ${WITH_IDLE} != no
BROKEN=		"WITH_IDLE must be poll, idled or no"
.endif
CONFIGURE_ARGS+=--with-idle=${WITH_IDLE}
.if ${WITH_IDLE} == idled
PLIST_SUB+=	IDLED=""
.else
PLIST_SUB+=	IDLED="@comment "
.endif
.else
PLIST_SUB+=	IDLED="@comment "
.endif

.if defined(WITH_LISTEXT)
CONFIGURE_ARGS+=--enable-listext
.endif

.if defined(WITH_ANNOTATEMORE)
CONFIGURE_ARGS+=--enable-annotatemore
.endif

.if defined(WITH_NETSCAPEHACK)
CONFIGURE_ARGS+=--enable-netscapehack
.endif

.if defined(WITH_DRAC)
EXTRA_PATCHES+=	${WRKSRC}/contrib/drac_auth.patch
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-aclocal.m4
USE_AUTOHEADER=	YES
USE_AUTOCONF=	YES
WANT_AUTOCONF_VER=257
CONFIGURE_ARGS+=--with-drac=${LOCALBASE}
BUILD_DEPENDS+=	${LOCALBASE}/lib/libdrac.a:${PORTSDIR}/mail/drac
.endif

.include <bsd.port.pre.mk>

.if defined(WITH_SNMP)
LIB_DEPENDS+=	snmp.4:${PORTSDIR}/net/net-snmp4
CONFIGURE_ARGS+=--with-ucdsnmp=${LOCALBASE}
.else
CONFIGURE_ARGS+=--with-ucdsnmp=no
.endif

CYRUS_USER?=	cyrus
CYRUS_GROUP?=	cyrus

MAN1=		cyradm.1 imtest.1 installsieve.1 lmtptest.1 mupdatetest.1 \
		nntptest.1 pop3test.1 sieveshell.1 sivtest.1 smtptest.1
MAN3=		imclient.3
MAN5=		cyrus.conf.5 imapd.conf.5 krb.equiv.5
MAN8=		arbitron.8 chk_cyrus.8 nntpd.8 ctl_cyrusdb.8 ctl_deliver.8 \
		cyr_expire.8 ctl_mboxlist.8 cvt_cyrusdb.8 cyrquota.8 \
		deliver.8 fetchnews.8 fud.8 idled.8 imapd.8 ipurge.8 \
		lmtpd.8 master.8 mbexamine.8 mbpath.8 notifyd.8 pop3d.8 \
		reconstruct.8 rmnews.8 smmapd.8 squatter.8 syncnews.8 \
		timsieved.8 tls_prune.8

DOCS=		altnamespace anoncvs bugs changes faq feedback index \
		install install-admin-mb install-auth install-compile \
		install-configure install-murder install-netnews \
		install-perf install-prereq install-sieve install-snmpmon \
		install-testing install-upgrade install-virtdomains \
		mailing-list man notes os overview questions readme sieve \
		sieve-protocol specs

DOCSDIR=	${PREFIX}/share/doc/cyrus-imapd22

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

pre-everything::
.if !defined(WITH_BDB_VER)
	@if ${LDCONFIG} -r | ${GREP} -qwE -e "-ldb(41|4)"; then \
		${ECHO_MSG} ""; \
		${ECHO_MSG} "It seems you have installed newer db than db3.  If"; \
		${ECHO_MSG} "you are using newer db for cyrus-sasl2, you should"; \
		${ECHO_MSG} "specify same version by WITH_BDB_VER.  For"; \
		${ECHO_MSG} "exapmle, WITH_BDB_VER=4 for db4."; \
		${ECHO_MSG} ""; \
	fi
.endif

post-patch:
		@${SED} -e "s|%%CYRUS_USER%%|${CYRUS_USER}|g" \
			${.CURDIR}/pkg-install > ${PKGINSTALL}
		@${SED} -e "s|%%CYRUS_USER%%|${CYRUS_USER}|g" \
			${.CURDIR}/pkg-deinstall > ${PKGDEINSTALL}
		@${REINPLACE_CMD} -e "s|/etc/|${PREFIX}/etc/|" \
				  -e "s|%%CYRUS_USER%%|${CYRUS_USER}|g" \
				  -e "s|%%CYRUS_GROUP%%|${CYRUS_GROUP}|g" \
			${WRKSRC}/tools/mkimap
		@${REINPLACE_CMD} -e "s|/etc/|${PREFIX}/etc/|g" \
				  -e "s|/usr/sieve|/var/imap/sieve|g" \
			${WRKSRC}/tools/masssievec
		@${CP} ${WRKSRC}/man/quota.8 ${WRKSRC}/man/cyrquota.8
.if ${PERL_LEVEL} < 500600
		@${REINPLACE_CMD} -e "s|exec perl -x|exec perl -I${SITE_PERL} -x|" \
			${WRKSRC}/perl/sieve/scripts/sieveshell.pl
.endif

post-install:
		@${MV} ${PREFIX}/cyrus/bin/quota ${PREFIX}/cyrus/bin/cyrquota
.if !defined(NOPORTDOCS)
		${MKDIR} ${DOCSDIR}/man
		${MKDIR} ${DOCSDIR}/text
.for file in ${DOCS}
		${INSTALL_DATA} ${WRKSRC}/doc/${file}.html ${DOCSDIR}
		@${ECHO_CMD} share/doc/cyrus-imapd22/${file}.html >>${TMPPLIST}
.endfor
.for file in ${MAN1} ${MAN3} ${MAN5} ${MAN8}
		ofile=`echo ${file} | ${SED} s/cyrquota/quota/`; \
		if [ -f ${WRKSRC}/doc/man/$${ofile}.html ]; then \
		${INSTALL_DATA} ${WRKSRC}/doc/man/$${ofile}.html \
			${DOCSDIR}/man/$${ofile}.html; \
		${ECHO_CMD} share/doc/cyrus-imapd22/man/$${ofile}.html \
			>>${TMPPLIST}; \
		fi
.endfor
.for file in cyrusv2.mc murder.fig murder.png netnews.fig netnews.png
		${INSTALL_DATA} ${WRKSRC}/doc/${file} ${DOCSDIR}
		@${ECHO_CMD} share/doc/cyrus-imapd22/${file} >>${TMPPLIST}
.endfor
.for file in ${DOCS}
		${INSTALL_DATA} ${WRKSRC}/doc/text/${file} ${DOCSDIR}/text
		@${ECHO_CMD} share/doc/cyrus-imapd22/text/${file} >>${TMPPLIST}
.endfor
		@${ECHO_CMD} "@dirrm share/doc/cyrus-imapd22/text" >>${TMPPLIST}
		@${ECHO_CMD} "@dirrm share/doc/cyrus-imapd22/man" >>${TMPPLIST}
		@${ECHO_CMD} "@dirrm share/doc/cyrus-imapd22" >>${TMPPLIST}
.endif
		@${SED} ${RC_SCRIPTS_SUB:S/$/!g/:S/^/ -e s!%%/:S/=/%%!/} \
			${FILESDIR}/imapd.sh > ${PREFIX}/etc/rc.d/imapd.sh
		@${CHMOD} 755 ${PREFIX}/etc/rc.d/imapd.sh
		${INSTALL_DATA} ${FILESDIR}/imapd.conf \
			${PREFIX}/etc/imapd.conf.dist
		${INSTALL_DATA} ${WRKSRC}/master/conf/normal.conf \
			${PREFIX}/etc/cyrus.conf.dist
		${INSTALL_SCRIPT} ${WRKSRC}/tools/mkimap \
			${PREFIX}/cyrus/bin/mkimap
		${INSTALL_SCRIPT} ${WRKSRC}/tools/masssievec \
			${PREFIX}/cyrus/bin/masssievec
		@PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} \
			POST-INSTALL
		@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
