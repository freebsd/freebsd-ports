# New ports collection makefile for:	sk-hunspell
# Date created:		2011-07-21
# Whom:			Baptiste Daroussin <bapt@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	hunspell
PORTVERSION=	20110228
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	http://www.sk-spell.sk.cx/files/
PKGNAMEPREFIX=	sk-
DISTNAME=	hunspell-sk-${PORTVERSION}

MAINTAINER=	office@FreeBSD.org
COMMENT=	Slovak hunspell dictionaries

LICENSE=	LGPL21 GPLv2 MPL
LICENSE_COMB=	dual

USE_ZIP=	yes
NO_BUILD=	yes

PLIST_FILES=	%%DATADIR%%/sk_SK.aff \
		%%DATADIR%%/sk_SK.dic
PLIST_DIRSTRY=	%%DATADIR%%

do-install:
	${MKDIR} ${DATADIR}/
	${INSTALL_DATA} ${WRKSRC}/sk_SK.aff ${WRKSRC}/sk_SK.dic ${DATADIR}/

.include <bsd.port.mk>
