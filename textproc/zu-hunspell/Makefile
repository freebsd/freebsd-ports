# New ports collection makefile for:	zu-hunspell
# Date created:		2011-07-20
# Whom:			Baptiste Daroussin <bapt@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	zu-hunspell
PORTVERSION=	20110323
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_MOZILLA_EXTENDED}
MASTER_SITE_SUBDIR=	addons/46490
DISTNAME=	zulu_spell_checker-${PORTVERSION}-tb+fn+fx+sm
EXTRACT_SUFX=	.xpi

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	Zulu hunspell dictionaries

USE_ZIP=	yes
NO_BUILD=	yes

PLIST_FILES=	share/hunspell/zu.aff \
		share/hunspell/zu.dic
PLIST_DIRS=	share/hunspell

do-install:
	@${MKDIR} ${PREFIX}/share/hunspell
	@${INSTALL_DATA} ${WRKDIR}/dictionaries/zu-ZA.aff ${PREFIX}/share/hunspell/zu.aff
	@${INSTALL_DATA} ${WRKDIR}/dictionaries/zu-ZA.dic ${PREFIX}/share/hunspell/zu.dic

.include <bsd.port.mk>
