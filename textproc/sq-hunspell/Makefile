# New ports collection makefile for:	sq-hunspell
# Date created:		2011-07-20
# Whom:			Baptiste Daroussin <bapt@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	sq-hunspell
PORTVERSION=	1.6.2
CATEGORIES=	textproc
MASTER_SITES=	http://www.shkenca.org/shkarkime/
DISTNAME=	myspell-sq_AL-${PORTVERSION}

MAINTAINER=	office@FreeBSD.org
COMMENT=	Albanian hunspell dictionaries

USE_ZIP=	yes
NO_BUILD=	yes

PLIST_FILES=	share/hunspell/sq_AL.aff \
		share/hunspell/sq_AL.dic
PLIST_DIRS=	share/hunspell

do-install:
	@${MKDIR} ${PREFIX}/share/hunspell
	@${INSTALL_DATA} ${WRKSRC}/sq_AL.* ${PREFIX}/share/hunspell

.include <bsd.port.mk>
