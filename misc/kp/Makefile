# New ports collection makefile for:    kp
# Version required:     1.00
# Date created:         8 May 1995
# Whom:                 asami
#
# $Id: Makefile,v 1.11 1998/10/09 01:14:42 asami Exp $
#

DISTNAME=       kp-1.00
CATEGORIES=	misc
MASTER_SITES=   ftp://stampede.cs.berkeley.edu/pub/kp/

MAINTAINER=	asami@FreeBSD.org

REQUIRES_MOTIF=	yes
USE_IMAKE=	yes
MAN1=		kp.1

post-install:
	${MKDIR} ${PREFIX}/share/kp/xmodmaps
	cd ${WRKSRC}; ${INSTALL_DATA} COPYRIGHT README ${PREFIX}/share/kp
	cd ${WRKSRC}/xmodmaps; ${INSTALL_DATA} * ${PREFIX}/share/kp/xmodmaps

.include <bsd.port.mk>
