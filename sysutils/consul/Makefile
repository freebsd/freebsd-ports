# $FreeBSD$

PORTNAME=	consul
PORTVERSION=	0.6.4
PORTREVISION=	1
DISTVERSIONPREFIX=	v
CATEGORIES=	sysutils
MASTER_SITES=	https://releases.hashicorp.com/consul/${PORTVERSION}/:web_ui
DISTFILES=	consul_${PORTVERSION}_web_ui.zip:web_ui

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Service discovery and configuration made easy

LICENSE=	MPL

BUILD_DEPENDS=	${LOCALBASE}/bin/go:lang/go

USES=		compiler

USE_GITHUB=	yes
GH_ACCOUNT=	hashicorp
GH_SUBDIR=	src/github.com/${GH_ACCOUNT}/${PORTNAME}

USE_RC_SUBR=	consul

USERS=		consul
GROUPS=		consul

STRIP=		# stripping can break go binaries

post-extract:
	@${MV} ${WRKSRC}/vendor/ ${WRKSRC}/src/

do-build:
	@cd ${WRKSRC}/src/github.com/hashicorp/consul; ${SETENV} ${BUILD_ENV} GOPATH=${WRKSRC} go build \
		-ldflags "-X main.GitDescribe=v${PORTVERSION}" -o bin/consul

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/github.com/hashicorp/consul/bin/consul ${STAGEDIR}${PREFIX}/bin/consul
	${MKDIR} ${STAGEDIR}${DATADIR}
	${MKDIR} ${WRKDIR}/dist
	${MV} ${WRKDIR}/index.html ${WRKDIR}/static ${WRKDIR}/dist
	cd ${WRKDIR}/dist && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}

.include <bsd.port.pre.mk>

# golang assumes that if clang is in use, it is called "clang" and not "cc". If
# it's called "cc", go fails.
.if ${COMPILER_TYPE} == clang
BUILD_ENV=	CC=clang
.endif

.include <bsd.port.post.mk>
