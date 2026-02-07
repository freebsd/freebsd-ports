PORTNAME=	layan-gtk-themes
DISTVERSION=	2023-05-23
CATEGORIES=	x11-themes

MAINTAINER=	Alexander88207@protonmail.com
COMMENT=	Flat Design theme for GTK 3, GTK 2 and Gnome-Shell
WWW=		https://github.com/vinceliuice/Layan-gtk-theme

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	bash>0:shells/bash \
		coreutils>0:sysutils/coreutils
RUN_DEPENDS=	gtk-engines2>0:x11-themes/gtk-engines2 \
		gtk-murrine-engine>0:x11-themes/gtk-murrine-engine

USES=		shebangfix

USE_GITHUB=	yes
GH_ACCOUNT=	vinceliuice
GH_PROJECT=	Layan-gtk-theme

SHEBANG_FILES=	install.sh

NO_ARCH=	yes
NO_BUILD=	yes

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/themes
	${WRKSRC}/install.sh -d ${STAGEDIR}${PREFIX}/share/themes

.include <bsd.port.mk>
