PORTNAME=	gwhich
PORTVERSION=	2.25
CATEGORIES=	misc
MASTER_SITES=	GNU/which
DISTNAME=	which-${PORTVERSION}

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Identify executable, alias, or shell function
WWW=		https://savannah.gnu.org/projects/which/

LICENSE=	GPLv3+

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--program-prefix=g

INFO=		which
PLIST_FILES=	bin/gwhich share/man/man1/gwhich.1.gz
PORTDOCS=	AUTHORS EXAMPLES NEWS README.*

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
