# New ports collection makefile for:	suck
# Version required:	2.6.2
# Date created:		30 Mar 1996
# Whom:			graphite@taurus.bekkoame.or.jp
#
# $Id: Makefile,v 1.1.1.1 1996/03/31 23:19:18 asami Exp $
#

DISTNAME=	suck-2.6.2
CATEGORIES+=	news
MASTER_SITES=	ftp://tsx-11.mit.edu/pub/linux/sources/sbin/ \
		ftp://ftp.iis.u-tokyo.ac.jp/pub2/Linux/sources/sbin/

MAINTAINER=	graphite@taurus.bekkoame.or.jp

USE_GMAKE=	yes

post-install:
	install -c -o bin -g bin -m 755 ${WRKSRC}/sample/get.news.innxmit ${PREFIX}/sbin
	install -c -o bin -g bin -m 755 ${WRKSRC}/sample/get.news.rnews ${PREFIX}/sbin
	install -c -o bin -g bin -m 755 ${WRKSRC}/sample/put.news ${PREFIX}/bin
	install -c -o bin -g bin -m 640 ${WRKSRC}/sample/*.sample ${PREFIX}/etc
.if !defined(NOMANCOMPRESS)
	gzip -9nf ${PREFIX}/man/man1/suck.1
	gzip -9nf ${PREFIX}/man/man1/rpost.1
	gzip -9nf ${PREFIX}/man/man1/testhost.1
.endif

.include <bsd.port.mk>
