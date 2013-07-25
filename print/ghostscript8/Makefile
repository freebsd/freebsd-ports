# Created by: Andreas Klemm <andreas@klemm.gtn.com>
# $FreeBSD$

PORTNAME=	ghostscript
PORTVERSION=	8.71
PORTREVISION=	13
CATEGORIES=	print
MASTER_SITES=	http://downloads.ghostscript.com/public/:gs_srcs \
		SF/ghostscript/GPL%20Ghostscript/${PORTVERSION}:gs_srcs \
		ftp://mirror.cs.wisc.edu/pub/mirrors/ghost/GPL/gs${PORTVERSION:S/.//}/:gs_srcs \
		http://www.humblesoft.com/pub/:epag
MASTER_SITE_SUBDIR=	ghostscript/:gs_srcs
PKGNAMESUFFIX=	8
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:gs_srcs ${EPAG_SRCS}:epag
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}
EXTRACT_AFTER_ARGS=	${EXCLUDE_DIRS:S/^/--exclude /}

MAINTAINER=	doceng@FreeBSD.org
COMMENT=	Ghostscript 8.x PostScript interpreter

LICENSE=	GPLv3

LIB_DEPENDS=	expat:${PORTSDIR}/textproc/expat2 \
		jasper:${PORTSDIR}/graphics/jasper \
		jbig2dec:${PORTSDIR}/graphics/jbig2dec \
		jpeg:${PORTSDIR}/graphics/jpeg \
		png15:${PORTSDIR}/graphics/png \
		paper:${PORTSDIR}/print/libpaper \
		tiff:${PORTSDIR}/graphics/tiff
RUN_DEPENDS=	${LOCALBASE}/share/${PORTNAME}/fonts/a010013l.pfb:${PORTSDIR}/print/gsfonts

CONFLICTS_INSTALL= \
		gambc-[0-9]* \
		ghostscript[79]-[0-9]* \
		ghostscript[79]-nox11-[0-9]* \
		ghostscript9-agpl-[0-9]* \
		ghostscript9-agpl-nox11-[0-9]*

USE_XZ=		yes
USES=		gmake
WANT_GNOME=	yes
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	autoconf
GNU_CONFIGURE=	yes

MAKE_JOBS_UNSAFE=	yes
MAKE_ENV=	CFLAGS_STANDARD="${CFLAGS}" \
		XCFLAGS="${XCFLAGS}" XLDFLAGS="${XLDFLAGS}" \
		EXTRALIBS="${EXTRALIBS}" \
		SOC_LOADER="dxmainc.c"
CONFIGURE_ENV=	${MAKE_ENV}
CONFIGURE_ARGS=	--disable-compile-inits \
		--enable-contrib \
		--enable-dynamic \
		--with-ijs \
		--with-jasper \
		--with-libpaper \
		--with-drivers=""
CPPFLAGS+=	-DUPD_SIGNAL=0 -I. \
		-I${WRKSRC}/jasper/src/libjasper/include \
		-I${LOCALBASE}/include/libpng15 \
		-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
XCFLAGS=	${PTHREAD_CFLAGS} \
		-DA4
XLDFLAGS=	${PTHREAD_LIBS}

PLIST_SUB=	GS_VERSION="${PORTVERSION}" \
		CIDFONTDIR="${CIDFONTDIR:S,^${PREFIX}/,,}"
SUB_FILES=	pkg-message
SUB_LIST=	DATADIR=${DATADIR} PORTVERSION=${PORTVERSION}
PKGMESSAGE=	${WRKDIR}/pkg-message

OPTIONS_DEFINE=	X11 DOCS CAIRO CUPS FONTCONFIG FT_BRIDGE GTK2 ICONV
OPTIONS_DEFAULT=X11 DOCS CAIRO CUPS FONTCONFIG                ICONV
FONTCONFIG_DESC=Enable fontconfig support
FT_BRIDGE_DESC=	Enable FreeType Bridge support
NO_OPTIONS_SORT=yes

MAN1=		dvipdf.1 font2c.1 gs.1 gslp.1 gsnd.1 \
		pdf2dsc.1 pdf2ps.1 pdfopt.1 pf2afm.1 pfbtopfa.1 printafm.1 \
		ps2ascii.1 ps2epsi.1 ps2pdf.1 ps2pdfwr.1 ps2ps.1 wftopfa.1
MLINKS=		gslp.1 gsbj.1 \
		gslp.1 gsdj.1 \
		gslp.1 gsdj500.1 \
		gslp.1 gslj.1 \
		ps2pdf.1 ps2pdf12.1 \
		ps2pdf.1 ps2pdf13.1 \
		ps2ps.1 eps2eps.1

CIDFONTDIR=	${DATADIR}/${PORTVERSION}/Resource
EXCLUDE_DIRS=	jbig2dec jpeg expat jasper libpng tiff zlib

.include "Makefile.drivers"
.include <bsd.port.options.mk>
.include "files/Makefile.drivers_post"

.for D in ${OPTIONS_DEFINE:MGS_*:S/^GS_//} \
	${OPTIONS_MULTI_X11:MGS_*:S/^GS_//} \
	${OPTIONS_GROUP_ICONV:MGS_*:S/^GS_//} \
	${OPTIONS_GROUP_SVGALIB:MGS_*:S/^GS_//}
.if ${PORT_OPTIONS:MGS_${D}}
PLIST_SUB+=	GS_${D}=""
.else
PLIST_SUB+=	GS_${D}="@comment "
.endif
.endfor

.if ${PORT_OPTIONS:MFONTCONFIG}
LIB_DEPENDS+=	fontconfig:${PORTSDIR}/x11-fonts/fontconfig
CONFIGURE_ARGS+=	--enable-fontconfig
.else
CONFIGURE_ARGS+=	--disable-fontconfig
.endif

.if ${PORT_OPTIONS:MFT_BRIDGE}
LIB_DEPENDS+=	freetype:${PORTSDIR}/print/freetype2
MAKE_ENV+=	FT_BRIDGE=1 FT_ROOT="${WRKSRC}/freetype" FT_LIB_EXT=".so"
CPPFLAGS+=	-I${LOCALBASE}/include/freetype2
PLIST_SUB+=	FAPI=""
.else
PLIST_SUB+=	FAPI="@comment "
.endif

ALL_TARGET=	so
INSTALL_TARGET=	soinstall
USE_LDCONFIG=	yes
PLIST_SUB+=	SHLIB_VER="${PORTVERSION:R}"

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
	${REINPLACE_CMD} -e 's|%%DATADIR%%|${DATADIR}|g ; \
		 s|%%GS_VERSION%%|${PORTVERSION}|g' \
			${WRKSRC}/contrib/japanese/dmp_site.ps

pre-build-drivers.mak:
	@${ECHO_CMD} '# automatically generated' > ${WRKSRC}/base/drivers.mak
.for N in ${DEVS_LIST}
	@${ECHO_CMD} 'DEVICE_${N}=' >> ${WRKSRC}/base/drivers.mak
.endfor
.for D in ${OPTIONS_DEFINE:MGS_*:S/^GS_//} \
	${OPTIONS_MULTI_X11:MGS_*:S/^GS_//} \
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
	${MKDIR} ${WRKSRC}/obj
	${MKDIR} ${WRKSRC}/bin
.if ${PORT_OPTIONS:MFT_BRIDGE}
	${MKDIR} ${WRKSRC}/freetype/include
	${LN} -s -f ${LOCALBASE}/include/ft2build.h \
		${WRKSRC}/freetype/include/ft2build.h
	${LN} -s -f ${LOCALBASE}/include/freetype2/freetype \
		${WRKSRC}/freetype/include/freetype
	${MKDIR} ${WRKSRC}/freetype/objs
	${LN} -s -f ${LOCALBASE}/lib/libfreetype.so \
		${WRKSRC}/freetype/objs/freetype214MT_D.so
.endif

pre-su-install:
	${MKDIR} ${DATADIR}

post-install-docs:
	${MKDIR} ${WRKSRC}/contrib/japanese
	${INSTALL_DATA} ${WRKSRC}/contrib/japanese/doc/* ${WRKSRC}/contrib/japanese
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC}/contrib && \
		${TAR} -cf - ${PORTDOC_FILES} | \
		( cd ${DOCSDIR} && ${TAR} -xof - )

.if ${PORT_OPTIONS:MFT_BRIDGE}
post-install-fapi:
	${INSTALL_DATA} ${WRKSRC}/lib/FAPIcidfmap			\
		${WRKSRC}/lib/FAPIconfig ${WRKSRC}/lib/FAPIfontmap	\
		${DATADIR}/${PORTVERSION}/Resource/Init

post-install: post-install-fapi
.endif

post-install:
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${DATADIR}/${PORTVERSION}
	${STRIP_CMD} ${PREFIX}/bin/gsc ${PREFIX}/bin/gsx
	${LN} -sf gsc ${PREFIX}/bin/gs
	${LN} -s -f ${LOCALBASE}/share/fonts/CIDFont ${CIDFONTDIR}/CIDFont
	@${ECHO_MSG}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG}

.if ${PORT_OPTIONS:MDOCS}
post-install: post-install-docs
.endif

.include <bsd.port.mk>
