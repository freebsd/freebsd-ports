# New ports collection makefile for:	ghostscript
# Version required:	5.10
# Date created:		11 December 1998
# Whom:			giffunip
#
# $Id: Makefile,v 1.28 1999/01/04 03:34:01 steve Exp $
#

DISTNAME=	ghostscript-5.10
CATEGORIES=	print
MASTER_SITES=	ftp://ftp.pdb.sni.de/pub/utilities/misc/	\
		http://www.ozemail.com.au/~geoffk/pdfencrypt/	\
		ftp://ftp.cs.wisc.edu/ghost/gnu/gs510/	\
		$(MASTER_SITE_GNU)
DISTFILES=	${PCL3_DRV} ${DECRYPT_PDF} ghostscript-5.10.tar.gz

MAINTAINER=	ports@FreeBSD.org

RUN_DEPENDS=	$(LOCALBASE)/share/ghostscript/fonts/Fontmap:${PORTSDIR}/print/gsfonts
BUILD_DEPENDS=	/nonexistent:${PORTSDIR}/graphics/jpeg:extract \
		/nonexistent:${PORTSDIR}/graphics/png:extract
LIB_DEPENDS=	png.2:${PORTSDIR}/graphics/png

USE_XLIB=	yes
EXTRACT_ONLY=	${GS_SOURCES} ${PCL3_DRV}
WRKSRC=		${WRKDIR}/gs5.10

MAKEFILE=	unix-gcc.mak
MAKE_FLAGS=	prefix=${PREFIX} CFLAGS="${CFLAGS}" -f
MAN1=		gs.1 pdf2dsc.1 pdf2ps.1 ps2ascii.1 ps2epsi.1 ps2pdf.1 gs-hpdj.1

GS_SOURCES=	ghostscript-5.10.tar.gz

# Additional driver for HP PCL3 Printers
PCL3_DRV=	hpdj-2.5.tar.gz

# replacement for pdf_sec.ps, that allows you to read encrypted PDF files
DECRYPT_PDF=	pdf_sec.ps

post-extract:
	${LN} -s ${WRKDIRPREFIX}${PORTSDIR}/graphics/jpeg/work/jpeg-6b ${WRKSRC}/jpeg
	${LN} -s ${WRKDIRPREFIX}${PORTSDIR}/graphics/png/work/libpng-1.0.3 ${WRKSRC}/libpng
	# additional PCL3  driver
	$(EXTRACT_CMD) -xvf ${WRKDIR}/hpdj-2.5/hpdj.tar -C $(WRKSRC)
	${PATCH} --directory=${WRKSRC} <${WRKSRC}/devs.mak-5.10.diff
	${PATCH} --directory=${WRKSRC} <${WRKSRC}/zmedia2.c-5.10.diff

do-configure:
	@(cd ${WRKSRC}; /bin/sh tar_cat )

post-install:
	strip ${PREFIX}/bin/gs
	${INSTALL_DATA} ${DISTDIR}/${DECRYPT_PDF} \
		${PREFIX}/share/ghostscript/5.10
	$(MKDIR) ${PREFIX}/libexec/lpr
	${INSTALL_SCRIPT} $(WRKSRC)/pj-gs.sh ${PREFIX}/libexec/lpr
	${INSTALL_SCRIPT} $(WRKSRC)/sysvlp.sh ${PREFIX}/libexec/lpr
	${INSTALL_SCRIPT} $(WRKSRC)/if-hpdj ${PREFIX}/libexec/lpr

.include <bsd.port.mk>
