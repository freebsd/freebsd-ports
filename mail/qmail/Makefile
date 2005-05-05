# New ports collection makefile for:	qmail
# Date created:		25 May 1998
# Whom:			Mario S F Ferreira <lioux@linf.unb.br> et al.
#
# $FreeBSD$
#

PORTNAME=	qmail
PORTVERSION?=	${QMAIL_VERSION}
PORTREVISION?=	3
CATEGORIES=	mail
MASTER_SITES+=	http://cr.yp.to/software/ \
		ftp://ftp.ntnu.no/pub/unix/mail/qmail/ \
		ftp://ftp.jp.qmail.org/qmail/ \
		ftp://ftp.net.ohio-state.edu/pub/networking/mail/qmail/ \
		${MASTER_SITE_QMAIL}
DISTNAME=	${PORTNAME}-${QMAIL_VERSION}

MAINTAINER?=	freebsd@galle.com.br
COMMENT?=	A secure, reliable, efficient, simple, and fast MTA

# qmail-* skeleton ports including this port may not want
# its patches
.if !defined(MAIN_QMAIL_PORT_DNS_PATCH_BARRIER)
# Patch necessary to cope with non-RFC >512 dns entries
# Since AOL has been using those, the problem has skyrocketed from minor to
# groundzero. qmail being RFC compliant need to be "fixed" to work with those
PATCH_SITES+=	http://www.ckdhr.com/ckd/:dns
PATCHFILES+=	qmail-103.patch:dns
PATCH_DIST_STRIP+=	-p1
.endif # MAIN_QMAIL_PORT_DNS_PATCH_BARRIER

.if !defined(MAIN_QMAIL_PORT_SENDMAIL_F_PATCH_BARRIER)
# David Phillips noticed that sendmail's -f option sets a default
# From: header, and so should qmail's emulation.
PATCH_SITES+=	http://david.acz.org/software/:sendmail_flagf
PATCHFILES+=	sendmail-flagf.patch:sendmail_flagf
.endif # MAIN_QMAIL_PORT_SENDMAIL_F_PATCH_BARRIER

.if !defined(MAIN_QMAIL_PORT_RFC2821_PATCH_BARRIER)
# This patch changes qmail-remote to skip over MX servers that greet with
# codes 400 to 499 and to bounce mail when any MX server that qmail tries
# greets with a code 500 to 599.
# Created by Matthias Andree
PATCH_SITES+=	http://www-dt.e-technik.uni-dortmund.de/~ma/qmail/:rfc2821
PATCHFILES+=	patch-qmail-1.03-rfc2821.diff:rfc2821
.endif # MAIN_QMAIL_PORT_RFC2821_PATCH_BARRIER

PATCH_SITES+=	${MASTER_SITE_LOCAL:S/$/:local,dns,ldap,mysql,smtp_auth_tls,tls/}
PATCH_SITE_SUBDIR+=	lioux/:local,dns,ldap,mysql,smtp_auth_tls,tls

MASTER_SITE_QMAIL+=	\
	http://qmail.geto.net/%SUBDIR%/ \
	http://qmail.palomine.net/%SUBDIR%/ \
	http://qmail.mirrors.summersault.com/%SUBDIR%/ \
	http://qmail.cdsinet.net/%SUBDIR%/ \
	http://qmail.fidnet.com/%SUBDIR%/ \
	http://qmail.mscnetworks.com/%SUBDIR%/ \
	http://qmail.teleglobe.net/%SUBDIR%/ \
	http://qmail.homegrownhost.net/%SUBDIR%/ \
	http://qmail.webmast.com/%SUBDIR%/ \
	http://qmail.glasswings.com.au/%SUBDIR%/ \
	http://qmail.planetmirror.com/%SUBDIR%/ \
	http://qmail.404-not-found.net/%SUBDIR%/ \
	http://qmail.hostlink.com.hk/%SUBDIR%/ \
	http://qmail.cbn.net.id/%SUBDIR%/ \
	http://www9.jp.qmail.org/%SUBDIR%/ \
	http://qmailorg.data-hotel.net/%SUBDIR%/ \
	http://qmail.manic.co.kr/%SUBDIR%/ \
	http://qmail.psshee.com/%SUBDIR%/ \
	http://qmail.soa.co.nz/%SUBDIR%/ \
	http://d2.nctu.edu.tw/qmail/%SUBDIR%/ \
	http://mirrors.kangaroot.net/qmail/%SUBDIR%/ \
	http://qmail.ssi.bg/%SUBDIR%/ \
	http://mirrors.sunsite.dk/qmailwww/%SUBDIR%/ \
	http://qmail.xinus.net/%SUBDIR%/ \
	http://qmail.lightwerk.com/%SUBDIR%/ \
	http://qmail.mirrors.Space.Net/%SUBDIR%/ \
	http://qmail-mirror.hoermann-rawema.de/%SUBDIR%/ \
	http://www.ntua.gr/qmail/%SUBDIR%/ \
	http://www.agria.hu/qmail/%SUBDIR%/ \
	http://qmail-mirror.naplopok.hu/%SUBDIR%/ \
	http://qmail.hu/%SUBDIR%/ \
	http://qmail.rhnet.is/%SUBDIR%/ \
	http://qmail.netsoc.ucd.ie/%SUBDIR%/ \
	http://complanet.ath.cx/qmail/%SUBDIR%/ \
	http://mirrors.dataloss.nl/www.qmail.org/%SUBDIR%/ \
	http://qmail.basefreak.nl/%SUBDIR%/ \
	http://www.math.ntnu.no/mirror/www.qmail.org/%SUBDIR%/ \
	http://qmail.obeer.com/%SUBDIR%/ \
	http://qmail.konnekt.org/%SUBDIR%/ \
	http://qmail.smux.net/%SUBDIR%/ \
	http://qmail.netvisao.pt/%SUBDIR%/ \
	http://qmail.ssc.nsu.ru/%SUBDIR%/ \
	http://qmail.tps.sk/%SUBDIR%/ \
	http://qmail.ipg.sk/%SUBDIR%/ \
	http://qmail.imasd.elmundo.es/%SUBDIR%/ \
	http://qmail.x42.com/%SUBDIR%/ \
	http://qmail.netrogenic.com/%SUBDIR%/ \
	http://qmail.omnis.ch/%SUBDIR%/ \
	http://qmail.asylog.net/%SUBDIR%/ \
	http://qmail.humourengine.com/%SUBDIR%/ \
	http://qmail.softflare.com/%SUBDIR%/ \
	http://qmail.blueyonder.co.uk/%SUBDIR%/ \
	http://qmail.usp.br/%SUBDIR%/ \
	http://qmail.matrix.com.br/%SUBDIR%/ \
	http://madhaus.utcs.utoronto.ca/qmail/%SUBDIR%/ \
	http://qmail.freezer-burn.org/%SUBDIR%/ \
	http://qmail.unam.mx/%SUBDIR%/ \
	http://qmail.ru.ac.za/%SUBDIR%/ \
	http://www.qmail.org/%SUBDIR%/

.if !defined(MAIN_QMAIL_PORT_DNS_PATCH_BARRIER) \
 	||(defined(WITH_QMAILQUEUE_PATCH)&&!defined(MAIN_QMAIL_PORT_WITH_QMAILQUEUE_PATCH_BARRIER)) \
	||(defined(WITH_BIG_TODO_PATCH)&&!defined(MAIN_QMAIL_PORT_WITH_BIG_TODO_PATCH_BARRIER)) \
	||(defined(WITH_BIG_CONCURRENCY_PATCH)&&!defined(MAIN_QMAIL_PORT_WITH_BIG_CONCURRENCY_PATCH_BARRIER)) \
	||(defined(WITH_OUTGOINGIP_PATCH)&&!defined(MAIN_QMAIL_PORT_WITH_OUTGOINGIP_PATCH_BARRIER))
PATCH_SITES+=	${MASTER_SITE_QMAIL}
.endif

# qmail-* skeleton ports including this port may not want
# its patches
# MAIN_QMAIL_PORT_WITH_QMAILQUEUE_PATCH_BARRIER
# MAIN_QMAIL_PORT_WITH_BIG_TODO_PATCH_BARRIER
# MAIN_QMAIL_PORT_WITH_BIG_CONCURRENCY_PATCH_BARRIER
# MAIN_QMAIL_PORT_WITH_OUTGOINGIP_PATCH_BARRIER
#
.if defined(WITH_QMAILQUEUE_PATCH)&&!defined(MAIN_QMAIL_PORT_WITH_QMAILQUEUE_PATCH_BARRIER)
PATCHFILES+=	qmailqueue-patch
.endif # WITH_QMAILQUEUE_PATCH && !MAIN_QMAIL_PORT_WITH_QMAILQUEUE_PATCH_BARRIER
.if defined(WITH_BIG_TODO_PATCH)&&!defined(MAIN_QMAIL_PORT_WITH_BIG_TODO_PATCH_BARRIER)
PATCHFILES+=	big-todo.103.patch
.endif # WITH_BIG_TODO_PATCH && !MAIN_QMAIL_PORT_WITH_BIG_TODO_PATCH_BARRIER
.if defined(WITH_BIG_CONCURRENCY_PATCH)&&!defined(MAIN_QMAIL_PORT_WITH_BIG_CONCURRENCY_PATCH_BARRIER)
PATCHFILES+=	big-concurrency.patch
.endif # WITH_BIG_CONCURRENCY_PATCH && !MAIN_QMAIL_PORT_WITH_BIG_CONCURRENCY_PATCH_BARRIER
.if defined(WITH_OUTGOINGIP_PATCH)&&!defined(MAIN_QMAIL_PORT_WITH_OUTGOINGIP_PATCH_BARRIER)
PATCHFILES+=	outgoingip.patch
.endif # WITH_OUTGOINGIP_PATCH && !MAIN_QMAIL_PORT_WITH_OUTGOINGIP_PATCH_BARRIER

NO_PACKAGE=	djb's packaging license does not allow non-standard\
		qmail binary distributions

# A normal qmail installation puts everything into /var/qmail/.
# If you want to install to /usr/local/, then "/usr/local/qmail" is
# suggested instead of "/usr/local", but both will work.
PREFIX?=		/var/qmail
QMAIL_VERSION?=		1.03

# Some default values, these can be modified by make command line
.if defined(WITH_BIG_CONCURRENCY_PATCH)&&!defined(MAIN_QMAIL_PORT_WITH_BIG_CONCURRENCY_PATCH_BARRIER)
WITH_BIG_CONCURRENCY_PATCH_CONCURRENCY_LIMIT?=	509
.endif # WITH_BIG_CONCURRENCY_PATCH && !MAIN_QMAIL_PORT_WITH_BIG_CONCURRENCY_PATCH_BARRIER

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

PLIST_SUB=	DOCDIR=${DOCDIR}

DOCFILES+=	${WRKSRC}/BLURB ${WRKSRC}/BLURB2 ${WRKSRC}/BLURB3 \
		${WRKSRC}/BLURB4 ${WRKSRC}/INTERNALS ${WRKSRC}/SECURITY \
		${WRKSRC}/THOUGHTS ${FILESDIR}/PORT_NOTES \
		${FILESDIR}/PORT_NOTES_FreeBSD_40-RELEASE \
		${WRKDIR}/mailer.conf.sample

# The following docfiles are normally installed with qmail-hier
DOCFILES+=	${WRKSRC}/FAQ ${WRKSRC}/UPGRADE ${WRKSRC}/SENDMAIL \
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

# More files normally installed with from hier.c
BOOTFILES=	home home+df proc proc+df binm1 binm1+df \
		binm2 binm2+df binm3 binm3+df

# Supplied by Stuart Henderson <stuart@internationalschool.co.uk>
BOOTFILES+=	maildir

SCRIPTS+=	enable-qmail

CONFIGUREPROGS=	${WRKSRC}/install ${WRKSRC}/dnsfq ${WRKSRC}/hostname \
		${WRKSRC}/dnsip ${WRKSRC}/ipmeprint ${WRKSRC}/dnsptr
CONFIGUREFILES=	${WRKSRC}/config ${WRKSRC}/config-fast

.if (${PREFIX} == ${LOCALBASE})
DOCDIR=	share/doc/qmail
.else
DOCDIR=	doc
.endif

NO_MTREE=	yes
USE_REINPLACE=	yes

.if !defined(_PREMKINCLUDED)
.include <bsd.port.pre.mk>
.endif

pre-fetch: pre-pre-fetch slaveport-pre-fetch post-pre-fetch

pre-pre-fetch:
.if !defined(MAIN_QMAIL_PORT_BUILD_WITH_OPTIONS_ADVERTISE_BARRIER)
	@${ECHO_MSG} ""
	@${ECHO_MSG} "You may use the following build options:"
	@${ECHO_MSG} ""
.if !defined(MAIN_QMAIL_PORT_WITH_QMAILQUEUE_PATCH_BARRIER)
	@${ECHO_MSG} "WITH_QMAILQUEUE_PATCH=yes	enable patch to qmail to run a QMAILQUEUE"
	@${ECHO_MSG} "				program instead of bin/qmail-queue"
.endif # MAIN_QMAIL_PORT_WITH_QMAILQUEUE_PATCH_BARRIER
.if !defined(MAIN_QMAIL_PORT_WITH_BIG_TODO_PATCH_BARRIER)
	@${ECHO_MSG} "WITH_BIG_TODO_PATCH=yes		enable big_todo qmail patch"
.endif # MAIN_QMAIL_PORT_WITH_BIG_TODO_PATCH_BARRIER
.if !defined(MAIN_QMAIL_PORT_WITH_BIG_CONCURRENCY_PATCH_BARRIER)
	@${ECHO_MSG} "WITH_BIG_CONCURRENCY_PATCH=yes	enable patch to qmail to"
	@${ECHO_MSG} "				use a concurrency greater than 240"
	@${ECHO_MSG} "WITH_BIG_CONCURRENCY_PATCH_CONCURRENCY_LIMIT=NUMBER"
	@${ECHO_MSG} "				(default NUMBER=${WITH_BIG_CONCURRENCY_PATCH_CONCURRENCY_LIMIT})"
	@${ECHO_MSG} "				set this to a value reasonable for"
	@${ECHO_MSG} "				your system if you use the patch"
.endif # MAIN_QMAIL_PORT_WITH_BIG_CONCURRENCY_PATCH_BARRIER
.if !defined(MAIN_QMAIL_PORT_WITH_OUTGOINGIP_PATCH_BARRIER)
	@${ECHO_MSG} "WITH_OUTGOINGIP_PATCH=yes	enable patch to qmail to"
	@${ECHO_MSG} "				allow setting the IP address"
	@${ECHO_MSG} "				used by qmail when sending"
	@${ECHO_MSG} "				outgoing messages"
.endif # MAIN_QMAIL_PORT_WITH_OUTGOINGIP_PATCH_BARRIER
.if !defined(MAIN_QMAIL_PORT_WITH_PRESERVE_CONFIG_FILES_BARRIER)
	@${ECHO_MSG} "WITH_PRESERVE_CONFIG_FILES=yes	do not run automatic config"
	@${ECHO_MSG} "				to preserve your config files"
.endif # MAIN_QMAIL_PORT_WITH_PRESERVE_CONFIG_FILES_BARRIER
	@${ECHO_MSG} "#"
.endif # MAIN_QMAIL_PORT_BUILD_WITH_OPTIONS_ADVERTISE_BARRIER

# Yet anther ugly hack (used by qmail-* skeleton ports)
# Permits them to define local targets without braking everything
# The ugly target name hopefully will avoid name clashing
.if !target(slaveport-pre-fetch)
slaveport-pre-fetch:
.endif

post-pre-fetch:
.if !defined(MAIN_QMAIL_PORT_BUILD_WITH_OPTIONS_ADVERTISE_BARRIER)
	@${ECHO_MSG} ""
.endif

post-patch: slaveport-post-patch post-post-patch

# Yet anther ugly hack (used by qmail-* skeleton ports)
# Permits them to define local targets without braking everything
# The ugly target name hopefully will avoid name clashing
.if !target(slaveport-post-patch)
slaveport-post-patch:
.endif

post-post-patch:
	@${SED} 's!%%PREFIX%%!${PREFIX}!g; \
	         s!%%ECHO_CMD%%!${ECHO_CMD}!g' \
	         ${FILESDIR}/bootfiles.sed.in > \
	         ${WRKDIR}/bootfiles.sed
.for i in ${BOOTFILES}
	@if  [ -f ${WRKSRC}/${i}.sh ] ; \
	then \
		${SED} -f ${WRKDIR}/bootfiles.sed ${WRKSRC}/$i.sh > ${WRKDIR}/${i} ; \
	elif [ -f ${FILESDIR}/${i} ] ; \
	then \
		${SED} -f ${WRKDIR}/bootfiles.sed ${FILESDIR}/$i > ${WRKDIR}/${i} ; \
	fi
.endfor
	@${MKDIR} ${WRKDIR}/scripts
	@${SED} "s!%%PREFIX%%!${PREFIX}!g; s!%%DOCDIR%%!${DOCDIR}!g" \
		${FILESDIR}/enable-qmail.in > \
		${WRKDIR}/scripts/enable-qmail
	@${SED} s!/var/qmail/!${PREFIX}/!g ${FILESDIR}/mailer.conf.sample > \
		${WRKDIR}/mailer.conf.sample
	@${REINPLACE_CMD} "s!/var/qmail!${PREFIX}!;s!/usr/local/!${LOCALBASE}/!" ${WRKSRC}/Makefile

# If you want to change the qmail users, they must be changed in both
# work/*/conf-users and pkg/INSTALL.

do-configure:
	@# Create/Check the necessary groups/users
	@PKG_PREFIX=${PREFIX} ${PKGINSTALL}
	@${ECHO_CMD} "${CC} ${CFLAGS}" > ${WRKSRC}/conf-cc
	@${ECHO_CMD} ${PREFIX} > ${WRKSRC}/conf-qmail
.if defined(WITH_BIG_CONCURRENCY_PATCH) \
	&& !defined(MAIN_QMAIL_PORT_WITH_BIG_CONCURRENCY_PATCH_BARRIER) \
	&& defined(WITH_BIG_CONCURRENCY_PATCH_CONCURRENCY_LIMIT)
	@if [ ${WITH_BIG_CONCURRENCY_PATCH_CONCURRENCY_LIMIT} -gt 0 ]; \
	then \
		${ECHO_CMD} "${WITH_BIG_CONCURRENCY_PATCH_CONCURRENCY_LIMIT}" \
			> ${WRKSRC}/conf-spawn ; \
	fi
.endif # MAIN_QMAIL_PORT_WITH_BIG_CONCURRENCY_PATCH_BARRIER

do-install:
	@# Check again, just in case (ideally should error if not found)
	@PKG_PREFIX=${PREFIX} ${PKGINSTALL}
	@${MKDIR} ${PREFIX}/${DOCDIR} ${PREFIX}/configure
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
	${INSTALL_DATA} ${DOCFILES} ${PREFIX}/${DOCDIR}
.endif
.if defined(PACKAGE_BUILDING)
	@${ECHO_CMD} "FreeBSD Binary package qmail installation" \
		> ${PREFIX}/${DOCDIR}/SYSDEPS
.else
	@cd ${WRKSRC} && ${CAT} `${CAT} SYSDEPS` \
		> ${PREFIX}/${DOCDIR}/SYSDEPS
.endif
.for i in root postmaster mailer-daemon
	@${TOUCH} ${PREFIX}/alias/.qmail-${i}
.endfor
	@# This is not part of qmail proper, hence the 2nd class citizenship
.if !defined(WITH_PRESERVE_CONFIG_FILES)
	@cd ${PREFIX}/configure ; ./config
.endif
	@${MKDIR} ${PREFIX}/scripts
	${INSTALL_SCRIPT} ${FILESDIR}/mkaliasdir ${PREFIX}/scripts
.for script in ${SCRIPTS}
	${INSTALL_SCRIPT} ${WRKDIR}/scripts/${script} ${PREFIX}/scripts
.endfor
	@${MKDIR} ${LOCALBASE}/etc/rc.d
	@${LN} -sf ${PREFIX}/rc ${LOCALBASE}/etc/rc.d/qmail.sh
	@${ECHO_CMD}
	@${SED} s!/var/qmail!${PREFIX}!g ${PKGMESSAGE} | ${FMT}
	@${ECHO_CMD}

.include <bsd.port.post.mk>
