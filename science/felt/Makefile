# New ports collection makefile for:	FElt
# Date created:		19 October 1996
# Whom:			Pedro Giffuni
#
# $FreeBSD$
#

PORTNAME=	felt
PORTVERSION=	3.05
CATEGORIES=	cad
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		http://symphony.clarku.edu/atkinson/felt/Binaries/ \
		ftp://ftp.isd.uni-stuttgart.de/pub/src/FEM/FElt/
MASTER_SITE_SUBDIR=	FElt
EXTRACT_SUFX=	.src.tar.gz

MAINTAINER=	giffunip@asme.org

LIB_DEPENDS=	Xaw3d.${XAWVER}:${PORTSDIR}/x11-toolkits/Xaw3d

WRKSRC=		${WRKDIR}/FElt-${PORTVERSION}
GNU_CONFIGURE=	yes
USE_X_PREFIX=	yes

MAN1=		burlap.1 corduroy.1 felt.1 patchwork.1 velvet.1 yardstick.1
MAN3=		Drawing.3
MAN4=		corduroy.4 felt.4

post-install:
	${MKDIR} ${PREFIX}/share/examples/FElt
	${CP} ${WRKSRC}/examples/* ${PREFIX}/share/examples/FElt
	${MKDIR} ${PREFIX}/share/doc/FElt
	${CP} ${WRKSRC}/*.html ${PREFIX}/share/doc/FElt

.include <bsd.port.mk>
