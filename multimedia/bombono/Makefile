# New ports collection makefile for: multimedia/bombono
# Date created:		07 Sep 2009
# Whom:			Stas Timokhin <stast@bsdportal.ru>
#
# $FreeBSD$
#

PORTNAME=	bombono
PORTVERSION=	0.5.1
PORTREVISION=	3
CATEGORIES=	multimedia
MASTER_SITES=	SF/bombono/bombono-dvd/${PORTVERSION} \
		http://www.stasyan.com/devel/distfiles/
DISTNAME=	bombono-dvd-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	DVD authoring program

LIB_DEPENDS=	gtkmm-2.4.1:${PORTSDIR}/x11-toolkits/gtkmm24 \
		xml++-2.6.2:${PORTSDIR}/textproc/libxml++26
BUILD_DEPENDS=	GraphicsMagick>=1.1.7:${PORTSDIR}/graphics/GraphicsMagick \
		mjpegtools>=1.9.0:${PORTSDIR}/multimedia/mjpegtools \
		dvdread-config:${PORTSDIR}/multimedia/libdvdread
RUN_DEPENDS=	GraphicsMagick>=1.1.7:${PORTSDIR}/graphics/GraphicsMagick \
		mjpegtools>=1.9.0:${PORTSDIR}/multimedia/mjpegtools \
		dvdread-config:${PORTSDIR}/multimedia/libdvdread \
		dvda-author:${PORTSDIR}/audio/dvda-author \
		growisofs:${PORTSDIR}/sysutils/dvd+rw-tools \
		toolame:${PORTSDIR}/audio/toolame

USE_BZIP2=	yes
USE_GNOME=	gtk20 libxml2
USE_GCC=	4.2+
USE_SCONS=	yes
SCONS_ENV=	CCFLAGS="${CCFLAGS}" CXXFLAGS="${CXXFLAGS}" \
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
