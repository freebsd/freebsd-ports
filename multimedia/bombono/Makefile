# Created by: Stas Timokhin <stast@bsdportal.ru>
# $FreeBSD$

PORTNAME=	bombono
PORTVERSION=	1.2.1
PORTREVISION=	4
CATEGORIES=	multimedia
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-dvd/1.2
DISTNAME=	${PORTNAME}-dvd-${PORTVERSION}

MAINTAINER=	pawel@FreeBSD.org
COMMENT=	DVD authoring program

BUILD_DEPENDS=	GraphicsMagick>=1.1.7:${PORTSDIR}/graphics/GraphicsMagick \
		mjpegtools>=1.9.0:${PORTSDIR}/multimedia/mjpegtools
LIB_DEPENDS=	gtkmm-2.4.1:${PORTSDIR}/x11-toolkits/gtkmm24 \
		xml++-2.6.2:${PORTSDIR}/textproc/libxml++26 \
		lavfile:${PORTSDIR}/multimedia/mjpegtools \
		dvdread:${PORTSDIR}/multimedia/libdvdread \
		avcodec:${PORTSDIR}/multimedia/ffmpeg \
		boost_filesystem:${PORTSDIR}/devel/boost-libs
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
INSTALLS_ICONS=	yes
MAKE_JOBS_SAFE=	yes

CXXFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -lintl
SCONS_ARGS=	DVDREAD_LIBPATH=${LOCALBASE}/lib \
		DVDREAD_INCLUDE=${LOCALBASE}/include LDFLAGS="${LDFLAGS}"

MAN1=		bombono-dvd.1 mpeg2demux.1
MANDIR=		${MANPREFIX}/man/man1

post-patch:
	@${REINPLACE_CMD} -e 's|-O2||' ${WRKSRC}/SConstruct

post-install:
	${MKDIR} ${MANDIR}
	${INSTALL_MAN} ${WRKSRC}/docs/man/man1/bombono-dvd.1  ${MANDIR}
	${INSTALL_MAN} ${WRKSRC}/docs/man/man1/mpeg2demux.1 ${MANDIR}

.include <bsd.port.mk>
