PORTNAME=	padauk
PORTVERSION=	2.8
PORTREVISION=	2
CATEGORIES=	x11-fonts
MASTER_SITES=	https://software.sil.org/downloads/r/padauk/

MAINTAINER=	buganini@gmail.com
COMMENT=	Unicode font supporting all the Myanmar characters
WWW=		https://scripts.sil.org/Padauk

LICENSE=	OFL11

NO_BUILD=	yes
USES=		fonts zip
WRKSRC=		${WRKDIR}/${DISTNAME}0

do-install:
	@${MKDIR} ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.ttf ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
