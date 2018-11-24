# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	madonctl
PORTVERSION=	2.3.1
DISTVERSIONPREFIX=	v
PORTREVISION=	2
CATEGORIES=	net

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	CLI client for the Mastodon social network API

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go

GO_PKGNAME=	github.com/${GH_ACCOUNT}/${GH_PROJECT}

PLIST_FILES=	bin/madonctl

GH_ACCOUNT=	McKael
GH_TUPLE=	McKael:madon:v2.3.0:McKael_madon/../src/github.com/McKael/madon \
		fsnotify:fsnotify:v1.4.7:fsnotify_fsnotify/../src/github.com/fsnotify/fsnotify \
		ghodss:yaml:v1.0.0:ghodss_yaml/../src/github.com/ghodss/yaml \
		go-yaml:yaml:v2.2.1:goyaml_yaml/../src/gopkg.in/yaml.v2 \
		golang:net:adae6a3:golang_net/../src/golang.org/x/net \
		golang:oauth2:8f65e30:golang_oauth2/../src/golang.org/x/oauth2 \
		golang:sys:62eef0e:golang_sys/../src/golang.org/x/sys \
		golang:text:6f44c5a:golang_text/../src/golang.org/x/text \
		gorilla:websocket:v1.4.0:gorilla_websocket/../src/github.com/gorilla/websocket \
		hashicorp:hcl:v1.0.0:hashicorp_hcl/../src/github.com/hashicorp/hcl \
		kr:text:v0.1.0:kr_text/../src/github.com/kr/text \
		magiconair:properties:v1.8.0:magiconair_properties/../src/github.com/magiconair/properties \
		mattn:go:go1.9.1:imattn_go/../src/github.com/mattn/go \
		mattn:go-isatty:v0.0.4:mattn_goisatty/../src/github.com/mattn/go-isatty \
		mitchellh:mapstructure:v1.1.2:mitchellh_mapstructure/../src/github.com/mitchellh/mapstructure \
		pelletier:go-toml:v1.2.0:pelletier_gotoml/../src/github.com/pelletier/go-toml \
		pkg:errors:v0.8.0:pkg_errors/../src/github.com/pkg/errors \
		sendgrid:rest:v2.4.1:sendgrid_rest/../src/github.com/sendgrid/rest \
		sgoertzen:html2text:491ddf8:sgoertzen_html2text/../src/github.com/sgoertzen/html2text \
		spf13:afero:v1.1.2:spf13_afero/../src/github.com/spf13/afero \
		spf13:cast:v1.3.0:spf13_cast/../src/github.com/spf13/cast \
		spf13:cobra:v0.0.3:spf13_cobra/../src/github.com/spf13/cobra \
		spf13:jwalterweatherman:v1.0.0:spf13_jwalterweatherman/../src/github.com/spf13/jwalterweatherman \
		spf13:pflag:v1.0.3:spf13_pflag/../src/github.com/spf13/pflag \
		spf13:viper:v1.2.1:spf13_viper/../src/github.com/spf13/viper \
		stretchr:testify:v1.2.2:stretchr_testify/../src/github.com/stretchr/testify
USE_GITHUB=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/bin/madonctl ${STAGEDIR}${PREFIX}/bin/madonctl

.include <bsd.port.mk>
