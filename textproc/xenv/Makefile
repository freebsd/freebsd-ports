PORTNAME=	xenv
PORTVERSION=	4.0
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	https://download.gnu.org.ua/release/xenv/

MAINTAINER=	zeus@gnu.org.ua
COMMENT=	Text preprocessor for environment variable expansion
WWW=		https://gnu.org.ua/software/xenv/

LICENSE=	GPLv3+

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
TEST_TARGET=	check

PLIST_FILES=	bin/xenv share/man/man1/xenv.1.gz
PORTDOCS=	NEWS README
INFO=		${PORTNAME}

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
