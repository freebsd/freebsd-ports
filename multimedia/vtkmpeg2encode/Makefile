# Created by: Jason W. Bacon <bacon@smithers.neuro.mcw.edu>
# $FreeBSD$

PORTNAME=	vtkmpeg2encode
PORTVERSION=	${VTK_VERSION}
CATEGORIES=	multimedia math
MASTER_SITES=	http://www.vtk.org/files/support/ \
		http://www.neuro.mcw.edu/Ports/distfiles/VTK5/
DISTNAME=	vtkmpeg2encode

MAINTAINER=	jwbacon@tds.net
COMMENT=	VTK MPEG2 encoding library

NO_CDROM=	the MPEG2 format and all software that uses it is subject to patent restrictions
NO_PACKAGE=	${NO_CDROM}

USES=		cmake
USE_LDCONFIG=	yes
CMAKE_ARGS?=	-DBUILD_SHARED_LIBS:BOOL=ON
VTK_VERSION=	5.10.1

MAN3=		vtkmpeg2encode.3

SUB_FILES=	vtkmpeg2encode.3

MPEGLIB=	libvtkMPEG2Encode

PLIST_DIRS=	include/vtk-${VTK_VERSION:R}
PLIST_FILES=	lib/${MPEGLIB}.so.${PORTVERSION} \
		lib/${MPEGLIB}.so.${VTK_VERSION:R} \
		lib/${MPEGLIB}.so.${VTK_VERSION:R:R} \
		lib/${MPEGLIB}.so \
		include/vtk-${VTK_VERSION:R}/mpeg2encDllConfig.h \
		include/vtk-${VTK_VERSION:R}/mpeg2enc_global.h \
		include/vtk-${VTK_VERSION:R}/mpeg2enc.h \
		include/vtk-${VTK_VERSION:R}/mpeg2enc_config.h \
		include/vtk-${VTK_VERSION:R}/vlc.h

NO_STAGE=	yes
post-build:
	${MV} ${WRKSRC}/${MPEGLIB}.so ${WRKSRC}/${MPEGLIB}.so.${PORTVERSION}

do-install:
	${MKDIR} ${PREFIX}/include/vtk-${VTK_VERSION:R}
	${INSTALL_DATA} ${WRKSRC}/${MPEGLIB}.so.${PORTVERSION} ${PREFIX}/lib
	${LN} -s ${PREFIX}/lib/${MPEGLIB}.so.${PORTVERSION} \
			${PREFIX}/lib/${MPEGLIB}.so.${VTK_VERSION:R}
	${LN} -s ${PREFIX}/lib/${MPEGLIB}.so.${PORTVERSION} \
	   ${PREFIX}/lib/${MPEGLIB}.so.${VTK_VERSION:R:R}
	${LN} -s ${PREFIX}/lib/${MPEGLIB}.so.${PORTVERSION} \
			${PREFIX}/lib/${MPEGLIB}.so
	${INSTALL_DATA} ${WRKSRC}/mpeg2encDllConfig.h \
			${WRKSRC}/mpeg2enc_global.h \
			${WRKSRC}/mpeg2enc.h \
			${WRKSRC}/mpeg2enc_config.h \
			${WRKSRC}/vlc.h \
			${PREFIX}/include/vtk-${VTK_VERSION:R}
	${INSTALL_MAN}	${WRKDIR}/vtkmpeg2encode.3 ${MANPREFIX}/man/man3

post-install:
	@${ECHO_MSG}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG}

.include <bsd.port.mk>
