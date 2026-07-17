PORTNAME=	gitlab-agent
PORTVERSION=	${GITLAB_VERSION}
DISTVERSIONPREFIX=	v
PORTREVISION=	${GITLAB_PORTREVISION} # modify it in www/gitlab/Makefile.common
CATEGORIES=	net

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	GitLab kubernetes agent
WWW=		https://gitlab.com/gitlab-org/cluster-integration/gitlab-agent

LICENSE=	MIT

# bazel>=0:devel/bazel  \
BUILD_DEPENDS=	git>=0:devel/git \
		golangci-lint>=0:devel/golangci-lint

USES=		go:modules
USE_GITLAB=	yes
GL_ACCOUNT=	gitlab-org/cluster-integration
# this branch removes the replace line in go.mod which breaks the way FreeBSD ports build go packages
GO_MOD_DIST=	https://gitlab.com/mfechner/gitlab-agent/-/raw/19-2-stable/
GO_MODULE=	gitlab.com/gitlab-org/cluster-integration/gitlab-agent/v19

_BUILD_DATE=	$$(date -u "+%Y-%m-%d-%H%M UTC")
GO_TARGET=     ./cmd/kas
GO_BUILDFLAGS= -tags="tracer_static,tracer_static_jaeger" \
		-ldflags=" \
		-X 'gitlab.com/gitlab-org/cluster-integration/gitlab-agent/v19/cmd.Version=v${PORTVERSION}' \
		-X 'gitlab.com/gitlab-org/cluster-integration/gitlab-agent/v19/cmd.Commit=${GL_TAGNAME:C/^(........).*/\1/}' \
		-X 'gitlab.com/gitlab-org/cluster-integration/gitlab-agent/v19/cmd.BuildTime=${_BUILD_DATE}'"

PLIST_FILES=	bin/kas

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/bin/kas ${STAGEDIR}${PREFIX}/bin/kas

.include "${.CURDIR}/../../www/gitlab/Makefile.common"
.include <bsd.port.mk>
