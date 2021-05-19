PORTNAME=	containerd
DISTVERSION=	1.5.1
PORTREVISION=	1
DISTVERSIONPREFIX=v
CATEGORIES=	sysutils

MAINTAINER=	decke@FreeBSD.org
COMMENT=	Open and reliable container runtime

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	bash:shells/bash \
		go:lang/go

USES=		gmake

USE_GITHUB=	yes
GH_ACCOUNT=	containerd
GH_SUBDIR=	src/github.com/containerd/containerd

MAKE_ENV=	${GO_ENV} \
		GOFLAGS="${GO_BUILDFLAGS}" \
		VERSION="${DISTVERSION}"

PLIST_FILES=	bin/containerd \
		bin/containerd-shim \
		bin/containerd-stress \
		bin/ctr

do-install:
	@(cd ${WRKSRC} && ${SETENV} DESTDIR="${STAGEDIR}${PREFIX}" ${MAKE_CMD} install)

.include <bsd.port.mk>
