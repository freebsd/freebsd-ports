PORTNAME=	steps-mono
DISTVERSION=	0.3-29
DISTVERSIONSUFFIX=	-gc090a79
CATEGORIES=	x11-fonts

MAINTAINER=	0mp@FreeBSD.org
COMMENT=	Monospace font created for the French magazine Etapes

LICENSE=	OFL11
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		fonts
USE_GITHUB=	yes
GH_ACCOUNT=	raphaelbastide

NO_ARCH=	yes
NO_BUILD=	yes

PLIST_FILES=	${FONTSDIR}/Steps-Mono-Thin.otf \
		${FONTSDIR}/Steps-Mono.otf

do-install:
	@${MKDIR} ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/fonts/*.otf ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
