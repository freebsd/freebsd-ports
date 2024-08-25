PORTNAME=	gitlab-agent
PORTVERSION=	17.1.6
DISTVERSIONPREFIX=	v
CATEGORIES=	net

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	GitLab kubernetes agent
WWW=		https://gitlab.com/gitlab-org/cluster-integration/gitlab-agent

LICENSE=	MIT

# bazel>=0:devel/bazel  \
BUILD_DEPENDS=	git>=0:devel/git \
		golangci-lint>=0:devel/golangci-lint

USES=		go:modules,1.22
GO_MODULE=	gitlab.com/gitlab-org/cluster-integration/gitlab-agent/v17

_BUILD_DATE=	$$(date -u "+%Y-%m-%d-%H%M UTC")
GO_TARGET=     ./cmd/kas
GO_BUILDFLAGS= -tags="tracer_static,tracer_static_jaeger" \
		-ldflags=" \
		-X 'gitlab.com/gitlab-org/cluster-integration/gitlab-agent/v16/cmd.Version=v${PORTVERSION}' \
		-X 'gitlab.com/gitlab-org/cluster-integration/gitlab-agent/v16/cmd.Commit=${GL_TAGNAME:C/^(........).*/\1/}' \
		-X 'gitlab.com/gitlab-org/cluster-integration/gitlab-agent/v16/cmd.BuildTime=${_BUILD_DATE}'"

PLIST_FILES=	bin/kas

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/bin/kas ${STAGEDIR}${PREFIX}/bin/kas

.include <bsd.port.mk>
