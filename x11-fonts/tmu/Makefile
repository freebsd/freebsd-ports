# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	tmu
DISTVERSION=	1.901b
CATEGORIES=	x11-fonts
MASTER_SITES=	CENKES
# http://www.thdl.org/tools/fonts/index.html

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Free Tibetan Machine Uni font

USES=		fonts tar:bzip2
NO_BUILD=	yes
PLIST_FILES=	${FONTSDIR}/tmu.ttf

post-extract:
	@cd ${WRKSRC}/&&${MV} TibMachUni-${DISTVERSION}.ttf tmu.ttf

do-install:
	@${INSTALL} -d ${STAGEDIR}${FONTSDIR}/
	${INSTALL_DATA} ${WRKSRC}/tmu.ttf ${STAGEDIR}${FONTSDIR}/

.include <bsd.port.mk>
