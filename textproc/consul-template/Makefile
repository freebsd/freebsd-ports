# Created by: Steve Wills <swills@FreeBSD.org>
# $FreeBSD$

PORTNAME=	consul-template
PORTVERSION=	0.19.3
DISTVERSIONPREFIX=	v
CATEGORIES=	textproc

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Generic template rendering and notifications with Consul

LICENSE=	MPL

BUILD_DEPENDS=	${LOCALBASE}/bin/go:lang/go

USE_GITHUB=	yes
GH_ACCOUNT=	hashicorp
GH_SUBDIR=	src/github.com/hashicorp/consul-template

PLIST_FILES=	bin/consul-template

USE_RC_SUBR=	consul-template

do-build:
	@cd ${WRKSRC}/src/github.com/hashicorp/consul-template ; \
		${SETENV} GOPATH=${WRKSRC} go build

do-install:
	${INSTALL_PROGRAM} \
		${WRKSRC}/src/github.com/hashicorp/consul-template/consul-template \
		${STAGEDIR}${PREFIX}/bin/consul-template

.include <bsd.port.mk>
