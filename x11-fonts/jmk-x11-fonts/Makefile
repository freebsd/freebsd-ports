PORTNAME=	jmk-x11-fonts
PORTVERSION=	3.0
PORTREVISION=	6
CATEGORIES=	x11-fonts
MASTER_SITES=	http://nikolas.us.to/jmkfonts/

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Jim Knoble's font package for X

BUILD_DEPENDS=	bdftopcf:x11-fonts/bdftopcf \
		mkfontscale>=0:x11-fonts/mkfontscale

USES=		fonts imake

do-install:
	@${MKDIR} ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.pcf.gz ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
