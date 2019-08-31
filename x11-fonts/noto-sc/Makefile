# $FreeBSD$

PORTNAME=	noto
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	x11-fonts
MASTER_SITES=	https://noto-website-2.storage.googleapis.com/pkgs/
DISTNAME=	Noto-hinted
PKGNAMESUFFIX=	-sc

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Google Noto Fonts family (Simplified Chinese)

LICENSE=	OFL11
LICENSE_FILE=	${WRKSRC}/LICENSE_OFL.txt

USES=		fonts zip

EXTRACT_AFTER_ARGS=	-d ${EXTRACT_WRKDIR} '*CJKsc*.otf'
NO_ARCH=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

do-install:
	${MKDIR} ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/*CJKsc*.otf ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
