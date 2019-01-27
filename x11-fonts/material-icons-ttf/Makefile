# $FreeBSD$

PORTNAME=	material-icons
DISTVERSION=	4.0.4
CATEGORIES=	x11-fonts
PKGNAMESUFFIX=	-ttf

MAINTAINER=	voidanix@420blaze.it
COMMENT=	Material Design icon set from Google

LICENSE=	CC-BY-4.0
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=	fonts

NO_ARCH=	yes
NO_BUILD=	yes

PLIST_FILES=	${FONTSDIR}/MaterialIcons-Regular.ttf

USE_GITHUB=	yes
GH_ACCOUNT=	jossef
GH_PROJECT=	material-design-icons-iconfont

do-install:
	@${MKDIR} ${STAGEDIR}${FONTSDIR}/
	${INSTALL_DATA} ${WRKSRC}/dist/fonts/*.ttf ${STAGEDIR}${FONTSDIR}/

.include <bsd.port.mk>
