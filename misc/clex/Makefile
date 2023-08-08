PORTNAME=	clex
PORTVERSION=	4.7
CATEGORIES=	misc
MASTER_SITES=	https://github.com/xitop/${PORTNAME}/releases/download/v${PORTVERSION}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Command line file manager
WWW=		http://www.clex.sk/

LICENSE=	GPLv2

USES=		ncurses gmake

GNU_CONFIGURE=	yes

PLIST_FILES=	bin/clex bin/cfg-clex bin/kbd-test \
		man/man1/cfg-clex.1.gz \
		man/man1/clex.1.gz \
		man/man1/kbd-test.1.gz

PORTDOCS=	AUTHORS ChangeLog README

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
