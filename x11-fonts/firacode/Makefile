# Created by: Dave Cottlehuber <dch@skunkwerks.at>

PORTNAME=	firacode
DISTVERSIONPREFIX=	v
DISTVERSION=	6.2
CATEGORIES=	x11-fonts
MASTER_SITES=	https://github.com/tonsky/FiraCode/releases/download/${DISTVERSION}/
DISTNAME=	Fira_Code_${DISTVERSIONPREFIX}${PORTVERSION}

MAINTAINER=	dch@FreeBSD.org
COMMENT=	Monospaced font with programming ligatures derived from Fira

LICENSE=	OFL11

USES=		fonts zip
NO_ARCH=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

do-install:
	@${MKDIR} ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/ttf/*.ttf \
		${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
