# New ports collection makefile for:	inn
# Version required:	1.4
# Date created:		20 Oct 1994
# Whom:			torstenb
#
# $Id: Makefile,v 1.5 1995/05/05 09:21:43 asami Exp $
#

DISTNAME=	inn1.4sec
PKGNAME=	inn-1.4
CATEGORIES+=	news
MASTER_SITES=	ftp://ftp.uu.net/networking/news/nntp/inn/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	torstenb@FreeBSD.ORG

NO_WRKSUBDIR=	YES

pre-install:
	mkdir -p ${PREFIX}/news /var/spool/news/over.view

post-install:
	gzip -9nf ${PREFIX}/man/man1/convdate.1 ${PREFIX}/man/man1/getlist.1 \
	${PREFIX}/man/man1/grephistory.1 ${PREFIX}/man/man1/inews.1 \
	${PREFIX}/man/man1/innconfval.1 ${PREFIX}/man/man1/installit.1 \
	${PREFIX}/man/man1/nntpget.1 ${PREFIX}/man/man1/rnews.1 \
	${PREFIX}/man/man1/shlock.1 ${PREFIX}/man/man1/shrinkfile.1 \
	${PREFIX}/man/man1/subst.1 ${PREFIX}/man/man3/clientlib.3 \
	${PREFIX}/man/man3/dbz.3 ${PREFIX}/man/man3/inndcomm.3 \
	${PREFIX}/man/man3/libinn.3 ${PREFIX}/man/man3/parsedate.3 \
	${PREFIX}/man/man3/qio.3 ${PREFIX}/man/man3/wildmat.3 \
	${PREFIX}/man/man5/active.5 ${PREFIX}/man/man5/control.ctl.5 \
	${PREFIX}/man/man5/expire.ctl.5 ${PREFIX}/man/man5/history.5 \
	${PREFIX}/man/man5/hosts.nntp.5 ${PREFIX}/man/man5/inn.conf.5 \
	${PREFIX}/man/man5/innwatch.ctl.5 ${PREFIX}/man/man5/moderators.5 \
	${PREFIX}/man/man5/newsfeeds.5 ${PREFIX}/man/man5/newslog.5 \
	${PREFIX}/man/man5/nnrp.access.5 ${PREFIX}/man/man5/nntpsend.ctl.5 \
	${PREFIX}/man/man5/overview.fmt.5 \
	${PREFIX}/man/man5/distrib.pats.5 ${PREFIX}/man/man5/passwd.nntp.5 \
	${PREFIX}/man/man8/archive.8 ${PREFIX}/man/man8/batcher.8 \
	${PREFIX}/man/man8/buffchan.8 ${PREFIX}/man/man8/ctlinnd.8 \
	${PREFIX}/man/man8/cvtbatch.8 ${PREFIX}/man/man8/expire.8 \
	${PREFIX}/man/man8/expireover.8 ${PREFIX}/man/man8/fastrm.8 \
	${PREFIX}/man/man8/filechan.8 ${PREFIX}/man/man8/innd.8 \
	${PREFIX}/man/man8/innxmit.8 ${PREFIX}/man/man8/news-recovery.8 \
	${PREFIX}/man/man8/news.daily.8 ${PREFIX}/man/man8/newslog.8 \
	${PREFIX}/man/man8/nnrpd.8 ${PREFIX}/man/man8/nntpsend.8 \
	${PREFIX}/man/man8/overchan.8 ${PREFIX}/man/man8/prunehistory.8

.include <bsd.port.mk>
