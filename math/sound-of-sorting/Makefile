# Created by: Stefan Esser <se@StefanEsser.FreeBSD.org>

PORTNAME=	sound-of-sorting
PORTVERSION=	0.6.5
DISTVERSIONPREFIX=	${PORTNAME}-
PORTREVISION=	3
CATEGORIES=	math

MAINTAINER=	se@FreeBSD.org
COMMENT=	Visualization and "Audibilization" of Sorting Algorithms

LICENSE=	GPLv3

USES=		compiler:c++11-lang sdl

GNU_CONFIGURE=	yes
USE_SDL=	sdl
USE_WX=		3.0+
WX_CONF_ARGS=	relative

OPTIONS_DEFINE=	DOCS

USE_GITHUB=	yes
GH_ACCOUNT=	bingmann
GH_TAGNAME=	5884a35

PLIST_FILES=	bin/sound-of-sorting
PORTDOCS=	README

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/src/sound-of-sorting ${STAGEDIR}${PREFIX}/bin/
		${MKDIR} ${STAGEDIR}${PREFIX}/share/doc/sound-of-sorting
		${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${PREFIX}/share/doc/sound-of-sorting/README

.include <bsd.port.mk>
