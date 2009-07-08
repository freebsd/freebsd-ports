# New ports collection makefile for:	c64-bdf
# Date created:				20/02/2008
# Whom:			Marcin Cieslak <saper@SYSTEM.PL>
#
# $FreeBSD$
#

PORTNAME=	c64bdf
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	x11-fonts
MASTER_SITES=	http://beej.us/c64bdf/
DISTNAME=	${PORTNAME}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Commodore 64 X11 fonts

NO_BUILD=	yes

FONTS=	c64 c64d
FONTDIR=	lib/X11/fonts/${PORTNAME}
FILES=	${FONTS:S,$,.bdf,} fonts.dir
PLIST_FILES=	${FILES:S,^,${FONTDIR}/,}
PLIST_DIRS=	${FONTDIR}

.include <bsd.port.pre.mk>

do-install:
	@${MKDIR} ${LOCALBASE}/${FONTDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${FILES} ${LOCALBASE}/${FONTDIR}

.include <bsd.port.post.mk>
