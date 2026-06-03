PORTNAME=	stixfonts
DISTVERSION=	2.13b171
PORTEPOCH=	1
CATEGORIES=	x11-fonts
MASTER_SITES=	https://github.com/stipub/stixfonts/raw/refs/tags/v${DISTVERSION}/zipfiles/
DISTNAME=	STIX2_13-all

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	OpenType Unicode fonts for Scientific, Technical, and Math texts
WWW=		https://www.stixfonts.org/

LICENSE=	OFL11

USES=		fonts

EXTRACT_SUFX=	.zip
EXTRACT_AFTER_ARGS=	--strip-components 1 \
			--exclude *.woff* \
			--exclude *wght* \
			--no-same-owner --no-same-permissions

NO_WRKSUBDIR=	yes
NO_ARCH=	yes
NO_BUILD=	yes

SUB_FILES=	pkg-message

do-install:
	${MKDIR} ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.otf ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.ttf ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
