# $FreeBSD$

PORTNAME=	envconsul
PORTVERSION=	0.6.0
DISTVERSIONPREFIX=	v
CATEGORIES=	sysutils

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Populate values from Consul into a process environment

LICENSE=	MPL
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${LOCALBASE}/bin/go:lang/go

USE_GITHUB=	yes
GH_ACCOUNT=	hashicorp
GH_TUPLE= \
	armon:go-metrics:6c5fa0d:gometrics/src/github.com/armon/go-metrics \
	armon:go-radix:fbd82e8:goradix/src/github.com/armon/go-radix \
	aws:aws-sdk-go:308eaa6:awssdkgo/src/github.com/aws/aws-sdk-go \
	coreos:etcd:6afd8e4:etcd/src/github.com/coreos/etcd \
	fatih:structs:a9f7daa:structs/src/github.com/fatih/structs \
	go-ini:ini:aea5e9f:ini/src/github.com/go-ini/ini \
	go-sql-driver:mysql:527bcd5:mysql/src/github.com/go-sql-driver/mysql \
	hashicorp:consul:809ed36:consul/src/github.com/hashicorp/consul \
	hashicorp:consul-template:ec11b92:consultemplate/src/github.com/hashicorp/consul-template \
	hashicorp:errwrap:7554cd9:errwrap/src/github.com/hashicorp/errwrap \
	hashicorp:go-cleanhttp:875fb67:gocleanhttp/src/github.com/hashicorp/go-cleanhttp \
	hashicorp:go-gatedio:8b8de10:gogatedio/src/github.com/hashicorp/go-gatedio \
	hashicorp:go-msgpack:fa3f638:gomsgpack/src/github.com/hashicorp/go-msgpack \
	hashicorp:go-multierror:d30f099:gomultierror/src/github.com/hashicorp/go-multierror \
	hashicorp:go-syslog:42a2b57:gosyslog/src/github.com/hashicorp/go-syslog \
	hashicorp:go-uuid:2951e8b:gouuid/src/github.com/hashicorp/go-uuid \
	hashicorp:golang-lru:17e3543:golanglru/src/github.com/hashicorp/golang-lru \
	hashicorp:hcl:4de5195:hcl/src/github.com/hashicorp/hcl \
	hashicorp:logutils:0dc08b1:logutils/src/github.com/hashicorp/logutils \
	hashicorp:serf:8d36400:serf/src/github.com/hashicorp/serf \
	hashicorp:vault:97820e2:vault/src/github.com/hashicorp/vault \
	jmespath:go-jmespath:bbaa094:gojmespath/src/github.com/jmespath/go-jmespath \
	lib:pq:ffe986a:pq/src/github.com/lib/pq \
	mitchellh:copystructure:6fc6626:copystructure/src/github.com/mitchellh/copystructure \
	mitchellh:iochan:87b45ff:iochan/src/github.com/mitchellh/iochan \
	mitchellh:mapstructure:281073e:mapstructure/src/github.com/mitchellh/mapstructure \
	mitchellh:reflectwalk:eecf4c7:reflectwalk/src/github.com/mitchellh/reflectwalk \
	samuel:go-zookeeper:913027e:gozookeeper/src/github.com/samuel/go-zookeeper \
	golang:crypto:c8b9e63:crypto/src/golang.org/x/crypto \
	golang:net:271cfc1:net/src/golang.org/x/net \
	hashicorp:envconsul:c2a1a65:envconsul

PLIST_FILES=	bin/envconsul

STRIP=		# stripping can break go binaries

OPTIONS_DEFINE=	DOCS

PORTDOCS=	README.md

post-patch:
	@${MKDIR} ${WRKSRC}/src/github.com/hashicorp/envconsul
.for src in .gitignore .travis.yml CHANGELOG.md Makefile README.md \
	cli.go cli_test.go config.go config_test.go flags.go main.go runner.go \
	runner_test.go scripts signals.go signals_windows.go
	@${MV} ${WRKSRC}/${src} \
		${WRKSRC}/src/github.com/hashicorp/envconsul
.endfor

do-build:
	@cd ${WRKSRC}/src/github.com/hashicorp/envconsul; ${SETENV} ${BUILD_ENV} GOPATH=${WRKSRC} go build -o bin/envconsul

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/github.com/hashicorp/envconsul/bin/envconsul ${STAGEDIR}${PREFIX}/bin/envconsul

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for doc in ${PORTDOCS}
	${CP} ${WRKSRC}/src/github.com/hashicorp/envconsul/${doc} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
