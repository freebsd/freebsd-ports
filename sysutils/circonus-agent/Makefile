# $FreeBSD$

PORTNAME=	circonus-agent
DISTVERSIONPREFIX=	v
DISTVERSION=	0.13.0
CATEGORIES=	sysutils

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Circonus host agent for metric collection

BROKEN=		unfetchable

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go

USE_GITHUB=	yes

GH_ACCOUNT=	circonus-labs
GH_SUBDIR=	src/github.com/circonus-labs/circonus-agent
GH_TUPLE=	alecthomas:units:2efee85:units/vendor/github.com/alecthomas/units \
		pkg:errors:645ef00:errors/vendor/github.com/pkg/errors \
		rs:zerolog:56a970de:zerolog/vendor/github.com/rs/zerolog \
		spf13:cobra:c439c4fa:cobra/vendor/github.com/spf13/cobra \
		spf13:viper:b5e8006c:viper/vendor/github.com/spf13/viper \
		golang:sys:7ceb54c8:sys/vendor/golang.org/x/sys \
		xi2:httpgzip:2d8bcdd:httpgzip/vendor/xi2.org/x/httpgzip \
		pelletier:go-toml:acdc4509:go_toml/vendor/github.com/pelletier/go-toml \
		maier:go-appstats:812a586:go_appstats/vendor/github.com/maier/go-appstats \
		circonus-labs:circonus-gometrics:b25d14e:circonus_gometrics/vendor/github.com/circonus-labs/circonus-gometrics \
		go-tomb:tomb:d5d1b58:tomb2/vendor/gopkg.in/tomb.v2 \
		go-yaml:yaml:7f97868e:yaml2/vendor/gopkg.in/yaml.v2 \
		go-ole:go-ole:a41e3c4:go_ole/vendor/github.com/go-ole/go-ole \
		circonus-labs:circonusllhist:1e65893c:circonusllhist/vendor/github.com/circonus-labs/circonusllhist \
		fsnotify:fsnotify:c2828203:fsnotify/vendor/github.com/fsnotify/fsnotify \
		hashicorp:go-retryablehttp:794af36:go_retryablehttp/vendor/github.com/hashicorp/go-retryablehttp \
		spf13:pflag:e57e3ee:pflag/vendor/github.com/spf13/pflag \
		hashicorp:go-cleanhttp:d5fe4b57:go_cleanhttp/vendor/github.com/hashicorp/go-cleanhttp \
		hashicorp:hcl:23c074d:hcl/vendor/github.com/hashicorp/hcl \
		magiconair:properties:c3beff4c:properties/vendor/github.com/magiconair/properties \
		mitchellh:mapstructure:00c29f56:mapstructure/vendor/github.com/mitchellh/mapstructure \
		spf13:afero:bb8f1927:afero/vendor/github.com/spf13/afero \
		spf13:cast:8965335b:cast/vendor/github.com/spf13/cast \
		spf13:jWalterWeatherman:7c0cea34:jWalterWeatherman/vendor/github.com/spf13/jwalterweatherman \
		golang:text:f21a4dfb:text/vendor/golang.org/x/text \
		tv42:httpunix:b75d861:httpunix/vendor/github.com/tv42/httpunix \
		prometheus:client_model:99fa1f4:client_model/vendor/github.com/prometheus/client_model \
		golang:protobuf:8ee7999:protobuf/vendor/github.com/golang/protobuf \
		prometheus:common:e4aa40a9:common/vendor/github.com/prometheus/common \
		matttproud:golang_protobuf_extensions:3247c845:golang_protobuf_extensions/vendor/github.com/matttproud/golang_protobuf_extensions

GO_TARGET=	:circonus-agentd

ETCDIR=		${PREFIX}/etc/circonus-agentd
PLIST_FILES=	bin/circonus-agentd "@dir ${ETCDIR}"

post-install:
	@${MKDIR} ${STAGEDIR}${ETCDIR}

.include <bsd.port.mk>
