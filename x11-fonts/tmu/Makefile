# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	tmu
DISTVERSION=	1.901b
CATEGORIES=	x11-fonts
MASTER_SITES=	CENKES
# http://www.thdl.org/tools/fonts/index.html

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Free Tibetan Machine Uni font

BUILD_DEPENDS=	mkfontscale:${PORTSDIR}/x11-fonts/mkfontscale	\
		mkfontdir:${PORTSDIR}/x11-fonts/mkfontdir	\
		fc-cache:${PORTSDIR}/x11-fonts/fontconfig

USES=		tar:bzip2
PLIST_SUB=	FONTSDIR="${FONTSDIR:S|${PREFIX}/||}"
FONTNAME=	${PORTNAME}
FONTSDIR?=	${PREFIX}/lib/X11/fonts/${FONTNAME}
NO_BUILD=	yes

post-extract:
	@cd ${WRKSRC}/&&${MV} TibMachUni-${DISTVERSION}.ttf tmu.ttf

do-install:
	@${INSTALL} -d ${STAGEDIR}${FONTSDIR}/
	@${INSTALL_DATA} ${WRKSRC}/tmu.ttf ${STAGEDIR}${FONTSDIR}/

.include <bsd.port.mk>
