# New ports collection makefile for:	hyphen
# Date created:		2011-07-21
# Whom:			Baptiste Daroussin <bapt@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	hyphen
PORTVERSION=	2004.04.15
CATEGORIES=	portuguese textproc
MASTER_SITES=	http://ftp.osuosl.org/pub/openoffice/contrib/dictionaries/
DISTNAME=	hyph_pt_PT

MAINTAINER=	office@FreeBSD.org
COMMENT=	Portuguese hyphenation rules

LICENSE=	LGPL21

USE_ZIP=	yes
NO_BUILD=	yes

PLIST_FILES=	share/hyphen/hyph_pt_PT.dic \
		share/hyphen/hyph_pt_BR.dic
PLIST_DIRS=	share/hyphen

do-install:
	@${MKDIR} ${PREFIX}/share/hyphen
	@${INSTALL_DATA} ${WRKDIR}/hyph_pt_PT.dic ${PREFIX}/share/hyphen
	@cd ${PREFIX}/share/hyphen; ${LN} -s hyph_pt_PT.dic hyph_pt_BR.dic

.include <bsd.port.mk>
