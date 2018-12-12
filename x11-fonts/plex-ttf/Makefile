# $FreeBSD$

PORTNAME=	plex-ttf
DISTVERSION=	1.2.2
CATEGORIES=	x11-fonts
MASTER_SITES=	https://github.com/IBM/plex/releases/download/v${DISTVERSION}/TrueType${EXTRACT_SUFX}?dummy=/

MAINTAINER=	tobik@FreeBSD.org
COMMENT=	IBM's signature typeface

LICENSE=	OFL11
LICENSE_FILE=	${WRKSRC}/TrueType/IBM-Plex-Mono/license.txt

USES=		fonts zip
NO_ARCH=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

do-install:
	@${MKDIR} ${STAGEDIR}${FONTSDIR}
	cd ${WRKSRC}/TrueType && ${INSTALL_DATA} IBM-Plex-Devanagri/*.ttf \
		IBM-Plex-Mono/*.ttf IBM-Plex-Sans/*.ttf IBM-Plex-Sans-Condensed/*.ttf \
		IBM-Plex-Sans-Hebrew/*.ttf IBM-Plex-Serif/*.ttf \
		IBM-Plex-Thai/*.ttf ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
