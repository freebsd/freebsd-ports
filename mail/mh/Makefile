# New ports collection makefile for:	mh
# Version required:	6.8.4
# Date created:		Oct 4, 1994
# Whom:			pst
#
# $Id: Makefile,v 1.6 1995/12/05 12:37:28 markm Exp $
#

DISTNAME=	mh-6.8.3
PKGNAME=	mh-6.8.4
CATEGORIES+=	mail
MASTER_SITES=	ftp://ftp.ics.uci.edu/pub/mh/tar/
EXTRACT_SUFX=	.tar.Z

PATCHSITES=	ftp://ftp.ics.uci.edu/pub/mh/updates/
PATCHFILES=	MH.6.8.4.Z

MAINTAINER=	markm@FreeBSD.ORG

MHMAN=	man1/ali.1 man1/anno.1 man1/burst.1 man1/comp.1 man1/dist.1 \
	man1/folder.1 man1/forw.1 man1/inc.1 man1/mark.1 man1/mh-chart.1 \
	man1/mh.1 man1/mhl.1 man1/mhook.1 man1/mhmail.1 man1/mhn.1 \
	man1/mhparam.1 man1/mhpath.1 man1/msgchk.1 man1/msh.1 man1/next.1 \
	man1/packf.1 man1/pick.1 man1/prev.1 man1/prompter.1 man1/rcvstore.1 \
	man1/refile.1 man1/repl.1 man1/rmf.1 man1/rmm.1 man1/scan.1 \
	man1/send.1 man1/show.1 man1/slocal.1 man1/sortm.1 man1/vmh.1 \
	man1/whatnow.1 man1/whom.1 man5/mh-alias.5 man5/mh-format.5 \
	man5/mh-mail.5 man5/mh-profile.5 man5/mh-sequence.5 man5/mh-tailor.5 \
	man8/ap.8 man8/conflict.8 man8/dp.8 man8/install-mh.8 man8/post.8 \
	man8/fmtdump.8

post-install:
	ldconfig -m ${PREFIX}/lib
	for m in ${MHMAN}; do gzip -9nf ${PREFIX}/man/$$m; done

.include <bsd.port.mk>
