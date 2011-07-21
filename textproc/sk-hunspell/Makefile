# New ports collection makefile for:	sk-hunspell
# Date created:		2011-07-21
# Whom:			Baptiste Daroussin <bapt@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	sk-hunspell
PORTVERSION=	20110228
CATEGORIES=	textproc
MASTER_SITES=	http://www.sk-spell.sk.cx/files/
DISTNAME=	hunspell-sk-${PORTVERSION}

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	Slovak hunspell dictionaries

LICENSE=	LGPL21 GPLv2 MPL
LICENSE_COMB=	dual

USE_ZIP=	yes
NO_BUILD=	yes

PLIST_FILES=	share/hunspell/sk_SK.aff \
		share/hunspell/sk_SK.dic
PLIST_DIRS=	share/hunspell

do-install:
	@${MKDIR} ${PREFIX}/share/hunspell
	@${INSTALL_DATA} ${WRKSRC}/sk_SK* ${PREFIX}/share/hunspell

.include <bsd.port.mk>
