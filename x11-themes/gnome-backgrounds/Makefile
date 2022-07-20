PORTNAME=	gnome-backgrounds
PORTVERSION=	42.0
CATEGORIES=	x11-themes graphics gnome
MASTER_SITES=	GNOME/sources/${PORTNAME}/${PORTVERSION:C/^([0-9]+)\..*/\1/}
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Collection of backgrounds for GNOME

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

PORTSCOUT=	limitw:1,even

NO_ARCH=	yes
USES=		gettext meson tar:xz

.include <bsd.port.mk>
