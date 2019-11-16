# $FreeBSD$

PORTNAME=	cloud-print-connector
PORTVERSION=	1.16
DISTVERSIONPREFIX=	v
PORTREVISION=	2
CATEGORIES=	print

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Share CUPS printers via Google Cloud Print

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libcups.so:print/cups \
		libavahi-client.so:net/avahi-app \
		libavahi-common.so:net/avahi-app

USES=		compiler go pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	google
GH_SUBDIR=	src/github.com/google/cloud-print-connector
GH_TUPLE=	urfave:cli:8e01ec4:cli/vendor/github.com/urfave/cli \
		satori:go.uuid:36e9d2e:gouuid/vendor/github.com/satori/go.uuid \
		coreos:go-systemd:88bfeed:gosystemd/vendor/github.com/coreos/go-systemd \
		golang:oauth2:ef14785:oauth2/vendor/golang.org/x/oauth2 \
		golang:net:039a425:net/vendor/golang.org/x/net \
		mildred:go-xdg:96b70c9:xdg/vendor/launchpad.net/go-xdg/v0
USE_RC_SUBR=	gcp-cups-connectord

GO_TARGET=	./gcp-connector-util ./gcp-cups-connector
PLIST_FILES=	${GO_TARGET:S/./bin/}

OPTIONS_DEFINE=	DOCS

PORTDOCS=	CONTRIBUTING.md README.md

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for doc in ${PORTDOCS}
	${CP} ${WRKSRC}/${doc} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
