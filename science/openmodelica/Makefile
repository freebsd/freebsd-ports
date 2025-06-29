PORTNAME=	openmodelica
DISTVERSIONPREFIX=	v
DISTVERSION=	1.25.1
PORTREVISION=	1
CATEGORIES=	science cad java
DIST_SUBDIR=	${PORTNAME}-${PORTVERSION}

#PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
#PATCHFILES=	6f8126fcd491d8c4d8b8c643bf0b6abd3a1f23f5.patch:-p1 # https://github.com/OpenModelica/OpenModelica/pull/13683

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Modelica-based modeling and simulation environment
WWW=		https://openmodelica.org/ \
		https://github.com/OpenModelica/OpenModelica

LICENSE=	OSMC-PL
LICENSE_NAME=	Public license for OpenModelica
LICENSE_TEXT=	See https://github.com/OpenModelica/OpenModelica/blob/master/OSMC-License.txt
LICENSE_PERMS=	auto-accept dist-mirror dist-sell pkg-mirror pkg-sell

BROKEN_aarch64=	compilation fails: gcc13 doesn't install libquadmath.so, see https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=285692
BROKEN_armv7=	link fails: ld: cannot find -lquadmath: No such file or directory
BROKEN_i386=	compilation fails: /wrkdirs/usr/ports/science/openmodelica/work/OpenModelica-1.20.0/OMCompiler/3rdParty/libffi/src/x86/sysv.S:841:1: error: changed section flags for .eh_frame, expected: 0x2

BUILD_DEPENDS=	asciidoc:textproc/asciidoc \
		autoconf>0:devel/autoconf \
		automake:devel/automake \
		gmake:devel/gmake \
		libtool>0:devel/libtool \
		${LOCALBASE}/include/readline/readline.h:devel/readline \
		sundials>0:math/sundials
LIB_DEPENDS=	libboost_filesystem.so:devel/boost-libs \
		libcurl.so:ftp/curl \
		libicuuc.so:devel/icu \
		libosg.so:graphics/osg \
		libuuid.so:misc/libuuid
RUN_DEPENDS=	bash:shells/bash \
		gmake:devel/gmake

USES=		cmake compiler:c++14-lang iconv fortran gettext-runtime gl \
		gnome blaslapack localbase:ldflags qt:5 readline pkgconfig \
		python:build shebangfix java
USE_QT=		concurrent core declarative gui location network opengl \
		printsupport svg webchannel webengine widgets xml xmlpatterns \
		buildtools:build linguisttools:build qmake:build
USE_GL=		gl opengl
USE_GNOME=	libxml2
USE_LDCONFIG=	${PREFIX}/lib/omc ${PREFIX}/lib/omc/OMSimulator ${PREFIX}/lib/omc/cpp ${PREFIX}/lib/omc/ffi # https://github.com/OpenModelica/OpenModelica/issues/9925

USE_GITHUB=	yes
GH_ACCOUNT=	OpenModelica
GH_PROJECT=	OpenModelica

SHEBANG_GLOB=	*.sh *.in *.ac

GH_TUPLE=	\
		OpenModelica:OMOptim:f1036f43db18c5015da259771004cfb80e08a110:OpenModelica_OMOptim/OMOptim \
		OpenModelica:OMSimulator:46fa40f:OpenModelica_OMSimulator/OMSimulator \
		OpenModelica:OMSimulator-3rdParty:5c10de1648d1134a577d9284b58580a72383d89f:OpenModelica_OMSimulator_3rdParty/OMSimulator/3rdParty \
		OpenModelica:OMCompiler-3rdParty:520663f:OpenModelica_OMCompiler_3rdParty/OMCompiler/3rdParty \
		OpenModelica:OMSens:093ad11:OpenModelica_OMSens/OMSens \
		OpenModelica:OMSens_Qt:bab329a:OpenModelica_OMSens_Qt/OMSens_Qt \
		OpenModelica:OpenModelica-common:08a01802db5ba5edb540383c46718b89ff229ef2:OpenModelica_OpenModelica_common/OMOptim/common \
		OpenModelica:OpenModelica-common:08a01802db5ba5edb540383c46718b89ff229ef2:OpenModelica_OpenModelica_common/OMSens_Qt/common
GH_TUPLE+=	OpenModelica:OMBootstrapping:91938f0acbdc6e9ba91114376e3640ca6147b579:bootstrapping/OMCompiler/Compiler/boot/bomc # downloaded by cmake

# this should change make program everywhere, but it doesn't,
# hence the patches in OMCompiler/Compiler/runtime/CMakeLists.txt, OMEdit/OMEditLIB/Simulation/SimulationOutputWidget.cpp
CMAKE_ARGS=	-DCMAKE_MAKE_PROGRAM=gmake \
		-DPython_EXECUTABLE=${PYTHON_CMD}

CMAKE_ARGS+=	-DOM_USE_CCACHE:BOOL=${CCACHE_ENABLED:S/yes/ON/:S/no/OFF/} # if refuses to build w/out ccache by default
#CMAKE_ARGS+=	-DOM_QT_MAJOR_VERSION=6 # broken, see https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=287596
CMAKE_ON=	OM_OMEDIT_ENABLE_QTWEBENGINE

LDFLAGS+=	-lexecinfo -lintl -pthread

BINARY_ALIAS=	make=${GMAKE}

post-extract:
	# remove stray *.orig files
	@${FIND} ${WRKSRC} -name "*.orig" -delete
	# remove rtime that isn't used on FreeBSD
	@${RM} -r ${WRKSRC}/OMSimulator/OMTLMSimulator/3rdParty/rtime
	# prevent bootstrap file download
	#${MKDIR} ${WRKSRC}/bomc
	${TOUCH} ${WRKSRC}/OMCompiler/Compiler/boot/bomc/sources.tar.gz
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
	#cd ${STAGEDIR}${PREFIX} && ${CHMOD} +x \
	#	bin/OMSimulator bin/OMSimulatorPython3 bin/StartTLMFmiWrapper
	# remove unnecessary files
	${RM} -r \
		${STAGEDIR}${PREFIX}/share/zmq \
		${STAGEDIR}${PREFIX}/doc \
		${STAGEDIR}${PREFIX}/share/doc
	# remove empty directories
	${FIND} ${STAGEDIR}${PREFIX}/include -type d -empty -delete
	# strip binaries
	#cd ${STAGEDIR}${PREFIX} && ${STRIP_CMD} \
		bin/OMSimulator bin/FMIWrapper \
		lib/omc/OMSimulator/libomtlmsimulator.so lib/omc/OMSimulator/libOMSimulator.so \
		lib/omc/libomtlmsimulator.so lib/omc/libOMSimulator.so

.include <bsd.port.mk>
