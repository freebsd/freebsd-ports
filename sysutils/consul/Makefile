# $FreeBSD$

PORTNAME=	consul
PORTVERSION=	0.5.2
DISTVERSIONPREFIX=	v
CATEGORIES=	sysutils
MASTER_SITES=	https://dl.bintray.com/mitchellh/consul/:web_ui
DISTFILES=	${PORTVERSION}_web_ui.zip:web_ui

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Service discovery and configuration made easy

LICENSE=	MPL

BUILD_DEPENDS=	${LOCALBASE}/bin/go:${PORTSDIR}/lang/go

USES=		compiler

USE_GITHUB=	yes
GH_ACCOUNT=	hashicorp:DEFAULT,go_checkpoint,go_msgpack,go_multierror,go_syslog,golang_lru,hcl,logutils,memberlist,raft,raft_mdb,serf,scada,yamux,migrate,msgpackrpc,boltdb \
		armon:circbuf,go_metrics,go_radix,gomdb golang:protobuf,crypto \
		boltdb:bolt inconshreveable:muxado matttproud:protobuf_ext \
		miekg:dns mitchellh:cli mitchellh:mapstructure \
		prometheus:client_golang,client_model,procfs \
		ryanuber:columnize ugorji:go
GH_PROJECT=	circbuf:circbuf protobuf:protobuf go-metrics:go_metrics \
		go-radix:go_radix gomdb:gomdb go-checkpoint:go_checkpoint \
		go-msgpack:go_msgpack go-multierror:go_multierror \
		go-syslog:go_syslog golang-lru:golang_lru hcl:hcl \
		logutils:logutils memberlist:memberlist raft:raft \
		raft-mdb:raft_mdb serf:serf scada-client:scada yamux:yamux \
		consul-migrate:migrate net-rpc-msgpackrpc:msgpackrpc \
		raft-boltdb:boltdb crypto:crypto bolt:bolt muxado:muxado \
		golang_protobuf_extensions:protobuf_ext dns:dns cli:cli \
		mapstructure:mapstructure client_golang:client_golang \
		client_model:client_model procfs:procfs columnize:columnize \
		go:go
GH_TAGNAME=	f092b4f:circbuf 5677a0e:protobuf a54701e:go_metrics \
		0bab926:go_radix 151f2e0:gomdb 88326f6:go_checkpoint \
		71c2886:go_msgpack fcdddc3:go_multierror 42a2b57:go_syslog \
		995efda:golang_lru 513e04c:hcl 367a65d:logutils \
		6025015:memberlist a8065f2:raft 4ec3694:raft_mdb 320787d:serf \
		c26580c:scada b2e5585:yamux 4977886:migrate \
		d377902:msgpackrpc d1e82c1:boltdb 74f810a:crypto 2c04100:bolt \
		f693c7e:muxado ba7d65a:protobuf_ext bb1103f:dns 6cc8bc5:cli \
		442e588:mapstructure 38dbb2e:client_golang \
		fa8ad6f:client_model 92faa30:procfs 44cb478:columnize \
		e906e39:go


USE_RC_SUBR=	consul

USERS=		consul
GROUPS=		consul

STRIP=		# stripping can break go binaries

post-patch:
	@${MKDIR} ${WRKSRC}/src/github.com/hashicorp/consul
.for src in .travis.yml CHANGELOG.md LICENSE Makefile README.md Vagrantfile \
	api acl bench contrib command commands.go consul demo deps main.go \
	main_test.go scripts terraform test testutil tlsutil ui version.go \
	watch website
	@${MV} ${WRKSRC}/${src} \
		${WRKSRC}/src/github.com/hashicorp/consul
.endfor
	@${MKDIR} ${WRKSRC}/src/github.com/armon
	@${MKDIR} ${WRKSRC}/src/github.com/boltdb
	@${MKDIR} ${WRKSRC}/src/github.com/inconshreveable
	@${MKDIR} ${WRKSRC}/src/github.com/miekg
	@${MKDIR} ${WRKSRC}/src/github.com/mitchellh
	@${MKDIR} ${WRKSRC}/src/github.com/ryanuber
	@${MKDIR} ${WRKSRC}/src/github.com/ugorji
	@${MKDIR} ${WRKSRC}/src/github.com/golang
	@${MKDIR} ${WRKSRC}/src/github.com/matttproud
	@${MKDIR} ${WRKSRC}/src/github.com/prometheus
	@${MKDIR} ${WRKSRC}/src/golang.org/x
	@${MV} ${WRKSRC_circbuf} \
		${WRKSRC}/src/github.com/armon/circbuf
	@${MV} ${WRKSRC_go_metrics} \
		${WRKSRC}/src/github.com/armon/go-metrics
	@${MV} ${WRKSRC_go_radix} \
		${WRKSRC}/src/github.com/armon/go-radix
	@${MV} ${WRKSRC_gomdb} \
		${WRKSRC}/src/github.com/armon/gomdb
	@${MV} ${WRKSRC_protobuf} \
		${WRKSRC}/src/github.com/golang/protobuf
	@${MV} ${WRKSRC_go_msgpack} \
		${WRKSRC}/src/github.com/hashicorp/go-msgpack
	@${MV} ${WRKSRC_go_multierror} \
		${WRKSRC}/src/github.com/hashicorp/go-multierror
	@${MV} ${WRKSRC_go_checkpoint} \
		${WRKSRC}/src/github.com/hashicorp/go-checkpoint
	@${MV} ${WRKSRC_go_syslog} \
		${WRKSRC}/src/github.com/hashicorp/go-syslog
	@${MV} ${WRKSRC_golang_lru} \
		${WRKSRC}/src/github.com/hashicorp/golang-lru
	@${MV} ${WRKSRC_hcl} \
		${WRKSRC}/src/github.com/hashicorp/hcl
	@${MV} ${WRKSRC_logutils} \
		${WRKSRC}/src/github.com/hashicorp/logutils
	@${MV} ${WRKSRC_memberlist} \
		${WRKSRC}/src/github.com/hashicorp/memberlist
	@${MV} ${WRKSRC_raft} \
		${WRKSRC}/src/github.com/hashicorp/raft
	@${MV} ${WRKSRC_raft_mdb} \
		${WRKSRC}/src/github.com/hashicorp/raft-mdb
	@${MV} ${WRKSRC_serf} \
		${WRKSRC}/src/github.com/hashicorp/serf
	@${MV} ${WRKSRC_scada} \
		${WRKSRC}/src/github.com/hashicorp/scada-client
	@${MV} ${WRKSRC_yamux} \
		${WRKSRC}/src/github.com/hashicorp/yamux
	@${MV} ${WRKSRC_muxado} \
		${WRKSRC}/src/github.com/inconshreveable/muxado
	@${MV} ${WRKSRC_dns} \
		${WRKSRC}/src/github.com/miekg/dns
	@${MV} ${WRKSRC_cli} \
		${WRKSRC}/src/github.com/mitchellh/cli
	@${MV} ${WRKSRC_mapstructure} \
		${WRKSRC}/src/github.com/mitchellh/mapstructure
	@${MV} ${WRKSRC_columnize} \
		${WRKSRC}/src/github.com/ryanuber/columnize
	@${MV} ${WRKSRC_msgpackrpc} \
		${WRKSRC}/src/github.com/hashicorp/net-rpc-msgpackrpc
	@${MV} ${WRKSRC_protobuf_ext} \
		${WRKSRC}/src/github.com/matttproud/golang_protobuf_extensions
	@${MV} ${WRKSRC_client_golang} \
		${WRKSRC}/src/github.com/prometheus/client_golang
	@${MV} ${WRKSRC_client_model} \
		${WRKSRC}/src/github.com/prometheus/client_model
	@${MV} ${WRKSRC_procfs} \
		${WRKSRC}/src/github.com/prometheus/procfs
	@${MV} ${WRKSRC_boltdb} \
		${WRKSRC}/src/github.com/hashicorp/raft-boltdb
	@${MV} ${WRKSRC_bolt} \
		${WRKSRC}/src/github.com/boltdb/bolt
	@${MV} ${WRKSRC_migrate} \
		${WRKSRC}/src/github.com/hashicorp/consul-migrate
	@${MV} ${WRKSRC_crypto} \
		${WRKSRC}/src/golang.org/x/crypto

do-build:
	@cd ${WRKSRC}/src/github.com/hashicorp/consul; ${SETENV} ${BUILD_ENV} GOPATH=${WRKSRC} go build -o bin/consul

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/github.com/hashicorp/consul/bin/consul ${STAGEDIR}${PREFIX}/bin/consul
	${MKDIR} ${STAGEDIR}${DATADIR}
	cd ${WRKDIR}/dist && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}

.include <bsd.port.pre.mk>

# golang assumes that if clang is in use, it is called "clang" and not "cc". If
# it's called "cc", go fails.
.if ${COMPILER_TYPE} == clang
BUILD_ENV=	CC=clang
.endif

.include <bsd.port.post.mk>
