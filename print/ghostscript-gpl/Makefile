# New ports collection makefile for:	ghostscript
# Date created:		Tue Jun 10 21:58:54 CEST 1997
# Whom:			Andreas Klemm <andreas@klemm.gtn.com>
#
# $FreeBSD$
#

PORTNAME=	ghostscript
PORTVERSION=	7.03
PORTREVISION=	3
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		http://members.ozemail.com.au/~geoffk/pdfencrypt/ \
		http://www.gelhaus.net/hp880c/1.4beta/ \
		http://home.t-online.de/home/Martin.Lottermoser/pcl3dist/ \
		http://www.harsch.net/Download/ \
		ftp://mirror.cs.wisc.edu/pub/mirrors/ghost/AFPL/gs703/ \
		ftp://mirror.cs.wisc.edu/pub/mirrors/ghost/AFPL/fonts/
MASTER_SITE_SUBDIR=	${PORTNAME} gimp-print hpinkjet
PKGNAMESUFFIX=	-afpl
DISTFILES=	${GS_SOURCES} ${GS_FONTS_STD} ${GS_FONTS_OTHER} \
		${DECRYPT_PDF} ${HP8XX_DRV} ${HPDJ_SRC} ${PCL3_SRC} \
		${HP970_DRV} ${GPRINT_SRC} ${HPIJS_SRC}
DIST_SUBDIR=	ghostscript
EXTRACT_ONLY=	${GS_SOURCES}

MAINTAINER=	ports@FreeBSD.org

BUILD_DEPENDS=	${NONEXISTENT}:${PORTSDIR}/graphics/jpeg:extract
LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png

NO_CDROM=	"Can only be distributed for free"

WRKSRC=		${WRKDIR}/gs${PORTVERSION}

USE_GMAKE=	yes
MAKE_ENV=	CC="${CC}" CXX="${CXX}" XCFLAGS="${XCFLAGS}"
MAKEFILE=	src/unix-gcc.mak
ALL_TARGET=	all pcl3opts
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

GS_SOURCES=	${DISTNAME}${EXTRACT_SUFX}
#  Note: the following two are real files that have symlinks with
#  later version numbers pointing to them.  To avoid unnecessarily
#  downloading distfiles, do not change these when upgrading the port
#  unless the files really change.
GS_FONTS_STD=	ghostscript-fonts-std-6.0.tar.gz
GS_FONTS_OTHER=	ghostscript-fonts-other-6.0.tar.gz

# Additional Drivers:

# Ghostscript Driver for HP DeskJet 812C/815C/832C/880C/882C/895C
# http://www.gelhaus.net/hp880c/
HP8XX=		cdj880
HP8XX_DRV=	gdevcd8.tar.gz

# HPDJ, additional driver for HP PCL3 Printers, by Martin Lottermoser
# still present, just for the case pcl3 is missing some hpdj feature
# http://home.t-online.de/home/Martin.Lottermoser/pcl3.html
HPDJ=		hpdj
HPDJ_VERS=	2.6
HPDJ_NAME=	${HPDJ}-${HPDJ_VERS}
HPDJ_SRC=	${HPDJ_NAME}.tar.gz
HPDJ_MAN1=	gs-hpdj.1

# PCL3 (hpdj successor now in RELEASE quality)
# additional driver for HP PCL3 Printers, by Martin Lottermoser
# http://home.t-online.de/home/Martin.Lottermoser/pcl3.html
PCL3=		pcl3
PCL3_VERS=	3.3
PCL3_NAME=	${PCL3}-${PCL3_VERS}
PCL3_SRC=	${PCL3_NAME}.tar.gz
PCL3_MAN1=	gs-pcl3.1 pcl3opts.1

# additional driver for HP DeskJet 970, supports duplex printing
# http://www.harsch.net/Ghostscript/ghostscript.html
HP970_DRV=	gdevdj9.c.gz

# Gimp-Print - very high quality driver for Epson, HPs,...
# http://gimp-print.sourceforge.net/
GPRINT=		gimp-print
GPRINT_VERS=	4.2.0
GPRINT_NAME=	${GPRINT}-${GPRINT_VERS}
GPRINT_SRC=	${GPRINT_NAME}.tar.gz

# HPinkjet - HP developed printer driver for PhotoSmart/DeskJet series
# http://hpinkjet.sourceforge.net/
HPIJS=		hpijs
HPIJS_VERS=	1.0.1
HPIJS_NAME=	${HPIJS}-${HPIJS_VERS}
HPIJS_SRC=	${HPIJS_NAME}.tar.gz

# contributed uniprint profiles
CONTRIB_UPP=	lqx70ch.upp lqx70cl.upp lqx70cm.upp \
		stc740ih.upp stc740p.upp stc740pl.upp

# replacement for pdf_sec.ps, that allows you to read encrypted PDF files
DECRYPT_PDF=	pdf_sec.ps

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
	${ECHO_MSG} ">>>   extracting ${HP8XX_DRV} ..."
	${TAR} -C ${WRKSRC}/src -xzf ${DISTDIR}/${DIST_SUBDIR}/${HP8XX_DRV}
# for HPDJ driver
	${ECHO_MSG} ">>>   extracting ${HPDJ_SRC} ..."
	${TAR} -C ${WRKSRC} -xzf ${DISTDIR}/${DIST_SUBDIR}/${HPDJ_SRC}
	${TAR} -C ${WRKSRC}/src -xf ${WRKSRC}/${HPDJ_NAME}/${HPDJ}.tar
# for PCL3 driver
	${ECHO_MSG} ">>>   extracting ${PCL3_SRC} ..."
	${TAR} -C ${WRKSRC} -xzf ${DISTDIR}/${DIST_SUBDIR}/${PCL3_SRC}
	${LN} -sf ${PCL3_NAME} ${WRKSRC}/pcl3
	${TAR} -C ${WRKSRC}/${PCL3_NAME} -xf \
		${WRKSRC}/${PCL3_NAME}/${PCL3}.tar
# for HP DeskJet 970 driver
	${ECHO_MSG} ">>>   extracting ${HP970_DRV} ..."
	${CP} ${DISTDIR}/${DIST_SUBDIR}/${HP970_DRV} ${WRKSRC}/src
	${GUNZIP_CMD} ${WRKSRC}/src/${HP970_DRV}
# for Gimp-Print driver
	${ECHO_MSG} ">>>   extracting ${GPRINT_SRC} ..."
	${TAR} -C ${WRKSRC} -xzf ${DISTDIR}/${DIST_SUBDIR}/${GPRINT_SRC}
# for HPinkjet driver
	${ECHO_MSG} ">>>   extracting ${HPIJS_SRC} ..."
	${TAR} -C ${WRKSRC} -xzf ${DISTDIR}/${DIST_SUBDIR}/${HPIJS_SRC}

post-patch:
	${PERL} -pi -e 's|^DEVICE_DEVS|#DEVICE_DEVS|g' \
		${WRKSRC}/src/unix-gcc.mak
	${PERL} -pi -e 's|\. de|\.|g' \
		${WRKSRC}/src/unixinst.mak
# for HPinkjet driver
	find ${WRKSRC}/${HPIJS_NAME} -name '*.h' | xargs ${PERL} -pi -e \
		's|#include <malloc.h>||g'

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
# for HP DeskJet 970 driver
	${ECHO_MSG} ">>>   adding DJ970 driver to contrib.mak ..."
	${CAT} ${FILESDIR}/dj970.contrib.mak \
		>> ${WRKSRC}/src/contrib.mak
# for Gimp-Print driver
	${ECHO_MSG} ">>>   adding ${GPRINT} driver to contrib.mak ..."
	${CAT} ${FILESDIR}/stp.contrib.mak \
		>> ${WRKSRC}/src/contrib.mak
# for HPinkjet driver
	${ECHO_MSG} ">>>   adding ${HPIJS} driver to contrib.mak ..."
	${CAT} ${FILESDIR}/hpijs.contrib.mak \
		>> ${WRKSRC}/src/contrib.mak

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
# for HPinkjet driver
	${ECHO_MSG} ">>>   running configure script for ${HPIJS} driver ..."
	cd ${WRKSRC}/${HPIJS_NAME} ; \
		${SETENV} ${MAKE_ENV} ${SH} ./configure \
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
	${LN} -sf ${WRKSRC}/${GPRINT_NAME}/include/gimp-print \
		${WRKSRC}/src
	${LN} -sf ${WRKSRC}/${GPRINT_NAME}/src/ghost/*.[ch] \
		${WRKSRC}/src
	${LN} -sf ${WRKSRC}/${GPRINT_NAME}/src/main/.libs/libgimpprint.a \
		${WRKSRC}/obj
# for HPinkjet driver
	${ECHO_MSG} ">>>   building ${HPIJS} server ..."
	cd ${WRKSRC}/${HPIJS_NAME} ; \
		${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} Makefile
	${ECHO_MSG} ">>>   creating symlinks for ${HPIJS} ..."
.for file in gdevijs.[ch] ijs.[ch] ijs_client.[ch] ijs_exec_unix.c unistd_.h
	${LN} -sf ${WRKSRC}/${HPIJS_NAME}/${file} \
		${WRKSRC}/src
.endfor

pre-install:
	${ECHO_MSG} ">>> in pre-install ..."
	${ECHO_MSG} ">>>   creating ghostscript destdir ..."
	${MKDIR} ${DATADIR}
	${ECHO_MSG} ">>>   extracting ghostscript fonts..."
	${TAR} -C ${DATADIR} -xzf ${DISTDIR}/${DIST_SUBDIR}/${GS_FONTS_STD}
	${TAR} -C ${DATADIR} -xzf ${DISTDIR}/${DIST_SUBDIR}/${GS_FONTS_OTHER}

post-install:
	${ECHO_MSG} ">>> in post-install ..."
	${ECHO_MSG} ">>>   stripping gs ..."
	strip ${PREFIX}/bin/gs
# for HPDJ driver
	${ECHO_MSG} ">>>   installing ${HPDJ} manpages ..."
.for i in ${HPDJ_MAN1}
	${INSTALL_MAN} ${WRKSRC}/src/${i} ${PREFIX}/man/man1
.endfor
	${ECHO_MSG} ">>>   creating ${HPDJ} destdir ..."
	${MKDIR} ${DATADIR}/${PORTVERSION}/hpdj
	${ECHO_MSG} ">>>   installing files in ${HPDJ} destdir ..."
.for i in README.hpdj example.mdf margins-A4.ps margins-A4Rotated.ps \
	margins-Letter.ps margins-LetterRotated.ps
	${INSTALL_DATA} ${WRKSRC}/src/${i} \
		${DATADIR}/${PORTVERSION}/hpdj
.endfor
# for PCL3 driver
	${ECHO_MSG} ">>>   installing ${PCL3} manpages ..."
.for i in ${PCL3_MAN1}
	${INSTALL_MAN} ${WRKSRC}/${PCL3_NAME}/doc/${i} ${PREFIX}/man/man1
.endfor
# other pcl3 stuff, which might be interesting for runtime
	${ECHO_MSG} ">>>   creating ${PCL3} destdir ..."
	${MKDIR} ${DATADIR}/${PORTVERSION}/pcl3
	${ECHO_MSG} ">>>   installing files in ${PCL3} destdir ..."
.for i in NEWS BUGS README lib/example.mcf lib/if-pcl3 ps/calign.ps \
	ps/dumppdd.ps ps/levels-test.ps ps/margins-A4.ps \
	ps/margins-A4Rotated.ps ps/margins-Env10Rotated.ps \
	ps/margins-EnvDLRotated.ps ps/margins-Letter.ps \
	ps/margins-LetterRotated.ps
	${INSTALL_DATA} ${WRKSRC}/${PCL3_NAME}/${i} \
		${DATADIR}/${PORTVERSION}/pcl3
.endfor
# for Gimp-Print driver
	${ECHO_MSG} ">>>   creating ${GPRINT} destdir ..."
	${MKDIR} ${DATADIR}/${PORTVERSION}/gimp-print
	${ECHO_MSG} ">>>   installing files in ${GPRINT} destdir ..."
.for i in README
	${INSTALL_DATA} ${WRKSRC}/${GPRINT_NAME}/src/ghost/${i} \
		${DATADIR}/${PORTVERSION}/gimp-print
.endfor
# for HPinkjet driver
	${ECHO_MSG} ">>>   installing ${HPIJS} server in bindir ..."
	${INSTALL_PROGRAM} ${WRKSRC}/${HPIJS_NAME}/hpijs ${PREFIX}/bin
	${ECHO_MSG} ">>>   creating ${HPIJS} destdir ..."
	${MKDIR} ${DATADIR}/${PORTVERSION}/hpijs
	${ECHO_MSG} ">>>   installing files in ${HPIJS} destdir ..."
.for i in hpijs_readme.html gs_hpijs.png printerdb_append append_db.sh
	${INSTALL_DATA} ${WRKSRC}/${HPIJS_NAME}/${i} \
		${DATADIR}/${PORTVERSION}/hpijs
.endfor
# contributed UPP driver
	${ECHO_MSG} ">>> installing contributed UPP profiles ..."
.for i in ${CONTRIB_UPP}
	${INSTALL_DATA} ${FILESDIR}/${i} \
		${DATADIR}/${PORTVERSION}/lib
.endfor
# for reading encrypted PDFs
	${ECHO_MSG} ">>> installing support for encrypted PDF files ..."
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/${DECRYPT_PDF} \
		${DATADIR}/${PORTVERSION}/lib
#
# now NOPORTDOCS dependend stuff
#
.if !defined(NOPORTDOCS)
	${ECHO_MSG} ">>> installing PORTDOC stuff ..."
# install hpdj docu, not necessary for runtime
# note: old hpdj driver has its files in ${WRKSRC}/src
	${ECHO_MSG} ">>>   creating ${HPDJ} docu destdir ..."
	${MKDIR} ${DOCSDIR}/${PORTVERSION}/hpdj
	${ECHO_MSG} ">>>   installing files in ${HPDJ} docu destdir ..."
.for i in NEWS hpdj.html
	${INSTALL_DATA} ${WRKSRC}/src/${i} \
		${DOCSDIR}/${PORTVERSION}/hpdj
.endfor
# install pcl3 docu, not necessary for runtime
# note: new pcl3 driver has a subdir of its own
	${ECHO_MSG} ">>>   creating ${PCL3} docu destdir ..."
	${MKDIR} ${DOCSDIR}/${PORTVERSION}/pcl3
	${ECHO_MSG} ">>>   installing files in ${PCL3} docu destdir ..."
.for i in NEWS doc/gs-pcl3.html doc/how-to-report.txt doc/pcl3opts.html
	${INSTALL_DATA} ${WRKSRC}/${PCL3_NAME}/${i} \
		${DOCSDIR}/${PORTVERSION}/pcl3
.endfor
.endif
	${ECHO_MSG} "> post-installation tasks completed."

.include <bsd.port.mk>
