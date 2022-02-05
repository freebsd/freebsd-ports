PORTNAME=	materialdesign
DISTVERSIONPREFIX=	v
DISTVERSION=	6.5.95
CATEGORIES=	x11-fonts
PKGNAMESUFFIX=	-ttf

MAINTAINER=	cs@FreeBSD.org
COMMENT=	Material Design Webfont

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=	fonts

NO_ARCH=	yes
NO_BUILD=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	Templarian
GH_PROJECT=	MaterialDesign-Webfont

PORTSCOUT=	skipv:variable-fonts

FONTNAME=	MaterialDesign-Webfont

do-install:
	${MKDIR} ${STAGEDIR}${FONTSDIR}/
	${INSTALL_DATA} ${WRKSRC}/fonts/*.ttf ${STAGEDIR}${FONTSDIR}/

.include <bsd.port.mk>
