# Created by: pb@FreeBSD.org
# $FreeBSD$

PORTNAME=	dvdauthor
PORTVERSION=	0.7.2
PORTREVISION=	1
CATEGORIES=	multimedia
MASTER_SITES=	SF/${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Makes a DVD file structure from one or more MPEG2 streams

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libdvdread.so:multimedia/libdvdread \
		libfribidi.so:converters/fribidi \
		libfreetype.so:print/freetype2 \
		libpng.so:graphics/png \
		libexpat.so:textproc/expat2 \
		libfontconfig.so:x11-fonts/fontconfig

WRKSRC=		${WRKDIR}/${PORTNAME}

USES=		gmake gnome iconv localbase pkgconfig
USE_GNOME=	libxml2
GNU_CONFIGURE=	yes

SUB_FILES=	README.FreeBSD

PORTDOCS=	*

OPTIONS_DEFINE=	DOCS IMAGEMAGICK
OPTIONS_RADIO=	VIDEO-FORMAT
OPTIONS_RADIO_VIDEO-FORMAT=	NTSC PAL

VIDEO-FORMAT_DESC=	Use default video format
NTSC_DESC=	Default video format NTSC
PAL_DESC=	Default video format PAL

IMAGEMAGICK_LIB_DEPENDS=	libMagick++-6.so:graphics/ImageMagick6

NTSC_CONFIGURE_ON=	--enable-default-video-format=NTSC
PAL_CONFIGURE_ON=	--enable-default-video-format=PAL

pre-configure-IMAGEMAGICK-off:
	@${REINPLACE_CMD} 's|usemagick=1|usemagick=0|g' \
		${WRKSRC}/configure

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} \
		${WRKSRC}/AUTHORS ${WRKSRC}/ChangeLog ${WRKSRC}/README \
		${WRKDIR}/README.FreeBSD ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
