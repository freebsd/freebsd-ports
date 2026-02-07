PORTNAME=	gallant
DISTVERSIONPREFIX=	v
DISTVERSION=	0.1
CATEGORIES=	x11-fonts

MAINTAINER=	schweikh@FreeBSD.org
COMMENT=	Sun Microsystems Gallant font with >4500 Unicode glyphs
WWW=		https://github.com/NanoBillion/gallant

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		fonts
USE_GITHUB=	yes
GH_ACCOUNT=	NanoBillion

NO_ARCH=	yes
NO_BUILD=	yes

PLIST_FILES=	${FONTSDIR}/gallant.pcf.gz

do-install:
	${MKDIR} ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/gallant.pcf.gz \
		${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
