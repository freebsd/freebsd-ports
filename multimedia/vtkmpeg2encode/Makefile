# New ports collection makefile for:	vtkmpeg2encode
# Date created:		2007-12-20
# Whom:			Jason W. Bacon <bacon@smithers.neuro.mcw.edu>
#
# $FreeBSD$
#

PORTNAME=	vtkmpeg2encode
PORTVERSION=	5.6.0
CATEGORIES=	multimedia math
MASTER_SITES=	http://www.vtk.org/files/support/ \
		http://www.neuro.mcw.edu/Ports/distfiles/VTK5/
DISTNAME=	vtkmpeg2encode

MAINTAINER=	jwbacon@tds.net
COMMENT=	VTK MPEG2 encoding library

NO_CDROM=	the MPEG2 format and all software that uses it is subject to patent restrictions
NO_PACKAGE=	${NO_CDROM}

USE_CMAKE=	yes
USE_LDCONFIG=	yes
CMAKE_ARGS?=	-DBUILD_SHARED_LIBS:BOOL=ON

MAN3=		vtkmpeg2encode.3

SUB_FILES=	vtkmpeg2encode.3

MPEGLIB=	libvtkMPEG2Encode

PLIST_DIRS=	include/vtk-5.6
PLIST_FILES=	lib/${MPEGLIB}.so.${PORTVERSION} \
		lib/${MPEGLIB}.so.5.6 \
		lib/${MPEGLIB}.so.5 \
		lib/${MPEGLIB}.so \
		include/vtk-5.6/mpeg2encDllConfig.h \
		include/vtk-5.6/mpeg2enc_global.h \
		include/vtk-5.6/mpeg2enc.h \
		include/vtk-5.6/mpeg2enc_config.h \
		include/vtk-5.6/vlc.h

post-build:
	${MV} ${WRKSRC}/${MPEGLIB}.so ${WRKSRC}/${MPEGLIB}.so.${PORTVERSION}

do-install:
	${MKDIR} ${PREFIX}/include/vtk-5.6
	${INSTALL_DATA} ${WRKSRC}/${MPEGLIB}.so.${PORTVERSION} ${PREFIX}/lib
	${LN} -s ${PREFIX}/lib/${MPEGLIB}.so.${PORTVERSION} \
			${PREFIX}/lib/${MPEGLIB}.so.5.6
	${LN} -s ${PREFIX}/lib/${MPEGLIB}.so.${PORTVERSION} \
			${PREFIX}/lib/${MPEGLIB}.so.5
	${LN} -s ${PREFIX}/lib/${MPEGLIB}.so.${PORTVERSION} \
			${PREFIX}/lib/${MPEGLIB}.so
	${INSTALL_DATA} ${WRKSRC}/mpeg2encDllConfig.h \
			${WRKSRC}/mpeg2enc_global.h \
			${WRKSRC}/mpeg2enc.h \
			${WRKSRC}/mpeg2enc_config.h \
			${WRKSRC}/vlc.h \
			${PREFIX}/include/vtk-5.6
	${INSTALL_MAN}	${WRKDIR}/vtkmpeg2encode.3 ${MANPREFIX}/man/man3

post-install:
	@${ECHO_MSG}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG}

.include <bsd.port.mk>
