PORTNAME=	zli
DISTVERSIONPREFIX=v
DISTVERSION=	2.1.8
CATEGORIES=	sysutils

MAINTAINER=	decke@FreeBSD.org
COMMENT=	Command line tool for zot servers
WWW=		https://zotregistry.dev/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	project-zot
GH_PROJECT=	zot

GO_MODULE=	zotproject.dev/zot
GO_MOD_DIST=	https://raw.githubusercontent.com/project-zot/zot/refs/tags/v${DISTVERSION}/
GO_TARGET=	./cmd/zli
GO_BUILDFLAGS=	-tags search -ldflags " \
		-X zotregistry.dev/zot/pkg/api/config.ReleaseTag=${DISTVERSION} \
		-X zotregistry.dev/zot/pkg/api/config.BinaryType=minimal \
		-X zotregistry.dev/zot/pkg/api/config.GoVersion=${GO_VERSION}"

PLIST_FILES=	bin/zli

.include <bsd.port.mk>
