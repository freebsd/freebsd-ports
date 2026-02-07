PORTNAME=	mojave-gtk-themes
DISTVERSION=	2024-11-15
CATEGORIES=	x11-themes

MAINTAINER=	Alexander88207@protonmail.com
COMMENT=	Macos Mojave theme for GTK 3, GTK 2 and Gnome-Shell
WWW=		https://github.com/vinceliuice/Mojave-gtk-theme

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	bash>0:shells/bash \
		sassc>0:textproc/sassc
RUN_DEPENDS=	gtk-engines2>0:x11-themes/gtk-engines2 \
		gtk-murrine-engine>0:x11-themes/gtk-murrine-engine

USES=		shebangfix

USE_GITHUB=	yes
GH_ACCOUNT=	vinceliuice
GH_PROJECT=	Mojave-gtk-theme

SHEBANG_FILES=	${WRKSRC}/src/main/gtk-3.0/make_gresource_xml.sh \
		${WRKSRC}/src/main/gtk-4.0/make_gresource_xml.sh install.sh \
		parse-sass.sh

NO_ARCH=	yes
NO_BUILD=	yes

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/themes
	${WRKSRC}/install.sh -d ${STAGEDIR}${PREFIX}/share/themes -t all

.include <bsd.port.mk>
