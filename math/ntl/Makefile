# New ports collection makefile for:	ntl
# Date created:				18 June 2000
# Whom:					bauerm
#
# $FreeBSD$
#

PORTNAME=	ntl
PORTVERSION=	5.3
CATEGORIES=	math
MASTER_SITES=	http://www.shoup.net/ntl/

MAINTAINER=	matthiasb@acm.org

LIB_DEPENDS=	gmp.6:${PORTSDIR}/math/libgmp4

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS}" \
		CXX="${CXX}" CXXFLAGS="${CXXFLAGS}" \
		NTL_GMP_LIP=on GMP_PREFIX="${LOCALBASE}"
CONFIGURE_WRKSRC= ${BUILD_WRKSRC}

BUILD_WRKSRC=	${WRKSRC}/src
MAKEFILE=	makefile

# Build with WITH_ISO_CXX=yes if you want to use the "Standard C++"
# version of NTL. In this version, all of NTL is "wrapped" inside
# the namespace NTL, and are no longer directly accessible---you must
# either use explicit qualification, or using directives, or
# using declarations.

.if defined(WITH_ISO_CXX)
CONFIGURE_ARGS+= NTL_STD_CXX=on
.endif

do-install:
	${MKDIR} ${PREFIX}/include/NTL
	${INSTALL_DATA} ${WRKSRC}/include/NTL/*  ${PREFIX}/include/NTL/
	${INSTALL_DATA} ${BUILD_WRKSRC}/ntl.a ${PREFIX}/lib/libntl.a
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/NTL
	${INSTALL_DATA} ${WRKSRC}/doc/* ${PREFIX}/share/doc/NTL/
.endif

.include <bsd.port.mk>
