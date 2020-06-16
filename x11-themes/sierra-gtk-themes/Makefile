# Created by: Alexander Vereeken <Alexander88207@protonmail.com>
# $FreeBSD$

PORTNAME=	sierra-gtk-themes
DISTVERSION=	2019-12-16
CATEGORIES=	x11-themes

MAINTAINER=	Alexander88207@protonmail.com
COMMENT=	MacOS High Sierra like theme for GTK 3, GTK 2 and Gnome-Shell etc

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	bash>0:shells/bash
RUN_DEPENDS=	gtk-murrine-engine>0:x11-themes/gtk-murrine-engine \
		gtk-engines2>0:x11-themes/gtk-engines2

USES=		shebangfix
SHEBANG_FILES=	install.sh

USE_GITHUB=	yes
GH_ACCOUNT=	vinceliuice
GH_PROJECT=	Sierra-gtk-theme
NO_ARCH=	yes
NO_BUILD=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|cp -ur|cp -pr|g' ${WRKSRC}/install.sh

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/themes
	${WRKSRC}/install.sh -d ${STAGEDIR}${PREFIX}/share/themes

.include <bsd.port.mk>
