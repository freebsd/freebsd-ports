PORTNAME=	gtk-gray-theme
PORTVERSION=	1.7
PORTREVISION=	8
CATEGORIES=	x11-themes gnome
MASTER_SITES=	https://BSDforge.com/projects/source/x11-themes/gtk-gray-theme/
DISTNAME=	34132-Gray

MAINTAINER=	portmaster@BSDforge.com
COMMENT=	Gray theme for GTK 2.0
WWW=		http://www.gnome-look.org/content/show.php?content=34132

BROKEN=		Unfetchable

RUN_DEPENDS=	icons-tango>0:x11-themes/icons-tango

NO_BUILD=	yes
USES=		gnome
USE_GNOME=	gtk20

do-install:
	cd ${WRKDIR} && ${COPYTREE_SHARE} "Gray Gray-Flat" ${STAGEDIR}${PREFIX}/share/themes

.include <bsd.port.mk>
