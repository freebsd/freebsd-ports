PORTNAME=	juliamono
DISTVERSION=	0.055
PORTREVISION=	1
CATEGORIES=	x11-fonts
MASTER_SITES=	https://github.com/cormullion/${PORTNAME}/releases/download/v${DISTVERSION}/
DISTNAME=	JuliaMono-ttf
DIST_SUBDIR=	${PORTNAME}/${DISTVERSION}

MAINTAINER=	trueos@norwegianrockcat.com
COMMENT=	Monospaced typeface with many Unicode characters
WWW=		https://juliamono.netlify.app/

LICENSE=	OFL11

USES=		fonts zip

NO_ARCH=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

do-install:
	@${MKDIR} ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.ttf ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
