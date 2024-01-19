PORTNAME=	tree
PORTVERSION=	2.1.1
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://mama.indstate.edu/users/ice/tree/src/ \
		https://fossies.org/linux/misc/

MAINTAINER=	gb@unistra.fr
COMMENT=	Display a tree-view of directories with optional color or HTML output
WWW=		https://mama.indstate.edu/users/ice/tree/

LICENSE=	GPLv2+

USES=		gmake tar:tgz
MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS}" LDFLAGS="${LDFLAGS}"

PLIST_FILES=	bin/tree \
		share/man/man1/tree.1.gz
PORTDOCS=	CHANGES README TODO

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tree ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/*.1 ${STAGEDIR}${PREFIX}/share/man/man1

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
