# New ports collection makefile for:	suck
# Version required:	3.9.1
# Date created:		30 Mar 1996
# Whom:			graphite@taurus.bekkoame.or.jp
#
# $Id: Makefile,v 1.10 1998/02/18 05:15:17 steve Exp $
#

DISTNAME=	suck-3.9.1
CATEGORIES=	news
MASTER_SITES=	http://home.att.net/~bobyetman/

MAINTAINER=	jseger@FreeBSD.org

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
MAN1=		suck.1 rpost.1 testhost.1 lmove.1

post-install:
	${MKDIR} ${PREFIX}/share/examples/suck
	${INSTALL_SCRIPT} ${WRKSRC}/sample/get.news.innxmit ${PREFIX}/share/examples/suck
	${INSTALL_SCRIPT} ${WRKSRC}/sample/get.news.rnews ${PREFIX}/share/examples/suck
	${INSTALL_SCRIPT} ${WRKSRC}/sample/put.news ${PREFIX}/share/examples/suck
	${INSTALL_DATA} ${WRKSRC}/sample/*.sample ${PREFIX}/share/examples/suck

.include <bsd.port.mk>
