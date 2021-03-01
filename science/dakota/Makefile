# $FreeBSD$

PORTNAME=	dakota
DISTVERSION=	6.13.0
PORTREVISION=	2
CATEGORIES=	science
MASTER_SITES=	https://dakota.sandia.gov/sites/default/files/distributions/public/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Interface between analysis codes & iterative systems analysis methods

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libblas.so:math/blas \
		libboost_system.so:devel/boost-libs \
		liblapack.so:math/lapack
RUN_DEPENDS=	bash:shells/bash

USES=		cmake compiler:c++11-lang fortran perl5 python shebangfix
USE_LDCONFIG=	yes

SHEBANG_GLOB=	*.sh *.py
SHEBANG_FILES=	interfaces/Python/mpitile \
		scripts/pyprepro/dprepro \
		scripts/pyprepro/pyprepro \
		scripts/dprepro.perl \
		test/dakota_test.perl

CMAKE_ON=	Boost_NO_BOOST_CMAKE \
		DAKOTA_GIT_checkout
#CMAKE_ON+=	HAVE_C3 # causes "duplicate include" error
#CMAKE_ON+=	DAKOTA_DL_SOLVER # fails to compile: error: declaration of anonymous class must be a definition
#CMAKE_ON+=	HAVE_NOWPAC # installs files into $PORTSDIR
CMAKE_ON+=	HAVE_DREAM HAVE_ADAPTIVE_SAMPLING HAVE_OPTPP DAKOTA_HOPS HAVE_ACRO \
		HAVE_JEGA HAVE_NOMAD HAVE_NPSOL HAVE_NL2SOL HAVE_DOT HAVE_SURFPACK \
		HAVE_CONMIN HAVE_DDACE HAVE_FSUDACE HAVE_PSUADE HAVE_ROL HAVE_DEMO_TPL # enable some methods that aren't enabled by default, see the list @ src/DakotaIterator.cpp

CMAKE_OFF=	DAKOTA_ENABLE_TESTS
CMAKE_ARGS=	-DDakota_VERSION_SRC:STRING=${DISTVERSION} -DDakota_GIT_REVL:STRING=${GIT_HASH} -DDakota_RELEASE_DATE:${STRING}=20201116

FFLAGS+=	-fallow-argument-mismatch
LDFLAGS+=	-lexecinfo

CONFLICTS_BUILD=	dakota # self: picks up some bundled packages from the pre-installed dakota package and then fails to install them
CONFLICTS_INSTALL=	openblas

USES_GIT=	no
GIT_URL=	https://software.sandia.gov/git/dakota
GIT_HASH=	82fd55ea1c6bb6d32e4c68e7f92d991d658ba90a

.if ${USES_GIT} == "yes"
FETCH_DEPENDS=	git:devel/git
do-fetch:
	@if [ "${FORCE_FETCH_ALL}" = "true" ] || ! [ -f "${DISTDIR}/${DIST_SUBDIR}/${DISTNAME}${EXTRACT_SUFX}" ]; then \
	  ${MKDIR} ${DISTDIR}/${DIST_SUBDIR} && \
	  cd ${DISTDIR}/${DIST_SUBDIR} && \
	    git clone -q ${GIT_URL} ${PORTNAME}-${DISTVERSIONFULL} && \
	    (cd ${PORTNAME}-${DISTVERSIONFULL} && \
	      git checkout devel && \
	      git submodule init packages/external && \
	      git submodule init packages/pecos && \
	      git submodule init packages/surfpack && \
	      git submodule update) && \
	    (cd ${PORTNAME}-${DISTVERSIONFULL} && git reset -q --hard ${GIT_HASH} && ${RM} -r .git) && \
	    ${FIND} ${PORTNAME}-${DISTVERSIONFULL} -and -exec ${TOUCH} -h -d 1970-01-01T00:00:00Z {} \; && \
	    ${FIND} ${PORTNAME}-${DISTVERSIONFULL} -print0 | LC_ALL=C ${SORT} -z | \
	        ${TAR} czf ${PORTNAME}-${DISTVERSIONFULL}${EXTRACT_SUFX} --format=bsdtar --gid 0 --uid 0 --options gzip:!timestamp --no-recursion --null -T - && \
	    ${RM} -r ${PORTNAME}-${DISTVERSIONFULL}; \
	fi
.else
DISTNAME=	${PORTNAME}-${DISTVERSION}-release-public.src-UI
.endif

OPTIONS_DEFINE=		GSL GUI HDF5
OPTIONS_DEFAULT=	GSL HDF5
OPTIONS_SUB=		yes

GSL_DESC=		GSL support
GSL_CMAKE_BOOL=		DAKOTA_HAVE_GSL HAVE_QUESO HAVE_QUESO_GPMSA # QUESO requires GSL
GSL_LIB_DEPENDS=	libgsl.so:math/gsl

HDF5_CMAKE_BOOL=	DAKOTA_HAVE_HDF5 \
			HAVE_MUQ # MUQ module requires HDF5
HDF5_LIB_DEPENDS=	libhdf5.so:science/hdf5 \
			libsz.so:science/szip

GUI_DESC=		Build the Dakota/Motif Graphics package
GUI_CMAKE_BOOL=		HAVE_X_GRAPHICS
GUI_BROKEN=		error: non-void function 'SciPlotListReturnPtr' should return a value

post-extract:
	@${FIND} ${WRKSRC} -name "*.orig" -delete
	@${ECHO} ${DISTVERSION} > ${WRKSRC}/VERSION # expected by the 'install' target

post-install:
	# remove eigen3 that Dakota installs
	cd ${STAGEDIR}${PREFIX} && ${RM} -r include/eigen3 share/eigen3
	# install libraries that it fails to install
.for l in libmuqUtilities.so libmuqModeling.so libmuqSamplingAlgorithms.so
	${INSTALL_LIB} ${BUILD_WRKSRC}/packages/external/muq2/lib/${l} ${STAGEDIR}${PREFIX}/lib
.endfor

do-test: # from Additional Test Suites @ https://dakota.sandia.gov/content/additional-test-suites (many tests are known to fail)
	## minimal set of fast-running tests that should NOT FAIL (may DIFF, depending on platform / compiler)
	#cd ${WRKSRC}/test && ./dakota_test.perl
	## test suite that should PASS on any supported platform (NO DIFF or FAIL)
	#cd ${WRKSRC}/test && ./dakota_test.perl --label-regex=AcceptanceTest
	## run all Dakota tests active in this build (should PASS or DIFF)
	#cd ${WRKSRC}/test && ./dakota_test.perl --label-regex=dakota_
	# Tests should be this way, but this fails:
	@cd ${BUILD_WRKSRC} && \
		${SETENV} ${CONFIGURE_ENV} ${CMAKE_BIN} ${CMAKE_ARGS} -DDAKOTA_ENABLE_TESTS:BOOL=ON ${CMAKE_SOURCE_PATH} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} ${ALL_TARGET} && \
		(cd ${WRKSRC} && ctest -j 4 -L FastTest -LE Diff)

.include <bsd.port.mk>
