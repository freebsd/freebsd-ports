# Created by: Dave Cottlehuber <dch@skunkwerks.at>
# $FreeBSD$

PORTNAME=	firacode
DISTVERSION=	1.207
CATEGORIES=	x11-fonts
MASTER_SITES=	https://github.com/tonsky/FiraCode/releases/download/${PORTVERSION}/
DISTNAME=	FiraCode_${PORTVERSION}

MAINTAINER=	dch@FreeBSD.org
COMMENT=	Monospaced font with programming ligatures derived from Fira

LICENSE=	OFL11

USES=		fonts xorg zip
USE_XORG=	x11
NO_ARCH=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

do-install:
	@${MKDIR} ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/otf/*.otf \
		${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
