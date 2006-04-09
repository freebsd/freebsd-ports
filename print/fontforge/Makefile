# New ports collection makefile for:	fontforge
# Date created:		25 March 2001
# Whom:			KANOU Hiroki <kanou@khdd.net>
#
# $FreeBSD$
#

PORTNAME=	fontforge
PORTVERSION=	20060406
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	fontforge
DISTFILES=	${EXTRACT_ONLY} ${DOCFILES}
EXTRACT_ONLY=	${PORTNAME}_full-${PORTVERSION}.tar.bz2
.if defined(FONTFORGE_WITH_TTF_DEBUGGER)
FREETYPE_VERSION=	2.1.10
EXTRACT_ONLY+=	freetype-${FREETYPE_VERSION}.tar.bz2
.endif

MAINTAINER=	kanou@khdd.net
COMMENT=	Type 1/TrueType/OpenType/bitmap font editor

LIB_DEPENDS=	uninameslist.0:${PORTSDIR}/textproc/libuninameslist \
		tiff.4:${PORTSDIR}/graphics/tiff \
		jpeg.9:${PORTSDIR}/graphics/jpeg \
		png.5:${PORTSDIR}/graphics/png \
		ungif.5:${PORTSDIR}/graphics/libungif \
		freetype.9:${PORTSDIR}/print/freetype2 \
		xml2.5:${PORTSDIR}/textproc/libxml2

DOC_VERSION=	${PORTVERSION}
DOCFILES=	${PORTNAME}_htdocs-${DOC_VERSION}.tar.bz2
.if !defined(NOPORTDOCS)
DOCFILES+=	${PORTNAME}_ja_htdocs-${DOC_VERSION}.tar.bz2
.endif

USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_ICONV=	yes
USE_XLIB=	yes
PATCH_STRIP=	-l

CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
.if !defined(FONTFORGE_NO_MULTILAYER)
WITH_MULTILAYER=	--with-multilayer
.endif
.if !defined(WITHOUT_TTF_BYTECODE_ENABLED) && defined(FONTFORGE_WITH_TTF_DEBUGGER)
WITH_FREETYPE_SRC=	--with-freetype-src=${WRKDIR}/freetype-${FREETYPE_VERSION}
.else
WITH_FREETYPE_SRC=	--without-freetype-src
.endif
CONFIGURE_ARGS=	${WITH_MULTILAYER} --with-devicetables ${WITH_FREETYPE_SRC}
CONFIGURE_ENV=	LDFLAGS="-L${LOCALBASE}/lib" CFLAGS="${CFLAGS} \
		-I${LOCALBASE}/include -I${LOCALBASE}/include/freetype2 \
		-L${LOCALBASE}/lib" CPPFLAGS="-I${LOCALBASE}/include \
		-I${LOCALBASE}/include/freetype2"

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
INSTALLS_SHLIB=	yes
GNU_CONFIGURE=	yes

MAN1=		fontforge.1 sfddiff.1

pre-everything::
.if defined(WITHOUT_EXTRA_ENCODINGS)
	@${ECHO_MSG} "WARNING: You should not compile libiconv with WITHOUT_EXTRA_ENCODINGS"
	@${ECHO_MSG} "defined, because libiconv must be configured with --enable-extra-encoding"
	@${ECHO_MSG} "as FontForge requires Shift-JIS."
	@${ECHO_MSG} ""
.endif
.if !defined(WITHOUT_TTF_BYTECODE_ENABLED) && !defined(FONTFORGE_WITH_TTF_DEBUGGER)
	@${ECHO_MSG} "If you have built freetype2 port with bytecode interpreter enabled,"
	@${ECHO_MSG} "You can use TTF instruction debugger by compiling fontforge port"
	@${ECHO_MSG} "with FONTFORGE_WITH_TTF_DEBUGGER defined."
	@${ECHO_MSG} "Note that you must put the source archive of FreeType in ${DISTDIR}."
	@${ECHO_MSG} "If you have installed freetype2 from a package, chdir to ${PORTSDIR}/print/"
	@${ECHO_MSG} "and execute 'make fetch' before building this port".
	@${ECHO_MSG} ""
.endif
.if !defined(FONTFORGE_NO_MULTILAYER)
	@${ECHO_MSG} "If your machine has small memory and you have to edit fonts with a lot"
	@${ECHO_MSG} "of glyphs, you can save memory by defining FONTFORGE_NO_MULTILAYER."
	@${ECHO_MSG} "Enabling multilayer editing increases memory consumption per glyph."
	@${ECHO_MSG} ""
.endif

post-extract:
	${MKDIR} ${WRKDIR}/html ${WRKSRC}/cidmap
	for doc in ${DOCFILES} ; \
		do ${TAR} -xzC ${WRKDIR}/html -f ${DISTDIR}/$${doc} ; \
	done
	${TAR} -xzC ${WRKSRC}/cidmap -f ${WRKDIR}/html/cidmaps.tgz
	${RM} ${WRKDIR}/html/cidmaps.tgz

.if !defined(FONTFORGE_NO_PLUGINS)
post-build:
	cd ${WRKSRC}/plugins; ${GMAKE}
.endif

post-install:
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/LICENSE ${DOCSDIR}
.if !defined(FONTFORGE_NO_PLUGINS)
	${MKDIR} ${PREFIX}/share/fontforge/plugins
	(cd ${WRKSRC}/plugins; ${INSTALL_DATA} .libs/* ${PREFIX}/share/fontforge/plugins )
.endif
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}/flags ${DOCSDIR}/ja ${DOCSDIR}/ja/nonBMP/
	${INSTALL_DATA} ${WRKDIR}/html/*.* ${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/html/flags/* ${DOCSDIR}/flags
	${INSTALL_DATA} ${WRKDIR}/html/ja/*.* ${DOCSDIR}/ja
	${INSTALL_DATA} ${WRKDIR}/html/ja/nonBMP/*.* ${DOCSDIR}/ja/nonBMP
.endif

.include <bsd.port.mk>
