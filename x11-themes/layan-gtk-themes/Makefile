# Created by: Alexander Vereeken <Alexander88207@protonmail.com>

PORTNAME=	layan-gtk-themes
DISTVERSION=	2021-01-12
CATEGORIES=	x11-themes

MAINTAINER=	Alexander88207@protonmail.com
COMMENT=	Layan is a flat Design theme for GTK 3, GTK 2 and Gnome-Shell

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	bash>0:shells/bash
RUN_DEPENDS=	gtk-murrine-engine>0:x11-themes/gtk-murrine-engine \
		gtk-engines2>0:x11-themes/gtk-engines2

USES=		shebangfix
SHEBANG_FILES=	install.sh

USE_GITHUB=	yes
GH_ACCOUNT=	vinceliuice
GH_PROJECT=	Layan-gtk-theme
GH_TAGNAME=	69f4bc4532ef4e81a36bd77d88074a5333575698
NO_ARCH=	yes
NO_BUILD=	yes

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/themes
	${WRKSRC}/install.sh -d ${STAGEDIR}${PREFIX}/share/themes

.include <bsd.port.mk>
