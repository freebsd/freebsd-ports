# New ports collection makefile for:	ve-hunspell
# Date created:		2011-07-20
# Whom:			Baptiste Daroussin <bapt@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ve-hunspell
PORTVERSION=	20110323
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_MOZILLA_EXTENDED}
MASTER_SITE_SUBDIR=	addons/46601
DISTNAME=	venda_spell_checker-${PORTVERSION}-tb+fn+fx+sm
EXTRACT_SUFX=	.xpi

MAINTAINER=	office@FreeBSD.org
COMMENT=	Venda hunspell dictionaries

USE_ZIP=	yes
NO_BUILD=	yes

PLIST_FILES=	share/hunspell/ve.aff \
		share/hunspell/ve.dic
PLIST_DIRS=	share/hunspell

do-install:
	@${MKDIR} ${PREFIX}/share/hunspell
	@${INSTALL_DATA} ${WRKDIR}/dictionaries/ve-ZA.aff ${PREFIX}/share/hunspell/ve.aff
	@${INSTALL_DATA} ${WRKDIR}/dictionaries/ve-ZA.dic ${PREFIX}/share/hunspell/ve.dic

.include <bsd.port.mk>
