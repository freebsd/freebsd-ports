PORTNAME=	urw-base35-fonts
DISTVERSION=	20200910
CATEGORIES=	x11-fonts

MAINTAINER=	m.ne@gmx.net
COMMENT=	URW core35 fonts in various formats

LICENSE=	AGPLv3

USES=		fonts
USE_GITHUB=	yes
GH_ACCOUNT=	ArtifexSoftware
GH_PROJECT=	urw-base35-fonts

NO_ARCH=	yes
NO_BUILD=	yes

do-install:
	@${MKDIR} ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/fonts/*.otf ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/fonts/*.ttf ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/fonts/*.afm ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/fonts/*.t1 ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
