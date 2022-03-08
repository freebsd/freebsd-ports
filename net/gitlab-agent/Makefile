# Created by: Matthias Fechner <mfechner@FreeBSD.org>

PORTNAME=	gitlab-agent
PORTVERSION=	14.8.1
PORTREVISION=	0
DISTVERSIONPREFIX=	v
CATEGORIES=	net

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	GitLab kubernetes agent

LICENSE=	MIT

# bazel>=0:devel/bazel  \
BUILD_DEPENDS=	git>=0:devel/git \
		golangci-lint>=0:devel/golangci-lint

USES=		go:modules
GO_MODULE=	gitlab.com/gitlab-org/cluster-integration/gitlab-agent/v14

GO_BUILDFLAGS=	-tags="tracer_static,tracer_static_jaeger" \
		-ldflags=" \
		-X gitlab.com/gitlab-org/cluster-integration/gitlab-agent/cmd.Version=v${PORTVERSION} \
		-X gitlab.com/gitlab-org/cluster-integration/gitlab-agent/cmd.Commit=${GL_COMMIT:C/^(........).*/\1/}"
GO_TARGET=	./cmd/kas

PLIST_FILES=	bin/kas

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/bin/kas ${STAGEDIR}${PREFIX}/bin/kas

.include <bsd.port.mk>

