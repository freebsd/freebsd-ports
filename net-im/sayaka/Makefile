PORTNAME=	sayaka
PORTVERSION=	3.5.1
PORTREVISION=	2
CATEGORIES=	net-im

MAINTAINER=	sue@iwmt.org
COMMENT=	Twitter client for sixel-capable terminals
WWW=		https://github.com/isaki68k/sayaka

LICENSE=	BSD2CLAUSE

LIB_DEPENDS=	libpng.so:graphics/png \
		libmbedtls.so:security/mbedtls

USES=		compiler:c++17-lang iconv jpeg pkgconfig
GNU_CONFIGURE=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	isaki68k

PLIST_FILES=	bin/sayaka
PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS

CXXFLAGS+=	-Wno-error=vla-cxx-extension

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/sayaka ${STAGEDIR}${PREFIX}/bin

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
