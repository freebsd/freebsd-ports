# New ports collection makefile for:	ti-hunspell
# Date created:		2011-07-20
# Whom:			Baptiste Daroussin <bapt@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ti-hunspell
PORTVERSION=	20090911
CATEGORIES=	textproc
MASTER_SITES=	http://www.cs.ru.nl/~biniam/geez/dict/
DISTNAME=	ti_ER

MAINTAINER=	office@FreeBSD.org
COMMENT=	Tigrigna hunspell dictionaries

USE_ZIP=	yes
NO_BUILD=	yes

PLIST_FILES=	share/hunspell/ti_ER.dic \
		share/hunspell/ti_ER.aff \
		share/hunspell/ti_ET.dic \
		share/hunspell/ti_ET.aff
PLIST_DIRS=	share/hunspell

do-install:
	@${MKDIR} ${PREFIX}/share/hunspell
	@${INSTALL_DATA} ${WRKDIR}/ti_ER* ${PREFIX}/share/hunspell
	@cd ${PREFIX}/share/hunspell; \
	${LN} -s ti_ER.aff ti_ET.aff; \
	${LN} -s ti_ER.dic ti_ET.dic

.include <bsd.port.mk>
