# New ports collection makefile for:	ss-hunspell
# Date created:		2011-07-20
# Whom:			Baptiste Daroussin <bapt@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ss-hunspell
PORTVERSION=	20110323
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_MOZILLA_EXTENDED}
MASTER_SITE_SUBDIR=	addons/46614
DISTNAME=	swati_spell_checker-${PORTVERSION}-tb+sm+fx+fn
EXTRACT_SUFX=	.xpi

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	Swati hunspell dictionaries

USE_ZIP=	yes
NO_BUILD=	yes

PLIST_FILES=	share/hunspell/ss_ZA.aff \
		share/hunspell/ss_ZA.dic
PLIST_DIRS=	share/hunspell

do-install:
	@${MKDIR} ${PREFIX}/share/hunspell
	@${INSTALL_DATA} ${WRKDIR}/dictionaries/ss-ZA.aff ${PREFIX}/share/hunspell/ss_ZA.aff
	@${INSTALL_DATA} ${WRKDIR}/dictionaries/ss-ZA.dic ${PREFIX}/share/hunspell/ss_ZA.dic

.include <bsd.port.mk>
