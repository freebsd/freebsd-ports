# $FreeBSD$

PORTNAME=	serf
PORTVERSION=	0.6.4
DISTVERSIONPREFIX=	v
CATEGORIES=	sysutils
MASTER_SITES=	GH \
		https://github.com/armon/circbuf/archive/f092b4f207b6e5cce0569056fba9e1a2735cb6cf.tar.gz?dummy=/:group2 \
		https://github.com/armon/go-metrics/archive/eb0af217e5e9747e41dd5303755356b62d28e3ec.tar.gz?dummy=/:group3 \
		https://github.com/hashicorp/go-msgpack/archive/71c2886f5a673a35f909803f38ece5810165097b.tar.gz?dummy=/:group4 \
		https://github.com/hashicorp/go-syslog/archive/ac3963b72ac367e48b1e68a831e62b93fb69091c.tar.gz?dummy=/:group5 \
		https://github.com/hashicorp/logutils/archive/23b0af5510a2d1442103ef83ffcf53eb82f3debc.tar.gz?dummy=/:group6 \
		https://github.com/hashicorp/memberlist/archive/9a1e242e454d2443df330bdd51a436d5a9058fc4.tar.gz?dummy=/:group7 \
		https://github.com/mitchellh/mapstructure/archive/442e588f213303bec7936deba67901f8fc8f18b1.tar.gz?dummy=/:group8 \
		https://github.com/hashicorp/mdns/archive/eb98accb64ea232136b5344464ed1d66d40f6196.tar.gz?dummy=/:group9 \
		https://github.com/mitchellh/cli/archive/e3c2e3d39391e9beb9660ccd6b4bd9a2f38dd8a0.tar.gz?dummy=/:group10 \
		https://github.com/ryanuber/columnize/archive/44cb4788b2ec3c3d158dd3d1b50aba7d66f4b59a.tar.gz?dummy=/:group11 \
		https://github.com/miekg/dns/archive/b65f52f3f0dd1afa25cbbf63f8e7eb15fb5c0641.tar.gz?dummy=/:group12 \
		https://github.com/hashicorp/go.net/archive/cbad13bf000d0cbdbc71506b26e94bcc72bbe74d.tar.gz?dummy=/:group13
PKGNAMEPREFIX=	hashicorp-
DISTFILES=	${DISTNAME}.tar.gz \
		armon_circbuf_f092b4f207b6e5cce0569056fba9e1a2735cb6cf.tar.gz:group2 \
		armon_go-metrics_eb0af217e5e9747e41dd5303755356b62d28e3ec.tar.gz:group3 \
		hashicorp_go-msgpack_71c2886f5a673a35f909803f38ece5810165097b.tar.gz:group4 \
		hashicorp_go-syslog_ac3963b72ac367e48b1e68a831e62b93fb69091c.tar.gz:group5 \
		hashicorp_logutils_23b0af5510a2d1442103ef83ffcf53eb82f3debc.tar.gz:group6 \
		hashicorp_memberlist_9a1e242e454d2443df330bdd51a436d5a9058fc4.tar.gz:group7 \
		mitchellh_mapstructure_442e588f213303bec7936deba67901f8fc8f18b1.tar.gz:group8 \
		hashicorp_mdns_eb98accb64ea232136b5344464ed1d66d40f6196.tar.gz:group9 \
		mitchellh_cli_e3c2e3d39391e9beb9660ccd6b4bd9a2f38dd8a0.tar.gz:group10 \
		ryanuber_columnize_44cb4788b2ec3c3d158dd3d1b50aba7d66f4b59a.tar.gz:group11 \
		miekg_dns_b65f52f3f0dd1afa25cbbf63f8e7eb15fb5c0641.tar.gz:group12 \
		hashicorp_go.net_cbad13bf000d0cbdbc71506b26e94bcc72bbe74d.tar.gz:group13

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Service discovery and configuration made easy

LICENSE=	MPL

BUILD_DEPENDS=	${LOCALBASE}/bin/go:${PORTSDIR}/lang/go

USE_GITHUB=	yes
GH_ACCOUNT=	hashicorp

USE_RC_SUBR=	serf

USERS=		serf
GROUPS=		serf

PLIST_FILES=	bin/serf

STRIP=		# stripping can break go binaries

post-patch:
	@${MKDIR} ${WRKSRC}/src/github.com/${GH_ACCOUNT}/${PORTNAME}
.for src in .gitignore .travis.yml CHANGELOG.md LICENSE Makefile README.md \
	client command commands.go demo deps main.go main_test.go ops-misc \
	scripts serf testutil version.go website
	@${MV} ${WRKSRC}/${src} \
		${WRKSRC}/src/github.com/hashicorp/${PORTNAME}
.endfor
	@${MKDIR} ${WRKSRC}/src/github.com/armon
	@${MKDIR} ${WRKSRC}/src/github.com/mitchellh
	@${MKDIR} ${WRKSRC}/src/github.com/miekg
	@${MKDIR} ${WRKSRC}/src/github.com/ryanuber
	@${MKDIR} ${WRKSRC}/src/code.google.com/p/go.net
	@${MV} ${WRKDIR}/circbuf-f092b4f207b6e5cce0569056fba9e1a2735cb6cf \
		${WRKSRC}/src/github.com/armon/circbuf
	@${MV} ${WRKDIR}/go-metrics-eb0af217e5e9747e41dd5303755356b62d28e3ec \
		${WRKSRC}/src/github.com/armon/go-metrics
	@${MV} ${WRKDIR}/go-msgpack-71c2886f5a673a35f909803f38ece5810165097b \
		${WRKSRC}/src/github.com/hashicorp/go-msgpack
	@${MV} ${WRKDIR}/go-syslog-ac3963b72ac367e48b1e68a831e62b93fb69091c \
		${WRKSRC}/src/github.com/hashicorp/go-syslog
	@${MV} ${WRKDIR}/logutils-23b0af5510a2d1442103ef83ffcf53eb82f3debc \
		${WRKSRC}/src/github.com/hashicorp/logutils
	@${MV} ${WRKDIR}/memberlist-9a1e242e454d2443df330bdd51a436d5a9058fc4 \
		${WRKSRC}/src/github.com/hashicorp/memberlist
	@${MV} ${WRKDIR}/mapstructure-442e588f213303bec7936deba67901f8fc8f18b1 \
		${WRKSRC}/src/github.com/mitchellh/mapstructure
	@${MV} ${WRKDIR}/mdns-eb98accb64ea232136b5344464ed1d66d40f6196 \
		${WRKSRC}/src/github.com/hashicorp/mdns
	@${MV} ${WRKDIR}/cli-e3c2e3d39391e9beb9660ccd6b4bd9a2f38dd8a0 \
		${WRKSRC}/src/github.com/mitchellh/cli
	@${MV} ${WRKDIR}/columnize-44cb4788b2ec3c3d158dd3d1b50aba7d66f4b59a \
		${WRKSRC}/src/github.com/ryanuber/columnize
	@${MV} ${WRKDIR}/dns-b65f52f3f0dd1afa25cbbf63f8e7eb15fb5c0641 \
		${WRKSRC}/src/github.com/miekg/dns
	@${MV} ${WRKDIR}/go.net-cbad13bf000d0cbdbc71506b26e94bcc72bbe74d \
		${WRKSRC}/src/github.com/hashicorp/go.net
	@${CP} -r ${WRKSRC}/src/github.com/hashicorp/go.net/internal \
		${WRKSRC}/src/code.google.com/p/go.net

do-build:
	@cd ${WRKSRC}/src/github.com/${GH_ACCOUNT}/${PORTNAME}; ${SETENV} ${BUILD_ENV} GOPATH=${WRKSRC} go build -o bin/${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/github.com/${GH_ACCOUNT}/${PORTNAME}/bin/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
