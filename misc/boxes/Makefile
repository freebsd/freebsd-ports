PORTNAME=	boxes
PORTVERSION=	2.2.0
PORTREVISION=	2
DISTVERSIONPREFIX=	v
CATEGORIES=	misc

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Draws ASCII-art configurable boxes around text or code
WWW=		https://boxes.thomasjensen.com/

LICENSE=	GPLv3

LIB_DEPENDS=	libpcre2-32.so:devel/pcre2 \
		libunistring.so:devel/libunistring

USES=		bison gmake

USE_GITHUB=	yes
GH_ACCOUNT=	ascii-boxes

MAKE_ARGS=	CC="${CC}" \
		CFLAGS="${CFLAGS} -I. -I../src -I${LOCALBASE}/include" \
		GLOBALCONF=${GLOBALCONF} \
		LDFLAGS="-L${LOCALBASE}/lib"
ALL_TARGET=	build

GLOBALCONF=	${DATADIR}/boxes-config

PLIST_FILES=	${DATADIR_REL}/${PORTNAME}-config \
		bin/${PORTNAME} \
		share/man/man1/${PORTNAME}.1.gz

PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS

post-patch:
	@${RM} ${WRKSRC}/src/${PORTNAME}.h ${WRKSRC}/doc/${PORTNAME}.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/out/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}-config ${STAGEDIR}${DATADIR}
	${INSTALL_MAN} ${WRKSRC}/doc/${PORTNAME}.1 \
		${STAGEDIR}${PREFIX}/share/man/man1/

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
