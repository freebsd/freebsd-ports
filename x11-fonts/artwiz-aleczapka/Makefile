# New ports collection makefile for:	artwiz-aleczapka
# Date created:				2004-04-22
# Whom:			Matt Lancereau <matt@rimasec.net>
#
# $FreeBSD$
#

PORTNAME=		artwiz-aleczapka-en
PORTVERSION=		1.3
CATEGORIES=		x11-fonts
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	artwizaleczapka

MAINTAINER=	matt@bsdfly.org
COMMENT=	A set of (improved) artwiz fonts

NO_BUILD=	yes
USE_BZIP2=	yes
USE_X_PREFIX=	yes
PKGMESSAGE=	${WRKDIR}/pkg-message

FONTS=	anorexia aqui cure cursor drift edges fkp gelly \
	glisp-bold glisp kates lime mints-mild mints-strong \
	nu smoothansi snap
FONTDIR=	${X11BASE}/lib/X11/fonts/${PORTNAME}/
FILES=	${FONTS:S,$,.pcf,} ${WRKSRC}/fonts.alias \
	${WRKSRC}/fonts.cache-1 ${WRKSRC}/fonts.dir

.include <bsd.port.pre.mk>

do-install:
	@${MKDIR} ${FONTDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${FILES} ${FONTDIR}

post-install:
	@${SED} 's|$${X11BASE}|${X11BASE}|g' \
		${PKGDIR}/pkg-message >${PKGMESSAGE}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
