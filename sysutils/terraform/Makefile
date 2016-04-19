# $FreeBSD$

PORTNAME=	terraform
PORTVERSION=	0.6.14
DISTVERSIONPREFIX=	v
CATEGORIES=	sysutils

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Provides a common configuration to launch infrastructure

BUILD_DEPENDS=	${LOCALBASE}/bin/go:lang/go

USE_GITHUB=	yes
GH_ACCOUNT=	hashicorp
STRIP=		# stripping can break go binaries

PLUGINS=	provider-atlas provider-aws provider-azure provider-azurerm \
		provider-chef provider-clc provider-cloudflare \
		provider-cloudstack provider-consul provider-datadog \
		provider-digitalocean provider-dme provider-dnsimple \
		provider-docker provider-dyn provider-github provider-google \
		provider-heroku provider-influxdb provider-mailgun \
		provider-mysql provider-null provider-openstack provider-packet \
		provider-postgresql provider-powerdns provider-rundeck \
		provider-statuscake provider-template provider-terraform \
		provider-tls provider-triton provider-ultradns provider-vcd \
		provider-vsphere provisioner-chef provisioner-file \
		provisioner-local-exec provisioner-remote-exec

post-extract:
	@${MV} ${WRKSRC}/vendor ${WRKSRC}/src
	@${MKDIR} ${WRKSRC}/src/github.com/${GH_ACCOUNT}/${PORTNAME}
.for src in .gitignore .travis.yml BUILDING.md CHANGELOG.md CONTRIBUTING.md \
	LICENSE Makefile README.md Vagrantfile builtin checkpoint.go command \
	commands.go communicator config config.go config_test.go config_unix.go \
	config_windows.go contrib dag deps digraph dot examples flatmap helper \
	main.go make.bat panic.go plugin rpc scripts state terraform \
	test-fixtures version.go website
	@${MV} ${WRKSRC}/${src} \
		${WRKSRC}/src/github.com/hashicorp/${PORTNAME}
.endfor

do-build:
	@cd ${WRKSRC}/src/github.com/${GH_ACCOUNT}/${PORTNAME}; ${SETENV} ${BUILD_ENV} GOPATH=${WRKSRC} go build -o bin/${PORTNAME}
.for plugin in ${PLUGINS}
	@cd ${WRKSRC}/src/github.com/${GH_ACCOUNT}/${PORTNAME}; ${SETENV} GOPATH=${WRKSRC} go build -o bin/${PORTNAME}-${plugin} github.com/hashicorp/terraform/builtin/bins/${plugin}
.endfor

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/github.com/${GH_ACCOUNT}/${PORTNAME}/bin/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
.for plugin in ${PLUGINS}
	${INSTALL_PROGRAM} ${WRKSRC}/src/github.com/${GH_ACCOUNT}/${PORTNAME}/bin/${PORTNAME}-${plugin} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}-${plugin}
.endfor

.include <bsd.port.mk>
