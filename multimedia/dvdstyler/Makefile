# Created by: Michael Johnson <ahze@ahze.net>
# $FreeBSD$

PORTNAME=	dvdstyler
PORTVERSION=	2.7.1
PORTREVISION=	1
PORTEPOCH=	2
CATEGORIES=	multimedia
MASTER_SITES=	SF
DISTNAME=	DVDStyler-${PORTVERSION}

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	WxWidgets frontend to dvd recoding and authoring programs

LICENSE=	GPLv2

BUILD_DEPENDS=	zip:${PORTSDIR}/archivers/zip \
		wxsvg>=1.2:${PORTSDIR}/graphics/wxsvg \
		dvdauthor:${PORTSDIR}/multimedia/dvdauthor \
		mplex:${PORTSDIR}/multimedia/mjpegtools \
		growisofs:${PORTSDIR}/sysutils/dvd+rw-tools \
		docbook-xml>=4.1.2:${PORTSDIR}/textproc/docbook-xml \
		xmlto:${PORTSDIR}/textproc/xmlto
LIB_DEPENDS=	libexif.so:${PORTSDIR}/graphics/libexif \
		libavcodec.so:${PORTSDIR}/multimedia/ffmpeg
RUN_DEPENDS=	zip:${PORTSDIR}/archivers/zip \
		wxsvg>=1.2:${PORTSDIR}/graphics/wxsvg \
		dvdauthor:${PORTSDIR}/multimedia/dvdauthor \
		mplex:${PORTSDIR}/multimedia/mjpegtools \
		mkisofs:${PORTSDIR}/sysutils/cdrtools \
		growisofs:${PORTSDIR}/sysutils/dvd+rw-tools

USES=		gettext gmake pkgconfig tar:bzip2
USE_WX=		3.0
WX_UNICODE=	yes
WX_COMPS=	wx
WX_CONF_ARGS=	absolute
USE_AUTOTOOLS=	aclocal automake autoconf
ACLOCAL_ARGS=	-I ${WRKSRC}
AUTOMAKE_ARGS=	--add-missing --copy --force-missing --foreign
CONFIGURE_ENV=	ac_cv_path_AVCONV_PATH=no

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_DEFINE=	DOCS GNOME

GNOME_USE=		GNOME=libgnomeui
GNOME_CONFIGURE_WITH=	gnome

.include <bsd.port.options.mk>

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
	@${ECHO_CMD} -n > ${WRKSRC}/NEWS

post-patch:
	@${REINPLACE_CMD} -e '/doc_DATA/s|COPYING||' \
		${WRKSRC}/Makefile.am
	@${REINPLACE_CMD} -e 's|=\(dvdstyler.png\)|=${PREFIX}/share/pixmaps/\1|' \
		${WRKSRC}/data/dvdstyler.desktop
	@${REINPLACE_CMD} -e 's|"sg\*"|"cd*"|g' \
		${WRKSRC}/src/BurnDlg.cpp
	@${REINPLACE_CMD} -e 's|/dev/dvd|${DEFAULT_DVD_DEVICE}|g' \
		${WRKSRC}/src/Config.h

.include <bsd.port.mk>
