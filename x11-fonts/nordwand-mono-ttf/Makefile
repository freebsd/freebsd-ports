PORTNAME=	nordwand-mono-ttf
DISTVERSION=	1.3.3
CATEGORIES=	x11-fonts
MASTER_SITES=	https://github.com/tywr/Nordwand-Mono/releases/download/${DISTVERSION}/
DISTNAME=	NordwandMono-TTF
DIST_SUBDIR=	fonts/${PORTNAME}/${DISTVERSION}

MAINTAINER=	mail@vchimishuk.org
COMMENT=	Compact monospace neo-grotesque font designed for developers
WWW=		https://github.com/tywr/Nordwand-Mono

LICENSE=	OFL11

USES=		fonts zip

FONTNAME=	NorwandMono
NO_ARCH=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

do-install:
	${MKDIR} ${STAGEDIR}${FONTSDIR}/
	${INSTALL_DATA} ${WRKSRC}/*.ttf ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
