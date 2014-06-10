# $FreeBSD$

PORTNAME=	nucleus
PORTVERSION=	0.77
PORTREVISION=	4
CATEGORIES=	x11-fonts
MASTER_SITES=	SF/xfonts/OldFiles

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Another font package for X

BUILD_DEPENDS=	bdftopcf:${PORTSDIR}/x11-fonts/bdftopcf
RUN_DEPENDS=	mkfontdir:${PORTSDIR}/x11-fonts/mkfontdir \
		mkfontscale:${PORTSDIR}/x11-fonts/mkfontscale

WRKSRC=		${WRKDIR}/${PORTNAME}

FONTDIR=	${PREFIX}/lib/X11/fonts/${PORTNAME}
PLIST_SUB=	FONTDIR="${FONTDIR:S|${PREFIX}/||}"

do-build:
	@cd ${WRKSRC}/src && ./compile

do-install:
	@${MKDIR} ${STAGEDIR}${FONTDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}/*.gz ${STAGEDIR}${FONTDIR}

.include <bsd.port.mk>
