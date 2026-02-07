PORTNAME=	pkgcompare
PORTVERSION=	1.1
PORTREVISION=	2
CATEGORIES=	ports-mgmt

MAINTAINER=	waitman@waitman.net
COMMENT=	Alternate to pkg upgrade
WWW=		https://github.com/waitman/pkg-compare

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libpkg.so:${PKG_ORIGIN} \
		libsqlite3.so:databases/sqlite3

USE_GITHUB=	yes
GH_ACCOUNT=	waitman
GH_PROJECT=	pkg-compare
GH_TAGNAME=	418295d

BINARY=		pkg-compare

PORTDOCS=	*
PLIST_FILES=	share/man/man8/pkg-compare.8.gz \
		sbin/pkg-compare
SUB_FILES=	pkg-message

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${BINARY} ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/pkg-compare.8 \
		${STAGEDIR}${PREFIX}/share/man/man8
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
