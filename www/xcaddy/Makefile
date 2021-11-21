PORTNAME=	xcaddy
DISTVERSIONPREFIX=	v
DISTVERSION=	0.2.0
CATEGORIES=	www
DIST_SUBDIR=	xcaddy

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Command line tool to make custom builds of the Caddy Web Server

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cpe go:modules
CPE_VENDOR=	caddyserver

USE_GITHUB=	yes
GH_ACCOUNT=	caddyserver
GH_TUPLE=	Masterminds:semver:v3.1.1:masterminds_semver_v3/vendor/github.com/Masterminds/semver/v3

GO_TARGET=	./cmd/xcaddy

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
