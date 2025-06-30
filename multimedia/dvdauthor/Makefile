PORTNAME=	dvdauthor
PORTVERSION=	0.7.2.20211105
PORTREVISION=	6
CATEGORIES=	multimedia

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Makes a DVD file structure from one or more MPEG2 streams
WWW=		https://dvdauthor.sourceforge.net/ https://github.com/ldo/dvdauthor

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libdvdread.so:multimedia/libdvdread \
		libfribidi.so:converters/fribidi \
		libfreetype.so:print/freetype2 \
		libpng.so:graphics/png \
		libexpat.so:textproc/expat2 \
		libfontconfig.so:x11-fonts/fontconfig

USE_GITHUB=	yes
GH_ACCOUNT=	ldo
GH_TAGNAME=	fe8fe35

USES=		autoreconf:build bison:alias gettext-tools \
		gmake gnome iconv localbase pkgconfig
USE_GNOME=	libxml2
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share

SUB_FILES=	README.FreeBSD

PORTDOCS=	*

OPTIONS_DEFINE=			DOCS MANPAGES
OPTIONS_RADIO=			IMAGEMAGICK VIDEO-FORMAT
OPTIONS_RADIO_IMAGEMAGICK=	GRAPHICSMAGICK IMAGEMAGICK6
OPTIONS_RADIO_VIDEO-FORMAT=	NTSC PAL
OPTIONS_SUB=			yes

GRAPHICSMAGICK_DESC=		GraphicsMagick image processing support
IMAGEMAGICK6_DESC=		ImageMagick 6.x image processing support
NTSC_DESC=			Default video format NTSC
PAL_DESC=			Default video format PAL
VIDEO-FORMAT_DESC=		Use default video format

GRAPHICSMAGICK_CONFIGURE_WITH=	graphicsmagick
GRAPHICSMAGICK_LIB_DEPENDS=	libGraphicsMagick.so:graphics/GraphicsMagick
IMAGEMAGICK6_CONFIGURE_WITH=	imagemagick
IMAGEMAGICK6_USES=		magick:6
MANPAGES_BUILD_DEPENDS=		docbook2man:textproc/docbook-utils \
				docbook-sgml>0:textproc/docbook-sgml
NTSC_CONFIGURE_ON=		--enable-default-video-format=NTSC
PAL_CONFIGURE_ON=		--enable-default-video-format=PAL

pre-configure-MANPAGES-off:
	@(${MV} ${WRKSRC}/doc/Makefile.am ${WRKSRC}/doc/Makefile.am.bak && \
	 ${GREP} '^dist_pkgdata_DATA' \
		${WRKSRC}/doc/Makefile.am.bak > ${WRKSRC}/doc/Makefile.am)

pre-configure:
	@(cd ${WRKSRC} && ${MKDIR} autotools/ && \
	 ${CP} ${LOCALBASE}/share/gettext/config.rpath autotools/ && \
	 ${LOCALBASE}/bin/autoreconf -i)

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} \
		${WRKSRC}/AUTHORS ${WRKSRC}/ChangeLog ${WRKSRC}/README \
		${WRKSRC}/TODO ${WRKDIR}/README.FreeBSD ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
