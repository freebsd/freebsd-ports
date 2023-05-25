PORTNAME=	qogir-gtk-themes
DISTVERSION=	2023-05-24
CATEGORIES=	x11-themes

MAINTAINER=	duchateau.olivier@gmail.com
COMMENT=	Qogir is a flat Design theme for GTK
WWW=		https://github.com/vinceliuice/Qogir-theme

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	bash>0:shells/bash \
		sassc>0:textproc/sassc
RUN_DEPENDS=	gtk-murrine-engine>0:x11-themes/gtk-murrine-engine \
		gtk-engines2>0:x11-themes/gtk-engines2 \
		adwaita-icon-theme>0:x11-themes/adwaita-icon-theme

USES=		shebangfix
SHEBANG_FILES=	install.sh

USE_GITHUB=	yes
GH_ACCOUNT=	vinceliuice
GH_PROJECT=	Qogir-theme
NO_ARCH=	yes
NO_BUILD=	yes

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/themes
	${WRKSRC}/install.sh -t all -d ${STAGEDIR}${PREFIX}/share/themes

.include <bsd.port.mk>
