# New ports collection makefile for:	hyphen
# Date created:		2011-07-21
# Whom:			Baptiste Daroussin <bapt@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	hyphen
PORTVERSION=	2004.04.15
PORTREVISION=	1
CATEGORIES=	russian textproc
MASTER_SITES=	http://ftp.osuosl.org/pub/openoffice/contrib/dictionaries/
DISTNAME=	hyph_ru_RU

MAINTAINER=	office@FreeBSD.org
COMMENT=	Russian hyphenation rules

LICENSE=	LGPL21

USE_ZIP=	yes
NO_BUILD=	yes

PLIST_FILES=	%%DATADIR%%/hyph_ru_RU.dic \
		%%DATADIR%%/hyph_ru_UA.dic
PLIST_DIRSTRY=	%%DATADIR%%

do-install:
	${MKDIR} ${DATADIR}/
	${INSTALL_DATA} ${WRKDIR}/hyph_ru_RU.dic ${DATADIR}/
	${LN} -s hyph_ru_RU.dic ${DATADIR}/hyph_ru_UA.dic

.include <bsd.port.mk>
