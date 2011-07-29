# New ports collection makefile for:	hunspell
# Date created:		2011-07-20
# Whom:			Baptiste Daroussin <bapt@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	hunspell
PORTVERSION=	20110701
PORTREVISION=	1
CATEGORIES=	russian textproc
MASTER_SITES=	GOOGLE_CODE
DISTNAME=	ru_RU_UTF8

MAINTAINER=	office@FreeBSD.org
COMMENT=	Hunspell russian dictionary

USE_ZIP=	yes
NO_BUILD=	yes
PROJECTHOST=	hunspell-ru

PLIST_FILES=	%%DATADIR%%/ru_RU.aff \
		%%DATADIR%%/ru_RU.dic
PLIST_DIRSTRY=	%%DATADIR%%

do-install:
	${MKDIR} ${DATADIR}/
	${INSTALL_DATA} ${WRKDIR}/ru_RU.aff ${WRKDIR}/ru_RU.dic ${DATADIR}/

.include <bsd.port.mk>
