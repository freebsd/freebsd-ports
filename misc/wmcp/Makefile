# New ports collection makefile for:	wmcp
# Date created:			10 February 1999
# Whom:				Jim Mock <jim@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	wmcp
PORTVERSION=	1.2.8
CATEGORIES=	misc windowmaker
MASTER_SITES=	http://soupnazi.org/FreeBSD/ports/distfiles/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A dockable pager for Window Maker

PLIST_FILES=	bin/wmcp
USE_X_PREFIX=	yes
USE_XPM=	yes
ALL_TARGET=	clean wmcp

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wmcp ${PREFIX}/bin

.include <bsd.port.mk>
