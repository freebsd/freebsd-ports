# New ports collection makefile for:	is-hyphen
# Date created:		2011-07-21
# Whom:			Baptiste Daroussin <bapt@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	is-hyphen
PORTVERSION=	2004.04.15
CATEGORIES=	textproc
MASTER_SITES=	http://ftp.osuosl.org/pub/openoffice/contrib/dictionaries/
DISTNAME=	hyph_is_IS

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	Icelandic hyphenation rules

LICENSE=	LGPL21

USE_ZIP=	yes
NO_BUILD=	yes

PLIST_FILES=	share/hyphen/hyph_is_IS.dic
PLIST_DIRS=	share/hyphen

do-install:
	@${MKDIR} ${PREFIX}/share/hyphen
	@${INSTALL_DATA} ${WRKDIR}/hyph_is_IS.dic ${PREFIX}/share/hyphen

.include <bsd.port.mk>
