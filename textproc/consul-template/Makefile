# Created by: Steve Wills <swills@FreeBSD.org>
# $FreeBSD$

PORTNAME=	consul-template
PORTVERSION=	0.12.2
DISTVERSIONPREFIX=	v
CATEGORIES=	textproc

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Generic template rendering and notifications with Consul

BUILD_DEPENDS=	${LOCALBASE}/bin/go:lang/go

USE_GITHUB=	yes
GH_ACCOUNT=	hashicorp:DEFAULT,consul,go_multierror,go_syslog,hcl,logutils \
		hashicorp:terraform,reap,vault,serf,chttp,errwrap golang:sys \
		armon:consul_api mitchellh:mapstructure go-yaml:yaml2 \
		fatih:structs
GH_PROJECT=	consul-api:consul_api consul:consul \
		go-multierror:go_multierror go-syslog:go_syslog hcl:hcl \
		logutils:logutils mapstructure:mapstructure terraform:terraform \
		go-reap:reap yaml:yaml2 sys:sys vault:vault serf:serf \
		go-cleanhttp:chttp errwrap:errwrap structs:structs
GH_TAGNAME=	dcfedd5:consul_api 0dc08b1:logutils aee8c49:hcl \
		42a2b57:go_syslog 281073e:mapstructure acabd4d:terraform \
		d30f099:go_multierror v0.6.3:consul 2d85522:reap f7716cb:yaml2 \
		442cd60:sys 4750307:vault b60fe33:serf ce617e7:chttp \
		7554cd9:errwrap dd04eba:structs

PLIST_FILES=	bin/consul-template

STRIP=		# stripping can break go binaries

post-patch:
	@${MKDIR} ${WRKSRC}/src/github.com/hashicorp/consul-template
.for src in CHANGELOG.md LICENSE Makefile README.md brain.go brain_test.go \
	cli.go cli_test.go config.go config_test.go dependency flags.go logging \
	main.go runner.go runner_test.go template.go template_functions.go \
	template_functions_test.go test template_test.go watch
	@${CP} -r ${WRKSRC}/${src} \
		${WRKSRC}/src/github.com/hashicorp/consul-template
.endfor
	@${MKDIR} ${WRKSRC}/src/github.com/armon
	@${MKDIR} ${WRKSRC}/src/github.com/mitchellh
	@${MKDIR} ${WRKSRC}/src/github.com/hashicorp
	@${MKDIR} ${WRKSRC}/src/github.com/fatih
	@${MKDIR} ${WRKSRC}/src/gopkg.in
	@${MKDIR} ${WRKSRC}/src/golang.org/x
	@${MV} ${WRKSRC_consul_api} ${WRKSRC}/src/github.com/armon/consul-api
	@${MV} ${WRKSRC_hcl} ${WRKSRC}/src/github.com/hashicorp/hcl
	@${MV} ${WRKSRC_logutils} ${WRKSRC}/src/github.com/hashicorp/logutils
	@${MV} ${WRKSRC_terraform} ${WRKSRC}/src/github.com/hashicorp/terraform
	@${MV} ${WRKSRC_mapstructure} ${WRKSRC}/src/github.com/mitchellh/mapstructure
	@${MV} ${WRKSRC_go_multierror} ${WRKSRC}/src/github.com/hashicorp/go-multierror
	@${MV} ${WRKSRC_go_syslog} ${WRKSRC}/src/github.com/hashicorp/go-syslog
	@${MV} ${WRKSRC_consul} ${WRKSRC}/src/github.com/hashicorp/consul
	@${MV} ${WRKSRC_reap} ${WRKSRC}/src/github.com/hashicorp/go-reap
	@${MV} ${WRKSRC_yaml2} ${WRKSRC}/src/gopkg.in/yaml.v2
	@${MV} ${WRKSRC_sys} ${WRKSRC}/src/golang.org/x/sys
	@${MV} ${WRKSRC_vault} ${WRKSRC}/src/github.com/hashicorp/vault
	@${MV} ${WRKSRC_serf} ${WRKSRC}/src/github.com/hashicorp/serf
	@${MV} ${WRKSRC_errwrap} ${WRKSRC}/src/github.com/hashicorp/errwrap
	@${MV} ${WRKSRC_structs} ${WRKSRC}/src/github.com/fatih/structs
	@${MV} ${WRKSRC_chttp} ${WRKSRC}/src/github.com/hashicorp/go-cleanhttp

do-build:
	@cd ${WRKSRC} ; ${SETENV} GOPATH=${WRKSRC} go build

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/consul-template-${PORTVERSION} ${STAGEDIR}${PREFIX}/bin/consul-template

.include <bsd.port.mk>
