# New ports collection makefile for:	FElt
# Version required:	3.02
# Date created:		19 October 1996
# Whom:			Pedro Giffuni
#
# $Id: Makefile,v 1.11 1998/12/26 06:29:19 flathill Exp $
#

DISTNAME=	felt-3.02
CATEGORIES=	cad
MASTER_SITES=	http://www-cse.ucsd.edu/users/atkinson/FElt/Binaries/ \
		ftp://ftp.isd.uni-stuttgart.de/pub/src/FEM/FElt/
EXTRACT_SUFX=	.src.tar.gz

MAINTAINER=	giffunip@asme.org

LIB_DEPENDS=	Xaw3d.6:${PORTSDIR}/x11-toolkits/Xaw3d

WRKSRC=		${WRKDIR}/FElt-3.02
GNU_CONFIGURE=	yes
USE_X_PREFIX=	yes

MAN1=		burlap.1 corduroy.1 felt.1 patchwork.1 velvet.1 yardstick.1
MAN3=		Drawing.3
MAN4=		corduroy.4 felt.4

post-patch:
	${RM} -f ${WRKSRC}/lib/Geompack/*.c

post-install:
	${MKDIR} ${PREFIX}/share/examples/FElt
	${CP} ${WRKSRC}/examples/* ${PREFIX}/share/examples/FElt
	${MKDIR} ${PREFIX}/share/doc/FElt
	${CP} ${WRKSRC}/*.html ${PREFIX}/share/doc/FElt

.include <bsd.port.mk>
