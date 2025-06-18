PORTNAME=	gitlab-kas-grpc
PORTVERSION=	${GITLAB_KAS_GRPC_VERSION}
PORTREVISION=	${GITLAB_PORTREVISION} # modify it in www/gitlab/Makefile.common
CATEGORIES=	net rubygems
MASTER_SITES=	RG

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Auto-generated gRPC client for KAS
WWW=		https://gitlab.com/gitlab-org/cluster-integration/gitlab-agent

LICENSE=	MIT

RUN_DEPENDS=	rubygem-grpc-gitlab>=1.0<2.0:net/rubygem-grpc-gitlab

USES=		gem

NO_ARCH=	yes

.include "${.CURDIR}/../../www/gitlab/Makefile.common"
.include <bsd.port.mk>
