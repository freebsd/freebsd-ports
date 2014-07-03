# Created by: Lowell Gilbert <lgfbsd@be-well.ilk.org>
# $FreeBSD$

PORTNAME=	isabella-ttf
PORTVERSION=	1.202
PORTREVISION=	1
CATEGORIES=	x11-fonts
MASTER_SITES=	http://www.thibault.org/fonts/isabella/
DISTNAME=	Isabella-${PORTVERSION}-ttf

MAINTAINER=	lgfbsd@be-well.ilk.org
COMMENT=	Font by John Stracke based on the Isabella Breviary

OPTIONS_DEFINE=	DOCS

RUN_DEPENDS=	mkfontscale:${PORTSDIR}/x11-fonts/mkfontscale \
		mkfontdir:${PORTSDIR}/x11-fonts/mkfontdir

NO_BUILD=	yes
WRKSRC=		${WRKDIR}/Isabella
FONTDIR=	${PREFIX}/lib/X11/fonts/stracke
PLIST_SUB=	FONTDIR="${FONTDIR:S|${PREFIX}/||}"

do-install:
	${MKDIR} ${STAGEDIR}${FONTDIR}
	${INSTALL_DATA} ${WRKSRC}/*.ttf ${STAGEDIR}${FONTDIR}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.txt ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
