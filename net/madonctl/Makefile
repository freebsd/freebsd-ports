# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	madonctl
PORTVERSION=	2.3.1
DISTVERSIONPREFIX=	v
CATEGORIES=	net
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	CLI client for the Mastodon social network API

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

GO_PKGNAME=	github.com/${GH_ACCOUNT}/${GH_PROJECT}
USES=		go

PLIST_FILES=	bin/madonctl

GH_ACCOUNT=	McKael
GH_TUPLE=	McKael:madon:v2.3.0:madon/../src/github.com/McKael/madon \
		fsnotify:fsnotify:v1.4.7:fsnotify/../src/github.com/fsnotify/fsnotify \
		ghodss:yaml:v1.0.0:yaml/../src/github.com/ghodss/yaml \
		go-yaml:yaml:v2.1.1:yaml2/../src/gopkg.in/yaml.v2 \
		golang:net:6078986:net/../src/golang.org/x/net \
		golang:oauth2:fdc9e63:oauth2/../src/golang.org/x/oauth2 \
		golang:sys:1e3c777:sys/../src/golang.org/x/sys \
		golang:text:8c34f84:text/../src/golang.org/x/text \
		gorilla:websocket:v1.2.0:websocket/../src/github.com/gorilla/websocket \
		hashicorp:hcl:f40e974:hcl/../src/github.com/hashicorp/hcl \
		kr:text:7cafcd8:text2/../src/github.com/kr/text \
		magiconair:properties:v1.7.6:properties/../src/github.com/magiconair/properties \
		mattn:go:go1.9.1:go/../src/github.com/mattn/go \
		mattn:go-isatty:v0.0.3:goisatty/../src/github.com/mattn/go-isatty \
		mitchellh:mapstructure:00c29f5:mapstructure/../src/github.com/mitchellh/mapstructure \
		pelletier:go-toml:v1.1.0:gotoml/../src/github.com/pelletier/go-toml \
		pkg:errors:v0.8.0:errors/../src/github.com/pkg/errors \
		sendgrid:rest:v2.4.0:rest/../src/github.com/sendgrid/rest \
		sgoertzen:html2text:491ddf8:html2text/../src/github.com/sgoertzen/html2text \
		spf13:afero:v1.0.2:afero/../src/github.com/spf13/afero \
		spf13:cast:v1.2.0:cast/../src/github.com/spf13/cast \
		spf13:cobra:v0.0.1:cobra/../src/github.com/spf13/cobra \
		spf13:pflag:v1.0.0:pflag/../src/github.com/spf13/pflag \
		spf13:viper:v1.0.2:viper/../src/github.com/spf13/viper \
		spf13:jWalterWeatherman:7c0cea3:jWalterWeatherman/../src/github.com/spf13/jwalterweatherman \
		stretchr:testify:v1.2.1:testify/../src/github.com/stretchr/testify
USE_GITHUB=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/bin/madonctl ${STAGEDIR}${PREFIX}/bin/madonctl

.include <bsd.port.mk>
