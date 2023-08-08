PORTNAME=	chomsky
PORTVERSION=	2.3
DISTVERSIONPREFIX=	v
CATEGORIES=	x11-fonts

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	New York Times masthead, reimagined as a full font
WWW=		https://github.com/ctrlcctrlv/chomsky

LICENSE=	OFL11
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		fonts
USE_GITHUB=	yes
GH_ACCOUNT=	ctrlcctrlv

NO_ARCH=	yes
NO_BUILD=	yes

PLIST_FILES=	${FONTSDIR}/Chomsky.otf

do-install:
	${MKDIR} ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/dist/*.otf ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
