# New ports collection makefile for:	ntl
# Date created:				18 June 2000
# Whom:					bauerm
#
# $FreeBSD$
#

PORTNAME=	ntl
PORTVERSION=	5.2
CATEGORIES=	math
MASTER_SITES=	http://www.shoup.net/ntl/

MAINTAINER=	matthiasb@acm.org

BUILD_DEPENDS=  libgmp3:${PORTSDIR}/math/libgmp3
RUN_DEPENDS=    libgmp3:${PORTSDIR}/math/libgmp3

USE_GMAKE=	yes
WRKSRC=		${WRKDIR}/${DISTNAME}/src
MAKEFILE=	makefile
HAS_CONFIGURE=	yes
CONFIGURE_ARGS= "GMP_INCDIR=${LOCALBASE}/include" "GMP_LIBDIR=${LOCALBASE}/lib" "GMP_PREFIX=${LOCALBASE}" "NTL_GMP_LIP=on"
MAKE_ARGS=	"DOCDIR=${LOCALBASE}/share/doc GMP_PREFIX=${LOCALBASE}"

do-install:
	${MKDIR} ${PREFIX}/include/NTL
	${INSTALL_DATA} ${WRKSRC}/../include/NTL/*  ${PREFIX}/include/NTL/.
	${INSTALL_DATA} ${WRKSRC}/ntl.a ${PREFIX}/lib/libntl.a
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/NTL
	${INSTALL_DATA} ${WRKSRC}/../doc/* ${PREFIX}/share/doc/NTL/.
.endif

.include <bsd.port.mk>
