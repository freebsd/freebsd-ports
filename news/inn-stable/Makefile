# New ports collection makefile for:	inn
# Date created:		20 Oct 1994 (1.4), 18 Dec 1996 (1.5.1)
# Whom:			torstenb
#
# $FreeBSD$
#

PORTNAME=	inn
SNAPSHOT=	20020104
PORTVERSION=	2.3.${SNAPSHOT}
CATEGORIES=	news
MASTER_SITES=	ftp://ftp.isc.org/isc/inn/snapshots/
DISTNAME=	inn-STABLE-${SNAPSHOT}

MAINTAINER=	des@FreeBSD.org

USE_GMAKE=YES

.if exists(/var/news)
INN_NEWSSPOOL?=/var/news
.elif exists(/var/spool/news)
INN_NEWSSPOOL?=/var/spool/news
.else
INN_NEWSSPOOL?=${PREFIX}/news/spool
.endif
INN_NEWSLOG?=/var/log/news

HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	--mandir=${PREFIX}/man
CONFIGURE_ARGS+=	--prefix=${PREFIX}/news
CONFIGURE_ARGS+=	--with-spool-dir=${INN_NEWSSPOOL}
CONFIGURE_ARGS+=	--with-log-dir=${INN_NEWSLOG}
CONFIGURE_ARGS+=	--with-perl
CONFIGURE_ARGS+=	--with-tmp-path=${INN_NEWSSPOOL}/tmp
CONFIGURE_ARGS+=	--with-largefiles
CONFIGURE_ARGS+=	--with-openssl

# Various Options. See ${WRKSRC}/INSTALL for details

# Use tagged hash table for the history database. Uses much less memory but
# is somewhat slower
#CONFIGURE_ARGS+=	--enable-tagged-hash

MAN1=	ckpasswd.1 convdate.1 fastrm.1 getlist.1 grephistory.1 inews.1 \
	innconfval.1 innfeed.1 innmail.1 nntpget.1 rnews.1 shlock.1 \
	shrinkfile.1 simpleftp.1 startinnfeed.1
MAN3=	clientlib.3 dbz.3 inndcomm.3 libinn.3 libstorage.3 parsedate.3 qio.3 \
	wildmat.3
MAN5=	active.5 buffindexed.conf.5 control.ctl.5 cycbuff.conf.5 \
	distrib.pats.5 expire.ctl.5 history.5 incoming.conf.5 inn.conf.5 \
	innfeed.conf.5 innwatch.ctl.5 moderators.5 motd.news.5 newsfeeds.5 \
	newslog.5 nnrp.access.5 nnrpd.track.5 nntpsend.ctl.5 ovdb.5 \
	overview.fmt.5 passwd.nntp.5 readers.conf.5 sasl.conf.5 \
	storage.conf.5 subscriptions.5
MAN8=	actsync.8 actsyncd.8 archive.8 batcher.8 buffchan.8 cnfsheadconf.8 \
	cnfsstat.8 controlchan.8 ctlinnd.8 cvtbatch.8 dbprocs.8 expire.8 \
	expireover.8 expirerm.8 filechan.8 inncheck.8 innd.8 inndf.8 \
	inndstart.8 innreport.8 innstat.8 innwatch.8 innxbatch.8 innxmit.8 \
	mailpost.8 makedbz.8 makehistory.8 mod-active.8 news.daily.8 \
	news2mail.8 newsrequeue.8 nnrpd.8 nntpsend.8 ovdb_recover.8 \
	ovdb_upgrade.8 overchan.8 pgpverify.8 prunehistory.8 pullnews.8 \
	scanlogs.8 send-uucp.8 sm.8 tally.control.8 writelog.8

EXTRA=	${WRKSRC}/HISTORY ${WRKSRC}/INSTALL ${WRKSRC}/LICENSE

INN_INCLUDES=	clibrary.h config.h configdata.h dbz.h libinn.h storage.h

pre-install:
	${MKDIR} ${INN_NEWSSPOOL}

post-install:
	@${CHOWN} root:news ${PREFIX}/news/bin/auth/passwd/ckpasswd
	@${CHMOD} 4755 ${PREFIX}/news/bin/auth/passwd/ckpasswd
	@(if [ ! -f ${PREFIX}/news/db/history ] ; then \
	    ${ECHO} 'Creating empty history database...' ; \
	    cd ${PREFIX}/news/db ; \
	    ${TOUCH} history ; \
	    ${CHMOD} 644 history ; \
	    ${CHOWN} news:news history ; \
	    su -fm news -c "../bin/makedbz -i" ; \
	    for s in dir hash index ; do \
		${MV} history.n.$${s} history.$${s} ; \
	    done ; \
	fi)
	@${SED} <${FILESDIR}/innd.sh >${PREFIX}/etc/rc.d/innd.sh \
	    s+!!PREFIX!!+${PREFIX}+g && ${CHMOD} +x ${PREFIX}/etc/rc.d/innd.sh
	@${MKDIR} ${PREFIX}/share/doc/inn
	@${INSTALL_DATA} ${EXTRA} ${PREFIX}/share/doc/inn
	@${MKDIR} ${PREFIX}/news/include
.for FILE in ${INN_INCLUDES}
	@${INSTALL_DATA} ${WRKSRC}/include/${FILE} ${PREFIX}/news/include/
.endfor
	@${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
