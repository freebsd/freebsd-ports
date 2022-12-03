PORTNAME=	polyclipper
DISTVERSIONPREFIX=	v
DISTVERSION=	1.2.3-2
DISTVERSIONSUFFIX=	-g2a727eb
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Library to clip polygons (in 2D) and polyhedra (in 3D) by planes
WWW=		https://github.com/LLNL/PolyClipper

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake

USE_GITHUB=	yes
GH_ACCOUNT=	LLNL
GH_PROJECT=	PolyClipper
GH_TUPLE=	llnl:blt:0ae6bd2:blt/cmake/blt \
		jmikeowen:PYB11Generator:f351df2:cmake/PYB11Generator

CMAKE_ON=	ENABLE_CXXONLY # otherwise it looks for python2
CMAKE_OFF=	BUILD_TESTING

NO_BUILD=	yes
NO_ARCH=	yes

do-test:
.for f in test_array_vector_2d.cc test_array_vector_3d.cc
	@${ECHO} "==> testing $f"
	@cd ${WRKSRC}/test/test_array_vector && \
		${CXX} ${CXXFLAGS} ${LDFLAGS} -o ${f}.bin ${f} -I${STAGEDIR}${PREFIX}/include && \
		./${f}.bin
.endfor

.include <bsd.port.mk>
