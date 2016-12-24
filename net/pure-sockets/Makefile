# Created by: Zhihao Yuan <lichray@gmail.com>
# $FreeBSD$

PORTNAME=	pure-sockets
PORTVERSION=	0.7
CATEGORIES=	net
MASTER_SITES=	https://bitbucket.org/purelang/pure-lang/downloads/
DIST_SUBDIR=	pure

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Pure language interface to the Berkeley socket functions

LICENSE=	GPLv3 LGPL3
LICENSE_COMB=	dual

USES=		pkgconfig pure

PORTDOCS=	README
PORTEXAMPLES=	*
PLIST_FILES=	lib/pure/sockets.pure \
		lib/pure/sockets.so

OPTIONS_DEFINE=	DOCS EXAMPLES

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/pure/sockets.so

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	@(cd ${WRKSRC}/examples/ && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>
