PORTNAME=	saga
PORTVERSION=	8.3.0
PORTREVISION=	1
CATEGORIES=	math
MASTER_SITES=	SF/saga-gis/SAGA%20-%20${PORTVERSION:C/\.[[:digit:]]\.[[:digit:]]*$//}/SAGA%20-%20${PORTVERSION}

MAINTAINER=	rhurlin@FreeBSD.org
COMMENT=	System for Automated Geoscientific Analyses

LICENSE=	GPLv2 LGPL21
LICENSE_COMB=	multi

.if !exists(/usr/include/omp.h)
BROKEN=		requires OpenMP support that is missing on this architecture
.endif

BUILD_DEPENDS=	clang${LLVM_DEFAULT}:devel/llvm${LLVM_DEFAULT} \
		swig:devel/swig
LIB_DEPENDS=	libcurl.so:ftp/curl \
		libfftw3.so:math/fftw3 \
		libgdal.so:graphics/gdal \
		libhdf5.so:science/hdf5 \
		libhpdf.so:print/libharu \
		libjasper.so:graphics/jasper \
		libodbc.so:databases/unixODBC \
		libopencv_core.so:graphics/opencv \
		libpdal_base.so:math/pdal \
		libproj.so:graphics/proj \
		libqhull_r.so:math/qhull \
		libsvm.so:science/libsvm \
		libsz.so:science/libaec \
		libtiff.so:graphics/tiff
RUN_DEPENDS:=	swig:devel/swig

USES=		cmake compiler:c++11-lib dos2unix gnome \
		iconv:wchar_t libtool localbase pkgconfig python
DOS2UNIX_GLOB=	*.cpp *.h
USE_LDCONFIG=	yes
USE_WX=		3.1+

CMAKE_ARGS+=	-DSVM_INCLUDE:PATH=${LOCALBASE}/include/svm.h
CMAKE_ON=	WITH_DEV_TOOLS WITH_EXCERCISES WITH_MRMR WITH_SYSTEM_SVM
CMAKE_ON+=	CMAKE_VERBOSE_MAKEFILE
CMAKE_OFF+=	WITH_TOOLS_LAS WITH_TRIANGLE

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}/saga-gis

PLIST_SUB=	PORTVERSION=${PORTVERSION}

OPTIONS_DEFINE=	PGSQL OPENMP VIGRA
OPTIONS_DEFAULT=	PGSQL VIGRA
OPTIONS_DEFAULT_amd64=	OPENMP
OPTIONS_DEFAULT_i386=	OPENMP
OPTIONS_DEFAULT_powerpc64=	OPENMP
OPTIONS_DEFAULT_powerpc64le=	OPENMP
NO_OPTIONS_SORT=	yes
OPTIONS_SUB=	yes
OPENMP_DESC=	Enable Multiprocessing (only amd64, i386 and powerpc64*)
VIGRA_DESC=	Enable 'Vision with Generic Algorithms' Library

OPENMP_CONFIGURE_ENABLE=	openmp
PGSQL_USES=		pgsql
PGSQL_CONFIGURE_WITH=	postgresql
VIGRA_BUILD_DEPENDS=	${LOCALBASE}/lib/libvigraimpex.so:graphics/vigra
VIGRA_RUN_DEPENDS=	${LOCALBASE}/lib/libvigraimpex.so:graphics/vigra

.include <bsd.port.pre.mk>

# make describe needs them here
CPP=		clang-cpp${LLVM_DEFAULT}
CC=		clang${LLVM_DEFAULT}
CXX=		clang++${LLVM_DEFAULT}

SUB_FILES=	pkg-message

post-patch:
.if ${ARCH} == "powerpc"
	@${REINPLACE_CMD} -e 's|typedef unsigned long	DWORD;|typedef unsigned int	DWORD;|' \
		${WRKSRC}/src/saga_core/saga_api/api_core.h
.endif
	@${REINPLACE_CMD} -e 's|PORTVERSION|${PORTVERSION}|' \
		${WRKSRC}/src/saga_core/saga_gui/dlg_about.cpp
	@${REINPLACE_CMD} -e 's|-lgomp|-lomp|' \
		${WRKSRC}/src/accessories/templates/template4saga-tools/my_tool_library/Makefile

post-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/src/saga_core/saga_gui/res/saga*.txt ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/src/saga_core/saga_gui/res/saga.png ${STAGEDIR}${DATADIR}
	${RM} ${STAGEDIR}${DATADIR}/saga_dic.txt ${STAGEDIR}${DATADIR}/saga_srs.txt
# toolchains dir was moved in r2805 (and followups r2810,r2811,r2820)
	(cd ${WRKSRC}/src/accessories && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR})
	${RM} -R ${STAGEDIR}${DATADIR}/CMakeLists.txt
	${RM} -R ${STAGEDIR}${DATADIR}/templates/template4saga-tools/my_tool_library/Makefile.bak
	${INSTALL_DATA} ${WRKSRC}/src/saga_core/saga_gui/res/saga.desktop \
		${STAGEDIR}${PREFIX}/share/applications/
# library helper files are not needed and cripple some math/qgis extensions
	@${RM} ${STAGEDIR}${PREFIX}/lib/saga/*.la

.include <bsd.port.post.mk>
