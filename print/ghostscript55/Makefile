# New ports collection makefile for:	ghostscript
# Date created:		Tue Jun 10 21:58:54 CEST 1997
# Whom:			Andreas Klemm <andreas@klemm.gtn.com>
#
# $FreeBSD$
#

PORTNAME=	ghostscript
PORTVERSION=	5.50
CATEGORIES=	print
MASTER_SITES=	ftp://ftp.cs.wisc.edu/ghost/aladdin/gs550/ \
		http://www.erdw.ethz.ch/~bonk/ftp/gs-driver-distrib/ \
		http://www.ozemail.com.au/~geoffk/pdfencrypt/
DISTFILES=	${GS_SOURCES} ${GS_FONTS_STD} ${GS_FONTS_OTHER} \
		${HP850_DRV} ${DECRYPT_PDF}

MAINTAINER=	andreas@FreeBSD.org

Y2K=		http://www.cs.wisc.edu/~ghost/aladdin/y2k.html

BUILD_DEPENDS=	/nonexistent:${PORTSDIR}/graphics/jpeg:extract \
		/nonexistent:${PORTSDIR}/graphics/png:extract \
		unzip:${PORTSDIR}/archivers/unzip
LIB_DEPENDS=	png.3:${PORTSDIR}/graphics/png

USE_XLIB=	yes
EXTRACT_ONLY=	${GS_SOURCES}
WRKSRC=		${WRKDIR}/gs5.50
USE_GMAKE=	yes
MAKEFILE=	unix-gcc.mak
MAN1=		gs.1 pdf2dsc.1 pdf2ps.1 ps2ascii.1 ps2epsi.1 ps2pdf.1 ps2ps.1

GS_SOURCES=	ghostscript-5.50.tar.gz
GS_SOURCES+=	ghostscript-5.50gnu.tar.gz
#  Note: the following two are real files that have symlinks with
#  later version numbers pointing to them.  To avoid unnecessarily
#  downloading distfiles, do not change these when upgrading the port
#  unless the files really change.
GS_FONTS_STD=	ghostscript-fonts-std-5.50.tar.gz
GS_FONTS_OTHER=	ghostscript-fonts-other-5.50.tar.gz

# Additional driver HP 850, see http://www.erdw.ethz.ch/~bonk/hp850/hp850.html
HP850_DRV=	hp8xxs13.zip

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
	${LN} -s ${WRKDIRPREFIX}${.CURDIR}/../../graphics/jpeg/work/jpeg-6b ${WRKSRC}/jpeg
	${LN} -s ${WRKDIRPREFIX}${.CURDIR}/../../graphics/png/work/libpng-* ${WRKSRC}/libpng
	${MV} ${WRKSRC}/devs.mak ${WRKSRC}/devs.mak.bak
	cd ${WRKSRC} && unzip -Lao ${DISTDIR}/${HP850_DRV}
	${MV} ${WRKSRC}/devs.mak.bak ${WRKSRC}/devs.mak

do-configure:
.if defined(BATCH)
	@${SETENV} WRKSRC=${WRKSRC} ${SH} ${SCRIPTDIR}/configure.batch
.else
	@${SETENV} WRKSRC=${WRKSRC} ${SH} ${SCRIPTDIR}/configure
.endif

pre-build:
	${MKDIR} ${WRKSRC}/obj

pre-install:
	@${MKDIR} ${PREFIX}/share/ghostscript ${PREFIX}/bin ${PREFIX}/man/man1
	(cd ${PREFIX}/share/ghostscript ; \
			${TAR} -xzf ${DISTDIR}/${GS_FONTS_STD})
	(cd ${PREFIX}/share/ghostscript/fonts ; \
			${TAR} -xzf ${DISTDIR}/${GS_FONTS_OTHER})

# install the readme and license file of the hp8xxx driver as well
post-install:
	strip ${PREFIX}/bin/gs
	${INSTALL_SCRIPT} ${WRKSRC}/unix-lpr.sh ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/lprsetup.sh ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/license.hp8 \
		${PREFIX}/share/ghostscript/5.50/doc
	${INSTALL_DATA} ${WRKSRC}/readme.hp8 \
		${PREFIX}/share/ghostscript/5.50/doc
.if defined(PDFENCRYPT)
	${INSTALL_DATA} ${DISTDIR}/pdf_sec.ps ${PREFIX}/share/ghostscript/5.50
.endif

# encrypted PDF support.  can't be packaged due to export control issues.
.if defined(PDFENCRYPT)
MASTER_SITES+=	http://www.ozemail.com.au/~geoffk/pdfencrypt/
DISTFILES+=	pdf_sec.ps
RESTRICTED=	"Crypto; export controlled, RC4 in PostScript code included"
.endif

.include <bsd.port.mk>
