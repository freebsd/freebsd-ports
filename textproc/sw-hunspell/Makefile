# New ports collection makefile for:	sw-hunspell
# Date created:		2011-07-20
# Whom:			Baptiste Daroussin <bapt@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	sw-hunspell
PORTVERSION=	1.46
CATEGORIES=	textproc
MASTER_SITES=	GOOGLE_CODE
DISTNAME=	sv-${PORTVERSION}

MAINTAINER=	office@FreeBSD.org
COMMENT=	Swedish hunspell dictionaries

PROJECTHOST=	dsso
USE_ZIP=	yes
NO_BUILD=	yes

PLIST_FILES=	share/hunspell/sv_SE.aff \
		share/hunspell/sv_SE.dic \
		share/hunspell/sv_FI.aff \
		share/hunspell/sv_FI.dic
PLIST_DIRS=	share/hunspell

do-install:
	@${MKDIR} ${PREFIX}/share/hunspell
	@${INSTALL_DATA} ${WRKDIR}/sv_SE* ${PREFIX}/share/hunspell
	@cd ${PREFIX}/share/hunspell; \
	${LN} -s sv_SE.aff sv_FI.aff; \
	${LN} -s sv_SE.dic sv_FI.dic

.include <bsd.port.mk>
