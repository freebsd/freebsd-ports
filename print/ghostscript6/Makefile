# New ports collection makefile for:	ghostscript
# Version required:	6.01
# Date created:		Tue Jun 10 21:58:54 CEST 1997
# Whom:			Andreas Klemm <andreas@klemm.gtn.com>
#
# $FreeBSD$
#

DISTNAME=	ghostscript-${GS_VERSION}
CATEGORIES=	print
MASTER_SITES=	ftp://ftp.cs.wisc.edu/ghost/aladdin/gs601/ \
		ftp://ftp.cs.wisc.edu/ghost/aladdin/fonts/ \
		http://www.ozemail.com.au/~geoffk/pdfencrypt/ \
		http://www.proaxis.com/~mgelhaus/linux/software/hp880c/1.31/
DISTFILES=	${GS_SOURCES} ${GS_FONTS_STD} ${GS_FONTS_OTHER} \
		${DECRYPT_PDF} ${HP880_DRV}

MAINTAINER=	andreas@FreeBSD.org

Y2K=		http://www.cs.wisc.edu/~ghost/aladdin/y2k.html

BUILD_DEPENDS=	/nonexistent:${PORTSDIR}/graphics/jpeg:extract
LIB_DEPENDS=	png.3:${PORTSDIR}/graphics/png

GS_VERSION=	6.01
PLIST_SUB=	GS_VERSION=${GS_VERSION}
USE_XLIB=	yes
EXTRACT_ONLY=	${GS_SOURCES}
WRKSRC=		${WRKDIR}/gs${GS_VERSION}
USE_GMAKE=	yes
MAKEFILE=	src/unix-gcc.mak
# Note: the order that the manpages are listed here matters because
# some of them are symbolic links
MAN1=		gs.1 dvipdf.1 font2c.1 eps2eps.1 gsbj.1 gsdj.1 gsdj500.1 \
		gslj.1 gslp.1 gsnd.1 pdf2dsc.1 pdf2ps.1 pf2afm.1 \
		pfbtopfa.1 printafm.1 ps2ascii.1 ps2epsi.1 ps2pdf12.1 \
		ps2pdf13.1 ps2pdf.1 ps2pdfwr.1 ps2ps.1 wftopfa.1

GS_SOURCES=	ghostscript-${GS_VERSION}.tar.gz
#  Note: the following two are real files that have symlinks with
#  later version numbers pointing to them.  To avoid unnecessarily
#  downloading distfiles, do not change these when upgrading the port
#  unless the files really change.
GS_FONTS_STD=	ghostscript-fonts-std-6.0.tar.gz
GS_FONTS_OTHER=	ghostscript-fonts-other-6.0.tar.gz

# Additional Drivers:

# http://www.proaxis.com/~mgelhaus/linux/software/hp880c/hp880c.html
HP880_DRV=	gdevcd8.tar.gz

# contributed uniprint profiles
CONTRIB_UPP=	lqx70ch.upp lqx70cl.upp lqx70cm.upp \
		stc740ih.upp stc740p.upp stc740pl.upp

# encrypted PDF support.  can't be packaged due to export control issues.
.if defined(PDFENCRYPT)
MASTER_SITES+=	http://www.ozemail.com.au/~geoffk/pdfencrypt/
DISTFILES+=	pdf_sec.ps
RESTRICTED=	"Crypto; export controlled, RC4 in PostScript code included"
.endif

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
	@${LN} -s ${PORTSDIR}/graphics/jpeg/work/jpeg-6b ${WRKSRC}/jpeg
	@cd ${WRKSRC}; ${TAR} -xzf ${DISTDIR}/${HP850_DRV}

do-configure:
.if defined(BATCH)
	@${SETENV} WRKSRC=${WRKSRC} ${SH} ${SCRIPTDIR}/configure.batch
.else
	@${SETENV} WRKSRC=${WRKSRC} ${SH} ${SCRIPTDIR}/configure
.endif

pre-build:
	@${MKDIR} ${WRKSRC}/obj
	@${MKDIR} ${WRKSRC}/bin

pre-install:
	@${MKDIR} ${PREFIX}/share/ghostscript
	@(cd ${PREFIX}/share/ghostscript ; \
			${TAR} -xzf ${DISTDIR}/${GS_FONTS_STD})
	@(cd ${PREFIX}/share/ghostscript ; \
			${TAR} -xzf ${DISTDIR}/${GS_FONTS_OTHER})

post-install:
	@strip ${PREFIX}/bin/gs
	@${INSTALL_SCRIPT} ${WRKSRC}/lib/unix-lpr.sh ${PREFIX}/bin
	@${INSTALL_SCRIPT} ${WRKSRC}/lib/lprsetup.sh ${PREFIX}/bin
.for i in ${CONTRIB_UPP}
	@${INSTALL_DATA} ${FILESDIR}/$i \
		${PREFIX}/share/ghostscript/${GS_VERSION}/lib
.endfor
.if defined(PDFENCRYPT)
	@${INSTALL_DATA} ${DISTDIR}/pdf_sec.ps \
		${PREFIX}/share/ghostscript/${GS_VERSION}/lib
.endif

.include <bsd.port.mk>
