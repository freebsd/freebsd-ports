PORTNAME=	zorin-gtk-themes
DISTVERSION=	4.2.2
CATEGORIES=	x11-themes

MAINTAINER=	Alexander88207@protonmail.com
COMMENT=	Zorin OS GTK theme
WWW=		https://github.com/ZorinOS/zorin-desktop-themes

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes

GH_ACCOUNT=	ZorinOS
GH_PROJECT=	zorin-desktop-themes
NO_ARCH=	yes
NO_BUILD=	yes

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/share/themes
	(cd ${WRKSRC} && \
		${COPYTREE_SHARE} "Zorin*" ${STAGEDIR}${PREFIX}/share/themes)

.include <bsd.port.mk>
