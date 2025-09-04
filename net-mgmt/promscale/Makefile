PORTNAME=	promscale
DISTVERSION=	0.17.0
PORTREVISION=	21
CATEGORIES=	net-mgmt
MASTER_SITES=   https://raw.githubusercontent.com/${GH_ACCOUNT}/${GH_PROJECT}/${DISTVERSIONFULL}/:gomod
DISTFILES=      go.mod:gomod

MAINTAINER=	feld@FreeBSD.org
COMMENT=	Timescale analytical platform for Prometheus metrics
WWW=		https://www.timescale.com/promscale

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

USE_RC_SUBR?=	${PORTNAME}

USERS=          promscale
GROUPS=         ${USERS}

SUB_LIST?=	USERS=${USERS} GROUPS=${GROUPS}

USE_GITHUB=	yes
GH_ACCOUNT=	timescale
GH_PROJECT=	promscale

GO_MODULE=	github.com/timescale/promscale
GO_TARGET=	./cmd/promscale

PLIST_FILES=	bin/promscale

.include <bsd.port.mk>
