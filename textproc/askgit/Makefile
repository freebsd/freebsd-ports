PORTNAME=	askgit
DISTVERSIONPREFIX=	v
DISTVERSION=	0.3.7
PORTREVISION=	1
CATEGORIES=	textproc

MAINTAINER=	lcook@FreeBSD.org
COMMENT=	Query git repositories with SQL

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libgit2.so:devel/libgit2

USES=		go:modules pkgconfig

GO_MODULE=	github.com/augmentable-dev/${PORTNAME}
GO_BUILDFLAGS=	-tags sqlite_vtable,sqlite_json1,system_libgit2
GO_TESTFLAGS=	${GO_BUILDFLAGS}

PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} \
		${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
