PORTNAME=	vultr-cli
DISTVERSIONPREFIX=	v
DISTVERSION=	2.17.0
PORTREVISION=	15
CATEGORIES=	www

MAINTAINER=	antranigv@freebsd.am
COMMENT=	Official command line tool for Vultr services
WWW=		https://github.com/vultr/vultr-cli

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	vultr
GH_TUPLE=	\
		fsnotify:fsnotify:v1.6.0:fsnotify_fsnotify/vendor/github.com/fsnotify/fsnotify \
		go-check:check:10cb98267c6c:go_check_check/vendor/gopkg.in/check.v1 \
		go-ini:ini:v1.67.0:go_ini_ini/vendor/gopkg.in/ini.v1 \
		go-yaml:yaml:v3.0.1:go_yaml_yaml/vendor/gopkg.in/yaml.v3 \
		golang:appengine:v1.6.7:golang_appengine/vendor/google.golang.org/appengine \
		golang:net:v0.11.0:golang_net/vendor/golang.org/x/net \
		golang:oauth2:v0.9.0:golang_oauth2/vendor/golang.org/x/oauth2 \
		golang:protobuf:v1.5.3:golang_protobuf/vendor/github.com/golang/protobuf \
		golang:sys:v0.9.0:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.10.0:golang_text/vendor/golang.org/x/text \
		google:go-querystring:v1.1.0:google_go_querystring/vendor/github.com/google/go-querystring \
		hashicorp:go-cleanhttp:v0.5.2:hashicorp_go_cleanhttp/vendor/github.com/hashicorp/go-cleanhttp \
		hashicorp:go-retryablehttp:v0.7.4:hashicorp_go_retryablehttp/vendor/github.com/hashicorp/go-retryablehttp \
		hashicorp:hcl:v1.0.0:hashicorp_hcl/vendor/github.com/hashicorp/hcl \
		inconshreveable:mousetrap:v1.1.0:inconshreveable_mousetrap/vendor/github.com/inconshreveable/mousetrap \
		magiconair:properties:v1.8.7:magiconair_properties/vendor/github.com/magiconair/properties \
		mitchellh:mapstructure:v1.5.0:mitchellh_mapstructure/vendor/github.com/mitchellh/mapstructure \
		pelletier:go-toml:v2.0.8:pelletier_go_toml_v2/vendor/github.com/pelletier/go-toml/v2 \
		protocolbuffers:protobuf-go:v1.30.0:protocolbuffers_protobuf_go/vendor/google.golang.org/protobuf \
		spf13:afero:v1.9.5:spf13_afero/vendor/github.com/spf13/afero \
		spf13:cast:v1.5.1:spf13_cast/vendor/github.com/spf13/cast \
		spf13:cobra:v1.7.0:spf13_cobra/vendor/github.com/spf13/cobra \
		spf13:jwalterweatherman:v1.1.0:spf13_jwalterweatherman/vendor/github.com/spf13/jwalterweatherman \
		spf13:pflag:v1.0.5:spf13_pflag/vendor/github.com/spf13/pflag \
		spf13:viper:v1.16.0:spf13_viper/vendor/github.com/spf13/viper \
		subosito:gotenv:v1.4.2:subosito_gotenv/vendor/github.com/subosito/gotenv \
		vultr:govultr:v3.0.3:vultr_govultr_v3/vendor/github.com/vultr/govultr/v3

PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	CHANGELOG.md README.md

OPTIONS_DEFINE=		DOCS
OPTIONS_DEFAULT=	DOCS

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
