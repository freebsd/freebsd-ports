# New ports collection makefile for:	FElt
# Version required:	 3.01
# Date created:		19 October 1996
# Whom:			
#
# $Id: Makefile,v 1.1.1.1 1997/01/15 07:19:43 tg Exp $
#

DISTNAME=	felt-3.01
CATEGORIES=	cad
MASTER_SITES=	http://www-cse.ucsd.edu/users/atkinson/FElt/Binaries/ \
		ftp://lucy.ifi.unibas.ch/unix/general/
EXTRACT_SUFX=	.src.tar.gz

MAINTAINER=	pgiffuni@FPS.biblos.unal.edu.co

WRKSRC=		${WRKDIR}/FElt-3.00
GNU_CONFIGURE=	yes
MAN1=		burlap.1 corduroy.1 felt.1 patchwork.1 velvet.1 yardstick.1
MAN3=		Drawing.3
MAN4=		corduroy.4 felt.4

#DOCS= 		ftp://cs.ucsd.edu/pub/felt/felt-3.00.ps.gz

post-patch:
	rm -f $(WRKSRC)/lib/Geompack/*.c

.include <bsd.port.mk>
