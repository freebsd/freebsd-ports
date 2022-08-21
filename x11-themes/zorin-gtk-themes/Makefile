PORTNAME=	zorin-gtk-themes
DISTVERSION=	3.4.4
CATEGORIES=	x11-themes

MAINTAINER=	Alexander88207@protonmail.com
COMMENT=	Zorin OS GTK theme

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes

GH_ACCOUNT=	ZorinOS
GH_PROJECT=	zorin-desktop-themes
NO_ARCH=	yes
NO_BUILD=	yes

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/share/themes
	${CP} -R ${WRKSRC}/Zorin* ${STAGEDIR}${PREFIX}/share/themes

.include <bsd.port.mk>
