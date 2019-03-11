# $FreeBSD$

PORTNAME=	font-tex-gyre-schola-math
DISTVERSION=	1.533
PORTREVISION=	1
CATEGORIES=	x11-fonts
MASTER_SITES=	http://www.gust.org.pl/projects/e-foundry/tg-math/download/
DISTNAME=	${PORTNAME:S/font-//:S/-//:S/-//}-${DISTVERSION:S/.//}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Math companion for the TeX Gyre Schola family

LICENSE=	GFL
LICENSE_NAME=	GUST Font License
LICENSE_FILE=	${WRKSRC}/doc/GUST-FONT-LICENSE.txt
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USES=		fonts zip
NO_BUILD=	yes
NO_ARCH=	yes
FONTNAME=	OTF

PLIST_FILES=	${FONTSDIR}/${PORTNAME:S/font-//:S/-//:S/-//}.otf

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/fonts/OTF
	${INSTALL_DATA} ${WRKSRC}/opentype/* ${STAGEDIR}${PREFIX}/share/fonts/OTF

.include <bsd.port.mk>
