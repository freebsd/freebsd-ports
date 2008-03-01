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
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:S/$/:gs_srcs/} \
		http://www.humblesoft.com/pub/:epag \
		ftp://mirror.cs.wisc.edu/pub/mirrors/ghost/GPL/gs${GS_VERSION:S/.//}/:gs_srcs
MASTER_SITE_SUBDIR=	ghostscript/:gs_srcs
PKGNAMESUFFIX=	-gpl
DISTFILES=	${GS_SRCS}:gs_srcs \
		${EPAG_SRCS}:epag
DIST_SUBDIR=	ghostscript
EXTRACT_ONLY=	${GS_SRCS}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GPL Postscript interpreter

BUILD_DEPENDS=	${LOCALBASE}/share/automake-1.10/install-sh:${PORTSDIR}/devel/automake110 \
		${LOCALBASE}/bin/libtool:${PORTSDIR}/devel/libtool15
LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg \
		png.5:${PORTSDIR}/graphics/png
RUN_DEPENDS=	${LOCALBASE}/share/ghostscript/fonts/a010013l.pfb:${PORTSDIR}/print/gsfonts

CONFLICTS=	ghostscript-gnu*
USE_BZIP2=	yes
USE_GMAKE=	yes
MAKE_ENV=	CC="${CC}" CXX="${CXX}" CFLAGS_STANDARD="${CFLAGS}" \
		XCFLAGS="${XCFLAGS}" XLDFLAGS="${XLDFLAGS}" \
		EXTRALIBS="${EXTRALIBS}"
PLIST_SUB=	GS_VERSION="${GS_VERSION}" \
		CIDFONTDIR="${CIDFONTDIR}"

OPTIONS=	A4SIZE	"Set A4 (not Letter) as a default paper size"	off \
		FONTCONFIG	"fontconfig support"	off \
		FT_BRIDGE	"FreeType bridge"	off \
		ICONV	"libiconv support (required by opvp/oprp drivers)" on \
		JPNFONTS	"Japanese font support"	on \
		SHLIB	"With shared libraries"	off \
		SVGALIB	"svgalib support"	off \
		X11	"X11 support"	on

MAN1=		dvipdf.1 font2c.1 gs.1 gslp.1 gsnd.1 gs-pcl3.1 pcl3opts.1 \
		pdf2dsc.1 pdf2ps.1 pdfopt.1 pf2afm.1 pfbtopfa.1 printafm.1 \
		ps2ascii.1 ps2epsi.1 ps2pdf.1 ps2pdfwr.1 ps2ps.1 wftopfa.1
MLINKS=		gslp.1 gsbj.1 \
		gslp.1 gsdj.1 \
		gslp.1 gsdj500.1 \
		gslp.1 gslj.1 \
		ps2pdf.1 ps2pdf12.1 \
		ps2pdf.1 ps2pdf13.1 \
		ps2ps.1 eps2eps.1

XCFLAGS=	${PTHREAD_CFLAGS}
XLDFLAGS=	${PTHREAD_LIBS}

.include "Makefile.inc"
.include <bsd.port.pre.mk>

SCRIPTS_ENV=	GS_DRIVERS_LIST="${GS_DRIVERS_LIST}" \
		WITHOUT_X11="${WITHOUT_X11}" \
		WITH_SVGALIB="${WITH_SVGALIB}" \
		WITH_ICONV="${WITH_ICONV}"

.if !defined(WITH_LETTERSIZE)
.if defined(A4) || defined(WITH_A4SIZE)
XCFLAGS+=	-DA4
MSG_PAPERSIZE=	"NOTE: Default paper size will be A4."
.endif
.endif

.if defined(WITHOUT_X11)
PKGNAMESUFFIX:=	${PKGNAMESUFFIX}-nox11
.else
USE_XORG=	xt xext
.endif

.if defined(WITH_SVGALIB)
LIB_DEPENDS+=	vga.1:${PORTSDIR}/graphics/svgalib
.endif

.if defined(WITH_ICONV)
USE_ICONV=	yes
EXTRALIBS+=	-liconv
.endif

.if defined(WITH_FONTCONFIG)
LIB_DEPENDS+=	fontconfig.1:${PORTSDIR}/x11-fonts/fontconfig
XCFLAGS+=	-DHAVE_FONTCONFIG=1
EXTRALIBS+=	-lfontconfig
.endif

.if defined(WITH_FT_BRIDGE)
BUILD_DEPENDS+=	${LOCALBASE}/lib/libfreetype.a:${PORTSDIR}/print/freetype2
MAKE_ENV+=	FT_BRIDGE=1 FT_ROOT="${WRKSRC}/freetype" FT_LIB_EXT=".a"
.endif

.if defined(WITH_SHLIB)
.if defined(WITHOUT_X11)
MAKE_ENV+=	SOC_LOADER="dxmainc.c"
.else
USE_GNOME=	gtk20
MAKE_ENV+=	SOC_LOADER="dxmain.c" \
		SOC_CFLAGS="`pkg-config --cflags gtk+-2.0`" \
		SOC_LIBS="`pkg-config --libs gtk+-2.0`"
.endif
ALL_TARGET=	so
INSTALL_TARGET=	soinstall
USE_LDCONFIG=	yes
PLIST_SUB+=	SHLIB="" SHLIB_VER="${GS_VERSION:R}"
.else
PLIST_SUB+=	SHLIB="@comment "
.endif

GS_SRCS=	${DISTNAME}${EXTRACT_SUFX}
CIDFONTDIR=	${PREFIX}/share/ghostscript/${GS_VERSION}/Resource

# Additional Drivers:

# EPAG - additional driver for Epson ESC/Page printers
# http://www.humblesoft.com/gdevepag.html
EPAG=		epag
EPAG_VERS=	3.09
EPAG_NAME=	${EPAG}-${EPAG_VERS}
EPAG_SRCS=	${EPAG_NAME}.tar.gz

# Add support for Japanese fonts
.if defined(WITH_JPNFONTS)
MASTER_SITES+=	http://www.interq.or.jp/mars/cherry/mac/:jpn
DISTFILES+=	${JPN_SRCS}:jpn
JPN_SRCS=	Font.tar.bz2
PLIST_SUB+=	JPN=""
.else
PLIST_SUB+=	JPN="@comment "
.endif

.SILENT:
pre-everything::
	${ECHO_MSG} ${MSG_PAPERSIZE}

post-extract:
	${ECHO_MSG} ">>> in post-extract ..."
.for _FILES in config.guess config.sub ltmain.sh
	(cd ${WRKSRC}/ijs; ${RM} -f ${_FILES}; \
	 ${LN} -s ${LOCALBASE}/share/libtool/${_FILES})
.endfor
.for _FILES in install-sh missing
	(cd ${WRKSRC}/ijs; ${RM} -f ${_FILES}; \
	 ${LN} -s ${LOCALBASE}/share/automake-1.10/${_FILES})
.endfor

# ** 3rd party driver **
# Note: don't forget to add those devices in scripts/configure,
# which update unix-gcc.mak to build gs with these new devices!
#
# for EPAG driver
	${ECHO_MSG} ">>>   extracting ${EPAG_SRCS} ..."
	${TAR} -C ${WRKSRC} -xzf ${DISTDIR}/${DIST_SUBDIR}/${EPAG_SRCS}
	${LN} -sf ${EPAG_NAME} ${WRKSRC}/${EPAG}
# for Japanese fonts
.if defined(WITH_JPNFONTS)
	${ECHO_MSG} ">>>   extracting ${JPN_SRCS} ..."
	${TAR} -C ${WRKSRC}/Resource -xypof ${DISTDIR}/${DIST_SUBDIR}/${JPN_SRCS}
.endif

post-patch:
	${REINPLACE_CMD} -e 's|^DEVICE_DEVS|#DEVICE_DEVS|g' \
		${WRKSRC}/src/unix-gcc.mak
	${REINPLACE_CMD} -e 's|\. de|\.|g' \
		${WRKSRC}/src/unixinst.mak
# for DMPRT driver
	${REINPLACE_CMD} -e 's|%%DATADIR%%|${DATADIR}|g ; \
		 s|%%GS_VERSION%%|${GS_VERSION}|g' \
			${WRKSRC}/contrib/japanese/dmp_site.ps

# here we apply the modifications necessary to build the 3rd party drivers
# advantage: you see unmodified makefiles after a pure make extract
pre-configure:
	${ECHO_MSG} ">>> in pre-configure ..."
# for EPAG driver
	${ECHO_MSG} ">>>   adding EPAG driver to contrib.mak ..."
	${CAT} ${FILESDIR}/epag.contrib.mak \
		>> ${WRKSRC}/src/contrib.mak

post-configure:
	${ECHO_MSG} ">>> in post-configure ..."
	cd ${WRKSRC}/jasper ; \
		${SETENV} ${MAKE_ENV} ${SH} ./configure --prefix=${PREFIX}
	cd ${WRKSRC}/ijs ; \
		${SETENV} ${MAKE_ENV} ${SH} ./autogen.sh

pre-build:
	${ECHO_MSG} ">>> in pre-build ..."
	${ECHO_MSG} ">>>   creating directories for compilation ..."
	${MKDIR} ${WRKSRC}/obj
	${MKDIR} ${WRKSRC}/bin
	${ECHO_MSG} ">>>   creating symlinks for EPAG ..."
.for i in gdevepag.c
	${LN} -sf ${WRKSRC}/${EPAG_NAME}/${i} ${WRKSRC}/src
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

post-build:
# for PCL3 driver
	${ECHO_MSG} ">>>   building PCL3 utility ..."
	cd ${WRKSRC} ; \
		${CC} ${CFLAGS} -I./obj -I./soobj -I./src \
		-I./contrib/pcl3/eprn -o bin/pcl3opts \
		contrib/pcl3/src/pcl3opts.c contrib/pcl3/src/pclscan.c \
		contrib/pcl3/eprn/mediasize.c contrib/pcl3/src/pclsize.c
# for EPAG driver
	${ECHO_MSG} ">>>   building EPAG utility ..."
	cd ${WRKSRC}/${EPAG_NAME} ; \
		${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} Makefile

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
# for PCL3 driver
	${ECHO_MSG} ">>>   installing PCL3 utility in bindir ..."
	${INSTALL_PROGRAM} ${WRKSRC}/bin/pcl3opts ${PREFIX}/bin
	${ECHO_MSG} ">>>   installing PCL3 manpages ..."
.for i in gs-pcl3.1 pcl3opts.1
	${INSTALL_MAN} ${WRKSRC}/contrib/pcl3/doc/${i} ${MANPREFIX}/man/man1
.endfor
# other pcl3 stuff, which might be interesting for runtime
	${ECHO_MSG} ">>>   creating PCL3 destdir ..."
	${MKDIR} ${DATADIR}/${GS_VERSION}/pcl3
	${ECHO_MSG} ">>>   installing files in PCL3 destdir ..."
.for i in NEWS BUGS README lib/example.mcf lib/if-pcl3 ps/calign.ps \
	ps/dumppdd.ps ps/levels-test.ps ps/margins-A4.ps \
	ps/margins-A4Rotated.ps ps/margins-Env10Rotated.ps \
	ps/margins-EnvDLRotated.ps ps/margins-Letter.ps \
	ps/margins-LetterRotated.ps
	${INSTALL_DATA} ${WRKSRC}/contrib/pcl3/${i} \
		${DATADIR}/${GS_VERSION}/pcl3
.endfor
# for DMPRT driver
	${ECHO_MSG} ">>>   installing DMPRT resources ..."
.for i in dmp_init.ps dmp_site.ps escp_24.src
	${INSTALL_DATA} ${WRKSRC}/contrib/japanese/${i} \
		${DATADIR}/${GS_VERSION}/lib
.endfor
# for EPAG driver
	${ECHO_MSG} ">>>   installing EPAG utility in bindir ..."
	${INSTALL_PROGRAM} ${WRKSRC}/${EPAG_NAME}/ert ${PREFIX}/bin
# contributed UPP driver
	${ECHO_MSG} ">>> installing contributed UPP profiles ..."
	${INSTALL_DATA} ${WRKSRC}/contrib/uniprint/*.upp \
		${DATADIR}/${GS_VERSION}/lib
.for i in lqx70ch.upp lqx70cl.upp lqx70cm.upp
	${INSTALL_DATA} ${FILESDIR}/${i} \
		${DATADIR}/${GS_VERSION}/lib
.endfor
# for Japanese fonts
.if defined(WITH_JPNFONTS)
	${ECHO_MSG} ">>>   installing Japanese font resources ..."
	${INSTALL_DATA} ${WRKSRC}/Resource/Font/* \
		${DATADIR}/${GS_VERSION}/Resource/Font/
.endif
#
# now NOPORTDOCS dependend stuff
#
.if !defined(NOPORTDOCS)
	${ECHO_MSG} ">>> installing PORTDOC stuff ..."
	${MKDIR} ${DOCSDIR}/${GS_VERSION}/japanese
	${INSTALL_DATA} ${WRKSRC}/contrib/japanese/doc/* \
		${DOCSDIR}/${GS_VERSION}/japanese
# for HP2200 driver
	${MKDIR} ${DOCSDIR}/${GS_VERSION}/chp2200
.for file in AUTHORS INSTALL
	${INSTALL_DATA} ${WRKSRC}/contrib/chp2200/${file} \
		${DOCSDIR}/${GS_VERSION}/chp2200
.endfor
# contributed UPP driver
	${MKDIR} ${DOCSDIR}/${GS_VERSION}/epson740
.for file in README upp-HowTo-to-be
	${INSTALL_DATA} ${WRKSRC}/contrib/epson740/${file} \
		${DOCSDIR}/${GS_VERSION}/epson740
.endfor
# for LXM3200 driver
	${MKDIR} ${DOCSDIR}/${GS_VERSION}/lxm3200-tweaked
	${INSTALL_DATA} ${WRKSRC}/contrib/lxm3200-tweaked/* \
		${DOCSDIR}/${GS_VERSION}/lxm3200-tweaked
# for MD2K driver
	${MKDIR} ${DOCSDIR}/${GS_VERSION}/md2k_md5k
	${INSTALL_DATA} ${WRKSRC}/contrib/md2k_md5k/* \
		${DOCSDIR}/${GS_VERSION}/md2k_md5k
# for PCL3 driver
	${ECHO_MSG} ">>>   installing PCL3 docs ..."
	${MKDIR} ${DOCSDIR}/${GS_VERSION}/pcl3
.for i in NEWS doc/gs-pcl3.html doc/how-to-report.txt doc/pcl3opts.html
	${INSTALL_DATA} ${WRKSRC}/contrib/pcl3/${i} \
		${DOCSDIR}/${GS_VERSION}/pcl3
.endfor
# for EPAG driver
	${ECHO_MSG} ">>>   installing EPAG docs ..."
	${MKDIR} ${DOCSDIR}/${GS_VERSION}/${EPAG}
.for i in ert.txt gdevepag.txt ChangeLog
	${INSTALL_DATA} ${WRKSRC}/${EPAG_NAME}/${i} \
		${DOCSDIR}/${GS_VERSION}/${EPAG}
.endfor
.for i in psprint gsepagif.sh
	${INSTALL_SCRIPT} ${WRKSRC}/${EPAG_NAME}/${i} \
		${DOCSDIR}/${GS_VERSION}/${EPAG}
.endfor
.endif
	${ECHO_MSG} "> post-installation tasks completed."
	@${ECHO_MSG}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG}

.if defined(WITH_FT_BRIDGE)
	${ECHO_MSG} " *** Configure FAPIfontmap and FAPIcidfmap accordingly"
	${ECHO_MSG} " *** in ${DATADIR}/${GS_VERSION}/lib"
	${ECHO_MSG} " *** to use FreeType fonts."
	@${ECHO_MSG}
.endif

.include <bsd.port.post.mk>
