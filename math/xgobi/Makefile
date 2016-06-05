# Created by: Tony Maher <tonym@biolateral.com.au>
# $FreeBSD$

PORTNAME=	xgobi
PORTVERSION=	2002.06.20
PORTREVISION=	4
CATEGORIES=	math graphics
MASTER_SITES=	http://public.research.att.com/~stat/xgobi/
DISTNAME=	xgobi
EXTRACT_SUFX=	.sh.gz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Graphical data visualisation tool

NO_CDROM=	Restrictive copyright (do not sell for profit)

BROKEN=		fails to fetch (no route to host)
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2016-07-04

PATCH_WRKSRC=	${WRKDIR}/${PORTNAME}/src
CONFIGURE_WRKSRC=	${PATCH_WRKSRC}
BUILD_WRKSRC=	${PATCH_WRKSRC}
CFLAGS+=	-Wno-return-type

USES=		imake
USE_XORG=	xbitmaps xaw

PROGRAMS=	xgvis xgobi
MANDIR=		${WRKSRC}/manpages

OPTIONS_DEFINE=	DOCS

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
	${INSTALL_PROGRAM} -s ${WRKSRC}/src/${file} ${STAGEDIR}${PREFIX}/bin
#	${STRIP_CMD} ${PREFIX}/bin/${file}
	${INSTALL_MAN} ${MANDIR}/${file}.1 ${STAGEDIR}${PREFIX}/man/man1
.endfor
	${INSTALL_DATA} ${WRKSRC}/XGobi.ex ${STAGEDIR}${PREFIX}/lib/X11/app-defaults
	 @${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	 @ cd ${WRKSRC}; \
	   for dir in data_*; do \
		${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/$${dir}; \
		cd ${WRKSRC}/$${dir}; \
		for file in *; do \
			${INSTALL_DATA} $${file} ${STAGEDIR}${EXAMPLESDIR}/$${dir}; \
		done \
	   done

.include <bsd.port.mk>
