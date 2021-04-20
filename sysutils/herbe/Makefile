PORTNAME=	herbe
DISTVERSION=	1.0.0
CATEGORIES=	sysutils

MAINTAINER=	0mp@FreeBSD.org
COMMENT=	Daemon-less notifications without D-Bus

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${LOCALBASE}/include/freetype2/ft2build.h:print/freetype2

USES=		localbase xorg
USE_CSTD=	c99

USE_GITHUB=	yes
GH_ACCOUNT=	dudik

USE_XORG=	x11 xft

MAKE_ARGS=	CFLAGS="${CFLAGS} ${LIBS}"

CFLAGS+=	-I${LOCALBASE}/include/freetype2
LIBS+=		-lX11 -lXft

PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
