PORTNAME=	gitlab-agent
PORTVERSION=	15.1.0
DISTVERSIONPREFIX=	v
PORTREVISION=	1
CATEGORIES=	net

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	GitLab kubernetes agent

LICENSE=	MIT

# bazel>=0:devel/bazel  \
BUILD_DEPENDS=	git>=0:devel/git \
		golangci-lint>=0:devel/golangci-lint

USES=		go:modules
GO_MODULE=	gitlab.com/gitlab-org/cluster-integration/gitlab-agent/v15

_BUILD_DATE=	$$(date -u "+%Y-%m-%d-%H%M UTC")
GO_BUILDFLAGS= -tags="tracer_static,tracer_static_jaeger" \
		-ldflags=" \
		-X 'gitlab.com/gitlab-org/cluster-integration/gitlab-agent/v15/cmd.Version=v${PORTVERSION}' \
		-X 'gitlab.com/gitlab-org/cluster-integration/gitlab-agent/v15/cmd.Commit=${GL_COMMIT:C/^(........).*/\1/}' \
		-X 'gitlab.com/gitlab-org/cluster-integration/gitlab-agent/v15/cmd.BuildTime=${_BUILD_DATE}'"
GO_TARGET=     ./cmd/kas

PLIST_FILES=	bin/kas

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/bin/kas ${STAGEDIR}${PREFIX}/bin/kas

.include <bsd.port.mk>
