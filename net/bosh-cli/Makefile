# $FreeBSD$

PORTNAME=	bosh-cli
PORTVERSION=	5.5.0
PORTREVISION=	1
CATEGORIES=	net sysutils

MAINTAINER=	dumbbell@FreeBSD.org
COMMENT=	CLI for BOSH

LICENSE=	APACHE20

USE_GITHUB=	yes
GH_TUPLE=	cloudfoundry:bosh-cli:v${PORTVERSION}

CONFLICTS_INSTALL=	rubygem-bosh_cli

USES=		go tar:xz

GO_PKGNAME=	github.com/cloudfoundry/bosh-cli

PLIST_FILES=	bin/bosh

post-patch:
	${REINPLACE_CMD} -e 's|\[DEV BUILD\]|${PORTVERSION}|' ${WRKSRC}/cmd/version.go

post-install:
	${MV} ${STAGEDIR}${PREFIX}/bin/bosh-cli ${STAGEDIR}${PREFIX}/bin/bosh

.include <bsd.port.mk>
