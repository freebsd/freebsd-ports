# New ports collection makefile for:	ts-hunspell
# Date created:		2011-07-20
# Whom:			Baptiste Daroussin <bapt@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ts-hunspell
PORTVERSION=	20110323
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_MOZILLA_EXTENDED}
MASTER_SITE_SUBDIR=	addons/46611
DISTNAME=	tsonga_spell_checker-${PORTVERSION}-tb+sm+fx+fn
EXTRACT_SUFX=	.xpi

MAINTAINER=	office@FreeBSD.org
COMMENT=	Tsonga hunspell dictionaries

USE_ZIP=	yes
NO_BUILD=	yes

PLIST_FILES=	share/hunspell/ts_ZA.aff \
		share/hunspell/ts_ZA.dic
PLIST_DIRS=	share/hunspell

do-install:
	@${MKDIR} ${PREFIX}/share/hunspell
	@${INSTALL_DATA} ${WRKDIR}/dictionaries/ts-ZA.aff ${PREFIX}/share/hunspell/ts_ZA.aff
	@${INSTALL_DATA} ${WRKDIR}/dictionaries/ts-ZA.dic ${PREFIX}/share/hunspell/ts_ZA.dic

.include <bsd.port.mk>
