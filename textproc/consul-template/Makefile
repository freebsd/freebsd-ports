# Created by: Steve Wills <swills@FreeBSD.org>
# $FreeBSD$

PORTNAME=	consul-template
PORTVERSION=	0.8.0
DISTVERSIONPREFIX=	v
CATEGORIES=	textproc

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Generic template rendering and notifications with Consul

BUILD_DEPENDS=	${LOCALBASE}/bin/go:${PORTSDIR}/lang/go

USE_GITHUB=	yes
GH_ACCOUNT=	hashicorp:DEFAULT,consul,go_multierror,go_syslog,hcl,logutils,terraform \
		armon:consul_api mitchellh:mapstructure
GH_PROJECT=	consul-api:consul_api consul:consul \
		go-multierror:go_multierror go-syslog:go_syslog hcl:hcl \
		logutils:logutils mapstructure:mapstructure terraform:terraform
GH_TAGNAME=	0e644b8:consul_api 23b0af5:logutils 2c88e7e:hcl \
		42a2b57:go_syslog 740c764:mapstructure d87fa90:terraform \
		fcdddc3:go_multierror v0.5.0:consul

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
	@${MV} ${WRKSRC_consul_api} ${WRKSRC}/src/github.com/armon/consul-api
	@${MV} ${WRKSRC_hcl} ${WRKSRC}/src/github.com/hashicorp/hcl
	@${MV} ${WRKSRC_logutils} ${WRKSRC}/src/github.com/hashicorp/logutils
	@${MV} ${WRKSRC_terraform} ${WRKSRC}/src/github.com/hashicorp/terraform
	@${MV} ${WRKSRC_mapstructure} ${WRKSRC}/src/github.com/mitchellh/mapstructure
	@${MV} ${WRKSRC_go_multierror} ${WRKSRC}/src/github.com/hashicorp/go-multierror
	@${MV} ${WRKSRC_go_syslog} ${WRKSRC}/src/github.com/hashicorp/go-syslog
	@${MV} ${WRKSRC_consul} ${WRKSRC}/src/github.com/hashicorp/consul

do-build:
	@cd ${WRKSRC} ; ${SETENV} GOPATH=${WRKSRC} go build

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/consul-template-${PORTVERSION} ${STAGEDIR}${PREFIX}/bin/consul-template

.include <bsd.port.mk>
