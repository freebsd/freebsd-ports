PORTNAME=	xenv
PORTVERSION=	1.2
CATEGORIES=	textproc
MASTER_SITES=	https://download.gnu.org.ua/release/xenv/

MAINTAINER=	zeus@gnu.org.ua
COMMENT=	Text preprocessor for environment variable expansion

LICENSE=	GPLv3+

MAKE_ARGS=	CFLAGS="${CFLAGS} -Wall"
ALL_TARGET=	${PORTNAME}
TEST_TARGET=	check

PLIST_FILES=	bin/xenv share/man/man1/xenv.1.gz
PORTDOCS=	NEWS README

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
