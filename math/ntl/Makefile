# New ports collection makefile for:	ntl
# Date created:				18 June 2000
# Whom:					bauerm
#
# $FreeBSD$
#

PORTNAME=	ntl
PORTVERSION=	5.4
CATEGORIES=	math
MASTER_SITES=	http://www.shoup.net/ntl/

MAINTAINER=	matthiasb@acm.org
COMMENT=	Victor Shoup's Number Theory Library

# ntl is faster with libgmp4, but you can disable it
.if !defined(WITHOUT_GMP)
LIB_DEPENDS=	gmp.6:${PORTSDIR}/math/libgmp4
.endif

USE_PERL5_BUILD=	yes
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS}" \
		CXX="${CXX}" CXXFLAGS="${CXXFLAGS}" NTL_STD_CXX=on

.if !defined(WITHOUT_GMP)
CONFIGURE_ARGS+=	NTL_GMP_LIP=on GMP_PREFIX="${LOCALBASE}"
.endif

CONFIGURE_WRKSRC=	${BUILD_WRKSRC}

BUILD_WRKSRC=	${WRKSRC}/src
MAKEFILE=	makefile

do-install:
	${MKDIR} ${PREFIX}/include/NTL
	${INSTALL_DATA} ${WRKSRC}/include/NTL/*  ${PREFIX}/include/NTL/
	${INSTALL_DATA} ${BUILD_WRKSRC}/ntl.a ${PREFIX}/lib/libntl.a

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/* ${DOCSDIR}
.endif

.include <bsd.port.mk>
