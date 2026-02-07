PORTNAME=	plex-ttf
DISTVERSION=	6.4.0
CATEGORIES=	x11-fonts
MASTER_SITES=	https://github.com/IBM/plex/releases/download/v${DISTVERSION}/
DISTNAME=	TrueType
DIST_SUBDIR=	fonts/${PORTNAME}/${DISTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	IBM's signature typeface
WWW=		https://github.com/IBM/plex

LICENSE=	OFL11
LICENSE_FILE=	${WRKSRC}/license.txt

USES=		fonts
NO_ARCH=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

EXTRACT_SUFX=	.zip
EXTRACT_AFTER_ARGS=	--strip-components 2 \
			--no-same-owner --no-same-permissions

do-install:
	@${MKDIR} ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.ttf ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/hinted/*.ttf ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
