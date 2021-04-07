PORTNAME=	linuxlibertine-g
PORTVERSION=	20120116
PORTREVISION=	2
CATEGORIES=	x11-fonts
MASTER_SITES=	http://www.numbertext.org/linux/
DISTNAME=	e7a384790b13c29113e22e596ade9687-LinLibertineG-${PORTVERSION}

MAINTAINER=	office@FreeBSD.org
COMMENT=	Linux Libertine G and Linux Biolinum G fonts

USES=		fonts zip

SUB_FILES=	pkg-message

FONTNAME=	LinLibertineG
NO_BUILD=	yes

WRKSRC=	${WRKDIR}/${FONTNAME}

do-install:
	${MKDIR} ${STAGEDIR}${FONTSDIR}
	cd ${WRKSRC} &&	\
		${INSTALL_DATA} ${WRKSRC}/*.ttf ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
