# New ports collection makefile for:	cnews
# Version required:	940927
# Date created:		28 September 1994
# Whom:			adam
#
# $Id: Makefile,v 1.16 1996/12/07 01:30:12 adam Exp $
#

DISTNAME=	cnews
PKGNAME=	cnews-cr.g
CATEGORIES=	news
MASTER_SITES=	ftp://ftp.zoo.toronto.edu/pub/
EXTRACT_SUFX=	.tar.Z

WRKSRC=		${WRKDIR}
MAKEFILE=	makefile
MAN1=		checknews.1cn inews.1cn postnews.1cn readnews.1cn
MAN5=		controlperm.5 news.5 newsctl.5 newsdb.5 newsoverview.5 \
		newssys.5
MAN8=		cnewsdo.8cn expire.8cn explode.8cn mergeactive.8 \
		mkhistory.8cn newsaux.8cn newsbatch.8cn newsmail.8cn \
		newsmaint.8cn newsoverview.8 relaynews.8cn report.8cn \
		rnews.8cn

BROKEN=		"Fails while installing bin/inews."

NEWSSPOOL=	${PREFIX}/newsspool
NEWSBIN=	${PREFIX}/news/cnewsbin
NEWSLIB=	${PREFIX}/news/lib
MANDIR=		${PREFIX}/man

do-install:
	rm -f ${PREFIX}/bin/inews
	cp ${WRKSRC}/libdbz/dbz.h ${PREFIX}/include
	cp ${WRKSRC}/libcnews.a ${PREFIX}/lib
	mkdir -p ${NEWSSPOOL}
	-ln -s ${NEWSSPOOL} /var/news
	mkdir -p ${NEWSBIN} ${NEWSLIB}
	chown news.news ${NEWSSPOOL} ${NEWSLIB}
	chown bin.bin ${NEWSBIN}
	cd ${WRKSRC}; \
		echo ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} install | \
		su -m bin
	cd ${WRKSRC}; \
		echo ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} setup | \
		su -m news
	cd ${WRKSRC}; \
		echo ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ui readpostcheck | \
		su -m bin
	chown news.news ${NEWSBIN}/input/newsspool
	chmod 6755 ${NEWSBIN}/input/newsspool
	install -c -o bin -g bin -m 444 ${WRKSRC}/man/*.1* ${MANDIR}/man1
	install -c -o bin -g bin -m 444 ${WRKSRC}/man/*.5* ${MANDIR}/man5
	install -c -o bin -g bin -m 444 ${WRKSRC}/man/*.8* ${MANDIR}/man8
	@echo ""
	@echo "!!!!!!!!"
	@echo "you MUST change the configuration of this news setup:"
	@echo "	cd to ${NEWSLIB} and change the following files..."
	@echo "mailname, whoami, organization, mailpaths, sys, readnews.ctl, postdefltgroup"
	@echo "	to suit your local system and news topology."
	@echo "!!!!!!!!"
	@echo ""

.include <bsd.port.mk>
