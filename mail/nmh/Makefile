# New ports collection makefile for:	nmh
# Version required:     0.27
# Date created:		26 July 1997
# Whom:			Scott Blachowicz <Scott.Blachowicz@seaslug.org>
#
# $Id: Makefile,v 1.9 1998/06/05 15:10:54 itojun Exp $
#

DISTNAME=	nmh-0.27
CATEGORIES=	mail
MASTER_SITES=   ftp://ftp.math.gatech.edu/pub/nmh/

MAINTAINER=     Scott.Blachowicz@seaslug.org

GNU_CONFIGURE=	yes
CONFIGURE_ARGS= --libexecdir=${PREFIX}/libexec/nmh \
		--sysconfdir=${PREFIX}/etc/nmh --enable-nmh-pop

MAN1= ali.1 anno.1 burst.1 comp.1 dist.1 flist.1 folder.1 forw.1 inc.1 \
      mark.1 mh-chart.1 mhl.1 mhmail.1 mhn.1 mhparam.1 mhpath.1 msgchk.1 msh.1 \
      next.1 nmh.1 packf.1 pick.1 prev.1 prompter.1 rcvdist.1 rcvpack.1 \
      rcvstore.1 rcvtty.1 refile.1 repl.1 rmf.1 rmm.1 scan.1 send.1 show.1 \
      slocal.1 sortm.1 vmh.1 whatnow.1 whom.1 mhbuild.1 sendfiles.1

MAN5= mh-alias.5 mh-draft.5 mh-format.5 mh-mail.5 mh-profile.5 \
      mh-sequence.5 mh-tailor.5

MAN8= ap.8 conflict.8 dp.8 fmtdump.8 install-mh.8 mh-mts.8 post.8

# Since we patch the autoconf files as well as their outputs, avoid attempt
# to regenerate header input files with 'autoheader' by Makefile.
post-patch:
	@${TOUCH} ${WRKSRC}/stamp-h.in

post-install:
	@PKG_PREFIX='${PREFIX}' sh ${PKGDIR}/INSTALL
	chgrp mail ${PREFIX}/bin/inc
	chmod g+s ${PREFIX}/bin/inc

.include <bsd.port.mk>
