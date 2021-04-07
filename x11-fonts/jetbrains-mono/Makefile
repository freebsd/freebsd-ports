PORTNAME=	jetbrains-mono
PORTVERSION=	2.225
PORTEPOCH=	1
CATEGORIES=	x11-fonts
MASTER_SITES=	https://github.com/JetBrains/JetBrainsMono/releases/download/v${PORTVERSION}/
DISTNAME=	JetBrainsMono-${DISTVERSION}

MAINTAINER=	lwhsu@FreeBSD.org
COMMENT=	Free and open source typeface for developers

LICENSE=	OFL11
LICENSE_FILE=	${WRKSRC}/OFL.txt

USES=		fonts zip

NO_ARCH=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

do-install:
	@${MKDIR} ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/fonts/ttf/*.ttf ${STAGEDIR}${FONTSDIR}
	${LS} ${STAGEDIR}${FONTSDIR}/*.ttf | ${SED} -e's,^${STAGEDIR},,' >> ${TMPPLIST}

.include <bsd.port.mk>
