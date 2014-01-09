# $FreeBSD$

PORTNAME=	jmk-x11-fonts
PORTVERSION=	3.0
PORTREVISION=	3
CATEGORIES=	x11-fonts
MASTER_SITES=	http://www.jmknoble.net/fonts/

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Jim Knoble's font package for X

BUILD_DEPENDS=	bdftopcf:${PORTSDIR}/x11-fonts/bdftopcf \
		mkfontdir:${PORTSDIR}/x11-fonts/mkfontdir \
		mkfontscale:${PORTSDIR}/x11-fonts/mkfontscale

USES=		imake

FONTDIR?=	${PREFIX}/lib/X11/fonts/${PORTNAME}
PLIST_SUB=	FONTDIR="${FONTDIR:S|${PREFIX}/||}"

do-install:
	@${MKDIR} ${STAGEDIR}${FONTDIR}
	${INSTALL_DATA} ${WRKSRC}/*.pcf.gz ${STAGEDIR}${FONTDIR}
	${INSTALL_DATA} ${WRKSRC}/fonts.dir ${STAGEDIR}${FONTDIR}

.include <bsd.port.mk>
