# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	madonctl
PORTVERSION=	1.2.0
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
GH_TUPLE=	McKael:madon:v1.6.0:madon/../src/github.com/McKael/madon \
		fsnotify:fsnotify:v1.4.2:fsnotify/../src/github.com/fsnotify/fsnotify \
		ghodss:yaml:v1.0.0:yaml/../src/github.com/ghodss/yaml \
		go-yaml:yaml:cd8b52f:yaml2/../src/gopkg.in/yaml.v2 \
		golang:net:5139290:net/../src/golang.org/x/net \
		golang:oauth2:f047394:oauth2/../src/golang.org/x/oauth2 \
		golang:sys:a2e06a1:sys/../src/golang.org/x/sys \
		golang:text:19e5161:text/../src/golang.org/x/text \
		gorilla:websocket:v1.1.0:websocket/../src/github.com/gorilla/websocket \
		hashicorp:hcl:392dba7:hcl/../src/github.com/hashicorp/hcl \
		kr:text:7cafcd8:text2/../src/github.com/kr/text \
		m0t0k1ch1:gomif:v0.3.0:gomif/../src/github.com/m0t0k1ch1/gomif \
		magiconair:properties:v1.7.2:properties/../src/github.com/magiconair/properties \
		mattn:go-isatty:v0.0.2:goisatty/../src/github.com/mattn/go-isatty \
		mitchellh:mapstructure:d0303fe:mapstructure/../src/github.com/mitchellh/mapstructure \
		pelletier:go-toml:v0.5.0:gotoml/../src/github.com/pelletier/go-toml \
		pelletier:go-buffruneio:v0.2.0:buffruneio/../src/github.com/pelletier/go-buffruneio \
		pkg:errors:v0.8.0:errors/../src/github.com/pkg/errors \
		sendgrid:rest:v2.4.0:rest/../src/github.com/sendgrid/rest \
		spf13:afero:9be6508:afero/../src/github.com/spf13/afero \
		spf13:cast:v1.1.0:cast/../src/github.com/spf13/cast \
		spf13:cobra:e606913:cobra/../src/github.com/spf13/cobra \
		spf13:jWalterWeatherman:0efa520:jWalterWeatherman/../src/github.com/spf13/jwalterweatherman \
		spf13:pflag:e57e3ee:pflag/../src/github.com/spf13/pflag \
		spf13:viper:0967fc9:viper/../src/github.com/spf13/viper
USE_GITHUB=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/bin/madonctl ${STAGEDIR}${PREFIX}/bin/madonctl

.include <bsd.port.mk>
