PORTNAME=	departure-mono
DISTVERSION=	1.500
CATEGORIES=	x11-fonts
MASTER_SITES=	https://github.com/rektdeckard/departure-mono/releases/download/v${DISTVERSION}/
DISTNAME=	DepartureMono-${DISTVERSION}

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Retro pixel-style monospace font with a lo-fi technical look
WWW=		https://departuremono.com/

LICENSE=	OFL11
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		fonts zip
FONTNAME=	DepartureMono

NO_ARCH=	yes
NO_BUILD=	yes

do-install:
	@${MKDIR} ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.otf ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
