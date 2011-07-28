# New ports collection makefile for:	ro-hunspell
# Date created:		2011-07-21
# Whom:			Baptiste Daroussin <bapt@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ro-hunspell
PORTVERSION=	3.3.6
CATEGORIES=	textproc
MASTER_SITES=	SF/rospell/Romanian%20dictionaries/dict-${PORTVERSION}/
DISTNAME=	ro_RO.${PORTVERSION}

MAINTAINER=	office@FreeBSD.org
COMMENT=	Romanian hunspell dictionaries

LICENSE=	LGPL21 GPLv2 MPL
LICENSE_COMB=	dual

USE_ZIP=	yes
NO_BUILD=	yes

PLIST_FILES=	share/hunspell/ro_RO.aff \
		share/hunspell/ro_RO.dic
PLIST_DIRS=	share/hunspell

do-install:
	@${MKDIR} ${PREFIX}/share/hunspell
	@${INSTALL_DATA} ${WRKDIR}/ro_RO.* ${PREFIX}/share/hunspell

.include <bsd.port.mk>
