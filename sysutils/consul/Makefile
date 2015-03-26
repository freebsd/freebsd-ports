# $FreeBSD$

PORTNAME=	consul
PORTVERSION=	0.4.1
CATEGORIES=	sysutils
MASTER_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/archive/${GH_TAGNAME}.tar.gz?dummy=/:group1 \
		https://github.com/armon/circbuf/archive/f092b4f207b6e5cce0569056fba9e1a2735cb6cf.tar.gz?dummy=/:group2 \
		https://github.com/armon/consul-api/archive/1b81c8e0c4cbf1d382310e4c0dc11221632e79d1.tar.gz?dummy=/:group3 \
		https://github.com/armon/go-metrics/archive/2b75159ce5d3641fb35b5a159cff309ac3cf4177.tar.gz?dummy=/:group4 \
		https://github.com/armon/go-radix/archive/b045fc0ad3587e8620fb42a0dea882cf8c08aef9.tar.gz?dummy=/:group5 \
		https://github.com/armon/gomdb/archive/a8e036c4dabe7437014ecf9dbc03c6f6f0766ef8.tar.gz?dummy=/:group6 \
		https://github.com/hashicorp/go-checkpoint/archive/89ef2a697dd8cdb4623097d5bb9acdb19a470767.tar.gz?dummy=/:group7 \
		https://github.com/hashicorp/go-msgpack/archive/71c2886f5a673a35f909803f38ece5810165097b.tar.gz?dummy=/:group8 \
		https://github.com/hashicorp/go-syslog/archive/ac3963b72ac367e48b1e68a831e62b93fb69091c.tar.gz?dummy=/:group9 \
		https://github.com/hashicorp/golang-lru/archive/253b2dc1ca8bae42c3b5b6e53dd2eab1a7551116.tar.gz?dummy=/:group10 \
		https://github.com/hashicorp/hcl/archive/e51eabcdf801f663738fa12f4340fbad13062738.tar.gz?dummy=/:group11 \
		https://github.com/hashicorp/logutils/archive/23b0af5510a2d1442103ef83ffcf53eb82f3debc.tar.gz?dummy=/:group12 \
		https://github.com/hashicorp/memberlist/archive/16d947e2d4b3f1fe508ee1d9b6ec34b8fd2e96d8.tar.gz?dummy=/:group13 \
		https://github.com/hashicorp/raft/archive/cc9710ab540985954a67c108f414aa3152f5916f.tar.gz?dummy=/:group14 \
		https://github.com/hashicorp/raft-mdb/archive/6f52d0ce62a34e3f5bd29aa4d7068030d700d94a.tar.gz?dummy=/:group15 \
		https://github.com/hashicorp/serf/archive/0479bc1b942fd84205587f7e73867ac78809966b.tar.gz?dummy=/:group16 \
		https://github.com/hashicorp/terraform/archive/2d117326edb33b7155d1ec9d0ab9d3542ba1b230.tar.gz?dummy=/:group17 \
		https://github.com/hashicorp/yamux/archive/9feabe6854fadca1abec9cd3bd2a613fe9a34000.tar.gz?dummy=/:group18 \
		https://github.com/inconshreveable/muxado/archive/f693c7e88ba316d1a0ae3e205e22a01aa3ec2848.tar.gz?dummy=/:group19 \
		https://github.com/miekg/dns/archive/dc30c7cd4ed2fc8af73d49da4ee285404958b8bd.tar.gz?dummy=/:group20 \
		https://github.com/mitchellh/cli/archive/e3c2e3d39391e9beb9660ccd6b4bd9a2f38dd8a0.tar.gz?dummy=/:group21 \
		https://github.com/mitchellh/mapstructure/archive/740c764bc6149d3f1806231418adb9f52c11bcbf.tar.gz?dummy=/:group22 \
		https://github.com/ryanuber/columnize/archive/44cb4788b2ec3c3d158dd3d1b50aba7d66f4b59a.tar.gz?dummy=/:group23 \
		https://github.com/ugorji/go/archive/e906e395b9d45d3230e800c8ad1f92f99764e753.tar.gz?dummy=/:group24 \
		https://dl.bintray.com/mitchellh/consul/:group25
DISTFILES=	consul-0.4.1.tar.gz:group1 \
		armon_circbuf_f092b4f207b6e5cce0569056fba9e1a2735cb6cf.tar.gz:group2 \
		armon_consul-api_1b81c8e0c4cbf1d382310e4c0dc11221632e79d1.tar.gz:group3 \
		armon_go-metrics_2b75159ce5d3641fb35b5a159cff309ac3cf4177.tar.gz:group4 \
		armon_go-radix_b045fc0ad3587e8620fb42a0dea882cf8c08aef9.tar.gz:group5 \
		armon_gomdb_a8e036c4dabe7437014ecf9dbc03c6f6f0766ef8.tar.gz:group6 \
		hashicorp_go-checkpoint_89ef2a697dd8cdb4623097d5bb9acdb19a470767.tar.gz:group7 \
		hashicorp_go-msgpack_71c2886f5a673a35f909803f38ece5810165097b.tar.gz:group8 \
		hashicorp_go-syslog_ac3963b72ac367e48b1e68a831e62b93fb69091c.tar.gz:group9 \
		hashicorp_golang-lru_253b2dc1ca8bae42c3b5b6e53dd2eab1a7551116.tar.gz:group10 \
		hashicorp_hcl_e51eabcdf801f663738fa12f4340fbad13062738.tar.gz:group11 \
		hashicorp_logutils_23b0af5510a2d1442103ef83ffcf53eb82f3debc.tar.gz:group12 \
		hashicorp_memberlist_16d947e2d4b3f1fe508ee1d9b6ec34b8fd2e96d8.tar.gz:group13 \
		hashicorp_raft_cc9710ab540985954a67c108f414aa3152f5916f.tar.gz:group14 \
		hashicorp_raft-mdb_6f52d0ce62a34e3f5bd29aa4d7068030d700d94a.tar.gz:group15 \
		hashicorp_serf_0479bc1b942fd84205587f7e73867ac78809966b.tar.gz:group16 \
		hashicorp_terraform_2d117326edb33b7155d1ec9d0ab9d3542ba1b230.tar.gz:group17 \
		hashicorp_yamux_9feabe6854fadca1abec9cd3bd2a613fe9a34000.tar.gz:group18 \
		inconshreveable_muxado_f693c7e88ba316d1a0ae3e205e22a01aa3ec2848.tar.gz:group19 \
		miekg_dns_dc30c7cd4ed2fc8af73d49da4ee285404958b8bd.tar.gz:group20 \
		mitchellh_cli_e3c2e3d39391e9beb9660ccd6b4bd9a2f38dd8a0.tar.gz:group21 \
		mitchellh_mapstructure_740c764bc6149d3f1806231418adb9f52c11bcbf.tar.gz:group22 \
		ryanuber_columnize_44cb4788b2ec3c3d158dd3d1b50aba7d66f4b59a.tar.gz:group23 \
		ugorji_go_e906e395b9d45d3230e800c8ad1f92f99764e753.tar.gz:group24 \
		0.4.1_web_ui.zip:group25

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Service discovery and configuration made easy

LICENSE=	MPL

BUILD_DEPENDS=	${LOCALBASE}/bin/go:${PORTSDIR}/lang/go

USES=		compiler

USE_GITHUB=	yes
GH_ACCOUNT=	hashicorp
GH_COMMIT=	aaddfa2
GH_TAGNAME=	v${PORTVERSION}

USE_RC_SUBR=	consul

USERS=		consul
GROUPS=		consul

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

STRIP=		# stripping can break go binaries

post-patch:
	@${MKDIR} ${WRKSRC}/src/github.com/hashicorp/consul
.for src in .gitignore .travis.yml CHANGELOG.md LICENSE Makefile README.md \
		Vagrantfile acl bench command commands.go consul demo deps \
		main.go main_test.go scripts terraform test testutil ui \
		version.go watch website
	@${MV} ${WRKSRC}/${src} \
		${WRKSRC}/src/github.com/hashicorp/consul
.endfor
	@${MKDIR} ${WRKSRC}/src/github.com/armon
	@${MKDIR} ${WRKSRC}/src/github.com/inconshreveable
	@${MKDIR} ${WRKSRC}/src/github.com/miekg
	@${MKDIR} ${WRKSRC}/src/github.com/mitchellh
	@${MKDIR} ${WRKSRC}/src/github.com/ryanuber
	@${MKDIR} ${WRKSRC}/src/github.com/ugorji
	@${MV} ${WRKDIR}/circbuf-f092b4f207b6e5cce0569056fba9e1a2735cb6cf \
		${WRKSRC}/src/github.com/armon/circbuf
	@${MV} ${WRKDIR}/consul-api-1b81c8e0c4cbf1d382310e4c0dc11221632e79d1 \
		${WRKSRC}/src/github.com/armon/consul-api
	@${MV} ${WRKDIR}/go-metrics-2b75159ce5d3641fb35b5a159cff309ac3cf4177 \
		${WRKSRC}/src/github.com/armon/go-metrics
	@${MV} ${WRKDIR}/go-radix-b045fc0ad3587e8620fb42a0dea882cf8c08aef9 \
		${WRKSRC}/src/github.com/armon/go-radix
	@${MV} ${WRKDIR}/gomdb-a8e036c4dabe7437014ecf9dbc03c6f6f0766ef8 \
		${WRKSRC}/src/github.com/armon/gomdb
	@${MV} ${WRKDIR}/go-msgpack-71c2886f5a673a35f909803f38ece5810165097b \
		${WRKSRC}/src/github.com/hashicorp/go-msgpack
	@${MV} ${WRKDIR}/go-checkpoint-89ef2a697dd8cdb4623097d5bb9acdb19a470767 \
		${WRKSRC}/src/github.com/hashicorp/go-checkpoint
	@${MV} ${WRKDIR}/go-syslog-ac3963b72ac367e48b1e68a831e62b93fb69091c \
		${WRKSRC}/src/github.com/hashicorp/go-syslog
	@${MV} ${WRKDIR}/golang-lru-253b2dc1ca8bae42c3b5b6e53dd2eab1a7551116 \
		${WRKSRC}/src/github.com/hashicorp/golang-lru
	@${MV} ${WRKDIR}/hcl-e51eabcdf801f663738fa12f4340fbad13062738 \
		${WRKSRC}/src/github.com/hashicorp/hcl
	@${MV} ${WRKDIR}/logutils-23b0af5510a2d1442103ef83ffcf53eb82f3debc \
		${WRKSRC}/src/github.com/hashicorp/logutils
	@${MV} ${WRKDIR}/memberlist-16d947e2d4b3f1fe508ee1d9b6ec34b8fd2e96d8 \
		${WRKSRC}/src/github.com/hashicorp/memberlist
	@${MV} ${WRKDIR}/raft-cc9710ab540985954a67c108f414aa3152f5916f \
		${WRKSRC}/src/github.com/hashicorp/raft
	@${MV} ${WRKDIR}/raft-mdb-6f52d0ce62a34e3f5bd29aa4d7068030d700d94a \
		${WRKSRC}/src/github.com/hashicorp/raft-mdb
	@${MV} ${WRKDIR}/serf-0479bc1b942fd84205587f7e73867ac78809966b \
		${WRKSRC}/src/github.com/hashicorp/serf
	@${MV} ${WRKDIR}/terraform-2d117326edb33b7155d1ec9d0ab9d3542ba1b230 \
		${WRKSRC}/src/github.com/hashicorp/terraform
	@${MV} ${WRKDIR}/yamux-9feabe6854fadca1abec9cd3bd2a613fe9a34000 \
		${WRKSRC}/src/github.com/hashicorp/yamux
	@${MV} ${WRKDIR}/muxado-f693c7e88ba316d1a0ae3e205e22a01aa3ec2848 \
		${WRKSRC}/src/github.com/inconshreveable/muxado
	@${MV} ${WRKDIR}/dns-dc30c7cd4ed2fc8af73d49da4ee285404958b8bd \
		${WRKSRC}/src/github.com/miekg/dns
	@${MV} ${WRKDIR}/cli-e3c2e3d39391e9beb9660ccd6b4bd9a2f38dd8a0 \
		${WRKSRC}/src/github.com/mitchellh/cli
	@${MV} ${WRKDIR}/mapstructure-740c764bc6149d3f1806231418adb9f52c11bcbf \
		${WRKSRC}/src/github.com/mitchellh/mapstructure
	@${MV} ${WRKDIR}/columnize-44cb4788b2ec3c3d158dd3d1b50aba7d66f4b59a \
		${WRKSRC}/src/github.com/ryanuber/columnize

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
