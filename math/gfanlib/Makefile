# Created by: Lorenzo Salvadore
# $FreeBSD$

PORTNAME=	gfanlib
DISTVERSION=	0.6.2
CATEGORIES=	math
MASTER_SITES=	http://home.math.au.dk/jensen/software/gfan/
DISTNAME=	gfan${DISTVERSION}

MAINTAINER=	phascolarctos@protonmail.ch
COMMENT=	Static library for computing Groebner fans and tropical varieties

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${LOCALBASE}/include/cdd/cdd.h:math/cddlib
LIB_DEPENDS=	libgmp.so:math/gmp

USES=		compiler:c++11-lang gmake localbase

GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include/cdd

CONFIGURE_WRKSRC=	${WRKSRC}/gfanlib
BUILD_WRKSRC=		${WRKSRC}/gfanlib

pre-configure:
	for x in ${WRKSRC}/src/gfanlib*; do ${MV} $$x ${WRKSRC}/gfanlib; done
# this is not supported yet, see ${WRKSRC}/Makefile: gfanlib_tableau.h
# is commented in GFANLIBFILES' declaration
	${RM} ${WRKSRC}/gfanlib/gfanlib_tableau.h

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/include/gfanlib
	${INSTALL_DATA} ${WRKSRC}/gfanlib/gfanlib*.h \
		${STAGEDIR}${PREFIX}/include/gfanlib
	${INSTALL_DATA} ${WRKSRC}/gfanlib/libgfan.a \
		${STAGEDIR}${PREFIX}/lib/libgfan.a

.include <bsd.port.mk>
