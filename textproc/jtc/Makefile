# $FreeBSD$

PORTNAME=	jtc
PORTVERSION=	1.75d
CATEGORIES=	textproc

MAINTAINER=	vulcan@wired.sh
COMMENT=	CLI tool to extract, manipulate and transform JSON

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		compiler:c++14-lang
USE_CXXSTD=	c++14
USE_GITHUB=	yes
GH_ACCOUNT=	ldn-softdev

LDFLAGS+=	-lexecinfo

PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	README.md Release\ Notes.md User\ Guide.md \
		Walk-path\ tutorial.md

OPTIONS_DEFINE=	DOCS

do-build:
	${CXX} ${CXXFLAGS} ${LDFLAGS} ${WRKSRC}/${PORTNAME}.cpp -o ${WRKSRC}/${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
