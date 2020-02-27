# $FreeBSD$

PORTNAME=	sent
PORTVERSION=	1
PORTREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	http://dl.suckless.org/tools/

MAINTAINER=	0mp@FreeBSD.org
COMMENT=	Simple plaintext presentation tool

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig
RUN_DEPENDS=	2ff:graphics/farbfeld

USES=		localbase xorg
USE_XORG=	x11 xft

CFLAGS+=	-I${LOCALBASE}/include/freetype2

MAKE_ARGS=	CC="${CC}" PREFIX="${PREFIX}" MANPREFIX="${MANPREFIX}/share/man" \
		X11INC="${LOCALBASE}/include" X11LIB="${LOCALBASE}/lib"
NO_WRKSUBDIR=	yes

PLIST_FILES=	bin/sent \
		share/man/man1/sent.1.gz
PORTDOCS=	README.md
PORTEXAMPLES=	example \
		nyan.png \
		transparent_test.ff

OPTIONS_DEFINE=	DOCS EXAMPLES

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/sent

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR})

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${PORTEXAMPLES} ${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>
