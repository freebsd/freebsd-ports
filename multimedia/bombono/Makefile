# Created by: Stas Timokhin <stast@bsdportal.ru>
# $FreeBSD$

PORTNAME=	bombono
PORTVERSION=	1.2.2
CATEGORIES=	multimedia
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-dvd/${PORTVERSION:R}
DISTNAME=	${PORTNAME}-dvd-${PORTVERSION}

MAINTAINER=	pawel@FreeBSD.org
COMMENT=	DVD authoring program

BUILD_DEPENDS=	GraphicsMagick>=1.1.7:${PORTSDIR}/graphics/GraphicsMagick
LIB_DEPENDS=	libgtkmm-2.4.so:${PORTSDIR}/x11-toolkits/gtkmm24 \
		libxml++-2.6.so:${PORTSDIR}/textproc/libxml++26 \
		liblavfile.so:${PORTSDIR}/multimedia/mjpegtools \
		libdvdread.so:${PORTSDIR}/multimedia/libdvdread \
		libavcodec.so:${PORTSDIR}/multimedia/ffmpeg \
		libboost_filesystem.so:${PORTSDIR}/devel/boost-libs
RUN_DEPENDS=	GraphicsMagick>=1.1.7:${PORTSDIR}/graphics/GraphicsMagick \
		dvda-author:${PORTSDIR}/audio/dvda-author \
		enca:${PORTSDIR}/converters/enca \
		growisofs:${PORTSDIR}/sysutils/dvd+rw-tools \
		toolame:${PORTSDIR}/audio/toolame

USES=		pkgconfig gettext
USE_BZIP2=	yes
USE_SCONS=	yes
USE_GCC=	4.2+
INSTALLS_ICONS=	yes

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
