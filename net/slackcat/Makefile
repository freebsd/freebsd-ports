PORTNAME=	slackcat
DISTVERSION=	1.7.3
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	https://raw.githubusercontent.com/${GH_ACCOUNT}/${GH_PROJECT}/${DISTVERSIONFULL}/:gomod
DISTFILES=	go.mod:gomod

MAINTAINER=	nork@ninth-nine.com
COMMENT=	Simple commandline utility to post snippets to Slack

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	bcicen
GH_TAGNAME=	5c4e4410002c

GO_MODULE=	github.com/${GH_ACCOUNT}/${GH_PROJECT}
GO_BUILDFLAGS=	-ldflags="-s -w -X main.version=${DISTVERSION} -X main.build=${GH_TAGNAME}"

PLIST_FILES=	bin/slackcat

.include <bsd.port.mk>
