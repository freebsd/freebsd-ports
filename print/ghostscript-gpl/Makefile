# New ports collection makefile for:	ghostscript
# Date created:		Tue Jun 10 21:58:54 CEST 1997
# Whom:			Andreas Klemm <andreas@klemm.gtn.com>
#
# $FreeBSD$
#

PORTNAME=	ghostscript
PORTVERSION=	7.04
PORTREVISION=	7
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:S/$/:gs_srcs,gs_fonts,gprint,bjc250/} \
		http://www.gelhaus.net/hp880c/1.4beta/:hp8xx \
		http://home.t-online.de/home/Martin.Lottermoser/pcl3dist/:hpdj_pcl3 \
		http://www.harsch.net/Download/:dj970 \
		http://plaza26.mbn.or.jp/~higamasa/gdevmd2k/:md2k \
		${MASTER_SITE_PORTS_JP:S/$/:ports_jp,ports_jp_gs/} \
		http://www.ucatv.ne.jp/~taeko/software/gs/:lips \
		http://www.humblesoft.com/pub/:epag \
		http://www.epkowa.on.arena.ne.jp/pips/data/gs65_304/:eplaser \
		http://www.hi.is.uec.ac.jp/~osamuw/gdevnpdl/:npdl \
		http://www.linuxprinting.org/download/printing/samsung-gdi/:gdi \
		ftp://mirror.cs.wisc.edu/pub/mirrors/ghost/AFPL/fonts/:fonts \
		ftp://mirror.cs.wisc.edu/pub/mirrors/ghost/AFPL/gs704/
MASTER_SITE_SUBDIR=	ghostscript/:gs_srcs,gs_fonts,ports_jp_gs \
			gimp-print/:gprint \
			bjc250gs/:bjc250 \
			./:ports_jp
PKGNAMESUFFIX=	-afpl
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
		${LIPS_SRCS}:lips \
		${DMPRT_SRCS}:ports_jp_gs \
		${EPAG_SRCS}:epag \
		${EPLASER_SRCS}:eplaser \
		${MJC_SRCS}:ports_jp \
		${NPDL_SRCS}:npdl \
		${GDI_SRCS}:gdi
DIST_SUBDIR=	ghostscript
EXTRACT_ONLY=	${GS_SRCS}

MAINTAINER=	ports@FreeBSD.org

BUILD_DEPENDS=	${NONEXISTENT}:${PORTSDIR}/graphics/jpeg:extract
LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png

NO_CDROM=	"Can only be distributed for free"

WRKSRC=		${WRKDIR}/gs${PORTVERSION}

USE_BZIP2=	yes
USE_REINPLACE=	yes
USE_GMAKE=	yes
MAKE_ENV=	CC="${CC}" CXX="${CXX}" CFLAGS_STANDARD="${CFLAGS}" \
		XCFLAGS="${XCFLAGS}"
PLIST_SUB=	GS_VERSION=${PORTVERSION}

MAN1=		ansi2knr.1 dvipdf.1 font2c.1 gs-hpdj.1 gs-pcl3.1 \
		gs.1 gslp.1 gsnd.1 pcl3opts.1 pdf2dsc.1 pdf2ps.1 pdfopt.1 \
		pf2afm.1 pfbtopfa.1 printafm.1 ps2ascii.1 ps2epsi.1 ps2pdf.1 \
		ps2pdfwr.1 ps2ps.1 wftopfa.1
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

.if !defined(WITHOUT_X11)
USE_XLIB=	yes
.else
PKGNAMESUFFIX:=	${PKGNAMESUFFIX}-nox11
MAKE_ENV+=	WITHOUT_X11="${WITHOUT_X11}"
.endif

.if defined(WITH_SHLIB)
.undef WITHOUT_X11
USE_GNOMENG=	yes
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
#  Note: the following two are real files that have symlinks with
#  later version numbers pointing to them.  To avoid unnecessarily
#  downloading distfiles, do not change these when upgrading the port
#  unless the files really change.
GS_FONTS_STD=	ghostscript-fonts-std-6.0.tar.gz
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

# PCL3 (hpdj successor now in RELEASE quality)
# additional driver for HP PCL3 printers, by Martin Lottermoser
# http://home.t-online.de/home/Martin.Lottermoser/pcl3.html
PCL3=		pcl3
PCL3_VERS=	3.3
PCL3_NAME=	${PCL3}-${PCL3_VERS}
PCL3_SRCS=	${PCL3_NAME}.tar.gz
PCL3_MAN1=	gs-pcl3.1 pcl3opts.1

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
# http://www.epkowa.co.jp/linux/lpd.html
EPLASER=	eplaser
EPLASER_VERS=	3.0.4
EPLASER_NAME=	${EPLASER}-${EPLASER_VERS}
EPLASER_SRCS=	${EPLASER_NAME}-651.tgz

# MJC - additional driver for Epson MachJet series
MJC=		mjc
MJC_VERS=	0.8
MJC_NAME=	gdevmjc-${MJC_VERS}
MJC_SRCS=	${MJC_NAME}.tar.gz

# NPDL - additional driver for NEC Printer Description Language printers
NPDL=		npdl
NPDL_VERS=	1.6.3
NPDL_NAME=	gdevnpdl-${NPDL_VERS}
NPDL_SRCS=	${NPDL_NAME}.tar.gz

# GDI - additional driver for Samsung SmartGDI laser printers
GDI=		gdi
GDI_NAME=	Samsung-SmartGDI-all-GS
GDI_SRCS=	${GDI_NAME}.tar.gz

# contributed uniprint profiles
CONTRIB_UPP=	lqx70ch.upp lqx70cl.upp lqx70cm.upp \
		stc740ih.upp stc740p.upp stc740pl.upp

.SILENT:

pre-everything::
.if !defined(A4)
	${ECHO_MSG} "Type \"make A4=yes\" if you want -DA4 for compilation."
.else
	${ECHO_MSG} "Using -DA4 for compilation."
.endif

post-extract:
	${ECHO_MSG} ">>> in post-extract ..."
	${LN} -sf `cd ${PORTSDIR}/graphics/jpeg && ${MAKE} -V WRKSRC` \
		${WRKSRC}/jpeg
# ** 3rd party driver **
# Note: don't forget to add those devices in scripts/configure and
# configure.batch, which update unix-gcc.mak to build gs with these
# new devices !
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
# for NPDL driver
	${ECHO_MSG} ">>>   extracting ${NPDL_SRCS} ..."
	${TAR} -C ${WRKSRC} -xzf ${DISTDIR}/${DIST_SUBDIR}/${NPDL_SRCS}
# for GDI driver
	${ECHO_MSG} ">>>   extracting ${GDI_SRCS} ..."
	${TAR} -C ${WRKSRC}/src -xzf ${DISTDIR}/${DIST_SUBDIR}/${GDI_SRCS}

post-patch:
	${REINPLACE_CMD} -e 's|^DEVICE_DEVS|#DEVICE_DEVS|g' \
		${WRKSRC}/src/unix-gcc.mak
	${REINPLACE_CMD} -e 's|\. de|\.|g' \
		${WRKSRC}/src/unixinst.mak
	${REINPLACE_CMD} -e 's|%%DATADIR%%|${DATADIR}|g' \
		${WRKSRC}/lib/gs_res.ps
# for DMPRT driver
	${REINPLACE_CMD} -e 's|%%DATADIR%%|${DATADIR}|g ; \
		 s|%%GS_VERSION%%|${PORTVERSION}|g' \
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
# for DJ970 driver
	${ECHO_MSG} ">>>   adding ${DJ970} driver to contrib.mak ..."
	${CAT} ${FILESDIR}/dj970.contrib.mak \
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
	${SED} -e 's:npdl:epag:g' ${WRKSRC}/${NPDL_NAME}/gdevnpdl.mak \
		>> ${WRKSRC}/src/contrib.mak
# for EPLASER driver
	${ECHO_MSG} ">>>   adding ${EPLASER} driver to contrib.mak ..."
	${CAT} ${WRKSRC}/${EPLASER_NAME}/gdevescv6.mak \
		>> ${WRKSRC}/src/contrib.mak
	${CAT} ${WRKSRC}/${EPLASER_NAME}/gdevesmv6.mak \
		>> ${WRKSRC}/src/contrib.mak
# for MJC driver
	${ECHO_MSG} ">>>   adding ${MJC} driver to contrib.mak ..."
	${CAT} ${WRKSRC}/${MJC_NAME}/gdevmjc.mak \
		>> ${WRKSRC}/src/contrib.mak
# for NPDL driver
	${ECHO_MSG} ">>>   adding ${NPDL} driver to contrib.mak ..."
	${CAT} ${WRKSRC}/${NPDL_NAME}/gdevnpdl.mak \
		>> ${WRKSRC}/src/contrib.mak
# for GDI driver
	${ECHO_MSG} ">>>   adding ${GDI} driver to contrib.mak ..."
	${CAT} ${WRKSRC}/src/smartgdi-contrib.mak \
		>> ${WRKSRC}/src/contrib.mak

do-configure:
	${ECHO_MSG} ">>> in do-configure ..."
.if defined(BATCH) || defined(PACKAGE_BUILDING)
	${SETENV} ${SCRIPTS_ENV} ${SH} ${SCRIPTDIR}/configure.batch
.else
.if defined(WITHOUT_X11)
	${GREP} -v '^  "x11' ${SCRIPTDIR}/configure > ${WRKDIR}/configure
	${SETENV} ${SCRIPTS_ENV} ${SH} ${WRKDIR}/configure
.else
	${SETENV} ${SCRIPTS_ENV} ${SH} ${SCRIPTDIR}/configure
.endif
.endif

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
	${LN} -sf ${WRKSRC}/src/unix-gcc.mak ${WRKSRC}/Makefile
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
.for i in gdevlips.[ch] gdevlprn.[ch] gdevl4r.c gdevl4v.c gdevespg.c gdevrpdl.c
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
# for NPDL driver
	${ECHO_MSG} ">>>   creating symlinks for ${NPDL} ..."
.for i in gdevnpdl.c
	${LN} -sf ${WRKSRC}/${NPDL_NAME}/${i} ${WRKSRC}/src
.endfor

pre-install:
	${ECHO_MSG} ">>> in pre-install ..."
	${ECHO_MSG} ">>>   creating ghostscript destdir ..."
	${MKDIR} ${DATADIR}
	${ECHO_MSG} ">>>   extracting ghostscript fonts ..."
	${TAR} -C ${DATADIR} -xzf ${DISTDIR}/${DIST_SUBDIR}/${GS_FONTS_STD}
	${TAR} -C ${DATADIR} -xzf ${DISTDIR}/${DIST_SUBDIR}/${GS_FONTS_OTHER}

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
	${MKDIR} ${DATADIR}/${PORTVERSION}/${HPDJ}
	${ECHO_MSG} ">>>   installing files in ${HPDJ} destdir ..."
.for i in README.hpdj example.mdf margins-A4.ps margins-A4Rotated.ps \
	margins-Letter.ps margins-LetterRotated.ps
	${INSTALL_DATA} ${WRKSRC}/src/${i} \
		${DATADIR}/${PORTVERSION}/${HPDJ}
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
	${MKDIR} ${DATADIR}/${PORTVERSION}/${PCL3}
	${ECHO_MSG} ">>>   installing files in ${PCL3} destdir ..."
.for i in NEWS BUGS README lib/example.mcf lib/if-pcl3 ps/calign.ps \
	ps/dumppdd.ps ps/levels-test.ps ps/margins-A4.ps \
	ps/margins-A4Rotated.ps ps/margins-Env10Rotated.ps \
	ps/margins-EnvDLRotated.ps ps/margins-Letter.ps \
	ps/margins-LetterRotated.ps
	${INSTALL_DATA} ${WRKSRC}/${PCL3_NAME}/${i} \
		${DATADIR}/${PORTVERSION}/${PCL3}
.endfor
# for DMPRT driver
	${ECHO_MSG} ">>>   installing ${DMPRT} resources ..."
.for i in dmp_init.ps dmp_site.ps escp_24.src
	${INSTALL_DATA} ${WRKSRC}/src/${i} \
		${DATADIR}/${PORTVERSION}/lib
.endfor
# for EPAG driver
	${ECHO_MSG} ">>>   installing ${EPAG} utility in bindir ..."
	${INSTALL_PROGRAM} ${WRKSRC}/${EPAG_NAME}/ert ${PREFIX}/bin
# contributed UPP driver
	${ECHO_MSG} ">>> installing contributed UPP profiles ..."
.for i in ${CONTRIB_UPP}
	${INSTALL_DATA} ${FILESDIR}/${i} \
		${DATADIR}/${PORTVERSION}/lib
.endfor
#
# now NOPORTDOCS dependend stuff
#
.if !defined(NOPORTDOCS)
	${ECHO_MSG} ">>> installing PORTDOC stuff ..."
	${MKDIR} ${DOCSDIR}/${PORTVERSION}
# for HPDJ driver
	${ECHO_MSG} ">>>   installing ${HPDJ} docs ..."
	${MKDIR} ${DOCSDIR}/${PORTVERSION}/${HPDJ}
.for i in NEWS hpdj.html
	${INSTALL_DATA} ${WRKSRC}/src/${i} \
		${DOCSDIR}/${PORTVERSION}/${HPDJ}
.endfor
# for PCL3 driver
	${ECHO_MSG} ">>>   installing ${PCL3} docs ..."
	${MKDIR} ${DOCSDIR}/${PORTVERSION}/${PCL3}
.for i in NEWS doc/gs-pcl3.html doc/how-to-report.txt doc/pcl3opts.html
	${INSTALL_DATA} ${WRKSRC}/${PCL3_NAME}/${i} \
		${DOCSDIR}/${PORTVERSION}/${PCL3}
.endfor
# for MD2K driver
	${ECHO_MSG} ">>>   installing ${MD2K} docs ..."
	${MKDIR} ${DOCSDIR}/${PORTVERSION}/${MD2K}
.for i in README.jis
	${INSTALL_DATA} ${WRKSRC}/${MD2K_NAME}/${i} \
		${DOCSDIR}/${PORTVERSION}/${MD2K}
.endfor
# for ALPS driver
	${ECHO_MSG} ">>>   installing ${ALPS} docs ..."
	${MKDIR} ${DOCSDIR}/${PORTVERSION}/${ALPS}
.for i in README.gdevalps
	${INSTALL_DATA} ${WRKSRC}/${ALPS_NAME}/${i} \
		${DOCSDIR}/${PORTVERSION}/${ALPS}
.endfor
# for BJ10V driver
	${ECHO_MSG} ">>>   installing ${BJ10V} docs ..."
	${MKDIR} ${DOCSDIR}/${PORTVERSION}/${BJ10V}
.for i in gdev10v.jis
	${INSTALL_DATA} ${WRKSRC}/${BJ10V_NAME}/${i} \
		${DOCSDIR}/${PORTVERSION}/${BJ10V}
.endfor
# for LIPS driver
	${ECHO_MSG} ">>>   installing ${LIPS} docs ..."
	${MKDIR} ${DOCSDIR}/${PORTVERSION}/${LIPS}
.for i in Gdevlips.htm
	${INSTALL_DATA} ${WRKSRC}/${LIPS_NAME}/${i} \
		${DOCSDIR}/${PORTVERSION}/${LIPS}
.endfor
# for DMPRT driver
	${ECHO_MSG} ">>>   installing ${DMPRT} docs ..."
	${MKDIR} ${DOCSDIR}/${PORTVERSION}/${DMPRT}
.for i in gdevdmpr.sj
	${INSTALL_DATA} ${WRKSRC}/src/${i} \
		${DOCSDIR}/${PORTVERSION}/${DMPRT}
.endfor
# for EPAG driver
	${ECHO_MSG} ">>>   installing ${EPAG} docs ..."
	${MKDIR} ${DOCSDIR}/${PORTVERSION}/${EPAG}
.for i in ert.txt gdevepag.txt ChangeLog
	${INSTALL_DATA} ${WRKSRC}/${EPAG_NAME}/${i} \
		${DOCSDIR}/${PORTVERSION}/${EPAG}
.endfor
.for i in psprint gsepagif.sh
	${INSTALL_SCRIPT} ${WRKSRC}/${EPAG_NAME}/${i} \
		${DOCSDIR}/${PORTVERSION}/${EPAG}
.endfor
# for EPLASER driver
	${ECHO_MSG} ">>>   installing ${EPLASER} docs ..."
	${MKDIR} ${DOCSDIR}/${PORTVERSION}/${EPLASER}
.for i in readme-eplaser-651.euc readme-eplaser-651-jp.euc
	${INSTALL_DATA} ${WRKSRC}/${EPLASER_NAME}/${i} \
		${DOCSDIR}/${PORTVERSION}/${EPLASER}
.endfor
# for MJC driver
	${ECHO_MSG} ">>>   installing ${MJC} docs ..."
	${MKDIR} ${DOCSDIR}/${PORTVERSION}/${MJC}
.for i in MJ700V2C.FAQ README.mjc README.mje README.noz cpem.doc
	${INSTALL_DATA} ${WRKSRC}/${MJC_NAME}/${i} \
		${DOCSDIR}/${PORTVERSION}/${MJC}
.endfor
# for NPDL driver
	${ECHO_MSG} ">>>   installing ${NPDL} docs ..."
	${MKDIR} ${DOCSDIR}/${PORTVERSION}/${NPDL}
.for i in gdevnpdl.jis
	${INSTALL_DATA} ${WRKSRC}/${NPDL_NAME}/${i} \
		${DOCSDIR}/${PORTVERSION}/${NPDL}
.endfor
# for GDI driver
	${ECHO_MSG} ">>>   installing ${GDI} docs ..."
	${MKDIR} ${DOCSDIR}/${PORTVERSION}/${GDI}
.for i in README
	${INSTALL_DATA} ${WRKSRC}/src/${i} \
		${DOCSDIR}/${PORTVERSION}/${GDI}
.endfor
.endif
	${ECHO_MSG} "> post-installation tasks completed."

.include <bsd.port.mk>
