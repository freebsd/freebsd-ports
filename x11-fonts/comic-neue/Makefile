PORTNAME=	comic-neue
DISTVERSION=	2.51
CATEGORIES=	x11-fonts

MAINTAINER=	0mp@FreeBSD.org
COMMENT=	Free Comic Sans alternative

LICENSE=	OFL11
LICENSE_FILE=	${WRKSRC}/OFL.txt

USES=		fonts

USE_GITHUB=	yes
GH_ACCOUNT=	crozynski
GH_PROJECT=	comicneue

NO_ARCH=	yes
NO_BUILD=	yes

do-install:
	@${MKDIR} ${STAGEDIR}${FONTSDIR}
	cd ${WRKSRC}/Fonts/OTF && ${INSTALL_DATA} ComicNeue-Angular/*.otf ComicNeue/*.otf ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
