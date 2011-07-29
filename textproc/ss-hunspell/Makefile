# New ports collection makefile for:	ss-hunspell
# Date created:		2011-07-20
# Whom:			Baptiste Daroussin <bapt@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	hunspell
PORTVERSION=	20110323
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_MOZILLA_EXTENDED}
MASTER_SITE_SUBDIR=	addons/46614
PKGNAMEPREFIX=	ss-
DISTNAME=	swati_spell_checker-${PORTVERSION}-tb+sm+fx+fn
EXTRACT_SUFX=	.xpi

MAINTAINER=	office@FreeBSD.org
COMMENT=	Swati hunspell dictionaries

USE_ZIP=	yes
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/dictionaries

PLIST_FILES=	%%DATADIR%%/ss_ZA.aff \
		%%DATADIR%%/ss_ZA.dic
PLIST_DIRSTRY=	%%DATADIR%%

do-install:
	${MKDIR} ${DATADIR}/
	${INSTALL_DATA} ${WRKSRC}/ss-ZA.aff ${DATADIR}/ss_ZA.aff
	${INSTALL_DATA} ${WRKSRC}/ss-ZA.dic ${DATADIR}/ss_ZA.dic

.include <bsd.port.mk>
