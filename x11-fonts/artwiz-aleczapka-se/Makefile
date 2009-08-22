# New ports collection makefile for:	artwiz-aleczapka-de
# Date created:			2004-08-28
# Whom:				Herbert J. Skuhra <herbert.skuhra@gmx.at>
#
# $FreeBSD$

PORTNAME=		artwiz-aleczapka-se
PORTVERSION=		1.3
PORTREVISION=	2
CATEGORIES=		x11-fonts
MASTER_SITES=		SF/artwizaleczapka/iso-8859-1/${PORTVERSION}

MAINTAINER=	herbert.skuhra@gmx.at
COMMENT=	A set of (improved) artwiz fonts

NO_BUILD=	yes
USE_BZIP2=	yes
PKGMESSAGE=	${WRKDIR}/pkg-message

FONTS=	anorexia.se aqui.se cure.se drift.se edges.se fkp.se gelly.se \
	glisp-bold.se glisp.se kates.se lime.se mints-mild.se \
	mints-strong.se nu.se smoothansi.se snap.se
FONTDIR=	${LOCALBASE}/lib/X11/fonts/${PORTNAME}/
FILES=	${FONTS:S,$,.pcf,} ${WRKSRC}/fonts.alias ${WRKSRC}/fonts.dir

.include <bsd.port.pre.mk>

do-install:
	@${MKDIR} ${FONTDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${FILES} ${FONTDIR}

post-install:
	@${SED} 's|$${LOCALBASE}|${LOCALBASE}|g' \
		${PKGDIR}/pkg-message >${PKGMESSAGE}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
