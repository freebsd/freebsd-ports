# New ports collection makefile for:	sl-mythes
# Date created:		2011-07-21
# Whom:			Baptiste Daroussin <bapt@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	sl-mythes
PORTVERSION=	2011.07.27
CATEGORIES=	textproc
MASTER_SITES=	http://193.2.66.133:85/download/
DISTNAME=	thes_sl_SI_v2

MAINTAINER=	office@FreeBSD.org
COMMENT=	Slovenian thesaurus

LICENSE=	LGPL21

USE_ZIP=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

PLIST_FILES=	share/mythes/th_sl_SI_v2.dat \
		share/mythes/th_sl_SI_v2.idx
PLIST_DIRSTRY=	share/mythes

do-install:
	${MKDIR} ${PREFIX}/share/mythes/
	${INSTALL_DATA} ${WRKSRC}/th_sl_SI_v2.dat ${WRKSRC}/th_sl_SI_v2.idx ${PREFIX}/share/mythes/

.include <bsd.port.mk>
