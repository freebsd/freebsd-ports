# New ports collection makefile for:	artwiz-fonts
# Date created:				25/08/2002
# Whom:			Dominic Marks <d.marks@student.umist.ac.uk>
#
# $FreeBSD$
#

PORTNAME=	artwiz-fonts
PORTVERSION=	1.0
CATEGORIES=	x11-fonts
MASTER_SITES=	http://www.xs4all.nl/~hanb/software/fluxbox/
DISTNAME=	${PORTNAME}

MAINTAINER=	d.marks@student.umist.ac.uk

NO_BUILD=	yes
USE_BZIP2=	yes
USE_X_PREFIX=	yes
PKGMESSAGE=	${WRKDIR}/pkg-message
WRKSRC=		${WRKDIR}/fluxbox-${PORTNAME}

FONTS=	anorexia aqui cure cursor drift edges gelly glisp-bold \
	glisp lime mints-mild mints-strong nu snap
FONTDIR=	${X11BASE}/lib/X11/fonts/${PORTNAME}/
FILES=	${FONTS:S,$,.pcf.gz,} ${FILESDIR}/fonts.dir

.include <bsd.port.pre.mk>

do-install:
	@${MKDIR} ${FONTDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${FILES} ${FONTDIR}

post-install:
	@${SED} 's|$${X11BASE}|${X11BASE}|g' \
		${PKGDIR}/pkg-message >${PKGMESSAGE}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
