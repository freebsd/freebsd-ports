# New ports collection makefile for:	lt-hyphen
# Date created:		2011-07-21
# Whom:			Baptiste Daroussin <bapt@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	lt-hyphen
PORTVERSION=	2004.04.15
CATEGORIES=	textproc
MASTER_SITES=	http://ftp.osuosl.org/pub/openoffice/contrib/dictionaries/
DISTNAME=	hyph_lt_LT

MAINTAINER=	office@FreeBSD.org
COMMENT=	Lithuanian hyphenation rules

LICENSE=	LGPL21

USE_ZIP=	yes
NO_BUILD=	yes

PLIST_FILES=	share/hyphen/hyph_lt_LT.dic
PLIST_DIRS=	share/hyphen

do-install:
	@${MKDIR} ${PREFIX}/share/hyphen
	@${INSTALL_DATA} ${WRKDIR}/hyph_lt_LT.dic ${PREFIX}/share/hyphen

.include <bsd.port.mk>
