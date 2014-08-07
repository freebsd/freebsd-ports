# Created by: Zhihao Yuan <lichray@gmail.com>
# $FreeBSD$

PORTNAME=	pure-csv
PORTVERSION=	1.5
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	https://cdn.bitbucket.org/purelang/pure-lang/downloads/
DIST_SUBDIR=	pure

MAINTAINER=	ports@FreeBSD.org
COMMENT=	CSV reading and writing module for the Pure language

LICENSE=	BSD3CLAUSE

USES=		pure
PORTDOCS=	README
OPTIONS_DEFINE=	DOCS

PLIST_FILES=	lib/pure/csv.pure \
		lib/pure/csv.so

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/pure/csv.so
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
