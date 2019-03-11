# Created by: Florian Limberger <flo@snakeoilproductions.net>
# $FreeBSD$

PORTNAME=	league-gothic
DISTVERSION=	g20140319
PORTREVISION=	1
CATEGORIES=	x11-fonts

MAINTAINER=	flo@snakeoilproductions.net
COMMENT=	Revival of an old classic, Alternate Gothic \#1

LICENSE=	OFL11
LICENSE_FILE=	${WRKSRC}/Open\ Font\ License.markdown

USES=		fonts
USE_GITHUB=	yes
GH_ACCOUNT=	theleagueof
GH_TAGNAME=	e6dce21

NO_ARCH=	yes
NO_BUILD=	yes

do-install:
	${MKDIR} ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.otf ${STAGEDIR}${FONTSDIR}
.include <bsd.port.mk>
