PORTNAME=	yaru-icon-theme
DISTVERSION=	25.10.3
CATEGORIES=	x11-themes

MAINTAINER=	Alexander88207@protonmail.com
COMMENT=	Default icon theme for Ubuntu
WWW=		https://github.com/ubuntu/yaru

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	bash:shells/bash \
		coreutils>0:sysutils/coreutils \
		sassc:textproc/sassc

USES=		gnome meson ninja python shebangfix
USE_GITHUB=	yes
GH_ACCOUNT=	ubuntu
GH_PROJECT=	yaru
USE_GNOME=	glib20:build

SHEBANG_FILES=	icons/meson/post_install.py \
		icons/src/generate-index-theme.py
SHEBANG_LANG=	${PYTHON_CMD}

MESON_ARGS=	-Dgnome-shell=false \
		-Dgtk=false \
		-Dgtksourceview=false \
		-Dmetacity=false \
		-Dsessions=false \
		-Dsounds=false

BINARY_ALIAS=	realpath=grealpath
NO_ARCH=	yes

.include <bsd.port.mk>
