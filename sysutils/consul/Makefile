PORTNAME=	consul
PORTVERSION=	1.15.2
DISTVERSIONPREFIX=	v
CATEGORIES=	sysutils
MASTER_SITES=	https://raw.githubusercontent.com/hashicorp/consul/${DISTVERSIONFULL}/ \
		https://raw.githubusercontent.com/hashicorp/consul/${DISTVERSIONFULL}/:api \
		https://raw.githubusercontent.com/hashicorp/consul/${DISTVERSIONFULL}/:envoyextensions \
		https://raw.githubusercontent.com/hashicorp/consul/${DISTVERSIONFULL}/:proto_public \
		https://raw.githubusercontent.com/hashicorp/consul/${DISTVERSIONFULL}/:sdk \
		https://raw.githubusercontent.com/hashicorp/consul/${DISTVERSIONFULL}/:troubleshoot
DISTFILES=	go.mod \
		api/go.mod:api \
		envoyextensions/go.mod:envoyextensions \
		proto-public/go.mod:proto_public \
		sdk/go.mod:sdk \
		troubleshoot/go.mod:troubleshoot

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Service discovery and configuration made easy
WWW=		https://www.consul.io/

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cpe go:modules
CPE_VENDOR=	hashicorp

USE_GITHUB=	yes
GH_ACCOUNT=	hashicorp

GITID=		5e08e22
USE_RC_SUBR=	consul

GO_MODULE=	github.com/hashicorp/consul
GO_BUILDFLAGS=	-ldflags="-s \
		-X github.com/hashicorp/consul/version.GitCommit=${GITID} \
		-X github.com/hashicorp/consul/version.BuildDate=${SOURCE_DATE_EPOCH:U${SOURCE_DATE_EPOCH_CMD:sh}} \
		"

ETCDIR=		${PREFIX}/etc/consul.d
SUB_LIST=	CONSUL_DBDIR=${CONSUL_DBDIR} \
		GROUP=${CONSUL_GROUP} \
		USER=${CONSUL_USER}

CONSUL_USER?=	consul
CONSUL_GROUP?=	consul
CONSUL_DBDIR?=	/var/db/${PORTNAME}

USERS=		${CONSUL_USER}
GROUPS=		${CONSUL_GROUP}

PLIST_FILES=	bin/consul

# Bring DISTINFO_FILE into scope so we can get the timestamp.
.include <bsd.port.pre.mk>

SOURCE_DATE_EPOCH_CMD=	date -ur \
			$$(${GREP} -m1 TIMESTAMP ${DISTINFO_FILE} | ${SED} -e 's/[^0-9]//g') \
			'+%Y-%m-%dT%H:%M:%SZ'

.include <bsd.port.post.mk>
