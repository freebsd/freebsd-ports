PORTNAME=	comfortaa-ttf
PORTVERSION=	3.001
PORTREVISION=	1
CATEGORIES=	x11-fonts
MASTER_SITES=	https://orig00.deviantart.net/40a3/f/2017/093/d/4/
DISTNAME=	comfortaa___font_by_aajohan-d1qr019

MAINTAINER=	rakuco@FreeBSD.org
COMMENT=	Stylish, modern and free sans-serif true type font

LICENSE=	OFL11
LICENSE_FILE=	${WRKSRC}/OFL.txt

USES=		fonts zip

FONTNAME=	Comfortaa
NO_ARCH=	yes
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${PORTVERSION}

do-install:
	${MKDIR} ${STAGEDIR}${FONTSDIR}/
	cd ${WRKSRC}/ && ${INSTALL_DATA} *.ttf ${STAGEDIR}${FONTSDIR}/

.include <bsd.port.mk>
