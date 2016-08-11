# Created by: Dave Cottlehuber <dch@skunkwerks.at>
# $FreeBSD$

PORTNAME=	firacode
PORTVERSION=	1.102
CATEGORIES=	x11-fonts
MASTER_SITES=	https://github.com/tonsky/FiraCode/releases/download/${PORTVERSION}/
DISTNAME=	FiraCode_${PORTVERSION}

MAINTAINER=	dch@skunkwerks.at
COMMENT=	Monospaced font with programming ligatures derived from Fira

LICENSE=	OFL11

USES=		fonts zip
USE_XORG=	x11
NO_ARCH=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

do-install:
	@${MKDIR} ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/FiraCode_${PORTVERSION}/*.otf \
		${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
