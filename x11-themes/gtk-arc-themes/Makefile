PORTNAME=	gtk-arc-themes
DISTVERSION=	20220223
PORTREVISION=	2
CATEGORIES=	x11-themes
MASTER_SITES=	https://github.com/jnsh/arc-theme/releases/download/${DISTVERSION}/
DISTNAME=	arc-theme-${DISTVERSION}

MAINTAINER=	Alexander88207@protonmail.com
COMMENT=	Arc-themes for GTK-2.0,3.0 & 4.0 based desktop environments
WWW=		https://github.com/jnsh/arc-theme

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	sassc:textproc/sassc
RUN_DEPENDS=	gtk-murrine-engine>0:x11-themes/gtk-murrine-engine

USES=		gnome meson python:build shebangfix tar:xz

USE_GNOME=	gtk20 gtk30 gtk40

MESON_ARGS=	-Dcinnamon_version=4.8 \
		-Dgnome_shell_version=41.4 \
		-Dthemes=cinnamon,gnome-shell,gtk2,gtk3,gtk4,metacity,plank,xfwm

SHEBANG_FILES=	meson/install-file.py

NO_ARCH=	yes

.include <bsd.port.mk>
