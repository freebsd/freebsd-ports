# New ports collection makefile for:    mgdiff
# Version required:     		1.0
# Date created:         		22 October 1996
# Whom:                 		andreas@marvin.robin.de
#
# $Id: Makefile,v 1.3 1997/04/11 09:39:54 obrien Exp $
#

DISTNAME=	mgdiff
PKGNAME=	mgdiff-1.0
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	applications

MAINTAINER=	andreas@marvin.robin.de

REQUIRES_MOTIF=	yes
USE_IMAKE=      yes

post-install:
	@${MKDIR} ${PREFIX}/lib/X11/mgdiff
	@${INSTALL_DATA} ${WRKSRC}/mgdiff.x[bp]m ${PREFIX}/lib/X11/mgdiff
	@${CAT} ${PKGDIR}/MESSAGE

.include <bsd.port.mk>
