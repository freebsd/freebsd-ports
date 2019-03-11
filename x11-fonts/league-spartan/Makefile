# Created by: Florian Limberger <flo@snakeoilproductions.net>
# $FreeBSD$

PORTNAME=	league-spartan
DISTVERSION=	g20140922
PORTREVISION=	1
CATEGORIES=	x11-fonts

MAINTAINER=	flo@snakeoilproductions.net
COMMENT=	Revival of ATF\'s classic Spartan

LICENSE=	OFL11
LICENSE_FILE=	${WRKSRC}/ofl.markdown

USES=		fonts
USE_GITHUB=	yes
GH_ACCOUNT=	theleagueof
GH_TAGNAME=	c350408b

NO_ARCH=	yes
NO_BUILD=	yes

PLIST_FILES=	${FONTSDIR}/LeagueSpartan-Bold.otf

do-install:
	${MKDIR} ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/LeagueSpartan-Bold.otf ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
