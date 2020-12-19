# Created by: Masaki TAGAWA <masaki@club.kyutech.ac.jp>
# $FreeBSD$

PORTNAME=	sourcecodepro
PORTVERSION=	2.032
CATEGORIES=	x11-fonts
PKGNAMESUFFIX=	-ttf
MASTER_SITES=	https://github.com/adobe-fonts/source-code-pro/releases/download/${PORTVERSION}R-ro%2F1.052R-it%2F1.012R-VAR/
DISTNAME=	TTF-source-code-pro-${PORTVERSION}R-ro-1.052R-it

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Set of fonts by Adobe designed for coders

LICENSE=	OFL11

PORTSCOUT=	skipv:variable-fonts

USES=		fonts zip

NO_ARCH=	yes
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/TTF

FONTNAME=	SourceCodePro
SUB_FILES=	pkg-message

do-install:
	${MKDIR} ${STAGEDIR}${FONTSDIR}/
	${INSTALL_DATA} ${WRKSRC}/*.ttf ${STAGEDIR}${FONTSDIR}/

.include <bsd.port.mk>
