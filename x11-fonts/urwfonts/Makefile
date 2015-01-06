# $FreeBSD$

PORTNAME=	urwfonts
PORTVERSION=	1.0
PORTREVISION=	5
CATEGORIES=	x11-fonts
MASTER_SITES=	ftp://ftp.gimp.org/pub/gimp/fonts/
DISTNAME=	urw-fonts

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Another font package for X

RUN_DEPENDS=	fc-cache:${PORTSDIR}/x11-fonts/fontconfig

WRKSRC=		${WRKDIR}/URW
NO_BUILD=	yes

FONTDIR=	${PREFIX}/lib/X11/fonts/${PORTNAME}
PLIST_SUB=	FONTDIR="${FONTDIR:S|${PREFIX}/||}"
SUB_LIST=	FONTDIR="${FONTDIR}"
SUB_FILES=	pkg-message

do-install:
	@${MKDIR} ${STAGEDIR}${FONTDIR}
.for FILE in fonts.dir fonts.scale Fontmap
	${INSTALL_DATA} ${WRKSRC}/$(FILE) ${STAGEDIR}${FONTDIR}
.endfor
	${INSTALL_DATA} ${WRKSRC}/*.pfb ${STAGEDIR}${FONTDIR}
	${INSTALL_DATA} ${WRKSRC}/*.afm ${STAGEDIR}${FONTDIR}
	${INSTALL_DATA} ${WRKSRC}/*.pfm ${STAGEDIR}${FONTDIR}

.include <bsd.port.mk>
