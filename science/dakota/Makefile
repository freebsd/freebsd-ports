PORTNAME=	dakota
DISTVERSION=	6.22.0
PORTREVISION=	1
PORTEVISION=	1
CATEGORIES=	science
MASTER_SITES=	https://github.com/snl-dakota/dakota/releases/download/v${DISTVERSION}/
DISTNAME=	${PORTNAME}-${DISTVERSION}-public-src-cli
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Interface between analysis codes & iterative systems analysis methods
WWW=		https://dakota.sandia.gov \
		https://github.com/snl-dakota/dakota

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	nanoflann>0:math/nanoflann
LIB_DEPENDS=	libblas.so:math/blas \
		libboost_program_options.so:devel/boost-libs \
		libexpat.so:textproc/expat2 \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libgsl.so:math/gsl \
		libhdf5.so:science/hdf5 \
		libicui18n.so:devel/icu \
		libkokkoscore.so:devel/kokkos \
		liblapack.so:math/lapack \
		libnlopt.so:math/nlopt \
		libpng16.so:graphics/png \
		libsz.so:science/libaec
RUN_DEPENDS=	bash:shells/bash

USES=		cmake compiler:c++11-lang fortran gettext-runtime jpeg motif perl5 pkgconfig python shebangfix xorg
USE_XORG=	ice sm x11 xau xcb xdmcp xext xft xmu xrender xt
USE_LDCONFIG=	yes

USE_GITHUB=	nodefault
GH_TUPLE=	stan-dev:math:v2.18.0:stanmath/stanmath

SHEBANG_GLOB=	*.sh *.py
SHEBANG_FILES=	interfaces/Python/mpitile \
		scripts/pyprepro/dprepro \
		scripts/pyprepro/pyprepro \
		scripts/dprepro.perl \
		test/dakota_test.perl

CXX=		${FILESDIR}/fake-c++.sh # change to c++14

CMAKE_ON=	HAVE_X_GRAPHICS # always enable graphics because w/out it a lot of unrelated files aren't installed due to bugs in the project
CMAKE_ON+=	Boost_NO_BOOST_CMAKE \
		DAKOTA_GIT_checkout
#CMAKE_ON+=	HAVE_C3 # causes "duplicate include" error
#CMAKE_ON+=	DAKOTA_DL_SOLVER # fails to compile: error: declaration of anonymous class must be a definition
#CMAKE_ON+=	HAVE_NOWPAC # installs files into $PORTSDIR
CMAKE_ON+=	HAVE_QUESO \
		HAVE_MUQ MUQ_USE_PYTHON \
		# enable some methods that aren't enabled by default, see the list @ src/DakotaIterator.cpp
CMAKE_ON+=	DAKOTA_HAVE_GSL DAKOTA_HAVE_HDF5

CMAKE_OFF=	DAKOTA_ENABLE_TESTS
CMAKE_ARGS=	-DDakota_VERSION_SRC:STRING=${DISTVERSION} -DDakota_GIT_REVL:STRING=unknown -DDakota_RELEASE_DATE:${STRING}=20211115 \
		-DPython_EXECUTABLE=${PYTHON_CMD} \
		-DMUQ_STANMATH_DIR=${WRKSRC}/stanmath \
		-DPython_EXECUTABLE=${PYTHON_CMD}

CFLAGS+=	-DH5_USE_110_API=1
FFLAGS+=	-fallow-argument-mismatch
LDFLAGS+=	-lexecinfo

CONFLICTS_BUILD=	dakota # self: picks up some bundled packages from the pre-installed dakota package and then fails to install them

MAKE_ARGS=	VERBOSE=1

post-extract:
	@${FIND} ${WRKSRC} -name "*.orig" -delete
	@${ECHO} ${DISTVERSION} > ${WRKSRC}/VERSION # expected by the 'install' target

post-patch:
	@${REINPLACE_CMD} -e 's| Boost::system||' \
		${WRKSRC}/cmake/DakotaFindSystemTPLs.cmake \
		${WRKSRC}/src/surrogates/unit/CMakeLists.txt

pre-configure: # MUQ_STANMATH_DIR is lost otherwise
	@${REINPLACE_CMD} 's|find_package(PkgConfig)|set(MUQ_STANMATH_DIR ${WRKSRC}/stanmath)|' ${WRKSRC}/packages/external/muq2/cmake/finds/FindSTANMATH.cmake

post-install:
	# remove eigen3 that Dakota installs, see https://github.com/snl-dakota/dakota/issues/182
	@cd ${STAGEDIR}${PREFIX} && \
		${RM} -r include/eigen3 share/eigen3

do-test: install # from Additional Test Suites @ https://dakota.sandia.gov/content/additional-test-suites (many tests are known to fail)
	## minimal set of fast-running tests that should NOT FAIL (may DIFF, depending on platform / compiler)
	cd ${WRKSRC}/test && ./dakota_test.perl
	## test suite that should PASS on any supported platform (NO DIFF or FAIL)
	#cd ${WRKSRC}/test && ./dakota_test.perl --label-regex=AcceptanceTest
	## run all Dakota tests active in this build (should PASS or DIFF)
	#cd ${WRKSRC}/test && ./dakota_test.perl --label-regex=dakota_
	# Tests should be this way, but this fails:
	#@cd ${BUILD_WRKSRC} && \
		${SETENV} ${CONFIGURE_ENV} ${CMAKE_BIN} ${CMAKE_ARGS} -DDAKOTA_ENABLE_TESTS:BOOL=ON ${CMAKE_SOURCE_PATH} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} ${ALL_TARGET} && \
		(cd ${WRKSRC} && ctest -j 4 -L FastTest -LE Diff)

.include <bsd.port.mk>
