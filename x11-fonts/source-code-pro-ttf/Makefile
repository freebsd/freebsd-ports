PORTNAME=	source-code-pro
PORTVERSION=	2.042
CATEGORIES=	x11-fonts
PKGNAMESUFFIX=	-ttf
MASTER_SITES=	https://github.com/adobe-fonts/source-code-pro/releases/download/${PORTVERSION}R-u%2F1.062R-i%2F1.026R-vf/
DISTNAME=	TTF-source-code-pro-${PORTVERSION}R-u_1.062R-i

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Set of fonts by Adobe designed for coders
WWW=		https://github.com/adobe-fonts/source-code-pro

LICENSE=	OFL11

USES=		fonts zip

NO_ARCH=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

FONTNAME=	SourceCodePro
SUB_FILES=	pkg-message

PORTSCOUT=	skipv:variable-fonts

do-install:
	${MKDIR} ${STAGEDIR}${FONTSDIR}/
	${INSTALL_DATA} ${WRKSRC}/TTF/*.ttf ${STAGEDIR}${FONTSDIR}/

.include <bsd.port.mk>
