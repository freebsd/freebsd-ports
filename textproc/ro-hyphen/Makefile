# New ports collection makefile for:	ro-hyphen
# Date created:		2011-07-21
# Whom:			Baptiste Daroussin <bapt@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ro-hyphen
PORTVERSION=	3.3.6
CATEGORIES=	textproc
MASTER_SITES=	SF/rospell/Romanian%20dictionaries/dict-${PORTVERSION}/
DISTNAME=	hyph_ro_RO.${PORTVERSION}

MAINTAINER=	office@FreeBSD.org
COMMENT=	Romanian hyphenation rules

LICENSE=	LGPL21 GPLv2 MPL
LICENSE_COMB=	dual

USE_ZIP=	yes
NO_BUILD=	yes

PLIST_FILES=	share/hyphen/hyph_ro_RO.dic
PLIST_DIRS=	share/hyphen

do-install:
	@${MKDIR} ${PREFIX}/share/hyphen
	@${INSTALL_DATA} ${WRKDIR}/hyph_ro_RO.* ${PREFIX}/share/hyphen

.include <bsd.port.mk>
