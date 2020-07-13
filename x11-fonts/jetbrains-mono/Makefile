# $FreeBSD$

PORTNAME=	jetbrains-mono
PORTVERSION=	2.001
PORTEPOCH=	1
CATEGORIES=	x11-fonts
MASTER_SITES=	https://github.com/JetBrains/JetBrainsMono/releases/download/v${PORTVERSION}/
DISTNAME=	JetBrains.Mono.${DISTVERSION}

MAINTAINER=	lwhsu@FreeBSD.org
COMMENT=	Free and open source typeface for developers

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		fonts zip

WRKSRC=	"${WRKDIR}/JetBrains Mono ${PORTVERSION}"

NO_ARCH=	yes
NO_BUILD=	yes

do-install:
	@${MKDIR} ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/ttf/*.ttf ${STAGEDIR}${FONTSDIR}
	${LS} ${STAGEDIR}${FONTSDIR}/*.ttf | ${SED} -e's,^${STAGEDIR},,' >> ${TMPPLIST}

.include <bsd.port.mk>
