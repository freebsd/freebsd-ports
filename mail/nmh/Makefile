# New ports collection makefile for:	nmh
# Date created:		07 Feb 1999
# Whom:			Scott Blachowicz <Scott.Blachowicz@seaslug.org>
#
# $FreeBSD$
#
# Makefile variables of interest:
#
# NMH_MTS - pass an MTS specification through to nmh's configure
#           script's "--with-mts" option.  Do a "make extract" and check
#           the NMH distribution's "INSTALL" file for more info.
#           Currently, the valid choices are
#    "smtp" - [the default] Open a connection to the SMTP port on
#           the configured server, default - localhost.  The server would
#           be specified in the etc/nmh/mts.conf file after installation.
#           This requires access to a SMTP daemon on the localhost or the
#           specified server system.
#    "sendmail" - Fork a copy of sendmail to handle the message. This
#           will have different behavior than "smtp" depending on your
#           local MTA and its configuration.  For example, some of the
#           rewriting facilities of "qmail-inject", if you are using qmail,
#           may be available this way, but not via NMH_MTS=smtp.
#
# NMH_EDITOR - pass an EDITOR specification through to nmh's configure
#           script's '--with-editor' option.
#
# NMH_PAGER - pass an PAGER specification through to nmh's configure
#           script's '--with-pager' option.
#
# NMH_LOCKING - specify the style of locking to be used by nmh for the
#           users' spool files (e.g. the 'inc' command). Must match the
#           locking style used by your MTA - the default is FLOCK_LOCKING
#           (the documented behavior for the 'mail.local' delivery program).
#           Do a 'make patch', then look in the source directory (currently
#           the config.h.in file) for more information on different locking
#           settings. Current valid settings are:
#             DOT_LOCKING FCNTL_LOCKING LOCKF_LOCKING FLOCK_LOCKING
#
# NMH_MASQUERADE - specify the type(s) of masquerading to allow.  This
#           is passed through to nmh's "--enable-masquerade" configure
#           option and the current syntax for that string is:
#             'draft_from[ mmailid[ username_extension]]'
#
# NMH_SMTPSERVERS - specify a blank-separated list of SMTP servers -
#           passed through to nmh's configure scripts '--with-smtpservers'
#           option.
#

PORTNAME=	nmh
PORTVERSION=	1.0.4
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.mhost.com/pub/nmh/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	jkoshy

MAINTAINER=	Scott.Blachowicz@seaslug.org

USE_AUTOCONF_VER=213
CONFIGURE_ARGS=	--libdir=${PREFIX}/libexec/nmh \
		--sysconfdir=${PREFIX}/etc/nmh --enable-nmh-pop
.ifdef NMH_MTS
CONFIGURE_ARGS+= --with-mts=${NMH_MTS}
.endif
.ifdef NMH_EDITOR
CONFIGURE_ARGS+= --with-editor=${NMH_EDITOR}
.endif
.ifdef NMH_MASQUERADE
CONFIGURE_ARGS+= --enable-masquerade="${NMH_MASQUERADE}"
.endif
.ifdef NMH_PAGER
CONFIGURE_ARGS+= --with-pager=${NMH_PAGER}
.endif
.ifdef NMH_SMTPSERVERS
CONFIGURE_ARGS+= --with-smtpservers="${NMH_SMTPSERVERS}"
.endif

.ifndef NMH_LOCKING
NMH_LOCKING=FLOCK_LOCKING
.endif
CFLAGS+= -D${NMH_LOCKING}

MAN1=	ali.1 anno.1 burst.1 comp.1 dist.1 flist.1 folder.1 forw.1 \
	inc.1 mark.1 mh-chart.1 mhbuild.1 mhl.1 mhlist.1 mhmail.1 \
	mhn.1 mhparam.1 mhpath.1 mhshow.1 mhstore.1 msgchk.1 msh.1 \
	next.1 nmh.1 packf.1 pick.1 prev.1 prompter.1 rcvdist.1 \
	rcvpack.1 rcvstore.1 rcvtty.1 refile.1 repl.1 rmf.1 rmm.1 \
	scan.1 send.1 sendfiles.1 show.1 slocal.1 sortm.1 \
	vmh.1 whatnow.1 whom.1

MAN5=	mh-alias.5 mh-draft.5 mh-format.5 mh-mail.5 mh-profile.5 \
	mh-sequence.5 mh-tailor.5
MLINKS=	mh-profile.5 mh_profile.5

MAN8=	ap.8 conflict.8 dp.8 fmtdump.8 install-mh.8 mh-mts.8 post.8

post-patch:
	@${PERL} -pi -e "s|autoconf|${AUTOCONF}|;\
		s|autoheader|${AUTOHEADER}|" ${WRKSRC}/Makefile.in

post-install:
	@PKG_PREFIX='${PREFIX}' ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
	chgrp mail ${PREFIX}/bin/inc
	${CHMOD} g+s ${PREFIX}/bin/inc
	for file in ${PREFIX}/etc/nmh/*.default ; do \
		if [ \! -f $${file%%.default} ] ; then \
			cp $$file $${file%%.default} ; \
			chmod u+w $${file%%.default} ; \
		fi \
	done

.include <bsd.port.mk>
