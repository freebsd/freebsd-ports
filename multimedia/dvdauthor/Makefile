# Created by: pb@FreeBSD.org
# $FreeBSD$

PORTNAME=	dvdauthor
PORTVERSION=	0.7.1
PORTREVISION=	10
CATEGORIES=	multimedia
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Makes a DVD file structure from one or more MPEG2 streams

LICENSE=	GPLv2

LIB_DEPENDS=	libdvdread.so:multimedia/libdvdread \
		libfribidi.so:converters/fribidi \
		libfreetype.so:print/freetype2 \
		libpng.so:graphics/png \
		libexpat.so:textproc/expat2 \
		libfontconfig.so:x11-fonts/fontconfig

WRKSRC=		${WRKDIR}/${PORTNAME}

USES=		gmake iconv pkgconfig
USE_GNOME=	libxml2
GNU_CONFIGURE=	yes
CFLAGS+=	-I${LOCALBASE}/include -L${LOCALBASE}/lib

PORTDOCS=	*

DOCSRCDIR1=	${WRKSRC}
DOC_FILES1=	AUTHORS ChangeLog README

DOCSRCDIR2=	${WRKDIR}
DOC_FILES2=	README.FreeBSD

OPTIONS_DEFINE=	DOCS IMAGEMAGICK VIDEO-FORMAT

OPTIONS_SINGLE=	VIDEO-FORMAT
OPTIONS_SINGLE_VIDEO-FORMAT=	NTSC PAL

VIDEO-FORMAT_DESC=	Use default video format
NTSC_DESC=	Default video format NTSC
PAL_DESC=	Default video format PAL

SUB_FILES=	README.FreeBSD

IMAGEMAGICK_LIB_DEPENDS=	libMagick++-6.so:graphics/ImageMagick

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNTSC}
.if ${PORT_OPTIONS:MVIDEO-FORMAT}
CONFIGURE_ENV+=	--enable-default-video-format=NTSC
.endif
.endif

.if ${PORT_OPTIONS:MPAL}
.if ${PORT_OPTIONS:MVIDEO-FORMAT}
CONFIGURE_ENV+=	--enable-default-video-format=PAL
.endif
.endif

pre-configure:
.if ! ${PORT_OPTIONS:MIMAGEMAGICK}
	@${REINPLACE_CMD} 's|usemagick=1|usemagick=0|g' \
		${WRKSRC}/configure
.endif

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DOC_FILES1:S|^|${DOCSRCDIR1}/|} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DOC_FILES2:S|^|${DOCSRCDIR2}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
