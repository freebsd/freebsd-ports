PORTNAME=	slackcat
DISTVERSION=	1.7.3
PORTREVISION=	27
CATEGORIES=	net
MASTER_SITES=	https://raw.githubusercontent.com/${GH_ACCOUNT}/${GH_PROJECT}/${DISTVERSIONFULL}/:gomod
DISTFILES=	go.mod:gomod

MAINTAINER=	nork@FreeBSD.org
COMMENT=	Simple commandline utility to post snippets to Slack
WWW=		https://github.com/bcicen/slackcat

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	bcicen
GH_TAGNAME=	5c4e4410002c
GH_TUPLE=	golang:sys:v0.6.0:sys

GO_MODULE=	github.com/${GH_ACCOUNT}/${GH_PROJECT}
GO_BUILDFLAGS=	-ldflags="-s -w -X main.version=${DISTVERSION} -X main.build=${GH_TAGNAME}"

PLIST_FILES=	bin/slackcat

pre-patch:
	${RM} -r ${WRKSRC}/vendor/golang.org/x/sys
	${LN} -s ${WRKDIR}/sys-* ${WRKSRC}/vendor/golang.org/x/sys

.include <bsd.port.mk>
