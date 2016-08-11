# Created by: Andreas Klemm <andreas@klemm.gtn.com>
# $FreeBSD$

PORTNAME=	ghostscript
PORTVERSION=	8.71
PORTREVISION=	21
CATEGORIES=	print
MASTER_SITES=	http://downloads.ghostscript.com/public/:gs_srcs \
		SF/ghostscript/GPL%20Ghostscript/${PORTVERSION}:gs_srcs \
		http://www.humblesoft.com/pub/:epag
PKGNAMESUFFIX=	8-base
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:gs_srcs ${EPAG_SRCS}:epag
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	doceng@FreeBSD.org
COMMENT=	Ghostscript 8.x PostScript interpreter, base part

LICENSE=	GPLv3

LIB_DEPENDS=	libexpat.so:textproc/expat2 \
		libfreetype.so:print/freetype2 \
		libjasper.so:graphics/jasper \
		libjbig2dec.so:graphics/jbig2dec \
		libpaper.so:print/libpaper \
		libpng.so:graphics/png \
		libtiff.so:graphics/tiff
RUN_DEPENDS=	${LOCALBASE}/share/${PORTNAME}/fonts/a010013l.pfb:print/gsfonts

CONFLICTS_INSTALL= \
		gambc-[0-9]* \
		ghostscript[789]-[0-9]* \
		ghostscript[789]-nox11-[0-9]* \
		ghostscript9-agpl-[0-9]* \
		ghostscript9-agpl-nox11-[0-9]*

USES=		autoreconf gmake pkgconfig shebangfix tar:xz
USE_LDCONFIG=	yes
SHEBANG_FILES=	${WRKSRC}/lib/fixmswrd.pl
EXTRACT_AFTER_ARGS=	${EXCLUDE_DIRS:S/^/--exclude /}
GNU_CONFIGURE=	yes
DATADIR=	${PREFIX}/share/${PORTNAME}/${PORTVERSION}
MAKE_JOBS_UNSAFE=	yes
MAKE_ENV=	CFLAGS_STANDARD="${CFLAGS}" \
		XCFLAGS="${XCFLAGS}" XLDFLAGS="${XLDFLAGS}" \
		FT_BRIDGE=1 FT_ROOT="${WRKSRC}/freetype" FT_LIB_EXT=".so" \
		SOC_LOADER="dxmainc.c"
CONFIGURE_ENV=	${MAKE_ENV}
CONFIGURE_ARGS=	--disable-compile-inits \
		--enable-contrib \
		--enable-dynamic \
		--with-ijs \
		--with-jasper \
		--with-libpaper \
		--without-x \
		--disable-gtk \
		--with-drivers=""
CPPFLAGS+=	-DUPD_SIGNAL=0 \
		-DJBIG_NO_MEMENTO \
		-I. \
		-I${WRKSRC}/jasper/src/libjasper/include \
		-I${LOCALBASE}/include/freetype2 \
		-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
XCFLAGS=	-DA4
XLDFLAGS=	-lpthread
ALL_TARGET=	so
INSTALL_TARGET=	soinstall
PLIST_SUB=	SHLIB_VER="${PORTVERSION:R}" \
		GS_VERSION="${PORTVERSION}"
SUB_FILES=	pkg-message
PKGMESSAGE=	${WRKDIR}/pkg-message

OPTIONS_DEFINE=	DOCS CAIRO CUPS FONTCONFIG ICONV
OPTIONS_DEFAULT=CAIRO CUPS FONTCONFIG ICONV
OPTIONS_SUB=	yes
FONTCONFIG_DESC=Enable fontconfig support
FONTCONFIG_LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig
FONTCONFIG_CONFIGURE_ENABLE=	fontconfig
NO_OPTIONS_SORT=yes

EXCLUDE_DIRS=	jbig2dec jpeg expat jasper libpng tiff zlib

.include "Makefile.drivers"
.include <bsd.port.options.mk>
.include "files/Makefile.drivers_post"

PORTDOCS=	japanese chp2200 epson740 lxm3200-tweaked md2k_md5k
PORTDOC_FILES=	japanese/Gdevlips.htm japanese/README.gs550j		\
	japanese/cdj880.txt japanese/dj505j.txt japanese/djgpp.txt	\
	japanese/gdev10v.txt japanese/gdevalps.txt			\
	japanese/gdevcd8.txt japanese/gdevdmpr.txt			\
	japanese/gdevfmlbp.txt japanese/gdevj100.txt			\
	japanese/gdevlbp3.txt japanese/gdevmag.txt			\
	japanese/gdevmd2k.txt japanese/gdevmjc.txt			\
	japanese/gdevml6.txt japanese/gdevp201.txt japanese/gs261j.euc	\
	japanese/gs261j.txt chp2200/AUTHORS chp2200/INSTALL		\
	epson740/README epson740/upp-HowTo-to-be			\
	lxm3200-tweaked/LICENSE lxm3200-tweaked/README			\
	lxm3200-tweaked/RELEASE_NOTES					\
	lxm3200-tweaked/Z12-Z31-QuickSetup md2k_md5k/README.jis

post-patch:
	${REINPLACE_CMD} -e 's,%%DATADIR%%,${DATADIR},' \
	    ${WRKSRC}/contrib/japanese/dmp_site.ps

pre-build-drivers.mak:
	@${ECHO_CMD} '# automatically generated' > ${WRKSRC}/base/drivers.mak
.for N in ${DEVS_LIST}
	@${ECHO_CMD} 'DEVICE_${N}=' >> ${WRKSRC}/base/drivers.mak
.endfor
.for D in ${OPTIONS_DEFINE:MGS_*:S/^GS_//} \
	${OPTIONS_GROUP_ICONV:MGS_*:S/^GS_//} \
	${OPTIONS_GROUP_SVGALIB:MGS_*:S/^GS_//}
.for N in ${DEVS_LIST}
.if ${PORT_OPTIONS:MGS_${D}}
.if !defined(OPTIONS_UNSET) || !${OPTIONS_UNSET:MGS_${D}}
.for X in ${DEVICE_${N}:M${D}.dev}
	@${ECHO_CMD} 'DEVICE_${N}+= $$(DD)${D}.dev'  >> ${WRKSRC}/base/drivers.mak
.endfor
.endif
.endif
.endfor
.endfor

pre-build: pre-build-drivers.mak
	${MKDIR} ${WRKSRC}/obj ${WRKSRC}/bin ${WRKSRC}/freetype/include
	${LN} -s -f ${LOCALBASE}/include/ft2build.h \
	    ${WRKSRC}/freetype/include/ft2build.h
	${LN} -s -f ${LOCALBASE}/include/freetype2/freetype \
	    ${WRKSRC}/freetype/include/freetype
	${MKDIR} ${WRKSRC}/freetype/objs
	${LN} -s -f ${LOCALBASE}/lib/libfreetype.so \
	    ${WRKSRC}/freetype/objs/freetype214MT_D.so

pre-install:
	cd ${WRKSRC}/Resource/Init && ${RM} -f \
	    gs_statd.ps.orig gs_ttf.ps.orig pdf_font.ps.orig
	${MKDIR} ${STAGEDIR}${DATADIR}

post-install-DOCS-on: post-install-docs
	${MKDIR} ${WRKSRC}/contrib/japanese
	${INSTALL_DATA} ${WRKSRC}/contrib/japanese/doc/* \
	    ${WRKSRC}/contrib/japanese
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/contrib && \
	    ${TAR} -cf - ${PORTDOC_FILES} | \
	    (cd ${STAGEDIR}${DOCSDIR} && ${TAR} -xof -)

post-install:
	${INSTALL_DATA} ${WRKSRC}/lib/FAPIcidfmap \
	    ${WRKSRC}/lib/FAPIconfig ${WRKSRC}/lib/FAPIfontmap \
	    ${STAGEDIR}${DATADIR}/Resource/Init
	${LN} -sf gsc ${STAGEDIR}${PREFIX}/bin/gs
	${LN} -s -f ${LOCALBASE}/share/fonts/CIDFont \
	    ${STAGEDIR}${DATADIR}/Resource/CIDFont

.include <bsd.port.mk>
