# New ports collection makefile for:	tk-hunspell
# Date created:		2011-07-20
# Whom:			Baptiste Daroussin <bapt@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	tk-hunspell
PORTVERSION=	0.01
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_MOZILLA_EXTENDED}
MASTER_SITE_SUBDIR=	addons/204314
DISTNAME=	turkmen_spell_checker-${PORTVERSION}-fx+tb+sm
EXTRACT_SUFX=	.xpi

MAINTAINER=	office@FreeBSD.org
COMMENT=	Turkmen hunspell dictionaries

USE_ZIP=	yes
NO_BUILD=	yes

PLIST_FILES=	share/hunspell/tk.aff \
		share/hunspell/tk.dic
PLIST_DIRS=	share/hunspell

do-install:
	@${MKDIR} ${PREFIX}/share/hunspell
	@${INSTALL_DATA} ${WRKDIR}/dictionaries/tk* ${PREFIX}/share/hunspell/

.include <bsd.port.mk>
