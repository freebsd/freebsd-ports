PORTNAME=	openmodelica
DISTVERSIONPREFIX=	v
DISTVERSION=	1.22.0
PORTREVISION=	1
CATEGORIES=	science cad java
DIST_SUBDIR=	${PORTNAME}-${PORTVERSION}

PATCH_SITES=	https://github.com/OpenModelica/OpenModelica/commit/
PATCHFILES+=	0f4b4ce89dca64287dd4c7a19a6aa98114ea563c.patch:-p1 # Qt WebEngine support

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

USES=		cmake compiler:c++14-lang iconv fortran gettext-runtime gl \
		gnome blaslapack localbase:ldflags qt:5 readline pkgconfig \
		python:build shebangfix
USE_QT=		concurrent core declarative gui network opengl \
		printsupport svg webchannel webengine widgets xml xmlpatterns \
		buildtools:build qmake:build
USE_GL=		gl opengl
USE_GNOME=	libxml2
USE_JAVA=	yes
USE_LDCONFIG=	${PREFIX}/lib/omc ${PREFIX}/lib/omc/OMSimulator ${PREFIX}/lib/omc/cpp ${PREFIX}/lib/omc/ffi # https://github.com/OpenModelica/OpenModelica/issues/9925

USE_GITHUB=	yes
GH_ACCOUNT=	OpenModelica
GH_PROJECT=	OpenModelica

SHEBANG_GLOB=	*.sh *.in *.ac

GH_TUPLE=	\
		OpenModelica:OMOptim:55102095970c73a4176820538d19aaf408515da9:OpenModelica_OMOptim/OMOptim \
		OpenModelica:OMSimulator:634b0193a3eb14e75622a8e720bf0fb6dab77487:OpenModelica_OMSimulator/OMSimulator \
		OpenModelica:OMSimulator-3rdParty:b4c3aa4a16a5920e88096780498cc4af157f3c05:OpenModelica_OMSimulator_3rdParty/OMSimulator/3rdParty \
		OpenModelica:OMCompiler-3rdParty:d19136844b49720ae3a8957f0fb1e137c7055b43:OpenModelica_OMCompiler_3rdParty/OMCompiler/3rdParty \
		OpenModelica:OMSens:8216eaefbb4ea2ff0c7a17a3487dcc2a8a17667d:OpenModelica_OMSens/OMSens \
		OpenModelica:OMSens_Qt:ff2ade18e7058f611ddfd575ccbd24f388615d3f:OpenModelica_OMSens_Qt/OMSens_Qt \
		OpenModelica:OpenModelica-common:08a01802db5ba5edb540383c46718b89ff229ef2:OpenModelica_OpenModelica_common/OMOptim/common \
		OpenModelica:OpenModelica-common:08a01802db5ba5edb540383c46718b89ff229ef2:OpenModelica_OpenModelica_common/OMSens_Qt/common
GH_TUPLE+=	OpenModelica:OMBootstrapping:c289e97c41d00939a4a69fe504961b47283a6d8e:bootstrapping/OMCompiler/Compiler/boot/bomc # downloaded by cmake

# this should change make program everywhere, but it doesn't,
# hence the patches in OMCompiler/Compiler/runtime/CMakeLists.txt, OMEdit/OMEditLIB/Simulation/SimulationOutputWidget.cpp
CMAKE_ARGS=	-DCMAKE_MAKE_PROGRAM=gmake \
		-DPython_EXECUTABLE=${PYTHON_CMD}

CMAKE_ARGS+=	-DOM_USE_CCACHE:BOOL=${CCACHE_ENABLED:S/yes/ON/:S/no/OFF/} # if refuses to build w/out ccache by default
CMAKE_ON=	OM_OMEDIT_ENABLE_QTWEBENGINE

LDFLAGS+=	-lexecinfo -lintl -pthread

BINARY_ALIAS=	make=${GMAKE}

CONFLICTS_BUILD=	sundials

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
