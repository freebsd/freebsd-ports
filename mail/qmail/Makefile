# New ports collection makefile for:	qmail
# Date created:		25 May 1998
# Whom:			Mario S F Ferreira <lioux@linf.unb.br> et al.
#
# $FreeBSD$
#

PORTNAME=	qmail
PORTVERSION= 	1.03
CATEGORIES=	mail
MASTER_SITES=	http://cr.yp.to/software/ \
		ftp://ftp.ntnu.no/pub/unix/mail/qmail/ \
		ftp://ftp.pipex.net/mirrors/qmail/ \
		ftp://ftp.jp.qmail.org/qmail/ \
		ftp://ftp.rifkin.technion.ac.il/pub/qmail/ \
		ftp://ftp.mira.net.au/unix/mail/qmail/ \
		ftp://ftp.net.ohio-state.edu/pub/networking/mail/qmail/ \
		ftp://ftp.id.wustl.edu/pub/qmail/ \
		ftp://koobera.math.uic.edu/www/

# Patch necessary to cope with non-RFC >512 dns entries
# Since AOL has been using those, the problem has skyrocketed from minor to
# groundzero. qmail being RFC compliant need to be "fixed" to work with those
PATCH_SITES?=	http://www.ckdhr.com/ckd/
PATCHFILES?=	qmail-103.patch
PATCH_DIST_STRIP+=	-p1

MAINTAINER=	lioux@linf.unb.br

# A normal qmail installation puts everything into /var/qmail/.
# If you want to install to /usr/local/, then "/usr/local/qmail" is
# suggested instead of "/usr/local", but both will work.
PREFIX=		/var/qmail

ALL_TARGET=	default dot-qmail.5 qmail-control.5 qmail-getpw.8 \
		qmail-limits.7 qmail-newmrh.8 qmail-newu.8 qmail-pw2u.8 \
		qmail-send.8 qmail-start.8 qmail-users.5

MAN1=	forward.1 condredirect.1 bouncesaying.1 except.1 maildirmake.1 \
	maildir2mbox.1 maildirwatch.1 mailsubj.1 qreceipt.1 qbiff.1 preline.1 \
	tcp-env.1
MAN5=	addresses.5 envelopes.5 maildir.5 mbox.5 dot-qmail.5 qmail-control.5 \
	qmail-header.5 qmail-log.5 qmail-users.5 tcp-environ.5
MAN7=	forgeries.7 qmail-limits.7 qmail.7
MAN8=	qmail-local.8 qmail-lspawn.8 qmail-getpw.8 qmail-remote.8 \
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
BOOTFILES=	${WRKSRC}/home ${WRKSRC}/home+df ${WRKSRC}/proc \
		${WRKSRC}/proc+df ${WRKSRC}/binm1 ${WRKSRC}/binm1+df \
		${WRKSRC}/binm2 ${WRKSRC}/binm2+df ${WRKSRC}/binm3 \
		${WRKSRC}/binm3+df

# Supplied by Stuart Henderson <stuart@internationalschool.co.uk>
BOOTFILES+=	${FILESDIR}/maildir

CONFIGUREPROGS=	${WRKSRC}/install ${WRKSRC}/dnsfq ${WRKSRC}/hostname \
		${WRKSRC}/dnsip ${WRKSRC}/ipmeprint ${WRKSRC}/dnsptr
CONFIGUREFILES=	${WRKSRC}/config ${WRKSRC}/config-fast

.if (${PREFIX} == ${LOCALBASE})
DOCDIR=	share/doc/qmail
.else
DOCDIR=	doc
.endif

NO_MTREE=	yes

.if !defined(_PREMKINCLUDED)
.include <bsd.port.pre.mk>
.endif

# If you want to change the qmail users, they must be changed in both
# work/*/conf-users and pkg/INSTALL.

do-configure:
	@# Create/Check the necessary groups/users
	@PKG_PREFIX=${PREFIX} ${PERL5} ${PKGDIR}/INSTALL
	@${ECHO} ${CC} ${CFLAGS} > ${WRKSRC}/conf-cc
	@${ECHO} ${PREFIX} > ${WRKSRC}/conf-qmail

post-patch: thereal-post-patch

do-install:
	@# Check again, just in case (ideally should error if not found)
	@PKG_PREFIX=${PREFIX} ${PERL5} ${PKGDIR}/INSTALL
	@${MKDIR} ${PREFIX}/${DOCDIR} ${PREFIX}/configure
	@cd ${WRKSRC} ; ./install
	${INSTALL_PROGRAM} ${CONFIGUREPROGS} ${PREFIX}/configure
	${INSTALL_SCRIPT} ${CONFIGUREFILES} ${PREFIX}/configure
	${INSTALL_SCRIPT} ${BOOTFILES} ${PREFIX}/boot
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
	@${ECHO} "FreeBSD Binary package QMail installation" \
		> ${PREFIX}/${DOCDIR}/SYSDEPS
.else
	@cd ${WRKSRC} && ${CAT} `${CAT} SYSDEPS` \
		> ${PREFIX}/${DOCDIR}/SYSDEPS
.endif
.for i in root postmaster mailer-daemon
	@${TOUCH} ${PREFIX}/alias/.qmail-${i}
.endfor
	@# This is not part of qmail proper, hence the 2nd class citizenship
	${INSTALL_SCRIPT} ${FILESDIR}/mkaliasdir ${PREFIX}/${DOCDIR}
	@cd ${PREFIX}/configure ; ./config
	@${MKDIR} ${LOCALBASE}/etc/rc.d
	@${LN} -sf ${PREFIX}/rc ${LOCALBASE}/etc/rc.d/qmail.sh
	@${ECHO}
	@${SED} s!/var/qmail!${PREFIX}!g ${PKGDIR}/MESSAGE | /usr/bin/fmt

# hack to allow slave ports to include bsd.port.pre.mk and then this file
.if defined(_PREMKINCLUDED)
.include <bsd.port.post.mk>
.else
.include <bsd.port.mk>
.endif

# Ugh...  ;-)
thereal-post-patch:
.for i in ${BOOTFILES}
	@if [ `dirname $i` != ${FILESDIR} ] ; \
	then \
		${CP} $i.sh $i.sh.orig; \
		(head -c `${EXPR} \`ls -l $i.sh.orig \
		    | ${AWK} '{print $$5}'\` - 1` $i.sh.orig ; ${ECHO} '&') \
		    > $i.sh ; \
	fi
.endfor
	@${SED} s!/var/qmail/!${PREFIX}/!g ${FILESDIR}/mailer.conf.sample > \
		${WRKDIR}/mailer.conf.sample

# Double Ugh... ;-)
${WRKDIR}/.thereal_disable_sendmail_done:
	@if [ ! -d ${WRKDIR} ]; \
	then \
		${MKDIR} ${WRKDIR} ; \
	fi

# I would like some input on the targets below. Only constructive ones
# please. :)
# based on shells/pdksh /etc/shells update PLIST.
thereal-disable-sendmail: ${WRKDIR}/.thereal_disable_sendmail_done /etc/rc.conf 
	@if [ -f /etc/rc.conf ]; \
	then \
		${CP} /etc/rc.conf /etc/rc.conf.bak && \
			${GREP} -v sendmail_enable /etc/rc.conf.bak > \
				/etc/rc.conf && \
			${TOUCH} ${WRKDIR}/.thereal_disable_sendmail_done ; \
	else \
		${ECHO_MSG} ¨===> ERROR: YOU DO NOT HAVE A VALID /etc/rc.conf¨ ; \
		${ECHO_MSG} ¨===> FIX this and try again¨ ; \
		${FALSE} ; \
	fi

disable-sendmail: thereal-disable-sendmail
	@${ECHO_MSG} "===> I hope you know what you are doing:"
	@${ECHO_MSG} "===> You just told your system to not"
	@${ECHO_MSG} "===> automaticaly start sendmail on your"
	@${ECHO_MSG} "===> next startup."
	@${ECHO_MSG} "===> (i.e., added sendmail_enable=\¨NO\¨ to rc.conf)"
	@if [ -f /etc/rc.conf ]; \
	then \
		${ECHO} sendmail_enable=\"NO\" >> /etc/rc.conf ; \
	fi

enable-sendmail: thereal-disable-sendmail
	@${ECHO_MSG} "===> I hope you know what you are doing:"
	@${ECHO_MSG} "===> You just told your system to"
	@${ECHO_MSG} "===> automaticaly start sendmail on your"
	@${ECHO_MSG} "===> next startup."
	@${ECHO_MSG} "===> (i.e., removed sendmail_enable=\¨NO\¨ from rc.conf)"

enable-qmail: install disable-sendmail
	@if [ -f /etc/mail/mailer.conf ]; \
	then \
		${CP} /etc/mail/mailer.conf /etc/mail/mailer.conf.bak && \
		${CP} ${WRKDIR}/mailer.conf.sample /etc/mail/mailer.conf ; \
	else \
		${ECHO_MSG} "===> ERROR: YOU DO NOT HAVE A VALID /etc/mail/mailer.conf" ; \
		${ECHO_MSG} "===> FIX this and try again" ; \
		${ECHO_MSG} "===> or, do \¨make force_enable_qmail\¨ if you are sure" ; \
		${ECHO_MSG} "===> you want this port replacing some binaries" ; \
		${ECHO_MSG} "===> IF THIS FEELS UNEASY, read ${PREFIX}/${DOCDIR}/REMOVE.sendmail and do it manually" ; \
	fi
	@${ECHO} "===> Do not forget to choose an appropriate qmail startup"
	@${ECHO} "===> script. Go through ${PREFIX}/boot, choose one"
	@${ECHO} "===> and copy the chosen script as ${PREFIX}/rc"
	@${ECHO} "===> For example, \¨cp ${PREFIX}/boot/proc+df ${PREFIX}/rc\¨"


# taken from mail/postfix idea
force-enable-qmail: install disable-sendmail
	@${ECHO_MSG} "===> Replacing sendmail"
	@if [ -e /usr/sbin/sendmail ]; then \
		${MV} -f /usr/sbin/sendmail /usr/sbin/sendmail.OFF && \
		${CHMOD} 0 /usr/sbin/sendmail.OFF; \
	fi
	@if [ -e ${PREFIX}/bin/sendmail ]; then \
		${LN} -s ${PREFIX}/bin/sendmail /usr/sbin/sendmail; \
	fi
	@${ECHO_MSG} "===> Replacing mailq"
	@if [ -e /usr/bin/mailq ]; then \
		${MV} -f /usr/bin/mailq /usr/bin/mailq.OFF && \
		${CHMOD} 0 /usr/bin/mailq.OFF; \
	fi  
	@if [ -e ${PREFIX}/bin/qmail-qread ]; then \
		${LN} -s ${PREFIX}/bin/qmail-qread /usr/bin/mailq; \
	fi
	@${ECHO_MSG} "===> Replacing newaliases"
	@if [ -e /usr/bin/newaliases ]; then \
		${MV} -f /usr/bin/newaliases /usr/bin/newaliases.OFF && \
		${CHMOD} 0 /usr/bin/newaliases.OFF; \
	fi
	@if [ -e ${PREFIX}/bin/newaliases ]; then \
		${LN} -s ${PREFIX}/bin/newaliases /usr/bin/newaliases; \
	fi

# The users are instructed (in PORT_NOTES) to install ${QUEUE_DIR}/rc
# themselves.  Each /var/qmail/ should have its own rc.  On many machines,
# /usr/local/ is nfs mounted and /var/qmail/ is local.  An individual
# machine may want/not-want qmail.  Pity we can't add a dir to local_startup
# from here.

# Wouldn't hurt to provide an "enable_qmail" and "disable_sendmail" target
# that do 1) and 2) above and disable the existing sendmail, respectively.
