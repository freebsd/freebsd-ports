# Created by: Herbert J. Skuhra <herbert.skuhra@gmx.at>
# $FreeBSD$

PORTNAME=	artwiz-aleczapka-se
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

FONTS=	anorexia.se aqui.se cure.se drift.se edges.se fkp.se gelly.se \
	glisp-bold.se glisp.se kates.se lime.se mints-mild.se \
	mints-strong.se nu.se smoothansi.se snap.se
FILES=	${FONTS:S,$,.pcf,} ${WRKSRC}/fonts.alias

do-install:
	${MKDIR} ${STAGEDIR}${FONTSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${FILES} ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
