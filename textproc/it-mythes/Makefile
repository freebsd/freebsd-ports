# New ports collection makefile for:	it-mythes
# Date created:		2011-07-21
# Whom:			Baptiste Daroussin <bapt@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	it-mythes
DISTVERSION=	02_09_l
CATEGORIES=	textproc
MASTER_SITES=	SF/linguistico/Thesaurus%20OOo%202.x.x/${DISTVERSION}_2008_11_29/
DISTNAME=	thesaurus2_it_${DISTVERSION}_2008_11_29

MAINTAINER=	office@FreeBSD.org
COMMENT=	Italian thesaurus

USE_ZIP=	yes
NO_BUILD=	yes

PLIST_FILES=	share/mythes/th_it_IT.dat \
		share/mythes/th_it_IT.idx
PLIST_DIRS=	share/mythes

do-install:
	@${MKDIR} ${PREFIX}/share/mythes
	@${INSTALL_DATA} ${WRKDIR}/th_it_IT.* ${PREFIX}/share/mythes

.include <bsd.port.mk>
