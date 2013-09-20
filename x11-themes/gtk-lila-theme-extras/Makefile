# Created by: Filippo Natali <filippo@widestore.net>
# $FreeBSD$

PORTNAME=	gtk-lila-theme-extras
PORTVERSION=	0.4.5
PORTREVISION=	7
CATEGORIES=	x11-themes gnome
MASTER_SITES=	SF/lila-theme/lila-gtk-extras/${PORTVERSION}
DISTNAME=	lila-gtk-extras-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GTK+ 2.0 Lila additional themes

WRKSRC=		${WRKDIR}/lila-gtk-extras
NO_BUILD=	yes

USE_BZIP2=	yes
USE_GNOME=	gtk20

NO_STAGE=	yes
.SILENT:

do-install:
	${MKDIR} ${PREFIX}/share/themes
	(cd ${WRKSRC} && ${COPYTREE_SHARE} . ${PREFIX}/share/themes)

.include <bsd.port.mk>
