# New ports collection makefile for:	qmail
# Date created:		25 May 1998
# Whom:			Mario S F Ferreira <lioux@linf.unb.br> et al.
#
# $FreeBSD$
#

PORTNAME=	qmail
PORTVERSION?=	${QMAIL_VERSION}
PORTREVISION?=	4
CATEGORIES=	mail
MASTER_SITES+=	${MASTER_SITE_QMAIL}
DISTNAME=	${PORTNAME}-${QMAIL_VERSION}

MAINTAINER?=	freebsd@galle.com.br
COMMENT?=	A secure, reliable, efficient, simple, and fast MTA

DIST_SUBDIR=	qmail

.if defined(SLAVE_LDAP) || \
    defined(SLAVE_SPAMCONTROL) || \
    defined(SLAVE_MYSQL)
BARRIER_MAILDIRQUOTA_PATCH=	yes
BARRIER_BLOCKEXEC_PATCH=	yes
.endif

.if defined(SLAVE_LDAP) || \
    defined(SLAVE_SPAMCONTROL)
BARRIER_DNS_PATCH=		yes
BARRIER_BIG_CONCURRENCY_PATCH=	yes
BARRIER_QMTPC_PATCH=		yes
BARRIER_DISCBOUNCES_PATCH=	yes
.endif

.if defined(SLAVE_LDAP) || \
    defined(SLAVE_SMTP_AUTH_TLS) || \
    defined(SLAVE_SPAMCONTROL) || \
    defined(SLAVE_TLS)
BARRIER_OUTGOINGIP_PATCH=	yes
BARRIER_RFC2821_PATCH=		yes
.endif

.if defined(SLAVE_MYSQL) || \
    defined(SLAVE_SPAMCONTROL)
BARRIER_QMAILQUEUE_PATCH=	yes
.endif

.if defined(SLAVE_SPAMCONTROL)
BARRIER_SENDMAIL_F_PATCH=yes
BARRIER_BIG_TODO_PATCH=yes
BARRIER_LOCALTIME_PATCH=yes
.endif

.if !defined(BARRIER_DNS_PATCH)
# Patch necessary to cope with non-RFC >512 dns entries
# Since AOL has been using those, the problem has skyrocketed from minor to
# groundzero. qmail being RFC compliant need to be "fixed" to work with those
PATCH_SITES+=	http://www.ckdhr.com/ckd/:dns
PATCHFILES+=	qmail-103.patch:dns
PATCH_DIST_STRIP+=	-p1
.endif

.if !defined(BARRIER_SENDMAIL_F_PATCH)
# David Phillips noticed that sendmail's -f option sets a default
# From: header, and so should qmail's emulation.
PATCH_SITES+=	http://david.acz.org/software/:sendmail_flagf
PATCHFILES+=	sendmail-flagf.patch:sendmail_flagf
.endif

.if !defined(BARRIER_RFC2821_PATCH)
# This patch changes qmail-remote to skip over MX servers that greet with
# codes 400 to 499 and to bounce mail when any MX server that qmail tries
# greets with a code 500 to 599.
# Created by Matthias Andree
PATCH_SITES+=	http://www-dt.e-technik.uni-dortmund.de/~ma/qmail/:rfc2821
PATCHFILES+=	patch-qmail-1.03-rfc2821.diff:rfc2821
.endif

.if defined(SLAVE_LDAP)
PATCH_SITES+=	http://www.nrg4u.com/qmail/:ldap
PATCHFILES+=	qmail-ldap-1.03-${LDAP_PATCH_DATE}.patch.gz:ldap
.elif defined(SLAVE_MYSQL)
PATCH_SITES+=	http://iain.cx/unix/qmail/download/:mysql
PATCHFILES+=	qmail-mysql-${MYSQL_PATCH_VERSION}.patch:mysql
.elif defined(SLAVE_SMTP_AUTH_TLS)
PATCH_SITES+=	http://students.imsa.edu/~ngroot/:smtp_auth_tls
PATCHFILES+=	qmail-1.03-starttls-smtp-auth.patch:smtp_auth_tls
.elif defined(SLAVE_TLS)
PATCH_SITES+=	http://www.esat.kuleuven.ac.be/~vermeule/qmail/:tls
PATCHFILES+=	tls.patch:tls
PATCH_DIST_STRIP+=	-p1
.endif

PATCH_SITES+=	${MASTER_SITE_LOCAL:S/$/:local,dns,ldap,mysql,smtp_auth_tls,tls/}
PATCH_SITE_SUBDIR+=	lioux/:local,dns,ldap,mysql,smtp_auth_tls,tls

NO_PACKAGE=	djb's packaging license does not allow non-standard \
		qmail binary distributions

# A normal qmail installation puts everything into /var/qmail/.
# If you want to install to /usr/local/, then "/usr/local/qmail" is
# suggested instead of "/usr/local", but both will work.
PREFIX?=		/var/qmail
QMAIL_VERSION?=		1.03

.if defined(SLAVE_SMTP_AUTH_TLS) || defined(SLAVE_TLS)
CFLAGS+=	-I${OPENSSLBASE}/include -L${OPENSSLBASE}/lib -DTLS
.if defined(WITH_TLS_DEBUG)
CFLAGS+=	-DDEBUG
.endif
.endif

.if !defined(BARRIER_QMAILQUEUE_PATCH)
OPTIONS+=	QMAILQUEUE_PATCH "run a QMAILQUEUE program" off
.endif
.if !defined(BARRIER_BIG_TODO_PATCH)
OPTIONS+=	BIG_TODO_PATCH "enable big_todo qmail patch" off
.endif
.if !defined(BARRIER_BIG_CONCURRENCY_PATCH)
OPTIONS+=	BIG_CONCURRENCY_PATCH "use a concurrency greater than 240" off
.endif
.if !defined(BARRIER_OUTGOINGIP_PATCH)
OPTIONS+=	OUTGOINGIP_PATCH "set the IP address to send messages" off
.endif
.if !defined(BARRIER_LOCALTIME_PATCH)
OPTIONS+=	LOCALTIME_PATCH "emit dates in the local timezone" off
.endif
.if !defined(BARRIER_QMTPC_PATCH)
OPTIONS+=	QMTPC_PATCH "send email using qmtp protocol" off
.endif
.if !defined(BARRIER_MAILDIRQUOTA_PATCH)
OPTIONS+=	MAILDIRQUOTA_PATCH "Maildir++ support" off
.endif
.if !defined(BARRIER_BLOCKEXEC_PATCH)
OPTIONS+=	BLOCKEXEC_PATCH "block many windows viruses/worms" off
.endif
.if !defined(BARRIER_DISCBOUNCES_PATCH)
OPTIONS+=	DISCBOUNCES_PATCH "discard double-bounces" off
.endif
.if defined(SLAVE_TLS) || defined(SLAVE_SMTP_AUTH_TLS)
OPTIONS+=	TLS_DEBUG "enable additional debug information" off
.elif defined(SLAVE_LDAP)
OPTIONS+=	TLS "SMTP TLS support" on \
		LDAP_CLUSTER "cluster support" on \
		AUTOMAILDIRMAKE "the auto-maildir-make feature" on \
		AUTOHOMEDIRMAKE "auto-homedir-make feature" on \
		LDAP_DEBUG "possibility to log and debug imap/pop" off \
		CLEARTEXTPASSWD "use cleartext passwords" off \
		DASH_EXT "dash_ext extended mail addresses add" off
.elif defined(SLAVE_SPAMCONTROL)
OPTIONS+=	RELAYMAILFROM	"Open relay based on mailfrom" off \
		QUITASAP	"Close session in case of a filter condition" off \
		REQBRACKETS	"Require brackets in <addresses>" on \
		VERP		"VERP addresses for recipients" on \
		RECIPIENTS550	"Get a 550 reply instead of a deferred bounce" off \
		LOCALMFREQAUTH	"Require auth when from is @ your domains" off \
		AUTHCRAM	"Aditional CRAM-MD5 support" off \
		MOREIPME	"Additional control files moreipme & notipme" off \
		BIGTODO		"Bruce Guenter's BigToDo patch" off
.endif
OPTIONS+=	RCDLINK "create rc.d/qmail.sh" on

ALL_TARGET+=	default dot-qmail.5 qmail-control.5 qmail-getpw.8 \
		qmail-limits.7 qmail-newmrh.8 qmail-newu.8 qmail-pw2u.8 \
		qmail-send.8 qmail-start.8 qmail-users.5

MAN1+=	forward.1 condredirect.1 bouncesaying.1 except.1 maildirmake.1 \
	maildir2mbox.1 maildirwatch.1 mailsubj.1 qreceipt.1 qbiff.1 preline.1 \
	tcp-env.1
MAN5+=	addresses.5 envelopes.5 maildir.5 mbox.5 dot-qmail.5 qmail-control.5 \
	qmail-header.5 qmail-log.5 qmail-users.5 tcp-environ.5
MAN7+=	forgeries.7 qmail-limits.7 qmail.7
MAN8+=	qmail-local.8 qmail-lspawn.8 qmail-getpw.8 qmail-remote.8 \
	qmail-rspawn.8 qmail-clean.8 qmail-send.8 qmail-start.8 splogger.8 \
	qmail-queue.8 qmail-inject.8 qmail-showctl.8 qmail-newmrh.8 \
	qmail-newu.8 qmail-pw2u.8 qmail-qread.8 qmail-qstat.8 qmail-tcpok.8 \
	qmail-tcpto.8 qmail-pop3d.8 qmail-popup.8 qmail-qmqpc.8 qmail-qmqpd.8 \
	qmail-qmtpd.8 qmail-smtpd.8 qmail-command.8

.if defined(SLAVE_SPAMCONTROL)
EXTRA_MAN8=	qmail-badloadertypes.8 qmail-badmimetypes.8 qmail-recipients.8
ALL_TARGET+=	${EXTRA_MAN8}
MAN8+=		${EXTRA_MAN8}
.endif

.if defined(SLAVE_SPAMCONTROL) || defined(SLAVE_SMTP_AUTH_TLS)
PLIST_SUB+=	README_AUTH=""
.else
PLIST_SUB+=	README_AUTH="@comment "
.endif

.if defined(SLAVE_LDAP)
PKGMESSAGE_SUFFIX=	-ldap
PLIST_SUB+=	LDAP=""
.else
PLIST_SUB+=	LDAP="@comment "
.endif

.if defined(SLAVE_SMTP_AUTH_TLS)
PKGMESSAGE_SUFFIX=	-smtp_auth+tls
PLIST_SUB+=	SMTP_AUTH_TLS=""
.else
PLIST_SUB+=	SMTP_AUTH_TLS="@comment "
.endif

.if defined(SLAVE_SPAMCONTROL)
PLIST_SUB+=	SPAMCONTROL=""
.else
PLIST_SUB+=	SPAMCONTROL="@comment "
.endif

.if defined(SLAVE_TLS)
PKGMESSAGE_SUFFIX=	-tls
PLIST_SUB+=	TLS=""
.else
PLIST_SUB+=	TLS="@comment "
.endif

SUB_FILES+=	pkg-message${PKGMESSAGE_SUFFIX} mailer.conf.sample \
		bootfiles.sed enable-qmail
PKGINSTALL?=	${WRKDIR}/pkg-install
PKGMESSAGE?=	${WRKDIR}/pkg-message${PKGMESSAGE_SUFFIX}

CSH?=	/bin/csh

DOCFILES+=	${WRKSRC}/BLURB ${WRKSRC}/BLURB2 ${WRKSRC}/BLURB3 \
		${WRKSRC}/BLURB4 ${WRKSRC}/INTERNALS ${WRKSRC}/SECURITY \
		${WRKSRC}/THOUGHTS ${FILESDIR}/PORT_NOTES \
		${FILESDIR}/PORT_NOTES_FreeBSD_40-RELEASE \
		${WRKDIR}/mailer.conf.sample \
		${WRKSRC}/FAQ ${WRKSRC}/UPGRADE ${WRKSRC}/SENDMAIL \
		${WRKSRC}/INSTALL ${WRKSRC}/INSTALL.alias \
		${WRKSRC}/INSTALL.ctl ${WRKSRC}/INSTALL.ids \
		${WRKSRC}/INSTALL.maildir ${WRKSRC}/INSTALL.mbox \
		${WRKSRC}/INSTALL.vsm ${WRKSRC}/TEST.deliver \
		${WRKSRC}/TEST.receive ${WRKSRC}/REMOVE.sendmail \
		${WRKSRC}/REMOVE.binmail ${WRKSRC}/PIC.local2alias \
		${WRKSRC}/PIC.local2ext ${WRKSRC}/PIC.local2local \
		${WRKSRC}/PIC.local2rem ${WRKSRC}/PIC.local2virt \
		${WRKSRC}/PIC.nullclient ${WRKSRC}/PIC.relaybad \
		${WRKSRC}/PIC.relaygood ${WRKSRC}/PIC.rem2local

.if defined(SLAVE_LDAP)
DOCFILES+=	${WRKSRC}/QLDAPINSTALL ${WRKSRC}/QLDAPNEWS \
		${WRKSRC}/POPBEFORESMTP ${WRKSRC}/QLDAPTODO \
		${WRKSRC}/QLDAPPICTURE
.elif defined(SLAVE_SMTP_AUTH_TLS)
DOCFILES+=	${WRKDIR}/SMTP_AUTH+TLS.readme \
		${WRKSRC}/README.auth
.elif defined(SLAVE_TLS)
DOCFILES+=	${WRKDIR}/TLS.readme
.elif defined(SLAVE_SPAMCONTROL)
DOCFILES+=	${WRKDIR}/doc/FILES.spamcontrol ${WRKDIR}/doc/HISTORY.spamcontrol \
		${WRKDIR}/doc/INSTALL.spamcontrol ${WRKDIR}/doc/LICENSE.spamcontrol \
		${WRKDIR}/doc/LOGGING.spamcontrol ${WRKDIR}/doc/Makefile.djbdns \
		${WRKDIR}/doc/README.auth ${WRKDIR}/doc/README.bigtodo \
		${WRKDIR}/doc/README.bouncemaxbytes ${WRKDIR}/doc/README.djbdns \
		${WRKDIR}/doc/README.doublebouncetrim ${WRKDIR}/doc/README.moreipme \
		${WRKDIR}/doc/README.qmailqueue ${WRKDIR}/doc/README.recipients \
		${WRKDIR}/doc/README.spamcontrol ${WRKDIR}/doc/README.wildmat \
		${WRKDIR}/doc/README_spamcontrol.html \
		${WRKDIR}/doc/RELEASE_22.spamcontrol \
		${WRKDIR}/doc/RELEASE_23.spamcontrol \
		${WRKDIR}/doc/SMTPREPLY.spamcontrol ${WRKDIR}/doc/TESTING.spamcontrol \
		${WRKDIR}/doc/TODO.spamcontrol ${WRKDIR}/doc/badloadertypes \
		${WRKDIR}/doc/badmailfrom ${WRKDIR}/doc/badmimetypes \
		${WRKDIR}/doc/badrcptto ${WRKDIR}/doc/conf-spamcontrol \
		${WRKDIR}/doc/install_spamcontrol.sh ${WRKDIR}/doc/tarpitcount
SCRIPTS+=	qmail-alias2recipients qmail-pwd2recipients \
		qmail-users2recipients qmail-vpopmail2recipients
.endif

BOOTFILES=	home home+df proc proc+df binm1 binm1+df \
		binm2 binm2+df binm3 binm3+df maildir

CONFIGUREPROGS=	${WRKSRC}/install ${WRKSRC}/dnsfq ${WRKSRC}/hostname \
		${WRKSRC}/dnsip ${WRKSRC}/ipmeprint ${WRKSRC}/dnsptr
CONFIGUREFILES=	${WRKSRC}/config ${WRKSRC}/config-fast

.if (${PREFIX} != ${LOCALBASE})
DOCSDIR=	${PREFIX}/doc
.endif

NO_MTREE=	yes
USE_REINPLACE=	yes

.include <bsd.port.pre.mk>

.if (defined(WITH_OUTGOINGIP_PATCH) && !defined(BARRIER_OUTGOINGIP_PATCH)) &&\
    (defined(WITH_QMTPC_PATCH)      && !defined(BARRIER_QMTPC_PATCH))
BROKEN=	"OUTGOINGIP and QMTPC conflicts! Please, make your choice"
.endif

.if defined(WITH_MAILDIRQUOTA_PATCH) && !defined(BARRIER_MAILDIRQUOTA_PATCH)
PATCH_SITES+=	http://www.alexdupre.com/qmail/:quota
PATCHFILES+=	qmail-maildir++.patch:quota
.endif

.if defined(WITH_BLOCKEXEC_PATCH) && !defined(BARRIER_BLOCKEXEC_PATCH)
PATCH_SITES+=	http://www.alexdupre.com/qmail/:blockexec
PATCHFILES+=	qmail-block-executables.patch:blockexec
.endif

.if defined(WITH_DISCBOUNCES_PATCH) && !defined(BARRIER_DISCBOUNCES_PATCH)
PATCH_SITES+=	http://www.alexdupre.com/qmail/:doublebounce
PATCHFILES+=	qmail-discard-double-bounces.patch:doublebounce
.endif

.if !defined(BARRIER_DNS_PATCH) \
 	||(defined(WITH_QMAILQUEUE_PATCH)     && !defined(BARRIER_QMAILQUEUE_PATCH)) \
	||(defined(WITH_BIG_TODO_PATCH)       && !defined(BARRIER_BIG_TODO_PATCH)) \
	||(defined(WITH_BIG_CONCURRENCY_PATCH)&& !defined(BARRIER_BIG_CONCURRENCY_PATCH)) \
	||(defined(WITH_OUTGOINGIP_PATCH)     && !defined(BARRIER_OUTGOINGIP_PATCH)) \
	||(defined(WITH_QMTPC_PATCH)          && !defined(BARRIER_QMTPC_PATCH))
PATCH_SITES+=	${MASTER_SITE_QMAIL}
.endif

.if defined(WITH_QMAILQUEUE_PATCH) && !defined(BARRIER_QMAILQUEUE_PATCH)
PATCHFILES+=	qmailqueue-patch
.endif
.if defined(WITH_BIG_TODO_PATCH) && !defined(BARRIER_BIG_TODO_PATCH)
PATCHFILES+=	big-todo.103.patch
.endif
.if defined(WITH_BIG_CONCURRENCY_PATCH) && !defined(BARRIER_BIG_CONCURRENCY_PATCH)
PATCHFILES+=	big-concurrency.patch
.endif
.if defined(WITH_OUTGOINGIP_PATCH) && !defined(BARRIER_OUTGOINGIP_PATCH)
PATCHFILES+=	outgoingip.patch
.endif
.if defined(WITH_QMTPC_PATCH) && !defined(BARRIER_QMTPC_PATCH)
PATCHFILES+=	qmail-1.03-qmtpc.patch
.endif

.if defined(WITH_LOCALTIME_PATCH) && !defined(BARRIER_LOCALTIME_PATCH)
PATCH_SITES+=	http://www.alib.jp/files/:localtime
PATCHFILES+=	qmail-date-localtime.patch:localtime
.endif

# Some default values, these can be modified by make command line
.if defined(WITH_BIG_CONCURRENCY_PATCH) && !defined(BARRIER_BIG_CONCURRENCY_PATCH)
WITH_BIG_CONCURRENCY_PATCH_CONCURRENCY_LIMIT?=	509
.endif

.if defined(WITH_RCDLINK)
PLIST_SUB+=	RCDLINK=""
RCDLINK=
.else
PLIST_SUB+=	RCDLINK="@comment "
RCDLINK=	\#
.endif

# Fill SELECTED_OPTIONS with options to write conf-spamcontrol
.if defined(SLAVE_SPAMCONTROL)
.if defined(WITH_RELAYMAILFROM)
SELECTED_OPTIONS+=	relaymailfrom=yes
.else
SELECTED_OPTIONS+=	relaymailfrom=no
.endif

.if defined(WITH_QUITASAP)
SELECTED_OPTIONS+=	quitasap=yes
.else
SELECTED_OPTIONS+=	quitasap=no
.endif

.if !defined(WITHOUT_REQBRACKETS)
SELECTED_OPTIONS+=	reqbrackets=yes
.else
SELECTED_OPTIONS+=	reqbrackets=no
.endif

.if !defined(WITHOUT_VERP)
SELECTED_OPTIONS+=	verp=yes
.else
SELECTED_OPTIONS+=	verp=no
.endif

.if defined(WITH_RECIPIENTS550)
SELECTED_OPTIONS+=	recipients550=yes
.else
SELECTED_OPTIONS+=	recipients550=no
.endif

.if defined(WITH_LOCALMFREQAUTH)
SELECTED_OPTIONS+=	localmfreqauth=yes
.else
SELECTED_OPTIONS+=	localmfreqauth=no
.endif

.if defined(WITH_AUTHCRAM)
SELECTED_OPTIONS+=	authcram=yes
.else
SELECTED_OPTIONS+=	authcram=no
.endif

.if defined(WITH_MOREIPME)
SELECTED_OPTIONS+=	moreipme=yes
.else
SELECTED_OPTIONS+=	moreipme=no
.endif

.if defined(WITH_BIGTODO)
SELECTED_OPTIONS+=	bigtodo=yes
.else
SELECTED_OPTIONS+=	bigtodo=no
.endif
.endif

pre-everything::
.if !defined(BARRIER_BIG_CONCURRENCY_PATCH)
	@${ECHO_MSG} ""
	@${ECHO_MSG} "You may use the following build options:"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "WITH_BIG_CONCURRENCY_PATCH_CONCURRENCY_LIMIT=NUMBER"
	@${ECHO_MSG} "				(default NUMBER=${WITH_BIG_CONCURRENCY_PATCH_CONCURRENCY_LIMIT})"
	@${ECHO_MSG} "				set this to a value reasonable for"
	@${ECHO_MSG} "				your system if you use the patch"
	@${ECHO_MSG} ""
.endif

post-extract:
.if defined(SLAVE_SPAMCONTROL)
	@cd ${WRKSRC} && ${TAR} -xzf ${DISTDIR}/${DIST_SUBDIR}/${SPAMCONTROL_DIST}
.endif

post-patch:
.if defined(SLAVE_MYSQL)
	@${REINPLACE_CMD} 's|/opt/mysql|${LOCALBASE}|' \
		${WRKSRC}/Makefile
.elif defined(SLAVE_SMTP_AUTH_TLS)
	@${HEAD} -6 ${DISTDIR}/${DIST_SUBDIR}/qmail-1.03-starttls-smtp-auth.patch \
		| ${TAIL} -5 \
		> ${WRKDIR}/SMTP_AUTH+TLS.readme
	@${REINPLACE_CMD} "s|/usr/local/ssl|${OPENSSLBASE}|" ${WRKSRC}/Makefile
.elif defined(SLAVE_SPAMCONTROL)
	@${ECHO_CMD} ${WRKDIR} > ${WRKSRC}/conf-qmail
	@${ECHO_CMD} "# Generated by qmail-spamcontrol FreeBSD port" \
		> ${WRKSRC}/conf-spamcontrol
.for option in ${SELECTED_OPTIONS}
	@${ECHO_CMD} ${option} >> ${WRKSRC}/conf-spamcontrol
.endfor
	@cd ${WRKSRC} && ./install_spamcontrol.sh
.elif defined(SLAVE_TLS)
	@${HEAD} -74 ${DISTDIR}/${DIST_SUBDIR}/tls.patch > ${WRKDIR}/TLS.readme
	@${REINPLACE_CMD} "s|/usr/local/ssl|${OPENSSLBASE}|" \
		${WRKSRC}/Makefile
.elif defined(SLAVE_LDAP)
	@${REINPLACE_CMD} "s|LDAPLIBS=-L/usr/local/lib|LDAPLIBS=-L${LOCALBASE}/lib|; \
			   s|LDAPINCLUDES=-I/usr/local/include|LDAPINCLUDES=-I${LOCALBASE}/include|" \
		${WRKSRC}/Makefile
.if !defined(WITHOUT_TLS)
	@${REINPLACE_CMD} "s|#TLSON=|TLSON=|; \
			   s|#TLSINCLUDES=-I/usr/local/include|TLSINCLUDES=-I${OPENSSLBASE}/include|; \
			   s|#TLSLIBS=-L/usr/local/lib|TLSLIBS=-L${OPENSSLBASE}/lib|; \
			   s|#OPENSSLBIN=/usr/local/bin/openssl|OPENSSLBIN=${OPENSSLBASE}/bin/openssl|" \
		${WRKSRC}/Makefile
.endif
.if !defined(WITHOUT_LDAP_CLUSTER)
	@${REINPLACE_CMD} "s|#LDAPFLAGS=-DQLDAP_CLUSTER\s+-DEXTERNAL_TODO|LDAPFLAGS\+=-DQLDAP_CLUSTER -DEXTERNAL_TODO#|" \
		${WRKSRC}/Makefile
.endif
.if !defined(WITHOUT_AUTOMAILDIRMAKE)
	@${REINPLACE_CMD} "s|#MDIRMAKE=-DAUTOMAILDIRMAKE|MDIRMAKE=-DAUTOMAILDIRMAKE|" \
		${WRKSRC}/Makefile
.endif
.if !defined(WITHOUT_AUTOHOMEDIRMAKE)
	@${REINPLACE_CMD} "s|#HDIRMAKE=-DAUTOHOMEDIRMAKE|HDIRMAKE=-DAUTOHOMEDIRMAKE|" \
		${WRKSRC}/Makefile
.endif
.if defined(WITH_LDAP_DEBUG)
	@${REINPLACE_CMD} "s|#DEBUG=-DDEBUG|DEBUG=-DDEBUG|" \
		${WRKSRC}/Makefile
.endif
.if defined(WITH_CLEARTEXTPASSWD)
	@${REINPLACE_CMD} "s|^#\s*-DCLEARTEXTPASSWD.*$$|LDAPFLAGS\+=-DCLEARTEXTPASSWD|" \
		${WRKSRC}/Makefile
.endif
.if defined(WITH_DASH_EXT)
	@${REINPLACE_CMD} "s|^# -DDASH_EXT.*$$|LDAPFLAGS\+=-DDASH_EXT|" \
		${WRKSRC}/Makefile
.endif
.endif
	@${REINPLACE_CMD} 's!/var/qmail!${PREFIX}!; \
			   s!/usr/local/!${LOCALBASE}/!' \
		${WRKSRC}/Makefile
	@${REINPLACE_CMD} 's!nofiles!qnofiles!g' \
		${WRKSRC}/conf-groups
	@${REINPLACE_CMD} '/"man"/d; /man\/man/d; /man\/cat/d; \
			   /"doc"/d; /"boot","/d' \
		${WRKSRC}/hier.c

do-configure:
	@${SED} -e 's,%%RCDLINK%%,${RCDLINK2},g; s,%%LOCALBASE%%,${LOCALBASE},g' \
		${FILESDIR}/pkg-install.in > ${WRKDIR}/pkg-install
	@${SETENV} PKG_PREFIX="${PREFIX}" ${CSH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL
	@${ECHO_CMD} "${CC} ${CFLAGS}" > ${WRKSRC}/conf-cc
	@${ECHO_CMD} ${PREFIX} > ${WRKSRC}/conf-qmail
.if defined(WITH_BIG_CONCURRENCY_PATCH) \
	&& !defined(BARRIER_BIG_CONCURRENCY_PATCH) \
	&& defined(WITH_BIG_CONCURRENCY_PATCH_CONCURRENCY_LIMIT)
	@if [ ${WITH_BIG_CONCURRENCY_PATCH_CONCURRENCY_LIMIT} -gt 0 ]; then \
		${ECHO_CMD} "${WITH_BIG_CONCURRENCY_PATCH_CONCURRENCY_LIMIT}" \
			> ${WRKSRC}/conf-spawn ; \
	fi
.endif

do-install:
.for i in ${BOOTFILES}
	@if  [ -f ${WRKSRC}/${i}.sh ] ; then \
		${SED} -f ${WRKDIR}/bootfiles.sed ${WRKSRC}/$i.sh > ${WRKDIR}/${i} ; \
	elif [ -f ${FILESDIR}/${i} ] ; then \
		${SED} -f ${WRKDIR}/bootfiles.sed ${FILESDIR}/$i > ${WRKDIR}/${i} ; \
	fi
.endfor
	@${MKDIR} ${DOCSDIR} ${PREFIX}/configure
	@cd ${WRKSRC} ; ./install
	${INSTALL_PROGRAM} ${CONFIGUREPROGS} ${PREFIX}/configure
	${INSTALL_SCRIPT} ${CONFIGUREFILES} ${PREFIX}/configure
.for i in ${BOOTFILES}
	${INSTALL_SCRIPT} ${WRKDIR}/${i:T} ${PREFIX}/boot
.endfor
.for i in 1 5 7 8
	@${MKDIR} ${PREFIX}/man/man$i
.for j in ${MAN${i}}
	${INSTALL_MAN} ${WRKSRC}/$j ${PREFIX}/man/man${i}
.endfor
.endfor
.if !defined(NOPORTDOCS)
	${INSTALL_DATA} ${DOCFILES} ${DOCSDIR}
.endif
	@${MKDIR} ${PREFIX}/scripts
	${INSTALL_SCRIPT} ${FILESDIR}/mkaliasdir ${PREFIX}/scripts
	${INSTALL_SCRIPT} ${WRKDIR}/enable-qmail ${PREFIX}/scripts
.for script in ${SCRIPTS}
	${INSTALL_SCRIPT} ${WRKDIR}/scripts/${script} ${PREFIX}/scripts
.endfor
.if defined(PACKAGE_BUILDING)
	@${ECHO_CMD} "FreeBSD Binary package qmail installation" \
		> ${DOCSDIR}/SYSDEPS
.else
	@cd ${WRKSRC} && ${CAT} `${CAT} SYSDEPS` \
		> ${DOCSDIR}/SYSDEPS
.endif
	@${SETENV} PKG_PREFIX="${PREFIX}" ${CSH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
	@${ECHO_CMD}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_CMD}

certificate:
.if defined(SLAVE_TLS) || defined(SLAVE_SMTP_AUTH_TLS) || defined(SLAVE_LDAP)
	@if [ -f ${OPENSSLDIR}/openssl.cnf ]; then \
		if [ ! -d ${WRKDIR} ]; then \
			${MKDIR} ${WRKDIR} ; \
		fi ; \
		${OPENSSLBASE}/bin/openssl req -new -x509 -nodes \
			-out ${WRKDIR}/servercert.pem -days 366 \
			-keyout ${WRKDIR}/servercert.pem ; \
		${INSTALL} -o qmaild -g qmail -m 0640 ${WRKDIR}/servercert.pem ${PREFIX}/control/servercert.pem ; \
		${ECHO_MSG} "===> Do not forget to do 'make clean' to clean up temporary files" ; \
	else \
		${ECHO_MSG} "===> You must create the file ${OPENSSLDIR}/openssl.cnf first." ; \
	fi
.endif

certificate-req:
.if defined(SLAVE_TLS) || defined(SLAVE_SMTP_AUTH_TLS) || defined(SLAVE_LDAP)
	@if [ -f ${OPENSSLDIR}/openssl.cnf ]; then \
		if [ ! -d ${WRKDIR} ]; then \
			${MKDIR} ${WRKDIR} ; \
		fi ; \
		${OPENSSLBASE}/bin/openssl req -new -nodes \
			-out ${WRKDIR}/req.pem \
			-keyout ${WRKDIR}/servercert.pem ; \
		${INSTALL} -o qmaild -g qmail -m 0640 ${WRKDIR}/servercert.pem ${PREFIX}/control/servercert.pem ; \
		${ECHO_MSG} ; \
		${ECHO_MSG} "===> Do not forget to do 'make clean' to clean up temporary files" ; \
		${ECHO_MSG} "===> Send ${WRKDIR}/req.pem to your CA to obtain signed_req.pem, and do:" ; \
		${ECHO_MSG} "===> cat signed_req.pem >> ${PREFIX}/control/servercert.pem" ; \
	else \
		${ECHO_MSG} "===> You must create the file ${OPENSSLDIR}/openssl.cnf first." ; \
	fi
.endif

.include <bsd.port.post.mk>
