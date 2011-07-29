# New ports collection makefile for:	xh-hunspell
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
MASTER_SITE_SUBDIR=	addons/46599
PKGNAMEPREFIX=	xh-
DISTNAME=	xhosa_spell_checker-${PORTVERSION}-tb+fn+fx+sm
EXTRACT_SUFX=	.xpi

MAINTAINER=	office@FreeBSD.org
COMMENT=	Xhosa hunspell dictionaries

USE_ZIP=	yes
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/dictionaries

PLIST_FILES=	%%DATADIR%%/xh.aff \
		%%DATADIR%%/xh.dic
PLIST_DIRSTRY=	%%DATADIR%%

do-install:
	${MKDIR} ${DATADIR}/
	${INSTALL_DATA} ${WRKSRC}/xh-ZA.aff ${DATADIR}/xh.aff
	${INSTALL_DATA} ${WRKSRC}/xh-ZA.dic ${DATADIR}/xh.dic

.include <bsd.port.mk>
