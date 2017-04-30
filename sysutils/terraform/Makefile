# $FreeBSD$

PORTNAME=	terraform
PORTVERSION=	0.9.4
DISTVERSIONPREFIX=	v
CATEGORIES=	sysutils

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Provides a common configuration to launch infrastructure

LICENSE=	MPL

BUILD_DEPENDS=	${LOCALBASE}/bin/go:lang/go

USE_GITHUB=	yes
GH_ACCOUNT=	hashicorp
GH_SUBDIR=	src/github.com/${GH_ACCOUNT}/${PORTNAME}

PLIST_FILES=	bin/${PORTNAME}

do-build:
	@cd ${WRKSRC}/src/github.com/${GH_ACCOUNT}/${PORTNAME}; \
		${SETENV} ${BUILD_ENV} GOPATH=${WRKSRC} \
		go build -o bin/${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/github.com/${GH_ACCOUNT}/${PORTNAME}/bin/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
