# Created by: Tobias Kortkamp <t@tobik.me>
# $FreeBSD$

PORTNAME=	terminus-ttf
PORTVERSION=	4.39
CATEGORIES=	x11-fonts
MASTER_SITES=	http://files.ax86.net/terminus-ttf/files/${PORTVERSION}/

MAINTAINER=	t@tobik.me
COMMENT=	Terminus Font - a clean fixed width font (TTF version)

LICENSE=	OFL11
LICENSE_FILE=	${WRKSRC}/COPYING

NO_ARCH=	yes
NO_BUILD=	yes
USE_XORG=	x11
USES=		fonts zip

FONTNAME=	TerminusTTF
SUB_FILES=	pkg-message

do-install:
	${MKDIR} ${STAGEDIR}${FONTSDIR}/
	${INSTALL_DATA} ${WRKSRC}/*.ttf ${STAGEDIR}${FONTSDIR}/

.include <bsd.port.mk>
