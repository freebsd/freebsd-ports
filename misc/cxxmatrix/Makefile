PORTNAME=	cxxmatrix
DISTVERSION=	g20210628
CATEGORIES=	misc

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	C++ Matrix: The Matrix Reloaded in Terminals

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

BUILD_DEPENDS=	gawk:lang/gawk

USES=		compiler:c++17-lang gmake
USE_GITHUB=	yes
GH_ACCOUNT=	akinomyoga
GH_TAGNAME=	e70ecca

MAKEFILE=	GNUmakefile

PLIST_FILES=	bin/cxxmatrix \
		share/man/man1/cxxmatrix.1.gz
PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} \
		-e 's|CXXFLAGS :=|CXXFLAGS +=|g' \
		-e 's|-Ofast||g' \
	${WRKSRC}/GNUmakefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cxxmatrix ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/cxxmatrix.1 ${STAGEDIR}${PREFIX}/share/man/man1

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
