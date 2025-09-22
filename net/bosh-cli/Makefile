PORTNAME=	bosh-cli
PORTVERSION=	5.5.0
PORTREVISION=	31
CATEGORIES=	net sysutils

MAINTAINER=	dumbbell@FreeBSD.org
COMMENT=	CLI for BOSH
WWW=		https://bosh.io/docs/cli-v2.html

LICENSE=	APACHE20

DEPRECATED=	Not updated in years, no demand for them
EXPIRATION_DATE=	2025-10-01

USE_GITHUB=	yes
GH_TUPLE=	cloudfoundry:bosh-cli:v${PORTVERSION}

USES=		go tar:xz

CONFLICTS_INSTALL=	schilyutils # bin/bosh

GO_PKGNAME=	github.com/cloudfoundry/bosh-cli

PLIST_FILES=	bin/bosh

post-patch:
	${REINPLACE_CMD} -e 's|\[DEV BUILD\]|${PORTVERSION}|' ${WRKSRC}/cmd/version.go

post-install:
	${MV} ${STAGEDIR}${PREFIX}/bin/bosh-cli ${STAGEDIR}${PREFIX}/bin/bosh

.include <bsd.port.mk>
