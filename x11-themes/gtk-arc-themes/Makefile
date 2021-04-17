# Created by: archfan <mail_me@riseup.net>

PORTNAME=	gtk-arc-themes
DISTVERSION=	20210412
CATEGORIES=	x11-themes

MAINTAINER=	Alexander88207@protonmail.com
COMMENT=	Arc-themes for GTK-2.0 and GTK-3.0 based desktop environments

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	coreutils>0:sysutils/coreutils \
		inkscape:graphics/inkscape \
		sassc:textproc/sassc
RUN_DEPENDS=	gtk-murrine-engine>0:x11-themes/gtk-murrine-engine

USES=		meson gnome

BINARY_ALIAS=	install=ginstall \
		cp=gcp

USE_GITHUB=	yes
GH_ACCOUNT=	jnsh
GH_PROJECT=	arc-theme

USE_GNOME=	gtk20 gtk30
NO_ARCH=	yes

MESON_ARGS=	-Dthemes=cinnamon,gnome-shell,gtk2,gtk3,metacity,plank,unity,xfwm \
		-Dcinnamon_version=4.8 \
		-Dgnome_shell_version=3.38 \
    		-Dgtk3_version=3.24
# Speed up build in Poudriere.  It calls inkscape a bazillion times
# and each instance tries to connect to 127.0.0.1:9090 which seems
# to be because of gtk3's broadway backend.  Disable all GDK backends.
MAKE_ENV=	GDK_BACKEND=""

.include <bsd.port.mk>
