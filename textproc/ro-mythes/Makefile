# New ports collection makefile for:	ro-mythes
# Date created:		2011-07-21
# Whom:			Baptiste Daroussin <bapt@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ro-mythes
PORTVERSION=	3.3
CATEGORIES=	textproc
MASTER_SITES=	SF/rospell/Romanian%20dictionaries/dict-${PORTVERSION}/
DISTNAME=	th_ro_RO.${PORTVERSION}

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	Romanian thesaurus

LICENSE=	GPLv2

USE_ZIP=	yes
NO_BUILD=	yes

PLIST_FILES=	share/mythes/th_ro_RO.dat \
		share/mythes/th_ro_RO.idx
PLIST_DIRS=	share/mythes

do-install:
	@${MKDIR} ${PREFIX}/share/mythes
	@${INSTALL_DATA} ${WRKDIR}/th_ro_RO.* ${PREFIX}/share/mythes

.include <bsd.port.mk>
