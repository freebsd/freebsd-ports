# New ports collection makefile for:	hunspell
# Date created:		2011-07-20
# Whom:			Baptiste Daroussin <bapt@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	hunspell
PORTVERSION=	2.4.2007.09.01
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	SF/linguistico/Dizionario%20italiano%20per%20OOo/${PORTVERSION:S/./_/g}/
PKGNAMEPREFIX=	it-
DISTNAME=	italiano_${PORTVERSION:S/./_/g}

MAINTAINER=	office@FreeBSD.org
COMMENT=	Italian hunspell dictionaries

LICENSE=	GPLv3

USE_ZIP=	yes
NO_BUILD=	yes

PLIST_FILES=	%%DATADIR%%/it_IT.aff \
		%%DATADIR%%/it_IT.dic
PLIST_DIRSTRY=	%%DATADIR%%

do-install:
	${MKDIR} ${DATADIR}/
	${INSTALL_DATA} ${WRKDIR}/it_IT.aff ${WRKDIR}/it_IT.dic ${DATADIR}/

.include <bsd.port.mk>
