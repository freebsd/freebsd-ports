PORTNAME=	lego
DISTVERSIONPREFIX=	v
DISTVERSION=	4.6.0
CATEGORIES=	security

MAINTAINER=	matt@matthoran.com
COMMENT=	Let's Encrypt client and ACME library written in Go

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${LOCALBASE}/share/certs/ca-root-nss.crt:security/ca_root_nss

USES=		go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	go-acme
GH_TUPLE=	Azure:azure-sdk-for-go:v32.4.0:azure_azure_sdk_for_go/vendor/github.com/Azure/azure-sdk-for-go \
		Azure:go-autorest:446f41b7d65b:azure_go_autorest_validation \
		Azure:go-autorest:55c0c4ebc34d:azure_go_autorest_cli \
		Azure:go-autorest:76c7860e9b60:azure_go_autorest_auth \
		Azure:go-autorest:79a63e70c4d8:azure_go_autorest_adal/vendor/github.com/Azure/go-autorest \
		Azure:go-autorest:autorest/v0.11.19:azure_go_autorest_autorest \
		Azure:go-autorest:b3a0b30a7423:azure_go_autorest_date \
		Azure:go-autorest:logger/v0.2.1:azure_go_autorest_logger \
		Azure:go-autorest:tracing/v0.6.0:azure_go_autorest_tracing \
		Azure:go-autorest:v14.2.0:azure_go_autorest \
		BurntSushi:toml:v0.3.1:burntsushi_toml/vendor/github.com/BurntSushi/toml \
		OpenDNS:vegadns2client:a3fa4a771d87:opendns_vegadns2client/vendor/github.com/OpenDNS/vegadns2client \
		SSLMate:go-pkcs12:c5206de65a78:sslmate_go_pkcs12/vendor/software.sslmate.com/src/go-pkcs12 \
		akamai:AkamaiOPEN-edgegrid-golang:v1.1.1:akamai_akamaiopen_edgegrid_golang/vendor/github.com/akamai/AkamaiOPEN-edgegrid-golang \
		aliyun:alibaba-cloud-sdk-go:v1.61.1183:aliyun_alibaba_cloud_sdk_go/vendor/github.com/aliyun/alibaba-cloud-sdk-go \
		aws:aws-sdk-go:v1.39.0:aws_aws_sdk_go/vendor/github.com/aws/aws-sdk-go \
		boombuler:barcode:6c824513bacc:boombuler_barcode/vendor/github.com/boombuler/barcode \
		cenkalti:backoff:v4.1.1:cenkalti_backoff_v4/vendor/github.com/cenkalti/backoff/v4 \
		census-instrumentation:opencensus-go:v0.22.3:census_instrumentation_opencensus_go/vendor/go.opencensus.io \
		cloudflare:cloudflare-go:v0.20.0:cloudflare_cloudflare_go/vendor/github.com/cloudflare/cloudflare-go \
		cpu:goacmedns:v0.1.1:cpu_goacmedns/vendor/github.com/cpu/goacmedns \
		cpuguy83:go-md2man:v2.0.0:cpuguy83_go_md2man_v2/vendor/github.com/cpuguy83/go-md2man/v2 \
		davecgh:go-spew:v1.1.1:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		deepmap:oapi-codegen:v1.6.1:deepmap_oapi_codegen/vendor/github.com/deepmap/oapi-codegen \
		dimchansky:utfbom:v1.1.1:dimchansky_utfbom/vendor/github.com/dimchansky/utfbom \
		dnsimple:dnsimple-go:v0.70.1:dnsimple_dnsimple_go/vendor/github.com/dnsimple/dnsimple-go \
		exoscale:egoscale:v0.67.0:exoscale_egoscale/vendor/github.com/exoscale/egoscale \
		fatih:structs:v1.1.0:fatih_structs/vendor/github.com/fatih/structs \
		form3tech-oss:jwt-go:v3.2.2:form3tech_oss_jwt_go/vendor/github.com/form3tech-oss/jwt-go \
		go-errors:errors:v1.0.1:go_errors_errors/vendor/github.com/go-errors/errors \
		go-ini:ini:v1.62.0:go_ini_ini/vendor/gopkg.in/ini.v1 \
		go-resty:resty:d7b97669fe48:go_resty_resty_v2/vendor/github.com/go-resty/resty/v2 \
		go-yaml:yaml:496545a6307b:go_yaml_yaml_1/vendor/gopkg.in/yaml.v3 \
		go-yaml:yaml:v2.4.0:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		gofrs:uuid:v3.2.0:gofrs_uuid/vendor/github.com/gofrs/uuid \
		golang:appengine:v1.6.5:golang_appengine/vendor/google.golang.org/appengine \
		golang:crypto:5ff15b29337e:golang_crypto/vendor/golang.org/x/crypto \
		golang:groupcache:8c9f03a8e57e:golang_groupcache/vendor/github.com/golang/groupcache \
		golang:net:4163338589ed:golang_net/vendor/golang.org/x/net \
		golang:oauth2:bf48bf16ab8d:golang_oauth2/vendor/golang.org/x/oauth2 \
		golang:protobuf:v1.5.2:golang_protobuf/vendor/github.com/golang/protobuf \
		golang:sys:665e8c7367d1:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.3.6:golang_text/vendor/golang.org/x/text \
		golang:time:38a9dc6acbc6:golang_time/vendor/golang.org/x/time \
		google:go-genproto:506484158171:google_go_genproto/vendor/google.golang.org/genproto \
		google:go-querystring:v1.1.0:google_go_querystring/vendor/github.com/google/go-querystring \
		google:uuid:v1.1.1:google_uuid/vendor/github.com/google/uuid \
		googleapis:gax-go:v2.0.5:googleapis_gax_go_v2/vendor/github.com/googleapis/gax-go \
		googleapis:google-api-go-client:v0.20.0:googleapis_google_api_go_client/vendor/google.golang.org/api \
		googleapis:google-cloud-go:v0.54.0:googleapis_google_cloud_go/vendor/cloud.google.com/go \
		gophercloud:gophercloud:v0.16.0:gophercloud_gophercloud/vendor/github.com/gophercloud/gophercloud \
		gophercloud:utils:f6de111f2eae:gophercloud_utils/vendor/github.com/gophercloud/utils \
		grpc:grpc-go:v1.27.1:grpc_grpc_go/vendor/google.golang.org/grpc \
		hashicorp:go-cleanhttp:v0.5.1:hashicorp_go_cleanhttp/vendor/github.com/hashicorp/go-cleanhttp \
		hashicorp:go-retryablehttp:v0.7.0:hashicorp_go_retryablehttp/vendor/github.com/hashicorp/go-retryablehttp \
		iij:doapi:0bbf12d6d7df:iij_doapi/vendor/github.com/iij/doapi \
		infobloxopen:infoblox-go-client:v1.1.1:infobloxopen_infoblox_go_client/vendor/github.com/infobloxopen/infoblox-go-client \
		jarcoal:httpmock:v1.0.6:jarcoal_httpmock/vendor/github.com/jarcoal/httpmock \
		jmespath:go-jmespath:v0.4.0:jmespath_go_jmespath/vendor/github.com/jmespath/go-jmespath \
		json-iterator:go:v1.1.7:json_iterator_go/vendor/github.com/json-iterator/go \
		k0kubun:go-ansi:3bf9e2903213:k0kubun_go_ansi/vendor/github.com/k0kubun/go-ansi \
		kolo:xmlrpc:e0350524596b:kolo_xmlrpc/vendor/github.com/kolo/xmlrpc \
		konsorten:go-windows-terminal-sequences:v1.0.2:konsorten_go_windows_terminal_sequences/vendor/github.com/konsorten/go-windows-terminal-sequences \
		labbsr0x:bindman-dns-webhook:v1.0.2:labbsr0x_bindman_dns_webhook/vendor/github.com/labbsr0x/bindman-dns-webhook \
		labbsr0x:goh:v1.0.1:labbsr0x_goh/vendor/github.com/labbsr0x/goh \
		linode:linodego:v0.31.1:linode_linodego/vendor/github.com/linode/linodego \
		liquidweb:go-lwApi:v0.0.5:liquidweb_go_lwapi/vendor/github.com/liquidweb/go-lwApi \
		liquidweb:liquidweb-cli:v0.6.9:liquidweb_liquidweb_cli/vendor/github.com/liquidweb/liquidweb-cli \
		liquidweb:liquidweb-go:v1.6.3:liquidweb_liquidweb_go/vendor/github.com/liquidweb/liquidweb-go \
		mattn:go-isatty:v0.0.12:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		miekg:dns:v1.1.43:miekg_dns/vendor/github.com/miekg/dns \
		mitchellh:go-homedir:v1.1.0:mitchellh_go_homedir/vendor/github.com/mitchellh/go-homedir \
		mitchellh:mapstructure:v1.4.1:mitchellh_mapstructure/vendor/github.com/mitchellh/mapstructure \
		modern-go:concurrent:bacd9c7ef1dd:modern_go_concurrent/vendor/github.com/modern-go/concurrent \
		modern-go:reflect2:v1.0.1:modern_go_reflect2/vendor/github.com/modern-go/reflect2 \
		namedotcom:go:08470befbe04:namedotcom_go/vendor/github.com/namedotcom/go \
		nrdcg:auroradns:v1.0.1:nrdcg_auroradns/vendor/github.com/nrdcg/auroradns \
		nrdcg:desec:v0.6.0:nrdcg_desec/vendor/github.com/nrdcg/desec \
		nrdcg:dnspod-go:v0.4.0:nrdcg_dnspod_go/vendor/github.com/nrdcg/dnspod-go \
		nrdcg:freemyip:v0.2.0:nrdcg_freemyip/vendor/github.com/nrdcg/freemyip \
		nrdcg:goinwx:v0.8.1:nrdcg_goinwx/vendor/github.com/nrdcg/goinwx \
		nrdcg:namesilo:v0.2.1:nrdcg_namesilo/vendor/github.com/nrdcg/namesilo \
		nrdcg:porkbun:v0.1.1:nrdcg_porkbun/vendor/github.com/nrdcg/porkbun \
		ns1:ns1-go:v2.6.2:ns1_ns1_go/vendor/gopkg.in/ns1/ns1-go.v2 \
		onsi:gomega:v1.14.0:onsi_gomega/vendor/github.com/onsi/gomega \
		oracle:oci-go-sdk:v24.3.0:oracle_oci_go_sdk/vendor/github.com/oracle/oci-go-sdk \
		ovh:go-ovh:v1.1.0:ovh_go_ovh/vendor/github.com/ovh/go-ovh \
		patrickmn:go-cache:v2.1.0:patrickmn_go_cache/vendor/github.com/patrickmn/go-cache \
		pkg:errors:v0.9.1:pkg_errors/vendor/github.com/pkg/errors \
		pmezard:go-difflib:v1.0.0:pmezard_go_difflib/vendor/github.com/pmezard/go-difflib \
		pquerna:otp:v1.3.0:pquerna_otp/vendor/github.com/pquerna/otp \
		protocolbuffers:protobuf-go:v1.26.0:protocolbuffers_protobuf_go/vendor/google.golang.org/protobuf \
		rainycape:memcache:1031fa0ce2f2:rainycape_memcache/vendor/github.com/rainycape/memcache \
		russross:blackfriday:v2.0.1:russross_blackfriday_v2/vendor/github.com/russross/blackfriday/v2 \
		sacloud:libsacloud:v1.36.2:sacloud_libsacloud/vendor/github.com/sacloud/libsacloud \
		scaleway:scaleway-sdk-go:bd30bebeac4f:scaleway_scaleway_sdk_go/vendor/github.com/scaleway/scaleway-sdk-go \
		shurcooL:sanitized_anchor_name:v1.0.0:shurcool_sanitized_anchor_name/vendor/github.com/shurcooL/sanitized_anchor_name \
		sirupsen:logrus:v1.4.2:sirupsen_logrus/vendor/github.com/sirupsen/logrus \
		smartystreets:go-aws-auth:0c1422d1fdb9:smartystreets_go_aws_auth/vendor/github.com/smartystreets/go-aws-auth \
		softlayer:softlayer-go:v1.0.3:softlayer_softlayer_go/vendor/github.com/softlayer/softlayer-go \
		softlayer:xmlrpc:5f089df7cb7e:softlayer_xmlrpc/vendor/github.com/softlayer/xmlrpc \
		spf13:cast:v1.3.1:spf13_cast/vendor/github.com/spf13/cast \
		square:go-jose:v2.6.0:square_go_jose/vendor/gopkg.in/square/go-jose.v2 \
		stretchr:objx:v0.3.0:stretchr_objx/vendor/github.com/stretchr/objx \
		stretchr:testify:v1.7.0:stretchr_testify/vendor/github.com/stretchr/testify \
		tencentcloud:tencentcloud-sdk-go:v1.0.287:tencentcloud_tencentcloud_sdk_go_common/vendor/github.com/tencentcloud/tencentcloud-sdk-go \
		transip:gotransip:v6.6.1:transip_gotransip_v6/vendor/github.com/transip/gotransip/v6 \
		uber-go:ratelimit:c15da0234277:uber_go_ratelimit/vendor/go.uber.org/ratelimit \
		urfave:cli:v1.22.5:urfave_cli/vendor/github.com/urfave/cli \
		vinyldns:go-vinyldns:v0.9.16:vinyldns_go_vinyldns/vendor/github.com/vinyldns/go-vinyldns \
		vultr:govultr:v2.7.1:vultr_govultr_v2/vendor/github.com/vultr/govultr/v2

GO_TARGET=	./cmd/lego
GO_BUILDFLAGS=	-ldflags '-X "main.version=${DISTVERSION}"'

SAMPLE_FILES=	deploy.sh.sample lego.sh.sample
SUB_FILES=	${SAMPLE_FILES} 604.lego pkg-message
SUB_LIST=	LEGO_USER=${LEGO_USER} \
		PORTNAME=${PORTNAME}

LEGO_USER?=	_lego

USERS=		${LEGO_USER}
GROUPS=		${LEGO_USER}

PERIODIC_DIRS=	etc/periodic/weekly
PERIODIC_FILES=	604.lego

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/${PERIODIC_DIRS}
	${INSTALL_SCRIPT} ${WRKDIR}/${PERIODIC_FILES} ${STAGEDIR}${PREFIX}/${PERIODIC_DIRS}/${PERIODIC_FILES}
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/ssl/lego \
		${STAGEDIR}${ETCDIR} ${STAGEDIR}${WWWDIR}
.	for d in ${SAMPLE_FILES}
		${INSTALL_SCRIPT} ${WRKDIR}/${d} ${STAGEDIR}${ETCDIR}/${d}
.	endfor

.include <bsd.port.mk>
