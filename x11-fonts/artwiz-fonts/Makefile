# New ports collection makefile for:	artwiz-fonts
# Date created:				25/08/2002
# Whom:			Dominic Marks <dominic_marks@btinternet.com>
#
# $FreeBSD$
#

PORTNAME=	artwiz-fonts
PORTVERSION=	1.0
CATEGORIES=	x11-fonts
MASTER_SITES=	http://www.xs4all.nl/~hanb/software/fluxbox/
DISTNAME=	${PORTNAME}

MAINTAINER=	dominic_marks@btinternet.com

NO_BUILD=	yes
USE_BZIP2=	yes
USE_REINPLACE=	yes
USE_X_PREFIX=	yes
PKGMESSAGE=	${WRKDIR}/pkg-message
WRKSRC=		${WRKDIR}/fluxbox-${PORTNAME}

FONTS=	anorexia aqui cure cursor drift edges gelly glisp-bold \
	glisp lime mints-mild mints-strong nu snap
FONTDIR=	${X11BASE}/lib/X11/fonts/${PORTNAME}/
FONTEXT=	pcf.gz

.include <bsd.port.pre.mk>

do-install:
	@${MKDIR} ${FONTDIR}
.for FONT in ${FONTS}
	@${INSTALL_DATA} ${WRKSRC}/${FONT}.${FONTEXT} ${FONTDIR}
.endfor
	@${INSTALL_DATA} ${FILESDIR}/fonts.dir ${FONTDIR}

post-install:
	@${SED} 's|$${X11BASE}|${X11BASE}|g' \
		${PKGDIR}/pkg-message >${PKGMESSAGE}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
