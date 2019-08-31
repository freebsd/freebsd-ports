# $FreeBSD$

PORTNAME=	noto
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	x11-fonts
MASTER_SITES=	https://noto-website-2.storage.googleapis.com/pkgs/
DISTNAME=	Noto-hinted
PKGNAMESUFFIX=	-jp

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Google Noto Fonts family (Japanese)

LICENSE=	OFL11
LICENSE_FILE=	${WRKSRC}/LICENSE_OFL.txt

USES=		fonts zip

EXTRACT_AFTER_ARGS=	-d ${EXTRACT_WRKDIR} '*CJKjp*.otf'
NO_ARCH=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

do-install:
	${MKDIR} ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/*CJKjp*.otf ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
