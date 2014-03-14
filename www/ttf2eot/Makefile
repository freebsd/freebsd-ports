# Created by: Stefan Bethke <stb@lassitu.de>
# $FreeBSD$

PORTNAME=	ttf2eot
DISTVERSION=	0.0.2-2
CATEGORIES=	www converters
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	stb@lassitu.de
COMMENT=	Convert TTF font file to EOT web embeddable file

USE_GMAKE=	yes
ALL_TARGET=	ttf2eot

PLIST_FILES=	bin/ttf2eot
PORTDOCS=	README

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's|g++|${CXX}|' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ttf2eot ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
