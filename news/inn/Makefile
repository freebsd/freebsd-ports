# New ports collection makefile for:	inn
# Version required:	1.7.2
# Date created:		20 Oct 1994 (1.4), 18 Dec 1996 (1.5.1)
# Whom:			torstenb
#
# $Id: Makefile,v 1.29 1998/11/07 08:49:32 hoek Exp $
#

DISTNAME=	inn-1.7.2
CATEGORIES=	news
MASTER_SITES=	ftp://ftp.isc.org/isc/inn/

MAINTAINER=	torstenb@FreeBSD.ORG

Y2K=		http://www.isc.org/y2k.html

# If you want PGP verification of control messages set PGPVERIFY to "DO"
PGPVERIFY?=	DONT

# TCL and/or PERL support is needed for writing filters
# if you want to enable tcl support, set USE_TCL to "DO"
# if you want to enable perl5 support, set USE_PERL5 to "DO"
#USE_TCL?=	DO
#USE_PERL5?=	DO

SCRIPTS_ENV=	PGPVERIFY=${PGPVERIFY} USE_TCL=${USE_TCL} \
		USE_PERL5=${USE_PERL5} PERL_VERSION=${PERL_VERSION}


NO_PACKAGE=	"Too many compile-time options"
MAN1=	convdate.1 getlist.1 grephistory.1 inews.1 innconfval.1 installit.1 \
	nntpget.1 rnews.1 shlock.1 shrinkfile.1 subst.1
MAN3=	clientlib.3 dbz.3 inndcomm.3 libinn.3 parsedate.3 qio.3 wildmat.3
MAN5=	active.5 control.ctl.5 distrib.pats.5 expire.ctl.5 history.5 \
	hosts.nntp.5 inn.conf.5 innwatch.ctl.5 moderators.5 newsfeeds.5 \
	newslog.5 nnrp.access.5 nntpsend.ctl.5 overview.fmt.5 passwd.nntp.5
MAN8=	actsync.8 archive.8 batcher.8 buffchan.8 crosspost.8 ctlinnd.8 \
	cvtbatch.8 expire.8 expireover.8 expirerm.8 fastrm.8 filechan.8 \
	inncheck.8 innd.8 innlog.pl.8 innstat.8 innwatch.8 innxbatch.8 \
	innxmit.8 makeactive.8 makehistory.8 news-recovery.8 nnrpd.8 \
	news.daily.8 newslog.8 newsrequeue.8 nntpsend.8 overchan.8 \
	prunehistory.8 scanlogs.8 tally.control.8 tally.unwanted.8 writelog.8

pre-configure:
	echo "${CFLAGS}" >/tmp/build-ports-news-inn-cflags

pre-install:
	${MKDIR} ${PREFIX}/news
	${MKDIR} -m 0755 ${PREFIX}/news/sbin && \
		chown news.news ${PREFIX}/news/sbin

update: build
	@(cd ${WRKSRC} ; ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} update)
	@${MAKE} ${.MAKEFLAGS} post-install

post-install:
	${INSTALL_DATA} ${WRKSRC}/lib/libinn.a ${PREFIX}/lib/
	${INSTALL_DATA} ${WRKSRC}/include/inndcomm.h ${PREFIX}/include/
	${INSTALL_DATA} ${WRKSRC}/include/libinn.h ${PREFIX}/include/
	${INSTALL_DATA} ${WRKSRC}/include/qio.h ${PREFIX}/include/
	if [ -d /var/spool/news ] && [ ! -d /var/news ]; then \
		${MKDIR} -m 0775 /var/spool/news/over.view; \
		chown news.news /var/spool/news/over.view; \
		${MKDIR} -m 0775 /var/spool/news/tmp; \
		chown news.news /var/spool/news/tmp; \
	else \
		${MKDIR} -m 0775 /var/news/over.view; \
		chown news.news /var/news/over.view; \
		${MKDIR} -m 0775 /var/news/tmp; \
		chown news.news /var/news/tmp; \
	fi
	${MKDIR} ${PREFIX}/news/locks
	chown news.news ${PREFIX}/news/locks
	chmod 0755 ${PREFIX}/news/locks
	${SED} <${FILESDIR}/innd.sh >${PREFIX}/etc/rc.d/innd.sh \
		s+!!PREFIX!!+${PREFIX}+g && chmod +x ${PREFIX}/etc/rc.d/innd.sh

.include <bsd.port.mk>
