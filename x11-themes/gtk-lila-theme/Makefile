# Created by: Filippo Natali <filippo@widestore.net>
# $FreeBSD$

PORTNAME=	gtk-lila-theme
PORTVERSION=	0.5.5
PORTREVISION=	6
CATEGORIES=	x11-themes gnome
MASTER_SITES=	SF/lila-theme/lila-gtk/${PORTVERSION}
DISTNAME=	lila-gtk-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GTK+ 2.0 Lila theme

WRKSRC=		${WRKDIR}/lila-gtk
NO_BUILD=	yes

USE_BZIP2=	yes
USE_GNOME=	gtk20

NO_STAGE=	yes
.SILENT:

do-install:
	${MKDIR} ${PREFIX}/share/themes
	(cd ${WRKSRC} && ${COPYTREE_SHARE} . ${PREFIX}/share/themes)

.include <bsd.port.mk>
