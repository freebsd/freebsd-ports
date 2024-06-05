PORTNAME=	containers-common
DISTVERSIONPREFIX=	v
DISTVERSION=	0.59.1
CATEGORIES=	sysutils

MAINTAINER=	dfr@FreeBSD.org
COMMENT=	Common manpages and config files for podman and buildah
WWW=		https://github.com/containers

LICENSE=	GPLv2

BUILD_DEPENDS=	bash:shells/bash \
		curl:ftp/curl \
		go-md2man:textproc/go-md2man

USES=		gmake

USE_GITHUB=	nodefault
GH_ACCOUNT=	containers:common containers:image containers:storage \
		containers:skopeo
GH_PROJECT=	common:common image:image storage:storage skopeo:skopeo
GH_TAGNAME=	v${DISTVERSION}:common v${IMAGEVERSION}:image \
		v${STORAGEVERSION}:storage v${SKOPEOVERSION}:skopeo

NO_ARCH=	yes

IMAGEVERSION=	5.31.0
STORAGEVERSION=	1.54.0
SKOPEOVERSION=	1.14.4

WRKSRC=		${WRKDIR}/common-${DISTVERSION}
IMAGESRC=	${WRKDIR}/image-${IMAGEVERSION}
STORAGESRC=	${WRKDIR}/storage-${STORAGEVERSION}
SKOPEOSRC=	${WRKDIR}/skopeo-${SKOPEOVERSION}

do-build:
	${GMAKE} -C ${WRKSRC}/docs
	${GMAKE} -C ${STORAGESRC} install.tools

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/containers/certs.d
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/containers/hooks.d
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/containers/registries.d
	${INSTALL_DATA} ${SKOPEOSRC}/default-policy.json ${STAGEDIR}${PREFIX}/etc/containers/policy.json.sample
# Temporary until https://github.com/containers/common/pull/1199 propagates to podman and buildah
	${INSTALL_DATA} ${PATCHDIR}/containers.conf ${STAGEDIR}${PREFIX}/etc/containers/containers.conf.sample
#${INSTALL_DATA} ${WRKSRC}/pkg/config/containers.conf-freebsd ${STAGEDIR}${PREFIX}/etc/containers/containers.conf.sample
	${INSTALL_DATA} ${STORAGESRC}/storage.conf-freebsd ${STAGEDIR}${PREFIX}/etc/containers/storage.conf.sample
	${INSTALL_DATA} ${IMAGESRC}/registries.conf ${STAGEDIR}${PREFIX}/etc/containers/registries.conf.sample
	${GMAKE} -C ${WRKSRC}/docs DESTDIR=${STAGEDIR} install
	${GMAKE} -C ${IMAGESRC} PREFIX=${STAGEDIR}${PREFIX} install-docs
	${GMAKE} -C ${STORAGESRC}/docs GOMD2MAN=${LOCALBASE}/bin/go-md2man containers-storage.conf.5
	${INSTALL_MAN} ${STORAGESRC}/docs/containers-storage.conf.5 ${STAGEDIR}${PREFIX}/share/man/man5

.include <bsd.port.mk>
