PORTNAME=	xenv
PORTVERSION=	4.0
CATEGORIES=	textproc
MASTER_SITES=	https://download.gnu.org.ua/release/xenv/

MAINTAINER=	zeus@gnu.org.ua
COMMENT=	Text preprocessor for environment variable expansion

LICENSE=	GPLv3+

GNU_CONFIGURE=	yes
TEST_TARGET=	check

PLIST_FILES=	bin/xenv man/man1/xenv.1.gz
PORTDOCS=	NEWS README
INFO=		${PORTNAME}

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
