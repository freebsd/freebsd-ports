# New ports collection makefile for:	inn
# Version required:	2.2
# Date created:		20 Oct 1994 (1.4), 18 Dec 1996 (1.5.1)
# Whom:			torstenb
#
# $FreeBSD$
#

DISTNAME=	inn-STABLE_2_2-1999-07-24_03-02
PKGNAME=	inn-stable-v22
CATEGORIES=	news
MASTER_SITES=	http://www.FreeBSD.org/~andreas/download/ \
		ftp://ftp.isc.org/isc/inn/snapshots/

MAINTAINER=	andreas@FreeBSD.org

Y2K=		http://www.isc.org/inn-y2k.html

.if defined(BATCH)
# in BATCH mode we use the default
NEWSSPOOL=/var/spool/news
NEWSLIB=${PREFIX}/news
NEWSLOG=/var/log/news
NEWSMAN=${PREFIX}/man
NEWSINFO=${PREFIX}/info
.else
# you can set this in /etc/make.conf !
NEWSSPOOL?=/var/spool/news
NEWSLIB?=${PREFIX}/news
NEWSLOG?=/var/log/news
NEWSMAN?=${PREFIX}/man
NEWSINFO?=${PREFIX}/info
.endif

HAS_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-spool-dir=${NEWSSPOOL}
CONFIGURE_ARGS+=--prefix=${NEWSLIB}
CONFIGURE_ARGS+=--with-log-dir=${NEWSLOG}
CONFIGURE_ARGS+=--mandir=${NEWSMAN}
CONFIGURE_ARGS+=--infodir=${NEWSINFO}

# tmp- and spool-dir have to live on the same filesystem, to avoid this error:
# "rnews: cant rename /tmp/36d24c3ehN1072
#              to /var/spool/news/incoming/36d24c3eTg1072 Cross-device link"
CONFIGURE_ARGS+=--with-tmp-path=${NEWSSPOOL}/tmp

# Highly recommended, because many of the really good spam filters
# are written in Perl (from the author)
CONFIGURE_ARGS+=--with-perl
# if server has less than 256 MB RAM
CONFIGURE_ARGS+=--enable-tagged-hash
# Do not create static libraries
CONFIGURE_ARGS+=--disable-static

# Most available filters seem to be written in Perl these days,
# so you can safely leave out TCL support (from the author)
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

pre-extract:
	@${ECHO} ">> building inn2 with NEWSSPOOL=${NEWSSPOOL}..."
	@${ECHO} ">> building inn2 with NEWSLIB=${NEWSLIB}..."
	@${ECHO} ">> building inn2 with NEWSLOG=${NEWSLOG}..."
	@${ECHO} ">> building inn2 with NEWSMAN=${NEWSMAN}..."
	@${ECHO} ">> building inn2 with NEWSINFO=${NEWSINFO}..."

pre-install:
.for dir in ${NEWSSPOOL} ${NEWSLIB} ${NEWSLOG} ${NEWSMAN} ${NEWSINFO}
	${MKDIR} ${dir}
	${CHOWN} news:news ${dir}
.endfor

update: build
	@(cd ${WRKSRC} ; ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} update)
	@${MAKE} ${.MAKEFLAGS} compress-man
	@${MAKE} ${.MAKEFLAGS} post-install

post-install:
	${MKDIR} -m 0775 ${NEWSSPOOL}/articles
	${CHOWN} news:news ${NEWSSPOOL}/articles
	${MKDIR} -m 0775 ${NEWSSPOOL}/cycbuffs
	${CHOWN} news:news ${NEWSSPOOL}/cycbuffs
	${MKDIR} -m 0775 ${NEWSSPOOL}/incoming/bad
	${CHOWN} news:news ${NEWSSPOOL}/incoming/bad
	${MKDIR} -m 0775 ${NEWSSPOOL}/innfeed
	${CHOWN} news:news ${NEWSSPOOL}/innfeed
	${MKDIR} -m 0775 ${NEWSSPOOL}/outgoing
	${CHOWN} news:news ${NEWSSPOOL}/outgoing
	${MKDIR} -m 0775 ${NEWSSPOOL}/overview
	${CHOWN} news:news ${NEWSSPOOL}/overview
	${MKDIR} -m 0775 ${NEWSSPOOL}/tmp
	${CHOWN} news:news ${NEWSSPOOL}/tmp
	${MKDIR} -m 0775 ${NEWSSPOOL}/uniover
	${CHOWN} news:news ${NEWSSPOOL}/uniover
	${SED} <${FILESDIR}/innd.sh >${PREFIX}/etc/rc.d/innd.sh \
		s+!!PREFIX!!+${PREFIX}+g && ${CHMOD} +x ${PREFIX}/etc/rc.d/innd.sh
	# make rnews work when getting news via uucp !
	${CHMOD} 4555 ${NEWSLIB}/bin/rnews

.include <bsd.port.mk>
