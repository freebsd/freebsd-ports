# New ports collection makefile for:	ghostscript
# Date created:		11 December 1998
# Whom:			giffunip
#
# $FreeBSD$
#

PORTNAME=	ghostscript
PORTVERSION=	5.10
CATEGORIES=	print
MASTER_SITES= ftp://ftp.sbs.de/pub/graphics/ghostscript/pcl3/ \
		${MASTER_SITE_GNU} \
		ftp://ftp.cs.wisc.edu/ghost/gnu/gs510/
MASTER_SITE_SUBDIR=	ghostscript
DISTFILES=	${GS_SOURCES} ${PCL3_DRV}

MAINTAINER=	ports@FreeBSD.org

RUN_DEPENDS=	${LOCALBASE}/share/ghostscript/fonts/Fontmap:${PORTSDIR}/print/gsfonts
BUILD_DEPENDS=	/nonexistent:${PORTSDIR}/graphics/jpeg:extract \
		/nonexistent:${PORTSDIR}/graphics/png:extract
LIB_DEPENDS=	png.3:${PORTSDIR}/graphics/png

USE_XLIB=	yes
EXTRACT_ONLY=	${GS_SOURCES} ${PCL3_DRV}
WRKSRC=		${WRKDIR}/gs5.10

MAKEFILE=	unix-gcc.mak
MAKE_FLAGS=	prefix=${PREFIX} CFLAGS="${CFLAGS}" -f
MAN1=		gs.1 pdf2dsc.1 pdf2ps.1 ps2ascii.1 ps2epsi.1 ps2pdf.1 gs-hpdj.1

GS_SOURCES=	ghostscript-5.10.tar.gz

# Additional driver for HP PCL3 Printers
PCL3_DRV=	hpdj-2.6.tar.gz

post-extract:
	${LN} -s ${WRKDIRPREFIX}${.CURDIR}/../../graphics/jpeg/work/jpeg-6b ${WRKSRC}/jpeg
	${LN} -s ${WRKDIRPREFIX}${.CURDIR}/../../graphics/png/work/libpng-1.0.5 ${WRKSRC}/libpng
	# additional PCL3  driver
	@${TAR} -xf ${WRKDIR}/hpdj-2.6/hpdj.tar -C ${WRKSRC}
	@${CAT} ${WRKSRC}/devs.mak-5.10.add >> ${WRKSRC}/devs.mak
	@${PATCH} -d ${WRKSRC} --forward --quiet -E < ${WRKSRC}/zmedia2.c-5.10.diff

do-configure:
	@(cd ${WRKSRC}; ${SH} tar_cat )

post-install:
	@strip ${PREFIX}/bin/gs
	@${MKDIR} ${PREFIX}/libexec/lpr
	${INSTALL_SCRIPT} ${WRKSRC}/pj-gs.sh ${PREFIX}/libexec/lpr
	${INSTALL_SCRIPT} ${WRKSRC}/sysvlp.sh ${PREFIX}/libexec/lpr
	${INSTALL_SCRIPT} ${WRKSRC}/if-hpdj ${PREFIX}/libexec/lpr
.if defined(PDFENCRYPT)
	${INSTALL_DATA} ${DISTDIR}/pdf_sec.ps ${PREFIX}/share/ghostscript/5.10
.endif

# encrypted PDF support.  can't be packaged due to export control issues.
.if defined(PDFENCRYPT)
MASTER_SITES+=  http://www.ozemail.com.au/~geoffk/pdfencrypt/
DISTFILES+=     pdf_sec.ps
RESTRICTED=     "Crypto; export controlled, RC4 in PostScript code included"
.endif

.include <bsd.port.mk>
