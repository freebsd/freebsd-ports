# $FreeBSD$

PORTNAME=	nomad
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.4
CATEGORIES=	sysutils

MAINTAINER=	jhixson@FreeBSD.org
COMMENT=	Cluster manager and scheduler

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go
USE_GITHUB=	yes
GH_ACCOUNT=	hashicorp
GH_SUBDIR=	src/github.com/hashicorp/nomad
USE_RC_SUBR=	nomad

GO_BUILDFLAGS=	-tags ui \
		-ldflags "-X main.GitDescribe=${DISTVERSIONFULL}"

USERS=		nomad
GROUPS=		nomad

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/nomad
	${INSTALL_DATA} ${WRKSRC}/dist/client.hcl ${STAGEDIR}${PREFIX}/etc/nomad/client.hcl.sample
	${INSTALL_DATA} ${WRKSRC}/dist/server.hcl ${STAGEDIR}${PREFIX}/etc/nomad/server.hcl.sample

.include <bsd.port.mk>
