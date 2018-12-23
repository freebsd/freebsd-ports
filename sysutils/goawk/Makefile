# $FreeBSD$

PORTNAME=	goawk
DISTVERSIONPREFIX=	v
DISTVERSION=	1.1.4
CATEGORIES=	sysutils

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	AWK interpreter written in Go

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/src/github.com/${GH_ACCOUNT}/${PORTNAME}/LICENSE.txt

BUILD_DEPENDS=	go:lang/go

USE_GITHUB=	nodefault # the main code is in GH_TUPLE
GH_ACCOUNT=	benhoyt
GH_TUPLE=	benhoyt:goawk:${DISTVERSIONFULL}:main/src/github.com/benhoyt/goawk
GH_SUBDIR=	src/github.com/${GH_ACCOUNT}/${PORTNAME}

PLIST_FILES=	bin/${PORTNAME}

do-build:
	@cd ${WRKSRC}/src/github.com/${GH_ACCOUNT}/${PORTNAME} && \
		${SETENV} ${MAKE_ENV} GOPATH=${WRKSRC} go install ./...

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
