# New ports collection makefile for:	yi-hunspell
# Date created:		2011-07-20
# Whom:			Baptiste Daroussin <bapt@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	yi-hunspell
PORTVERSION=	0.0.2
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_MOZILLA_EXTENDED}
MASTER_SITE_SUBDIR=	addons/222538
DISTNAME=	yiddish_spell_checker__yivo_-${PORTVERSION}-fx+tb+sm+fn
EXTRACT_SUFX=	.xpi

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	Yiddish hunspell dictionaries

USE_ZIP=	yes
NO_BUILD=	yes

PLIST_FILES=	share/hunspell/yi.aff \
		share/hunspell/yi.dic
PLIST_DIRS=	share/hunspell

do-install:
	@${MKDIR} ${PREFIX}/share/hunspell
	@${INSTALL_DATA} ${WRKDIR}/dictionaries/* ${PREFIX}/share/hunspell/

.include <bsd.port.mk>
