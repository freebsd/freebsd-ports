# New ports collection makefile for:	qmail
# Version required:	1.03
# Date created:		25 May 1998
# Whom:			Mario S F Ferreira <lioux@gns.com.br> et al.
#
# $FreeBSD$
#

DISTNAME=	qmail-1.03
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.net.ohio-state.edu/pub/networking/mail/qmail/ \
		ftp://ftp.ntnu.no/pub/unix/mail/qmail/ \
		ftp://ftp.mira.net.au/unix/mail/qmail/ \
		ftp://ftp.id.wustl.edu/pub/qmail/ \
		ftp://mirror.uk.uu.net/pub/qmail/ \
		ftp://ftp.jp.qmail.org/qmail/ \
		http://ftp.rifkin.technion.ac.il/pub/qmail/ \
		http://koobera.math.uic.edu/www/software/ \
		http://pobox.com/~djb/software/ 

# Patch necessary to cope with non-RFC >512 dns entries
# Since AOL has been using those, the problem has skyrocketed from minor to
# groundzero. qmail being RFC compliant need to be "fixed" to work with those
PATCH_SITES=	http://www.ckdhr.com/ckd/
PATCHFILES=	qmail-103.patch
PATCH_DIST_STRIP+=	-p1

MAINTAINER=	lioux@gns.com.br

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

DOCFILES=	${WRKSRC}/BLURB ${WRKSRC}/BLURB2 ${WRKSRC}/BLURB3 \
		${WRKSRC}/BLURB4 ${WRKSRC}/INTERNALS ${WRKSRC}/SECURITY \
		${WRKSRC}/THOUGHTS ${FILESDIR}/PORT_NOTES

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

CONFIGUREFILES=	${WRKSRC}/install ${WRKSRC}/dnsfq ${WRKSRC}/hostname \
		${WRKSRC}/dnsip ${WRKSRC}/ipmeprint ${WRKSRC}/dnsptr

.if (${PREFIX} == "/usr/local")
DOCDIR=	share/doc/qmail
.else
DOCDIR=	doc
.endif

NO_MTREE=	yes

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
	@${INSTALL_PROGRAM} ${CONFIGUREFILES} ${PREFIX}/configure
	@${INSTALL_SCRIPT} ${WRKSRC}/config ${PREFIX}/configure
	@${INSTALL_SCRIPT} ${BOOTFILES} ${PREFIX}/boot
.for i in 1 5 7 8
	@${MKDIR} ${PREFIX}/man/man$i
.for j in ${MAN${i}}
	@${INSTALL_MAN} ${WRKSRC}/$j ${PREFIX}/man/man${i}
.endfor
.endfor
.if !defined(NOPORTDOCS)
	@${INSTALL_DATA} ${DOCFILES} ${PREFIX}/${DOCDIR}
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
	@${INSTALL_SCRIPT} ${FILESDIR}/mkaliasdir ${PREFIX}/${DOCDIR}
	@cd ${PREFIX}/configure ; ./config
	@${MKDIR} /usr/local/etc/rc.d
	@${LN} -sf ${PREFIX}/rc /usr/local/etc/rc.d/qmail.sh
	@${ECHO}
	@${SED} s!/usr/local/!${PREFIX}/!g ${PKGDIR}/MESSAGE | /usr/bin/fmt

.include <bsd.port.mk>

# Ugh...  ;-)
thereal-post-patch:
.for i in ${BOOTFILES}
	if [ `dirname $i` != ${FILESDIR} ] ; \
	then \
		${CP} $i.sh $i.sh.orig; \
		(head -c `${EXPR} \`ls -l $i.sh.orig \
		    | ${AWK} '{print $$5}'\` - 1` $i.sh.orig ; ${ECHO} '&') \
		    > $i.sh ; \
	fi
.endfor

# The users are instructed (in PORT_NOTES) to install ${QUEUE_DIR}/rc
# themselves.  Each /var/qmail/ should have its own rc.  On many machines,
# /usr/local/ is nfs mounted and /var/qmail/ is local.  An individual
# machine may want/not-want qmail.  Pity we can't add a dir to local_startup
# from here.

# Wouldn't hurt to provide an "enable_qmail" and "disable_sendmail" target
# that do 1) and 2) above and disable the existing sendmail, respectively.
