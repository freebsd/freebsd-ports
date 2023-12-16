PORTNAME=	xcaddy
DISTVERSIONPREFIX=	v
DISTVERSION=	0.3.5
PORTREVISION=	2
CATEGORIES=	www
DIST_SUBDIR=	xcaddy

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Command line tool to make custom builds of the Caddy Web Server
WWW=		https://github.com/caddyserver/xcaddy

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

USE_GITHUB=	yes
GH_ACCOUNT=	caddyserver
GH_TUPLE=	Masterminds:semver:v3.1.1:masterminds_semver_v3/vendor/github.com/Masterminds/semver/v3 \
		google:shlex:e7afc7fbc510:google_shlex/vendor/github.com/google/shlex

GO_TARGET=	./cmd/xcaddy

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
