# $FreeBSD$

PORTNAME=	circonus-agent
DISTVERSIONPREFIX=	v
DISTVERSION=	0.13.0
CATEGORIES=	sysutils

MAINTAINER=	sam.gwydir@joyent.com
COMMENT=	Circonus host agent for metric collection

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go

USE_GITHUB=	yes

GH_ACCOUNT=	circonus-labs
GH_SUBDIR=	src/github.com/circonus-labs/circonus-agent
GH_TUPLE=	alecthomas:units:2efee85:units/src/github.com/alecthomas/units \
		pkg:errors:645ef00:errors/src/github.com/pkg/errors \
		rs:zerolog:56a970de:zerolog/src/github.com/rs/zerolog \
		spf13:cobra:c439c4fa:cobra/src/github.com/spf13/cobra \
		spf13:viper:b5e8006c:viper/src/github.com/spf13/viper \
		golang:sys:7ceb54c8:sys/src/golang.org/x/sys \
		xi2:httpgzip:2d8bcdd:httpgzip/src/xi2.org/x/httpgzip \
		pelletier:go-toml:acdc4509:go_toml/src/github.com/pelletier/go-toml \
		maier:go-appstats:812a586:go_appstats/src/github.com/maier/go-appstats \
		circonus-labs:circonus-gometrics:b25d14e:circonus_gometrics/src/github.com/circonus-labs/circonus-gometrics \
		go-tomb:tomb:d5d1b58:tomb2/src/gopkg.in/tomb.v2 \
		go-yaml:yaml:7f97868e:yaml2/src/gopkg.in/yaml.v2 \
		go-ole:go-ole:a41e3c4:go_ole/src/github.com/go-ole/go-ole \
		circonus-labs:circonusllhist:1e65893c:circonusllhist/src/github.com/circonus-labs/circonusllhist \
		fsnotify:fsnotify:c2828203:fsnotify/src/github.com/fsnotify/fsnotify \
		hashicorp:go-retryablehttp:794af36:go_retryablehttp/src/github.com/hashicorp/go-retryablehttp \
		spf13:pflag:e57e3ee:pflag/src/github.com/spf13/pflag \
		hashicorp:go-cleanhttp:d5fe4b57:go_cleanhttp/src/github.com/hashicorp/go-cleanhttp \
		hashicorp:hcl:23c074d:hcl/src/github.com/hashicorp/hcl \
		magiconair:properties:c3beff4c:properties/src/github.com/magiconair/properties \
		mitchellh:mapstructure:00c29f56:mapstructure/src/github.com/mitchellh/mapstructure \
		spf13:afero:bb8f1927:afero/src/github.com/spf13/afero \
		spf13:cast:8965335b:cast/src/github.com/spf13/cast \
		spf13:jWalterWeatherman:7c0cea34:jWalterWeatherman/src/github.com/spf13/jwalterweatherman \
		golang:text:f21a4dfb:text/src/golang.org/x/text \
		tv42:httpunix:b75d861:httpunix/src/github.com/tv42/httpunix \
		prometheus:client_model:99fa1f4:client_model/src/github.com/prometheus/client_model \
		golang:protobuf:8ee7999:protobuf/src/github.com/golang/protobuf \
		prometheus:common:e4aa40a9:common/src/github.com/prometheus/common \
		matttproud:golang_protobuf_extensions:3247c845:golang_protobuf_extensions/src/github.com/matttproud/golang_protobuf_extensions

ETCDIR=		${PREFIX}/etc/circonus-agentd
PLIST_FILES=	bin/circonus-agentd "@dir ${ETCDIR}"

do-build:
	( cd ${WRKSRC}; \
		${SETENV} ${MAKE_ENV} ${BUILD_ENV} GOPATH=${WRKSRC} \
		go build ${BUILD_FLAGS} -o bin/circonus-agentd )

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/circonus-agentd ${STAGEDIR}${PREFIX}/bin/circonus-agentd
	@${MKDIR} ${STAGEDIR}${ETCDIR}

.include <bsd.port.mk>
