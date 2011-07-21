# New ports collection makefile for:	mythes
# Date created:		2011-07-21
# Whom:			Baptiste Daroussin <bapt@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mythes
PORTVERSION=	1.5
CATEGORIES=	polish textproc
MASTER_SITES=	SF/synonimy/synonimy/${PORTVERSION}/
DISTNAME=	OOo2-Thesaurus-${PORTVERSION}

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	Polish thesaurus

LICENSE=	LGPL21

USE_ZIP=	yes
NO_BUILD=	yes

PLIST_FILES=	share/mythes/th_pl_PL_v2.dat \
		share/mythes/th_pl_PL_v2.idx

PLIST_DIRS=	share/mythes

do-install:
	@${MKDIR} ${PREFIX}/share/mythes
	@${INSTALL_DATA} ${WRKDIR}/th_pl_PL_v2.* ${PREFIX}/share/mythes

.include <bsd.port.mk>
