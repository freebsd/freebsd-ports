# Created by: Steve Wills <swills@FreeBSD.org>
# $FreeBSD$

PORTNAME=	consul-template
PORTVERSION=	0.14.0
DISTVERSIONPREFIX=	v
CATEGORIES=	textproc

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Generic template rendering and notifications with Consul

BUILD_DEPENDS=	${LOCALBASE}/bin/go:lang/go

USE_GITHUB=	yes
GH_ACCOUNT=	hashicorp

PLIST_FILES=	bin/consul-template

STRIP=		# stripping can break go binaries

post-extract:
	@${MV} ${WRKSRC}/vendor ${WRKSRC}/src
	@${MKDIR} ${WRKSRC}/src/github.com/hashicorp/consul-template
	@cd ${WRKSRC} ; \
	${MV} .gitignore .travis.yml CHANGELOG.md Godeps LICENSE Makefile \
	README.md brain.go brain_test.go cli.go cli_test.go config.go \
	config_test.go dedup.go dedup_test.go dependency flags.go logging \
	main.go runner.go runner_test.go scripts template.go \
	template_functions.go template_functions_test.go template_test.go test \
	watch \
	${WRKSRC}/src/github.com/hashicorp/consul-template

do-build:
	@cd ${WRKSRC}/src/github.com/hashicorp/consul-template ; \
		${SETENV} GOPATH=${WRKSRC} go build

do-install:
	${INSTALL_PROGRAM} \
		${WRKSRC}/src/github.com/hashicorp/consul-template/consul-template \
		${STAGEDIR}${PREFIX}/bin/consul-template

.include <bsd.port.mk>
