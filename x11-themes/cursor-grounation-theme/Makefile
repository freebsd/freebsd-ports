# New ports collection makefile for:	cursor-grounation-theme
# Date created:			12 Feb 2006
# Whom:				Babak Farrokhi <babak@farrokhi.net>
#
# $FreeBSD$
#

PORTNAME=	cursor-grounation-theme
PORTVERSION=	0.3
PORTREVISION=	2
CATEGORIES=	x11-themes
MASTER_SITES=	http://www.gnome-look.org/CONTENT/content-files/
DISTNAME=	14484-Grounation-${PORTVERSION}

MAINTAINER=	farrokhi@FreeBSD.org
COMMENT=	Moshi's Grounation cursors

NO_BUILD=	yes
USE_BZIP2=	yes

WRKSRC=		${WRKDIR}/Grounation-${PORTVERSION}

do-install:
	@${MKDIR} ${PREFIX}/lib/X11/icons/grounation/cursors
	cd ${WRKSRC}/Grounation/cursors \
		&& ${INSTALL_DATA} * ${PREFIX}/lib/X11/icons/grounation/cursors

.include <bsd.port.mk>
