PORTNAME=	chrono
DISTVERSIONPREFIX=	v
DISTVERSION=	1.1.0-4
DISTVERSIONSUFFIX=	-g70cda7f
PORTREVISION=	28
CATEGORIES=	misc
PKGNAMESUFFIX=	-time-tracking

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Fast time tracking tool made with love
WWW=		https://github.com/gochrono/chrono

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	gochrono
GH_TUPLE=	\
		SaidinWoT:timespan:a3d8e4741124:saidinwot_timespan/vendor/github.com/SaidinWoT/timespan \
		davecgh:go-spew:v1.1.1:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		dustin:go-humanize:v1.0.0:dustin_go_humanize/vendor/github.com/dustin/go-humanize \
		fsnotify:fsnotify:v1.4.7:fsnotify_fsnotify/vendor/github.com/fsnotify/fsnotify \
		go-resty:resty:v1.9.1:go_resty_resty/vendor/gopkg.in/resty.v1 \
		go-yaml:yaml:v2.2.2:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		gofrs:uuid:v3.1.0:gofrs_uuid/vendor/github.com/gofrs/uuid \
		golang:appengine:v1.2.0:golang_appengine/vendor/google.golang.org/appengine \
		golang:net:f5e5bdd77824:golang_net/vendor/golang.org/x/net \
		golang:protobuf:v1.2.0:golang_protobuf/vendor/github.com/golang/protobuf \
		golang:sys:v0.5.0:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.3.0:golang_text/vendor/golang.org/x/text \
		gookit:color:v1.1.6:gookit_color/vendor/github.com/gookit/color \
		hashicorp:hcl:v1.0.0:hashicorp_hcl/vendor/github.com/hashicorp/hcl \
		inconshreveable:mousetrap:v1.0.0:inconshreveable_mousetrap/vendor/github.com/inconshreveable/mousetrap \
		jinzhu:now:v1.1.1:jinzhu_now/vendor/github.com/jinzhu/now \
		kirsle:configdir:e45d2f54772f:kirsle_configdir/vendor/github.com/kirsle/configdir \
		magefile:mage:v1.6.2:magefile_mage/vendor/github.com/magefile/mage \
		magiconair:properties:v1.8.0:magiconair_properties/vendor/github.com/magiconair/properties \
		mitchellh:mapstructure:v1.1.2:mitchellh_mapstructure/vendor/github.com/mitchellh/mapstructure \
		pelletier:go-toml:v1.2.0:pelletier_go_toml/vendor/github.com/pelletier/go-toml \
		pmezard:go-difflib:v1.0.0:pmezard_go_difflib/vendor/github.com/pmezard/go-difflib \
		spf13:afero:v1.1.2:spf13_afero/vendor/github.com/spf13/afero \
		spf13:cast:v1.3.0:spf13_cast/vendor/github.com/spf13/cast \
		spf13:cobra:v0.0.3:spf13_cobra/vendor/github.com/spf13/cobra \
		spf13:jwalterweatherman:v1.0.0:spf13_jwalterweatherman/vendor/github.com/spf13/jwalterweatherman \
		spf13:pflag:v1.0.3:spf13_pflag/vendor/github.com/spf13/pflag \
		spf13:viper:v1.3.1:spf13_viper/vendor/github.com/spf13/viper \
		stretchr:testify:v1.2.2:stretchr_testify/vendor/github.com/stretchr/testify \
		vmihailenco:msgpack:v4.0.0:vmihailenco_msgpack/vendor/github.com/vmihailenco/msgpack

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
