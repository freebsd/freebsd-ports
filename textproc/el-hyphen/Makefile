# New ports collection makefile for:	el-hyphen
# Date created:		2011-07-21
# Whom:			Baptiste Daroussin <bapt@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	el-hyphen
PORTVERSION=	2005.10.17
CATEGORIES=	textproc
MASTER_SITES=	http://ftp.osuosl.org/pub/openoffice/contrib/dictionaries/
DISTNAME=	hyph_el_GR

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	Greek hyphenation rules

LICENSE=	LGPL21

USE_ZIP=	yes
NO_BUILD=	yes

PLIST_FILES=	share/hyphen/hyph_el_GR.dic \
		share/hyphen/hyph_el_CY.dic

PLIST_DIRS=	share/hyphen

do-install:
	@${MKDIR} ${PREFIX}/share/hyphen
	@${INSTALL_DATA} ${WRKDIR}/hyph_el_GR.dic ${PREFIX}/share/hyphen
	@cd ${PREFIX}/share/hyphen; \
	${LN} -s hyph_el_GR.dic hyph_el_CY.dic

.include <bsd.port.mk>
