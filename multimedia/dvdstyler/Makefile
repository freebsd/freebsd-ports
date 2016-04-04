# Created by: Michael Johnson <ahze@ahze.net>
# $FreeBSD$

PORTNAME=	dvdstyler
PORTVERSION=	2.9.6
PORTEPOCH=	2
CATEGORIES=	multimedia
MASTER_SITES=	SF
DISTNAME=	DVDStyler-${PORTVERSION}

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	WxWidgets frontend to dvd recoding and authoring programs

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	zip:archivers/zip \
		wxsvg>=1.2:graphics/wxsvg \
		dvdauthor:multimedia/dvdauthor \
		mplex:multimedia/mjpegtools \
		growisofs:sysutils/dvd+rw-tools \
		docbook-xml>=4.1.2:textproc/docbook-xml \
		xmlto:textproc/xmlto
LIB_DEPENDS=	libexif.so:graphics/libexif \
		libavcodec.so:multimedia/ffmpeg
RUN_DEPENDS=	zip:archivers/zip \
		wxsvg>=1.2:graphics/wxsvg \
		dvdauthor:multimedia/dvdauthor \
		mplex:multimedia/mjpegtools \
		mkisofs:sysutils/cdrtools \
		growisofs:sysutils/dvd+rw-tools

USES=		autoreconf compiler:c++11-lib gettext gmake pkgconfig tar:bzip2
USE_CXXSTD=	gnu++11
USE_WX=		3.0
WX_CONF_ARGS=	absolute
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	ac_cv_path_AVCONV_PATH="" OBJCXX="${CXX}"

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_DEFINE=	DOCS GNOME

GNOME_USE=		GNOME=libgnomeui
GNOME_CONFIGURE_WITH=	gnome

.if defined(WITH_DVD_DEVICE)
DEFAULT_DVD_DEVICE=${WITH_DVD_DEVICE}
.else
DEFAULT_DVD_DEVICE=/dev/cd0
.endif

pre-everything::
.if !defined(WITH_DVD_DEVICE)
	@${ECHO_MSG} "===>"
	@${ECHO_MSG} "===> The default DVD device is ${DEFAULT_DVD_DEVICE}"
	@${ECHO_MSG} "===> Define WITH_DVD_DEVICE if you want to change the default"
	@${ECHO_MSG} "===> For example, 'make WITH_DVD_DEVICE=\"/dev/somedevice\"'"
.endif

post-patch:
	@${REINPLACE_CMD} -e '/doc_DATA/s|COPYING||' \
		${WRKSRC}/Makefile.am
	@${REINPLACE_CMD} -e 's|"sg\*"|"cd*"|g' \
		${WRKSRC}/src/SysUtils.cpp
	@${REINPLACE_CMD} -e 's|/dev/dvd|${DEFAULT_DVD_DEVICE}|g' \
		${WRKSRC}/src/Config.h

.include <bsd.port.mk>
