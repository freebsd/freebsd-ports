PORTNAME=	nomad
DISTVERSIONPREFIX=	v
DISTVERSION=	1.8.1
PORTREVISION=	3
CATEGORIES=	sysutils
MASTER_SITES=	https://raw.githubusercontent.com/hashicorp/nomad/${DISTVERSIONFULL}/
DISTFILES=	go.mod \
		api/go.mod

PATCH_SITES=	https://github.com/hashicorp/nomad/commit/
PATCHFILES=	2c86fe02834dc17a518d6e485aed66e971f7ed68.patch:-p1 \
		ed748105c9284e7c1d0feec20bb450d1d3c7007d.patch:-p1

MAINTAINER=	jhixson@FreeBSD.org
COMMENT=	Cluster manager and scheduler
WWW=		https://www.nomadproject.io/

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cpe go:1.22,modules
CPE_VENDOR=	hashicorp
USE_GITHUB=	yes
GH_ACCOUNT=	hashicorp
USE_RC_SUBR=	nomad

GO_MODULE=	github.com/hashicorp/nomad
GO_BUILDFLAGS=	-tags ui \
		-ldflags "-X main.GitDescribe=${DISTVERSIONFULL}"

USERS=		nomad
GROUPS=		nomad

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/nomad
	${INSTALL_DATA} ${WRKSRC}/demo/vagrant/client1.hcl ${STAGEDIR}${PREFIX}/etc/nomad/client1.hcl.sample
	${INSTALL_DATA} ${WRKSRC}/demo/vagrant/client2.hcl ${STAGEDIR}${PREFIX}/etc/nomad/client2.hcl.sample
	${INSTALL_DATA} ${WRKSRC}/demo/vagrant/server.hcl ${STAGEDIR}${PREFIX}/etc/nomad/server.hcl.sample

# Bring DISTINFO_FILE into scope so we can get the timestamp.
.include <bsd.port.pre.mk>

SOURCE_DATE_EPOCH_CMD=	date -ur \
			$$(${GREP} -m1 TIMESTAMP ${DISTINFO_FILE} | ${SED} -e 's/[^0-9]//g') \
			'+%Y-%m-%dT%H:%M:%SZ'

.include <bsd.port.post.mk>
