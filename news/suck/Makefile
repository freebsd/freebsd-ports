# New ports collection makefile for:	suck
# Version required:	3.6.0
# Date created:		30 Mar 1996
# Whom:			graphite@taurus.bekkoame.or.jp
#
# $Id: Makefile,v 1.5 1997/10/05 05:06:19 max Exp $
#

DISTNAME=	suck-3.6.0
CATEGORIES=	news
MASTER_SITES=	ftp://sunsite.unc.edu/pub/Linux/system/news/transport/

MAINTAINER=	jseger@freebsd.org

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
