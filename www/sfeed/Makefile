PORTNAME=	sfeed
PORTVERSION=	1.8
CATEGORIES=	www
MASTER_SITES=	https://codemadness.org/releases/sfeed/

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	RSS and Atom parser
WWW=		https://codemadness.org/sfeed-simple-feed-parser.html

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/LICENSE

CFLAGS+=	-D__BSD_VISIBLE

OPTIONS_DEFINE=	DOCS

post-install:
	cd ${STAGEDIR}${PREFIX}/bin && ${STRIP_CMD} sfeed sfeed_atom sfeed_curses sfeed_frames sfeed_gopher sfeed_html sfeed_mbox sfeed_json sfeed_opml_import sfeed_plain sfeed_twtxt sfeed_web sfeed_xmlenc

.include <bsd.port.mk>
