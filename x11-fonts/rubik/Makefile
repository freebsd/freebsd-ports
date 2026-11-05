PORTNAME=	rubik
DISTVERSION=	2.300
CATEGORIES=	x11-fonts

MAINTAINER=	dch@FreeBSD.org
COMMENT=	Sans-serif font family with slightly rounded corners
WWW=		https://fonts.google.com/specimen/Rubik

LICENSE=	OFL11
LICENSE_FILE=	${WRKSRC}/OFL.txt

USES=		fonts
FONTNAME=	Rubik
USE_GITHUB=	yes
GH_ACCOUNT=	googlefonts
GH_TAGNAME=	e337a5f69a9bea30e58d05bd40184d79cc099628

NO_ARCH=	yes
NO_BUILD=	yes

do-install:
	@${MKDIR} ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/fonts/variable/* ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
