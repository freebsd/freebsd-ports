# New ports collection makefile for:	suck
# Version required:	2.6.1
# Date created:		30 Mar 1996
# Whom:			graphite@taurus.bekkoame.or.jp
#
# $Id$
#

DISTNAME=	suck-2.6.1
CATEGORIES+=	news
MASTER_SITES=	ftp://sunsite.unc.edu/pub/Linux/system/Mail/news/ \
		ftp://tsx-11.mit.edu/pub/linux/sources/sbin/

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
