# New ports collection makefile for:	uz-hunspell
# Date created:		2011-07-20
# Whom:			Baptiste Daroussin <bapt@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	uz-hunspell
PORTVERSION=	0.6
CATEGORIES=	textproc
MASTER_SITES=	http://www-user.uni-bremen.de/~kmashrab/uzbek-word-list/
DISTNAME=	uzbek-wordlist-${PORTVERSION}

MAINTAINER=	office@FreeBSD.org
COMMENT=	Uzbek hunspell dictionaries

USE_BZIP2=	yes
WRKSRC=	${WRKDIR}/${DISTNAME}/hunspell
ALL_TARGET=	uz_UZ.dic

PLIST_FILES=	share/hunspell/uz_UZ.dic \
		share/hunspell/uz_UZ.aff

PLIST_DIRS=	share/hunspell

do-install:
	@${MKDIR} ${PREFIX}/share/hunspell
	@${INSTALL_DATA} ${WRKSRC}/uz* ${PREFIX}/share/hunspell

.include <bsd.port.mk>
