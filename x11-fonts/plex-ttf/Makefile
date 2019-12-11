# $FreeBSD$

PORTNAME=	plex-ttf
DISTVERSION=	4.0.2
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
	${FIND} ${WRKSRC} -name *.ttf -type f \
		-exec ${INSTALL_DATA} {} ${STAGEDIR}${FONTSDIR} \;

.include <bsd.port.mk>
