# New ports collection makefile for:	pl-hunspell
# Date created:		2011-07-21
# Whom:			Baptiste Daroussin <bapt@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pl-hunspell
PORTVERSION=	20110721
CATEGORIES=	textproc
MASTER_SITES=	http://sjp.pl/slownik/ort/
DISTNAME=	sjp-myspell-pl-${PORTVERSION}

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	Polish hunspell dictionaries

LICENSE=	LGPL21 GPLv2 MPL
LICENSE_COMB=	dual

USE_ZIP=	yes
NO_BUILD=	yes

PLIST_FILES=	share/hunspell/pl_PL.aff \
		share/hunspell/pl_PL.dic
PLIST_DIRS=	share/hunspell

post-extract:
	@${MKDIR} ${WRKSRC}
	@${EXTRACT_CMD} ${WRKDIR}/pl_PL.zip -d ${WRKSRC}

do-install:
	@${MKDIR} ${PREFIX}/share/hunspell
	@${INSTALL_DATA} ${WRKSRC}/pl_PL.* ${PREFIX}/share/hunspell

.include <bsd.port.mk>
