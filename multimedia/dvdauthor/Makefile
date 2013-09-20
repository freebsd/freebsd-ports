# Created by: pb@FreeBSD.org
# $FreeBSD$

PORTNAME=	dvdauthor
PORTVERSION=	0.7.1
CATEGORIES=	multimedia
MASTER_SITES=	SF

MAINTAINER=	nemysis@gmx.ch
COMMENT=	Makes a DVD file structure from one or more MPEG2 streams

LICENSE=	GPLv2

LIB_DEPENDS=	dvdread:${PORTSDIR}/multimedia/libdvdread \
		fribidi:${PORTSDIR}/converters/fribidi \
		freetype:${PORTSDIR}/print/freetype2 \
		png15:${PORTSDIR}/graphics/png \
		expat:${PORTSDIR}/textproc/expat2 \
		fontconfig:${PORTSDIR}/x11-fonts/fontconfig

WRKSRC=		${WRKDIR}/${PORTNAME}

USES=		pkgconfig iconv
USE_GNOME=	libxml2
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
CFLAGS+=	-I${LOCALBASE}/include -L${LOCALBASE}/lib

DOCSRCDIR1=	${WRKSRC}
DOC_FILES1=	AUTHORS ChangeLog README TODO

DOCSRCDIR2=	${WRKDIR}
DOC_FILES2=	README.FreeBSD

MAN1=		dvdauthor.1 dvddirdel.1 dvdunauthor.1 mpeg2desc.1 spumux.1 spuunmux.1

OPTIONS_DEFINE=	VIDEO-FORMAT IMAGEMAGICK

OPTIONS_SINGLE=	VIDEO-FORMAT
OPTIONS_SINGLE_VIDEO-FORMAT=	NTSC PAL

VIDEO-FORMAT_DESC=	Use default video format
NTSC_DESC=	Default video format NTSC
PAL_DESC=	Default video format PAL

SUB_FILES=	README.FreeBSD

NO_STAGE=	yes
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

.if ${PORT_OPTIONS:MIMAGEMAGICK}
LIB_DEPENDS+=	Magick:${PORTSDIR}/graphics/ImageMagick
.endif

pre-configure:
.if !${PORT_OPTIONS:MIMAGEMAGICK}
	@${REINPLACE_CMD} 's|usemagick=1|usemagick=0|g' \
		${WRKSRC}/configure
.endif

post-install:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${DOC_FILES1:S|^|${DOCSRCDIR1}/|} ${DOCSDIR}
	${INSTALL_DATA} ${DOC_FILES2:S|^|${DOCSRCDIR2}/|} ${DOCSDIR}
.endif

.include <bsd.port.mk>
