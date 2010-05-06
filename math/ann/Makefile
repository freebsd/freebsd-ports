# New ports collection makefile for:	ann
# Date created:		2010-04-23
# Whom:			Tz-Huan Huang <tzhuan@csie.org>
#
# $FreeBSD$
#

PORTNAME=	ann
PORTVERSION=	1.1.2
CATEGORIES=	math science
MASTER_SITES=	http://www.cs.umd.edu/~mount/ANN/Files/1.1.2/
DISTNAME=	ann_1.1.2

MAINTAINER=	tzhuan@csie.org
COMMENT=	A Library for Approximate Nearest Neighbor Searching

WRKSRC=		${WRKDIR}/ann_1.1.2
USE_LDCONFIG=	yes
USE_GMAKE=	yes

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/lib/libann.so.0 ${PREFIX}/lib
	${INSTALL_PROGRAM} ${WRKSRC}/lib/libann.a ${PREFIX}/lib
	${LN} -fs libann.so.0 ${PREFIX}/lib/libann.so
	${MKDIR} ${PREFIX}/include/ANN
	${INSTALL_DATA} ${WRKSRC}/include/ANN/* ${PREFIX}/include/ANN
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/ANNmanual.pdf ${DOCSDIR}

.include <bsd.port.mk>
