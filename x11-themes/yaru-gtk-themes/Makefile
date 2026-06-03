PORTNAME=	yaru-gtk-themes
DISTVERSION=	25.10.3
CATEGORIES=	x11-themes

MAINTAINER=	Alexander88207@protonmail.com
COMMENT=	Default GTK theme for Ubuntu
WWW=		https://github.com/ubuntu/yaru

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	bash:shells/bash \
		coreutils>0:sysutils/coreutils \
		sassc:textproc/sassc

USES=		gnome meson pkgconfig python shebangfix
USE_GITHUB=	yes
GH_ACCOUNT=	ubuntu
GH_PROJECT=	yaru
USE_GNOME=	glib20:build

SHEBANG_FILES=	cinnamon-shell/src/post_install.py \
		common/colorize-dummy-svg.py \
		gnome-shell/gresources-xml-parser.py \
		gtk/src/post_install.py \
		metacity/src/post_install.py
SHEBANG_LANG=	${PYTHON_CMD}

MESON_ARGS=	-Dcinnamon-dark=true \
		-Dcinnamon-shell=true \
		-Dcinnamon=true \
		-Dicons=false \
		-Dmate-dark=true \
		-Dmate=true \
		-Dsessions=false \
		-Dsounds=false \
		-Dxfwm4=true

BINARY_ALIAS=	realpath=grealpath cp=gcp mv=gmv
NO_ARCH=	yes

.include <bsd.port.mk>
