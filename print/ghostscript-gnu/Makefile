# New ports collection makefile for:	ghostscript
# Date created:		Tue Jun 10 21:58:54 CEST 1997
# Whom:			Andreas Klemm <andreas@klemm.gtn.com>
#
# $FreeBSD$
#

PORTNAME=	ghostscript
PORTVERSION=	${GS_VERSION}
PORTREVISION=	6
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:S/$/:gs_srcs,gprint,bjc250/} \
		http://www.gelhaus.net/hp880c/1.4beta/:hp8xx \
		http://home.t-online.de/home/Martin.Lottermoser/pcl3dist/:hpdj_pcl3 \
		http://www.harsch.net/Download/:dj970 \
		http://plaza26.mbn.or.jp/~higamasa/gdevmd2k/:md2k \
		${MASTER_SITE_PORTS_JP:S/$/:ports_jp,ports_jp_gs/} \
		ftp://download.canon-sales.co.jp/pub/driver/lasershot/linux/:cpca \
		http://www.ucatv.ne.jp/~taeko/software/gs/:lips \
		http://www.humblesoft.com/pub/:epag \
		http://www.epkowa2.on.arena.ne.jp/gslpd/data/V${EPLASER_VERS:S/.//g}/:eplaser \
		http://www.linuxprinting.org/download/printing/samsung-gdi/:gdi \
		http://www.linuxprinting.org/download/printing/:lxm3200 \
		http://homepage.powerup.com.au/~pbwest/lexmark/:lx5000 \
		ftp://mirror.cs.wisc.edu/pub/mirrors/ghost/fonts/:gs_fonts \
		ftp://mirror.cs.wisc.edu/pub/mirrors/ghost/gnu/gs${GS_VERSION:S/.//}/:gs_srcs
MASTER_SITE_SUBDIR=	ghostscript/:gs_srcs,ports_jp_gs \
			gimp-print/:gprint \
			bjc250gs/:bjc250 \
			./:ports_jp
PKGNAMESUFFIX=	-gnu
DISTFILES=	${GS_SRCS}:gs_srcs \
		${GS_FONTS_STD}:gs_fonts \
		${GS_FONTS_OTHER}:gs_fonts \
		${HP8XX_SRCS}:hp8xx \
		${HPDJ_SRCS}:hpdj_pcl3 \
		${PCL3_SRCS}:hpdj_pcl3 \
		${DJ970_SRCS}:dj970 \
		${GPRINT_SRCS}:gprint \
		${MD2K_SRCS}:md2k \
		${ALPS_SRCS}:ports_jp_gs \
		${BJ10V_SRCS}:ports_jp_gs \
		${BJC250_SRCS}:bjc250 \
		${CPCA_SRCS}:cpca \
		${LIPS_SRCS}:lips \
		${DMPRT_SRCS}:ports_jp_gs \
		${EPAG_SRCS}:epag \
		${EPLASER_SRCS}:eplaser \
		${MJC_SRCS}:ports_jp \
		${GDI_SRCS}:gdi \
		${LXM3200_SRCS}:lxm3200 \
		${LX5000_SRCS}:lx5000 \
		${LEX7000_SRCS}:lx5000
DIST_SUBDIR=	ghostscript
EXTRACT_ONLY=	${GS_SRCS}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GNU Postscript interpreter

LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg \
		png.5:${PORTSDIR}/graphics/png

CONFLICTS=	ghostscript-afpl*
USE_BZIP2=	yes
USE_REINPLACE=	yes
USE_GMAKE=	yes
MAKE_ENV=	CC="${CC}" CXX="${CXX}" CFLAGS_STANDARD="${CFLAGS}" \
		XCFLAGS="${XCFLAGS}"
PLIST_SUB=	GS_VERSION="${GS_VERSION}"

SCRIPTS_ENV=	GS_DRIVERS_LIST="${GS_DRIVERS_LIST}" \
		WITHOUT_X11="${WITHOUT_X11}" \
		WITH_SVGALIB="${WITH_SVGALIB}"

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

XCFLAGS=	-DUPD_SIGNAL=0

.if defined(A4)
XCFLAGS+=	-DA4
.endif

.if defined(WITHOUT_X11)
PKGNAMESUFFIX:=	${PKGNAMESUFFIX}-nox11
.else
USE_XLIB=	yes
.endif

.if defined(WITH_SVGALIB)
LIB_DEPENDS+=	vga.1:${PORTSDIR}/graphics/svgalib
.endif

.if defined(WITH_SHLIB)
.undef WITHOUT_X11
USE_GNOME=	gtk12
MAKE_ENV+=	GS_SHLIB_VER="${SHLIB_VER}"
ALL_TARGET=	so pcl3opts
INSTALL_TARGET=	soinstall
INSTALLS_SHLIB=	yes
SHLIB_VER=	1
PLIST_SUB+=	SHLIB="" SHLIB_VER="${SHLIB_VER}"
.else
ALL_TARGET=	all pcl3opts
PLIST_SUB+=	SHLIB="@comment "
.endif

GS_SRCS=	${DISTNAME}${EXTRACT_SUFX}
GS_FONTS_STD=	ghostscript-fonts-std-8.11.tar.gz
GS_FONTS_OTHER=	ghostscript-fonts-other-6.0.tar.gz

# Additional Drivers:

# HP8XX - additional driver for HP DeskJet 812C/815C/832C/880C/882C/895C
# http://www.gelhaus.net/hp880c/
HP8XX=		cdj880
HP8XX_SRCS=	gdevcd8.tar.gz

# HPDJ - additional driver for HP PCL3 printers, by Martin Lottermoser
# still present, just for the case pcl3 is missing some hpdj feature
# http://home.t-online.de/home/Martin.Lottermoser/pcl3.html
HPDJ=		hpdj
HPDJ_VERS=	2.6
HPDJ_NAME=	${HPDJ}-${HPDJ_VERS}
HPDJ_SRCS=	${HPDJ_NAME}.tar.gz
HPDJ_MAN1=	gs-hpdj.1
MAN1+=		${HPDJ_MAN1}

# PCL3 (hpdj successor now in RELEASE quality)
# additional driver for HP PCL3 printers, by Martin Lottermoser
# http://home.t-online.de/home/Martin.Lottermoser/pcl3.html
PCL3=		pcl3
PCL3_VERS=	3.3
PCL3_NAME=	${PCL3}-${PCL3_VERS}
PCL3_SRCS=	${PCL3_NAME}.tar.gz
PCL3_MAN1=	gs-pcl3.1 pcl3opts.1
MAN1+=		${PCL3_MAN1}

# DJ970 - additional driver for HP DeskJet 970, supports duplex printing
# http://www.harsch.net/Ghostscript/ghostscript.html
DJ970=		gdevdj9
DJ970_SRCS=	${DJ970}.c.gz

# Gimp-Print - very high quality driver for Epson, HPs,...
# http://gimp-print.sourceforge.net/
#
# NOTE:
# Support of stp driver interface has already been discontinued, and using
# ijs driver with ijsgimpprint (part of print/gimp-print port) is highly
# recommended.
#
# For that reason, integlation of stp driver is disabled by default.
GPRINT=		gimp-print
GPRINT_VERS=	4.2.1
GPRINT_NAME=	${GPRINT}-${GPRINT_VERS}
GPRINT_SRCS=	${GPRINT_NAME}.tar.gz

# MD2K - additional driver for Alps MD-2000/2010/4000/1300/1500/5000
# http://plaza26.mbn.or.jp/~higamasa/gdevmd2k/
MD2K=		md2k
MD2K_VERS=	0.2a
MD2K_NAME=	gdevmd2k-${MD2K_VERS}
MD2K_SRCS=	${MD2K_NAME}.tar.gz

# ALPS - additional driver for Alps MD-5000
ALPS=		alps
ALPS_VERS=	0.2
ALPS_NAME=	gdevalps-${ALPS_VERS}
ALPS_SRCS=	gdevalps-0.21.tar.gz

# BJ10V - additional driver for Canon BJ-10V
BJ10V=		bj10v
BJ10V_NAME=	gdev10v
BJ10V_SRCS=	${BJ10V_NAME}.tar.gz

# BJC250 - additional driver for Canon BJC-210/240/250/265/1000
# http://bjc250gs.sourceforge.net/
BJC250=		bjc250
BJC250_VERS=	0.756
BJC250_NAME=	${BJC250}-v${BJC250_VERS}
BJC250_SRCS=	gs7.05-${BJC250_NAME}.diff.gz

# CPCA - additional driver for Canon CPCA printers
# http://cweb.canon.jp/open-mie/technical/index-j.html
CPCA=		cpca
CPCA_VERS=	1.0.0
CPCA_NAME=	canon-lips4-${CPCA_VERS}
CPCA_SRCS=	${CPCA_NAME}-651.tgz

# LIPS - additional driver for Canon LIPS II+/III/IVc/IV printers
# http://www.ucatv.ne.jp/~taeko/software/gs/
LIPS=		lips
LIPS_VERS=	2.4.0
LIPS_NAME=	gdevlips-${LIPS_VERS}
LIPS_SRCS=	${LIPS_NAME}.tar.gz

# DMPRT - additional driver for generic dot matrix printers
DMPRT=		dmprt
DMPRT_VERS=	2.01
DMPRT_NAME=	${DMPRT}-${DMPRT_VERS}
DMPRT_SRCS=	${DMPRT_NAME}.tar.gz

# EPAG - additional driver for Epson ESC/Page printers
# http://www.humblesoft.com/gdevepag.html
EPAG=		epag
EPAG_VERS=	3.09
EPAG_NAME=	${EPAG}-${EPAG_VERS}
EPAG_SRCS=	${EPAG_NAME}.tar.gz

# EPLASER - additional driver for ESC/Page printers (Epson Kowa developed)
# http://www.epkowa.co.jp/english/linux_e/index.html
EPLASER=	eplaser
EPLASER_VERS=	3.1.3
EPLASER_NAME=	${EPLASER}-${EPLASER_VERS}
EPLASER_SRCS=	${EPLASER_NAME}-705.tgz

# MJC - additional driver for Epson MachJet series
MJC=		mjc
MJC_VERS=	0.8
MJC_NAME=	gdevmjc-${MJC_VERS}
MJC_SRCS=	${MJC_NAME}.tar.gz

# GDI - additional driver for Samsung SmartGDI laser printers
GDI=		gdi
GDI_NAME=	Samsung-SmartGDI-all-GS
GDI_SRCS=	${GDI_NAME}.orig.tar.gz

# LXM3200 - additional driver for Lexmark 3200/Z12/Z22/Z31/Z32
LXM3200=	lxm3200
LXM3200_VERS=	20030501
LXM3200_NAME=	${LXM3200}-tweaked-${LXM3200_VERS}
LXM3200_SRCS=	${LXM3200_NAME}.tar.gz

# LX5000 - additional driver for Lexmark 5000/Z51/Z82
# http://homepage.powerup.com.au/~pbwest/lexmark/lexmark.html
LX5000=		lx5000
LX5000_SRCS=	gdevlx50.c

# LEX7000 - additional driver for Lexmark 2050/3200/5700/7000
# http://bimbo.fjfi.cvut.cz/~paluch/l7kdriver/
LEX7000=	lex7000
LEX7000_SRCS=	gs6.0.lexmark7000.patch

# contributed uniprint profiles
CONTRIB_UPP=	lqx70ch.upp lqx70cl.upp lqx70cm.upp \
		stc740ih.upp stc740p.upp stc740pl.upp

.include <bsd.port.pre.mk>
.SILENT:

pre-everything::
.if !defined(A4)
	${ECHO_MSG} "Type \"make A4=yes\" if you want -DA4 for compilation."
.else
	${ECHO_MSG} "Using -DA4 for compilation."
.endif

post-extract:
	${ECHO_MSG} ">>> in post-extract ..."
# ** 3rd party driver **
# Note: don't forget to add those devices in scripts/configure,
# which update unix-gcc.mak to build gs with these new devices!
#
# for HP8XX driver
	${ECHO_MSG} ">>>   extracting ${HP8XX_SRCS} ..."
	${TAR} -C ${WRKSRC}/src -xzf ${DISTDIR}/${DIST_SUBDIR}/${HP8XX_SRCS}
# for HPDJ driver
	${ECHO_MSG} ">>>   extracting ${HPDJ_SRCS} ..."
	${TAR} -C ${WRKSRC} -xzf ${DISTDIR}/${DIST_SUBDIR}/${HPDJ_SRCS}
	${TAR} -C ${WRKSRC}/src -xf ${WRKSRC}/${HPDJ_NAME}/${HPDJ}.tar
# for PCL3 driver
	${ECHO_MSG} ">>>   extracting ${PCL3_SRCS} ..."
	${TAR} -C ${WRKSRC} -xzf ${DISTDIR}/${DIST_SUBDIR}/${PCL3_SRCS}
	${LN} -sf ${PCL3_NAME} ${WRKSRC}/${PCL3}
	${TAR} -C ${WRKSRC}/${PCL3_NAME} -xf \
		${WRKSRC}/${PCL3_NAME}/${PCL3}.tar
# for DJ970 driver
	${ECHO_MSG} ">>>   extracting ${DJ970_SRCS} ..."
	${CP} ${DISTDIR}/${DIST_SUBDIR}/${DJ970_SRCS} ${WRKSRC}/src
	${GUNZIP_CMD} ${WRKSRC}/src/${DJ970_SRCS}
# for Gimp-Print driver
	${ECHO_MSG} ">>>   extracting ${GPRINT_SRCS} ..."
	${TAR} -C ${WRKSRC} -xzf ${DISTDIR}/${DIST_SUBDIR}/${GPRINT_SRCS}
# for MD2K driver
	${ECHO_MSG} ">>>   extracting ${MD2K_SRCS} ..."
	${TAR} -C ${WRKSRC} -xzf ${DISTDIR}/${DIST_SUBDIR}/${MD2K_SRCS}
	${LN} -sf ${MD2K_NAME} ${WRKSRC}/${MD2K}
# for ALPS driver
	${ECHO_MSG} ">>>   extracting ${ALPS_SRCS} ..."
	${TAR} -C ${WRKSRC} -xzf ${DISTDIR}/${DIST_SUBDIR}/${ALPS_SRCS}
	${LN} -sf ${ALPS_NAME} ${WRKSRC}/${ALPS}
# for BJ10V driver
	${ECHO_MSG} ">>>   extracting ${BJ10V_SRCS} ..."
	${TAR} -C ${WRKSRC} -xzf ${DISTDIR}/${DIST_SUBDIR}/${BJ10V_SRCS}
# for BJC250 driver
	${ECHO_MSG} ">>>   extracting ${BJC250_SRCS} ..."
	${MKDIR} ${WRKSRC}/${BJC250_NAME}/src
	${GZCAT} ${DISTDIR}/${DIST_SUBDIR}/${BJC250_SRCS} | \
		${PATCH} -d ${WRKSRC}/${BJC250_NAME} -f -s -N -E -p1 \
		2>/dev/null || ${TRUE}
	${LN} -sf ${BJC250_NAME} ${WRKSRC}/${BJC250}
# for CPCA driver
	${ECHO_MSG} ">>>   extracting ${CPCA_SRCS} ..."
	${TAR} -C ${WRKSRC}/src -xzf ${DISTDIR}/${DIST_SUBDIR}/${CPCA_SRCS}
# for LIPS driver
	${ECHO_MSG} ">>>   extracting ${LIPS_SRCS} ..."
	${TAR} -C ${WRKSRC} -xzf ${DISTDIR}/${DIST_SUBDIR}/${LIPS_SRCS}
	${LN} -sf ${LIPS_NAME} ${WRKSRC}/${LIPS}
# for DMPRT driver
	${ECHO_MSG} ">>>   extracting ${DMPRT_SRCS} ..."
	${TAR} -C ${WRKSRC}/src -xzf ${DISTDIR}/${DIST_SUBDIR}/${DMPRT_SRCS}
# for EPAG driver
	${ECHO_MSG} ">>>   extracting ${EPAG_SRCS} ..."
	${TAR} -C ${WRKSRC} -xzf ${DISTDIR}/${DIST_SUBDIR}/${EPAG_SRCS}
# for EPLASER driver
	${ECHO_MSG} ">>>   extracting ${EPLASER_SRCS} ..."
	${TAR} -C ${WRKSRC} -xzf ${DISTDIR}/${DIST_SUBDIR}/${EPLASER_SRCS}
	${LN} -sf ${EPLASER_NAME} ${WRKSRC}/${EPLASER}
# for MJC driver
	${ECHO_MSG} ">>>   extracting ${MJC_SRCS} ..."
	${TAR} -C ${WRKSRC} -xzf ${DISTDIR}/${DIST_SUBDIR}/${MJC_SRCS}
	${LN} -sf ${MJC_NAME} ${WRKSRC}/${MJC}
# for GDI driver
	${ECHO_MSG} ">>>   extracting ${GDI_SRCS} ..."
	${TAR} -C ${WRKSRC}/src -xzf ${DISTDIR}/${DIST_SUBDIR}/${GDI_SRCS}
# for LXM3200 driver
	${ECHO_MSG} ">>>   extracting ${LXM3200_SRCS} ..."
	${TAR} -C ${WRKSRC} -xzf ${DISTDIR}/${DIST_SUBDIR}/${LXM3200_SRCS}
	${LN} -sf ${LXM3200_NAME} ${WRKSRC}/${LXM3200}
# for LX5000 driver
	${ECHO_MSG} ">>>   extracting ${LX5000_SRCS} ..."
	${CP} ${DISTDIR}/${DIST_SUBDIR}/${LX5000_SRCS} ${WRKSRC}/src
# for LEX7000 driver
	${ECHO_MSG} ">>>   extracting ${LEX7000_SRCS} ..."
	${MKDIR} ${WRKSRC}/${LEX7000}
	${CAT} ${DISTDIR}/${DIST_SUBDIR}/${LEX7000_SRCS} | \
		${PATCH} -d ${WRKSRC}/${LEX7000} -f -s -N -E -p1 \
		2>/dev/null || ${TRUE}

post-patch:
	${REINPLACE_CMD} -e 's|^DEVICE_DEVS|#DEVICE_DEVS|g' \
		${WRKSRC}/src/unix-gcc.mak
	${REINPLACE_CMD} -e 's|\. de|\.|g' \
		${WRKSRC}/src/unixinst.mak
	${REINPLACE_CMD} -e 's|%%DATADIR%%|${DATADIR}|g' \
		${WRKSRC}/lib/gs_res.ps
# for DMPRT driver
	${REINPLACE_CMD} -e 's|%%DATADIR%%|${DATADIR}|g ; \
		 s|%%GS_VERSION%%|${GS_VERSION}|g' \
			${WRKSRC}/src/dmp_site.ps

# here we apply the modifications necessary to build the 3rd party drivers
# advantage: you see unmodified makefiles after a pure make extract
pre-configure:
	${ECHO_MSG} ">>> in pre-configure ..."
# for HP8XX driver
	${ECHO_MSG} ">>>   adding ${HP8XX} driver to contrib.mak ..."
	${CAT} ${FILESDIR}/cdj850.contrib.mak \
		>> ${WRKSRC}/src/contrib.mak
# for HPDJ driver
	${ECHO_MSG} ">>>   adding ${HPDJ} driver to contrib.mak ..."
	${CAT} ${WRKSRC}/src/contrib.mak-5.94.add \
		>> ${WRKSRC}/src/contrib.mak
# for PCL3 driver
	${ECHO_MSG} ">>>   adding ${PCL3} driver to contrib.mak ..."
	${CAT} ${WRKSRC}/${PCL3_NAME}/src/contrib.mak-7.00.add \
		>> ${WRKSRC}/src/contrib.mak
# for Gimp-Print driver
	${ECHO_MSG} ">>>   adding ${GPRINT} driver to contrib.mak ..."
	${CAT} ${FILESDIR}/stp.contrib.mak \
		>> ${WRKSRC}/src/contrib.mak
# for MD2K driver
	${ECHO_MSG} ">>>   adding ${MD2K} driver to contrib.mak ..."
	${CAT} ${WRKSRC}/${MD2K_NAME}/gdevmd2k.mak-5.50 \
		>> ${WRKSRC}/src/contrib.mak
# for ALPS driver
	${ECHO_MSG} ">>>   adding ${ALPS} driver to contrib.mak ..."
	${CAT} ${WRKSRC}/${ALPS_NAME}/gdevalps.mak-5.50 \
		>> ${WRKSRC}/src/contrib.mak
# for BJ10V driver
	${ECHO_MSG} ">>>   adding ${BJ10V} driver to contrib.mak ..."
	${CAT} ${WRKSRC}/${BJ10V_NAME}/gdev10v.mak \
		>> ${WRKSRC}/src/contrib.mak
# for BJC250 driver
	${ECHO_MSG} ">>>   adding ${BJC250} driver to contrib.mak ..."
	${CAT} ${FILESDIR}/bjc250.contrib.mak \
		>> ${WRKSRC}/src/contrib.mak
# for CPCA driver
	${ECHO_MSG} ">>>   adding ${CPCA} driver to contrib.mak ..."
	${CAT} ${WRKSRC}/src/cpca_gdev.mak \
		>> ${WRKSRC}/src/contrib.mak
# for LIPS driver
	${ECHO_MSG} ">>>   adding ${LIPS} driver to contrib.mak ..."
	${CAT} ${WRKSRC}/${LIPS_NAME}/gdevlips.mak \
		>> ${WRKSRC}/src/contrib.mak
# for DMPRT driver
	${ECHO_MSG} ">>>   adding ${DMPRT} driver to contrib.mak ..."
	${CAT} ${WRKSRC}/src/gdevdmpr.mak \
		>> ${WRKSRC}/src/contrib.mak
# for EPAG driver
	${ECHO_MSG} ">>>   adding ${EPAG} driver to contrib.mak ..."
	${CAT} ${FILESDIR}/epag.contrib.mak \
		>> ${WRKSRC}/src/contrib.mak
# for EPLASER driver
	${ECHO_MSG} ">>>   adding ${EPLASER} driver to contrib.mak ..."
	${CAT} ${WRKSRC}/${EPLASER_NAME}/gdevescv7.mak \
		>> ${WRKSRC}/src/contrib.mak
	${CAT} ${WRKSRC}/${EPLASER_NAME}/gdevesmv7.mak \
		>> ${WRKSRC}/src/contrib.mak
# for MJC driver
	${ECHO_MSG} ">>>   adding ${MJC} driver to contrib.mak ..."
	${CAT} ${WRKSRC}/${MJC_NAME}/gdevmjc.mak \
		>> ${WRKSRC}/src/contrib.mak
# for GDI driver
	${ECHO_MSG} ">>>   adding ${GDI} driver to contrib.mak ..."
	${CAT} ${WRKSRC}/src/smartgdi-contrib.mak \
		>> ${WRKSRC}/src/contrib.mak
# for LXM3200 driver
	${ECHO_MSG} ">>>   adding ${LXM3200} driver to contrib.mak ..."
	${CAT} ${FILESDIR}/lxm3200.contrib.mak \
		>> ${WRKSRC}/src/contrib.mak
# for LX5000 driver
	${ECHO_MSG} ">>>   adding ${LX5000} driver to contrib.mak ..."
	${CAT} ${FILESDIR}/lx5000.contrib.mak \
		>> ${WRKSRC}/src/contrib.mak
# for LEX7000 driver
	${ECHO_MSG} ">>>   adding ${LEX7000} driver to contrib.mak ..."
	${CAT} ${FILESDIR}/lex7000.contrib.mak \
		>> ${WRKSRC}/src/contrib.mak

post-configure:
	${ECHO_MSG} ">>> in post-configure ..."
# for Gimp-Print driver
	${ECHO_MSG} ">>>   running configure script for ${GPRINT} library ..."
	cd ${WRKSRC}/${GPRINT_NAME} ; \
		${SETENV} ${MAKE_ENV} ${SH} ./configure \
			--without-translated-ppds --with-ghost \
			--without-gimp --without-samples \
			--without-user-guide --disable-escputil \
			--disable-nls --disable-shared \
			--prefix=${PREFIX}

pre-build:
	${ECHO_MSG} ">>> in pre-build ..."
	${ECHO_MSG} ">>>   creating directories for compilation ..."
	${MKDIR} ${WRKSRC}/obj
	${MKDIR} ${WRKSRC}/bin
# for Gimp-Print driver
	${ECHO_MSG} ">>>   building ${GPRINT} library ..."
	cd ${WRKSRC}/${GPRINT_NAME} ; \
		${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} Makefile
	${ECHO_MSG} ">>>   creating symlinks for ${GPRINT} ..."
	${LN} -sf ${WRKSRC}/${GPRINT_NAME}/src/ghost/*.[ch] \
		${WRKSRC}/src
	${MKDIR} ${WRKSRC}/${GPRINT}
	${LN} -sf ${WRKSRC}/${GPRINT_NAME}/include/gimp-print \
		${WRKSRC}/${GPRINT}/gimp-print
	${LN} -sf ${WRKSRC}/${GPRINT_NAME}/src/main/.libs/libgimpprint.a \
		${WRKSRC}/${GPRINT}/libgimpprint.a
# for MD2K driver
	${ECHO_MSG} ">>>   creating symlinks for ${MD2K} ..."
.for i in gdevmd2k.c
	${LN} -sf ${WRKSRC}/${MD2K_NAME}/${i} ${WRKSRC}/src
.endfor
# for ALPS driver
	${ECHO_MSG} ">>>   creating symlinks for ${ALPS} ..."
.for i in gdevalps.c
	${LN} -sf ${WRKSRC}/${ALPS_NAME}/${i} ${WRKSRC}/src
.endfor
# for BJ10V driver
	${ECHO_MSG} ">>>   creating symlinks for ${BJ10V} ..."
.for i in gdev10v.c
	${LN} -sf ${WRKSRC}/${BJ10V_NAME}/${i} ${WRKSRC}/src
.endfor
# for BJC250 driver
	${ECHO_MSG} ">>>   creating symlinks for ${BJC250} ..."
.for i in gdevbjc_.[ch] gdevbjca.c
	${LN} -sf ${WRKSRC}/${BJC250_NAME}/src/${i} ${WRKSRC}/src
.endfor
# for LIPS driver
	${ECHO_MSG} ">>>   creating symlinks for ${LIPS} ..."
.for i in gdevlips.[ch] gdevlprn.[ch] gdevl4r.c gdevl4v.c gdevespg.c \
	gdevnpdl.c gdevrpdl.c
	${LN} -sf ${WRKSRC}/${LIPS_NAME}/${i} ${WRKSRC}/src
.endfor
# for EPAG driver
	${ECHO_MSG} ">>>   building ${EPAG} utility ..."
	cd ${WRKSRC}/${EPAG_NAME} ; \
		${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} Makefile
	${ECHO_MSG} ">>>   creating symlinks for ${EPAG} ..."
.for i in gdevepag.c
	${LN} -sf ${WRKSRC}/${EPAG_NAME}/${i} ${WRKSRC}/src
.endfor
# for EPLASER driver
	${ECHO_MSG} ">>>   creating symlinks for ${EPLASER} ..."
.for i in gdevescv.[ch] gdevesmv.c
	${LN} -sf ${WRKSRC}/${EPLASER_NAME}/${i} ${WRKSRC}/src
.endfor
# for MJC driver
	${ECHO_MSG} ">>>   creating symlinks for ${MJC} ..."
.for i in gdevmjc.c mjbarrie.c mjbksep.c mjespdtc.c mjespdtm.c mjespdty.c \
	mjgrnsp.c mjgrnsp2.c mjhtocmy.c mjmtx2.c mjvtbl.c
	${LN} -sf ${WRKSRC}/${MJC_NAME}/${i} ${WRKSRC}/src
.endfor
# for LXM3200 driver
	${ECHO_MSG} ">>>   creating symlinks for ${LXM3200} ..."
.for i in gdevlx32.c
	${LN} -sf ${WRKSRC}/${LXM3200_NAME}/${i} ${WRKSRC}/src
.endfor
# for LEX7000 driver
	${ECHO_MSG} ">>>   creating symlinks for ${LEX7000} ..."
.for i in gdevlx7.c
	${LN} -sf ${WRKSRC}/${LEX7000}/src/${i} ${WRKSRC}/src
.endfor

pre-su-install:
	${ECHO_MSG} ">>> in pre-install ..."
	${ECHO_MSG} ">>>   creating ghostscript destdir ..."
	${MKDIR} ${DATADIR}
	${ECHO_MSG} ">>>   extracting ghostscript fonts ..."
	${TAR} -C ${DATADIR} -xzf ${DISTDIR}/${DIST_SUBDIR}/${GS_FONTS_STD}
	${TAR} -C ${DATADIR} -xzf ${DISTDIR}/${DIST_SUBDIR}/${GS_FONTS_OTHER}
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${DATADIR}

post-install:
	${ECHO_MSG} ">>> in post-install ..."
	${ECHO_MSG} ">>>   stripping gs ..."
.if defined(WITH_SHLIB)
	${STRIP_CMD} ${PREFIX}/bin/gsc ${PREFIX}/bin/gsx
	${LN} -sf gsc ${PREFIX}/bin/gs
.else
	${STRIP_CMD} ${PREFIX}/bin/gs
.endif
# for HPDJ driver
	${ECHO_MSG} ">>>   installing ${HPDJ} manpages ..."
.for i in ${HPDJ_MAN1}
	${INSTALL_MAN} ${WRKSRC}/src/${i} ${MANPREFIX}/man/man1
.endfor
	${ECHO_MSG} ">>>   creating ${HPDJ} destdir ..."
	${MKDIR} ${DATADIR}/${GS_VERSION}/${HPDJ}
	${ECHO_MSG} ">>>   installing files in ${HPDJ} destdir ..."
.for i in README.hpdj example.mdf margins-A4.ps margins-A4Rotated.ps \
	margins-Letter.ps margins-LetterRotated.ps
	${INSTALL_DATA} ${WRKSRC}/src/${i} \
		${DATADIR}/${GS_VERSION}/${HPDJ}
.endfor
# for PCL3 driver
	${ECHO_MSG} ">>>   installing ${PCL3} utility in bindir ..."
	${INSTALL_PROGRAM} ${WRKSRC}/bin/pcl3opts ${PREFIX}/bin
	${ECHO_MSG} ">>>   installing ${PCL3} manpages ..."
.for i in ${PCL3_MAN1}
	${INSTALL_MAN} ${WRKSRC}/${PCL3_NAME}/doc/${i} ${MANPREFIX}/man/man1
.endfor
# other pcl3 stuff, which might be interesting for runtime
	${ECHO_MSG} ">>>   creating ${PCL3} destdir ..."
	${MKDIR} ${DATADIR}/${GS_VERSION}/${PCL3}
	${ECHO_MSG} ">>>   installing files in ${PCL3} destdir ..."
.for i in NEWS BUGS README lib/example.mcf lib/if-pcl3 ps/calign.ps \
	ps/dumppdd.ps ps/levels-test.ps ps/margins-A4.ps \
	ps/margins-A4Rotated.ps ps/margins-Env10Rotated.ps \
	ps/margins-EnvDLRotated.ps ps/margins-Letter.ps \
	ps/margins-LetterRotated.ps
	${INSTALL_DATA} ${WRKSRC}/${PCL3_NAME}/${i} \
		${DATADIR}/${GS_VERSION}/${PCL3}
.endfor
# for DMPRT driver
	${ECHO_MSG} ">>>   installing ${DMPRT} resources ..."
.for i in dmp_init.ps dmp_site.ps escp_24.src
	${INSTALL_DATA} ${WRKSRC}/src/${i} \
		${DATADIR}/${GS_VERSION}/lib
.endfor
# for EPAG driver
	${ECHO_MSG} ">>>   installing ${EPAG} utility in bindir ..."
	${INSTALL_PROGRAM} ${WRKSRC}/${EPAG_NAME}/ert ${PREFIX}/bin
# contributed UPP driver
	${ECHO_MSG} ">>> installing contributed UPP profiles ..."
.for i in ${CONTRIB_UPP}
	${INSTALL_DATA} ${FILESDIR}/${i} \
		${DATADIR}/${GS_VERSION}/lib
.endfor
#
# now NOPORTDOCS dependend stuff
#
.if !defined(NOPORTDOCS)
	${ECHO_MSG} ">>> installing PORTDOC stuff ..."
	${MKDIR} ${DOCSDIR}/${GS_VERSION}
# for HPDJ driver
	${ECHO_MSG} ">>>   installing ${HPDJ} docs ..."
	${MKDIR} ${DOCSDIR}/${GS_VERSION}/${HPDJ}
.for i in NEWS hpdj.html
	${INSTALL_DATA} ${WRKSRC}/src/${i} \
		${DOCSDIR}/${GS_VERSION}/${HPDJ}
.endfor
# for PCL3 driver
	${ECHO_MSG} ">>>   installing ${PCL3} docs ..."
	${MKDIR} ${DOCSDIR}/${GS_VERSION}/${PCL3}
.for i in NEWS doc/gs-pcl3.html doc/how-to-report.txt doc/pcl3opts.html
	${INSTALL_DATA} ${WRKSRC}/${PCL3_NAME}/${i} \
		${DOCSDIR}/${GS_VERSION}/${PCL3}
.endfor
# for MD2K driver
	${ECHO_MSG} ">>>   installing ${MD2K} docs ..."
	${MKDIR} ${DOCSDIR}/${GS_VERSION}/${MD2K}
.for i in README.jis
	${INSTALL_DATA} ${WRKSRC}/${MD2K_NAME}/${i} \
		${DOCSDIR}/${GS_VERSION}/${MD2K}
.endfor
# for ALPS driver
	${ECHO_MSG} ">>>   installing ${ALPS} docs ..."
	${MKDIR} ${DOCSDIR}/${GS_VERSION}/${ALPS}
.for i in README.gdevalps
	${INSTALL_DATA} ${WRKSRC}/${ALPS_NAME}/${i} \
		${DOCSDIR}/${GS_VERSION}/${ALPS}
.endfor
# for BJ10V driver
	${ECHO_MSG} ">>>   installing ${BJ10V} docs ..."
	${MKDIR} ${DOCSDIR}/${GS_VERSION}/${BJ10V}
.for i in gdev10v.jis
	${INSTALL_DATA} ${WRKSRC}/${BJ10V_NAME}/${i} \
		${DOCSDIR}/${GS_VERSION}/${BJ10V}
.endfor
# for LIPS driver
	${ECHO_MSG} ">>>   installing ${LIPS} docs ..."
	${MKDIR} ${DOCSDIR}/${GS_VERSION}/${LIPS}
.for i in Gdevlips.htm
	${INSTALL_DATA} ${WRKSRC}/${LIPS_NAME}/${i} \
		${DOCSDIR}/${GS_VERSION}/${LIPS}
.endfor
# for DMPRT driver
	${ECHO_MSG} ">>>   installing ${DMPRT} docs ..."
	${MKDIR} ${DOCSDIR}/${GS_VERSION}/${DMPRT}
.for i in gdevdmpr.sj
	${INSTALL_DATA} ${WRKSRC}/src/${i} \
		${DOCSDIR}/${GS_VERSION}/${DMPRT}
.endfor
# for EPAG driver
	${ECHO_MSG} ">>>   installing ${EPAG} docs ..."
	${MKDIR} ${DOCSDIR}/${GS_VERSION}/${EPAG}
.for i in ert.txt gdevepag.txt ChangeLog
	${INSTALL_DATA} ${WRKSRC}/${EPAG_NAME}/${i} \
		${DOCSDIR}/${GS_VERSION}/${EPAG}
.endfor
.for i in psprint gsepagif.sh
	${INSTALL_SCRIPT} ${WRKSRC}/${EPAG_NAME}/${i} \
		${DOCSDIR}/${GS_VERSION}/${EPAG}
.endfor
# for EPLASER driver
	${ECHO_MSG} ">>>   installing ${EPLASER} docs ..."
	${MKDIR} ${DOCSDIR}/${GS_VERSION}/${EPLASER}
.for i in readme-eplaser-705.euc readme-eplaser-705-jp.euc
	${INSTALL_DATA} ${WRKSRC}/${EPLASER_NAME}/${i} \
		${DOCSDIR}/${GS_VERSION}/${EPLASER}
.endfor
# for MJC driver
	${ECHO_MSG} ">>>   installing ${MJC} docs ..."
	${MKDIR} ${DOCSDIR}/${GS_VERSION}/${MJC}
.for i in MJ700V2C.FAQ README.mjc README.mje README.noz cpem.doc
	${INSTALL_DATA} ${WRKSRC}/${MJC_NAME}/${i} \
		${DOCSDIR}/${GS_VERSION}/${MJC}
.endfor
# for GDI driver
	${ECHO_MSG} ">>>   installing ${GDI} docs ..."
	${MKDIR} ${DOCSDIR}/${GS_VERSION}/${GDI}
.for i in README
	${INSTALL_DATA} ${WRKSRC}/src/${i} \
		${DOCSDIR}/${GS_VERSION}/${GDI}
.endfor
# for LXM3200 driver
	${ECHO_MSG} ">>>   installing ${LXM3200} docs ..."
	${MKDIR} ${DOCSDIR}/${GS_VERSION}/${LXM3200}
.for i in README RELEASE_NOTES Z12-Z31-QuickSetup
	${INSTALL_DATA} ${WRKSRC}/${LXM3200_NAME}/${i} \
		${DOCSDIR}/${GS_VERSION}/${LXM3200}
.endfor
.endif
	${ECHO_MSG} "> post-installation tasks completed."

.include "Makefile.inc"
.include <bsd.port.post.mk>
