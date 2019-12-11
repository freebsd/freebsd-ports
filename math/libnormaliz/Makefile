# $FreeBSD$

PORTNAME=		libnormaliz
DISTVERSIONPREFIX=	v
DISTVERSION=		3.8.3
PORTREVISION=		1
CATEGORIES=		math

MAINTAINER=	phascolarctos@protonmail.ch
COMMENT=	Computations in affin monoids, vector configurations etc

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${LOCALBASE}/include/boost/dynamic_bitset.hpp:devel/boost-libs \
		${LOCALBASE}/include/gmpxx.h:math/gmp

USES=		autoreconf compiler:c++11-lang gmake libtool
USE_GITHUB=	yes

GH_ACCOUNT=	Normaliz
GH_PROJECT=	Normaliz

BUILD_WRKSRC=	${WRKSRC}/source/libnormaliz
INSTALL_WRKSRC=	${WRKSRC}/source/libnormaliz

CXXFLAGS+=	-I ${LOCALBASE}/include \
		-I ${WRKSRC}/source
MAKEFILE=	Makefile.classic
GNU_CONFIGURE=	yes
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_DEFINE=		COCOA DOCS FLINT OPENMP
COCOA_DESC=		Link with libcocoa.a (might cause circular dependency)
COCOA_BUILD_DEPENDS=	${LOCALBASE}/lib/libcocoa.a:math/cocoalib
COCOA_CONFIGURE_ENABLE=	nmzintegrate
FLINT_DESC=		Link with libflint.so
FLINT_BUILD_DEPENDS=	${LOCALBASE}/lib/libflint.so:math/flint2
FLINT_CONFIGURE_ENABLE=	flint
FLINT_LDFLAGS=		-lpthread
OPENMP_BUILD_DEPENDS=	${LOCALBASE}/lib/libomp.so:devel/openmp
OPENMP_CONFIGURE_ENABLE=	openmp

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/include/libnormaliz
	${INSTALL_DATA}	${INSTALL_WRKSRC}/libnormaliz.a ${STAGEDIR}${PREFIX}/lib
	cd ${INSTALL_WRKSRC} && ${INSTALL_DATA} cone.h cone_property.h convert.h general.h HilbertSeries.h integer.h libnormaliz.h map_operations.h matrix.h my_omp.h normaliz_exception.h sublattice_representation.h vector_operations.h version.h nmz_integrate.h ${STAGEDIR}${PREFIX}/include/libnormaliz

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/doc/Normaliz.pdf ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
