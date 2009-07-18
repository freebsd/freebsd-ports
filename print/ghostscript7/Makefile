# New ports collection makefile for:	ghostscript
# Date created:		Tue Jun 10 21:58:54 CEST 1997
# Whom:			Andreas Klemm <andreas@klemm.gtn.com>
#
# $FreeBSD$
#

PORTNAME=	ghostscript7
PORTVERSION=	7.07
PORTREVISION=	21
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:S/$/:gs_srcs/} \
		${MASTER_SITE_PORTS_JP:S/$/:ports_jp,ports_jp_gs/} \
		ftp://mirror.cs.wisc.edu/pub/mirrors/ghost/gnu/gs${PORTVERSION:S/.//}/:gs_srcs
MASTER_SITE_SUBDIR=	ghostscript/:gs_srcs,ports_jp_gs \
			./:ports_jp
DISTNAME=	${PORTNAME:S,7$,,}-${PORTVERSION}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:gs_srcs
DIST_SUBDIR=	${PORTNAME:S,7$,,}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	doceng@FreeBSD.org
COMMENT=	Ghostscript 7.x PostScript interpreter

LIB_DEPENDS=	jpeg.10:${PORTSDIR}/graphics/jpeg \
		png.5:${PORTSDIR}/graphics/png
RUN_DEPENDS=	${LOCALBASE}/share/ghostscript/fonts/a010013l.pfb:${PORTSDIR}/print/gsfonts

# normazile WRKSRC so things like cups-pstoraster may work
WRKSRC=		${WRKDIR}/${PORTNAME:S,7$,,}
DATADIR=	${PREFIX}/share/${PORTNAME:S,7$,,}

CONFLICTS=	gambc-* ghostscript8-*

USE_BZIP2=	yes
USE_GMAKE=	yes
WANT_GNOME=	yes
GNU_CONFIGURE=	yes
MAKE_ENV=	CFLAGS_STANDARD="${CFLAGS}" \
		XCFLAGS="${XCFLAGS}" XLDFLAGS="${XLDFLAGS}" \
		EXTRALIBS="${EXTRALIBS}"
CONFIGURE_ENV=	${MAKE_ENV} \
		CPPFLAGS="-DUPD_SIGNAL=0 -I. -I${WRKSRC}/gimp-print -I${LOCALBASE}/include/libpng -I${LOCALBASE}/include" \
		LDFLAGS="${XLDFLAGS}"
CONFIGURE_ARGS=	--disable-compile-inits \
		--with-ijs
PLIST_SUB=	GS_VERSION="${PORTVERSION}"

OPTIONS=	A4SIZE	"Set A4 (not Letter) as a default paper size"	off \
		X11	"X11 support"	on

MAN1=		ansi2knr.1 dvipdf.1 font2c.1 gs.1 gslp.1 gsnd.1 pdf2dsc.1 \
		pdf2ps.1 pdfopt.1 pf2afm.1 pfbtopfa.1 printafm.1 ps2ascii.1 \
		ps2epsi.1 ps2pdf.1 ps2pdfwr.1 ps2ps.1 wftopfa.1
MLINKS=		gslp.1 gsbj.1 \
		gslp.1 gsdj.1 \
		gslp.1 gsdj500.1 \
		gslp.1 gslj.1 \
		ps2pdf.1 ps2pdf12.1 \
		ps2pdf.1 ps2pdf13.1 \
		ps2ps.1 eps2eps.1

XCFLAGS=	${PTHREAD_CFLAGS}
XLDFLAGS=	-L${LOCALBASE}/lib -L${WRKSRC}/gimp-print ${PTHREAD_LIBS}

.include "Makefile.drivers"
.include <bsd.port.pre.mk>

post-extract-all:
	${LN} -sf ${WRKDIR}/${DISTNAME} ${WRKDIR}/${PORTNAME:S,7$,,}

post-extract: post-extract-all

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

.if defined(WITH_GS_lvga256) \
	|| defined(WITH_GS_vgalib)
. if defined(WITHOUT_SVGALIB)
. warning drivers incompatible with WITHOUT_SVGALIB will be removed automatically
. undef WITH_GS_lvga256
. undef WITH_GS_vgalib
. else
LIB_DEPENDS+=	vga.1:${PORTSDIR}/graphics/svgalib
. endif
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
. if defined(WITHOUT_X11)
. warning drivers incompatible with WITHOUT_X11 will be removed automatically
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
. endif
USE_XORG=	xt xext
CONFIGURE_ARGS+=--with-x \
		--x-includes=${X11BASE}/include \
		--x-libraries=${X11BASE}/lib
CONFLICTS+=	ghostscript7-nox11-[0-9]*
.else
PKGNAMESUFFIX:=	${PKGNAMESUFFIX}-nox11
CONFIGURE_ARGS+=--without-x
CONFLICTS+=	ghostscript7-[0-9]*
.endif

.if defined(WITH_SHLIB)
.undef WITHOUT_X11
USE_GNOME=	gtk12
MAKE_ENV+=	GS_SHLIB_VER="${SHLIB_VER}"
ALL_TARGET=	so pcl3opts
INSTALL_TARGET=	soinstall
USE_LDCONFIG=	yes
SHLIB_VER=	1
PLIST_SUB+=	SHLIB="" SHLIB_VER="${SHLIB_VER}"
.else
ALL_TARGET=	all pcl3opts
PLIST_SUB+=	SHLIB="@comment "
.endif

.if !defined(WITHOUT_GS_cdj670) \
	&& !defined(WITHOUT_GS_cdj850) \
	&& !defined(WITHOUT_GS_cdj880) \
	&& !defined(WITHOUT_GS_cdj890) \
	&& !defined(WITHOUT_GS_cdj1600)
.include "${FILESDIR}/Makefile.cdj880"
.endif
.if !defined(WITHOUT_GS_pcl3)
.include "${FILESDIR}/Makefile.pcl3"
.endif
.if !defined(WITHOUT_GS_cdj970)
.include "${FILESDIR}/Makefile.cdj970"
.endif

.include "${FILESDIR}/Makefile.gprint"

.if !defined(WITHOUT_GS_md2k) && !defined(WITHOUT_GS_md5k)
.include "${FILESDIR}/Makefile.md2k"
.endif

.if !defined(WITHOUT_GS_md50Mono) \
	&& !defined(WITHOUT_GS_md50Eco) \
	&& !defined(WITHOUT_GS_md1xMono)
.include "${FILESDIR}/Makefile.alps"
.endif

.if !defined(WITHOUT_GS_bj10v) && !defined(WITHOUT_bj10vh)
.include "${FILESDIR}/Makefile.bj10v"
.endif

.if !defined(WITHOUT_GS_bjccmyk) \
	&& !defined(WITHOUT_GS_bjccolor) \
	&& !defined(WITHOUT_GS_bjcgray) \
	&& !defined(WITHOUT_GS_bjcmono)
.include "${FILESDIR}/Makefile.bjc250"
.endif

.if !defined(WITHOUT_GS_lbp1310) \
	&& !defined(WITHOUT_GS_lbp1510) \
	&& !defined(WITHOUT_GS_lbp1610) \
	&& !defined(WITHOUT_GS_lbp1710) \
	&& !defined(WITHOUT_GS_lbp1810) \
	&& !defined(WITHOUT_GS_lbp1910)
.include "${FILESDIR}/Makefile.cpca"
.endif

.if !defined(WITHOUT_GS_lips2p) \
	&& !defined(WITHOUT_GS_lips3) \
	&& !defined(WITHOUT_GS_lips4) \
	&& !defined(WITHOUT_GS_bjc880j) \
	&& !defined(WITHOUT_GS_lips4v) \
	&& !defined(WITHOUT_GS_escpage) \
	&& !defined(WITHOUT_GS_lp2000) \
	&& !defined(WITHOUT_GS_npdl) \
	&& !defined(WITHOUT_GS_rpdl)
.include "${FILESDIR}/Makefile.lips"
.endif

.if !defined(WITHOUT_GS_dmprt)
.include "${FILESDIR}/Makefile.dmprt"
.endif

.if !defined(WITHOUT_GS_epag)
.include "${FILESDIR}/Makefile.epag"
.endif

.if !defined(WITHOUT_GS_alc8600) \
	&& !defined(WITHOUT_GS_alc8500) \
	&& !defined(WITHOUT_GS_alc2000) \
	&& !defined(WITHOUT_GS_alc4000) \
	&& !defined(WITHOUT_GS_alc1900) \
	&& !defined(WITHOUT_GS_alc4100) \
	&& !defined(WITHOUT_GS_lp9800c) \
	&& !defined(WITHOUT_GS_lp9000c) \
	&& !defined(WITHOUT_GS_lp9500c) \
	&& !defined(WITHOUT_GS_lp8800c) \
	&& !defined(WITHOUT_GS_lp8300c) \
	&& !defined(WITHOUT_GS_lp8500c) \
	&& !defined(WITHOUT_GS_lp3000c) \
	&& !defined(WITHOUT_GS_lp8200c) \
	&& !defined(WITHOUT_GS_lp8000c) \
	&& !defined(WITHOUT_GS_epl6100) \
	&& !defined(WITHOUT_GS_epl5900) \
	&& !defined(WITHOUT_GS_epl5800) \
	&& !defined(WITHOUT_GS_epl2050) \
	&& !defined(WITHOUT_GS_epl2050p) \
	&& !defined(WITHOUT_GS_epl2120) \
	&& !defined(WITHOUT_GS_epl2500) \
	&& !defined(WITHOUT_GS_epl2750) \
	&& !defined(WITHOUT_GS_lp9000b) \
	&& !defined(WITHOUT_GS_lp2500) \
	&& !defined(WITHOUT_GS_lp9100) \
	&& !defined(WITHOUT_GS_lp7900) \
	&& !defined(WITHOUT_GS_lp7500) \
	&& !defined(WITHOUT_GS_lp2400) \
	&& !defined(WITHOUT_GS_lp2200) \
	&& !defined(WITHOUT_GS_lp9400) \
	&& !defined(WITHOUT_GS_lp8900) \
	&& !defined(WITHOUT_GS_lp8700) \
	&& !defined(WITHOUT_GS_lp8100) \
	&& !defined(WITHOUT_GS_lp7700) \
	&& !defined(WITHOUT_GS_lp8600f) \
	&& !defined(WITHOUT_GS_lp8400f) \
	&& !defined(WITHOUT_GS_lp8300f) \
	&& !defined(WITHOUT_GS_lp1900) \
	&& !defined(WITHOUT_GS_lp9600s) \
	&& !defined(WITHOUT_GS_lp9300) \
	&& !defined(WITHOUT_GS_lp9600) \
	&& !defined(WITHOUT_GS_lp8600) \
	&& !defined(WITHOUT_GS_lp1800)
.include "${FILESDIR}/Makefile.eplaser"
.endif

.if !defined(WITHOUT_GS_mjc180) \
	&& !defined(WITHOUT_GS_mjc360) \
	&& !defined(WITHOUT_GS_mjc720) \
	&& !defined(WITHOUT_GS_mj500c)
.include "${FILESDIR}/Makefile.mjc"
.endif

.if !defined(WITHOUT_GS_gdi)
.include "${FILESDIR}/Makefile.gdi"
.endif

.if !defined(WITHOUT_GS_lxm3200)
.include "${FILESDIR}/Makefile.lxm3200"
.endif

.if !defined(WITHOUT_GS_lx5000)
.include "${FILESDIR}/Makefile.lx5000"
.endif

.if !defined(WITHOUT_GS_lex2050) \
	&& !defined(WITHOUT_GS_lex3200) \
	&& !defined(WITHOUT_GS_lex5700) \
	&& !defined(WITHOUT_GS_lex7000)
.include "${FILESDIR}/Makefile.lex7000"
.endif

# contributed uniprint profiles
CONTRIB_UPP=	lqx70ch.upp lqx70cl.upp lqx70cm.upp \
		stc740ih.upp stc740p.upp stc740pl.upp

pre-everything::
	@${ECHO_MSG} ${MSG_PAPERSIZE}

post-patch:
	${REINPLACE_CMD} -e 's|^DEVICE_DEVS|#DEVICE_DEVS|g' \
		${WRKSRC}/src/unix-gcc.mak
	${REINPLACE_CMD} -e 's|\. de|\.|g' \
		${WRKSRC}/src/unixinst.mak
	${REINPLACE_CMD} -e 's|%%DATADIR%%|${DATADIR}|g' \
		${WRKSRC}/lib/gs_res.ps

pre-build-drivers.mak:
	@${ECHO_CMD} 'DEVICE_DEVS= \' > ${WRKSRC}/src/drivers.mak
.for D in ${OPTIONS:MGS_*:S/^GS_//}
.if defined(WITH_GS_${D})
	@${ECHO_CMD} '$$(DD)${D}.dev \' >> ${WRKSRC}/src/drivers.mak
.endif
.endfor

pre-build-contrib_extra.mak:
	${CAT} /dev/null ${EXTRADEVMKFILE} > ${WRKSRC}/src/contrib_extra.mak

pre-build-all:
	${MKDIR} ${WRKSRC}/obj ${WRKSRC}/bin

pre-build: pre-build-all pre-build-drivers.mak pre-build-contrib_extra.mak

pre-su-install:
	${MKDIR} ${DATADIR}
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${DATADIR}

post-install:
.if defined(WITH_SHLIB)
	${STRIP_CMD} ${PREFIX}/bin/gsc ${PREFIX}/bin/gsx
	${LN} -s -f gsc ${PREFIX}/bin/gs
.else
	${STRIP_CMD} ${PREFIX}/bin/gs
.endif
	cd ${FILESDIR} \
		&& ${INSTALL_DATA} ${CONTRIB_UPP} ${DATADIR}/${PORTVERSION}/lib
	@${ECHO_MSG}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG}

post-install-docs:
	${MKDIR} ${DOCSDIR}

.if !defined(NOPORTDOCS)
post-install: post-install-docs
.endif

.include <bsd.port.post.mk>
