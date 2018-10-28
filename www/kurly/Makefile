# $FreeBSD$

PORTNAME=	kurly
DISTVERSIONPREFIX=	v
DISTVERSION=	1.2.2
CATEGORIES=	www

MAINTAINER=	seanc@FreeBSD.org
COMMENT=	Alternative implementation of curl written in Golang

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC_kurly}/LICENSE

BUILD_DEPENDS=	go:lang/go

USE_GITLAB=	nodefault
GL_TUPLE=	davidjpeacock:kurly:369c1998dfbfca7043f8c995c8ef8714496530ea:kurly/src/gitlab.com/davidjpeacock/kurly

USE_GITHUB=	nodefault
GH_TUPLE=	aki237:nscjar:e2df936:nscjar/src/github.com/aki237/nscjar \
		alsm:ioprogress:063c372:ioprogress/src/github.com/alsm/ioprogress \
		urfave:cli:8e01ec4:ucli/src/github.com/urfave/cli

PLIST_FILES=	bin/kurly

do-build:
	cd ${WRKSRC_kurly} && \
		${SETENV} ${MAKE_ENV} CGO_ENABLED=0 GOPATH=${WRKSRC} go build -o ${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC_kurly}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
