# $FreeBSD$

PORTNAME=	consul
PORTVERSION=	0.5.0
CATEGORIES=	sysutils
MASTER_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/archive/${GH_TAGNAME}.tar.gz?dummy=/:group1 \
		https://github.com/armon/circbuf/archive/f092b4f207b6e5cce0569056fba9e1a2735cb6cf.tar.gz?dummy=/:group2 \
		https://github.com/golang/protobuf/archive/5677a0e3d5e89854c9974e1256839ee23f8233ca.tar.gz?dummy=/:group3 \
		https://github.com/armon/go-metrics/archive/88b7658f24511c4b885942b26e9ea7a61ee37ebc.tar.gz?dummy=/:group4 \
		https://github.com/armon/go-radix/archive/e39d623f12e8e41c7b5529e9a9dd67a1e2261f80.tar.gz?dummy=/:group5 \
		https://github.com/armon/gomdb/archive/151f2e08ef45cb0e57d694b2562f351955dff572.tar.gz?dummy=/:group6 \
		https://github.com/hashicorp/go-checkpoint/archive/88326f6851319068e7b34981032128c0b1a6524d.tar.gz?dummy=/:group7 \
		https://github.com/hashicorp/go-msgpack/archive/71c2886f5a673a35f909803f38ece5810165097b.tar.gz?dummy=/:group8 \
		https://github.com/hashicorp/go-multierror/archive/fcdddc395df1ddf4247c69bd436e84cfa0733f7e.tar.gz?dummy=/:group9 \
		https://github.com/hashicorp/go-syslog/archive/42a2b573b664dbf281bd48c3cc12c086b17a39ba.tar.gz?dummy=/:group10 \
		https://github.com/hashicorp/golang-lru/archive/f09f965649501e2ac1b0c310c632a7bebdbdc1d4.tar.gz?dummy=/:group11 \
		https://github.com/hashicorp/hcl/archive/513e04c400ee2e81e97f5e011c08fb42c6f69b84.tar.gz?dummy=/:group12 \
		https://github.com/hashicorp/logutils/archive/23b0af5510a2d1442103ef83ffcf53eb82f3debc.tar.gz?dummy=/:group13 \
		https://github.com/hashicorp/memberlist/archive/9a1e242e454d2443df330bdd51a436d5a9058fc4.tar.gz?dummy=/:group14 \
		https://github.com/hashicorp/raft/archive/a88bfa8385bc52c1f25d0fc02d1b55a2708d04ab.tar.gz?dummy=/:group15 \
		https://github.com/hashicorp/raft-mdb/archive/4ec3694ffbc74d34f7532e70ef2e9c3546a0c0b0.tar.gz?dummy=/:group16 \
		https://github.com/hashicorp/serf/archive/cc95df950d69acfd117128c98a3bc6b64c1da3fd.tar.gz?dummy=/:group17 \
		https://github.com/hashicorp/scada-client/archive/c26580cfe35393f6f4bf1b9ba55e6afe33176bae.tar.gz?dummy=/:group18 \
		https://github.com/hashicorp/yamux/archive/b4f943b3f25da97dec8e26bee1c3269019de070d.tar.gz?dummy=/:group19 \
		https://github.com/inconshreveable/muxado/archive/f693c7e88ba316d1a0ae3e205e22a01aa3ec2848.tar.gz?dummy=/:group20 \
		https://github.com/miekg/dns/archive/64fea017a260b4ccbfbb3f60ab027e0398cd8f6f.tar.gz?dummy=/:group21 \
		https://github.com/mitchellh/cli/archive/e3c2e3d39391e9beb9660ccd6b4bd9a2f38dd8a0.tar.gz?dummy=/:group22 \
		https://github.com/mitchellh/mapstructure/archive/740c764bc6149d3f1806231418adb9f52c11bcbf.tar.gz?dummy=/:group23 \
		https://github.com/ryanuber/columnize/archive/44cb4788b2ec3c3d158dd3d1b50aba7d66f4b59a.tar.gz?dummy=/:group24 \
		https://github.com/ugorji/go/archive/e906e395b9d45d3230e800c8ad1f92f99764e753.tar.gz?dummy=/:group25 \
		https://github.com/hashicorp/net-rpc-msgpackrpc/archive/d377902b7aba83dd3895837b902f6cf3f71edcb2.tar.gz?dummy=/:group26 \
		https://github.com/matttproud/golang_protobuf_extensions/archive/ba7d65ac66e9da93a714ca18f6d1bc7a0c09100c.tar.gz?dummy=/:group27 \
		https://github.com/prometheus/client_golang/archive/38dbb2e26868d15db0275ddbaac0cbe450ec03de.tar.gz?dummy=/:group28 \
		https://github.com/prometheus/client_model/archive/fa8ad6fec33561be4280a8f0514318c79d7f6cb6.tar.gz?dummy=/:group29 \
		https://github.com/prometheus/procfs/archive/92faa308558161acab0ada1db048e9996ecec160.tar.gz?dummy=/:group30 \
		https://dl.bintray.com/mitchellh/consul/:group31
DISTFILES=	consul-${PORTVERSION}.tar.gz:group1 \
		armon_circbuf_f092b4f207b6e5cce0569056fba9e1a2735cb6cf.tar.gz:group2 \
		golang_protobuf_5677a0e3d5e89854c9974e1256839ee23f8233ca.tar.gz:group3 \
		armon_go-metrics_88b7658f24511c4b885942b26e9ea7a61ee37ebc.tar.gz:group4 \
		armon_go-radix_e39d623f12e8e41c7b5529e9a9dd67a1e2261f80.tar.gz:group5 \
		armon_gomdb_151f2e08ef45cb0e57d694b2562f351955dff572.tar.gz:group6 \
		hashicorp_go-checkpoint_88326f6851319068e7b34981032128c0b1a6524d.tar.gz:group7 \
		hashicorp_go-msgpack_71c2886f5a673a35f909803f38ece5810165097b.tar.gz:group8 \
		hashicorp_go-multierror_fcdddc395df1ddf4247c69bd436e84cfa0733f7e.tar.gz:group9 \
		hashicorp_go-syslog_42a2b573b664dbf281bd48c3cc12c086b17a39ba.tar.gz:group10 \
		hashicorp_golang-lru_f09f965649501e2ac1b0c310c632a7bebdbdc1d4.tar.gz:group11 \
		hashicorp_hcl_513e04c400ee2e81e97f5e011c08fb42c6f69b84.tar.gz:group12 \
		hashicorp_logutils_23b0af5510a2d1442103ef83ffcf53eb82f3debc.tar.gz:group13 \
		hashicorp_memberlist_9a1e242e454d2443df330bdd51a436d5a9058fc4.tar.gz:group14 \
		hashicorp_raft_a88bfa8385bc52c1f25d0fc02d1b55a2708d04ab.tar.gz:group15 \
		hashicorp_raft-mdb_4ec3694ffbc74d34f7532e70ef2e9c3546a0c0b0.tar.gz:group16 \
		hashicorp_serf_cc95df950d69acfd117128c98a3bc6b64c1da3fd.tar.gz:group17 \
		hashicorp_scada-client_c26580cfe35393f6f4bf1b9ba55e6afe33176bae.tar.gz:group18 \
		hashicorp_yamux_b4f943b3f25da97dec8e26bee1c3269019de070d.tar.gz:group19 \
		inconshreveable_muxado_f693c7e88ba316d1a0ae3e205e22a01aa3ec2848.tar.gz:group20 \
		miekg_dns_64fea017a260b4ccbfbb3f60ab027e0398cd8f6f.tar.gz:group21 \
		mitchellh_cli_e3c2e3d39391e9beb9660ccd6b4bd9a2f38dd8a0.tar.gz:group22 \
		mitchellh_mapstructure_740c764bc6149d3f1806231418adb9f52c11bcbf.tar.gz:group23 \
		ryanuber_columnize_44cb4788b2ec3c3d158dd3d1b50aba7d66f4b59a.tar.gz:group24 \
		ugorji_go_e906e395b9d45d3230e800c8ad1f92f99764e753.tar.gz:group25 \
		net-rpc-msgpackrpc_d377902b7aba83dd3895837b902f6cf3f71edcb2.tar.gz:group26 \
		golang_protobuf_extensions_ba7d65ac66e9da93a714ca18f6d1bc7a0c09100c.tar.gz:group27 \
		prometheus_client_golang_38dbb2e26868d15db0275ddbaac0cbe450ec03de.tar.gz:group28 \
		prometheus_client_model_fa8ad6fec33561be4280a8f0514318c79d7f6cb6.tar.gz:group29 \
		prometheus_procfs_92faa308558161acab0ada1db048e9996ecec160.tar.gz:group30 \
		${PORTVERSION}_web_ui.zip:group31

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
	@${MKDIR} ${WRKSRC}/src/github.com/inconshreveable
	@${MKDIR} ${WRKSRC}/src/github.com/miekg
	@${MKDIR} ${WRKSRC}/src/github.com/mitchellh
	@${MKDIR} ${WRKSRC}/src/github.com/ryanuber
	@${MKDIR} ${WRKSRC}/src/github.com/ugorji
	@${MKDIR} ${WRKSRC}/src/github.com/golang
	@${MKDIR} ${WRKSRC}/src/github.com/matttproud
	@${MKDIR} ${WRKSRC}/src/github.com/prometheus
	@${MV} ${WRKDIR}/circbuf-f092b4f207b6e5cce0569056fba9e1a2735cb6cf \
		${WRKSRC}/src/github.com/armon/circbuf
	@${MV} ${WRKDIR}/go-metrics-88b7658f24511c4b885942b26e9ea7a61ee37ebc \
		${WRKSRC}/src/github.com/armon/go-metrics
	@${MV} ${WRKDIR}/go-radix-e39d623f12e8e41c7b5529e9a9dd67a1e2261f80 \
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
	@${MV} ${WRKDIR}/golang-lru-f09f965649501e2ac1b0c310c632a7bebdbdc1d4 \
		${WRKSRC}/src/github.com/hashicorp/golang-lru
	@${MV} ${WRKDIR}/hcl-513e04c400ee2e81e97f5e011c08fb42c6f69b84 \
		${WRKSRC}/src/github.com/hashicorp/hcl
	@${MV} ${WRKDIR}/logutils-23b0af5510a2d1442103ef83ffcf53eb82f3debc \
		${WRKSRC}/src/github.com/hashicorp/logutils
	@${MV} ${WRKDIR}/memberlist-9a1e242e454d2443df330bdd51a436d5a9058fc4 \
		${WRKSRC}/src/github.com/hashicorp/memberlist
	@${MV} ${WRKDIR}/raft-a88bfa8385bc52c1f25d0fc02d1b55a2708d04ab \
		${WRKSRC}/src/github.com/hashicorp/raft
	@${MV} ${WRKDIR}/raft-mdb-4ec3694ffbc74d34f7532e70ef2e9c3546a0c0b0 \
		${WRKSRC}/src/github.com/hashicorp/raft-mdb
	@${MV} ${WRKDIR}/serf-cc95df950d69acfd117128c98a3bc6b64c1da3fd \
		${WRKSRC}/src/github.com/hashicorp/serf
	@${MV} ${WRKDIR}/scada-client-c26580cfe35393f6f4bf1b9ba55e6afe33176bae \
		${WRKSRC}/src/github.com/hashicorp/scada-client
	@${MV} ${WRKDIR}/yamux-b4f943b3f25da97dec8e26bee1c3269019de070d \
		${WRKSRC}/src/github.com/hashicorp/yamux
	@${MV} ${WRKDIR}/muxado-f693c7e88ba316d1a0ae3e205e22a01aa3ec2848 \
		${WRKSRC}/src/github.com/inconshreveable/muxado
	@${MV} ${WRKDIR}/dns-64fea017a260b4ccbfbb3f60ab027e0398cd8f6f \
		${WRKSRC}/src/github.com/miekg/dns
	@${MV} ${WRKDIR}/cli-e3c2e3d39391e9beb9660ccd6b4bd9a2f38dd8a0 \
		${WRKSRC}/src/github.com/mitchellh/cli
	@${MV} ${WRKDIR}/mapstructure-740c764bc6149d3f1806231418adb9f52c11bcbf \
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
