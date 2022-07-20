PORTNAME=	totp-cli
PORTVERSION=	1.2.1
PORTREVISION=	2
DISTVERSIONPREFIX=	v
CATEGORIES=	security

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Authy/Google Authenticator like TOTP CLI tool

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

PLIST_FILES=	bin/totp-cli

GH_ACCOUNT=	yitsushi
GH_TUPLE=	go-yaml:yaml:v3.0.1:go_yaml_yaml/vendor/gopkg.in/yaml.v3 \
		golang:crypto:0559593:golang_crypto/vendor/golang.org/x/crypto \
		golang:sys:05e143d:golang_sys/vendor/golang.org/x/sys \
		golang:term:065cf7b:golang_term/vendor/golang.org/x/term \
		golang:text:b4bca84:golang_text/vendor/golang.org/x/text \
		kardianos:osext:2bc1f35:kardianos_osext/vendor/github.com/kardianos/osext \
		mitchellh:go-homedir:af06845:mitchellh_gohomedir/vendor/github.com/mitchellh/go-homedir \
		yitsushi:github-release-check:4d0202c:yitsushi_github_release_check/vendor/github.com/yitsushi/github-release-check \
		yitsushi:go-commander:b4d4247:yitsushi_go_commander/vendor/github.com/yitsushi/go-commander
USE_GITHUB=	yes

.include <bsd.port.mk>
