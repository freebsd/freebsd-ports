# Created by: Olivier Duchateau
# $FreeBSD$

PORTNAME=	greybird
PORTVERSION=	3.22.11
DISTVERSIONPREFIX=	v
CATEGORIES=	x11-themes xfce
PKGNAMESUFFIX=	-theme

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Gtk and xfwm4 themes for the Xfce Desktop

LICENSE=	GPLv2 CC-BY-SA-3.0
LICENSE_COMB=	dual

BUILD_DEPENDS=	sassc:textproc/sassc
RUN_DEPENDS=	gtk-murrine-engine>=0.98.1:x11-themes/gtk-murrine-engine

USES=		gnome meson pkgconfig python:3.5+,build
USE_GNOME=	gdkpixbuf2:build glib20:build librsvg2:build

PORTSCOUT=	limit:^3\.22\.

GH_ACCOUNT=	shimmerproject
GH_PROJECT=	Greybird

USE_GITHUB=	yes
NO_BUILD=	yes

OPTIONS_DEFINE=		NOTIFYD
OPTIONS_DEFAULT=	NOTIFYD
OPTIONS_SUB=		yes

NOTIFYD_DESC=	Install xfce4-notifyd theme

post-patch-NOTIFYD-off:
	${REINPLACE_CMD} -e 's|install_data(xfce_notify_|#install_data(xfce_notify_|g' \
		${WRKSRC}/light/meson.build

.include <bsd.port.mk>
