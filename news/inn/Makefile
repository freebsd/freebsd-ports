# New ports collection makefile for:	inn
# Date created:		20 Oct 1994 (1.4), 18 Dec 1996 (1.5.1), 14 Feb 1999 (2.2)
# Whom:			torstenb
#
# $FreeBSD$
#

PORTNAME=	inn
PORTVERSION=	2.2.2
CATEGORIES=	news
MASTER_SITES=	ftp://ftp.isc.org/isc/inn/

MAINTAINER=	torstenb@FreeBSD.org

Y2K=		http://www.isc.org/inn-y2k.html

USE_GMAKE=YES

.if exists(/var/news)
INN_NEWSSPOOL?=/var/news
.else
INN_NEWSSPOOL?=/var/spool/news
.endif
INN_NEWSLIB?=${PREFIX}/news
INN_NEWSLOG?=/var/log/news

HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	--mandir=${PREFIX}/man
CONFIGURE_ARGS+=	--prefix=${INN_NEWSLIB}
CONFIGURE_ARGS+=	--with-spool-dir=${INN_NEWSSPOOL}
CONFIGURE_ARGS+=	--with-log-dir=${INN_NEWSLOG}
CONFIGURE_ARGS+=	--with-perl
CONFIGURE_ARGS+=	--with-tmp-path=${INN_NEWSSPOOL}/tmp
CONFIGURE_ARGS+=	--with-largefiles

# Various Options. See ${WRKSRC}/INSTALL for details

# Use tagged hash table for the history database. Uses much less memory but
# is somewhat slower
#CONFIGURE_ARGS+=	--enable-tagged-hash

MAN1=	convdate.1 getlist.1 grephistory.1 inews.1 innconfval.1 innfeed.1 \
	installit.1 nntpget.1 rnews.1 shlock.1 shrinkfile.1 startinnfeed.1 \
	subst.1
MAN3=	clientlib.3 dbz.3 inndcomm.3 libinn.3 libstorage.3 parsedate.3 qio.3 \
	wildmat.3
MAN5=	active.5 control.ctl.5 cycbuff.conf.5 distrib.pats.5 expire.ctl.5 \
	history.5 incoming.conf.5 inn.conf.5 innfeed.conf.5 innwatch.ctl.5 \
	moderators.5 motd.news.5 newsfeeds.5 newslog.5 nnrp.access.5 \
	nnrpd.track.5 nntpsend.ctl.5 overview.ctl.5 overview.fmt.5 \
	passwd.nntp.5 storage.conf.5 storage.ctl.5
MAN8=	actived.8 actsync.8 actsyncd.8 archive.8 batcher.8 buffchan.8 \
	cnfsstat.8 controlchan.8 crosspost.8 ctlinnd.8 cvtbatch.8 expire.8 \
	expireindex.8 expireover.8 expirerm.8 fastrm.8 filechan.8 inncheck.8 \
	innd.8 inndf.8 innreport.8 innstat.8 innwatch.8 innxbatch.8 innxmit.8 \
	mailpost.8 makeactive.8 makehistory.8 news-recovery.8 news.daily.8 \
	news2mail.8 newslog.8 newsrequeue.8 nnrpd.8 nntpsend.8 overchan.8 \
	pgpverify.8 prunehistory.8 pullnews.8 scanlogs.8 send-uucp.8 sm.8 \
	tally.control.8 tally.unwanted.8 writelog.8

pre-install:
	${MKDIR} /var/spool/news

post-install:
	${SED} <${FILESDIR}/innd.sh >${PREFIX}/etc/rc.d/innd.sh \
		s+!!PREFIX!!+${PREFIX}+g && chmod +x ${PREFIX}/etc/rc.d/innd.sh

.include <bsd.port.mk>
