# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	madonctl
PORTVERSION=	2.3.1
DISTVERSIONPREFIX=	v
PORTREVISION=	5
CATEGORIES=	net

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	CLI client for the Mastodon social network API

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

PLIST_FILES=	bin/madonctl

GH_ACCOUNT=	McKael
GH_TAGNAME=	b936445
GH_TUPLE=	McKael:madon:v2.3.0:McKael_madon/vendor/github.com/McKael/madon/v2 \
		fsnotify:fsnotify:v1.4.7:fsnotify_fsnotify/vendor/github.com/fsnotify/fsnotify \
		ghodss:yaml:v1.0.0:ghodss_yaml/vendor/github.com/ghodss/yaml \
		go-yaml:yaml:v2.2.2:goyaml_yaml/vendor/gopkg.in/yaml.v2 \
		golang:net:ba9fcec:golang_net/vendor/golang.org/x/net \
		golang:oauth2:0f29369:golang_oauth2/vendor/golang.org/x/oauth2 \
		golang:sys:749cb33:golang_sys/vendor/golang.org/x/sys \
		golang:text:3d0f797:golang_text/vendor/golang.org/x/text \
		gorilla:websocket:v1.4.1:gorilla_websocket/vendor/github.com/gorilla/websocket \
		hashicorp:hcl:v1.0.0:hashicorp_hcl/vendor/github.com/hashicorp/hcl \
		kr:text:v0.1.0:kr_text/vendor/github.com/kr/text \
		magiconair:properties:v1.8.1:magiconair_properties/vendor/github.com/magiconair/properties \
		mattn:go:go1.9.1:imattn_go/vendor/github.com/mattn/go \
		mattn:go-isatty:v0.0.9:mattn_goisatty/vendor/github.com/mattn/go-isatty \
		mitchellh:mapstructure:v1.1.2:mitchellh_mapstructure/vendor/github.com/mitchellh/mapstructure \
		pelletier:go-toml:v1.4.0:pelletier_gotoml/vendor/github.com/pelletier/go-toml \
		pkg:errors:v0.8.1:pkg_errors/vendor/github.com/pkg/errors \
		sendgrid:rest:v2.4.1:sendgrid_rest/vendor/github.com/sendgrid/rest \
		sgoertzen:html2text:491ddf8:sgoertzen_html2text/vendor/github.com/sgoertzen/html2text \
		spf13:afero:v1.2.2:spf13_afero/vendor/github.com/spf13/afero \
		spf13:cast:v1.3.0:spf13_cast/vendor/github.com/spf13/cast \
		spf13:cobra:v0.0.5:spf13_cobra/vendor/github.com/spf13/cobra \
		spf13:jwalterweatherman:v1.1.0:spf13_jwalterweatherman/vendor/github.com/spf13/jwalterweatherman \
		spf13:pflag:v1.0.3:spf13_pflag/vendor/github.com/spf13/pflag \
		spf13:viper:v1.4.0:spf13_viper/vendor/github.com/spf13/viper \
		stretchr:testify:v1.4.0:stretchr_testify/vendor/github.com/stretchr/testify
USE_GITHUB=	yes

.include <bsd.port.mk>
