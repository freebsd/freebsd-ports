# Created by: KANOU Hiroki <kanou@khdd.net>
# $FreeBSD$

PORTNAME=	fontforge
DISTVERSION=	20120731-b
PORTREVISION=	2
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

LIB_DEPENDS=	uninameslist:${PORTSDIR}/textproc/libuninameslist \
		tiff:${PORTSDIR}/graphics/tiff \
		jpeg:${PORTSDIR}/graphics/jpeg \
		png15:${PORTSDIR}/graphics/png \
		gif:${PORTSDIR}/graphics/giflib \
		xml2:${PORTSDIR}/textproc/libxml2 \
		spiro:${PORTSDIR}/graphics/libspiro

USE_BZIP2=	yes
USES=		gettext iconv
USE_XORG=	x11 xi ice xkbui
USE_GMAKE=	yes
PATCH_STRIP=	-l

OPTIONS_DEFINE=	DOCS MULTILAYER FREETYPE PLUGINS PYTHON CAIRO PYTHON
OPTIONS_DEFAULT=	DOCS MULTILAYER PLUGINS
MULTILAYER_DESC=	type3/SVG multilayer font support

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
DOC_VERSION=	${DISTVERSION}
MASTER_SITES+=	SF/${PORTNAME}/${PORTNAME}-docs:docs
DOCFILES=	${PORTNAME}_htdocs-${DOC_VERSION}.tar.bz2
DISTFILES+=	${DOCFILES:C/$/:docs/}
.endif

.if ${PORT_OPTIONS:MMULTILAYER}
WITH_TYPE3_MULTILAYER=	--enable-type3
.else
WITH_TYPE3_MULTILAYER=	--disable-type3
.endif

.if ${PORT_OPTIONS:MFREETYPE}
FREETYPE_VERSION=	2.4.11
FREETYPE_SRC=	freetype-${FREETYPE_VERSION}.tar.bz2
DISTFILES+=	${FREETYPE_SRC:C/$/:freetype/}
WITH_FREETYPE_SRC=	--enable-freetype --with-freetype-bytecode \
			--with-freetype-src=${WRKDIR}/freetype-${FREETYPE_VERSION}
LIB_DEPENDS+=	freetype:${PORTSDIR}/print/freetype2
.else
WITH_FREETYPE_SRC=	--disable-freetype --without-freetype-bytecode \
			--without-freetype-src
.endif

CONFIGURE_ARGS=	${WITH_TYPE3_MULTILAYER} --enable-devicetables ${WITH_FREETYPE_SRC} \
		--enable-pasteafter --enable-tilepath
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	libtool

MAN1=		fontforge.1 fontimage.1 fontlint.1 sfddiff.1

.if ${PORT_OPTIONS:MPLUGINS}
PLIST_SUB+=	NO_PLUGINS=""
.else
PLIST_SUB+=	NO_PLUGINS="@comment "
.endif

.if ${PORT_OPTIONS:MPYTHON}
USE_PYTHON=	yes
ONLY_FOR_ARCHS=	i386
ONLY_FOR_ARCHS_REASON=	Python on non-i386 systems doesn't link with Fontforge (issues with use of Python's .a file)
CONFIGURE_ARGS+=	--with-python
LDFLAGS+=	-lutil
.else
CONFIGURE_ARGS+=	--without-python
.endif

.if ${PORT_OPTIONS:MCAIRO}
LIB_DEPENDS+=	cairo:${PORTSDIR}/graphics/cairo
CONFIGURE_ARGS+=	--with-cairo
.else
CONFIGURE_ARGS+=	--without-cairo
.endif

.if ${PORT_OPTIONS:MPANGO}
USE_GNOME+=	pango
CONFIGURE_ARGS+=	--with-pango
.else
CONFIGURE_ARGS+=	--without-pango
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
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/LICENSE ${DOCSDIR}
.if ${PORT_OPTIONS:MPLUGINS}
	${MKDIR} ${PREFIX}/share/fontforge/plugins
	(cd ${WRKSRC}/plugins; ${INSTALL_DATA} .libs/* ${PREFIX}/share/fontforge/plugins)
.endif
.if ${PORT_OPTIONS:MDOCS}
# Ditto the above note in post-extract for these comments
#	${MKDIR} ${DOCSDIR}/flags
	${INSTALL_DATA} ${WRKDIR}/html/*.* ${DOCSDIR}
#	${INSTALL_DATA} ${WRKDIR}/html/flags/*.* ${DOCSDIR}/flags
.endif

.include <bsd.port.mk>
