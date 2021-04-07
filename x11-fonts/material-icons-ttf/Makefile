PORTNAME=	material-icons
DISTVERSION=	5.0.1
CATEGORIES=	x11-fonts
PKGNAMESUFFIX=	-ttf

MAINTAINER=	voidanix@420blaze.it
COMMENT=	Material Design icon set from Google

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=	fonts

USE_GITHUB=	yes
GH_ACCOUNT=	jossef
GH_PROJECT=	material-design-icons-iconfont

NO_ARCH=	yes
NO_BUILD=	yes

PLIST_FILES=	${FONTSDIR}/MaterialIcons-Regular.ttf

do-install:
	@${MKDIR} ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/dist/fonts/*.ttf ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
