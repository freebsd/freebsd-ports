PORTNAME=	ops-agent
DISTVERSION=	2.48.0
PORTREVISION=	7
CATEGORIES=	sysutils
PKGNAMEPREFIX=	gcp-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Gather logs and metrics from Google Compute Engine instances
WWW=		https://cloud.google.com/stackdriver/docs/solutions/agents/ops-agent

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
GO_MODULE=	github.com/GoogleCloudPlatform/ops-agent@v0.0.0-20240624194131-536ab1c138a1

GO_TARGET=	./cmd/google_cloud_ops_agent_engine
PLIST_FILES=	bin/google_cloud_ops_agent_engine

.include <bsd.port.mk>
