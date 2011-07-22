# New ports collection makefile for:	hunspell
# Date created:		2011-07-20
# Whom:			Baptiste Daroussin <bapt@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	hunspell
PORTVERSION=	20110701
CATEGORIES=	russian textproc
MASTER_SITES=	GOOGLE_CODE
DISTNAME=	ru_RU_UTF8

MAINTAINER=	office@FreeBSD.org
COMMENT=	Hunspell russian dictionnary

PROJECTHOST=	hunspell-ru
USE_ZIP=	yes
NO_BUILD=	yes

PLIST_FILES=	share/hunspell/ru_RU.aff \
		share/hunspell/ru_RU.dic
PLIST_DIRS=	share/hunspell

do-install:
		@${MKDIR} ${PREFIX}/share/hunspell
		@${INSTALL_DATA} ${WRKDIR}/ru_RU.aff \
			${WRKDIR}/ru_RU.dic \
			${PREFIX}/share/hunspell/

.include <bsd.port.mk>
