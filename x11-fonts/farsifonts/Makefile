# Created by: Babak Farrokhi <babak@farrokhi.net>
# $FreeBSD$

PORTNAME=	farsifonts
PORTVERSION=	0.4
PORTREVISION=	4
CATEGORIES=	x11-fonts
MASTER_SITES=	SF/farsi-fonts/

MAINTAINER=	javad.kouhi@gmail.com
COMMENT=	Standard set of Unicode Persian fonts

USES=		fonts zip

NO_BUILD=	yes

do-install:
	@${MKDIR} ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.ttf ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
