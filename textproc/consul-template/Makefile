PORTNAME=	consul-template
DISTVERSION=	0.39.0
DISTVERSIONPREFIX=	v
CATEGORIES=	textproc

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Generic template rendering and notifications with Consul
WWW=		https://github.com/hashicorp/consul-template

LICENSE=	MPL20

USES=		go:1.22,modules
USE_RC_SUBR=	consul-template

GO_MODULE=	github.com/hashicorp/consul-template
GO_BUILDFLAGS=	-ldflags='\
		-s -w -X github.com/hashicorp/consul-template/version.Name=${PORTNAME} \
		-X github.com/hashicorp/consul-template/version.GitCommit=release'

PLIST_FILES=	bin/consul-template

.include <bsd.port.mk>
