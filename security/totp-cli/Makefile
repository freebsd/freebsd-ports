# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	totp-cli
PORTVERSION=	1.1.8
DISTVERSIONPREFIX=	v
PORTREVISION=	1
CATEGORIES=	security

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Authy/Google Authenticator like TOTP CLI tool

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.md

USES=		go:modules

PLIST_FILES=	bin/totp-cli

GH_ACCOUNT=	yitsushi
GH_TUPLE=	golang:crypto:71b5226:golang_crypto/vendor/golang.org/x/crypto \
		golang:sys:749cb33:golang_sys/vendor/golang.org/x/sys \
		kardianos:osext:2bc1f35:kardianos_osext/vendor/github.com/kardianos/osext \
		mitchellh:go-homedir:v1.1.0:mitchellh_gohomedir/vendor/github.com/mitchellh/go-homedir \
		yitsushi:github-release-check:v1.0.1:yitsushi_github_release_check/vendor/github.com/yitsushi/github-release-check \
		yitsushi:go-commander:v1.1.0:yitsushi_go_commander/vendor/github.com/yitsushi/go-commander
USE_GITHUB=	yes

.include <bsd.port.mk>
