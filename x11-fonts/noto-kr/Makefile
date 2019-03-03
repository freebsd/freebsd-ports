# $FreeBSD$

PORTNAME=	noto
PORTVERSION=	1.0
CATEGORIES=	x11-fonts
MASTER_SITES=	https://noto-website.storage.googleapis.com/pkgs/
DISTNAME=	Noto-hinted
DISTFILES=	${DISTNAME}.zip \
		NotoSerifCJKkr-hinted.zip
PKGNAMESUFFIX=	-kr

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Google Noto Fonts family (Korean)

LICENSE=	OFL11
LICENSE_FILE=	${WRKSRC}/LICENSE_OFL.txt

USES=		fonts zip

EXTRACT_AFTER_ARGS=	-d ${EXTRACT_WRKDIR} -x '*.ttf'
NO_ARCH=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

do-install:
	${MKDIR} ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/*CJKkr*.otf ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
