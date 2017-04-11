# $FreeBSD$

PORTNAME=	serf
PORTVERSION=	0.8.1
DISTVERSIONPREFIX=	v
CATEGORIES=	sysutils
PKGNAMEPREFIX=	hashicorp-

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Service discovery and configuration made easy

LICENSE=	MPL

BUILD_DEPENDS=	go:lang/go

USE_GITHUB=	yes

GH_ACCOUNT=	hashicorp
GH_SUBDIR:=	src/github.com/${GH_ACCOUNT}/${PORTNAME}

USE_RC_SUBR=	serf

USERS=		serf
GROUPS=		serf

PLIST_FILES=	bin/serf

do-build:
	@cd ${WRKSRC}/src/github.com/${GH_ACCOUNT}/${PORTNAME}; \
		${SETENV} GOPATH=${WRKSRC}:${WRKSRC}/vendor/ \
		go build -o bin/${PORTNAME} ./cmd/serf/

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/github.com/${GH_ACCOUNT}/${PORTNAME}/bin/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
