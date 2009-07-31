# New ports collection makefile for:	gtk-lila-theme
# Date Created:				2 Feb 2005
# Whom:					Filippo Natali <filippo@widestore.net>
#
# $FreeBSD$
#

PORTNAME=	gtk-lila-theme
PORTVERSION=	0.5.5
PORTREVISION=	4
CATEGORIES=	x11-themes gnome
MASTER_SITES=	http://lila-theme.uni.cc/files/tarballs/
DISTNAME=	lila-gtk-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GTK+ 2.0 Lila theme

WRKSRC=		${WRKDIR}

NO_BUILD=	yes
USE_GNOME=	gtk20
USE_BZIP2=	yes

do-install:
	@${MKDIR} ${PREFIX}/share/themes
	@${CP} -R ${WRKDIR}/lila-gtk/GorLila ${PREFIX}/share/themes
	@${CP} -R ${WRKDIR}/lila-gtk/SimpLila ${PREFIX}/share/themes

.include <bsd.port.mk>
