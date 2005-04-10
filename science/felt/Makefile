# New ports collection makefile for:	FElt
# Date created:		19 October 1996
# Whom:			Pedro Giffuni
#
# $FreeBSD$
#

PORTNAME=	felt
PORTVERSION=	3.06
CATEGORIES=	science
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	felt
EXTRACT_SUFX=	-devel.src.tar.gz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A system for Finite Element Analysis

LIB_DEPENDS=	Xaw3d:${PORTSDIR}/x11-toolkits/Xaw3d \
		Xm.3:${PORTSDIR}/x11-toolkits/open-motif

USE_X_PREFIX=	yes
USE_GL=		yes
USE_REINPLACE=	yes
WRKSRC=		${WRKDIR}/FElt-${PORTVERSION}
GNU_CONFIGURE=	yes

MAN1=		burlap.1 corduroy.1 felt.1 patchwork.1 velvet.1 yardstick.1
MAN3=		Drawing.3
MAN4=		corduroy.4 felt.4

post-patch:
	@${REINPLACE_CMD} -e 's,<malloc.h>,<stdlib.h>, ; s,"malloc.h",<stdlib.h>,' \
	${WRKSRC}/lib/Felt/parser.c \
	${WRKSRC}/lib/Widgets/xwd.c ${WRKSRC}/lib/Matrix/data.c	\
	${WRKSRC}/lib/Matrix/factor.c ${WRKSRC}/lib/Matrix/eigen.c \
	${WRKSRC}/lib/Matrix/c_data.c ${WRKSRC}/lib/Matrix/c_factor.c \
	${WRKSRC}/src/Velvet/error.c \
	${WRKSRC}/src/Burlap/interactive.c \
	${WRKSRC}/src/Burlap/parser.c \
	${WRKSRC}/src/Corduroy/parser.c	\
	${WRKSRC}/src/Patchwork/util.c

post-install:
	${MKDIR} ${PREFIX}/share/examples/FElt
	${CP} ${WRKSRC}/examples/* ${PREFIX}/share/examples/FElt
	${MKDIR} ${PREFIX}/share/doc/FElt
	${CP} ${WRKSRC}/*.html ${PREFIX}/share/doc/FElt

.include <bsd.port.mk>
