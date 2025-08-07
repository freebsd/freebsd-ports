PORTNAME=		exoscale-cli
DISTVERSIONPREFIX=	v
DISTVERSION=		1.84.0
PORTREVISION=	1
CATEGORIES=		net devel

MAINTAINER=	egypcio@FreeBSD.org
COMMENT=	Manage your Exoscale infrastructure easily from the command-line
WWW=		https://github.com/exoscale/cli

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:1.23,modules
USE_GITHUB=	yes

GH_ACCOUNT=	exoscale
GH_PROJECT=	cli
CGO_ENABLED=	0
GO_BUILDFLAGS=	-ldflags '-s -w -extldflags "-static" -X main.commit= -X main.version=${DISTVERSION}'

PLIST_FILES=	bin/${PORTNAME} \
		bin/exo

post-install:
	${RLN} ${STAGEDIR}/${PREFIX}/bin/${PORTNAME} ${STAGEDIR}/${PREFIX}/bin/exo

.include <bsd.port.mk>
