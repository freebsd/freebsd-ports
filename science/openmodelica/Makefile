PORTNAME=	openmodelica
DISTVERSIONPREFIX=	v
DISTVERSION=	1.20.0
PORTREVISION=	2
CATEGORIES=	science cad java
MASTER_SITES=	https://build.openmodelica.org/omc/bootstrap/:bootstrap
DISTFILES=	sources.tar.gz:bootstrap
DIST_SUBDIR=	${PORTNAME}-${PORTVERSION}

PATCH_SITES=	https://github.com/${PORTNAME}/${PORTNAME}/commit/
PATCHFILES=	01b6764df51f4f097d1c2e093e945ebd9a2f15a3.patch:-p1 # backport of https://github.com/OpenModelica/OpenModelica/pull/10261

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Modelica-based modeling and simulation environment
WWW=		https://openmodelica.org/

LICENSE=	OSMC-PL
LICENSE_NAME=	Public license for OpenModelica
LICENSE_TEXT=	See https://github.com/OpenModelica/OpenModelica/blob/master/OSMC-License.txt
LICENSE_PERMS=	auto-accept dist-mirror dist-sell pkg-mirror pkg-sell

BROKEN_aarch64=	link fails: /usr/local/bin/ld: cannot find -lquadmath: No such file or directory
BROKEN_i386=	compilation fails: /wrkdirs/usr/ports/science/openmodelica/work/OpenModelica-1.20.0/OMCompiler/3rdParty/libffi/src/x86/sysv.S:841:1: error: changed section flags for .eh_frame, expected: 0x2

BUILD_DEPENDS=	asciidoc:textproc/asciidoc \
		autoconf>0:devel/autoconf \
		automake:devel/automake \
		gmake:devel/gmake \
		libtool>0:devel/libtool \
		${LOCALBASE}/include/readline/readline.h:devel/readline
LIB_DEPENDS=	libboost_filesystem.so:devel/boost-libs \
		libcurl.so:ftp/curl \
		libosg.so:graphics/osg \
		libuuid.so:misc/e2fsprogs-libuuid
RUN_DEPENDS=	bash:shells/bash \
		gmake:devel/gmake

USES=		cmake compiler:c++14-lang dos2unix iconv fortran gettext-runtime gl gnome blaslapack localbase:ldflags qt:5 pkgconfig python:build shebangfix
USE_QT=		concurrent core gui network opengl printsupport svg webkit widgets xml xmlpatterns buildtools:build qmake:build
USE_GL=		gl opengl
USE_GNOME=	libxml2
USE_JAVA=	yes
USE_LDCONFIG=	${PREFIX}/lib/omc ${PREFIX}/lib/omc/OMSimulator ${PREFIX}/lib/omc/cpp ${PREFIX}/lib/omc/ffi # https://github.com/OpenModelica/OpenModelica/issues/9925

USE_GITHUB=	yes
GH_ACCOUNT=	OpenModelica
GH_PROJECT=	OpenModelica

DOS2UNIX_FILES=	OMSimulator/OMTLMSimulator/3rdParty/Makefile \
		OMCompiler/3rdParty/FMIL/ThirdParty/Expat/expat-2.1.0/CMakeLists.txt

SHEBANG_GLOB=	*.sh *.in *.ac
SHEBANG_FILES=	OMSimulator/OMTLMSimulator/OMFMISimulatorWrapper/StartTLMOMFMISimulatorWrapper \
		OMSimulator/OMTLMSimulator/Hopsan/StartTLMHopsan \
		OMSimulator/testsuite/tlm/StartTLMFmiWrapper \
		OMSimulator/OMTLMSimulator/FMIWrapper/StartTLMFmiWrapper \
		OMSimulator/OMTLMSimulator/OpenModelica/StartTLMOpenModelica

GH_TUPLE=	\
		OpenModelica:OMOptim:4116ef7:OMOptim/OMOptim \
			OpenModelica:OpenModelica-common:08a0180:OMOptim_common/OMOptim/common \
		OpenModelica:OMSimulator:af996ad:OMSimulator/OMSimulator \
			OpenModelica:OMSimulator-3rdParty:6202ca1:OMSimulator_3rdParty/OMSimulator/3rdParty \
			OpenModelica:OMTLMSimulator:07d5353:OMSimulator_OMTLMSimulator/OMSimulator/OMTLMSimulator \
		OpenModelica:OMCompiler-3rdParty:a60ba6c:OMCompiler_3rdParty/OMCompiler/3rdParty \
		OpenModelica:OMSens:66b920b:OMSens/OMSens \
		OpenModelica:OMSens_Qt:ef85128:OMSens_Qt/OMSens_Qt
			#OpenModelica:OpenModelica-common:08a0180:OMSens_Qt_common/OMSens_Qt/common

# this should change make program everywhere, but it doesn't,
# hence the patches in OMCompiler/Compiler/runtime/CMakeLists.txt, OMEdit/OMEditLIB/Simulation/SimulationOutputWidget.cpp
CMAKE_ARGS=	-DCMAKE_MAKE_PROGRAM=gmake \
		-DPython_EXECUTABLE=${PYTHON_CMD}

CMAKE_ARGS+=	-DOM_USE_CCACHE:BOOL=${CCACHE_ENABLED:S/yes/ON/:S/no/OFF/} # if refuses to build w/out ccache by default

LDFLAGS+=	-lexecinfo -lintl -pthread

BINARY_ALIAS=	make=${GMAKE} gcc=${FILESDIR}/gcc.sh git=false

CONFLICTS_BUILD=	sundials

post-extract:
	# remove stray *.orig files
	@${FIND} ${WRKSRC} -name "*.orig" -delete
	# remove rtime that isn't used on FreeBSD
	@${RM} -r ${WRKSRC}/OMSimulator/OMTLMSimulator/3rdParty/rtime
	# create symlink for sources.tar.gz
	@${MKDIR} ${WRKSRC}/OMCompiler/Compiler/boot/bomc
	@${LN} -s ${DISTDIR}/${DIST_SUBDIR}/sources.tar.gz ${WRKSRC}/OMCompiler/Compiler/boot/bomc/sources.tar.gz
	# workaround for broken fetch
	@${RLN} ${WRKSRC}/OMOptim/common ${WRKSRC}/OMSens_Qt/common

post-patch:
	# fix bash shebangs
	@${REINPLACE_CMD} -e 's|#!/bin/bash|#!${LOCALBASE}/bin/bash|' \
		${WRKSRC}/OMCompiler/Examples/GenerateDoc.mos \
		${WRKSRC}/OMCompiler/3rdParty/tbb/build/generate_tbbvars.sh
	# add path to libgfortran to link flags for OM internal builds
	@${REINPLACE_CMD} \
		-e 's|@RT_LDFLAGS_GENERATED_CODE_SIM@|& -L${LOCALBASE}/lib/gcc${FC:S/gfortran//}|' \
		${WRKSRC}/OMCompiler/Compiler/Util/Autoconf.mo.in

post-install:
	# workaround for https://github.com/OpenModelica/OpenModelica/issues/9919
	cd ${STAGEDIR}${PREFIX} && ${CHMOD} +x \
		bin/OMSimulator bin/OMSimulatorPython3 bin/StartTLMFmiWrapper
	# remove unnecessary files
	${RM} -r \
		${STAGEDIR}${PREFIX}/share/zmq \
		${STAGEDIR}${PREFIX}/doc \
		${STAGEDIR}${PREFIX}/share/doc
	# remove empty directories
	${FIND} ${STAGEDIR}${PREFIX}/include -type d -empty -delete
	# strip binaries
	cd ${STAGEDIR}${PREFIX} && ${STRIP_CMD} \
		bin/OMSimulator bin/FMIWrapper \
		lib/omc/OMSimulator/libomtlmsimulator.so lib/omc/OMSimulator/libOMSimulator.so \
		lib/omc/libomtlmsimulator.so lib/omc/libOMSimulator.so

.include <bsd.port.mk>
