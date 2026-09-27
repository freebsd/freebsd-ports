PORTNAME=	apbs
DISTVERSIONPREFIX=	v
DISTVERSION=	3.4.1
CATEGORIES=	science

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Electrostatic and solvation properties for complex molecules
WWW=		https://www.poissonboltzmann.org/ \
		https://github.com/Electrostatics/apbs

LICENSE=	MIT

LIB_DEPENDS=	libumfpack.so:math/suitesparse-umfpack \
		libarpack.so:math/arpack-ng \
		libsuperlu.so:math/superlu

USES=		cmake shebangfix gettext-runtime
SHEBANG_FILES=	${WRKSRC}/tools/github/getReleases.sh \
		${WRKSRC}/examples/run_examples.sh \
		${WRKSRC}/examples/run_selected_examples.sh \
		${WRKSRC}/examples/protein-rna/postprocess.sh \
		${WRKSRC}/examples/protein-rna/run_apdx_files.sh \
		${WRKSRC}/examples/ion-pmf/runme.sh \
		${WRKSRC}/examples/helix/Run_membrane-helix.sh \
		${WRKSRC}/examples/point-pmf/runme.sh

USE_GITHUB=	yes
GH_ACCOUNT=	Electrostatics
GH_PROJECT=	apbs
GH_TUPLE=	Electrostatics:FETK:57195e55351e04ce6ee0ef56a143c996a9aee7e2:fetk/externals/fetk \
		Electrostatics:geoflow_c:e8ce510:geoflow_c/externals/geoflow_c \
		Electrostatics:TABIPB:de187a4:bem/externals/bem \
		lwwilson1:mesh_routines:ddb75cb:mr/externals/mesh_routines \
		Electrostatics:pb_solvers:168a83e:ps/externals/pb_s_am
USE_LDCONFIG=	yes

CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_ARGS+=	-DAPBS_STATIC_BUILD=OFF \
		-DENABLE_TESTS=OFF

# Fix build on recent current with clang11
CFLAGS+=	-fcommon

# FETK's mc component includes <umfpack.h> but does not add the SuiteSparse
# include directory found by its own FindUMFPACK.
CFLAGS+=	-I${LOCALBASE}/include/suitesparse

post-extract:
	@${CP} ${FILESDIR}/FindSuiteSparse.cmake ${WRKSRC}/cmake/

do-test: # run one example as a test to verify the build
	@cd ${WRKSRC}/examples/born && \
		${STAGEDIR}${PREFIX}/bin/apbs apbs-mol-auto.in

.include <bsd.port.mk>
