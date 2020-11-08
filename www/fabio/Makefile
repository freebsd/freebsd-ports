# $FreeBSD$

PORTNAME=	fabio
PORTVERSION=	1.5.14
DISTVERSIONPREFIX=	v
CATEGORIES=	www

MAINTAINER=	stl@ossuary.net
COMMENT=	Zero-conf load balancing HTTP(S) router managed by Consul

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	fabiolb
GH_SUBDIR=	src/github.com/fabiolb/fabio
GH_TUPLE=	Shopify:sarama:v1.19.0:shopify_sarama/vendor/github.com/Shopify/sarama \
		apache:thrift:da1169d75b15:apache_thrift/vendor/github.com/apache/thrift \
		armon:go-proxyproto:5b7edb60ff5f:armon_go_proxyproto/vendor/github.com/armon/go-proxyproto \
		circonus-labs:circonus-gometrics:v2.2.4:circonus_labs_circonus_gometrics/vendor/github.com/circonus-labs/circonus-gometrics \
		circonus-labs:circonusllhist:d724266ae527:circonus_labs_circonusllhist/vendor/github.com/circonus-labs/circonusllhist \
		cyberdelia:go-metrics-graphite:b8345b7f01d5:cyberdelia_go_metrics_graphite/vendor/github.com/cyberdelia/go-metrics-graphite \
		davecgh:go-spew:v1.1.1:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		eapache:go-resiliency:v1.1.0:eapache_go_resiliency/vendor/github.com/eapache/go-resiliency \
		eapache:go-xerial-snappy:776d5712da21:eapache_go_xerial_snappy/vendor/github.com/eapache/go-xerial-snappy \
		eapache:queue:v1.1.0:eapache_queue/vendor/github.com/eapache/queue \
		fatih:structs:5ada2f449b10:fatih_structs/vendor/github.com/fatih/structs \
		go-logfmt:logfmt:v0.3.0:go_logfmt_logfmt/vendor/github.com/go-logfmt/logfmt \
		gobwas:glob:19c076cdf202:gobwas_glob/vendor/github.com/gobwas/glob \
		gogo:protobuf:v1.2.1:gogo_protobuf/vendor/github.com/gogo/protobuf \
		golang:crypto:3d3f9f413869:golang_crypto/vendor/golang.org/x/crypto \
		golang:net:adae6a3d119a:golang_net/vendor/golang.org/x/net \
		golang:protobuf:v1.2.0:golang_protobuf/vendor/github.com/golang/protobuf \
		golang:snappy:2e65f85255db:golang_snappy/vendor/github.com/golang/snappy \
		golang:sync:42b317875d0f:golang_sync/vendor/golang.org/x/sync \
		golang:sys:62eef0e2fa9b:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.3.0:golang_text/vendor/golang.org/x/text \
		google:go-genproto:082222b4a5c5:google_go_genproto/vendor/google.golang.org/genproto \
		grpc:grpc-go:v1.16.0:grpc_grpc_go/vendor/google.golang.org/grpc \
		hashicorp:consul:v1.4.2:hashicorp_consul/vendor/github.com/hashicorp/consul \
		hashicorp:errwrap:7554cd9344ce:hashicorp_errwrap/vendor/github.com/hashicorp/errwrap \
		hashicorp:go-cleanhttp:v0.5.0:hashicorp_go_cleanhttp/vendor/github.com/hashicorp/go-cleanhttp \
		hashicorp:go-multierror:d30f09973e19:hashicorp_go_multierror/vendor/github.com/hashicorp/go-multierror \
		hashicorp:go-retryablehttp:v0.5.0:hashicorp_go_retryablehttp/vendor/github.com/hashicorp/go-retryablehttp \
		hashicorp:go-rootcerts:6bb64b370b90:hashicorp_go_rootcerts/vendor/github.com/hashicorp/go-rootcerts \
		hashicorp:go-sockaddr:6d291a969b86:hashicorp_go_sockaddr/vendor/github.com/hashicorp/go-sockaddr \
		hashicorp:hcl:d7400db7143f:hashicorp_hcl/vendor/github.com/hashicorp/hcl \
		hashicorp:serf:v0.7.0:hashicorp_serf/vendor/github.com/hashicorp/serf \
		hashicorp:vault:v0.6.0:hashicorp_vault/vendor/github.com/hashicorp/vault \
		inetaf:tcpproxy:b6bb9b5b8252:inetaf_tcpproxy/vendor/github.com/inetaf/tcpproxy \
		kr:logfmt:b84e30acd515:kr_logfmt/vendor/github.com/kr/logfmt \
		magiconair:properties:49d762b9817b:magiconair_properties/vendor/github.com/magiconair/properties \
		mitchellh:go-homedir:1111e456ffea:mitchellh_go_homedir/vendor/github.com/mitchellh/go-homedir \
		mitchellh:mapstructure:d2dd02622084:mitchellh_mapstructure/vendor/github.com/mitchellh/mapstructure \
		mwitkow:grpc-proxy:0f1106ef9c76:mwitkow_grpc_proxy/vendor/github.com/mwitkow/grpc-proxy \
		opentracing-contrib:go-observer:a52f23424492:opentracing_contrib_go_observer/vendor/github.com/opentracing-contrib/go-observer \
		opentracing:opentracing-go:v1.0.2:opentracing_opentracing_go/vendor/github.com/opentracing/opentracing-go \
		openzipkin:zipkin-go-opentracing:v0.3.4:openzipkin_zipkin_go_opentracing/vendor/github.com/openzipkin/zipkin-go-opentracing \
		pascaldekloe:goe:f99183613f48:pascaldekloe_goe/vendor/github.com/pascaldekloe/goe \
		pierrec:lz4:v2.0.5:pierrec_lz4/vendor/github.com/pierrec/lz4 \
		pkg:errors:v0.8.0:pkg_errors/vendor/github.com/pkg/errors \
		pkg:profile:v1.2.1:pkg_profile/vendor/github.com/pkg/profile \
		pubnub:go-metrics-statsd:7da61f429d6b:pubnub_go_metrics_statsd/vendor/github.com/pubnub/go-metrics-statsd \
		rakyll:statik:v0.1.6:rakyll_statik/vendor/github.com/rakyll/statik \
		rcrowley:go-metrics:e2704e165165:rcrowley_go_metrics/vendor/github.com/rcrowley/go-metrics \
		rogpeppe:fastuuid:6724a57986af:rogpeppe_fastuuid/vendor/github.com/rogpeppe/fastuuid \
		sergi:go-diff:24e2351369ec:sergi_go_diff/vendor/github.com/sergi/go-diff \
		tg123:go-htpasswd:d38e564730bf:tg123_go_htpasswd/vendor/github.com/tg123/go-htpasswd \
		tv42:httpunix:b75d8614f926:tv42_httpunix/vendor/github.com/tv42/httpunix

USE_RC_SUBR=	fabio

PLIST_FILES=	"@sample etc/fabio.properties.sample" \
		sbin/fabio

GO_TARGET=	:${PREFIX}/sbin/fabio
GO_BUILDFLAGS=	-ldflags "-X main.GitDescribe=v${PORTVERSION}"

post-install:
	${INSTALL_DATA} ${GO_WRKSRC}/fabio.properties ${STAGEDIR}${PREFIX}/etc/fabio.properties.sample

.include <bsd.port.mk>
