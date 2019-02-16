# Created by: archfan <mail_me@riseup.net>
# $FreeBSD$

PORTNAME=	gtk-arc-themes
PORTVERSION=	20170302
PORTREVISION=	2
CATEGORIES=	x11-themes

MAINTAINER=	mail_me@riseup.net
COMMENT=	Arc-themes for GTK-2.0 and GTK-3.0 based desktop environments

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	gtk-murrine-engine>0:x11-themes/gtk-murrine-engine \
		gnome-themes-extra>0:x11-themes/gnome-themes-extra
RUN_DEPENDS=	gtk-murrine-engine>0:x11-themes/gtk-murrine-engine \
		gnome-themes-extra>0:x11-themes/gnome-themes-extra

USE_GITHUB=	yes
GH_ACCOUNT=	horst3180
GH_PROJECT=	arc-theme

USES=		autoreconf gnome pkgconfig
GNU_CONFIGURE=	yes
USE_GNOME=	gtk20 gtk30
NO_ARCH=	yes
CONFIGURE_ARGS=	--with-gnome=3.22

.include <bsd.port.mk>
