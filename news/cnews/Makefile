# New ports collection makefile for:	cnews
# Version required:	940927
# Date created:		28 September 1994
# Whom:			adam
#
# $Id: Makefile,v 1.18 1998/08/30 15:45:29 steve Exp $
#

DISTNAME=	c-news
PKGNAME=	cnews-cr.g
CATEGORIES=	news
MASTER_SITES=	ftp://ftp.cs.toronto.edu/pub/c-news/ \
		ftp://ftp.funet.fi/pub/unix/news/cnews/ \
		ftp://ftp.win.or.jp/pub/network/news/cnews/ \
		ftp://ftp.redcom.ru/pub/unix/usenet/c-news/ \
		ftp://ftp.mc.hik.se/pub/unix/news/c-news/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	ports@FreeBSD.ORG

NO_WRKSUBDIR=	yes
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
MANDIR=		${PREFIX}/man

do-install:
	${RM} -f ${PREFIX}/bin/inews
	${INSTALL_DATA} ${WRKSRC}/libdbz/dbz.h ${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/libcnews.a ${PREFIX}/lib
	${MKDIR} ${NEWSSPOOL} ${NEWSBIN} ${NEWSLIB}
	-ln -s ${NEWSSPOOL} /var/news
	chown news.news ${NEWSSPOOL} ${NEWSLIB}
	chown bin.bin ${NEWSBIN}
	cd ${WRKSRC}; ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} install
	cd ${WRKSRC}; ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} setup
	cd ${WRKSRC}; ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ui readpostcheck
.for f in checknews cnewsdo inews injnews postnews readnews
	chown bin.bin ${PREFIX}/bin/$f
.endfor
	chown news.news ${NEWSBIN}/input/newsspool
	chmod 6755 ${NEWSBIN}/input/newsspool
	${INSTALL_MAN} ${WRKSRC}/man/*.1* ${MANDIR}/man1
	${INSTALL_MAN} ${WRKSRC}/man/*.5* ${MANDIR}/man5
	${INSTALL_MAN} ${WRKSRC}/man/*.8* ${MANDIR}/man8
	@${ECHO} ""
	@${ECHO} "!!!!!!!!"
	@${ECHO} "you MUST change the configuration of this news setup:"
	@${ECHO} "	cd to ${NEWSLIB} and change the following files..."
	@${ECHO} "mailname, whoami, organization, mailpaths, sys, readnews.ctl, postdefltgroup"
	@${ECHO} "	to suit your local system and news topology."
	@${ECHO} "!!!!!!!!"
	@${ECHO} ""

.include <bsd.port.mk>
