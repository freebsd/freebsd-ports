# $FreeBSD$

PORTNAME=	kurly
DISTVERSIONPREFIX=	v
DISTVERSION=	1.2.1
CATEGORIES=	www

MAINTAINER=	seanc@FreeBSD.org
COMMENT=	Alternative implementation of curl written in Golang

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	go:lang/go

USE_GITHUB=	yes
GH_ACCOUNT=	davidjpeacock
GH_SUBDIR=	src/github.com/${GH_ACCOUNT}/${PORTNAME}

GH_TUPLE=	davidjpeacock:kurly:${DISTVERSIONPREFIX}${DISTVERSION}:DEFAULT/src/github.com/davidjpeacock/kurly \
		aki237:nscjar:e2df936:nscjar/src/github.com/aki237/nscjar \
		alsm:ioprogress:063c372:ioprogress/src/github.com/alsm/ioprogress \
		davidjpeacock:cli:8ba6f23:cli/src/github.com/davidjpeacock/cli

PLIST_FILES=	bin/kurly

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} CGO_ENABLED=0 GOPATH=${WRKSRC} \
	${LOCALBASE}/bin/go build -o ${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
