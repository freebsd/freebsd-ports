# Created by: Steve Wills <swills@FreeBSD.org>
# $FreeBSD$

PORTNAME=	consul-template
PORTVERSION=	0.8.0
DISTVERSIONPREFIX=	v
CATEGORIES=	textproc
MASTER_SITES=	https://codeload.github.com/armon/consul-api/legacy.tar.gz/0e644b8?dummy=/:group2 \
		https://codeload.github.com/hashicorp/hcl/legacy.tar.gz/2c88e7e?dummy=/:group3 \
		https://codeload.github.com/hashicorp/logutils/legacy.tar.gz/23b0af5?dummy=/:group4 \
		https://codeload.github.com/hashicorp/terraform/legacy.tar.gz/d87fa90?dummy=/:group5 \
		https://codeload.github.com/mitchellh/mapstructure/legacy.tar.gz/740c764?dummy=/:group6 \
		https://github.com/hashicorp/go-multierror/archive/fcdddc395df1ddf4247c69bd436e84cfa0733f7e.tar.gz?dummy=/:group7 \
		https://github.com/hashicorp/go-syslog/archive/42a2b573b664dbf281bd48c3cc12c086b17a39ba.tar.gz?dummy=/:group8 \
		https://github.com/hashicorp/consul/archive/v0.5.0.tar.gz?dummy=/:group9
DISTFILES=	${DISTNAME}.tar.gz \
		armon-consul-api-0e644b8.tar.gz:group2 \
		hashicorp-hcl-2c88e7e.tar.gz:group3 \
		hashicorp-logutils-23b0af5.tar.gz:group4 \
		hashicorp-terraform-d87fa90.tar.gz:group5 \
		mitchellh-mapstructure-740c764.tar.gz:group6 \
		hashicorp_go-multierror_fcdddc395df1ddf4247c69bd436e84cfa0733f7e.tar.gz:group7 \
		hashicorp_go-syslog_42a2b573b664dbf281bd48c3cc12c086b17a39ba.tar.gz:group8 \
		consul-v0.5.0.tar.gz:group9

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Generic template rendering and notifications with Consul

BUILD_DEPENDS=	${LOCALBASE}/bin/go:${PORTSDIR}/lang/go

USE_GITHUB=	yes
GH_ACCOUNT=	hashicorp

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

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
	@${MV} ${WRKDIR}/armon-consul-api-0e644b8 ${WRKSRC}/src/github.com/armon/consul-api
	@${MV} ${WRKDIR}/hashicorp-hcl-2c88e7e ${WRKSRC}/src/github.com/hashicorp/hcl
	@${MV} ${WRKDIR}/hashicorp-logutils-23b0af5 ${WRKSRC}/src/github.com/hashicorp/logutils
	@${MV} ${WRKDIR}/hashicorp-terraform-d87fa90 ${WRKSRC}/src/github.com/hashicorp/terraform
	@${MV} ${WRKDIR}/mitchellh-mapstructure-740c764 ${WRKSRC}/src/github.com/mitchellh/mapstructure
	@${MV} ${WRKDIR}/go-multierror-fcdddc395df1ddf4247c69bd436e84cfa0733f7e ${WRKSRC}/src/github.com/hashicorp/go-multierror
	@${MV} ${WRKDIR}/go-syslog-42a2b573b664dbf281bd48c3cc12c086b17a39ba ${WRKSRC}/src/github.com/hashicorp/go-syslog
	@${MV} ${WRKDIR}/consul-0.5.0 ${WRKSRC}/src/github.com/hashicorp/consul

do-build:
	@cd ${WRKSRC} ; ${SETENV} GOPATH=${WRKSRC} go build

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/consul-template-${PORTVERSION} ${STAGEDIR}${PREFIX}/bin/consul-template

.include <bsd.port.mk>
