# New ports collection makefile for:	da-hyphen
# Date created:		2011-07-21
# Whom:			Baptiste Daroussin <bapt@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	da-hyphen
PORTVERSION=	2007.09.30
CATEGORIES=	textproc
MASTER_SITES=	http://ftp.osuosl.org/pub/openoffice/contrib/dictionaries/
DISTNAME=	hyph_da_DK

MAINTAINER=	office@FreeBSD.org
COMMENT=	Danish hyphenation rules

LICENSE=	LGPL21

USE_ZIP=	yes
NO_BUILD=	yes

PLIST_FILES=	share/hyphen/hyph_da_DK.dic
PLIST_DIRS=	share/hyphen

do-install:
	@${MKDIR} ${PREFIX}/share/hyphen
	@${INSTALL_DATA} ${WRKDIR}/hyph_da_DK.dic ${PREFIX}/share/hyphen

.include <bsd.port.mk>
