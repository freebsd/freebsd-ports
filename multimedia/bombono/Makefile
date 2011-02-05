# New ports collection makefile for: multimedia/bombono
# Date created:		07 Sep 2009
# Whom:			Stas Timokhin <stast@bsdportal.ru>
#
# $FreeBSD$
#

PORTNAME=	bombono
PORTVERSION=	1.0.0
CATEGORIES=	multimedia
MASTER_SITES=	SF/bombono/bombono-dvd/1.0
DISTNAME=	bombono-dvd-${PORTVERSION}

MAINTAINER=	c0rn@o2.pl
COMMENT=	DVD authoring program

BUILD_DEPENDS=	GraphicsMagick>=1.1.7:${PORTSDIR}/graphics/GraphicsMagick \
		mjpegtools>=1.9.0:${PORTSDIR}/multimedia/mjpegtools
LIB_DEPENDS=	gtkmm-2.4.1:${PORTSDIR}/x11-toolkits/gtkmm24 \
		xml++-2.6.2:${PORTSDIR}/textproc/libxml++26 \
		lavfile:${PORTSDIR}/multimedia/mjpegtools \
		dvdread:${PORTSDIR}/multimedia/libdvdread \
		avcodec:${PORTSDIR}/multimedia/ffmpeg
RUN_DEPENDS=	GraphicsMagick>=1.1.7:${PORTSDIR}/graphics/GraphicsMagick \
		dvda-author:${PORTSDIR}/audio/dvda-author \
		enca:${PORTSDIR}/converters/enca \
		growisofs:${PORTSDIR}/sysutils/dvd+rw-tools \
		toolame:${PORTSDIR}/audio/toolame

USE_BZIP2=	yes
USE_GNOME=	gtk20 libxml2
USE_GCC=	4.2+
USE_SCONS=	yes
USE_GETTEXT=	yes
MAKE_JOBS_SAFE=	yes
SCONS_ENV=	CCFLAGS="${CCFLAGS} -I${LOCALBASE}/include" \
		CXXFLAGS="${CXXFLAGS} -I${LOCALBASE}/include" \
		LINKFLAGS="${LINKFLAGS}" PKGCONFIGDIR="${PKGCONFIGDIR}" \
		CPPPATH="${CPPPATH}" LIBPATH="${LIBPATH}" PREFIX="${PREFIX}" \
		CC="${CC}" CXX="${CXX}" \
		DVDREAD_LIBPATH=${LOCALBASE}/lib DVDREAD_INCLUDE=${LOCALBASE}/include

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 700000
BROKEN=		does not compile
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-O2||' ${WRKSRC}/SConstruct

.include <bsd.port.post.mk>
