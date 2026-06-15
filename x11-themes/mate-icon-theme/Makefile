PORTNAME=	mate-icon-theme
DISTVERSION=	1.28.0
PORTREVISION=	1
CATEGORIES=	x11-themes mate
MASTER_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/releases/download/v${DISTVERSION}/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Collection of icons for the MATE desktop
WWW=		https://mate-desktop.org/

LICENSE=	LGPL3 CC-BY-SA-3.0
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${LOCALBASE}/share/icons/hicolor/index.theme:misc/hicolor-icon-theme \
		icon-naming-utils>=0.8.7:x11-themes/icon-naming-utils
RUN_DEPENDS=	${LOCALBASE}/share/icons/hicolor/index.theme:misc/hicolor-icon-theme

USES=		gettext-tools gmake gnome pkgconfig tar:xz
USE_GITHUB=	nodefault
GH_ACCOUNT=	mate-desktop
USE_GNOME=	intltool
PORTSCOUT=	site:https://github.com/mate-desktop/mate-icon-theme/releases/ limitw:1,even
GNU_CONFIGURE=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
