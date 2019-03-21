# Created by: Alan Eldridge <alane@FreeBSD.org>
# $FreeBSD$

PORTNAME=	tree
PORTVERSION=	1.8.0
CATEGORIES=	sysutils
MASTER_SITES=	ftp://mama.indstate.edu/linux/tree/

MAINTAINER=	gb@unistra.fr
COMMENT=	Display a tree-view of directories with optional color or HTML output

LICENSE=	GPLv2

MAKE_ENV+=	MKDIR="${MKDIR}"
USES=		gmake tar:tgz

PLIST_FILES=	bin/tree \
		man/man1/tree.1.gz

PORTDOCS=	CHANGES README

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tree ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/*.1 ${STAGEDIR}${MAN1PREFIX}/man/man1
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
