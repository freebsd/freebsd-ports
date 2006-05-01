# New ports collection makefile for:	inn
# Date created:		20 Oct 1994 (1.4), 18 Dec 1996 (1.5.1), 14 Feb 1999 (2.2)
# Whom:			torstenb
#
# $FreeBSD$
#

PORTNAME=	inn
PORTVERSION=	${SNAPSHOT}
CATEGORIES=	news ipv6
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=clement
PKGNAMESUFFIX=	-${BRANCH}
DISTNAME=	${PORTNAME}-${BRANCH:U}-${SNAPSHOT}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	InterNetNews -- the Internet meets Netnews

BRANCH=		stable
SNAPSHOT=	20040707

NO_LATEST_LINK=	yes
USE_GMAKE=	yes
USE_PERL5=	yes
USE_OPENSSL=	yes

CONFLICTS=	inn-2.4.0* inn-current-*

.if exists(/var/news) && !defined(PACKAGE_BUILDING)
INN_NEWSSPOOL?=/var/news
.elif exists(/var/spool/news) && !defined(PACKAGE_BUILDING)
INN_NEWSSPOOL?=/var/spool/news
.else
INN_NEWSSPOOL?=${PREFIX}/news/spool
.endif
INN_NEWSLOG?=/var/log/news

HAS_CONFIGURE=		yes
CONFIGURE_ENV+=		LOCALBASE=${LOCALBASE}
CONFIGURE_ARGS+=	--mandir=${PREFIX}/man \
			--prefix=${PREFIX}/news \
			--with-spool-dir=${INN_NEWSSPOOL} \
			--with-log-dir=${INN_NEWSLOG} \
			--with-perl \
			--with-tmp-dir=${INN_NEWSSPOOL}/tmp \
			--with-openssl=${OPENSSLBASE} \
			--enable-ipv6 \
			--with-etc-dir=${ETC_DIR}

.if defined(WITH_BERKELEYDB)
.    if !defined(WITH_BDB_VER)
WITH_BDB_VER=	42
.    endif
.    if (${WITH_BDB_VER} == 3) || (${WITH_BDB_VER} == 4) || (${WITH_BDB_VER} == 41)
LIB_DEPENDS+=		db${WITH_BDB_VER}:${PORTSDIR}/databases/db${WITH_BDB_VER}
.elif (${WITH_BDB_VER} == 42)
LIB_DEPENDS+=		db-4.2:${PORTSDIR}/databases/db42
.    elif ${WITH_BDB_VER} == 2
IGNORE=		"Does not compile with db2"
.    else
IGNORE=		"Unknown BerkeleyDB version"
.    endif
CONFIGURE_ENV+=		DB_VER=db${WITH_BDB_VER}
CONFIGURE_ARGS+=	--with-berkeleydb
.endif

.if defined(WITH_PYTHON)
USE_PYTHON=		YES
CONFIGURE_ARGS+=	--with-python
.endif

.if defined(WITH_TCL)
USE_REINPLACE=		yes
CONFIGURE_ARGS+=	--with-tcl=${LOCALBASE}
BUILD_DEPENDS+=		${LOCALBASE}/include/tcl8.3/tcl.h:${PORTSDIR}/lang/tcl83
.endif

.if defined (WITH_MAXSOCKET)
CONFIGURE_ARGS+=	--with-max-sockets=${WITH_MAXSOCKET}
.endif

.if defined(WITH_KEYWORDS)
CONFIGURE_ARGS+=	--enable-keywords
.endif

.if defined(WITH_SASL)
CONFIGURE_ARGS+=	--with-sasl=${LOCALBASE}
LIB_DEPENDS+=		sasl2:${PORTSDIR}/security/cyrus-sasl2
.endif

.if defined(WITH_TAGGED_HASH)
CONFIGURE_ARGS+=	--enable-tagged-hash
DBZ_FILES=		dir pag
PLIST_SUB=		SUB_WITH_TAGGED_HASH=""
PLIST_SUB+=		SUB_WITHOUT_TAGGED_HASH="@comment "
.else
CONFIGURE_ARGS+=	--enable-largefiles
DBZ_FILES=		dir hash index
PLIST_SUB=		SUB_WITH_TAGGED_HASH="@comment "
PLIST_SUB+=		SUB_WITHOUT_TAGGED_HASH=""
.endif

EXTRA=		CONTRIBUTORS HACKING INSTALL LICENSE MANIFEST NEWS README TODO
HEADERS=	clibrary.h config.h dbz.h libinn.h storage.h

MAN1=	convdate.1 fastrm.1 getlist.1 grephistory.1 inews.1 innconfval.1 \
	innfeed.1 innmail.1 nntpget.1 pgpverify.1 rnews.1 shlock.1 \
	shrinkfile.1 simpleftp.1 sm.1 startinnfeed.1
MAN3=	clientlib.3 dbz.3 inndcomm.3 libauth.3 libinn.3 libinnhist.3 \
	libstorage.3 list.3 parsedate.3 qio.3 tst.3 uwildmat.3
MAN5=	active.5 active.times.5 buffindexed.conf.5 control.ctl.5 \
	cycbuff.conf.5 distrib.pats.5 expire.ctl.5 history.5 incoming.conf.5 \
	inn.conf.5 innfeed.conf.5 innwatch.ctl.5 moderators.5 motd.news.5 \
	newsfeeds.5 newslog.5 nnrpd.track.5 nntpsend.ctl.5 ovdb.5 \
	overview.fmt.5 passwd.nntp.5 radius.conf.5 readers.conf.5 \
	sasl.conf.5 storage.conf.5 subscriptions.5
MAN8=	actsync.8 actsyncd.8 archive.8 auth_smb.8 batcher.8 buffchan.8 \
	ckpasswd.8 cnfsheadconf.8 cnfsstat.8 controlchan.8 ctlinnd.8 \
	cvtbatch.8 domain.8 expire.8 expireover.8 expirerm.8 filechan.8 \
	ident.8 inncheck.8 innd.8 inndf.8 inndstart.8 innreport.8 innstat.8 \
	innupgrade.8 innwatch.8 innxbatch.8 innxmit.8 mailpost.8 makedbz.8 \
	makehistory.8 mod-active.8 news.daily.8 news2mail.8 ninpaths.8 \
	nnrpd.8 nntpsend.8 ovdb_init.8 ovdb_monitor.8 ovdb_server.8 \
	ovdb_stat.8 overchan.8 perl-nocem.8 prunehistory.8 pullnews.8 \
	radius.8 rc.news.8 scanlogs.8 send-nntp.8 send-uucp.8 sendinpaths.8 \
	tally.control.8 tdx-util.8 writelog.8

TO_BE_STRIPPED=	bin/auth/resolv/domain bin/auth/resolv/ident bin/auth/passwd/auth_smb \
		bin/auth/passwd/ckpasswd bin/auth/passwd/radius bin/rnews.libexec/decode \
		bin/rnews.libexec/encode bin/tdx-util bin/innd bin/inndstart bin/nnrpd \
		bin/innfeed bin/startinnfeed bin/imapfeed bin/convdate bin/expire \
		bin/expireover bin/fastrm bin/grephistory bin/makedbz bin/makehistory \
		bin/prunehistory bin/ctlinnd bin/getlist bin/inews bin/innconfval \
		bin/ovdb_init bin/ovdb_monitor bin/ovdb_server bin/ovdb_stat bin/rnews \
		bin/sm bin/actsync bin/archive bin/batcher bin/buffchan bin/cvtbatch \
		bin/filechan bin/inndf bin/innxmit bin/innxbatch bin/ninpaths bin/nntpget \
		bin/overchan bin/shlock bin/shrinkfile

.include <bsd.port.pre.mk>

.if defined(WITH_STANDARD_ETC)
ETC_DIR=	${PREFIX}/etc/inn
PLIST_SUB+=	ETCDIR="etc/inn"
.else
ETC_DIR=	${PREFIX}/news/etc
PLIST_SUB+=	ETCDIR=news/etc
.endif

post-patch:
.if defined(WITH_TCL)
	@${REINPLACE_CMD} -e 's!<tcl.h>!<tcl8.3/tcl.h>!' ${WRKSRC}/innd/innd.h
	@${REINPLACE_CMD} -e 's!-ltcl!-ltcl83!' ${WRKSRC}/configure
.endif

post-install:
.if !defined(WITHOUT_STRIP)
.for FILE in ${TO_BE_STRIPPED}
	${STRIP_CMD} ${PREFIX}/news/${FILE}
.endfor
.endif
	${CHOWN} root:wheel ${PREFIX}/man ${PREFIX}/man/man1 ${PREFIX}/man/man3 \
		${PREFIX}/man/man5 ${PREFIX}/man/man8
	${MKDIR} ${INN_NEWSSPOOL}
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for FILE in ${EXTRA}
	${INSTALL_DATA} ${WRKSRC}/${FILE} ${DOCSDIR}
.endfor
.endif
	${MKDIR} ${PREFIX}/news/include
.for FILE in ${HEADERS}
	${INSTALL_DATA} ${WRKSRC}/include/${FILE} ${PREFIX}/news/include/
.endfor
	@${SED} <${FILESDIR}/innd.sh >${PREFIX}/etc/rc.d/innd.sh \
	    s+!!PREFIX!!+${PREFIX}+g && ${CHMOD} +x ${PREFIX}/etc/rc.d/innd.sh
	@${CHOWN} root:news ${PREFIX}/news/bin/auth/passwd/ckpasswd
	@${CHMOD} 4755 ${PREFIX}/news/bin/auth/passwd/ckpasswd
	@PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} CHECK-CONF ${ETC_DIR}
	@(if [ ! -f ${PREFIX}/news/db/history ] ; then \
	    ${ECHO} 'Creating empty history database...' ; \
	    cd ${PREFIX}/news/db ; \
	    ${TOUCH} history ; \
	    ${CHMOD} 644 history ; \
	    ${CHOWN} news:news history ; \
	    su -fm news -c "../bin/makedbz -i" ; \
	    for s in ${DBZ_FILES}  ; do \
		${MV} history.n.$${s} history.$${s} ; \
	    done ; \
	fi)
	@${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.post.mk>
