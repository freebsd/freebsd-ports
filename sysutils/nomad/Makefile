PORTNAME=	nomad
DISTVERSIONPREFIX=	v
DISTVERSION=	1.9.6
CATEGORIES=	sysutils
MASTER_SITES=	https://raw.githubusercontent.com/hashicorp/nomad/${DISTVERSIONFULL}/
DISTFILES=	go.mod \
		api/go.mod

# Patches with fixes:
# - Fix default client retry configuration
# - Allow disabling "wait" again
# - Fix runaway render loop in consul-template
PATCH_SITES=	https://github.com/hashicorp/${PORTNAME}/commit/
PATCHFILES+=	7b89c0ee28b17a742b97ecd9c6601ba7839748cb.diff:-p1 \
		590b085246c58bb233b2c1a59b3f22a0bf2e2bd4.diff:-p1 \
		37fb418a160a380ee20dc19ea3eaecf0bbd27e64.diff:-p1

MAINTAINER=	jhixson@FreeBSD.org
COMMENT=	Cluster manager and scheduler
WWW=		https://www.nomadproject.io/

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cpe go:1.23,modules
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
