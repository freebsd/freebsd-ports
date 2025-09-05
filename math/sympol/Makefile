PORTNAME=	sympol
DISTVERSIONPREFIX=	v
DISTVERSION=	0.1.9
PORTREVISION=	15
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C++ library and tool to work with symmetric polyhedra
WWW=		https://www.math.uni-rostock.de/~rehn/software/sympol.html

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	permlib>0:math/permlib
LIB_DEPENDS=	libbliss.so:math/bliss \
		libboost_program_options.so:devel/boost-libs \
		libcddgmp.so:math/cddlib \
		libgmp.so:math/gmp

USES=		cmake:testing compiler:c++11-lang eigen:3 localbase:ldflags perl5 shebangfix
USE_CXXSTD=	c++14
USE_PERL5=	test
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	tremlin
GH_PROJECT=	SymPol

SHEBANG_GLOB=	*.pl

CMAKE_ARGS=		-DBLISS_INCLUDE_DIR=${LOCALBASE}/include/bliss
CMAKE_TESTING_ON=	BUILD_TESTS # test 'perltest' fails with 'output format mismatch', see https://github.com/tremlin/SymPol/issues/1

post-install:
	@${RM} ${STAGEDIR}${PREFIX}/lib/libcddgmp.so
	# fix incorrect subdirectories in #include statements, see https://github.com/tremlin/SymPol/issues/2
	@${REINPLACE_CMD} -i '' -e 's|#include "yal/|#include "|' ${STAGEDIR}${PREFIX}/include/sympol/*.h
	@${REINPLACE_CMD} -i '' -e 's|#include "\.\./matrix/|#include "|' ${STAGEDIR}${PREFIX}/include/sympol/*.h
	@${REINPLACE_CMD} -i '' -e 's|#include "\.\./|#include "|' ${STAGEDIR}${PREFIX}/include/sympol/*.h

pre-test: # correct the build directory path
	@${REINPLACE_CMD} -e "s|'\\.\\./build/release'|'${BUILD_WRKSRC}'|" ${WRKSRC}/contrib/test-sympol.pl

.include <bsd.port.mk>
