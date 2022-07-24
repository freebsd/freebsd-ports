PORTNAME=	yaru-gtk-themes
DISTVERSION=	22.04.4
CATEGORIES=	x11-themes

MAINTAINER=	Alexander88207@protonmail.com
COMMENT=	Default GTK theme for Ubuntu

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	bash>0:shells/bash \
		coreutils>0:sysutils/coreutils \
		sassc:textproc/sassc
RUN_DEPENDS=	gtk-engines2>0:x11-themes/gtk-engines2 \
		gtk-murrine-engine>0:x11-themes/gtk-murrine-engine

USES=		gnome meson pkgconfig python shebangfix
USE_GNOME=	glib20:build
USE_GITHUB=	yes
GH_ACCOUNT=	ubuntu
GH_PROJECT=	yaru

NO_ARCH=	yes

BINARY_ALIAS=	realpath=grealpath

MESON_ARGS=	-Dcinnamon-dark=true \
		-Dcinnamon-shell=true \
		-Dcinnamon=true \
		-Dicons=false \
		-Dmate-dark=true \
		-Dmate=true \
		-Dsessions=false \
		-Dsounds=false \
		-Dxfwm4=true

SHEBANG_LANG=	${PYTHON_CMD}
SHEBANG_FILES=	cinnamon-shell/src/post_install.py common/colorize-dummy-svg.py \
		gnome-shell/gresources-xml-parser.py gtk/src/post_install.py \
		metacity/src/post_install.py

.include <bsd.port.mk>
