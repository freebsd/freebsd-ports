PORTNAME=	mergestat
DISTVERSIONPREFIX=	v
DISTVERSION=	0.5.3
CATEGORIES=	textproc

MAINTAINER=	lcook@FreeBSD.org
COMMENT=	Query git repositories with SQL

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	sqlite3>=3.0.0:databases/sqlite3
LIB_DEPENDS=	libgit2.so:devel/libgit2

USES=		go:modules pkgconfig
GO_MODULE=	github.com/${PORTNAME}/${PORTNAME}

GO_BUILDFLAGS=	-tags sqlite_vtable,sqlite_json1,system_libgit2
GO_TESTFLAGS=	${GO_BUILDFLAGS}

CGO_CFLAGS+=	-DUSE_LIBSQLITE3
CGO_LDFLAGS+=	-Wl,--unresolved-symbols=ignore-in-object-files

PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS

pre-patch:
	@${MKDIR} ${WRKSRC}/vendor/go.riyazali.net/sqlite/bridge
	@${CP} ${FILESDIR}/bridge.h ${FILESDIR}/bridge.c ${WRKSRC}/vendor/go.riyazali.net/sqlite/bridge

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} \
		${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
