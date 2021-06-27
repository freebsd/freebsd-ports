# Created by: Alexander Vereeken <Alexander88207@protonmail.com>

PORTNAME=	qogir-gtk-themes
DISTVERSION=	2021-06-25
CATEGORIES=	x11-themes

MAINTAINER=	Alexander88207@protonmail.com
COMMENT=	Qogir is a flat Design theme for GTK

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	bash>0:shells/bash
RUN_DEPENDS=	gtk-murrine-engine>0:x11-themes/gtk-murrine-engine \
		gtk-engines2>0:x11-themes/gtk-engines2

USES=		shebangfix
SHEBANG_FILES=	install.sh

USE_GITHUB=	yes
GH_ACCOUNT=	vinceliuice
GH_PROJECT=	Qogir-theme
NO_ARCH=	yes
NO_BUILD=	yes

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/themes
	${WRKSRC}/install.sh -d ${STAGEDIR}${PREFIX}/share/themes

.include <bsd.port.mk>
