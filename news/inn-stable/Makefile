# New ports collection makefile for:	inn
# Version required:	1.4
# Date created:		20 Oct 1994
# Whom:			torstenb
#
# $Id: Makefile,v 1.19 1996/12/08 01:45:08 max Exp $
#

DISTNAME=	inn1.4sec
PKGNAME=	inn-1.4
CATEGORIES=	news
MASTER_SITES=	ftp://ftp.uu.net/networking/news/nntp/inn/
EXTRACT_SUFX=	.tar.Z

PATCH_SITES=	ftp://ftp.math.psu.edu/pub/INN/patches/OLD/
PATCHFILES=	select-loop-bug.patch innxmit-long-lines.patch

MAINTAINER=	torstenb@FreeBSD.ORG

NO_PACKAGE=	"Too many compile-time options"
NO_WRKSUBDIR=	yes
MAN1=	convdate.1 getlist.1 grephistory.1 inews.1 innconfval.1 installit.1 \
	nntpget.1 rnews.1 shlock.1 shrinkfile.1 subst.1 
MAN3=	clientlib.3 ddbz.3 inndcomm.3 libinn.3 parsedate.3 qio.3 wildmat.3 
MAN5=	active.5 control.ctl.5 expire.ctl.5 history.5 hosts.nntp.5 \
	inn.conf.5 innwatch.ctl.5 moderators.5 newsfeeds.5 newslog.5 \
	nnrp.access.5 nntpsend.ctl.5 overview.fmt.5 distrib.pats.5 \
	passwd.nntp.5 
MAN8=	archive.8 batcher.8 buffchan.8 ctlinnd.8 cvtbatch.8 expire.8 
	expireover.8 fastrm.8 filechan.8 innd.8 innxmit.8 news-recovery.8 \
	news.daily.8 newslog.8 nnrpd.8 nntpsend.8 overchan.8 prunehistory.8

pre-configure:
	echo "${CFLAGS}" >/tmp/build-ports-news-inn-cflags

pre-install:
	${MKDIR} ${PREFIX}/news

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
	else \
		${MKDIR} -m 0775 /var/news/over.view; \
		chown news.news /var/news/over.view; \
	fi
	${MKDIR} ${PREFIX}/news/locks
	chown news.news ${PREFIX}/news/locks
	chmod 0755 ${PREFIX}/news/locks

.include <bsd.port.mk>
