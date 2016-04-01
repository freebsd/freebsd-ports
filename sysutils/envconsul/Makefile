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
GH_ACCOUNT=	armon:gometrics,goradix aws:awssdkgo coreos:etcd fatih:structs \
		go-ini:ini go-sql-driver:mysql hashicorp:DEFAULT,consul,consultemplate \
		hashicorp:errwrap,gocleanhttp,gogatedio,gomsgpack \
		hashicorp:gomultierror,gosyslog,gouuid,golanglru,hcl,logutils \
		hashicorp:serf,vault jmespath:gojmespath lib:pq \
		mitchellh:copystructure,iochan,mapstructure,reflectwalk \
		samuel:gozookeeper golang:crypto,net
GH_PROJECT=	go-metrics:gometrics go-radix:goradix aws-sdk-go:awssdkgo \
		etcd:etcd structs:structs ini:ini mysql:mysql consul:consul \
		consul-template:consultemplate errwrap:errwrap \
		go-cleanhttp:gocleanhttp go-gatedio:gogatedio \
		go-msgpack:gomsgpack go-multierror:gomultierror \
		go-syslog:gosyslog go-uuid:gouuid golang-lru:golanglru hcl:hcl \
		logutils:logutils serf:serf vault:vault go-jmespath:gojmespath \
		pq:pq copystructure:copystructure iochan:iochan \
		mapstructure:mapstructure reflectwalk:reflectwalk \
		go-zookeeper:gozookeeper crypto:crypto net:net
GH_TAGNAME=	6c5fa0d:gometrics fbd82e8:goradix 308eaa6:awssdkgo 6afd8e4:etcd \
		a9f7daa:structs aea5e9f:ini 527bcd5:mysql 809ed36:consul \
		ec11b92:consultemplate c2a1a65:envconsul 7554cd9:errwrap \
		875fb67:gocleanhttp 8b8de10:gogatedio fa3f638:gomsgpack \
		d30f099:gomultierror 42a2b57:gosyslog 2951e8b:gouuid \
		17e3543:golanglru 4de5195:hcl 0dc08b1:logutils 8d36400:serf \
		97820e2:vault bbaa094:gojmespath ffe986a:pq \
		6fc6626:copystructure 87b45ff:iochan 281073e:mapstructure \
		eecf4c7:reflectwalk 913027e:gozookeeper c8b9e63:crypto \
		271cfc1:net

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
	@${MKDIR} ${WRKSRC}/src/github.com/armon
	@${MKDIR} ${WRKSRC}/src/github.com/aws
	@${MKDIR} ${WRKSRC}/src/github.com/coreos
	@${MKDIR} ${WRKSRC}/src/github.com/fatih
	@${MKDIR} ${WRKSRC}/src/github.com/go-ini
	@${MKDIR} ${WRKSRC}/src/github.com/go-sql-driver
	@${MKDIR} ${WRKSRC}/src/github.com/jmespath
	@${MKDIR} ${WRKSRC}/src/github.com/lib
	@${MKDIR} ${WRKSRC}/src/github.com/mitchellh
	@${MKDIR} ${WRKSRC}/src/github.com/samuel
	@${MKDIR} ${WRKSRC}/src/golang.org/x
	@${MV} ${WRKSRC_gometrics} ${WRKSRC}/src/github.com/armon/go-metrics
	@${MV} ${WRKSRC_goradix} ${WRKSRC}/src/github.com/armon/go-radix
	@${MV} ${WRKSRC_awssdkgo} ${WRKSRC}/src/github.com/aws/aws-sdk-go
	@${MV} ${WRKSRC_etcd} ${WRKSRC}/src/github.com/coreos/etcd
	@${MV} ${WRKSRC_structs} ${WRKSRC}/src/github.com/fatih/structs
	@${MV} ${WRKSRC_ini} ${WRKSRC}/src/github.com/go-ini/ini
	@${MV} ${WRKSRC_mysql} ${WRKSRC}/src/github.com/go-sql-driver/mysql
	@${MV} ${WRKSRC_consul} ${WRKSRC}/src/github.com/hashicorp/consul
	@${MV} ${WRKSRC_consultemplate} ${WRKSRC}/src/github.com/hashicorp/consul-template
	@${MV} ${WRKSRC_errwrap} ${WRKSRC}/src/github.com/hashicorp/errwrap
	@${MV} ${WRKSRC_gocleanhttp} ${WRKSRC}/src/github.com/hashicorp/go-cleanhttp
	@${MV} ${WRKSRC_gogatedio} ${WRKSRC}/src/github.com/hashicorp/go-gatedio
	@${MV} ${WRKSRC_gomsgpack} ${WRKSRC}/src/github.com/hashicorp/go-msgpack
	@${MV} ${WRKSRC_gomultierror} ${WRKSRC}/src/github.com/hashicorp/go-multierror
	@${MV} ${WRKSRC_gosyslog} ${WRKSRC}/src/github.com/hashicorp/go-syslog
	@${MV} ${WRKSRC_gouuid} ${WRKSRC}/src/github.com/hashicorp/go-uuid
	@${MV} ${WRKSRC_golanglru} ${WRKSRC}/src/github.com/hashicorp/golang-lru
	@${MV} ${WRKSRC_hcl} ${WRKSRC}/src/github.com/hashicorp/hcl
	@${MV} ${WRKSRC_logutils} ${WRKSRC}/src/github.com/hashicorp/logutils
	@${MV} ${WRKSRC_serf} ${WRKSRC}/src/github.com/hashicorp/serf
	@${MV} ${WRKSRC_vault} ${WRKSRC}/src/github.com/hashicorp/vault
	@${MV} ${WRKSRC_gojmespath} ${WRKSRC}/src/github.com/jmespath/go-jmespath
	@${MV} ${WRKSRC_pq} ${WRKSRC}/src/github.com/lib/pq
	@${MV} ${WRKSRC_copystructure} ${WRKSRC}/src/github.com/mitchellh/copystructure
	@${MV} ${WRKSRC_iochan} ${WRKSRC}/src/github.com/mitchellh/iochan
	@${MV} ${WRKSRC_mapstructure} ${WRKSRC}/src/github.com/mitchellh/mapstructure
	@${MV} ${WRKSRC_reflectwalk} ${WRKSRC}/src/github.com/mitchellh/reflectwalk
	@${MV} ${WRKSRC_gozookeeper} ${WRKSRC}/src/github.com/samuel/go-zookeeper
	@${MV} ${WRKSRC_crypto} ${WRKSRC}/src/golang.org/x/crypto
	@${MV} ${WRKSRC_net} ${WRKSRC}/src/golang.org/x/net

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
