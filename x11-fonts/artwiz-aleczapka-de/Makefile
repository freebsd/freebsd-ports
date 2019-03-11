# Created by: Herbert J. Skuhra <herbert.skuhra@gmx.at>
# $FreeBSD$

PORTNAME=	artwiz-aleczapka-de
PORTVERSION=	1.3
PORTREVISION=	4
CATEGORIES=	x11-fonts
MASTER_SITES=	SF/artwizaleczapka/iso-8859-1/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Set of (improved) artwiz fonts

NO_BUILD=	yes
NO_ARCH=	yes
USES=		fonts tar:bzip2
SUB_FILES=	pkg-message

FONTS=	anorexia.de aqui.de cure.de drift.de edges.de fkp.de gelly.de \
	glisp-bold.de glisp.de kates.de lime.de mints-mild.de \
	mints-strong.de nu.de smoothansi.de snap.de
FILES=	${FONTS:S,$,.pcf,} ${WRKSRC}/fonts.alias

do-install:
	${MKDIR} ${STAGEDIR}${FONTSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${FILES} ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
