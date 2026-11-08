PORTNAME=	container-libs-common
DISTVERSIONPREFIX=	v
DISTVERSION=	0.67.2
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	https://github.com/podman-container-tools/container-libs/archive/refs/tags/common/v${DISTVERSION}/:libs \
		https://github.com/podman-container-tools/skopeo/archive/refs/tags/:skopeo
DISTFILES=	v${DISTVERSION}.tar.gz:libs \
		v${SKOPEOVERSION}.tar.gz:skopeo
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	dfr@FreeBSD.org
COMMENT=	Common manpages and config files for podman and buildah
WWW=		https://github.com/podman-container-tools/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/common/LICENSE

BUILD_DEPENDS=	bash:shells/bash \
		curl:ftp/curl \
		go-md2man:textproc/go-md2man

USES=		gmake

NO_ARCH=	yes

SKOPEOVERSION=	1.22.3

post-patch:
	${SED} -I '' /golangci/d ${WRKSRC}/storage/Makefile
	${SED} -I '' -Ee s/go-md2man../go-md2man/ ${WRKSRC}/storage/Makefile

do-build:
	${GMAKE} -C ${WRKSRC}/common/docs

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/containers/certs.d
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/containers/hooks.d
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/containers/registries.d
	${INSTALL_DATA} ${WRKSRC}/image/default-policy.json \
		${STAGEDIR}${PREFIX}/etc/containers/policy.json.sample
# Temporary until https://github.com/containers/common/pull/1199 propagates to podman and buildah
	${INSTALL_DATA} ${PATCHDIR}/containers.conf \
		${STAGEDIR}${PREFIX}/etc/containers/containers.conf.sample
	${INSTALL_DATA} ${WRKSRC}/storage/storage.conf-freebsd \
		${STAGEDIR}${PREFIX}/etc/containers/storage.conf.sample
	${INSTALL_DATA} ${WRKSRC}/image/registries.conf \
		${STAGEDIR}${PREFIX}/etc/containers/registries.conf.sample
	${GMAKE} -C ${WRKSRC}/common/docs DESTDIR=${STAGEDIR} install
	${GMAKE} -C ${WRKSRC}/image PREFIX=${STAGEDIR}${PREFIX} install-docs
	${GMAKE} -C ${WRKSRC}/storage/docs GOMD2MAN=${LOCALBASE}/bin/go-md2man \
		containers-storage.conf.5
	${INSTALL_MAN} ${WRKSRC}/storage/docs/containers-storage.conf.5 ${STAGEDIR}${PREFIX}/share/man/man5

.include <bsd.port.mk>
