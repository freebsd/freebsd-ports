# New ports collection makefile for:	ntl
# Date created:				18 June 2000
# Whom:					bauerm
#
# $FreeBSD$
#

PORTNAME=	ntl
PORTVERSION=	5.0c
CATEGORIES=	math
MASTER_SITES=	http://www.shoup.net/ntl/

MAINTAINER=	matthiasb@acm.org

USE_GMAKE=	yes
WRKSRC=		${WRKDIR}/${DISTNAME}/src
MAKEFILE=	makefile
HAS_CONFIGURE=	yes
MAKE_ARGS=	"DOCDIR=${LOCALBASE}/share/doc"

do-install:
	${MKDIR} ${PREFIX}/include/NTL
	${INSTALL_DATA} ${WRKSRC}/../include/NTL/*  ${PREFIX}/include/NTL/.
	${INSTALL_DATA} ${WRKSRC}/ntl.a ${PREFIX}/lib/libntl.a
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/NTL
	${INSTALL_DATA} ${WRKSRC}/../doc/* ${PREFIX}/share/doc/NTL/.
.endif

.include <bsd.port.mk>
