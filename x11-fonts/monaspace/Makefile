PORTNAME=	monaspace
DISTVERSION=	1.101
CATEGORIES=	x11-fonts
MASTER_SITES=	https://github.com/githubnext/monaspace/releases/download/v${DISTVERSION}/
DISTNAME=	${PORTNAME}-v${DISTVERSION}

MAINTAINER=	lwhsu@FreeBSD.org
COMMENT=	Innovative superfamily of fonts for code
WWW=		https://monaspace.githubnext.com

LICENSE=	OFL11
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		fonts zip

NO_ARCH=	yes
NO_BUILD=	yes

do-install:
	@${MKDIR} ${STAGEDIR}${FONTSDIR}

	${INSTALL_DATA} ${WRKSRC}/fonts/otf/*.otf ${STAGEDIR}${FONTSDIR}
	${LS} ${STAGEDIR}${FONTSDIR}/*.otf | ${SED} -e's,^${STAGEDIR},,' >> ${TMPPLIST}

	${INSTALL_DATA} ${WRKSRC}/fonts/variable/*.ttf ${STAGEDIR}${FONTSDIR}
	${LS} ${STAGEDIR}${FONTSDIR}/*.ttf | ${SED} -e's,^${STAGEDIR},,' >> ${TMPPLIST}

.include <bsd.port.mk>
