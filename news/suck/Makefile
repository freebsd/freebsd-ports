# New ports collection makefile for:	suck
# Version required:	2.6.2
# Date created:		30 Mar 1996
# Whom:			graphite@taurus.bekkoame.or.jp
#
# $Id: Makefile,v 1.2 1996/04/07 08:15:23 asami Exp $
#

DISTNAME=	suck-2.6.2
CATEGORIES=	news
MASTER_SITES=	ftp://tsx-11.mit.edu/pub/linux/sources/sbin/ \
		ftp://ftp.iis.u-tokyo.ac.jp/pub2/Linux/sources/sbin/

MAINTAINER=	graphite@taurus.bekkoame.or.jp

USE_GMAKE=	yes
MAN1=		suck.1 rpost.1 testhost.1

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/sample/get.news.innxmit ${PREFIX}/sbin
	${INSTALL_SCRIPT} ${WRKSRC}/sample/get.news.rnews ${PREFIX}/sbin
	${INSTALL_SCRIPT} ${WRKSRC}/sample/put.news ${PREFIX}/bin
	install -c -o bin -g bin -m 640 ${WRKSRC}/sample/*.sample ${PREFIX}/etc

.include <bsd.port.mk>
