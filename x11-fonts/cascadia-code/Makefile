PORTNAME=	cascadia-code
PORTVERSION=	2105.24
CATEGORIES=	x11-fonts
MASTER_SITES=	https://github.com/microsoft/cascadia-code/releases/download/v${PORTVERSION}/
DISTNAME=	CascadiaCode-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Monospaced font with programming ligatures

LICENSE=	OFL11

USES=		fonts zip

NO_ARCH=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

do-install:
	@${MKDIR} ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/ttf/static/*.ttf ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
