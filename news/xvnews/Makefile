# New ports collection makefile for:	xvnews
# Version required:	2.3.2
# Date created:		31 Jul 1996
# Whom:			shanee@augusta.de
#
# $Id: Makefile,v 1.3 1997/10/26 23:57:21 fenner Exp $
#

DISTNAME=	xvnews-2.3.2
CATEGORIES=	news
MASTER_SITES=	${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	applications

MAINTAINER=	shanee@augusta.de

LIB_DEPENDS=	xview\\.3\\.:${PORTSDIR}/x11-toolkits/xview-lib

USE_IMAKE=	yes
NO_INSTALL_MANPAGES=	yes
MAN1=		xvnews.1

post-install:
	${INSTALL_MAN} $(WRKSRC)/xvnews.1 ${PREFIX}/man/man1/

.include <bsd.port.mk>
