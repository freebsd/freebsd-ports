# $FreeBSD$

PORTNAME=	plex-ttf
DISTVERSION=	1.0.2
CATEGORIES=	x11-fonts
MASTER_SITES=	https://github.com/IBM/plex/releases/download/v${DISTVERSION}/TrueType${EXTRACT_SUFX}?dummy=/

MAINTAINER=	tobik@FreeBSD.org
COMMENT=	IBM's signature typeface

LICENSE=	OFL11
LICENSE_FILE=	${WRKSRC}/TrueType/LICENSE.txt

USES=		fonts zip
NO_ARCH=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

do-install:
	@${MKDIR} ${STAGEDIR}${FONTSDIR}
	cd ${WRKSRC}/TrueType && ${INSTALL_DATA} IBM-Plex-Mono/* IBM-Plex-Sans/* \
		IBM-Plex-Sans-Condensed/* IBM-Plex-Serif/* ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
