PORTNAME=	yaru-icon-theme
DISTVERSION=	22.04.4
CATEGORIES=	x11-themes

MAINTAINER=	Alexander88207@protonmail.com
COMMENT=	Default icon theme for Ubuntu

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	bash>0:shells/bash \
		coreutils>0:sysutils/coreutils \
		sassc:textproc/sassc

USES=		gnome meson ninja python shebangfix
USE_GNOME=	glib20:build
USE_GITHUB=	yes
GH_ACCOUNT=	ubuntu
GH_PROJECT=	yaru

NO_ARCH=	yes

BINARY_ALIAS=	realpath=grealpath

MESON_ARGS=	-Dgnome-shell=false \
		-Dgtk=false \
		-Dgtksourceview=false \
		-Dmetacity=false \
		-Dsessions=false \
		-Dsounds=false

SHEBANG_LANG=	${PYTHON_CMD}
SHEBANG_FILES=	icons/meson/post_install.py icons/src/generate-index-theme.py

.include <bsd.port.mk>
