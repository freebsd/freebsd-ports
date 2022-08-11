PORTNAME=	ttf2eot
PORTVERSION=	0.0.3
DISTVERSIONPREFIX=	v
CATEGORIES=	www converters

MAINTAINER=	portmaster@bsdforge.com
COMMENT=	Convert TTF font file to EOT web embeddable file

LICENSE=	BSD2CLAUSE LGPL20
LICENSE_COMB=	multi

USE_GITHUB=	yes
GH_ACCOUNT=	wget
GH_PROJECT=	ttf2eot
GH_TAGNAME=	b732f41

USES=		gmake
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
