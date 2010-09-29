# New ports collection makefile for:	ntl
# Date created:				18 June 2000
# Whom:					bauerm
#
# $FreeBSD$
#

PORTNAME=	ntl
PORTVERSION=	5.5.2
PORTREVISION=	2
CATEGORIES=	math
MASTER_SITES=	http://www.shoup.net/ntl/

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Victor Shoup's Number Theory Library

# ntl is faster with libgmp4, but you can disable it
.if !defined(WITHOUT_GMP)
LIB_DEPENDS=	gmp.10:${PORTSDIR}/math/gmp

CONFIGURE_ARGS=	NTL_GMP_LIP=on
.endif

USE_PERL5_BUILD=	yes
HAS_CONFIGURE=	yes
CONFIGURE_ARGS+=	AR="${AR}" \
		CC="${CC}" CFLAGS="${CFLAGS}" \
		CXX="${CXX}" CXXFLAGS="${CXXFLAGS}" \
		DEF_PREFIX="${LOCALBASE}" \
		LDFLAGS="${LDFLAGS}" NTL_STD_CXX=on \
		PREFIX="${PREFIX}" RANLIB="${RANLIB}"

CFLAGS+=	-fPIC
WRKSRC=		${WRKDIR}/${DISTNAME}/src
MAKEFILE=	makefile

do-install:
	${MKDIR} ${PREFIX}/include/NTL
	${INSTALL_DATA} ${WRKSRC}/../include/NTL/*  ${PREFIX}/include/NTL/
	${INSTALL_DATA} ${WRKSRC}/ntl.a ${PREFIX}/lib/libntl.a

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/../doc/* ${DOCSDIR}
.endif

test: build
	@(cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${MAKE} \
		${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} check)

.include <bsd.port.mk>
