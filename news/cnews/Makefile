# New ports collection makefile for:	cnews
# Version required:	940927
# Date created:		28 September 1994
# Whom:			adam
#
# $Id: Makefile,v 1.19 1998/12/17 21:54:51 jseger Exp $
#

DISTNAME=	c-news
PKGNAME=	cnews-cr.g
CATEGORIES=	news
MASTER_SITES=	ftp://ftp.cs.toronto.edu/pub/c-news/ \
		ftp://ftp.funet.fi/pub/unix/news/cnews/ \
		ftp://ftp.win.or.jp/pub/network/news/cnews/ \
		ftp://ftp.redcom.ru/pub/unix/usenet/c-news/ \
		ftp://ftp.mc.hik.se/pub/unix/news/c-news/ \
		ftp://ftp.dinoex.org/pub/c-news/
EXTRACT_SUFX=	.tar.Z
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		pgpverify-1.11

PATCH_SITES=    ftp://ftp.dinoex.org/pub/c-news/
PATCHFILES=     c-news-patch-fileart.c c-news-patch-namecheck.awk \
		c-news-patch-newsrun c-news-patch-sendbatches \
		c-news-patch-ctl-pgp3 c-news-patch-ctl-more \
		c-news-patch-ctl-regexp \
		c-news-patch-doexpire c-news-patch-queuelen.tay \
		c-news-patch-bunzip2 \
		c-news-patch-ctl-underscore \
		c-news-patch-pgpverify-1.11

MAINTAINER=	dirk.meyer@dinoex.sub.org

DIST_SUBDIR=	c-news
NO_WRKSUBDIR=	yes
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}
MAKEFILE=	makefile
MAN1=		checknews.1cn inews.1cn postnews.1cn readnews.1cn
MAN5=		controlperm.5 news.5 newsctl.5 newsdb.5 newsoverview.5 \
		newssys.5
MAN8=		cnewsdo.8cn expire.8cn explode.8cn mergeactive.8 \
		mkhistory.8cn newsaux.8cn newsbatch.8cn newsmail.8cn \
		newsmaint.8cn newsoverview.8 relaynews.8cn report.8cn \
		rnews.8cn

NEWSSPOOL=	${PREFIX}/newsspool
NEWSBIN=	${PREFIX}/news/cnewsbin
NEWSLIB=	${PREFIX}/news/lib
PGPVERIFY=	pgpverify-1.11

pre-patch:
	@${CP} ${DISTDIR}/${DIST_SUBDIR}/${PGPVERIFY} ${WRKSRC}/${PGPVERIFY}

do-install:
	${RM} -f ${PREFIX}/bin/inews
	${INSTALL_DATA} ${WRKSRC}/libdbz/dbz.h ${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/libcnews.a ${PREFIX}/lib
	${MKDIR} ${NEWSSPOOL} ${NEWSBIN} ${NEWSLIB}
	-ln -s ${NEWSSPOOL} /var/news
	chown news.news ${NEWSSPOOL} ${NEWSLIB}
	chown bin.bin ${NEWSBIN}
	${INSTALL_SCRIPT} ${WRKSRC}/${PGPVERIFY} ${NEWSBIN}/pgpverify
	cd ${WRKSRC}; ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} install
	cd ${WRKSRC}; ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} setup
	cd ${WRKSRC}; ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ui readpostcheck
.for f in checknews cnewsdo inews injnews postnews readnews
	chown bin.bin ${PREFIX}/bin/$f
.endfor
	chown news.news ${NEWSBIN}/input/newsspool
	chmod 6755 ${NEWSBIN}/input/newsspool
.for i in ${MAN1}
	${INSTALL_MAN} ${WRKSRC}/man/${i} ${PREFIX}/man/man1
.endfor
.for i in ${MAN5}
	${INSTALL_MAN} ${WRKSRC}/man/${i} ${PREFIX}/man/man5
.endfor
.for i in ${MAN8}
	${INSTALL_MAN} ${WRKSRC}/man/${i} ${PREFIX}/man/man8
.endfor
	@${ECHO} ""
	@${ECHO} "!!!!!!!!"
	@${ECHO} "you MUST change the configuration of this news setup:"
	@${ECHO} "	cd to ${NEWSLIB} and change the following files..."
	@${ECHO} "mailname, whoami, organization, mailpaths, sys, readnews.ctl, postdefltgroup"
	@${ECHO} "	to suit your local system and news topology."
	@${ECHO} "!!!!!!!!"
	@${ECHO} ""

.include <bsd.port.mk>
