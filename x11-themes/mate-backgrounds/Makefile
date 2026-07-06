PORTNAME=	mate-backgrounds
DISTVERSION=	1.28.0
PORTREVISION=	1
CATEGORIES=	x11-themes graphics mate
MASTER_SITES=	https://github.com/mate-desktop/${PORTNAME}/releases/download/v${DISTVERSION}/
DIST_SUBDIR=	mate

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Collection of backgrounds for MATE
WWW=		https://mate-desktop.org/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gettext gmake gnome pathfix tar:xz
USE_GNOME=	glib20 intlhack
PORTSCOUT=	site:https://github.com/mate-desktop/mate-backgrounds/releases/ limitw:1,even
GNU_CONFIGURE=	yes

.include <bsd.port.mk>
