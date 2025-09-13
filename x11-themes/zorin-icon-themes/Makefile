PORTNAME=	zorin-icon-themes
DISTVERSION=	4.0.5
CATEGORIES=	x11-themes

MAINTAINER=	Alexander88207@protonmail.com
COMMENT=	Zorin OS icon theme
WWW=		https://github.com/ZorinOS/zorin-icon-themes

LICENSE=	CC-BY-SA-4.0
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes

GH_ACCOUNT=	ZorinOS
NO_ARCH=	yes
NO_BUILD=	yes

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/share/icons
	${CP} -R ${WRKSRC}/Zorin* ${STAGEDIR}${PREFIX}/share/icons

.include <bsd.port.mk>
