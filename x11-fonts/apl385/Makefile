# $FreeBSD$

PORTNAME=	apl385
DISTVERSION=	20191020
CATEGORIES=	x11-fonts
MASTER_SITES=	http://apl385.com/fonts/
DISTNAME=	${PORTNAME}

MAINTAINER=	0mp@FreeBSD.org
COMMENT=	APL385 Unicode monospaced code font

LICENSE=	PD

USES=		fonts zip

FONTNAME=	APL385

NO_ARCH=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

PLIST_FILES=	${FONTSDIR}/Apl385.ttf

do-install:
	@${MKDIR} ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/Apl385.ttf ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
