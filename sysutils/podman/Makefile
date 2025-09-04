PORTNAME=	podman
DISTVERSIONPREFIX=	v
DISTVERSION=	5.6.0
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

USE_GITHUB=	yes
GH_ACCOUNT=	containers
GH_PROJECT=	podman

INSTALL_TARGET=	install install.completions

.include <bsd.port.mk>
