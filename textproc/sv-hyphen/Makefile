# New ports collection makefile for:	sv-hyphen
# Date created:		2011-07-21
# Whom:			Baptiste Daroussin <bapt@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	sv-hyphen
PORTVERSION=	2005.04.15
CATEGORIES=	textproc
MASTER_SITES=	http://ftp.osuosl.org/pub/openoffice/contrib/dictionaries/
DISTNAME=	hyph_sv_SE

MAINTAINER=	office@FreeBSD.org
COMMENT=	Swedish hyphenation rules

LICENSE=	LGPL21

USE_ZIP=	yes
NO_BUILD=	yes

PLIST_FILES=	share/hyphen/hyph_sv_SE.dic \
		share/hyphen/hyph_sv_FI.dic
PLIST_DIRS=	share/hyphen

do-install:
	@${MKDIR} ${PREFIX}/share/hyphen
	@${INSTALL_DATA} ${WRKDIR}/hyph_sv_SE.dic ${PREFIX}/share/hyphen
	@cd ${PREFIX}/share/hyphen; ${LN} -s hyph_sv_SE.dic hyph_sv_FI.dic

.include <bsd.port.mk>
