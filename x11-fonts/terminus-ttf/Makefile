PORTNAME=	terminus-ttf
PORTVERSION=	4.49.3
CATEGORIES=	x11-fonts
MASTER_SITES=	https://files.ax86.net/terminus-ttf/files/${PORTVERSION}/

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Terminus Font - a clean fixed width font (TTF version)
WWW=		https://files.ax86.net/terminus-ttf/

LICENSE=	OFL11
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		fonts zip

FONTNAME=	TerminusTTF
NO_ARCH=	yes
NO_BUILD=	yes

SUB_FILES=	pkg-message
PLIST_SUB=	PORTVERSION=${PORTVERSION}

do-install:
	${MKDIR} ${STAGEDIR}${FONTSDIR}/
	${INSTALL_DATA} ${WRKSRC}/*.ttf ${STAGEDIR}${FONTSDIR}/

.include <bsd.port.mk>
