# New ports collection makefile for:	mythes
# Date created:		2011-07-21
# Whom:			Baptiste Daroussin <bapt@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mythes
PORTVERSION=	2007.06.13
CATEGORIES=	russian textproc
MASTER_SITES=	http://download.i-rs.ru/pub/openoffice/dict/
DISTNAME=	thes_ru_RU_v2

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	Russian thesaurus

LICENSE=	LGPL21

USE_ZIP=	yes
NO_BUILD=	yes

PLIST_FILES=	share/mythes/th_ru_RU_v2.dat \
		share/mythes/th_ru_RU_v2.idx \
		share/mythes/th_ru_UA_v2.dat \
		share/mythes/th_ru_UA_v2.idx

PLIST_DIRS=	share/mythes

do-install:
		@${MKDIR} ${PREFIX}/share/mythes
		@${INSTALL_DATA} ${WRKDIR}/th_ru_RU_v2.* ${PREFIX}/share/mythes
		@cd ${PREFIX}/share/mythes; \
		${LN} -s th_ru_RU_v2.dat th_ru_UA_v2.dat; \
		${LN} -s th_ru_RU_v2.idx th_ru_UA_v2.idx

.include <bsd.port.mk>
