# Created by: anholt@FreeBSD.org
# $FreeBSD$

PORTNAME=	paraview
DISTVERSION=	5.6.0
PORTREVISION=	4
CATEGORIES=	science graphics
MASTER_SITES=	http://www.paraview.org/files/v${VERMAJORMINOR}/
DISTNAME=	ParaView-v${PORTVERSION}

MAINTAINER=	devel@stasyan.com
COMMENT=	Powerful scientific data visualization application

LICENSE=	ParaView_License_1.2
LICENSE_NAME=	ParaView_License
LICENSE_FILE=	${PATCH_WRKSRC}/License_v1.2.txt
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/matplotlib/pyplot.py:math/py-matplotlib@${PY_FLAVOR}
LIB_DEPENDS=	libhdf5.so:science/hdf5 \
		libpng.so:graphics/png \
		libtiff.so:graphics/tiff \
		libfreetype.so:print/freetype2 \
		libexpat.so:textproc/expat2 \
		libjbig.so:graphics/jbigkit \
		liborc-0.4.so:devel/orc \
		libpcre.so:devel/pcre \
		libffi.so:devel/libffi \
		libdrm.so:graphics/libdrm \
		libfontconfig.so:x11-fonts/fontconfig \
		libprotobuf.so:devel/protobuf
RUN_DEPENDS=	bash:shells/bash	\
		${PYTHON_SITELIBDIR}/matplotlib/pyplot.py:math/py-matplotlib@${PY_FLAVOR}

USES=		alias cmake compiler:c11 gl jpeg localbase python:2.7 qt:5 \
		shebangfix xorg
USE_QT=		core gui help network sql widgets x11extras xmlpatterns \
		buildtools_build qmake_build
USE_GL=		gl glu
USE_XORG=	x11 xt xext ice xdmcp xau xcb xfixes xdamage xxf86vm xrender sm xorgproto
USE_LDCONFIG=	yes
USE_GSTREAMER=	yes

CONFLICTS_INSTALL=	${PYTHON_PKGNAMEPREFIX}pygments

CMAKE_ARGS+=	-DBUILD_SHARED_LIBS="ON" \
		-DVTK_USE_SYSTEM_PNG="ON" \
		-DVTK_USE_SYSTEM_JPEG="ON" \
		-DVTK_USE_SYSTEM_TIFF="ON" \
		-DVTK_USE_SYSTEM_ZLIB="ON" \
		-DVTK_USE_SYSTEM_FREETYPE="ON" \
		-DVTK_USE_SYSTEM_EXPAT="ON" \
		-DVTK_USE_SYSTEM_PROTOBUF="ON" \
		-DVTK_USE_X="ON" \
		-DVTK_HAVE_GETSOCKNAME_WITH_SOCKLEN_T=1 \
		-DPARAVIEW_ENABLE_PYTHON:BOOL="ON" \
		-DPARAVIEW_ENABLE_FFMPEG:BOOL="OFF" \
		-DBUILD_TESTING:BOOL="OFF" \
		-DExternalData_OBJECT_STORES="${WRKDIR}/VTK/ExternalData/MD5" \
		-DFREETYPE_INCLUDE_DIRS="${LOCALBASE}/include/freetype2"
MAKE_ENV=	XDG_CONFIG_HOME=${WRKDIR}

SHEBANG_FILES=	Catalyst/catalyze.py VTK/Examples/SearchScript.sh \
		VTK/Utilities/Maintenance/*.sh

OPTIONS_DEFINE=	OSMESA GL2PS DOCS
OPTIONS_SUB=	yes
OSMESA_DESC=	Use Mesa for off-screen rendering
GL2PS_DESC=	Install support conversion OpenGL to PostScript
#		VTKMPEG2	"Install patented MPEG2 encoder module" Off \

VERMAJORMINOR=	${PORTVERSION:R}

OSMESA_LIB_DEPENDS=	libOSMesa.so:graphics/libosmesa
OSMESA_CMAKE_BOOL=	VTK_OPENGL_HAS_OSMESA
OSMESA_CMAKE_ON=	-DOSMESA_INCLUDE_DIR:PATH=${LOCALBASE}/include/Mesa \
			-DOSMESA_LIBRARY:FILEPATH=${LOCALBASE}/lib/libOSMesa.so

GL2PS_LIB_DEPENDS=	libgl2ps.so:print/gl2ps
GL2PS_CMAKE_BOOL=	VTK_USE_GL2PS

PLIST_SUB+=	VERMAJORMINOR=${VERMAJORMINOR}
CMAKE2INST=	ParaViewConfig.cmake \
		cmake_install.cmake
LIB_INSTDIR=	${PREFIX}/lib/${PORTNAME}-${VERMAJORMINOR}

pre-configure:
	@${REINPLACE_CMD} -e 's|png_set_gray_1_2_4_to_8|png_set_expand_gray_1_2_4_to_8|' \
		${PATCH_WRKSRC}/VTK/IO/Image/vtkPNGReader.cxx
	@${REINPLACE_CMD} -e 's|/bin/bash|${LOCALBASE}/bin/bash|'	\
		${PATCH_WRKSRC}/VTK/Utilities/Maintenance/vtk_site_history.py

post-install:
.for c2f in ${CMAKE2INST}
	${SED} -e 's|${BUILD_WRKSRC}|${LIB_INSTDIR}|g' \
		-e 's|${PATCH_WRKSRC}|${LIB_INSTDIR}|g' \
		${BUILD_WRKSRC}/${c2f} > ${STAGEDIR}${LIB_INSTDIR}/`${BASENAME} ${c2f}`
.endfor
	${INSTALL_DATA} ${PATCH_WRKSRC}/CMake/UseParaView.cmake \
		${STAGEDIR}${PREFIX}/lib/${PORTNAME}-${VERMAJORMINOR}

.include <bsd.port.mk>
