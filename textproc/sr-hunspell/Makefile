# New ports collection makefile for:	sr-hunspell
# Date created:		2011-07-20
# Whom:			Baptiste Daroussin <bapt@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	sr-hunspell
PORTVERSION=	0.18
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_MOZILLA_EXTENDED}
MASTER_SITE_SUBDIR=	addons/10894
DISTNAME=	serbian_dictionary-${PORTVERSION}-fx+tb+sm
EXTRACT_SUFX=	.xpi

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	Serbian hunspell dictionnaries

USE_ZIP=	yes
NO_BUILD=	yes

PLIST_FILES=	share/hunspell/sr_YU.aff \
		share/hunspell/sr_YU.dic \
		share/hunspell/sh_YU.aff \
		share/hunspell/sh_YU.dic

PLIST_DIRS=	share/hunspell

do-install:
	@${MKDIR} ${PREFIX}/share/hunspell
	@${INSTALL_DATA} ${WRKDIR}/dictionaries/sr-RS-Cyrl.aff ${PREFIX}/share/hunspell/sr_YU.aff
	@${INSTALL_DATA} ${WRKDIR}/dictionaries/sr-RS-Cyrl.dic ${PREFIX}/share/hunspell/sr_YU.dic
	@${INSTALL_DATA} ${WRKDIR}/dictionaries/sr-RS-Latn.aff ${PREFIX}/share/hunspell/sh_YU.aff
	@${INSTALL_DATA} ${WRKDIR}/dictionaries/sr-RS-Latn.dic ${PREFIX}/share/hunspell/sh_YU.dic


.include <bsd.port.mk>
