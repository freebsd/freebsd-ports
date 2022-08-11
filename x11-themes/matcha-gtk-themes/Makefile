PORTNAME=	matcha-gtk-themes
DISTVERSION=	2021-11-29
CATEGORIES=	x11-themes

MAINTAINER=	Alexander88207@protonmail.com
COMMENT=	Flat design theme for GTK 3, GTK 2, and Gnome-Shell

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	bash>0:shells/bash
RUN_DEPENDS=	gtk-engines2>0:x11-themes/gtk-engines2 \
		gtk-murrine-engine>0:x11-themes/gtk-murrine-engine

USES=		shebangfix
USE_GITHUB=	yes
GH_ACCOUNT=	vinceliuice
GH_PROJECT=	Matcha-gtk-theme
SHEBANG_FILES=	install.sh
NO_ARCH=	yes
NO_BUILD=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|cp -ur|cp -pr|g' ${WRKSRC}/install.sh

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/themes
	${WRKSRC}/install.sh -d ${STAGEDIR}${PREFIX}/share/themes

.include <bsd.port.mk>
