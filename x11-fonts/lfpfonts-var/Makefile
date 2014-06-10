# $FreeBSD$

PORTNAME=	lfpfonts-var
PORTVERSION=	0.83
PORTREVISION=	3
CATEGORIES=	x11-fonts
MASTER_SITES=	SF/xfonts/${PORTNAME}/${PORTVERSION}

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Variable width fonts from the Linux Font Project

RUN_DEPENDS=	mkfontdir:${PORTSDIR}/x11-fonts/mkfontdir \
		mkfontscale:${PORTSDIR}/x11-fonts/mkfontscale

WRKSRC=		${WRKDIR}/lfpfonts-var

NO_BUILD=	yes
USES=		tar:bzip2

FONTDIR=	${PREFIX}/lib/X11/fonts/${PORTNAME}
PLIST_SUB=	FONTDIR="${FONTDIR:S|${PREFIX}/||}"

do-install:
	@${MKDIR} ${STAGEDIR}${FONTDIR}
	${INSTALL_DATA} ${WRKSRC}/lfp-var/*.pcf.gz ${STAGEDIR}${FONTDIR}

.include <bsd.port.mk>
