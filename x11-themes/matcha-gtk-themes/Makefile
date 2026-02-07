PORTNAME=	matcha-gtk-themes
DISTVERSION=	2025-04-11
CATEGORIES=	x11-themes

MAINTAINER=	Alexander88207@protonmail.com
COMMENT=	Flat design theme for GTK based desktop environment
WWW=		https://github.com/vinceliuice/Matcha-gtk-theme

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	bash>0:shells/bash
RUN_DEPENDS=	adwaita-icon-theme>0:x11-themes/adwaita-icon-theme

USES=		shebangfix
USE_GITHUB=	yes
GH_ACCOUNT=	vinceliuice
GH_PROJECT=	Matcha-gtk-theme
SHEBANG_FILES=	install.sh
NO_ARCH=	yes
NO_BUILD=	yes

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/themes
	${WRKSRC}/install.sh -d ${STAGEDIR}${PREFIX}/share/themes

.include <bsd.port.mk>
