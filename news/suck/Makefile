# New ports collection makefile for:	suck
# Version required:	3.5.2
# Date created:		30 Mar 1996
# Whom:			graphite@taurus.bekkoame.or.jp
#
# $Id: Makefile,v 1.3 1996/11/18 11:38:13 asami Exp $
#

DISTNAME=	suck-3.5.2
CATEGORIES=	news
MASTER_SITES=	ftp://tsx-11.mit.edu/pub/linux/sources/sbin/ \
		ftp://ftp.iis.u-tokyo.ac.jp/pub2/Linux/sources/sbin/

MAINTAINER=	jseger@scds.com

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
MAN1=		suck.1 rpost.1 testhost.1 lmove.1 lpost.1

post-install:
	${MKDIR} ${PREFIX}/share/examples/suck
	${INSTALL_SCRIPT} ${WRKSRC}/sample/get.news.innxmit ${PREFIX}/share/examples/suck
	${INSTALL_SCRIPT} ${WRKSRC}/sample/get.news.rnews ${PREFIX}/share/examples/suck
	${INSTALL_SCRIPT} ${WRKSRC}/sample/put.news ${PREFIX}/share/examples/suck
	${INSTALL_DATA} ${WRKSRC}/sample/*.sample ${PREFIX}/share/examples/suck

.include <bsd.port.mk>
