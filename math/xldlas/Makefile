# New ports collection makefile for:	xldlas
# Version required:	0.85
# Date created:         20 Dec 97
# Whom:                 Pedro Giffuni <giffunip@asme.org>
#
# $Id: Makefile,v 1.5 1998/09/26 23:18:07 steve Exp $
#

DISTNAME=	xldlas-0.85
CATEGORIES=	math
MASTER_SITES=	http://a42.com/~thor/xldlas/			\
		http://sunsite.math.klte.hu/mirrors/xldlas/	\
		${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	apps/graphics/visualization
EXTRACT_SUFX=	-source.tgz

MAINTAINER=	giffunip@asme.org

LIB_DEPENDS=	xforms.0:${PORTSDIR}/x11-toolkits/xforms

WRKSRC=		${WRKDIR}/xldlas

USE_X_PREFIX=	yes

MAN1=	xldlas.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xldlas ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/xldlas.1 ${PREFIX}/man/man1
	${MKDIR} ${PREFIX}/share/xldlas
	${CP} -R ${WRKSRC}/help ${PREFIX}/share/xldlas

.include <bsd.port.mk>
