# Created by: Alan Eldridge <alane@FreeBSD.org>

PORTNAME=	tree
PORTVERSION=	2.0.1
CATEGORIES=	sysutils
MASTER_SITES=	http://mama.indstate.edu/users/ice/tree/src/ \
		https://fossies.org/linux/misc/

MAINTAINER=	gb@unistra.fr
COMMENT=	Display a tree-view of directories with optional color or HTML output

LICENSE=	GPLv2+

USES=		gmake tar:tgz
MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS}" LDFLAGS="${LDFLAGS}"

PLIST_FILES=	bin/tree \
		man/man1/tree.1.gz \
		man/man1/tree.fr.1.gz
PORTDOCS=	CHANGES README TODO

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tree ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/*.1 ${STAGEDIR}${MAN1PREFIX}/man/man1

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
