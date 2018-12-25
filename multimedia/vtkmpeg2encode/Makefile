# $FreeBSD$

PORTNAME=	vtkmpeg2encode
PORTVERSION=	${VTK_VERSION}
PORTREVISION=	1
CATEGORIES=	multimedia math
MASTER_SITES=	http://www.vtk.org/files/support/ \
		http://www.neuro.mcw.edu/Ports/distfiles/VTK5/
DISTNAME=	vtkmpeg2encode

MAINTAINER=	ports@FreeBSD.org
COMMENT=	VTK MPEG2 encoding library

LICENSE=	MPEG-2
LICENSE_NAME=	MPEG-2 license
LICENSE_FILE=	${WRKSRC}/mpeg2enc.h
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USES=		cmake:insource
USE_LDCONFIG=	yes
CMAKE_ARGS?=	-DBUILD_SHARED_LIBS:BOOL=ON
VTK_VERSION=	5.10.1

SUB_FILES=	vtkmpeg2encode.3

MPEGLIB=	libvtkMPEG2Encode

PLIST_FILES=	lib/${MPEGLIB}.so.${PORTVERSION} \
		lib/${MPEGLIB}.so.${VTK_VERSION:R} \
		lib/${MPEGLIB}.so.${VTK_VERSION:R:R} \
		lib/${MPEGLIB}.so \
		include/vtk-${VTK_VERSION:R}/mpeg2encDllConfig.h \
		include/vtk-${VTK_VERSION:R}/mpeg2enc_global.h \
		include/vtk-${VTK_VERSION:R}/mpeg2enc.h \
		include/vtk-${VTK_VERSION:R}/mpeg2enc_config.h \
		include/vtk-${VTK_VERSION:R}/vlc.h \
		man/man3/vtkmpeg2encode.3.gz

post-build:
	${MV} ${WRKSRC}/${MPEGLIB}.so ${WRKSRC}/${MPEGLIB}.so.${PORTVERSION}

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/include/vtk-${VTK_VERSION:R}
	${INSTALL_LIB} ${WRKSRC}/${MPEGLIB}.so.${PORTVERSION} ${STAGEDIR}${PREFIX}/lib
	${LN} -s ${MPEGLIB}.so.${PORTVERSION} \
			${STAGEDIR}${PREFIX}/lib/${MPEGLIB}.so.${VTK_VERSION:R}
	${LN} -s ${MPEGLIB}.so.${PORTVERSION} \
			${STAGEDIR}${PREFIX}/lib/${MPEGLIB}.so.${VTK_VERSION:R:R}
	${LN} -s ${MPEGLIB}.so.${PORTVERSION} \
			${STAGEDIR}${PREFIX}/lib/${MPEGLIB}.so
	${INSTALL_DATA} ${WRKSRC}/mpeg2encDllConfig.h \
			${WRKSRC}/mpeg2enc_global.h \
			${WRKSRC}/mpeg2enc.h \
			${WRKSRC}/mpeg2enc_config.h \
			${WRKSRC}/vlc.h \
			${STAGEDIR}${PREFIX}/include/vtk-${VTK_VERSION:R}
	${INSTALL_MAN}	${WRKDIR}/vtkmpeg2encode.3 ${STAGEDIR}${MANPREFIX}/man/man3

.include <bsd.port.mk>
