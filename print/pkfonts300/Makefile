# New ports collection makefile for: English PK fonts
# Version required:	?
# Date created:		16 Mar 1996
# Whom:			Hideaki Ohmon <ohmon@tom.sfc.keio.ac.jp>
#
# $Id: Makefile,v 1.13 1998/11/19 19:56:39 asami Exp $
#

DISTNAME=	pkfonts
PKGNAME=	pkfonts${RESOLUTION}-1.0
CATEGORIES=	print
MASTER_SITES=	ftp://ftp.tut.ac.jp/TeX/fonts/ \
		ftp://ftp.nihon-u.ac.jp/pub/.OldStockPlace/TeX/WS/font/ \
		ftp://ftp.univ-evry.fr/.04/system/OpenBSD/distfiles/pkfonts/ \
		ftp://ftp.wg.omron.co.jp/pub/tex/
DISTFILES=	pk${RESOLUTION}.tar.gz
# see below for RESOLUTION definition

DIST_SUBDIR=	pkfonts
EXTRACT_ONLY=	# extracted directly in install target
NO_BUILD=	yes
PLIST=		${PKGDIR}/${RESOLUTION}.list

.if !defined(RESOLUTION)
RESOLUTION=	300
.else
.if ${RESOLUTION} != 118 && ${RESOLUTION} != 240 && \
	${RESOLUTION} != 300 && ${RESOLUTION} != 360 && \
	${RESOLUTION} != 400 && ${RESOLUTION} != 600
.BEGIN:
	@${ECHO} "Error: invalid value for RESOLUTION: \"${RESOLUTION}\""
	@${ECHO} "Possible values are: 118, 240, 300, 360, 400 and 600."
	@${FALSE}
.endif
.endif

do-install:
	${MKDIR} ${PREFIX}/lib/fonts
	tar -C ${PREFIX}/lib/fonts -xzf ${DISTDIR}/${DIST_SUBDIR}/${DISTFILES}

.include <bsd.port.mk>
