# Created by: archfan <mail_me@riseup.net>
# $FreeBSD$

PORTNAME=	gtk-arc-themes
PORTVERSION=	20160605
CATEGORIES=	x11-themes

MAINTAINER=	mail_me@riseup.net
COMMENT=	Arc-themes for GTK-2.0 and GTK-3.0 based desktop environments

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	gtk-murrine-engine>0:x11-themes/gtk-murrine-engine \
		gnome-themes-standard>0:x11-themes/gnome-themes-standard
RUN_DEPENDS=	gtk-murrine-engine>0:x11-themes/gtk-murrine-engine \
		gnome-themes-standard>0:x11-themes/gnome-themes-standard

USE_GITHUB=	yes
GH_ACCOUNT=	horst3180
GH_PROJECT=	arc-theme
GH_TAGNAME=	e10fefb

USES=		autoreconf pkgconfig
GNU_CONFIGURE=	yes
USE_GNOME=	gtk20 gtk30
NO_ARCH=	yes

.include <bsd.port.mk>
