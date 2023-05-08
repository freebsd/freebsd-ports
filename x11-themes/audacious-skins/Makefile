PORTNAME=	audacious-skins
PORTVERSION=	1.0.0
CATEGORIES=	x11-themes

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Collection of audacious skins
WWW=		https://github.com/ehaupt/audacious-skins

LICENSE=	GPLv2

USE_GITHUB=	yes
GH_ACCOUNT=	ehaupt

DATADIR=	${PREFIX}/share/audacious

NO_ARCH=	yes
NO_BUILD=	yes

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}/Skins
	${INSTALL_DATA} ${WRKSRC}/Skins/*.wsz ${STAGEDIR}${DATADIR}/Skins

.include <bsd.port.mk>
