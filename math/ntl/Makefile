# New ports collection makefile for:	ntl
# Date created:				18 June 2000
# Whom:					bauerm
#
# $FreeBSD$
#

PORTNAME=	ntl
PORTVERSION=	4.1a
CATEGORIES=	math
MASTER_SITES=	http://www.shoup.net/ntl/

MAINTAINER=	matthiasb@acm.org

USE_GMAKE=	yes
WRKSRC=		${WRKDIR}/${DISTNAME}/src
NO_BUILD=	yes
MAKEFILE=	makefile

post-install:
	${MKDIR} ${PREFIX}/include/NTL
	${INSTALL_DATA} ${WRKSRC}/../include/NTL/*  ${PREFIX}/include/NTL/.
	${INSTALL_DATA} ${WRKSRC}/ntl.a ${PREFIX}/lib/libntl.a
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/ntl
	${INSTALL_DATA} ${WRKSRC}/../doc/* ${PREFIX}/share/doc/ntl/.
.endif

.include <bsd.port.mk>
