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
#           (the documented behavior for the 'mail.local' delivery
#           program).
#

PORTNAME=	nmh
PORTVERSION=	1.0.3
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.mhost.com/pub/nmh/ \
		http://people.FreeBSD.org/~jkoshy/PORTS/

MAINTAINER=     Scott.Blachowicz@seaslug.org

USE_AUTOCONF=   yes
CONFIGURE_ARGS= --libdir=${PREFIX}/libexec/nmh \
		--sysconfdir=${PREFIX}/etc/nmh --enable-nmh-pop
.ifdef NMH_MTS
CONFIGURE_ARGS+= --with-mts=${NMH_MTS}
.endif
.ifdef NMH_EDITOR
CONFIGURE_ARGS+= --with-editor=${NMH_EDITOR}
.endif
.ifdef NMH_PAGER
CONFIGURE_ARGS+= --with-pager=${NMH_PAGER}
.endif

.ifndef NMH_LOCKING
NMH_LOCKING=FLOCK_LOCKING
.endif
CFLAGS+= -D$(NMH_LOCKING)

MAN1= ali.1 anno.1 burst.1 comp.1 dist.1 flist.1 folder.1 forw.1 \
      inc.1 mark.1 mh-chart.1 mhbuild.1 mhl.1 mhlist.1 mhmail.1 \
      mhn.1 mhparam.1 mhpath.1 mhshow.1 mhstore.1 msgchk.1 msh.1 \
      next.1 nmh.1 packf.1 pick.1 prev.1 prompter.1 rcvdist.1 \
      rcvpack.1 rcvstore.1 rcvtty.1 refile.1 repl.1 rmf.1 rmm.1 \
      scan.1 send.1 sendfiles.1 show.1 slocal.1 sortm.1 \
      vmh.1 whatnow.1 whom.1

MAN5= mh-alias.5 mh-draft.5 mh-format.5 mh-mail.5 mh-profile.5 \
      mh-sequence.5 mh-tailor.5
MLINKS= mh-profile.5 mh_profile.5

MAN8= ap.8 conflict.8 dp.8 fmtdump.8 install-mh.8 mh-mts.8 post.8

pre-configure:
	cd ${WRKSRC}; chmod +w configure

post-install:
	@PKG_PREFIX='${PREFIX}' sh ${PKGDIR}/INSTALL
	chgrp mail ${PREFIX}/bin/inc
	${CHMOD} g+s ${PREFIX}/bin/inc

.include <bsd.port.mk>
