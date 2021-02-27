# $FreeBSD$

PORTNAME=	consul-template
PORTVERSION=	0.25.2
DISTVERSIONPREFIX=	v
CATEGORIES=	textproc

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Generic template rendering and notifications with Consul

LICENSE=	MPL20

USES=		go:modules

USE_GITHUB=	yes
GH_TUPLE=	hashicorp:${PORTNAME}:${DISTVERSIONPREFIX}${PORTVERSION}:DEFAULT/src/github.com/hashicorp/consul-template \
		BurntSushi:toml:v0.3.1:burntsushi_toml/vendor/github.com/BurntSushi/toml \
		armon:go-metrics:v0.3.4:armon_go_metrics/vendor/github.com/armon/go-metrics \
		davecgh:go-spew:v1.1.1:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		fatih:color:v1.9.0:fatih_color/vendor/github.com/fatih/color \
		go-yaml:yaml:v2.3.0:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		golang:crypto:7f63de1d35b0:golang_crypto/vendor/golang.org/x/crypto \
		golang:net:0a1ea396d57c:golang_net/vendor/golang.org/x/net \
		golang:snappy:v0.0.2:golang_snappy/vendor/github.com/golang/snappy \
		golang:sys:fdedc70b468f:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.3.3:golang_text/vendor/golang.org/x/text \
		golang:time:3af7569d3a1e:golang_time/vendor/golang.org/x/time \
		hashicorp:consul:v0.4.1:hashicorp_consul_sdk/vendor/github.com/hashicorp/consul/sdk \
		hashicorp:consul:api/v1.4.0:hashicorp_consul_api/vendor/github.com/hashicorp/consul \
		hashicorp:errwrap:v1.1.0:hashicorp_errwrap/vendor/github.com/hashicorp/errwrap \
		hashicorp:go-cleanhttp:v0.5.1:hashicorp_go_cleanhttp/vendor/github.com/hashicorp/go-cleanhttp \
		hashicorp:go-gatedio:v0.5.0:hashicorp_go_gatedio/vendor/github.com/hashicorp/go-gatedio \
		hashicorp:go-hclog:v0.14.1:hashicorp_go_hclog/vendor/github.com/hashicorp/go-hclog \
		hashicorp:go-immutable-radix:v1.3.0:hashicorp_go_immutable_radix/vendor/github.com/hashicorp/go-immutable-radix \
		hashicorp:go-multierror:v1.1.0:hashicorp_go_multierror/vendor/github.com/hashicorp/go-multierror \
		hashicorp:go-retryablehttp:v0.6.7:hashicorp_go_retryablehttp/vendor/github.com/hashicorp/go-retryablehttp \
		hashicorp:go-rootcerts:v1.0.2:hashicorp_go_rootcerts/vendor/github.com/hashicorp/go-rootcerts \
		hashicorp:go-sockaddr:v1.0.2:hashicorp_go_sockaddr/vendor/github.com/hashicorp/go-sockaddr \
		hashicorp:go-syslog:v1.0.0:hashicorp_go_syslog/vendor/github.com/hashicorp/go-syslog \
		hashicorp:go-uuid:v1.0.1:hashicorp_go_uuid/vendor/github.com/hashicorp/go-uuid \
		hashicorp:golang-lru:v0.5.4:hashicorp_golang_lru/vendor/github.com/hashicorp/golang-lru \
		hashicorp:hcl:v1.0.0:hashicorp_hcl/vendor/github.com/hashicorp/hcl \
		hashicorp:logutils:v1.0.0:hashicorp_logutils/vendor/github.com/hashicorp/logutils \
		hashicorp:serf:v0.9.4:hashicorp_serf/vendor/github.com/hashicorp/serf \
		hashicorp:vault:0dc007d98cc8:hashicorp_vault_sdk/vendor/github.com/hashicorp/vault \
		hashicorp:vault:746c0b111519:hashicorp_vault_api \
		mattn:go-colorable:v0.1.7:mattn_go_colorable/vendor/github.com/mattn/go-colorable \
		mattn:go-isatty:v0.0.12:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		mattn:go-shellwords:v1.0.10:mattn_go_shellwords/vendor/github.com/mattn/go-shellwords \
		mitchellh:go-homedir:v1.1.0:mitchellh_go_homedir/vendor/github.com/mitchellh/go-homedir \
		mitchellh:go-testing-interface:v1.0.0:mitchellh_go_testing_interface/vendor/github.com/mitchellh/go-testing-interface \
		mitchellh:hashstructure:v1.0.0:mitchellh_hashstructure/vendor/github.com/mitchellh/hashstructure \
		mitchellh:mapstructure:v1.3.3:mitchellh_mapstructure/vendor/github.com/mitchellh/mapstructure \
		pierrec:lz4:v2.5.2:pierrec_lz4/vendor/github.com/pierrec/lz4 \
		pkg:errors:v0.9.1:pkg_errors/vendor/github.com/pkg/errors \
		pmezard:go-difflib:v1.0.0:pmezard_go_difflib/vendor/github.com/pmezard/go-difflib \
		ryanuber:go-glob:v1.0.0:ryanuber_go_glob/vendor/github.com/ryanuber/go-glob \
		square:go-jose:v2.5.1:square_go_jose/vendor/gopkg.in/square/go-jose.v2 \
		stretchr:testify:v1.4.0:stretchr_testify/vendor/github.com/stretchr/testify

GO_BUILDFLAGS=	-ldflags='\
		-s -w -X github.com/hashicorp/consul-template/version.Name=${PORTNAME} \
		-X github.com/hashicorp/consul-template/version.GitCommit=release'
PLIST_FILES=	bin/consul-template

USE_RC_SUBR=	consul-template

post-extract:
	@${RM} -r ${WRKSRC}/vendor/github.com/hashicorp/vault/api
	@${RLN} ${WRKSRC_hashicorp_vault_api}/api ${WRKSRC}/vendor/github.com/hashicorp/vault/api

.include <bsd.port.mk>
