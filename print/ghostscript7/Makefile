# New ports collection makefile for:	ghostscript
# Date created:		Tue Jun 10 21:58:54 CEST 1997
# Whom:			Andreas Klemm <andreas@klemm.gtn.com>
#
# $FreeBSD$
#

PORTNAME=	ghostscript
PORTVERSION=	5.50a
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_GNU} \
		ftp://ftp.cs.wisc.edu/ghost/gnu/gs550/ \
		ftp://ftp.cs.wisc.edu/ghost/gnu/fonts/ \
		http://www.ozemail.com.au/~geoffk/pdfencrypt/ \
		http://www.erdw.ethz.ch/~bonk/ftp/gs-driver-distrib/
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTFILES=	${GS_SOURCES} ${GS_FONTS_STD} ${GS_FONTS_OTHER} \
		${DECRYPT_PDF} ${HP850_DRV}
EXTRACT_ONLY=	${GS_SOURCES}

MAINTAINER=	andreas@FreeBSD.org

BUILD_DEPENDS=	${NONEXISTENT}:${PORTSDIR}/graphics/jpeg:extract \
		unzip:${PORTSDIR}/archivers/unzip
LIB_DEPENDS=	png.4:${PORTSDIR}/graphics/png

WRKSRC=		${WRKDIR}/gs5.50

USE_XLIB=	yes
USE_GMAKE=	yes
MAKEFILE=	unix-gcc.mak
MAN1=		gs.1 pdf2dsc.1 pdf2ps.1 ps2ascii.1 ps2epsi.1 ps2pdf.1 ps2ps.1

GS_SOURCES=	gnu-gs-5.50a.tar.gz
#  Note: the following two are real files that have symlinks with
#  later version numbers pointing to them.  To avoid unnecessarily
#  downloading distfiles, do not change these when upgrading the port
#  unless the files really change.
GS_FONTS_STD=	gnu-gs-fonts-std-6.0.tar.gz
GS_FONTS_OTHER=	gnu-gs-fonts-other-6.0.tar.gz

# Additional driver HP 850, see http://www.erdw.ethz.ch/~bonk/hp850/hp850.html
HP850_DRV=	hp8xxs13.zip

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
	${LN} -s ${WRKDIRPREFIX}${.CURDIR}/../../graphics/jpeg/work/jpeg-6b ${WRKSRC}/jpeg
	unzip -L -q -aa -o ${DISTDIR}/${HP850_DRV} -d ${WRKSRC} -x devs.mak

do-configure:
.if defined(BATCH)
	@${SETENV} WRKSRC=${WRKSRC} ${SH} ${SCRIPTDIR}/configure.batch
.else
	@${SETENV} WRKSRC=${WRKSRC} ${SH} ${SCRIPTDIR}/configure
.endif

pre-build:
	${MKDIR} ${WRKSRC}/obj

pre-install:
	@${MKDIR} ${PREFIX}/share/ghostscript
	${TAR} -C ${PREFIX}/share/ghostscript -xzf ${DISTDIR}/${GS_FONTS_STD}
	${TAR} -C ${PREFIX}/share/ghostscript -xzf ${DISTDIR}/${GS_FONTS_OTHER}

# install the readme and license file of the hp8xxx driver as well
post-install:
	strip ${PREFIX}/bin/gs
	${INSTALL_SCRIPT} ${WRKSRC}/unix-lpr.sh ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/lprsetup.sh ${PREFIX}/bin
	${INSTALL_DATA} ${DISTDIR}/pdf_sec.ps \
		${PREFIX}/share/ghostscript/5.50
	${INSTALL_DATA} ${WRKSRC}/license.hp8 \
		${PREFIX}/share/ghostscript/5.50/doc
	${INSTALL_DATA} ${WRKSRC}/readme.hp8 \
		${PREFIX}/share/ghostscript/5.50/doc

.include <bsd.port.mk>
