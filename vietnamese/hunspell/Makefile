# New ports collection makefile for:	hunspell
# Date created:		2011-07-20
# Whom:			Baptiste Daroussin <bapt@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	hunspell
PORTVERSION=	20080604
CATEGORIES=	vietnamese textproc
MASTER_SITES=	GOOGLE_CODE
DISTNAME=	vi_VN

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	Hunspell vietnamese dictionnary

PROJECTHOST=	hunspell-spellcheck-vi
USE_ZIP=	yes
NO_BUILD=	yes

PLIST_FILES=	share/hunspell/vi_VN.aff \
		share/hunspell/vi_VN.dic
PLIST_DIRS=	share/hunspell

do-install:
		@${MKDIR} ${PREFIX}/share/hunspell
		@${INSTALL_DATA} ${WRKDIR}/vi_VN.aff \
			${WRKDIR}/vi_VN.dic \
			${PREFIX}/share/hunspell/

.include <bsd.port.mk>
