# New ports collection makefile for:	tn-hunspell
# Date created:		2011-07-20
# Whom:			Baptiste Daroussin <bapt@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	tn-hunspell
PORTVERSION=	20110323
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_MOZILLA_EXTENDED}
MASTER_SITE_SUBDIR=	addons/46617
DISTNAME=	tswana_spell_checker-${PORTVERSION}-tb+sm+fx+fn
EXTRACT_SUFX=	.xpi

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	Tswana hunspell dictionaries

USE_ZIP=	yes
NO_BUILD=	yes

PLIST_FILES=	share/hunspell/tn_ZA.aff \
		share/hunspell/tn_ZA.dic \
		share/hunspell/tn_BW.aff \
		share/hunspell/tn_BW.dic
PLIST_DIRS=	share/hunspell

do-install:
	@${MKDIR} ${PREFIX}/share/hunspell
	@${INSTALL_DATA} ${WRKDIR}/dictionaries/tn-ZA.aff ${PREFIX}/share/hunspell/tn_ZA.aff
	@${INSTALL_DATA} ${WRKDIR}/dictionaries/tn-ZA.dic ${PREFIX}/share/hunspell/tn_ZA.dic
	@cd ${PREFIX}/share/hunspell ; \
	${LN} -s tn_ZA.aff tn_BW.aff ; \
	${LN} -s tn_ZA.dic tn_BW.dic

.include <bsd.port.mk>
