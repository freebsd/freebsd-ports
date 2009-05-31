# New ports collection makefile for:	ghostscript
# Date created:		Tue Jun 10 21:58:54 CEST 1997
# Whom:			Andreas Klemm <andreas@klemm.gtn.com>
#
# $FreeBSD$
#

PORTNAME=	ghostscript8
PORTVERSION=	8.64
PORTREVISION=	3
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:S/$/:gs_srcs/} \
		ftp://mirror.cs.wisc.edu/pub/mirrors/ghost/GPL/gs${PORTVERSION:S/.//}/:gs_srcs \
		http://www.humblesoft.com/pub/:epag
MASTER_SITE_SUBDIR=	ghostscript/:gs_srcs
DISTNAME=	${PORTNAME:S,8$,,}-${PORTVERSION}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:gs_srcs ${EPAG_SRCS}:epag
DIST_SUBDIR=	${PORTNAME:S,8$,,}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	doceng@FreeBSD.org
COMMENT=	Ghostscript 8.x PostScript interpreter

LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg \
		png.5:${PORTSDIR}/graphics/png \
		cupsimage.2:${PORTSDIR}/print/cups-image
RUN_DEPENDS=	${LOCALBASE}/share/${PORTNAME:S,8,,}/fonts/a010013l.pfb:${PORTSDIR}/print/gsfonts

CONFLICTS=	gambc-[0-9]* ghostscript7-[0-9]* ghostscript7-*-[0-9]*

USE_BZIP2=	yes
USE_GMAKE=	yes
WANT_GNOME=	yes
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
MAKE_JOBS_UNSAFE=	yes

MAKE_ENV=	CFLAGS_STANDARD="${CFLAGS}" \
		XCFLAGS="${XCFLAGS}" XLDFLAGS="${XLDFLAGS}" \
		EXTRALIBS="${EXTRALIBS}" \
		SOC_LOADER="dxmainc.c"
CONFIGURE_ENV=	${MAKE_ENV} \
		CPPFLAGS="-DUPD_SIGNAL=0 -I. -I${WRKSRC}/jasper/src/libjasper/include -I${LOCALBASE}/include/libpng -I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--disable-compile-inits \
		--enable-contrib \
		--enable-dynamic \
		--with-ijs \
		--with-jasper
XCFLAGS=	${PTHREAD_CFLAGS}
XLDFLAGS=	${PTHREAD_LIBS}

PLIST_SUB=	GS_VERSION="${PORTVERSION}" \
		CIDFONTDIR="${CIDFONTDIR:S,^${PREFIX}/,,}"
SUB_FILES=	pkg-message
SUB_LIST=	DATADIR=${DATADIR} PORTVERSION=${PORTVERSION}
PKGMESSAGE=	${WRKDIR}/pkg-message
DATADIR=	${PREFIX}/share/${PORTNAME:S,8$,,}

OPTIONS=	A4SIZE	"Set A4 (not Letter) as a default paper size"	off \
		FONTCONFIG	"fontconfig support"	on \
		FT_BRIDGE	"FreeType bridge"	off \
		X11	"X11 support"	on

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

.include "Makefile.drivers"
.include <bsd.port.pre.mk>

.for D in ${OPTIONS:MGS_*:S/^GS_//}
.if !defined(WITHOUT_GS_${D})
PLIST_SUB+=	GS_${D}=""
.else
PLIST_SUB+=	GS_${D}="@comment "
.endif
.endfor

.if !defined(WITHOUT_GS_dmprt)
.include "${FILESDIR}/Makefile.dmprt"
.endif

.if !defined(WITHOUT_GS_epag)
.include "${FILESDIR}/Makefile.epag"
.endif

EPAG_BASE=	epag
EPAG_SRCS=	${EPAG_BASE}-3.09.tar.gz
EPAG_NAME=	${EPAG_SRCS:S,.tar.gz$,,}

post-extract-epag:
	${TAR} -C ${WRKSRC} -xzf ${DISTDIR}/${DIST_SUBDIR}/${EPAG_SRCS}
	${LN} -s -f ${EPAG_NAME} ${WRKSRC}/${EPAG_BASE}
	${INSTALL_DATA} ${FILESDIR}/epag.contrib.mak ${WRKSRC}/base/epag.contrib.mak

post-extract: post-extract-epag

.if !defined(WITHOUT_GS_pcl3)
.include "${FILESDIR}/Makefile.pcl3"
.endif

.if defined(WITHOUT_SVGALIB)
.undef WITH_GS_lvga256
.undef WITH_GS_vgalib
.endif

.if defined(WITH_GS_lvga256) \
	|| defined(WITH_GS_vgalib)
LIB_DEPENDS+=	vga.1:${PORTSDIR}/graphics/svgalib
.endif

.if defined(WITHOUT_X11)
. undef WITH_GS_x11
. undef WITH_GS_x11alpha
. undef WITH_GS_x11cmyk
. undef WITH_GS_x11cmyk2
. undef WITH_GS_x11cmyk4
. undef WITH_GS_x11cmyk8
. undef WITH_GS_x11gray2
. undef WITH_GS_x11gray4
. undef WITH_GS_x11mono
. undef WITH_GS_x11rg16x
. undef WITH_GS_x11rg32x
.endif

.if defined(WITH_GS_x11) \
	|| defined(WITH_GS_x11alpha) \
	|| defined(WITH_GS_x11cmyk) \
	|| defined(WITH_GS_x11cmyk2) \
	|| defined(WITH_GS_x11cmyk4) \
	|| defined(WITH_GS_x11cmyk8) \
	|| defined(WITH_GS_x11gray2) \
	|| defined(WITH_GS_x11gray4) \
	|| defined(WITH_GS_x11mono) \
	|| defined(WITH_GS_x11rg16x) \
	|| defined(WITH_GS_x11rg32x)
USE_XORG=	xt xext
CONFIGURE_ARGS+=--with-x \
		--x-includes=${X11BASE}/include \
		--x-libraries=${X11BASE}/lib
CONFLICTS+=	ghostscript8-nox11-[0-9]*
.else
PKGNAMESUFFIX:=	${PKGNAMESUFFIX}-nox11
CONFIGURE_ARGS+=--without-x
CONFLICTS+=	ghostscript8-[0-9]*
.endif

.if defined(WITHOUT_ICONV)
. undef WITH_GS_oprp
. undef WITH_GS_opvp
.endif

_ICONV_ARG=	no
.if defined(WITH_GS_oprp) \
	|| defined(WITH_GS_opvp)
USE_ICONV=	yes
_ICONV_ARG=	gnu
EXTRALIBS+=	-liconv
.endif
CONFIGURE_ARGS+=--with-libiconv=${_ICONV_ARG}

.if !defined(WITH_LETTERSIZE)
.if defined(A4) || defined(WITH_A4SIZE)
XCFLAGS+=	-DA4
MSG_PAPERSIZE=	"NOTE: Default paper size will be A4."
.endif
.endif

.if !defined(WITHOUT_FONTCONFIG)
LIB_DEPENDS+=	fontconfig.1:${PORTSDIR}/x11-fonts/fontconfig
CONFIGURE_ARGS+=	--enable-fontconfig
.else
CONFIGURE_ARGS+=	--disable-fontconfig
.endif

.if !defined(WITHOUT_FT_BRIDGE)
LIB_DEPENDS+=	freetype.9:${PORTSDIR}/print/freetype2
MAKE_ENV+=	FT_BRIDGE=1 FT_ROOT="${WRKSRC}/freetype" FT_LIB_EXT=".so"
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

pre-everything::
	@${ECHO_MSG} ${MSG_PAPERSIZE}

post-patch:
	${REINPLACE_CMD} -e 's|%%DATADIR%%|${DATADIR}|g ; \
		 s|%%GS_VERSION%%|${PORTVERSION}|g' \
			${WRKSRC}/contrib/japanese/dmp_site.ps

pre-build-drivers.mak:
	@${ECHO_CMD} 'DEVICE_DEVS= \' > ${WRKSRC}/base/drivers.mak
.for D in ${OPTIONS:MGS_*:S/^GS_//}
.if defined(WITH_GS_${D})
	@${ECHO_CMD} '$$(DD)${D}.dev \' >> ${WRKSRC}/base/drivers.mak
.endif
.endfor

pre-build: pre-build-drivers.mak
	${MKDIR} ${WRKSRC}/obj
	${MKDIR} ${WRKSRC}/bin
.if defined(WITH_FT_BRIDGE)
	${MKDIR} ${WRKSRC}/freetype/include
	${LN} -s -f ${LOCALBASE}/include/ft2build.h \
		${WRKSRC}/freetype/include/ft2build.h
	${LN} -s -f ${LOCALBASE}/include/freetype2/freetype \
		${WRKSRC}/freetype/include/freetype
	${MKDIR} ${WRKSRC}/freetype/objs
	${LN} -s -f ${LOCALBASE}/lib/libfreetype.so \
		${WRKSRC}/freetype/objs/freetype214MT_D.so
# bug in 8.64.  Fixed in r9467.
	${MV} ${WRKSRC}/base/write_t[12].[ch] \
		${WRKSRC}/base/wrfont.[ch] \
		${WRKSRC}/psi
.endif

pre-su-install:
	${MKDIR} ${DATADIR}
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${DATADIR}

post-install-docs:
	${MKDIR} ${WRKSRC}/contrib/japanese
	${INSTALL_DATA} ${WRKSRC}/contrib/japanese/doc/* ${WRKSRC}/contrib/japanese
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC}/contrib && \
		${TAR} -cf - ${PORTDOC_FILES} | \
		( cd ${DOCSDIR} && ${TAR} -xof - )

.if defined(WITH_FT_BRIDGE)
post-install-fapi:
	${INSTALL_DATA} ${WRKSRC}/lib/FAPIcidfmap			\
		${WRKSRC}/lib/FAPIconfig ${WRKSRC}/lib/FAPIfontmap	\
		${DATADIR}/${PORTVERSION}/Resource/Init

post-install: post-install-fapi
.endif

post-install:
	${STRIP_CMD} ${PREFIX}/bin/gsc ${PREFIX}/bin/gsx
	${LN} -sf gsc ${PREFIX}/bin/gs
	${LN} -s -f ${LOCALBASE}/share/fonts/CIDFont ${CIDFONTDIR}/CIDFont
	@${ECHO_MSG}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG}

.if !defined(NOPORTDOCS)
post-install: post-install-docs
.endif

.include <bsd.port.post.mk>
