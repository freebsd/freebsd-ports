# New ports collection makefile for:	ghostscript
# Date created:		Tue Jun 10 21:58:54 CEST 1997
# Whom:			Andreas Klemm <andreas@klemm.gtn.com>
#
# $FreeBSD$
#

PORTNAME=	ghostscript
PORTVERSION=	${GS_VERSION}
PORTREVISION=	${GS_REVISION}
PORTEPOCH=	${GS_EPOCH}
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:S/$/:gs_srcs,bjc250/} \
		http://www.gelhaus.net/hp880c/1.4beta/:hp8xx \
		http://www.harsch.net/Download/:dj970 \
		http://www33.ocn.ne.jp/~higamasa/gdevmd2k/:md2k \
		${MASTER_SITE_PORTS_JP:S/$/:ports_jp,ports_jp_gs/} \
		ftp://download.canon-sales.co.jp/pub/driver/lasershot/linux/:cpca \
		http://www.ucatv.ne.jp/~taeko/software/gs/:lips \
		http://www.humblesoft.com/pub/:epag \
		${MASTER_SITE_LOCAL}:eplaser \
		http://www.linuxprinting.org/download/printing/samsung-gdi/:gdi \
		http://www.linuxprinting.org/download/printing/:lxm3200 \
		http://homepage.powerup.com.au/~pbwest/lexmark/:lx5000 \
		ftp://mirror.cs.wisc.edu/pub/mirrors/ghost/AFPL/gs${GS_VERSION:S/.//}/:gs_srcs
MASTER_SITE_SUBDIR=	ghostscript/:gs_srcs,ports_jp_gs \
			bjc250gs/:bjc250 \
			./:ports_jp \
			arved/:eplaser
PKGNAMESUFFIX=	-afpl
DISTFILES=	${GS_SRCS}:gs_srcs \
		${HP8XX_SRCS}:hp8xx \
		${DJ970_SRCS}:dj970 \
		${MD2K_SRCS}:md2k \
		${ALPS_SRCS}:ports_jp_gs \
		${BJ10V_SRCS}:ports_jp_gs \
		${BJC250_SRCS}:bjc250 \
		${CPCA_SRCS}:cpca \
		${LIPS_SRCS}:lips \
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
COMMENT=	AFPL Postscript interpreter

LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg \
		png.5:${PORTSDIR}/graphics/png
RUN_DEPENDS=	${LOCALBASE}/share/ghostscript/fonts/a010013l.pfb:${PORTSDIR}/print/gsfonts

NO_CDROM=	Can only be distributed for free

CONFLICTS=	ghostscript-gnu* ghostscript-gpl*
USE_BZIP2=	yes
USE_GMAKE=	yes
MAKE_ENV=	CC="${CC}" CXX="${CXX}" CFLAGS_STANDARD="${CFLAGS}" \
		XCFLAGS="${XCFLAGS}"
PLIST_SUB=	GS_VERSION="${GS_VERSION}" \
		CIDFONTDIR=${CIDFONTDIR}

SCRIPTS_ENV=	GS_DRIVERS_LIST="${GS_DRIVERS_LIST}" \
		WITHOUT_X11="${WITHOUT_X11}" \
		WITH_SVGALIB="${WITH_SVGALIB}"

MAN1=		dvipdf.1 font2c.1 gs.1 gslp.1 gsnd.1 pdf2dsc.1 pdf2ps.1 \
		pdfopt.1 pf2afm.1 pfbtopfa.1 printafm.1 ps2ascii.1 \
		ps2epsi.1 ps2pdf.1 ps2pdfwr.1 ps2ps.1 wftopfa.1
MLINKS=		gslp.1 gsbj.1 \
		gslp.1 gsdj.1 \
		gslp.1 gsdj500.1 \
		gslp.1 gslj.1 \
		ps2pdf.1 ps2pdf12.1 \
		ps2pdf.1 ps2pdf13.1 \
		ps2ps.1 eps2eps.1

XCFLAGS=	-DUPD_SIGNAL=0 -DSTDINT_TYPES_DEFINED=1

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

.if defined(WITH_FT_BRIDGE)
BUILD_DEPENDS+=	${LOCALBASE}/lib/libfreetype.a:${PORTSDIR}/print/freetype2
MAKE_ENV+=	FT_BRIDGE=1 FT_ROOT="${WRKSRC}/freetype" FT_LIB_EXT=".a"
.endif

.if defined(WITH_SHLIB)
.undef WITHOUT_X11
USE_GNOME=	gtk12
MAKE_ENV+=	GS_SHLIB_VER="${SHLIB_VER}"
ALL_TARGET=	so
INSTALL_TARGET=	soinstall
INSTALLS_SHLIB=	yes
SHLIB_VER=	1
PLIST_SUB+=	SHLIB="" SHLIB_VER="${SHLIB_VER}"
.else
PLIST_SUB+=	SHLIB="@comment "
.endif

GS_SRCS=	${DISTNAME}${EXTRACT_SUFX}
CIDFONTDIR=	${PREFIX}/share/ghostscript/${GS_VERSION}/Resource

# Additional Drivers:

# HP8XX - additional driver for HP DeskJet 812C/815C/832C/880C/882C/895C
# http://www.gelhaus.net/hp880c/
HP8XX=		cdj880
HP8XX_SRCS=	gdevcd8.tar.gz

# DJ970 - additional driver for HP DeskJet 970, supports duplex printing
# http://www.harsch.net/Ghostscript/ghostscript.html
DJ970=		gdevdj9
DJ970_SRCS=	${DJ970}.c.gz

# MD2K - additional driver for Alps MD-2000/2010/4000/1300/1500/5000
# http://www33.ocn.ne.jp/~higamasa/gdevmd2k/
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

# EPAG - additional driver for Epson ESC/Page printers
# http://www.humblesoft.com/gdevepag.html
EPAG=		epag
EPAG_VERS=	3.09
EPAG_NAME=	${EPAG}-${EPAG_VERS}
EPAG_SRCS=	${EPAG_NAME}.tar.gz

# EPLASER - additional driver for ESC/Page printers, by EPSON AVASYS Corp.
# http://www.avasys.jp/english/linux_e/index.html
EPLASER=	eplaser
EPLASER_VERS=	3.1.4
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

.include "Makefile.inc"
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
# for DJ970 driver
	${ECHO_MSG} ">>>   extracting ${DJ970_SRCS} ..."
	${CP} ${DISTDIR}/${DIST_SUBDIR}/${DJ970_SRCS} ${WRKSRC}/src
	${GUNZIP_CMD} ${WRKSRC}/src/${DJ970_SRCS}
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
# for EPAG driver
	${ECHO_MSG} ">>>   extracting ${EPAG_SRCS} ..."
	${TAR} -C ${WRKSRC} -xzf ${DISTDIR}/${DIST_SUBDIR}/${EPAG_SRCS}
	${LN} -sf ${EPAG_NAME} ${WRKSRC}/${EPAG}
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

# here we apply the modifications necessary to build the 3rd party drivers
# advantage: you see unmodified makefiles after a pure make extract
pre-configure:
	${ECHO_MSG} ">>> in pre-configure ..."
# for HP8XX driver
	${ECHO_MSG} ">>>   adding ${HP8XX} driver to contrib.mak ..."
	${CAT} ${FILESDIR}/cdj850.contrib.mak \
		>> ${WRKSRC}/src/contrib.mak
# for DJ970 driver
	${ECHO_MSG} ">>>   adding ${DJ970} driver to contrib.mak ..."
	${CAT} ${FILESDIR}/dj970.contrib.mak \
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

pre-build:
	${ECHO_MSG} ">>> in pre-build ..."
	${ECHO_MSG} ">>>   creating directories for compilation ..."
	${MKDIR} ${WRKSRC}/obj
	${MKDIR} ${WRKSRC}/bin
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
.if defined(WITH_FT_BRIDGE)
	${MKDIR} ${WRKSRC}/freetype/include
	${LN} -sf ${LOCALBASE}/include/ft2build.h \
		${WRKSRC}/freetype/include/ft2build.h
	${LN} -sf ${LOCALBASE}/include/freetype2/freetype \
		${WRKSRC}/freetype/include/freetype
	${MKDIR} ${WRKSRC}/freetype/objs
	${LN} -sf ${LOCALBASE}/lib/libfreetype.a \
		${WRKSRC}/freetype/objs/freetype214MT_D.a
.endif

pre-su-install:
	${ECHO_MSG} ">>> in pre-install ..."
	${ECHO_MSG} ">>>   creating ghostscript destdir ..."
	${MKDIR} ${DATADIR}
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${DATADIR}

post-install:
	${ECHO_MSG} ">>> in post-install ..."
	${LN} -s -f ${LOCALBASE}/share/fonts/CIDFont ${CIDFONTDIR}/CIDFont
	${ECHO_MSG} ">>>   stripping gs ..."
.if defined(WITH_SHLIB)
	${STRIP_CMD} ${PREFIX}/bin/gsc ${PREFIX}/bin/gsx
	${LN} -sf gsc ${PREFIX}/bin/gs
.else
	${STRIP_CMD} ${PREFIX}/bin/gs
.endif
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
.for i in readme-eplaser-705.euc
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

.include <bsd.port.post.mk>
