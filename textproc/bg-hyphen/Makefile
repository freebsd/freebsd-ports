# New ports collection makefile for:	bg-hyphen
# Date created:		2011-07-21
# Whom:			Baptiste Daroussin <bapt@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	bg-hyphen
PORTVERSION=	4.3
CATEGORIES=	textproc
MASTER_SITES=	SF/bgoffice/OpenOffice.org%20Hyphenation%20BG/${PORTVERSION}/
DISTNAME=	OOo-hyph-bg-${PORTVERSION}

MAINTAINER=	office@FreeBSD.org
COMMENT=	Bulgarian hyphenation rules

LICENSE=	GPLv2 LGPL21 MPL
LICENSE_COMB=	dual

USE_ZIP=	yes
NO_BUILD=	yes

PLIST_FILES=	share/hyphen/hyph_bg_BG.dic
PLIST_DIRS=	share/hyphen

do-install:
	@${MKDIR} ${PREFIX}/share/hyphen/
	@${INSTALL_DATA} ${WRKSRC}/hyph_bg_BG.dic ${PREFIX}/share/hyphen

.include <bsd.port.mk>
