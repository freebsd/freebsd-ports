# Created by: Michael Johnson <ahze@ahze.net>
# $FreeBSD$

PORTNAME=	dvdstyler
PORTVERSION=	2.4.3
PORTREVISION=	3
PORTEPOCH=	2
CATEGORIES=	multimedia
MASTER_SITES=	SF
DISTNAME=	DVDStyler-${PORTVERSION}

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	WxWidgets frontend to dvd recoding and authoring programs

LICENSE=	GPLv2

BUILD_DEPENDS=	zip:${PORTSDIR}/archivers/zip \
		wxsvg>=1.1.14:${PORTSDIR}/graphics/wxsvg \
		dvdauthor:${PORTSDIR}/multimedia/dvdauthor \
		mplex:${PORTSDIR}/multimedia/mjpegtools \
		growisofs:${PORTSDIR}/sysutils/dvd+rw-tools \
		docbook-sk>=4.1.2:${PORTSDIR}/textproc/docbook-sk \
		xmlto:${PORTSDIR}/textproc/xmlto 
LIB_DEPENDS=	exif:${PORTSDIR}/graphics/libexif \
		avcodec1:${PORTSDIR}/multimedia/ffmpeg1
RUN_DEPENDS=	zip:${PORTSDIR}/archivers/zip \
		wxsvg>=1.1.14:${PORTSDIR}/graphics/wxsvg \
		dvdauthor:${PORTSDIR}/multimedia/dvdauthor \
		mplex:${PORTSDIR}/multimedia/mjpegtools \
		mkisofs:${PORTSDIR}/sysutils/cdrtools \
		growisofs:${PORTSDIR}/sysutils/dvd+rw-tools

OPTIONS_DEFINE=	GNOME DOCS

USE_BZIP2=	yes
USES=		gettext pkgconfig
USE_WX=		2.8
WX_COMPS=	wx svg
WX_CONF_ARGS=	absolute
USE_GNOME=	desktopfileutils
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LIBAV_CFLAGS="${LIBAV_CFLAGS}" LIBAV_LIBS="${LIBAV_LIBS}" \
		ac_cv_path_FFMPEG_PATH="${LOCALBASE}/bin/ffmpeg1"
MAKE_ENV=	AM_CPPFLAGS="${LIBAV_CFLAGS}"

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

MAN1=		dvdstyler.1

LIBAV_PC=	libavcodec1 libavformat1 libavutil1 libswscale1
LIBAV_CFLAGS=	$$(pkg-config --cflags ${LIBAV_PC})
LIBAV_LIBS=	$$(pkg-config --libs ${LIBAV_PC})

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGNOME}
USE_GNOME+=	libgnomeui
GNOMEUI_PC=	libgnomeui-2.0
.else
GNOMEUI_PC=	_libgnomeui-2.0_
.endif

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

post-extract:
.for i in configure install-sh
	@${CHMOD} ${BINMODE} ${WRKSRC}/${i}
.endfor

post-patch:
	@${REINPLACE_CMD} -e '/GNOMEUI2/s|"libgnomeui-2.0"|"${GNOMEUI_PC}"|g' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e '/^install-data-am:/s|install-docDATA||g' \
		${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's|"sg\*"|"cd*"|g' \
		${WRKSRC}/src/BurnDlg.cpp
	@${REINPLACE_CMD} -e 's|/dev/dvd|${DEFAULT_DVD_DEVICE}|g' \
		${WRKSRC}/src/Config.h

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
.for i in AUTHORS ChangeLog INSTALL README
	(cd ${WRKSRC} && ${INSTALL_DATA} ${i} ${DOCSDIR})
.endfor
.endif
	@-update-desktop-database

.include <bsd.port.mk>
