# New ports collection makefile for:	ghostscript-cjk
# Date created:		Dec 24 2001
# Whom:			Tomokatsu SAITO <saito@a2z.co.jp>
#
# $FreeBSD$
#

PORTNAME=	ghostscript
PORTVERSION=	6.52
CATEGORIES=	print
MASTER_SITES=	ftp://ftp.gyve.org/pub/gs-cjk/M2/ \
		ftp://ftp.gyve.org/pub/gs-cjk/ \
		${GPRINT_SITE} ${HPIJS_SITE} ${NPDL_SITE} ${EPAG_SITE} \
		${ALPS_SITE} ${LIPS_SITE} ${EPLASER_SITE} \
		${MASTER_SITE_GNU} \
		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
PKGNAMESUFFIX=	-gnu-cjk
DISTFILES=	${GS_SRC} ${GS_CJK_PATCH} ${CMAP} ${CJKFONTS} \
		${GPRINT_SRC} ${HPIJS_SRC} ${NPDL_SRC} ${EPAG_SRC} \
		${ALPS_SRC} ${LIPS_SRC} ${EPLASER_SRC} ${BJ_SRC} ${MD2K_SRC} \
		${MJC_SRC}
DIST_SUBDIR=	ghostscript
EXTRACT_ONLY=	${GS_SRC}

MAINTAINER=	saito@a2z.co.jp

BUILD_DEPENDS=	${NONEXISTENT}:${PORTSDIR}/graphics/jpeg:extract
LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png
RUN_DEPENDS=	gs:${PORTSDIR}/print/ghostscript-gnu

USE_BZIP2=	yes
USE_XLIB=	yes
USE_GMAKE=	yes
MAKE_ENV=	CC="${CC}" CXX="${CXX}" XCFLAGS="${XCFLAGS}"
MAKEFILE=	src/unix-gcc.mak
PLIST_SUB=	GS_VERSION=${PORTVERSION}

XCFLAGS=	-DUPD_SIGNAL=0

GS_SRC=		${DISTNAME}${EXTRACT_SUFX}
GS_CJK=		gs6.51-cjk-M2-R3
GS_CJK_PATCH=	${GS_CJK}.tar.gz
CMAP=		adobe-cmaps-200109.tar.gz
RESOURCE=	${DATADIR}/Resource
PRINTER_DOC=	${DOCSDIR}/${PORTVERSION}/printers

CJKLIB=		CIDFnmap.ARP CIDFnmap.Bae CIDFnmap.CJK CIDFnmap.Koc \
		CIDFnmap.Ore CIDFnmap.Sol CIDFnmap
CJKLIB2=	gs_cff.ps gs_cidfn.ps gs_cmap.ps gs_init.ps gs_ttf.ps
CJKLIB3=	gs_cidcm.ps gs_res.ps

CJKEXM=		all_ac1.ps gscjk_ac.ps all_ag1.ps gscjk_ag.ps all_aj1.ps \
		gscjk_aj.ps all_aj2.ps gscjk_ak.ps all_ak1.ps iso2022.ps

################# Printer driver stuffs #################
# GPRINT, HPIJS, CONTRIB_UPP are taken from print/ghostscript-gnu
# Other printer drivers are for those sold in Japan.
# Addition for Chinese, Korean printers are welcome.
#
# gimp-print - very high quality driver for Epson, HPs,...
GPRINT=		gimp-print
GPRINT_VERS=	4.2.0
GPRINT_NAME=	${GPRINT}-${GPRINT_VERS}
GPRINT_SRC=	${GPRINT_NAME}.tar.gz
GPRINT_SITE=	${MASTER_SITE_SOURCEFORGE:S,%SUBDIR%,gimp-print,}

# HPinkjet - HP developed printer driver for PhotoSmart/DeskJet series
HPIJS=		hpijs
HPIJS_VERS=	1.0
HPIJS_NAME=	${HPIJS}-${HPIJS_VERS}
HPIJS_SRC=	${HPIJS_NAME}.tar.gz
HPIJS_SITE=	${MASTER_SITE_SOURCEFORGE:S,%SUBDIR%,hpinkjet,}

# contributed uniprint profiles
CONTRIB_UPP=	lqx70ch.upp lqx70cl.upp lqx70cm.upp \
		stc740ih.upp stc740p.upp stc740pl.upp

# NPDL - NEC Printer Description Language driver
NPDL=		gdevnpdl
NPDL_VERS=	1.6.3
NPDL_NAME=	${NPDL}-${NPDL_VERS}
NPDL_SRC=	${NPDL_NAME}.tar.gz
NPDL_SITE=	http://www.ceres.dti.ne.jp/~owatanab/gdevnpdl/

# EPAG - Epson ESC/Page Language driver
EPAG=		epag
EPAG_VERS=	3.09
EPAG_NAME=	${EPAG}-${EPAG_VERS}
EPAG_SRC=	${EPAG_NAME}.tar.gz
EPAG_SITE=	http://www.humblesoft.com/pub/

# ALPS - Alps MD-5000 printer driver
ALPS=		gdevalps
ALPS_VERS=	0.2
ALPS_NAME=	${ALPS}-${ALPS_VERS}
ALPS_SRC=	${ALPS}-0.21.tar.gz
ALPS_SITE=	${MASTER_SITE_PORTS_JP}

# LIPS - Canon LIPS II+/III/IVc/IV printer driver
LIPS=		gdevlips
LIPS_VERS=	2.4.0
LIPS_NAME=	${LIPS}-${LIPS_VERS}
LIPS_SRC=	${LIPS_NAME}.tar.gz
LIPS_SITE=	${MASTER_SITE_PORTS_JP}

# EPLASER - Epson Kowa developed printer driver for ESC/Page Laser printers
EPLASER=	eplaser
EPLASER_VERS=	3.0.1
EPLASER_NAME=	${EPLASER}-${EPLASER_VERS}
EPLASER_SRC=	${EPLASER_NAME}-651.tgz
EPLASER_SITE=	http://www.epkowa.on.arena.ne.jp/pips/data/gs65_301/

# bj10v driver
BJ=		gdev10v
BJ_NAME=	${BJ}
BJ_SRC=		${BJ_NAME}.tar.gz

# md2k driver
MD2K=		gdevmd2k
MD2K_VERS=	0.2a
MD2K_NAME=	${MD2K}-${MD2K_VERS}
MD2K_SRC=	${MD2K_NAME}.tar.gz

# mjc driver
MJC=		gdevmjc
MJC_VERS=	0.8
MJC_NAME=	${MJC}-${MJC_VERS}
MJC_SRC=	${MJC_NAME}.tar.gz

.if defined(NO_A4)
.else
XCFLAGS+=	-DA4
.endif

pre-fetch:
.if !defined(NO_A4)
	@${ECHO_MSG} "Type \"make NO_A4=yes\" if you want not set A4 paper default."
.endif

.SILENT:

post-extract:
	${ECHO_MSG} ">>> in post-extract ..."
	${LN} -sf `cd ${PORTSDIR}/graphics/jpeg && ${MAKE} -V WRKSRC` \
		${WRKSRC}/jpeg
	${TAR} -C ${WRKDIR} -xzf ${DISTDIR}/${DIST_SUBDIR}/${GS_CJK_PATCH}
	cd ${WRKDIR}/${GS_CJK} ; \
		${RM} -f src_time_.h.patch src_unix-gcc.mak.patch
# ** 3rd party driver **
# Note: don't forget to add those devices in scripts/configure and
# configure.batch, which update unix-gcc.mak to build gs with these
# new devices !
#
# for Gimp-Print driver
	${ECHO_MSG} ">>>   extracting ${GPRINT_SRC} ..."
	${TAR} -C ${WRKSRC} -xzf ${DISTDIR}/${DIST_SUBDIR}/${GPRINT_SRC}
# for HPinkjet driver
	${ECHO_MSG} ">>>   extracting ${HPIJS_SRC} ..."
	${TAR} -C ${WRKSRC} -xzf ${DISTDIR}/${DIST_SUBDIR}/${HPIJS_SRC}
# for NPDL driver
	${ECHO_MSG} ">>>   extracting ${NPDL_SRC} ..."
	${TAR} -C ${WRKSRC} -xzf ${DISTDIR}/${DIST_SUBDIR}/${NPDL_SRC}
# for EPAG driver
	${ECHO_MSG} ">>>   extracting ${EPAG_SRC} ..."
	${TAR} -C ${WRKSRC} -xzf ${DISTDIR}/${DIST_SUBDIR}/${EPAG_SRC}
# for ALPS driver
	${ECHO_MSG} ">>>   extracting ${ALPS_SRC} ..."
	${TAR} -C ${WRKSRC} -xzf ${DISTDIR}/${DIST_SUBDIR}/${ALPS_SRC}
	${LN} -sf ${ALPS_NAME} ${WRKSRC}/${ALPS}
# for LIPS driver
	${ECHO_MSG} ">>>   extracting ${LIPS_SRC} ..."
	${TAR} -C ${WRKSRC} -xzf ${DISTDIR}/${DIST_SUBDIR}/${LIPS_SRC}
	${LN} -sf ${LIPS_NAME} ${WRKSRC}/${LIPS}
# for EPLASER driver
	${ECHO_MSG} ">>>   extracting ${EPLASER_SRC} ..."
	${TAR} -C ${WRKSRC} -xzf ${DISTDIR}/${DIST_SUBDIR}/${EPLASER_SRC}
# for bj10v driver
	${ECHO_MSG}  ">>>   extracting ${BJ_SRC} ..."
	${TAR} -C ${WRKSRC} -xzf ${_DISTDIR}/${BJ_SRC}
	${CP} ${WRKSRC}/${BJ_NAME}/gdev10v.c ${WRKSRC}/src
# for md2k driver
	${ECHO_MSG}  ">>>   extracting ${MD2K_SRC} ..."
	${TAR} -C ${WRKSRC} -xzf ${_DISTDIR}/${MD2K_SRC}
	${CP} ${WRKSRC}/${MD2K_NAME}/gdevmd2k.c ${WRKSRC}/src
# for mjc driver
	${ECHO_MSG} ">>>   extracting ${MJC_SRC} ..."
	${TAR} -C ${WRKSRC} -xzf ${_DISTDIR}/${MJC_SRC}
	${CP} ${WRKSRC}/${MJC_NAME}/*.[ch] ${WRKSRC}/src

post-patch:
	${ECHO_MSG} ">>> in post-patch ..."
	${ECHO_MSG} ">>>   applying gs-cjk patchset ..."
	${CAT} ${WRKDIR}/${GS_CJK}/src*patch | ${PATCH} -s -p0 -d ${WRKSRC}
.for i in ${CJKLIB} ${CJKLIB2}
	${PATCH} -s -d ${WRKSRC}/lib < ${WRKDIR}/${GS_CJK}/lib_${i}.patch
.endfor
.for i in ${CJKLIB3}
	${PATCH} -s -d ${WRKSRC}/lib < ${FILESDIR}/${i}.patch
.endfor
.for i in ${CJKEXM}
	${PATCH} -s -d ${WRKSRC}/examples < \
		${WRKDIR}/${GS_CJK}/examples_${i}.patch
.endfor
# for HPinkjet driver
	find ${WRKSRC}/${HPIJS_NAME} -name '*.h' | xargs ${PERL} -pi -e \
		's|#include <malloc.h>||g'

pre-configure:
	${ECHO_MSG} ">>> in pre-configure ..."
	${PERL} -pi -e 's|^DEVICE_DEVS|#DEVICE_DEVS|g' \
		${WRKSRC}/src/unix-gcc.mak
# for Gimp-Print driver
	${ECHO_MSG} ">>>   adding ${GPRINT} driver to contrib.mak ..."
	${CAT} ${PORTSDIR}/print/ghostscript-gnu/files/stp.contrib.mak \
		>> ${WRKSRC}/src/contrib.mak
# for HPinkjet driver
	${ECHO_MSG} ">>>   adding ${HPIJS} driver to contrib.mak ..."
	${CAT} ${PORTSDIR}/print/ghostscript-gnu/files/hpijs.contrib.mak \
		>> ${WRKSRC}/src/contrib.mak
# for NPDL driver
	${ECHO_MSG} ">>>   adding ${NPDL} driver to contrib.mak ..."
	${CAT} ${WRKSRC}/${NPDL_NAME}/gdevnpdl.mak \
		 >>  ${WRKSRC}/src/contrib.mak
# for EPAG driver
	${ECHO_MSG} ">>>   adding ${EPAG} driver to contrib.mak ..."
	${SED} -e 's:npdl:epag:g' ${WRKSRC}/${NPDL_NAME}/gdevnpdl.mak \
		>>  ${WRKSRC}/src/contrib.mak
# for ALPS driver
	${ECHO_MSG} ">>>   adding ${ALPS} driver to contrib.mak ..."
	${CAT} ${WRKSRC}/${ALPS_NAME}/gdevalps.mak-5.50 \
		>>  ${WRKSRC}/src/contrib.mak
# for LIPS driver
	${CAT} ${WRKSRC}/${LIPS_NAME}/gdevlips.mak \
		>>  ${WRKSRC}/src/contrib.mak
# for EPLASER driver
	${CAT} ${WRKSRC}/${EPLASER_NAME}/gdevescv6.mak \
		>>  ${WRKSRC}/src/contrib.mak
	${CAT} ${WRKSRC}/${EPLASER_NAME}/gdevesmv6.mak \
		>>  ${WRKSRC}/src/contrib.mak
# for bj10v driver
	${ECHO_MSG} ">>>   adding ${BJ} driver to contrib.mak ..."
	${CAT} ${WRKSRC}/${BJ_NAME}/gdev10v.mak \
		>> ${WRKSRC}/src/contrib.mak
# for md2k driver
	${ECHO_MSG} ">>>   adding ${MD2K} driver to contrib.mak ..."
	${CAT} ${WRKSRC}/${MD2K_NAME}/gdevmd2k.mak-5.50 \
		>> ${WRKSRC}/src/contrib.mak
# for mjc driver
	${ECHO_MSG} ">>>   adding ${MJC} driver to contrib.mak ..."
	${CAT} ${WRKSRC}/${MJC_NAME}/gdevmjc.mak \
		>>  ${WRKSRC}/src/contrib.mak

do-configure:
	${ECHO_MSG} ">>> in do-configure ..."
.if defined(BATCH) || defined(PACKAGE_BUILDING)
	${SETENV} ${SCRIPTS_ENV} ${SH} ${SCRIPTDIR}/configure.batch
.else
	${SETENV} ${SCRIPTS_ENV} ${SH} ${SCRIPTDIR}/configure
.endif

post-configure:
	${ECHO_MSG} ">>> in post-configure ..."
# for Gimp-Print driver
	${ECHO_MSG} ">>>   running configure script for ${GPRINT} driver ..."
	cd ${WRKSRC}/${GPRINT_NAME} ; \
		${SETENV} ${MAKE_ENV} ${SH} ./configure \
			--without-cups --without-translated-ppds \
			--with-ghost --without-foomatic \
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
	${LN} -sf ${WRKSRC}/${GPRINT_NAME}/include/gimp-print ${WRKSRC}/src
	${LN} -sf ${WRKSRC}/${GPRINT_NAME}/src/ghost/*.[ch] ${WRKSRC}/src
	${LN} -sf ${WRKSRC}/${GPRINT_NAME}/src/main/.libs/libgimpprint.a \
		${WRKSRC}/obj
# for HPinkjet driver
	${ECHO_MSG} ">>>   creating symlinks for ${HPIJS} ..."
.for file in gdevijs.[ch] ijs.[ch] ijs_client.[ch] ijs_exec_unix.c unistd_.h
	${LN} -sf ${WRKSRC}/${HPIJS_NAME}/${file} ${WRKSRC}/src
.endfor
# for NPDL driver
	${ECHO_MSG} ">>>   creating symlinks for ${NPDL} ..."
	${LN} -sf ${WRKSRC}/${NPDL_NAME}/gdevnpdl.c ${WRKSRC}/src
# for EPAG driver
	${ECHO_MSG} ">>>   building ert (Epson printer utility)..."
	cd ${WRKSRC}/${EPAG_NAME} ; \
		${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} Makefile
	${ECHO_MSG} ">>>   creating symlinks for ${EPAG} ..."
	${LN} -sf ${WRKSRC}/${EPAG_NAME}/gdevepag.c ${WRKSRC}/src
# for ALPS driver
	${ECHO_MSG} ">>>   creating symlinks for ${ALPS} ..."
	${LN} -sf ${WRKSRC}/${ALPS_NAME}/gdevalps.c ${WRKSRC}/src
# for LIPS driver
	${ECHO_MSG} ">>>   creating symlinks for ${LIPS} ..."
.for file in gdevlips.[ch] gdevlprn.[ch] gdevl4r.c gdevl4v.c gdevrpdl.c
	${LN} -sf ${WRKSRC}/${LIPS_NAME}/${file} ${WRKSRC}/src
.endfor
# for EPLASER driver
	${ECHO_MSG} ">>>   creating symlinks for ${EPLASER} ..."
.for file in gdevescv.[ch] gdevesmv.c
	${LN} -sf ${WRKSRC}/${EPLASER_NAME}/${file} ${WRKSRC}/src
.endfor

do-install:
	${ECHO_MSG} ">>> in do-install ..."
	${ECHO_MSG} ">>>   overwriting ghostscript executable ..."
	${MV} ${PREFIX}/bin/gs ${PREFIX}/bin/gs.orig
	${INSTALL_PROGRAM} ${WRKSRC}/bin/gs ${PREFIX}/bin
	${ECHO_MSG} ">>>   installing ert (Epson printer utility)..."
	${INSTALL_PROGRAM} ${WRKSRC}/${EPAG_NAME}/ert ${PREFIX}/bin

	${ECHO_MSG} ">>>   installing font files ..."
.for i in ${CJKLIB}
	${INSTALL_DATA} ${WRKSRC}/lib/${i} ${DATADIR}/${PORTVERSION}/lib
.endfor
.for i in  ${CJKLIB2} ${CJKLIB3}
	diff -c ${DATADIR}/${PORTVERSION}/lib/${i} ${WRKSRC}/lib/${i} | \
		${PATCH} -s -d ${DATADIR}/${PORTVERSION}/lib
.endfor

	${ECHO_MSG} ">>>   installing example files ..."
.for i in ${CJKEXM}
	${INSTALL_DATA} ${WRKSRC}/examples/${i} \
		${DATADIR}/${PORTVERSION}/examples
.endfor

	${ECHO_MSG} ">>>   installing font resources ..."
	${MKDIR} ${RESOURCE}
	${MKDIR} ${RESOURCE}/CIDFont
	${MKDIR} ${RESOURCE}/Font
	${TAR} -C ${RESOURCE} -xzf ${DISTDIR}/${DIST_SUBDIR}/${CMAP}
	${TAR} -C ${RESOURCE} -xzf ${WRKDIR}/${GS_CJK}/install-cid.tar.gz

# documents how to setup this package
.if !defined(NOPORTDOCS)
	${ECHO_MSG} ">>>   installing documents ..."
	${MKDIR} ${DOCSDIR}/${PORTVERSION}/CJK
.for i in ANNOUNCE COPYING ChangeLog HACKING NEWS README.cn README.en \
	  README.jp README.kr README.tw
	${INSTALL_DATA} ${WRKDIR}/${GS_CJK}/${i} \
		${DOCSDIR}/${PORTVERSION}/CJK
.endfor
# EPAG documents
	${MKDIR} ${PRINTER_DOC}/${EPAG_NAME}
.for i in ert.txt gdevepag.txt ChangeLog
	${INSTALL_DATA} ${WRKSRC}/${EPAG_NAME}/${i} \
		${PRINTER_DOC}/${EPAG_NAME}
.endfor
.for i in psprint gsepagif.sh
	${INSTALL_SCRIPT} ${WRKSRC}/${EPAG_NAME}/${i} \
		${PRINTER_DOC}/${EPAG_NAME}
.endfor
# NPDL document
	${INSTALL_DATA} ${WRKSRC}/${NPDL_NAME}/gdevnpdl.jis ${PRINTER_DOC}
# ALPS document
	${INSTALL_DATA} ${WRKSRC}/${ALPS_NAME}/README.gdevalps ${PRINTER_DOC}
# LIPS document
	${INSTALL_DATA} ${WRKSRC}/${LIPS_NAME}/Gdevlips.htm ${PRINTER_DOC}
# EPLASER document
	${INSTALL_DATA} ${WRKSRC}/${EPLASER_NAME}/readme-eplaser-651.euc \
		${PRINTER_DOC}
# bj10v document
	${INSTALL_DATA} ${WRKSRC}/${BJ_NAME}/gdev10v.jis ${PRINTER_DOC}
# md2k document
	${INSTALL_DATA} ${WRKSRC}/${MD2K_NAME}/README.jis \
		${PRINTER_DOC}/README.${MD2K}
# MJC document
	${MKDIR} ${PRINTER_DOC}/${MJC}
.for i in MJ700V2C.FAQ README.mjc README.mje README.noz cpem.doc
	${INSTALL_DATA} ${WRKSRC}/${MJC_NAME}/${i} \
		${PRINTER_DOC}/${MJC}
.endfor
.endif

.include <bsd.port.mk>
