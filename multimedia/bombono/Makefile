# Created by: Stas Timokhin <stast@bsdportal.ru>
# $FreeBSD$

PORTNAME=	bombono
PORTVERSION=	1.2.2
PORTREVISION=	7
CATEGORIES=	multimedia
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-dvd/${PORTVERSION:R}
DISTNAME=	${PORTNAME}-dvd-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	DVD authoring program

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	gm:graphics/GraphicsMagick
LIB_DEPENDS=	libxml++-2.6.so:textproc/libxml++26 \
		liblavfile.so:multimedia/mjpegtools \
		libdvdread.so:multimedia/libdvdread \
		libavcodec.so:multimedia/ffmpeg \
		libboost_filesystem.so:devel/boost-libs
RUN_DEPENDS=	gm:graphics/GraphicsMagick \
		enca:converters/enca \
		growisofs:sysutils/dvd+rw-tools \
		toolame:audio/toolame

USES=		desktop-file-utils gettext pkgconfig scons shared-mime-info \
		tar:bzip2
USE_GNOME=	gtkmm24
INSTALLS_ICONS=	yes

CXXFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -lintl
MAKE_ARGS=	DVDREAD_INCLUDE=${LOCALBASE}/include \
		DVDREAD_LIBPATH=${LOCALBASE}/lib \
		CXXFLAGS="${CXXFLAGS}" LDFLAGS="${LDFLAGS}" \
		CC="${CC}" CXX="${CXX}" USE_EXT_BOOST=true

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD && ${OSVERSION} > 1000023
USES+=		compiler:gcc-c++11-lib
.endif

post-install:
.for i in bombono-dvd mpeg2demux
	${INSTALL_MAN} ${WRKSRC}/docs/man/man1/${i}.1 ${STAGEDIR}${MANPREFIX}/man/man1
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${i}
.endfor

.include <bsd.port.mk>
