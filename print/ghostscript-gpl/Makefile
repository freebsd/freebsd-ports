# New ports collection makefile for:	ghostscript
# Version required:	5.0
# Date created:		Tue Jun 10 21:58:54 CEST 1997
# Whom:			Andreas Klemm <andreas@klemm.gtn.com>
#
# $Id: Makefile,v 1.14 1997/10/13 11:22:43 asami Exp $
#

DISTNAME=	ghostscript-5.10
CATEGORIES=	print
MASTER_SITES=	ftp://ftp.cs.wisc.edu/ghost/aladdin/gs510/ \
		ftp://bonk.ethz.ch/gs-driver-distrib/
DISTFILES=	${GS_SOURCES} ${GS_FONTS_STD} ${GS_FONTS_OTHER} \
		${HP850_DRV}

MAINTAINER=	andreas@FreeBSD.ORG

BUILD_DEPENDS=	/nonexistent:${PORTSDIR}/graphics/jpeg:extract \
		/nonexistent:${PORTSDIR}/graphics/png:extract \
		unzip:${PORTSDIR}/archivers/unzip

MAKE_ENV=	PORTSDIR=${PORTSDIR}
EXTRACT_ONLY=	${GS_SOURCES}
WRKSRC=		${WRKDIR}/gs5.10
MAKEFILE=	unix-gcc.mak
MAKE_FLAGS=	prefix=${PREFIX} zlibc_=-lz CFLAGS="${CFLAGS}" -f
MAN1=		gs.1 pdf2dsc.1 pdf2ps.1 ps2ascii.1 ps2epsi.1 ps2pdf.1

GS_SOURCES=	ghostscript-5.10.tar.gz
GS_SOURCES+=	ghostscript-5.10gnu.tar.gz
#  Note: the following two are real files that have symlinks with
#  later version numbers pointing to them.  To avoid unnecessarily
#  downloading distfiles, do not change these when upgrading the port
#  unless the files really change.
GS_FONTS_STD=	ghostscript-fonts-std-4.0.tar.gz
GS_FONTS_OTHER=	ghostscript-fonts-other-5.03.tar.gz

# Additional driver HP 850, see http://bonk.ethz.ch/hp850/hp850.html
HP850_DRV=	hp850.zip

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
	${TOUCH} ${WRKSRC}/adler32.c
	${TOUCH} ${WRKSRC}/deflate.c
	${TOUCH} ${WRKSRC}/trees.c
	${TOUCH} ${WRKSRC}/adler32.o
	${TOUCH} ${WRKSRC}/deflate.o
	${TOUCH} ${WRKSRC}/trees.o
	ln -s ${PORTSDIR}/graphics/jpeg/work/jpeg-6a ${WRKSRC}/jpeg-6a
	ln -s ${PORTSDIR}/graphics/png/work/libpng-0.96 ${WRKSRC}/libpng
	cd ${WRKSRC} && unzip -La ${DISTDIR}/${HP850_DRV}

do-configure:
.if defined(BATCH)
	@${SETENV} PORTSDIR=${PORTSDIR} WRKSRC=${WRKSRC} \
		${SH} ${SCRIPTDIR}/configure.batch
.else
	@${SETENV} PORTSDIR=${PORTSDIR} WRKSRC=${WRKSRC} \
		${SH} ${SCRIPTDIR}/configure
.endif

pre-install:
	@${MKDIR} ${PREFIX}/share/ghostscript ${PREFIX}/bin ${PREFIX}/man/man1
	(cd ${PREFIX}/share/ghostscript ; \
			tar -xzf ${DISTDIR}/${GS_FONTS_STD})
	(cd ${PREFIX}/share/ghostscript/fonts ; \
			tar -xzf ${DISTDIR}/${GS_FONTS_OTHER})

post-install:
	strip ${PREFIX}/bin/gs

.include <bsd.port.mk>
