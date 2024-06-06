PORTNAME=	cascadia-code
PORTVERSION=	2404.23
CATEGORIES=	x11-fonts
MASTER_SITES=	https://github.com/microsoft/cascadia-code/releases/download/v${PORTVERSION}/
DISTNAME=	CascadiaCode-${PORTVERSION}
EXTRACT_SUFX=	.zip

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Monospaced font with programming ligatures
WWW=		https://github.com/microsoft/cascadia-code

LICENSE=	OFL11

USES=		fonts

NO_ARCH=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

EXTRACT_AFTER_ARGS=	--include ttf/static \
			--no-same-owner --no-same-permissions

do-install:
	@${MKDIR} ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/ttf/static/*.ttf ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
