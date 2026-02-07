PORTNAME=	geist
PORTVERSION=	1.3.0
CATEGORIES=	x11-fonts
MASTER_SITES=	https://github.com/vercel/geist-font/releases/download/${PORTVERSION}/
PKGNAMESUFFIX=	-sans
DISTNAME=	Geist-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Geist Sans by Vercel
WWW=		https://vercel.com/font \
		https://github.com/vercel/geist-font

LICENSE=	OFL11
LICENSE_FILE=	${WRKSRC}/LICENSE.TXT

USES=		fonts zip

NO_ARCH=	yes
NO_BUILD=	yes

do-install:
	${MKDIR} ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/statics-ttf/*.ttf ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
