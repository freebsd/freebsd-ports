# New ports collection makefile for:	ghostscript
# Version required:	5.0
# Date created:		Tue Jun 10 21:58:54 CEST 1997
# Whom:			Andreas Klemm <andreas@klemm.gtn.com>
#
# $Id: Makefile,v 1.4 1997/06/14 09:36:28 andreas Exp $
#

DISTNAME=	ghostscript-5.0
CATEGORIES=	print
MASTER_SITES=	ftp://ftp.cs.wisc.edu/ghost/aladdin/
DISTFILES=	${GS_SOURCES} ${GS_FONTS_STD} ${GS_FONTS_OTHER}

MAINTAINER=	andreas@FreeBSD.org

BUILD_DEPENDS=	/nonexistent:${PORTSDIR}/graphics/jpeg \
		/nonexistent:${PORTSDIR}/graphics/png
DEPENDS_TARGET=	extract

MAKE_ENV=	PORTSDIR=${PORTSDIR}
EXTRACT_ONLY=	${GS_SOURCES}
WRKSRC=		${WRKDIR}/gs5.0
MAKEFILE=	unix-gcc.mak
MAKE_FLAGS=	prefix=${PREFIX} zlibc_=-lz CFLAGS="${CFLAGS}" -f
MAN1=		gs.1 pdf2dsc.1 pdf2ps.1 ps2ascii.1 ps2epsi.1 ps2pdf.1

GS_SOURCES=	ghostscript-5.0.tar.gz
GS_SOURCES+=	ghostscript-5.0gnu.tar.gz
#  Note: the following two are real files that have symlinks with
#  later version numbers pointing to them.  To avoid unnecessarily
#  downloading distfiles, do not change these when upgrading the port
#  unless the files really change.
GS_FONTS_STD=	ghostscript-fonts-std-4.0.tar.gz
GS_FONTS_OTHER=	ghostscript-fonts-other-5.0.tar.gz

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
	touch $(WRKSRC)/adler32.c
	touch $(WRKSRC)/deflate.c
	touch $(WRKSRC)/trees.c
	touch $(WRKSRC)/adler32.o
	touch $(WRKSRC)/deflate.o
	touch $(WRKSRC)/trees.o

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
