# $FreeBSD$

PORTNAME=	jetbrains-mono
PORTVERSION=	1.0.0
CATEGORIES=	x11-fonts
MASTER_SITES=	https://download.jetbrains.com/fonts/
DISTNAME=	JetBrainsMono-${DISTVERSION}

MAINTAINER=	lwhsu@FreeBSD.org
COMMENT=	Free and open source typeface for developers

LICENSE=	APACHE20

USES=		fonts zip

NO_ARCH=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

do-install:
	@${MKDIR} ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.ttf ${STAGEDIR}${FONTSDIR}
	${LS} ${STAGEDIR}${FONTSDIR}/*.ttf | ${SED} -e's,^${STAGEDIR},,' >> ${TMPPLIST}

.include <bsd.port.mk>
