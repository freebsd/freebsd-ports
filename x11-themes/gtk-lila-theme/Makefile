# New ports collection makefile for:	gtk-lila-theme
# Date Created:				2 Feb 2005
# Whom:					Filippo Natali <filippo@widestore.net>
#
# $FreeBSD$
#

PORTNAME=	gtk-lila-theme
PORTVERSION=	0.5.4
PORTREVISION=	1
CATEGORIES=	x11-themes gnome
MASTER_SITES=	http://lila-theme.uni.cc/files/tarballs/
DISTNAME=	lila-gtk-${PORTVERSION}

MAINTAINER=	filippo.natali@gmail.com
COMMENT=	GTK+ 2.0 Lila theme

WRKSRC=		${WRKDIR}

USE_X_PREFIX=	yes
NO_BUILD=	yes
USE_GNOME=	gtk20
USE_BZIP2=	yes

do-install:
	@${CP} -R ${WRKDIR}/lila-gtk/GorLila ${X11BASE}/share/themes
	@${CP} -R ${WRKDIR}/lila-gtk/SimpLila ${X11BASE}/share/themes

.include <bsd.port.mk>
