PORTNAME=	podman
DISTVERSIONPREFIX=	v
DISTVERSION=	5.5.1
CATEGORIES=	sysutils

MAINTAINER=	dfr@FreeBSD.org
COMMENT=	Manage Pods, Containers and Container Images
WWW=		https://podman.io/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	bash:shells/bash \
		ggrep:textproc/gnugrep \
		go-md2man:textproc/go-md2man \
		gsed:textproc/gsed
LIB_DEPENDS=	libgpgme.so:security/gpgme
RUN_DEPENDS=	conmon:sysutils/conmon \
		containernetworking-plugins>=0:net/containernetworking-plugins \
		containers-common>=0:sysutils/containers-common \
		ocijail:sysutils/ocijail

USES=		gmake go:no_targets,1.23 pkgconfig python:build shebangfix
USE_RC_SUBR=	podman podman_service

SHEBANG_FILES=	${WRKSRC}/hack/markdown-preprocess
MAKE_ARGS=	SHELL=${LOCALBASE}/bin/bash

# Parallel builds are flaky due to some kind of file race in the
# markdown-preprocess phase of the docs build.
MAKE_JOBS_UNSAFE=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	containers
GH_PROJECT=	podman

INSTALL_TARGET=	install install.completions

# Temporary until https://github.com/containers/podman/pull/16422 lands
do-install:
	${GMAKE} -C ${WRKSRC} ${MAKE_ARGS} DESTDIR=${STAGEDIR} GO=${GO_CMD} install
	${GMAKE} -C ${WRKSRC} ${MAKE_ARGS} DESTDIR=${STAGEDIR} GO=${GO_CMD} install.completions
	${RM} ${STAGEDIR}${PREFIX}/lib/tmpfiles.d/podman.conf

.include <bsd.port.mk>
