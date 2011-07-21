# New ports collection makefile for:	bg-mythes
# Date created:		2011-07-21
# Whom:			Baptiste Daroussin <bapt@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	bg-mythes
PORTVERSION=	4.3
CATEGORIES=	textproc
MASTER_SITES=	SF/bgoffice/OpenOffice.org%20Thesaurus%20BG/${PORTVERSION}/
DISTNAME=	OOo-thes-bg-${PORTVERSION}

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	Bulgarian thesaurus

LICENSE=	GPLv2 LGPL21 MPL
LICENSE_COMB=	dual

USE_ZIP=	yes
NO_BUILD=	yes

PLIST_FILES=	share/mythes/th_bg_BG.dat \
		share/mythes/th_bg_BG.idx

PLIST_DIRS=	share/mythes

do-install:
	@${MKDIR} ${PREFIX}/share/mythes
	@${INSTALL_DATA} ${WRKSRC}/th_bg_BG.* ${PREFIX}/share/mythes

.include <bsd.port.mk>
