PORTNAME=	montecarlo_fonts
DISTVERSION=	1.0
PORTREVISION=	4
CATEGORIES=	x11-fonts
MASTER_SITES=	http://bok.net/MonteCarlo/downloads/ \
		http://mirror.4bit.ws/
DISTNAME=	MonteCarlo-PCF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Monospace font
WWW=		https://bok.net/MonteCarlo/

# No specific license mentioned in distfiles or website but the font is
# freely available.
LICENSE=	NONE

USES=		fonts tar:tgz xorg
USE_XORG=	x11
NO_BUILD=	yes

do-install:
	@${MKDIR} ${STAGEDIR}${FONTSDIR}
	@${INSTALL_DATA} ${WRKSRC}/*.pcf ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
