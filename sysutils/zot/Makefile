PORTNAME=	zot
DISTVERSIONPREFIX=v
DISTVERSION=	2.1.8
CATEGORIES=	sysutils

MAINTAINER=	decke@FreeBSD.org
COMMENT=	Production ready and vendor neutral OCI image registry
WWW=		https://zotregistry.dev/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	project-zot

GO_MODULE=	zotproject.dev/zot
GO_MOD_DIST=	https://raw.githubusercontent.com/project-zot/zot/refs/tags/v${DISTVERSION}/
GO_TARGET=	./cmd/zot
GO_BUILDFLAGS=	-ldflags " \
		-X zotregistry.dev/zot/pkg/api/config.ReleaseTag=${DISTVERSION} \
		-X zotregistry.dev/zot/pkg/api/config.BinaryType=minimal \
		-X zotregistry.dev/zot/pkg/api/config.GoVersion=${GO_VERSION}"

USE_RC_SUBR=	zot

PLIST_FILES=	bin/zot \
		etc/zot/config-minimal.json.sample

post-install:
	${MKDIR} ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${PATCHDIR}/config-minimal.json ${STAGEDIR}${ETCDIR}/config-minimal.json.sample

.include <bsd.port.mk>
