PORTNAME=	jira-cli
DISTVERSIONPREFIX=	v
DISTVERSION=	1.7.0
PORTREVISION=	1
CATEGORIES=	www
DIST_SUBDIR=	jira-cli

MAINTAINER=	fox@FreeBSD.org
COMMENT=	Feature-rich Interactive Jira Command Line
WWW=		https://github.com/ankitpokhrel/jira-cli

LICENSE=	MIT

USES=		go:modules

GO_MODULE=	github.com/ankitpokhrel/jira-cli
GO_BUILDFLAGS=	-ldflags="-X github.com/ankitpokhrel/jira-cli/internal/version.Version=v${PORTVERSION} \
		-X github.com/ankitpokhrel/jira-cli/internal/version.BuildDate=$$(date +'%Y-%m-%dT%H:%M:%S%Z') \
		-X github.com/ankitpokhrel/jira-cli/internal/version.GitCommit= "
GO_TARGET=	./cmd/jira

post-install:
	${STAGEDIR}${PREFIX}/bin/jira man -g -o ${STAGEDIR}${PREFIX}/share/man/man7

.include <bsd.port.mk>
