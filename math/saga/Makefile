PORTNAME=	saga
PORTVERSION=	9.9.2
CATEGORIES=	math
MASTER_SITES=	SF/saga-gis/SAGA%20-%20${PORTVERSION:C/\.[[:digit:]]\.[[:digit:]]*$//}/SAGA%20-%20${PORTVERSION}

MAINTAINER=	rhurlin@FreeBSD.org
COMMENT=	System for Automated Geoscientific Analyses
WWW=		http://www.saga-gis.org/en/index.html

LICENSE=	GPLv2 LGPL21
LICENSE_COMB=	multi

.if !exists(/usr/include/omp.h)
BROKEN=		requires OpenMP support that is missing on this architecture
.endif

BUILD_DEPENDS=	swig:devel/swig
LIB_DEPENDS=	libcurl.so:ftp/curl \
		libexiv2.so:graphics/exiv2 \
		libfftw3.so:math/fftw3 \
		libgdal.so:graphics/gdal \
		libhdf5.so:science/hdf5 \
		libhpdf.so:print/libharu \
		libodbc.so:databases/unixODBC \
		libopencv_core.so:graphics/opencv \
		libpdalcpp.so:math/pdal \
		libproj.so:graphics/proj \
		libsvm.so:science/libsvm \
		libsz.so:science/libaec \
		libtiff.so:graphics/tiff
RUN_DEPENDS:=	swig:devel/swig

USES=		cmake compiler:c++17-lang desktop-file-utils dos2unix \
		gnome iconv:wchar_t localbase pkgconfig python
DOS2UNIX_GLOB=	*.cpp *.h *.txt
USE_LDCONFIG=	yes
USE_WX=		3.2+

GIT_TAGNAME=	5d95de070

CMAKE_ARGS=	-DSVM_INCLUDE:PATH=${LOCALBASE}/include/svm.h \
		-DWITH_TOOLS_PDAL:BOOL=TRUE
CMAKE_ON=	CMAKE_VERBOSE_MAKEFILE
CMAKE_ON+=	WITH_DEV_TOOLS
CMAKE_ON+=	WITH_EXCERCISES
CMAKE_ON+=	WITH_EXIV2
CMAKE_ON+=	WITH_LIFETIME_TRACKER
CMAKE_ON+=	WITH_MRMR
CMAKE_ON+=	WITH_SYSTEM_SVM
CMAKE_ON+=	WITH_TOOLS_HPDF
CMAKE_ON+=	WITH_TOOLS_OPENCV
CMAKE_ON+=	WITH_PYTHON_PKG
CMAKE_ON+=	WITH_TOOLS_PDAL
CMAKE_ON+=	WITH_TOOLS_POSTGRES
CMAKE_ON+=	WITH_TOOLS_PROJ
CMAKE_OFF=	WITH_CLIPPER_ONE
CMAKE_OFF+=	WITH_TOOLS_RIEGL

SUB_FILES=	pkg-message

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}/${PORTNAME}-gis

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

SUB_FILES=	pkg-message

post-patch:
.if ${ARCH} == "powerpc"
	@${REINPLACE_CMD} -e 's|typedef unsigned long	DWORD;|typedef unsigned int	DWORD;|' \
		${WRKSRC}/src/saga_core/saga_api/api_core.h
.endif
	@${REINPLACE_CMD} -e 's|GIT_TAGNAME|${GIT_TAGNAME}|g' \
		${WRKSRC}/src/saga_core/saga_gui/CMakeLists.txt \
		${WRKSRC}/src/saga_core/saga_gui/dlg_about.cpp
	@${REINPLACE_CMD} -e 's|-lgomp|-lomp|' \
		${WRKSRC}/src/saga_core/saga_api/saga_api_to_python.py

post-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/src/saga_core/saga_gui/res/saga*.txt ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/src/saga_core/saga_gui/res/saga.png ${STAGEDIR}${DATADIR}
	${RM} ${STAGEDIR}${DATADIR}/saga_dic.txt ${STAGEDIR}${DATADIR}/saga_srs.txt
# Put accessories under share/saga, python/data already under site-packages/PySAGA ;)
	(cd ${WRKSRC}/src/accessories && ${RM} -R python)
	(cd ${WRKSRC}/src/accessories && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR})
	${RM} -R ${STAGEDIR}${DATADIR}/CMakeLists.txt
	${RM} -R ${STAGEDIR}${DATADIR}/templates/template4saga-tools/my_tool_library/Makefile.bak
# library helper files are not needed and cripple some math/qgis extensions
	@${RM} ${STAGEDIR}${PREFIX}/lib/saga/*.la

.include <bsd.port.post.mk>
