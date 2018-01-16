# $FreeBSD$

PORTNAME=	circonus-agent
DISTVERSIONPREFIX=	v
DISTVERSION=	0.9.1
CATEGORIES=	sysutils

MAINTAINER=	sam.gwydir@joyent.com
COMMENT=	Circonus host agent for metric collection

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
BUILD_DEPENDS=	go>=1.8:lang/go

GH_TUPLE=	circonus-labs:circonus-agent:${DISTVERSIONPREFIX}${DISTVERSION}:DEFAULT/src/github.com/circonus-labs/circonus-agent \
		alecthomas:units:2efee85:units/src/github.com/alecthomas/units \
		pkg:errors:645ef00:errors/src/github.com/pkg/errors \
		rs:zerolog:3ac71fc:zerolog/src/github.com/rs/zerolog \
		spf13:cobra:7b2c5ac:cobra/src/github.com/spf13/cobra \
		spf13:viper:25b30aa:viper/src/github.com/spf13/viper \
		golang:sys:8b4580a:sys/src/golang.org/x/sys \
		xi2:httpgzip:2d8bcdd:httpgzip/src/xi2.org/x/httpgzip \
		pelletier:go-toml:16398ba:go_toml/src/github.com/pelletier/go-toml \
		maier:go-appstats:812a586:go_appstats/src/github.com/maier/go-appstats \
		circonus-labs:circonus-gometrics:b25d14e:circonus_gometrics/src/github.com/circonus-labs/circonus-gometrics \
		go-tomb:tomb:d5d1b58:tomb2/src/gopkg.in/tomb.v2 \
		go-yaml:yaml:4c78c97:yaml2/src/gopkg.in/yaml.v2 \
		go-ole:go-ole:a41e3c4:go_ole/src/github.com/go-ole/go-ole \
		circonus-labs:circonusllhist:6e85b93:circonusllhist/src/github.com/circonus-labs/circonusllhist \
		fsnotify:fsnotify:4da3e2c:fsnotify/src/github.com/fsnotify/fsnotify \
		hashicorp:go-retryablehttp:794af36:go_retryablehttp/src/github.com/hashicorp/go-retryablehttp \
		spf13:pflag:e57e3ee:pflag/src/github.com/spf13/pflag \
		hashicorp:go-cleanhttp:06c9ea3:go_cleanhttp/src/github.com/hashicorp/go-cleanhttp \
		hashicorp:hcl:23c074d:hcl/src/github.com/hashicorp/hcl \
		magiconair:properties:49d762b:properties/src/github.com/magiconair/properties \
		mitchellh:mapstructure:06020f8:mapstructure/src/github.com/mitchellh/mapstructure \
		spf13:afero:8d919cb:afero/src/github.com/spf13/afero \
		spf13:cast:acbeb36:cast/src/github.com/spf13/cast \
		spf13:jWalterWeatherman:12bd96e:jWalterWeatherman/src/github.com/spf13/jwalterweatherman \
		golang:text:6353ef0:text/src/golang.org/x/text \
		tv42:httpunix:b75d861:httpunix/src/github.com/tv42/httpunix \
		prometheus:client_model:99fa1f4:client_model/src/github.com/prometheus/client_model \
		golang:protobuf:8ee7999:protobuf/src/github.com/golang/protobuf \
		prometheus:common:2e54d0b:common/src/github.com/prometheus/common \
		matttproud:golang_protobuf_extensions:c12348c:golang_protobuf_extensions/src/github.com/matttproud/golang_protobuf_extensions

ETCDIR=		${PREFIX}/etc/circonus-agentd
PLIST_FILES=	bin/circonus-agentd "@dir ${ETCDIR}"

do-build:
	( cd ${WRKSRC}; \
		${SETENV} ${BUILD_ENV} GOPATH=${WRKSRC} \
		go build ${BUILD_FLAGS} -o bin/circonus-agentd )

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/circonus-agentd ${STAGEDIR}${PREFIX}/bin/circonus-agentd
	@${MKDIR} ${STAGEDIR}${ETCDIR}

.include <bsd.port.mk>
