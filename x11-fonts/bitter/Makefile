PORTNAME=	bitter
DISTVERSIONPREFIX=	v.
DISTVERSION=	2.110
PORTEPOCH=	1
CATEGORIES=	x11-fonts

MAINTAINER=	rakuco@FreeBSD.org
COMMENT=	Contemporary serif typeface for text designed for comfortably reading

LICENSE=	OFL11

USES=		fonts
USE_GITHUB=	yes
GH_ACCOUNT=	solmatas
GH_PROJECT=	Bitter

NO_ARCH=	yes
NO_BUILD=	yes

do-install:
	${MKDIR} ${STAGEDIR}${FONTSDIR}
	cd ${WRKSRC}/fonts/otf && \
		${INSTALL_DATA} *.otf ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
