# New ports collection makefile for:	sl-mythes
# Date created:		2011-07-21
# Whom:			Baptiste Daroussin <bapt@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	sl-mythes
PORTVERSION=	2011.07.24
CATEGORIES=	textproc
MASTER_SITES=	http://193.2.66.133:85/download/
DISTNAME=	thes_sl_SI_v2

MAINTAINER=	office@FreeBSD.org
COMMENT=	Slovenian thesaurus

LICENSE=	LGPL21

USE_ZIP=	yes
NO_BUILD=	yes

PLIST_FILES=	share/mythes/th_sl_SI_v2.dat \
		share/mythes/th_sl_SI_v2.idx
PLIST_DIRS=	share/mythes

do-install:
	@${MKDIR} ${PREFIX}/share/mythes
	@${INSTALL_DATA} ${WRKDIR}/th_sl_SI_v2.* ${PREFIX}/share/mythes

.include <bsd.port.mk>
