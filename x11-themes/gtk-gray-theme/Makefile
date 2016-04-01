# Created by: Babak Farrokhi <babak@farrokhi.net>
# $FreeBSD$

PORTNAME=	gtk-gray-theme
PORTVERSION=	1.7
PORTREVISION=	7
CATEGORIES=	x11-themes gnome
MASTER_SITES=	http://www.gnome-look.org/CONTENT/content-files/
DISTNAME=	34132-Gray

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Gray theme for GTK+ 2.0

RUN_DEPENDS=	icons-tango>0:x11-themes/icons-tango

NO_BUILD=	yes
USE_GNOME=	gtk20

do-install:
	cd ${WRKDIR} && ${COPYTREE_SHARE} "Gray Gray-Flat" ${STAGEDIR}${PREFIX}/share/themes

.include <bsd.port.mk>
