PORTNAME=	mirrorselect
DISTVERSIONPREFIX=	v
DISTVERSION=	0.9.0
PORTREVISION=	30
CATEGORIES=	www ports-mgmt

MAINTAINER=	aly@aaronly.me
COMMENT=	HTTP service that selects pkg(8) mirrors near to the client
WWW=		https://github.com/DragonFlyBSD/mirrorselect

LICENSE=	BSD3CLAUSE

USES=		go:modules
USE_RC_SUBR=	${PORTNAME}
SUB_FILES=	${PORTNAME}

USE_GITHUB=	yes
GH_ACCOUNT=	DragonFlyBSD

GH_TUPLE=	\
		fsnotify:fsnotify:v1.4.7:fsnotify_fsnotify/vendor/github.com/fsnotify/fsnotify \
		gin-contrib:sse:v0.1.0:gin_contrib_sse/vendor/github.com/gin-contrib/sse \
		gin-gonic:gin:v1.6.3:gin_gonic_gin/vendor/github.com/gin-gonic/gin \
		go-ini:ini:v1.51.0:go_ini_ini/vendor/gopkg.in/ini.v1 \
		go-playground:locales:v0.13.0:go_playground_locales/vendor/github.com/go-playground/locales \
		go-playground:universal-translator:v0.17.0:go_playground_universal_translator/vendor/github.com/go-playground/universal-translator \
		go-playground:validator:v10.2.0:go_playground_validator_v10/vendor/github.com/go-playground/validator/v10 \
		go-yaml:yaml:v2.2.8:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		golang:protobuf:v1.3.3:golang_protobuf/vendor/github.com/golang/protobuf \
		golang:sys:v0.6.0:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.3.2:golang_text/vendor/golang.org/x/text \
		hashicorp:hcl:v1.0.0:hashicorp_hcl/vendor/github.com/hashicorp/hcl \
		jlaffaye:ftp:9aae4d151126:jlaffaye_ftp/vendor/github.com/jlaffaye/ftp \
		json-iterator:go:v1.1.9:json_iterator_go/vendor/github.com/json-iterator/go \
		leodido:go-urn:v1.2.0:leodido_go_urn/vendor/github.com/leodido/go-urn \
		magiconair:properties:v1.8.1:magiconair_properties/vendor/github.com/magiconair/properties \
		mattn:go-isatty:v0.0.12:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		mitchellh:mapstructure:v1.1.2:mitchellh_mapstructure/vendor/github.com/mitchellh/mapstructure \
		modern-go:concurrent:bacd9c7ef1dd:modern_go_concurrent/vendor/github.com/modern-go/concurrent \
		modern-go:reflect2:v1.0.1:modern_go_reflect2/vendor/github.com/modern-go/reflect2 \
		oschwald:maxminddb-golang:v1.8.0:oschwald_maxminddb_golang/vendor/github.com/oschwald/maxminddb-golang \
		pelletier:go-toml:v1.2.0:pelletier_go_toml/vendor/github.com/pelletier/go-toml \
		spf13:afero:v1.1.2:spf13_afero/vendor/github.com/spf13/afero \
		spf13:cast:v1.3.0:spf13_cast/vendor/github.com/spf13/cast \
		spf13:jwalterweatherman:v1.0.0:spf13_jwalterweatherman/vendor/github.com/spf13/jwalterweatherman \
		spf13:pflag:v1.0.3:spf13_pflag/vendor/github.com/spf13/pflag \
		spf13:viper:v1.7.1:spf13_viper/vendor/github.com/spf13/viper \
		subosito:gotenv:v1.2.0:subosito_gotenv/vendor/github.com/subosito/gotenv \
		ugorji:go:v1.1.7:ugorji_go_codec/vendor/github.com/ugorji/go

PLIST_FILES=	${LOCALBASE}/bin/${PORTNAME} \
		"@dir ${ETCDIR}/mirrorselect" \
		"@sample ${ETCDIR}/${PORTNAME}.toml.sample" \
		"@sample ${ETCDIR}/mirrors.toml.sample"

post-install:
	${MKDIR} ${STAGEDIR}${ETCDIR}/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.toml \
		${STAGEDIR}${ETCDIR}/${PORTNAME}.toml.sample
	${INSTALL_DATA} ${WRKSRC}/mirrors.toml \
		${STAGEDIR}${ETCDIR}/mirrors.toml.sample

.include <bsd.port.mk>
