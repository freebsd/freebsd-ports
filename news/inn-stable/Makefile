# New ports collection makefile for:	inn
# Version required:	1.7.2
# Date created:		20 Oct 1994 (1.4), 18 Dec 1996 (1.5.1)
# Whom:			torstenb
#
# $Id: Makefile,v 1.33 1999/02/16 22:07:51 andreas Exp $
#

DISTNAME=	inn-STABLE_2_2-1999-02-14_03-02
PKGNAME=	inn-stable-v22
CATEGORIES=	news
MASTER_SITES=	ftp://ftp.isc.org/isc/inn/snapshots/

MAINTAINER=	andreas@FreeBSD.ORG

HAS_CONFIGURE=	yes
CONFIGURE_ARGS+=--prefix=${PREFIX}/news
CONFIGURE_ARGS+=--infodir=${PREFIX}/info
CONFIGURE_ARGS+=--mandir=${PREFIX}/man
CONFIGURE_ARGS+=--with-spool-dir=/var/spool/news
CONFIGURE_ARGS+=--with-log-dir=/var/log/news
CONFIGURE_ARGS+=--with-tmp-path=/tmp

# Highly recommended, because many of the really good spam filters
# are written in Perl
CONFIGURE_ARGS+=--with-perl
# if server has less than 256 MB RAM
CONFIGURE_ARGS+=--enable-tagged-hash
# Do not create static libraries
CONFIGURE_ARGS+=--disable-static

# Most available filters seem to be written in Perl these days,
# so you can safely leave out TCL support.
#CONFIGURE_ARGS+=--with-tcl
# Do not create shared libraries
#CONFIGURE_ARGS+=--disable-shared

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
	${MKDIR} ${PREFIX}/news
	${MKDIR} -m 0755 ${PREFIX}/news/sbin && \
		chown news.news ${PREFIX}/news/sbin

update: build
	@(cd ${WRKSRC} ; ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} update)
	@${MAKE} ${.MAKEFLAGS} post-install

post-install:
	if [ ! -d /var/spool/news ]; then \
		${MKDIR} -m 0775 /var/spool/news/articles; \
		chown news.news /var/spool/news/articles; \
		${MKDIR} -m 0775 /var/spool/news/cycbuffs; \
		chown news.news /var/spool/news/cycbuffs; \
		${MKDIR} -m 0775 /var/spool/news/incoming; \
		chown news.news /var/spool/news/incoming; \
		${MKDIR} -m 0775 /var/spool/news/innfeed; \
		chown news.news /var/spool/news/innfeed; \
		${MKDIR} -m 0775 /var/spool/news/outgoing; \
		chown news.news /var/spool/news/outgoing; \
		${MKDIR} -m 0775 /var/spool/news/overview; \
		chown news.news /var/spool/news/overview; \
		${MKDIR} -m 0775 /var/spool/news/tmp; \
		chown news.news /var/spool/news/tmp; \
		${MKDIR} -m 0775 /var/spool/news/uniover; \
		chown news.news /var/spool/news/uniover; \
	fi
	${SED} <${FILESDIR}/innd.sh >${PREFIX}/etc/rc.d/innd.sh \
		s+!!PREFIX!!+${PREFIX}+g && chmod +x ${PREFIX}/etc/rc.d/innd.sh
	# make rnews work when getting news via uucp !
	chmod 4555 ${PREFIX}/news/bin/rnews

.include <bsd.port.mk>
