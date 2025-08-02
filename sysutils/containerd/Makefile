PORTNAME=	containerd
DISTVERSIONPREFIX=v
DISTVERSION=	2.1.4
CATEGORIES=	sysutils

MAINTAINER=	decke@FreeBSD.org
COMMENT=	Open and reliable container runtime
WWW=		https://containerd.io/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	bash:shells/bash

USES=		cpe gmake go:1.23,modules,no_targets
USE_GITHUB=	yes
GH_SUBDIR=	src/github.com/containerd/containerd

CPE_VENDOR=	linuxfoundation

USE_RC_SUBR=	containerd

MAKE_ENV=	${GO_ENV} \
		GOFLAGS="${GO_BUILDFLAGS}" \
		VERSION="${DISTVERSION}"

PLIST_FILES=	bin/containerd \
		bin/containerd-stress \
		bin/ctr

do-install:
	@(cd ${WRKSRC} && ${SETENV} DESTDIR="${STAGEDIR}" ${MAKE_CMD} install)

.include <bsd.port.mk>
