# New ports collection makefile for:    paraview
# Date created:         		25 May, 2005
# Whom:					anholt@FreeBSD.ORG
#
# $FreeBSD$
#

PORTNAME=	paraview
PORTVERSION=	3.6.1
CATEGORIES=	science graphics
MASTER_SITES=	http://www.paraview.org/files/v3.6/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	ParaView is a powerful scientific data visualization application

LIB_DEPENDS=	hdf5.0:${PORTSDIR}/science/hdf5 \
		png.5:${PORTSDIR}/graphics/png \
		jpeg.10:${PORTSDIR}/graphics/jpeg \
		tiff.4:${PORTSDIR}/graphics/tiff \
		freetype.9:${PORTSDIR}/print/freetype2 \
		expat.6:${PORTSDIR}/textproc/expat2

USE_QT_VER=	4
QT_COMPONENTS=	qmake_build moc_build rcc_build uic_build \
		linguist_build assistant_run qt3support \
		dbus designer gui help-tools network script \
		sql svg xml webkit assistantclient
USE_GL=		yes
USE_XORG=	x11 xt
USE_GMAKE=	yes
USE_LDCONFIG=	yes
USE_CMAKE=	yes
CMAKE_ARGS+=	-DPARAVIEW_USE_SYSTEM_HDF5=1 \
		-DBUILD_SHARED_LIBS="ON" \
		-DVTK_USE_SYSTEM_PNG="ON" \
		-DVTK_USE_SYSTEM_JPEG="ON" \
		-DVTK_USE_SYSTEM_TIFF="ON" \
		-DVTK_USE_SYSTEM_ZLIB="ON" \
		-DVTK_USE_SYSTEM_FREETYPE="ON" \
		-DVTK_USE_SYSTEM_EXPAT="ON" \
		-DVTK_USE_X="ON" \
		-DVTK_HAVE_GETSOCKNAME_WITH_SOCKLEN_T=1 \
		-DQT_ASSISTANT_EXECUTABLE="${LOCALBASE}/bin/assistant-qt4" \
		-DCMAKE_INCLUDE_DIRECTORIES_BEFORE="ON"

PATCH_WRKSRC=	${WRKDIR}/ParaView3
WRKSRC=		${WRKDIR}/ParaView3/build
CMAKE_SOURCE_PATH=	..

PLIST_SUB+=	VERMAJORMINOR=3.6
CMAKE2INST=	ParaViewConfig.cmake \
		ParaViewLibraryDepends.cmake cmake_install.cmake
LIB_INSTDIR=	${PREFIX}/lib/${PORTNAME}-${PORTVERSION:R}

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 700000
BROKEN=		does not build on 6.x
.endif

post-extract:
	${MKDIR} ${WRKSRC}

post-install:
.for c2f in ${CMAKE2INST}
	${SED} -e 's|${WRKSRC}|${LIB_INSTDIR}|g' \
		-e 's|${PATCH_WRKSRC}|${LIB_INSTDIR}|g' \
		${WRKSRC}/${c2f} > ${LIB_INSTDIR}/`${BASENAME} ${c2f}`
.endfor
	${INSTALL_DATA} ${PATCH_WRKSRC}/ParaViewUse.cmake \
		${PREFIX}/lib/${PORTNAME}-${PORTVERSION:R}

.include <bsd.port.post.mk>
