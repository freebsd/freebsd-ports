# $FreeBSD$

PORTNAME=	jetbrains-mono
PORTVERSION=	1.0.6
PORTEPOCH=	1
CATEGORIES=	x11-fonts
MASTER_SITES=	https://github.com/JetBrains/JetBrainsMono/releases/download/v${PORTVERSION}/
DISTNAME=	JetBrainsMono-${DISTVERSION}

MAINTAINER=	lwhsu@FreeBSD.org
COMMENT=	Free and open source typeface for developers

LICENSE=	APACHE20

USES=		fonts zip

WRKSRC=	${WRKDIR}/JetBrainsMono-${PORTVERSION}

NO_ARCH=	yes
NO_BUILD=	yes

do-install:
	@${MKDIR} ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/ttf/*.ttf ${STAGEDIR}${FONTSDIR}
	${LS} ${STAGEDIR}${FONTSDIR}/*.ttf | ${SED} -e's,^${STAGEDIR},,' >> ${TMPPLIST}

.include <bsd.port.mk>
