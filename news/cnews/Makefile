# New ports collection makefile for:	cnews
# Version required:	940927
# Date created:		28 September 1994
# Whom:			adam
#
# $Id: Makefile,v 1.3 1995/04/01 12:49:06 jkh Exp $
#

DISTNAME=	cnews
PKGNAME=	cnews-cr.e
CATEGORIES+=	news
MASTER_SITES=	ftp://ftp.zoo.toronto.edu/pub/
EXTRACT_SUFX=	.tar.Z

WRKSRC=		${WRKDIR}
MAKEFILE=	makefile

NEWSSPOOL=	/usr/local/newsspool
NEWSBIN=	/usr/local/libexec/news
NEWSLIB=	/usr/local/lib/news
MANDIR=		/usr/local/man

install: all
	@echo "===>  installing for ${DISTNAME}"
	mkdir -p ${NEWSSPOOL}
	ln -s ${NEWSSPOOL} /var/news
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
	mkdir -p ${MANDIR}/man1 ${MANDIR}/man5 ${MANDIR}/man8
	install -o bin -g bin -m 444 ${WRKSRC}/man/*.1* ${MANDIR}/man1
	install -o bin -g bin -m 444 ${WRKSRC}/man/*.5* ${MANDIR}/man5
	install -o bin -g bin -m 444 ${WRKSRC}/man/*.8* ${MANDIR}/man8
	@echo ""
	@echo "!!!!!!!!"
	@echo "you MUST change the configuration of this news setup:"
	@echo "	cd to ${NEWSLIB} and change the following files..."
	@echo "mailname, whoami, organization, mailpaths, sys, readnews.ctl, postdefltgroup"
	@echo "	to suit your local system and news topology."
	@echo "!!!!!!!!"
	@echo ""

.include <bsd.port.mk>
