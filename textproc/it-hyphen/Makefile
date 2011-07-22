# New ports collection makefile for:	it-hyphen
# Date created:		2011-07-21
# Whom:			Baptiste Daroussin <bapt@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	it-hyphen
PORTVERSION=	2007.11.26
CATEGORIES=	textproc
MASTER_SITES=	http://ftp.osuosl.org/pub/openoffice/contrib/dictionaries/
DISTNAME=	hyph_it_IT

MAINTAINER=	office@FreeBSD.org
COMMENT=	Italian hyphenation rules

LICENSE=	LGPL21

USE_ZIP=	yes
NO_BUILD=	yes

PLIST_FILES=	share/hyphen/hyph_it_IT.dic \
		share/hyphen/hyph_it_CH.dic
PLIST_DIRS=	share/hyphen

do-install:
	@${MKDIR} ${PREFIX}/share/hyphen
	@${INSTALL_DATA} ${WRKDIR}/hyph_it_IT.dic ${PREFIX}/share/hyphen
	@cd ${PREFIX}/share/hyphen; ${LN} -s hyph_it_IT.dic hyph_it_CH.dic

.include <bsd.port.mk>
