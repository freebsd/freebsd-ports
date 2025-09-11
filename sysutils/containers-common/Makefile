PORTNAME=	containers-common
DISTVERSIONPREFIX=	v
DISTVERSION=	0.64.1
PORTREVISION=	1
CATEGORIES=	sysutils

MAINTAINER=	dfr@FreeBSD.org
COMMENT=	Common manpages and config files for podman and buildah
WWW=		https://github.com/containers

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC_common}/LICENSE

BUILD_DEPENDS=	bash:shells/bash \
		curl:ftp/curl \
		go-md2man:textproc/go-md2man

USES=		gmake

USE_GITHUB=	nodefault
GH_ACCOUNT=	containers:common containers:image containers:skopeo \
		containers:storage
GH_PROJECT=	common:common image:image skopeo:skopeo storage:storage
GH_TAGNAME=	v${DISTVERSION}:common v${IMAGEVERSION}:image \
		v${SKOPEOVERSION}:skopeo v${STORAGEVERSION}:storage

NO_ARCH=	yes

IMAGEVERSION=	5.36.2
SKOPEOVERSION=	1.20.0
STORAGEVERSION=	1.59.1

do-build:
	${GMAKE} -C ${WRKSRC_common}/docs
	${GMAKE} -C ${WRKSRC_storage} install.tools

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/containers/certs.d
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/containers/hooks.d
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/containers/registries.d
	${INSTALL_DATA} ${WRKSRC_skopeo}/default-policy.json \
		${STAGEDIR}${PREFIX}/etc/containers/policy.json.sample
# Temporary until https://github.com/containers/common/pull/1199 propagates to podman and buildah
	${INSTALL_DATA} ${PATCHDIR}/containers.conf \
		${STAGEDIR}${PREFIX}/etc/containers/containers.conf.sample
	${INSTALL_DATA} ${WRKSRC_storage}/storage.conf-freebsd \
		${STAGEDIR}${PREFIX}/etc/containers/storage.conf.sample
	${INSTALL_DATA} ${WRKSRC_image}/registries.conf \
		${STAGEDIR}${PREFIX}/etc/containers/registries.conf.sample
	${GMAKE} -C ${WRKSRC_common}/docs DESTDIR=${STAGEDIR} install
	${GMAKE} -C ${WRKSRC_image} PREFIX=${STAGEDIR}${PREFIX} install-docs
	${GMAKE} -C ${WRKSRC_storage}/docs GOMD2MAN=${LOCALBASE}/bin/go-md2man \
		containers-storage.conf.5
	${INSTALL_MAN} ${WRKSRC_storage}/docs/containers-storage.conf.5 ${STAGEDIR}${PREFIX}/share/man/man5

.include <bsd.port.mk>
