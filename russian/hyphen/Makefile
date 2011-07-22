# New ports collection makefile for:	hyphen
# Date created:		2011-07-21
# Whom:			Baptiste Daroussin <bapt@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	hyphen
PORTVERSION=	2004.04.15
CATEGORIES=	russian textproc
MASTER_SITES=	http://ftp.osuosl.org/pub/openoffice/contrib/dictionaries/
DISTNAME=	hyph_ru_RU

MAINTAINER=	office@FreeBSD.org
COMMENT=	Russian hyphenation rules

LICENSE=	LGPL21

USE_ZIP=	yes
NO_BUILD=	yes

PLIST_FILES=	share/hyphen/hyph_ru_RU.dic \
		share/hyphen/hyph_ru_UA.dic
PLIST_DIRS=	share/hyphen

do-install:
	@${MKDIR} ${PREFIX}/share/hyphen
	@${INSTALL_DATA} ${WRKDIR}/hyph_ru_RU.dic ${PREFIX}/share/hyphen
	@cd ${PREFIX}/share/hyphen; ${LN} -s hyph_ru_RU.dic hyph_ru_UA.dic

.include <bsd.port.mk>
