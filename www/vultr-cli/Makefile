PORTNAME=	vultr-cli
DISTVERSIONPREFIX=	v
DISTVERSION=	3.6.0
PORTREVISION=	1
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
		fsnotify:fsnotify:v1.8.0:fsnotify_fsnotify/vendor/github.com/fsnotify/fsnotify \
		go-check:check:10cb98267c6c:go_check_check/vendor/gopkg.in/check.v1 \
		go-viper:mapstructure:v2.3.0:go_viper_mapstructure_v2/vendor/github.com/go-viper/mapstructure/v2 \
		go-yaml:yaml:v3.0.1:go_yaml_yaml/vendor/gopkg.in/yaml.v3 \
		golang:oauth2:v0.30.0:golang_oauth2/vendor/golang.org/x/oauth2 \
		golang:sys:v0.29.0:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.21.0:golang_text/vendor/golang.org/x/text \
		google:go-querystring:v1.1.0:google_go_querystring/vendor/github.com/google/go-querystring \
		hashicorp:go-cleanhttp:v0.5.2:hashicorp_go_cleanhttp/vendor/github.com/hashicorp/go-cleanhttp \
		hashicorp:go-retryablehttp:v0.7.8:hashicorp_go_retryablehttp/vendor/github.com/hashicorp/go-retryablehttp \
		inconshreveable:mousetrap:v1.1.0:inconshreveable_mousetrap/vendor/github.com/inconshreveable/mousetrap \
		pelletier:go-toml:v2.2.3:pelletier_go_toml_v2/vendor/github.com/pelletier/go-toml/v2 \
		sagikazarmark:locafero:v0.7.0:sagikazarmark_locafero/vendor/github.com/sagikazarmark/locafero \
		sourcegraph:conc:v0.3.0:sourcegraph_conc/vendor/github.com/sourcegraph/conc \
		spf13:afero:v1.12.0:spf13_afero/vendor/github.com/spf13/afero \
		spf13:cast:v1.7.1:spf13_cast/vendor/github.com/spf13/cast \
		spf13:cobra:v1.9.1:spf13_cobra/vendor/github.com/spf13/cobra \
		spf13:pflag:v1.0.6:spf13_pflag/vendor/github.com/spf13/pflag \
		spf13:viper:v1.20.1:spf13_viper/vendor/github.com/spf13/viper \
		subosito:gotenv:v1.6.0:subosito_gotenv/vendor/github.com/subosito/gotenv \
		uber-go:atomic:v1.9.0:uber_go_atomic/vendor/go.uber.org/atomic \
		uber-go:multierr:v1.9.0:uber_go_multierr/vendor/go.uber.org/multierr \
		vultr:govultr:v3.21.1:vultr_govultr_v3/vendor/github.com/vultr/govultr/v3

PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	CHANGELOG.md README.md

OPTIONS_DEFINE=		DOCS
OPTIONS_DEFAULT=	DOCS

post-extract:
	${CP} ${FILESDIR}/modules.txt ${WRKSRC}/vendor

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
