# New ports collection makefile for:	ghostscript
# Date created:		Tue Jun 10 21:58:54 CEST 1997
# Whom:			Andreas Klemm <andreas@klemm.gtn.com>
#
# $FreeBSD$
#

PORTNAME=	ghostscript
PORTVERSION=	6.50
CATEGORIES=	print
MASTER_SITES=	ftp://ftp.fh-koblenz.de/pub/Ghostscript/aladdin/gs650/ \
	ftp://ftp.fh-koblenz.de/pub/Ghostscript/aladdin/fonts/ \
	http://www.gelhaus.net/hp880c/1.4beta/ \
	http://home.t-online.de/home/Martin.Lottermoser/pcl3dist/ \
	http://www.harsch.net/Download/ \
	http://www.ozemail.com.au/~geoffk/pdfencrypt/ \
	http://download.sourceforge.net/ghostscript/ \
	ftp://ftp.cs.wisc.edu/ghost/aladdin/fonts/ \
	ftp://ftp.mirror.ac.uk/sites/ftp.cs.wisc.edu/ghost/aladdin/gs650/ \
	ftp://ftp.mirror.ac.uk/sites/ftp.cs.wisc.edu/ghost/aladdin/fonts/ \
	ftp://ftp.medasys-digital-systems.fr/pub/unix/ghostscript/aladdin/gs650/ \
	ftp://ftp.medasys-digital-systems.fr/pub/unix/ghostscript/aladdin/fonts/ \
	ftp://munnari.oz.au/ghost/aladdin/gs650/ \
	ftp://munnari.oz.au/ghost/aladdin/fonts/ \
	ftp://sunsite.cnlab-switch.ch/mirror/ghost/aladdin/gs650/ \
	ftp://sunsite.cnlab-switch.ch/mirror/ghost/aladdin/fonts/
# note: russian mirror isn't up to date
DISTFILES=	${GS_SOURCES} ${GS_FONTS_STD} ${GS_FONTS_OTHER} \
		${DECRYPT_PDF} ${HP8XX_DRV} ${HPDJ_DRV} ${PCL3_SRC} \
		${HP970_DRV}
EXTRACT_ONLY=	${GS_SOURCES}

MAINTAINER=	andreas@FreeBSD.org

BUILD_DEPENDS=	${NONEXISTENT}:${PORTSDIR}/graphics/jpeg:extract
LIB_DEPENDS=	png.4:${PORTSDIR}/graphics/png

WRKSRC=		${WRKDIR}/gs${PORTVERSION}
ALL_TARGET=	all pcl3opts
USE_XLIB=	yes
USE_GMAKE=	yes
MAKEFILE=	src/unix-gcc.mak
PLIST_SUB=	GS_VERSION=${PORTVERSION}
# Note: the order that the manpages are listed here matters because
# some of them are symbolic links
MAN1=		gs.1 dvipdf.1 font2c.1 eps2eps.1 gsbj.1 gsdj.1 gsdj500.1 \
		gslj.1 gslp.1 gsnd.1 pdf2dsc.1 pdfopt.1 pdf2ps.1 pf2afm.1 \
		pfbtopfa.1 printafm.1 ps2ascii.1 ps2epsi.1 ps2pdf12.1 \
		ps2pdf13.1 ps2pdf.1 ps2pdfwr.1 ps2ps.1 wftopfa.1 \
		gs-hpdj.1 gs-pcl3.1 pcl3opts.1

GS_SOURCES=	ghostscript-${PORTVERSION}.tar.gz
#  Note: the following two are real files that have symlinks with
#  later version numbers pointing to them.  To avoid unnecessarily
#  downloading distfiles, do not change these when upgrading the port
#  unless the files really change.
GS_FONTS_STD=	ghostscript-fonts-std-6.0.tar.gz
GS_FONTS_OTHER=	ghostscript-fonts-other-6.0.tar.gz

# Additional Drivers:

# Ghostscript Driver for HP DeskJet 812C/815C/832C/880C/882C/895C
# http://www.gelhaus.net/hp880c/
# driver names:	cdj880
HP8XX_DRV=	gdevcd8.tar.gz

# HPDJ, additional driver for HP PCL3 Printers, by Martin Lottermoser
# ftp://ftp.sbs.de/pub/graphics/ghostscript/pcl3/pcl3.html
HPDJ_NAME=	hpdj
HPDJ_VERS=	2.6
HPDJ_DIR=	${HPDJ_NAME}-${HPDJ_VERS}
HPDJ_SRC=	${HPDJ_NAME}-${HPDJ_VERS}.tar.gz
HPDJ_MAN1=	gs-hpdj.1

# PCL3 (hpdj successor in BETA state)
# additional driver for HP PCL3 Printers, by Martin Lottermoser
# http://home.t-online.de/home/Martin.Lottermoser/pcl3.html
PCL3_NAME=	pcl3
PCL3_VERS=	3.0.2
PCL3_DIR=	${PCL3_NAME}-${PCL3_VERS}
PCL3_SRC=	${PCL3_NAME}-${PCL3_VERS}.tar.gz
PCL3_MAN1=	gs-pcl3.1 pcl3opts.1

# additional driver for HP DeskJet 970, supports duplex printing
HP970_DRV=	gdevdj9.c.gz

# contributed uniprint profiles
CONTRIB_UPP=	lqx70ch.upp lqx70cl.upp lqx70cm.upp \
		stc740ih.upp stc740p.upp stc740pl.upp

# replacement for pdf_sec.ps, that allows you to read encrypted PDF files
DECRYPT_PDF=	pdf_sec.ps

.if defined(A4)
CFLAGS+=	-DA4
.endif

pre-fetch:
.if !defined(A4)
	@${ECHO_MSG} "Type \"make A4=yes\" if you want -DA4 for compilation."
.else
	@${ECHO_MSG} "Using -DA4 for compilation."
.endif

post-extract:
	@${ECHO} ">>> in post-extract ..."
	@${LN} -s ${WRKDIRPREFIX}${.CURDIR}/../../graphics/jpeg/work/jpeg-6b \
		${WRKSRC}/jpeg
# ** 3rd party driver **
# Note: don't forget to add those devices in scripts/configure and
# configure.batch, which update unix-gcc.mak to build gs with these
# new devices !
#
# for HP8XX driver
	@${ECHO} ">>>   extracting ${HP8XX_DRV} ..."
	@${TAR} -C ${WRKSRC}/src -xzf ${DISTDIR}/${HP8XX_DRV}
# for HPDJ driver
	@${ECHO} ">>>   extracting ${HPDJ_SRC} ..."
	@${TAR} -C ${WRKDIR} -xzf ${DISTDIR}/${HPDJ_SRC}
	@${TAR} -C ${WRKSRC}/src -xf ${WRKDIR}/${HPDJ_DIR}/${HPDJ_NAME}.tar
# for PCL3 driver
	@${ECHO} ">>>   extracting ${PCL3_SRC} ..."
	@${TAR} -C ${WRKSRC} -xzf ${DISTDIR}/${PCL3_SRC}
	@${LN} -s ${PCL3_DIR} ${WRKSRC}/pcl3
	@${TAR} -C ${WRKSRC}/${PCL3_DIR} -xf \
		${WRKSRC}/${PCL3_DIR}/${PCL3_NAME}.tar
# for HP DeskJet 970 driver
	@${ECHO} ">>>   extracting ${HP970_DRV} ..."
	@${CP} ${DISTDIR}/${HP970_DRV} ${WRKSRC}/src
	@${GUNZIP_CMD} ${WRKSRC}/src/${HP970_DRV}

# here we apply unofficial patches from 3rd party drivers
post-patch:
# from PCL3 driver
	@${ECHO} ">>> in post-patch ..."
	@${ECHO} ">>>   applying patches from PCL3 ..."
	@${PATCH} -d ${WRKSRC}/src --forward --quiet -E \
		< ${WRKSRC}/${PCL3_DIR}/src/zmedia2.c-6.01.diff

# here we apply the modifications necessary to build the 3rd party drivers
# advantage: you see unmodified makefiles after a pure make extract
pre-configure:
	@${ECHO} ">>> in pre-configure ..."
# for HPDJ driver
	@${ECHO} ">>>   adding HPDJ driver to contrib.mak ..."
	@${CAT} ${WRKSRC}/src/contrib.mak-5.94.add \
		>> ${WRKSRC}/src/contrib.mak
# for PCL3 driver
	@${ECHO} ">>>   adding PCL3 driver to contrib.mak ..."
	@${CAT} ${WRKSRC}/${PCL3_DIR}/src/contrib.mak-6.01.add \
		>> ${WRKSRC}/src/contrib.mak
# for HP DeskJet 970 driver
	@${ECHO} ">>>   adding DJ970 driver to contrib.mak ..."
	@${CAT} ${FILESDIR}/dj970.contrib.mak \
		>> ${WRKSRC}/src/contrib.mak

do-configure:
	@${ECHO} ">>> in do-configure ..."
.if defined(BATCH)
	@${SETENV} ${SCRIPTS_ENV} ${SH} ${SCRIPTDIR}/configure.batch
.else
	# XXX diable dialog based configure, needs some rework later...
	#@${SETENV} ${SCRIPTS_ENV} ${SH} ${SCRIPTDIR}/configure
	@${SETENV} ${SCRIPTS_ENV} ${SH} ${SCRIPTDIR}/configure.batch
.endif

pre-build:
	@${ECHO} ">>> in pre-build ..."
	@${ECHO} ">>>   creating directories for compilation ..."
	@${MKDIR} ${WRKSRC}/obj
	@${MKDIR} ${WRKSRC}/bin

pre-install:
	@${ECHO} ">>> in pre-install ..."
	@${ECHO} ">>>   creating destdir ..."
	@${MKDIR} ${PREFIX}/share/ghostscript
	@${ECHO} ">>>   extracting gs fonts..."
	@${TAR} -C ${PREFIX}/share/ghostscript -xzf ${DISTDIR}/${GS_FONTS_STD}
	@${TAR} -C ${PREFIX}/share/ghostscript -xzf ${DISTDIR}/${GS_FONTS_OTHER}

post-install:
	@${ECHO} ">>> in post-install ..."
	@${ECHO} ">>>   stripping gs ..."
	@strip ${PREFIX}/bin/gs
	@${ECHO} ">>>   installing additional scripts ..."
	@${INSTALL_SCRIPT} ${WRKSRC}/lib/unix-lpr.sh ${PREFIX}/bin
	@${INSTALL_SCRIPT} ${WRKSRC}/lib/lprsetup.sh ${PREFIX}/bin
# for HPDJ driver
	@${ECHO} ">>>   installing HPDJ manpages ..."
.for i in ${HPDJ_MAN1}
	@${INSTALL_MAN} ${WRKSRC}/src/${i} ${PREFIX}/man/man1
.endfor
	@${ECHO} ">>>   creating HPDJ destdir ..."
	@${MKDIR} ${PREFIX}/share/ghostscript/${PORTVERSION}/hpdj
	@${ECHO} ">>>   installing files in HPDJ destdir ..."
.for i in README.hpdj example.mdf margins-A4.ps margins-A4Rotated.ps \
	margins-Letter.ps margins-LetterRotated.ps
	@${INSTALL_DATA} ${WRKSRC}/src/${i} \
		${PREFIX}/share/ghostscript/${PORTVERSION}/hpdj
.endfor
# for PCL3 driver
	@${ECHO} ">>> installing PCL3 manpages ..."
.for i in ${PCL3_MAN1}
	@${INSTALL_MAN} ${WRKSRC}/${PCL3_DIR}/doc/${i} ${PREFIX}/man/man1
.endfor
# other pcl3 stuff, which might be interesting for runtime
	@${ECHO} ">>>   creating PCL3 destdir ..."
	@${MKDIR} ${PREFIX}/share/ghostscript/${PORTVERSION}/pcl3
	@${ECHO} ">>>   installing files in PCL3 destdir ..."
.for i in BETA BUGS README lib/example.mcf lib/if-pcl3 ps/calign.ps \
	ps/dumppdd.ps ps/levels-test.ps ps/margins-A4.ps \
	ps/margins-A4Rotated.ps ps/margins-Env10Rotated.ps \
	ps/margins-EnvDLRotated.ps ps/margins-Letter.ps \
	ps/margins-LetterRotated.ps
	@${INSTALL_DATA} ${WRKSRC}/${PCL3_DIR}/${i} \
		${PREFIX}/share/ghostscript/${PORTVERSION}/pcl3
.endfor
# contributed UPP driver
	@${ECHO} ">>> installing contributed UPP profiles ..."
.for i in ${CONTRIB_UPP}
	@${INSTALL_DATA} ${FILESDIR}/${i} \
		${PREFIX}/share/ghostscript/${PORTVERSION}/lib
.endfor
# for reading encrypted PDFs
	@${ECHO} ">>> installing support for encrypted PDF files ..."
	@${INSTALL_DATA} ${DISTDIR}/${DECRYPT_PDF} \
		${PREFIX}/share/ghostscript/${PORTVERSION}/lib
#
# now NOPORTDOCS dependend stuff
#
.if !defined(NOPORTDOCS)
	@${ECHO} ">>> installing PORTDOC stuff ..."
# install hpdj docu, not necessary for runtime
# note: old hpdj driver has its files in ${WRKSRC}/src
	@${ECHO} ">>>   creating HPDJ docu destdir ..."
	@${MKDIR} ${PREFIX}/share/doc/ghostscript/${PORTVERSION}/hpdj
	@${ECHO} ">>>   installing files in HPDJ docu destdir ..."
.for i in LGPL.txt NEWS hpdj.html
	@${INSTALL_DATA} ${WRKSRC}/src/${i} \
		${PREFIX}/share/doc/ghostscript/${PORTVERSION}/hpdj
.endfor
# install pcl3 docu, not necessary for runtime
# note: new pcl3 driver has a subdir of its own
	@${ECHO} ">>>   creating HPDJ docu destdir ..."
	@${MKDIR} ${PREFIX}/share/doc/ghostscript/${PORTVERSION}/pcl3
	@${ECHO} ">>>   installing files in HPDJ docu destdir ..."
.for i in LGPL NEWS doc/gs-pcl3.html doc/how-to-report.txt doc/pcl3opts.html
	@${INSTALL_DATA} ${WRKSRC}/${PCL3_DIR}/${i} \
		${PREFIX}/share/doc/ghostscript/${PORTVERSION}/pcl3
.endfor
.endif
	@${ECHO} "> post-installation tasks completed."

.include <bsd.port.mk>
