PORTNAME=	mate-backgrounds
DISTVERSION=	1.28.0
PORTREVISION=	1
CATEGORIES=	x11-themes graphics mate
MASTER_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/releases/download/v${DISTVERSION}/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Collection of backgrounds for MATE
WWW=		https://mate-desktop.org/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gettext gmake gnome pathfix tar:xz
USE_GITHUB=	nodefault
GH_ACCOUNT=	mate-desktop
USE_GNOME=	glib20 intlhack
PORTSCOUT=	site:https://github.com/mate-desktop/mate-backgrounds/releases/ limitw:1,even
GNU_CONFIGURE=	yes

.include <bsd.port.mk>
