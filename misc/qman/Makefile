PORTNAME=	qman
PORTVERSION=	1.4.2.20250630
CATEGORIES=	misc

MAINTAINER=	tagattie@FreeBSD.org
COMMENT=	More modern man page viewer for our terminals
WWW=		https://github.com/plp13/qman

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	cog:devel/py-cogapp

USES=		groff:run meson pkgconfig

USE_GITHUB=	yes
GH_ACCOUNT=	plp13
GH_TAGNAME=	16b4e808ab619d7bfb7d94017ca9505b69a387fb

MESON_ARGS=	-Dconfigdir=${PREFIX}/etc/xdg/${PORTNAME} \
		-Ddocs=disabled \
		-Dtests=disabled

OPTIONS_DEFINE=	BZIP2 DOCS GZIP LZMA MANPAGES
OPTIONS_DEFAULT=BZIP2 GZIP LZMA MANPAGES
OPTIONS_SUB=	yes

BZIP2_DESC=	Support bzip2-compressed manual pages
GZIP_DESC=	Support gzip-compressed manual pages
LZMA_DESC=	Support xz-compressed manual pages

BZIP2_MESON_ENABLED=	bzip2
GZIP_MESON_ENABLED=	gzip
LZMA_MESON_ENABLED=	lzma
MANPAGES_MESON_ENABLED=	man-pages

PORTDOCS=	BUILDING.md CONTRIBUTING.md DEBUGGING.md OS_SPECIFIC.md \
		README.md TESTING.md TROUBLESHOOTING.md

.include <bsd.port.options.mk>

# FreeBSD 13 is missing /usr/libdata/pkgconfig/ncursesw.pc
.if ${OPSYS} == FreeBSD && ${OSREL:R} == 13
USES+=		ncurses:port
.else
USES+=		ncurses
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|' \
		${WRKSRC}/config/qman.conf
	@${REINPLACE_CMD} -e 's|/etc|${PREFIX}&|' \
		${WRKSRC}/src/config.c.cog ${WRKSRC}/src/config.h.cog

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${PORTDOCS:S|README.md||:S|^|${WRKSRC}/doc/|} ${STAGEDIR}${DOCSDIR}


.include <bsd.port.mk>
