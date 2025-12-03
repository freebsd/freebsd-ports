PORTNAME=	zot
DISTVERSIONPREFIX=v
DISTVERSION=	2.1.11
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	https://github.com/project-zot/zui/releases/download/commit-${ZUI_VERSION}/:ui
DISTFILES=	zui.tgz:ui

MAINTAINER=	decke@FreeBSD.org
COMMENT=	Production ready and vendor neutral OCI image registry
WWW=		https://zotregistry.dev/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_i386=	modernc.org/libc does not compile on i386

USES=		go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	project-zot

ZUI_VERSION=	f870292

GO_MODULE=	zotproject.dev/zot
GO_MOD_DIST=	https://raw.githubusercontent.com/project-zot/zot/refs/tags/v${DISTVERSION}/
GO_TARGET=	./cmd/zot
GO_BUILDFLAGS=	-ldflags " \
		-X zotregistry.dev/zot/pkg/api/config.ReleaseTag=${DISTVERSION} \
		-X zotregistry.dev/zot/pkg/api/config.BinaryType=full \
		-X zotregistry.dev/zot/pkg/api/config.GoVersion=${GO_VERSION}" \
		-tags sync,search,scrub,metrics,lint,ui,mgmt,profile,userprefs,imagetrust,events,search,mgmt,userprefs

USE_RC_SUBR=	zot

PLIST_FILES=	bin/zot \
		etc/zot/config-minimal.json.sample \
		etc/zot/config-ui.json.sample

post-extract:
	${TAR} -xf ${DISTDIR}/${DIST_SUBDIR}/zui.tgz -C ${WRKSRC}/pkg/extensions

post-install:
	${MKDIR} ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${PATCHDIR}/config-minimal.json ${STAGEDIR}${ETCDIR}/config-minimal.json.sample
	${INSTALL_DATA} ${PATCHDIR}/config-ui.json ${STAGEDIR}${ETCDIR}/config-ui.json.sample

.include <bsd.port.mk>
