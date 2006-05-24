# New ports collection makefile for:	labplot
# Date created:				07 August 2004
# Whom:					Kay Lehmann <kay_lehmann@web.de>
#
# $FreeBSD$
#

PORTNAME=	LabPlot
PORTVERSION=	1.5.0.5
PORTREVISION=	5
CATEGORIES=	math kde
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=labplot

MAINTAINER=	kay_lehmann@web.de
COMMENT=	LabPlot : Data analysis and visualisation

LIB_DEPENDS=	tiff.4:${PORTSDIR}/graphics/tiff \
		Magick.10:${PORTSDIR}/graphics/ImageMagick \
		audiofile.0:${PORTSDIR}/audio/libaudiofile \
		gsl.9:${PORTSDIR}/math/gsl \
		jasper.4:${PORTSDIR}/graphics/jasper \
		fftw3.4:${PORTSDIR}/math/fftw3 \
		netcdf:${PORTSDIR}/science/netcdf \
		qwtplot3d.0:${PORTSDIR}/math/qwtplot3d
RUN_DEPENDS=	pstoedit:${PORTSDIR}/graphics/pstoedit

WRKSRC=		${WRKDIR}/${PORTNAME}-1.5.0

USE_QT_VER=	3
USE_KDELIBS_VER=3
USE_GL=		yes
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool:15
INSTALLS_SHLIB=	yes
LDCONFIG_DIRS+=	%%PREFIX%%/lib
CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS} -I${LOCALBASE}/include -I${LOCALBASE}/include/kexidb ${PTHREAD_CFLAGS}" \
		LDFLAGS="${LDFLAGS} ${PTHREAD_LIBS}"
CONFIGURE_ARGS+=--program-prefix='' --disable-cdf \
		--enable-system-qwtplot3d --enable-KexiDB=no

MAN1=		LabPlot.1 labplot.1

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
IGNORE=		does not compile on 4.x
.endif

#This needs some more work before enabling this feature
#.if defined(WITH_VTK)
#LIB_DEPENDS+=	vtkRendering.1:${PORTSDIR}/math/vtk
#BUILD_DEPENDS+=	vtkRenderer.h:${PORTSDIR}/math/vtk-headers
#CFLAGS+=	${PTHREAD_CLAGS} -I${LOCALBASE}/include/vtk
#LDFLAGS+=	${PTHREAD_LIBS}
#CONFIGURE_ENV=	CFLAGS="${CFLAGS}" \
#		LDFLAGS="${LDFLAGS}" \
#		CPPFLAGS="${CPPFLAGS}" \
#		CXXFLAGS="${CXXFLAGS}" \
#CONFIGURE_ENV+=	VTK_DIR=${LOCALBASE}
#CONFIGURE_ARGS+=	--enable-vtk
#.endif

.include <bsd.port.post.mk>
