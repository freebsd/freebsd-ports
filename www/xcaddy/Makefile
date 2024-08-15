PORTNAME=	xcaddy
DISTVERSIONPREFIX=	v
DISTVERSION=	0.4.2
PORTREVISION=	3
CATEGORIES=	www
DIST_SUBDIR=	xcaddy

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Command line tool to make custom builds of the Caddy Web Server
WWW=		https://github.com/caddyserver/xcaddy

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

# xcaddy actually needs to run the go command to perform builds
RUN_DEPENDS=	go:lang/go

USES=		go:modules

USE_GITHUB=	yes
GH_ACCOUNT=	caddyserver
GH_TUPLE=	Masterminds:semver:v3.2.1:masterminds_semver_v3/vendor/github.com/Masterminds/semver/v3 \
		akavel:rsrc:v0.10.2:akavel_rsrc/vendor/github.com/akavel/rsrc \
		google:shlex:e7afc7fbc510:google_shlex/vendor/github.com/google/shlex \
		josephspurrier:goversioninfo:v1.4.0:josephspurrier_goversioninfo/vendor/github.com/josephspurrier/goversioninfo

GO_TARGET=	./cmd/xcaddy

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
