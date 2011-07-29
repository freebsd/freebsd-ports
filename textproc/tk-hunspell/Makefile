# New ports collection makefile for:	tk-hunspell
# Date created:		2011-07-20
# Whom:			Baptiste Daroussin <bapt@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	hunspell
PORTVERSION=	0.01
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_MOZILLA_EXTENDED}
MASTER_SITE_SUBDIR=	addons/204314
PKGNAMEPREFIX=	tk-
DISTNAME=	turkmen_spell_checker-${PORTVERSION}-fx+tb+sm
EXTRACT_SUFX=	.xpi

MAINTAINER=	office@FreeBSD.org
COMMENT=	Turkmen hunspell dictionaries

USE_ZIP=	yes
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/dictionaries

PLIST_FILES=	%%DATADIR%%/tk.aff \
		%%DATADIR%%/tk.dic
PLIST_DIRSTRY=	%%DATADIR%%

do-install:
	${MKDIR} ${DATADIR}/
	${INSTALL_DATA} ${WRKSRC}/tk.aff ${WRKSRC}/tk.dic ${DATADIR}/

.include <bsd.port.mk>
