# New ports collection makefile for:	xgobi
# Date created:				5 December 2001
# Whom:					Tony Maher <tonym@biolateral.com.au>
#
# $FreeBSD$
#

PORTNAME=	xgobi
PORTVERSION=	2002.06.20
CATEGORIES=	math graphics
MASTER_SITES=	http://www.research.att.com/areas/stat/xgobi/
DISTNAME=	xgobi
EXTRACT_SUFX=	.sh.gz

MAINTAINER=	tonym@biolateral.com.au
COMMENT=	Graphical data visualisation tool

NO_CDROM=	"Restrictive copyright (do not sell for profit)"

PATCH_WRKSRC=	${WRKDIR}/${PORTNAME}/src
CONFIGURE_WRKSRC=	${PATCH_WRKSRC}
BUILD_WRKSRC=	${PATCH_WRKSRC}

USE_IMAKE=	true
USE_XPM=	yes

XFREE86_HTML_MAN=	no
MANCOMPRESSED=	no
MAN1=		xgvis.1 xgobi.1

PROGRAMS=	xgvis xgobi
MANDIR=		${WRKSRC}/manpages

# The distfile is a shar file.  It also does not extract cleanly.
# 3 files extract to current directory so use post-extract to move
# them to proper locations.

do-extract:
	@${MKDIR} ${WRKDIR}
	@for file in ${EXTRACT_ONLY}; do \
	    cd ${WRKDIR} && \
	        ${GZCAT} ${DISTDIR}/$${file} | ${SH} > /dev/null 2>&1; \
	done
	@${MV} ${WRKDIR}/aclocal.m4 ${WRKSRC}
	@${MV} ${WRKDIR}/make.out ${WRKSRC}
	@${MV} ${WRKDIR}/xgobi.html ${MANDIR}

do-install:
.for file in ${PROGRAMS}
	${INSTALL_PROGRAM} ${WRKSRC}/src/${file} ${PREFIX}/bin
	${STRIP_CMD} ${PREFIX}/bin/${file}
	${INSTALL_MAN} ${MANDIR}/${file}.1 ${PREFIX}/man/man1
.endfor
	${INSTALL_DATA} ${WRKSRC}/XGobi.ex ${PREFIX}/lib/X11/app-defaults
.if !defined(NOPORTDOCS)
	 @${MKDIR} ${EXAMPLESDIR}
	 @ cd ${WRKSRC}; \
	   for dir in data_*; do \
		${MKDIR} ${EXAMPLESDIR}/$${dir}; \
		cd ${WRKSRC}/$${dir}; \
		for file in *; do \
			${INSTALL_DATA} $${file} ${EXAMPLESDIR}/$${dir}; \
		done \
	   done
.endif

.include <bsd.port.mk>
