# New ports collection makefile for:	artwiz-aleczapka-de
# Date created:			2004-08-28
# Whom:				Herbert J. Skuhra <herbert.skuhra@gmx.at>
#
# $FreeBSD$

PORTNAME=		artwiz-aleczapka-se
PORTVERSION=		1.3
CATEGORIES=		x11-fonts
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	artwizaleczapka

MAINTAINER=	herbert.skuhra@gmx.at
COMMENT=	A set of (improved) artwiz fonts

NO_BUILD=	yes
USE_BZIP2=	yes
USE_X_PREFIX=	yes
PKGMESSAGE=	${WRKDIR}/pkg-message

FONTS=	anorexia.se aqui.se cure.se drift.se edges.se fkp.se gelly.se \
	glisp-bold.se glisp.se kates.se lime.se mints-mild.se \
	mints-strong.se nu.se smoothansi.se snap.se
FONTDIR=	${X11BASE}/lib/X11/fonts/${PORTNAME}/
FILES=	${FONTS:S,$,.pcf,} ${WRKSRC}/fonts.alias ${WRKSRC}/fonts.dir

.include <bsd.port.pre.mk>

do-install:
	@${MKDIR} ${FONTDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${FILES} ${FONTDIR}

post-install:
	@${SED} 's|$${X11BASE}|${X11BASE}|g' \
		${PKGDIR}/pkg-message >${PKGMESSAGE}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
