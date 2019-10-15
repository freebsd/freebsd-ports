# Created by: Steve Wills <swills@FreeBSD.org>
# $FreeBSD$

PORTNAME=	consul-template
PORTVERSION=	0.22.0
DISTVERSIONPREFIX=	v
CATEGORIES=	textproc

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Generic template rendering and notifications with Consul

LICENSE=	MPL20

USES=		go:modules

USE_GITHUB=	yes
GHTAG=		6cae10fe
GH_TUPLE=	hashicorp:${PORTNAME}:${DISTVERSIONPREFIX}${PORTVERSION}:DEFAULT/src/github.com/hashicorp/consul-template \
		BurntSushi:toml:v0.3.1:burntsushi_toml/vendor/github.com/BurntSushi/toml \
		armon:go-metrics:ec5e00d3c878:armon_go_metrics/vendor/github.com/armon/go-metrics \
		davecgh:go-spew:v1.1.1:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		go-yaml:yaml:v2.2.2:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		golang:crypto:4def268fd1a4:golang_crypto/vendor/golang.org/x/crypto \
		golang:net:ca1201d0de80:golang_net/vendor/golang.org/x/net \
		golang:snappy:v0.0.1:golang_snappy/vendor/github.com/golang/snappy \
		golang:text:v0.3.2:golang_text/vendor/golang.org/x/text \
		golang:time:9d24e82272b4:golang_time/vendor/golang.org/x/time \
		hashicorp:consul:v1.1.0:hashicorp_consul/vendor/github.com/hashicorp/consul \
		hashicorp:errwrap:v1.0.0:hashicorp_errwrap/vendor/github.com/hashicorp/errwrap \
		hashicorp:go-cleanhttp:v0.5.1:hashicorp_go_cleanhttp/vendor/github.com/hashicorp/go-cleanhttp \
		hashicorp:go-gatedio:v0.5.0:hashicorp_go_gatedio/vendor/github.com/hashicorp/go-gatedio \
		hashicorp:go-immutable-radix:v1.1.0:hashicorp_go_immutable_radix/vendor/github.com/hashicorp/go-immutable-radix \
		hashicorp:go-multierror:v1.0.0:hashicorp_go_multierror/vendor/github.com/hashicorp/go-multierror \
		hashicorp:go-retryablehttp:v0.5.4:hashicorp_go_retryablehttp/vendor/github.com/hashicorp/go-retryablehttp \
		hashicorp:go-rootcerts:v1.0.1:hashicorp_go_rootcerts/vendor/github.com/hashicorp/go-rootcerts \
		hashicorp:go-sockaddr:v1.0.2:hashicorp_go_sockaddr/vendor/github.com/hashicorp/go-sockaddr \
		hashicorp:go-syslog:v1.0.0:hashicorp_go_syslog/vendor/github.com/hashicorp/go-syslog \
		hashicorp:go-uuid:v1.0.1:hashicorp_go_uuid/vendor/github.com/hashicorp/go-uuid \
		hashicorp:golang-lru:v0.5.3:hashicorp_golang_lru/vendor/github.com/hashicorp/golang-lru \
		hashicorp:hcl:v1.0.0:hashicorp_hcl/vendor/github.com/hashicorp/hcl \
		hashicorp:logutils:v1.0.0:hashicorp_logutils/vendor/github.com/hashicorp/logutils \
		hashicorp:serf:v0.8.3:hashicorp_serf/vendor/github.com/hashicorp/serf \
		hashicorp:vault:746c0b111519:hashicorp_vault/vendor/github.com/hashicorp/vault \
		mattn:go-shellwords:v1.0.5:mattn_go_shellwords/vendor/github.com/mattn/go-shellwords \
		mitchellh:go-homedir:v1.1.0:mitchellh_go_homedir/vendor/github.com/mitchellh/go-homedir \
		mitchellh:go-testing-interface:v1.0.0:mitchellh_go_testing_interface/vendor/github.com/mitchellh/go-testing-interface \
		mitchellh:hashstructure:v1.0.0:mitchellh_hashstructure/vendor/github.com/mitchellh/hashstructure \
		mitchellh:mapstructure:v1.1.2:mitchellh_mapstructure/vendor/github.com/mitchellh/mapstructure \
		pierrec:lz4:v2.2.5:pierrec_lz4/vendor/github.com/pierrec/lz4 \
		pkg:errors:v0.8.1:pkg_errors/vendor/github.com/pkg/errors \
		pmezard:go-difflib:v1.0.0:pmezard_go_difflib/vendor/github.com/pmezard/go-difflib \
		ryanuber:go-glob:v1.0.0:ryanuber_go_glob/vendor/github.com/ryanuber/go-glob \
		square:go-jose:v2.3.1:square_go_jose/vendor/gopkg.in/square/go-jose.v2 \
		stretchr:testify:v1.3.0:stretchr_testify/vendor/github.com/stretchr/testify

GO_BUILDFLAGS=	-ldflags='\
		-s -w -X github.com/hashicorp/consul-template/version.Name=${PORTNAME} \
		-X github.com/hashicorp/consul-template/version.GitCommit=${GHTAG}'
PLIST_FILES=	bin/consul-template

USE_RC_SUBR=	consul-template

.include <bsd.port.mk>
