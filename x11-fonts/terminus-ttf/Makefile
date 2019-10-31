# Created by: Tobias Kortkamp <t@tobik.me>
# $FreeBSD$

PORTNAME=	terminus-ttf
PORTVERSION=	4.47.0
PORTREVISION=	2
CATEGORIES=	x11-fonts
MASTER_SITES=	http://files.ax86.net/terminus-ttf/files/${PORTVERSION}/

MAINTAINER=	tobik@FreeBSD.org
COMMENT=	Terminus Font - a clean fixed width font (TTF version)

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
