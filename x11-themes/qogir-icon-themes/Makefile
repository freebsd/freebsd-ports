PORTNAME=	qogir-icon-themes
DISTVERSION=	2025-02-15
CATEGORIES=	x11-themes

MAINTAINER=	Alexander88207@protonmail.com
COMMENT=	Flat colorful design icon theme for linux desktops
WWW=		https://github.com/vinceliuice/Qogir-icon-theme

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	bash>0:shells/bash \
		gtk-update-icon-cache:graphics/gtk-update-icon-cache

USES=		shebangfix

USE_GITHUB=	yes
GH_ACCOUNT=	vinceliuice
GH_PROJECT=	Qogir-icon-theme
SHEBANG_FILES=	install.sh

NO_ARCH=	yes
NO_BUILD=	yes

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons
	${SETENV} PATH="${PATH}" ${WRKSRC}/install.sh -d ${STAGEDIR}${PREFIX}/share/icons -t default

.include <bsd.port.mk>
