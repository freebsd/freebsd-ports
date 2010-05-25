# New ports collection makefile for:	ghostscript
# Date created:		Tue Jun 10 21:58:54 CEST 1997
# Whom:			Andreas Klemm <andreas@klemm.gtn.com>
#
# $FreeBSD$
#

PORTNAME=	ghostscript8
PORTVERSION=	8.71
PORTREVISION=	2
CATEGORIES=	print
MASTER_SITES=	http://ghostscript.com/releases/:gs_srcs \
		SF/ghostscript/files/GPL%20Ghostscript/${PORTVERSION}:gs_srcs \
		ftp://mirror.cs.wisc.edu/pub/mirrors/ghost/GPL/gs${PORTVERSION:S/.//}/:gs_srcs \
		http://www.humblesoft.com/pub/:epag
MASTER_SITE_SUBDIR=	ghostscript/:gs_srcs
DISTNAME=	${PORTNAME:S,8$,,}-${PORTVERSION}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:gs_srcs ${EPAG_SRCS}:epag
DIST_SUBDIR=	${PORTNAME:S,8$,,}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	doceng@FreeBSD.org
COMMENT=	Ghostscript 8.x PostScript interpreter

LIB_DEPENDS=	jpeg.11:${PORTSDIR}/graphics/jpeg \
		png.6:${PORTSDIR}/graphics/png \
		tiff.4:${PORTSDIR}/graphics/tiff
RUN_DEPENDS=	${LOCALBASE}/share/${PORTNAME:S,8,,}/fonts/a010013l.pfb:${PORTSDIR}/print/gsfonts

CONFLICTS=	gambc-[0-9]* ghostscript7-[0-9]* ghostscript7-*-[0-9]*

USE_GMAKE=	yes
WANT_GNOME=	yes
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
MAKE_JOBS_UNSAFE=	yes

MAKE_ENV=	CFLAGS_STANDARD="${CFLAGS}" \
		XCFLAGS="${XCFLAGS}" XLDFLAGS="${XLDFLAGS}" \
		EXTRALIBS="${EXTRALIBS}" \
		SOC_LOADER="dxmainc.c"
CONFIGURE_ENV=	${MAKE_ENV} CPPFLAGS="${CPPFLAGS}" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--disable-compile-inits \
		--enable-contrib \
		--enable-dynamic \
		--with-ijs \
		--with-jasper \
		--with-drivers=""
CPPFLAGS=	-DUPD_SIGNAL=0 -I. \
		-I${WRKSRC}/jasper/src/libjasper/include \
		-I${LOCALBASE}/include/libpng \
		-I${LOCALBASE}/include
XCFLAGS=	${PTHREAD_CFLAGS}
XLDFLAGS=	${PTHREAD_LIBS}

PLIST_SUB=	GS_VERSION="${PORTVERSION}" \
		CIDFONTDIR="${CIDFONTDIR:S,^${PREFIX}/,,}"
SUB_FILES=	pkg-message
SUB_LIST=	DATADIR=${DATADIR} PORTVERSION=${PORTVERSION}
PKGMESSAGE=	${WRKDIR}/pkg-message
DATADIR=	${PREFIX}/share/${PORTNAME:S,8$,,}

OPTIONS=	A4SIZE	"Set A4 (not Letter) as a default paper size"	off \
		CUPS	"Enable CUPS support"	on \
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
.include "${FILESDIR}/Makefile.drivers_post"

.for D in ${OPTIONS:MGS_*:S/^GS_//}
.if !defined(WITHOUT_GS_${D})
PLIST_SUB+=	GS_${D}=""
.else
PLIST_SUB+=	GS_${D}="@comment "
.endif
.endfor

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

pre-everything::
	@${ECHO_MSG} ${MSG_PAPERSIZE}

post-patch:
	${REINPLACE_CMD} -e 's|%%DATADIR%%|${DATADIR}|g ; \
		 s|%%GS_VERSION%%|${PORTVERSION}|g' \
			${WRKSRC}/contrib/japanese/dmp_site.ps

pre-build-drivers.mak:
	@${ECHO_CMD} '# automatically generated' > ${WRKSRC}/base/drivers.mak
.for N in ${DEVS_LIST}
	@${ECHO_CMD} 'DEVICE_${N}=' >> ${WRKSRC}/base/drivers.mak
.endfor
.for D in ${OPTIONS:MGS_*:S/^GS_//}
.for N in ${DEVS_LIST}
.if defined(WITH_GS_${D})
.for X in ${DEVICE_${N}:M${D}.dev}
	@${ECHO_CMD} 'DEVICE_${N}+= $$(DD)${D}.dev'  >> ${WRKSRC}/base/drivers.mak
.endfor
.endif
.endfor
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
