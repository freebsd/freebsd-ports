# Created by: Steve Wills <swills@FreeBSD.org>
# $FreeBSD$

PORTNAME=	consul-template
PORTVERSION=	0.3.1
CATEGORIES=	textproc
MASTER_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/archive/${GH_TAGNAME}.tar.gz?dummy=/:group1 \
		https://codeload.github.com/armon/consul-api/legacy.tar.gz/0e644b8?dummy=/:group2 \
		https://codeload.github.com/hashicorp/hcl/legacy.tar.gz/2c88e7e?dummy=/:group3 \
		https://codeload.github.com/hashicorp/logutils/legacy.tar.gz/23b0af5?dummy=/:group4 \
		https://codeload.github.com/hashicorp/terraform/legacy.tar.gz/d87fa90?dummy=/:group5 \
		https://codeload.github.com/mitchellh/mapstructure/legacy.tar.gz/740c764?dummy=/:group6
DISTFILES=	consul-template-0.3.1.tar.gz:group1 \
		armon-consul-api-0e644b8.tar.gz:group2 \
		hashicorp-hcl-2c88e7e.tar.gz:group3 \
		hashicorp-logutils-23b0af5.tar.gz:group4 \
		hashicorp-terraform-d87fa90.tar.gz:group5 \
		mitchellh-mapstructure-740c764.tar.gz:group6

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Generic template rendering and notifications with Consul

BUILD_DEPENDS=	${LOCALBASE}/bin/go:${PORTSDIR}/lang/go

USE_GITHUB=	yes
GH_ACCOUNT=	hashicorp
GH_COMMIT=	e22fbf7
GH_TAGNAME=	v${PORTVERSION}

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

PLIST_FILES=	bin/consul-template

STRIP=		# stripping can break go binaries

post-patch:
	@${MKDIR} ${WRKSRC}/src/github.com/armon
	@${MKDIR} ${WRKSRC}/src/github.com/hashicorp/consul-template
	@${MKDIR} ${WRKSRC}/src/github.com/mitchellh
	@${MV} ${WRKDIR}/armon-consul-api-0e644b8 ${WRKSRC}/src/github.com/armon/consul-api
	@${MV} ${WRKDIR}/hashicorp-hcl-2c88e7e ${WRKSRC}/src/github.com/hashicorp/hcl
	@${MV} ${WRKDIR}/hashicorp-logutils-23b0af5 ${WRKSRC}/src/github.com/hashicorp/logutils
	@${MV} ${WRKDIR}/hashicorp-terraform-d87fa90 ${WRKSRC}/src/github.com/hashicorp/terraform
	@${MV} ${WRKDIR}/mitchellh-mapstructure-740c764 ${WRKSRC}/src/github.com/mitchellh/mapstructure
	@${MV} ${WRKSRC}/util ${WRKSRC}/src/github.com/hashicorp/consul-template
	@${MV} ${WRKSRC}/test ${WRKSRC}/src/github.com/hashicorp/consul-template

do-build:
	@cd ${WRKSRC} ; ${SETENV} GOPATH=${WRKSRC} go build

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/consul-template-${PORTVERSION} ${STAGEDIR}${PREFIX}/bin/consul-template

.include <bsd.port.mk>
