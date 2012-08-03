# New ports collection makefile for:	cursor-jimmac-theme
# Date created:			17 July 2005
# Whom:				Piotr Smyrak <smyru@heron.pl>
#
# $FreeBSD$
#

PORTNAME=	cursor-jimmac-theme
PORTVERSION=	0.1
PORTREVISION=	2
CATEGORIES=	x11-themes
MASTER_SITES=	http://www.gnome-look.org/CONTENT/content-files/
DISTNAME=	6550-Jimmac

MAINTAINER=	smyru@heron.pl
COMMENT=	The beautiful Jimmac X cursor themes

NO_BUILD=	yes

WRKSRC=		${WRKDIR}/Jimmac

do-install:
	@${MKDIR} ${PREFIX}/lib/X11/icons/Jimmac/cursors
	cd ${WRKSRC}/jimmac/cursors \
		&& ${INSTALL_DATA} * ${PREFIX}/lib/X11/icons/Jimmac/cursors

.include <bsd.port.mk>
