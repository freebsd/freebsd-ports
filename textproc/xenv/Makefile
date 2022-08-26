PORTNAME=	xenv
PORTVERSION=	3.2
CATEGORIES=	textproc
MASTER_SITES=	https://download.gnu.org.ua/release/xenv/

MAINTAINER=	zeus@gnu.org.ua
COMMENT=	Text preprocessor for environment variable expansion

LICENSE=	GPLv3+

USES=		makeinfo
MAKE_ARGS=	CFLAGS="${CFLAGS} -Wall"
ALL_TARGET=	${PORTNAME}
TEST_TARGET=	check

PLIST_FILES=	bin/xenv share/man/man1/xenv.1.gz
PORTDOCS=	NEWS README
INFO=		${PORTNAME}

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e '/^%{/ { x; s/^/#include <signal.h>/; \
		H; x; }' ${WRKSRC}/xenv.l

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
