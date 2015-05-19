# $FreeBSD$

PORTNAME=	consul
PORTVERSION=	0.5.2
CATEGORIES=	sysutils
MASTER_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/archive/${GH_TAGNAME}.tar.gz?dummy=/:group1 \
		https://github.com/armon/circbuf/archive/f092b4f207b6e5cce0569056fba9e1a2735cb6cf.tar.gz?dummy=/:group2 \
		https://github.com/golang/protobuf/archive/5677a0e3d5e89854c9974e1256839ee23f8233ca.tar.gz?dummy=/:group3 \
	 	https://github.com/armon/go-metrics/archive/a54701ebec11868993bc198c3f315353e9de2ed6.tar.gz?dummy=/:group4 \
		https://github.com/armon/go-radix/archive/0bab926c3433cfd6490c6d3c504a7b471362390c.tar.gz?dummy=/:group5 \
		https://github.com/armon/gomdb/archive/151f2e08ef45cb0e57d694b2562f351955dff572.tar.gz?dummy=/:group6 \
		https://github.com/hashicorp/go-checkpoint/archive/88326f6851319068e7b34981032128c0b1a6524d.tar.gz?dummy=/:group7 \
		https://github.com/hashicorp/go-msgpack/archive/71c2886f5a673a35f909803f38ece5810165097b.tar.gz?dummy=/:group8 \
		https://github.com/hashicorp/go-multierror/archive/fcdddc395df1ddf4247c69bd436e84cfa0733f7e.tar.gz?dummy=/:group9 \
		https://github.com/hashicorp/go-syslog/archive/42a2b573b664dbf281bd48c3cc12c086b17a39ba.tar.gz?dummy=/:group10 \
		https://github.com/hashicorp/golang-lru/archive/995efda3e073b6946b175ed93901d729ad47466a.tar.gz?dummy=/:group11 \
		https://github.com/hashicorp/hcl/archive/513e04c400ee2e81e97f5e011c08fb42c6f69b84.tar.gz?dummy=/:group12 \
		https://github.com/hashicorp/logutils/archive/367a65d59043b4f846d179341d138f01f988c186.tar.gz?dummy=/:group13 \
		https://github.com/hashicorp/memberlist/archive/6025015f2dc659ca2c735112d37e753bda6e329d.tar.gz?dummy=/:group14 \
		https://github.com/hashicorp/raft/archive/a8065f298505708bf60f518c09178149f3c06f21.tar.gz?dummy=/:group15 \
		https://github.com/hashicorp/raft-mdb/archive/4ec3694ffbc74d34f7532e70ef2e9c3546a0c0b0.tar.gz?dummy=/:group16 \
		https://github.com/hashicorp/serf/archive/320787d8567bdcf9d77f8c5d65031fcb19e71ebc.tar.gz?dummy=/:group17 \
		https://github.com/hashicorp/scada-client/archive/c26580cfe35393f6f4bf1b9ba55e6afe33176bae.tar.gz?dummy=/:group18 \
		https://github.com/hashicorp/yamux/archive/b2e55852ddaf823a85c67f798080eb7d08acd71d.tar.gz?dummy=/:group19 \
		https://github.com/inconshreveable/muxado/archive/f693c7e88ba316d1a0ae3e205e22a01aa3ec2848.tar.gz?dummy=/:group20 \
		https://github.com/miekg/dns/archive/bb1103f648f811d2018d4bedcb2d4b2bce34a0f1.tar.gz?dummy=/:group21 \
		https://github.com/mitchellh/cli/archive/6cc8bc522243675a2882b81662b0b0d2e04b99c9.tar.gz?dummy=/:group22 \
		https://github.com/mitchellh/mapstructure/archive/442e588f213303bec7936deba67901f8fc8f18b1.tar.gz?dummy=/:group23 \
		https://github.com/ryanuber/columnize/archive/44cb4788b2ec3c3d158dd3d1b50aba7d66f4b59a.tar.gz?dummy=/:group24 \
		https://github.com/ugorji/go/archive/e906e395b9d45d3230e800c8ad1f92f99764e753.tar.gz?dummy=/:group25 \
		https://github.com/hashicorp/net-rpc-msgpackrpc/archive/d377902b7aba83dd3895837b902f6cf3f71edcb2.tar.gz?dummy=/:group26 \
		https://github.com/matttproud/golang_protobuf_extensions/archive/ba7d65ac66e9da93a714ca18f6d1bc7a0c09100c.tar.gz?dummy=/:group27 \
		https://github.com/prometheus/client_golang/archive/38dbb2e26868d15db0275ddbaac0cbe450ec03de.tar.gz?dummy=/:group28 \
		https://github.com/prometheus/client_model/archive/fa8ad6fec33561be4280a8f0514318c79d7f6cb6.tar.gz?dummy=/:group29 \
		https://github.com/prometheus/procfs/archive/92faa308558161acab0ada1db048e9996ecec160.tar.gz?dummy=/:group30 \
		https://dl.bintray.com/mitchellh/consul/:group31 \
		https://github.com/hashicorp/raft-boltdb/archive/d1e82c1ec3f15ee991f7cc7ffd5b67ff6f5bbaee.tar.gz?dummy=/:group32 \
		https://github.com/boltdb/bolt/archive/2c04100eb9793f2b8541d243494e2909d2112325.tar.gz?dummy=/:group33 \
		https://github.com/hashicorp/consul-migrate/archive/4977886fc950a0db1a6f0bbadca56dfabf170f9c.tar.gz?dummy=/:group34 \
		https://github.com/golang/crypto/archive/74f810a0152f4c50a16195f6b9ff44afc35594e8.tar.gz?dummy=/:group35
DISTFILES=	consul-${PORTVERSION}.tar.gz:group1 \
		armon_circbuf_f092b4f207b6e5cce0569056fba9e1a2735cb6cf.tar.gz:group2 \
		golang_protobuf_5677a0e3d5e89854c9974e1256839ee23f8233ca.tar.gz:group3 \
		armon_go-metrics_a54701ebec11868993bc198c3f315353e9de2ed6.tar.gz:group4 \
		armon_go-radix_0bab926c3433cfd6490c6d3c504a7b471362390c.tar.gz:group5 \
		armon_gomdb_151f2e08ef45cb0e57d694b2562f351955dff572.tar.gz:group6 \
		hashicorp_go-checkpoint_88326f6851319068e7b34981032128c0b1a6524d.tar.gz:group7 \
		hashicorp_go-msgpack_71c2886f5a673a35f909803f38ece5810165097b.tar.gz:group8 \
		hashicorp_go-multierror_fcdddc395df1ddf4247c69bd436e84cfa0733f7e.tar.gz:group9 \
		hashicorp_go-syslog_42a2b573b664dbf281bd48c3cc12c086b17a39ba.tar.gz:group10 \
		hashicorp_golang-lru_995efda3e073b6946b175ed93901d729ad47466a.tar.gz:group11 \
		hashicorp_hcl_513e04c400ee2e81e97f5e011c08fb42c6f69b84.tar.gz:group12 \
		hashicorp_logutils_367a65d59043b4f846d179341d138f01f988c186.tar.gz:group13 \
		hashicorp_memberlist_6025015f2dc659ca2c735112d37e753bda6e329d.tar.gz:group14 \
		hashicorp_raft_a8065f298505708bf60f518c09178149f3c06f21.tar.gz:group15 \
		hashicorp_raft-mdb_4ec3694ffbc74d34f7532e70ef2e9c3546a0c0b0.tar.gz:group16 \
		hashicorp_serf_320787d8567bdcf9d77f8c5d65031fcb19e71ebc.tar.gz:group17 \
		hashicorp_scada-client_c26580cfe35393f6f4bf1b9ba55e6afe33176bae.tar.gz:group18 \
		hashicorp_yamux_b2e55852ddaf823a85c67f798080eb7d08acd71d.tar.gz:group19 \
		inconshreveable_muxado_f693c7e88ba316d1a0ae3e205e22a01aa3ec2848.tar.gz:group20 \
		miekg_dns_bb1103f648f811d2018d4bedcb2d4b2bce34a0f1.tar.gz:group21 \
		mitchellh_cli_6cc8bc522243675a2882b81662b0b0d2e04b99c9.tar.gz:group22 \
		mitchellh_mapstructure_442e588f213303bec7936deba67901f8fc8f18b1.tar.gz:group23 \
		ryanuber_columnize_44cb4788b2ec3c3d158dd3d1b50aba7d66f4b59a.tar.gz:group24 \
		ugorji_go_e906e395b9d45d3230e800c8ad1f92f99764e753.tar.gz:group25 \
		net-rpc-msgpackrpc_d377902b7aba83dd3895837b902f6cf3f71edcb2.tar.gz:group26 \
		golang_protobuf_extensions_ba7d65ac66e9da93a714ca18f6d1bc7a0c09100c.tar.gz:group27 \
		prometheus_client_golang_38dbb2e26868d15db0275ddbaac0cbe450ec03de.tar.gz:group28 \
		prometheus_client_model_fa8ad6fec33561be4280a8f0514318c79d7f6cb6.tar.gz:group29 \
		prometheus_procfs_92faa308558161acab0ada1db048e9996ecec160.tar.gz:group30 \
		${PORTVERSION}_web_ui.zip:group31 \
		hashicorp_raft-boltdb_d1e82c1ec3f15ee991f7cc7ffd5b67ff6f5bbaee.tar.gz:group32 \
		boltdb_bolt_2c04100eb9793f2b8541d243494e2909d2112325.tar.gz:group33 \
		hashicorp_consul-migrate_4977886fc950a0db1a6f0bbadca56dfabf170f9c.tar.gz:group34 \
		golang_crypto_74f810a0152f4c50a16195f6b9ff44afc35594e8.tar.gz:group35

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Service discovery and configuration made easy

LICENSE=	MPL

BUILD_DEPENDS=	${LOCALBASE}/bin/go:${PORTSDIR}/lang/go

USES=		compiler

USE_GITHUB=	yes
GH_ACCOUNT=	hashicorp
GH_TAGNAME=	v${PORTVERSION}

USE_RC_SUBR=	consul

USERS=		consul
GROUPS=		consul

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

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
	@${MV} ${WRKDIR}/circbuf-f092b4f207b6e5cce0569056fba9e1a2735cb6cf \
		${WRKSRC}/src/github.com/armon/circbuf
	@${MV} ${WRKDIR}/go-metrics-a54701ebec11868993bc198c3f315353e9de2ed6 \
		${WRKSRC}/src/github.com/armon/go-metrics
	@${MV} ${WRKDIR}/go-radix-0bab926c3433cfd6490c6d3c504a7b471362390c \
		${WRKSRC}/src/github.com/armon/go-radix
	@${MV} ${WRKDIR}/gomdb-151f2e08ef45cb0e57d694b2562f351955dff572 \
		${WRKSRC}/src/github.com/armon/gomdb
	@${MV} ${WRKDIR}/protobuf-5677a0e3d5e89854c9974e1256839ee23f8233ca \
		${WRKSRC}/src/github.com/golang/protobuf
	@${MV} ${WRKDIR}/go-msgpack-71c2886f5a673a35f909803f38ece5810165097b \
		${WRKSRC}/src/github.com/hashicorp/go-msgpack
	@${MV} ${WRKDIR}/go-multierror-fcdddc395df1ddf4247c69bd436e84cfa0733f7e \
		${WRKSRC}/src/github.com/hashicorp/go-multierror
	@${MV} ${WRKDIR}/go-checkpoint-88326f6851319068e7b34981032128c0b1a6524d \
		${WRKSRC}/src/github.com/hashicorp/go-checkpoint
	@${MV} ${WRKDIR}/go-syslog-42a2b573b664dbf281bd48c3cc12c086b17a39ba \
		${WRKSRC}/src/github.com/hashicorp/go-syslog
	@${MV} ${WRKDIR}/golang-lru-995efda3e073b6946b175ed93901d729ad47466a \
		${WRKSRC}/src/github.com/hashicorp/golang-lru
	@${MV} ${WRKDIR}/hcl-513e04c400ee2e81e97f5e011c08fb42c6f69b84 \
		${WRKSRC}/src/github.com/hashicorp/hcl
	@${MV} ${WRKDIR}/logutils-367a65d59043b4f846d179341d138f01f988c186 \
		${WRKSRC}/src/github.com/hashicorp/logutils
	@${MV} ${WRKDIR}/memberlist-6025015f2dc659ca2c735112d37e753bda6e329d \
		${WRKSRC}/src/github.com/hashicorp/memberlist
	@${MV} ${WRKDIR}/raft-a8065f298505708bf60f518c09178149f3c06f21 \
		${WRKSRC}/src/github.com/hashicorp/raft
	@${MV} ${WRKDIR}/raft-mdb-4ec3694ffbc74d34f7532e70ef2e9c3546a0c0b0 \
		${WRKSRC}/src/github.com/hashicorp/raft-mdb
	@${MV} ${WRKDIR}/serf-320787d8567bdcf9d77f8c5d65031fcb19e71ebc \
		${WRKSRC}/src/github.com/hashicorp/serf
	@${MV} ${WRKDIR}/scada-client-c26580cfe35393f6f4bf1b9ba55e6afe33176bae \
		${WRKSRC}/src/github.com/hashicorp/scada-client
	@${MV} ${WRKDIR}/yamux-b2e55852ddaf823a85c67f798080eb7d08acd71d \
		${WRKSRC}/src/github.com/hashicorp/yamux
	@${MV} ${WRKDIR}/muxado-f693c7e88ba316d1a0ae3e205e22a01aa3ec2848 \
		${WRKSRC}/src/github.com/inconshreveable/muxado
	@${MV} ${WRKDIR}/dns-bb1103f648f811d2018d4bedcb2d4b2bce34a0f1 \
		${WRKSRC}/src/github.com/miekg/dns
	@${MV} ${WRKDIR}/cli-6cc8bc522243675a2882b81662b0b0d2e04b99c9 \
		${WRKSRC}/src/github.com/mitchellh/cli
	@${MV} ${WRKDIR}/mapstructure-442e588f213303bec7936deba67901f8fc8f18b1 \
		${WRKSRC}/src/github.com/mitchellh/mapstructure
	@${MV} ${WRKDIR}/columnize-44cb4788b2ec3c3d158dd3d1b50aba7d66f4b59a \
		${WRKSRC}/src/github.com/ryanuber/columnize
	@${MV} ${WRKDIR}/net-rpc-msgpackrpc-d377902b7aba83dd3895837b902f6cf3f71edcb2 \
		${WRKSRC}/src/github.com/hashicorp/net-rpc-msgpackrpc
	@${MV} ${WRKDIR}/golang_protobuf_extensions-ba7d65ac66e9da93a714ca18f6d1bc7a0c09100c \
		${WRKSRC}/src/github.com/matttproud/golang_protobuf_extensions
	@${MV} ${WRKDIR}/client_golang-38dbb2e26868d15db0275ddbaac0cbe450ec03de \
		${WRKSRC}/src/github.com/prometheus/client_golang
	@${MV} ${WRKDIR}/client_model-fa8ad6fec33561be4280a8f0514318c79d7f6cb6 \
		${WRKSRC}/src/github.com/prometheus/client_model
	@${MV} ${WRKDIR}/procfs-92faa308558161acab0ada1db048e9996ecec160 \
		${WRKSRC}/src/github.com/prometheus/procfs
	@${MV} ${WRKDIR}/raft-boltdb-d1e82c1ec3f15ee991f7cc7ffd5b67ff6f5bbaee \
		${WRKSRC}/src/github.com/hashicorp/raft-boltdb
	@${MV} ${WRKDIR}/bolt-2c04100eb9793f2b8541d243494e2909d2112325 \
		${WRKSRC}/src/github.com/boltdb/bolt
	@${MV} ${WRKDIR}/consul-migrate-4977886fc950a0db1a6f0bbadca56dfabf170f9c \
		${WRKSRC}/src/github.com/hashicorp/consul-migrate
	@${MV} ${WRKDIR}/crypto-74f810a0152f4c50a16195f6b9ff44afc35594e8 \
		${WRKSRC}/src/golang.org/x/crypto

do-build:
	@cd ${WRKSRC}/src/github.com/hashicorp/consul; ${SETENV} ${BUILD_ENV} GOPATH=${WRKSRC} go build -o bin/consul

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/github.com/hashicorp/consul/bin/consul ${STAGEDIR}${PREFIX}/bin/consul
	${MKDIR} ${STAGEDIR}${DATADIR}
	cd ${WRKDIR}/dist && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD && ${OSVERSION} < 900044 && ${ARCH} == i386
BROKEN=		Does not build
.endif

# golang assumes that if clang is in use, it is called "clang" and not "cc". If
# it's called "cc", go fails.
.if ${COMPILER_TYPE} == clang
BUILD_ENV=	CC=clang
.endif

.include <bsd.port.post.mk>
