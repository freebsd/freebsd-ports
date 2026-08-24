PORTNAME=	ubuntu-font
DISTVERSION=	0.863
CATEGORIES=	x11-fonts
MASTER_SITES=	https://launchpad.net/ubuntu/+archive/primary/+sourcefiles/fonts-ubuntu/${DISTVERSION}-0ubuntu1/
DISTNAME=	fonts-ubuntu_${DISTVERSION}.orig


MAINTAINER=	0mp@FreeBSD.org
COMMENT=	Ubuntu font family
WWW=		https://design.ubuntu.com/font/

LICENSE=	UFL
LICENSE_FILE=	${WRKSRC}/LICENCE.txt
LICENSE_NAME=	Ubuntu Font License (UFL)
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USES=		fonts

NO_ARCH=	yes
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/fonts-ubuntu-${DISTVERSION}

SUB_FILES=	pkg-message

OPTIONS_DEFINE=	DOCS

do-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.txt ${STAGEDIR}${DOCSDIR}
	@${MKDIR} ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.ttf ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
