# New ports collection makefile for:	amspsfnt
# Date created:		11 September 1998
# Whom:			giffunip
#
# $FreeBSD$
#

PORTNAME=	amspsfnt
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	print x11-fonts
MASTER_SITES=	ftp://ftp.ams.org/pub/tex/psfonts/ams/
DISTNAME=	amsps
EXTRACT_SUFX=	-unix.tar.gz

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	AMSFonts PostScript Fonts (Adobe Type 1 format)

BUILD_DEPENDS=	${LOCALBASE}/bin/type1inst:${PORTSDIR}/x11-fonts/p5-type1inst

WRKSRC=		${WRKDIR}/amspsfnt

FONTSDIR=	share/fonts/amspsfont
SUB_FILES=	pkg-message

do-build:
	(cd ${WRKSRC}/pfb; ${LOCALBASE}/bin/type1inst -nolog)

do-install:
	${MKDIR} ${PREFIX}/${FONTSDIR}/afm
	${INSTALL_DATA} ${WRKSRC}/afm/* ${PREFIX}/${FONTSDIR}/afm
	${MKDIR} ${PREFIX}/${FONTSDIR}/pfb
	${INSTALL_DATA} ${WRKSRC}/pfb/* ${PREFIX}/${FONTSDIR}/pfb
	${INSTALL_DATA} ${WRKSRC}/READ.ME ${PREFIX}/${FONTSDIR}

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
