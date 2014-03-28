# Created by: KANOU Hiroki <kanou@khdd.net>
# $FreeBSD$

PORTNAME=	fontforge
DISTVERSION=	20120731-b
PORTREVISION=	3
CATEGORIES=	print
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-source \
		SF/freetype/${PORTNAME}/${PORTVERSION}:freetype \
		http://sunsite.cnlab-switch.ch/ftp/mirror/freetype/freetype2/:freetype \
		http://www.funet.fi/pub/mirrors/ftp.freetype.org/freetype2/:freetype \
		http://ftp.sunet.se/pub/text-processing/freetype/freetype2/:freetype \
		${MASTER_SITE_RINGSERVER:S,%SUBDIR%,graphics/freetype/&,}:freetype \
		ftp://ftp.freetype.org/freetype/freetype2/:freetype
DISTFILES=	${PORTNAME}_full-${DISTVERSION}.tar.bz2

MAINTAINER=	cyberbotx@cyberbotx.com
COMMENT=	Type 1/TrueType/OpenType/bitmap font editor

LIB_DEPENDS=	libuninameslist.so:${PORTSDIR}/textproc/libuninameslist \
		libtiff.so:${PORTSDIR}/graphics/tiff \
		libjpeg.so:${PORTSDIR}/graphics/jpeg \
		libpng15.so:${PORTSDIR}/graphics/png \
		libgif.so:${PORTSDIR}/graphics/giflib \
		libxml2.so:${PORTSDIR}/textproc/libxml2 \
		libspiro.so:${PORTSDIR}/graphics/libspiro

USES=		gettext gmake iconv tar:bzip2
USE_XORG=	x11 xi ice xkbui
PATCH_STRIP=	-l

CONFIGURE_ARGS=	--enable-devicetables --enable-pasteafter --enable-tilepath
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	libtool

OPTIONS_DEFINE=	DOCS MULTILAYER FREETYPE PLUGINS PYTHON CAIRO PANGO
OPTIONS_SUB=	yes
OPTIONS_DEFAULT=	MULTILAYER PLUGINS
MULTILAYER_DESC=	Type3/SVG multilayer font support

FREETYPE_LIB_DEPENDS=	libfreetype.so:${PORTSDIR}/print/freetype2
FREETYPE_CONFIGURE_ENABLE=	freetype
FREETYPE_CONFIGURE_WITH=	freetype-bytecode

MULTILAYER_CONFIGURE_ENABLE=	type3

PYTHON_USE=	PYTHON=yes
PYTHON_CONFIGURE_WITH=	python
PYTHON_LDFLAGS=	-lutil

CAIRO_USE=	GNOME=cairo
CAIRO_CONFIGURE_WITH=	cairo

PANGO_USE=	GNOME=pango
PANGO_CONFIGURE_WITH=	pango

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
DOC_VERSION=	${DISTVERSION}
MASTER_SITES+=	SF/${PORTNAME}/${PORTNAME}-docs:docs
DOCFILES=	${PORTNAME}_htdocs-${DOC_VERSION}.tar.bz2
DISTFILES+=	${DOCFILES:C/$/:docs/}
.endif

.if ${PORT_OPTIONS:MFREETYPE}
FREETYPE_VERSION=	2.5.3
FREETYPE_SRC=	freetype-${FREETYPE_VERSION}.tar.bz2
DISTFILES+=	${FREETYPE_SRC:C/$/:freetype/}
CONFIGURE_ARGS+=	--with-freetype-src=${WRKDIR}/freetype-${FREETYPE_VERSION}
.else
CONFIGURE_ARGS+=	--without-freetype-src
.endif

.if ${PORT_OPTIONS:MPYTHON}
ONLY_FOR_ARCHS=	i386
ONLY_FOR_ARCHS_REASON=	Python on non-i386 systems doesn't link with Fontforge (issues with use of Python's .a file)
.endif

pre-everything::
.if !${PORT_OPTIONS:MMULTILAYER}
	@${ECHO_MSG} "If your machine has small memory and you have to edit fonts with a lot"
	@${ECHO_MSG} "of glyphs, you can save memory by enabling the MULTILAYER option."
	@${ECHO_MSG} "Enabling multilayer editing increases memory consumption per glyph."
	@${ECHO_MSG} ""
.endif

.if ${PORT_OPTIONS:MDOCS}
post-extract:
	${MKDIR} ${WRKDIR}/html ${WRKSRC}/cidmap
	for doc in ${DOCFILES} ; \
		do ${TAR} -xjC ${WRKDIR}/html -f ${DISTDIR}/$${doc} ; \
	done
# The 20080607 and up versions of fontforge's documentation doesn't contain the cidmaps,
#  but I'm leaving this here just in case they are added back in a later version.
#	${TAR} -xzC ${WRKSRC}/cidmap -f ${WRKDIR}/html/cidmaps.tgz
#	${RM} ${WRKDIR}/html/cidmaps.tgz
.endif

post-patch:
	@${CHMOD} +x ${WRKSRC}/configure

.if ${PORT_OPTIONS:MPLUGINS}
post-build:
	cd ${WRKSRC}/plugins; ${GMAKE}
.endif

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/LICENSE ${STAGEDIR}${DOCSDIR}
.if ${PORT_OPTIONS:MPLUGINS}
	${MKDIR} ${STAGEDIR}${PREFIX}/share/fontforge/plugins
	@(cd ${WRKSRC}/plugins/.libs && ${STRIP_CMD} gb12345.o gb12345.so)
	(cd ${WRKSRC}/plugins; ${INSTALL_DATA} .libs/* \
		${STAGEDIR}${PREFIX}/share/fontforge/plugins)
.endif
.if ${PORT_OPTIONS:MDOCS}
	${INSTALL_DATA} ${WRKDIR}/html/*.* ${STAGEDIR}${DOCSDIR}
.endif
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	@(cd ${STAGEDIR}${PREFIX}/lib && ${STRIP_CMD} libgunicode.so.3 \
		libgutils.so.1 libgioftp.so.1 libgdraw.so.4 libfontforge.so.1)

.include <bsd.port.mk>
