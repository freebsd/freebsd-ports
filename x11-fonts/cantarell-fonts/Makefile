# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cantarell-fonts
PORTVERSION=	0.101
PORTREVISION=	1
CATEGORIES=	x11-fonts gnome
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Cantarell, a Humanist sans-serif font family

LICENSE=	OFL11
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	appstream-util:devel/appstream-glib
LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig

USES=		gettext-tools fonts meson tar:xz
FONTSDIR=	share/fonts/cantarell
NO_ARCH=	yes

.include <bsd.port.mk>
