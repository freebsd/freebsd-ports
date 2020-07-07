# $FreeBSD$

PORTNAME=	lego
DISTVERSIONPREFIX=	v
DISTVERSION=	3.8.0
CATEGORIES=	security

MAINTAINER=	matt@matthoran.com
COMMENT=	Let's Encrypt client and ACME library written in Go

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${LOCALBASE}/share/certs/ca-root-nss.crt:security/ca_root_nss

USES=		go:modules

GO_TARGET=	./cmd/lego
GO_BUILDFLAGS=	-ldflags '-X "main.version=${DISTVERSION}"'

USE_GITHUB=	yes
GH_ACCOUNT=	go-acme go-ini:go_ini_ini
GH_PROJECT=	ini:go_ini_ini
GH_TAGNAME=	v1.51.1:go_ini_ini
GH_TUPLE=	\
		Azure:azure-sdk-for-go:v32.4.0:azure_azure_sdk_for_go/vendor/github.com/Azure/azure-sdk-for-go \
		Azure:go-autorest:2913f263500c:azure_go_autorest_adal/vendor/github.com/Azure/go-autorest \
		Azure:go-autorest:3133e83bedd2:azure_go_autorest_cli \
		Azure:go-autorest:4bb4e3c99dd9:azure_go_autorest_date \
		Azure:go-autorest:autorest/v0.5.0:azure_go_autorest_autorest \
		Azure:go-autorest:da8db3a19ec5:azure_go_autorest_auth \
		Azure:go-autorest:f29a2eccaa17:azure_go_autorest_to \
		Azure:go-autorest:logger/v0.1.0:azure_go_autorest_logger \
		Azure:go-autorest:tracing/v0.1.0:azure_go_autorest_tracing \
		BurntSushi:toml:v0.3.1:burntsushi_toml/vendor/github.com/BurntSushi/toml \
		OpenDNS:vegadns2client:a3fa4a771d87:opendns_vegadns2client/vendor/github.com/OpenDNS/vegadns2client \
		akamai:AkamaiOPEN-edgegrid-golang:v0.9.8:akamai_akamaiopen_edgegrid_golang/vendor/github.com/akamai/AkamaiOPEN-edgegrid-golang \
		aliyun:alibaba-cloud-sdk-go:v1.61.112:aliyun_alibaba_cloud_sdk_go/vendor/github.com/aliyun/alibaba-cloud-sdk-go \
		aws:aws-sdk-go:v1.30.20:aws_aws_sdk_go/vendor/github.com/aws/aws-sdk-go \
		boombuler:barcode:6c824513bacc:boombuler_barcode/vendor/github.com/boombuler/barcode \
		cenkalti:backoff:v4.0.0:cenkalti_backoff_v4/vendor/github.com/cenkalti/backoff/v4 \
		census-ecosystem:opencensus-go-exporter-ocagent:v0.4.12:census_ecosystem_opencensus_go_exporter_ocagent/vendor/contrib.go.opencensus.io/exporter/ocagent \
		census-instrumentation:opencensus-go:v0.22.3:census_instrumentation_opencensus_go/vendor/go.opencensus.io \
		census-instrumentation:opencensus-proto:v0.2.1:census_instrumentation_opencensus_proto/vendor/github.com/census-instrumentation/opencensus-proto \
		cloudflare:cloudflare-go:v0.10.2:cloudflare_cloudflare_go/vendor/github.com/cloudflare/cloudflare-go \
		cpu:goacmedns:v0.0.2:cpu_goacmedns/vendor/github.com/cpu/goacmedns \
		cpuguy83:go-md2man:f79a8a8ca69d:cpuguy83_go_md2man_v2/vendor/github.com/cpuguy83/go-md2man/v2 \
		davecgh:go-spew:v1.1.1:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		dgrijalva:jwt-go:v3.2.0:dgrijalva_jwt_go/vendor/github.com/dgrijalva/jwt-go \
		dimchansky:utfbom:v1.1.0:dimchansky_utfbom/vendor/github.com/dimchansky/utfbom \
		dnsimple:dnsimple-go:v0.60.0:dnsimple_dnsimple_go/vendor/github.com/dnsimple/dnsimple-go \
		exoscale:egoscale:v0.18.1:exoscale_egoscale/vendor/github.com/exoscale/egoscale \
		fatih:structs:v1.1.0:fatih_structs/vendor/github.com/fatih/structs \
		go-errors:errors:v1.0.1:go_errors_errors/vendor/github.com/go-errors/errors \
		go-resty:resty:v1.12.0:go_resty_resty/vendor/gopkg.in/resty.v1 \
		go-yaml:yaml:v2.2.8:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		gofrs:uuid:v3.2.0:gofrs_uuid/vendor/github.com/gofrs/uuid \
		golang:appengine:v1.6.5:golang_appengine/vendor/google.golang.org/appengine \
		golang:crypto:78000ba7a073:golang_crypto/vendor/golang.org/x/crypto \
		golang:groupcache:8c9f03a8e57e:golang_groupcache/vendor/github.com/golang/groupcache \
		golang:net:244492dfa37a:golang_net/vendor/golang.org/x/net \
		golang:oauth2:bf48bf16ab8d:golang_oauth2/vendor/golang.org/x/oauth2 \
		golang:protobuf:v1.3.4:golang_protobuf/vendor/github.com/golang/protobuf \
		golang:sync:cd5d95a43a6e:golang_sync/vendor/golang.org/x/sync \
		golang:sys:5c8b2ff67527:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.3.2:golang_text/vendor/golang.org/x/text \
		golang:time:555d28b269f0:golang_time/vendor/golang.org/x/time \
		google:go-genproto:506484158171:google_go_genproto/vendor/google.golang.org/genproto \
		google:go-querystring:v1.0.0:google_go_querystring/vendor/github.com/google/go-querystring \
		google:uuid:v1.1.1:google_uuid/vendor/github.com/google/uuid \
		googleapis:gax-go:v2.0.5:googleapis_gax_go_v2/vendor/github.com/googleapis/gax-go \
		googleapis:google-api-go-client:v0.20.0:googleapis_google_api_go_client/vendor/google.golang.org/api \
		googleapis:google-cloud-go:v0.54.0:googleapis_google_cloud_go/vendor/cloud.google.com/go \
		gophercloud:gophercloud:v0.3.0:gophercloud_gophercloud/vendor/github.com/gophercloud/gophercloud \
		grpc-ecosystem:grpc-gateway:v1.8.5:grpc_ecosystem_grpc_gateway/vendor/github.com/grpc-ecosystem/grpc-gateway \
		grpc:grpc-go:v1.27.1:grpc_grpc_go/vendor/google.golang.org/grpc \
		hashicorp:go-cleanhttp:v0.5.1:hashicorp_go_cleanhttp/vendor/github.com/hashicorp/go-cleanhttp \
		hashicorp:go-retryablehttp:v0.6.6:hashicorp_go_retryablehttp/vendor/github.com/hashicorp/go-retryablehttp \
		iij:doapi:0bbf12d6d7df:iij_doapi/vendor/github.com/iij/doapi \
		jmespath:go-jmespath:v0.3.0:jmespath_go_jmespath/vendor/github.com/jmespath/go-jmespath \
		json-iterator:go:v1.1.7:json_iterator_go/vendor/github.com/json-iterator/go \
		kolo:xmlrpc:e0350524596b:kolo_xmlrpc/vendor/github.com/kolo/xmlrpc \
		konsorten:go-windows-terminal-sequences:v1.0.2:konsorten_go_windows_terminal_sequences/vendor/github.com/konsorten/go-windows-terminal-sequences \
		labbsr0x:bindman-dns-webhook:v1.0.2:labbsr0x_bindman_dns_webhook/vendor/github.com/labbsr0x/bindman-dns-webhook \
		labbsr0x:goh:v1.0.1:labbsr0x_goh/vendor/github.com/labbsr0x/goh \
		linode:linodego:v0.10.0:linode_linodego/vendor/github.com/linode/linodego \
		liquidweb:liquidweb-go:v1.6.0:liquidweb_liquidweb_go/vendor/github.com/liquidweb/liquidweb-go \
		miekg:dns:v1.1.27:miekg_dns/vendor/github.com/miekg/dns \
		mitchellh:go-homedir:v1.1.0:mitchellh_go_homedir/vendor/github.com/mitchellh/go-homedir \
		mitchellh:mapstructure:v1.3.1:mitchellh_mapstructure/vendor/github.com/mitchellh/mapstructure \
		modern-go:concurrent:bacd9c7ef1dd:modern_go_concurrent/vendor/github.com/modern-go/concurrent \
		modern-go:reflect2:v1.0.1:modern_go_reflect2/vendor/github.com/modern-go/reflect2 \
		namedotcom:go:08470befbe04:namedotcom_go/vendor/github.com/namedotcom/go \
		nrdcg:auroradns:v1.0.1:nrdcg_auroradns/vendor/github.com/nrdcg/auroradns \
		nrdcg:dnspod-go:v0.4.0:nrdcg_dnspod_go/vendor/github.com/nrdcg/dnspod-go \
		nrdcg:goinwx:v0.7.0:nrdcg_goinwx/vendor/github.com/nrdcg/goinwx \
		nrdcg:namesilo:v0.2.1:nrdcg_namesilo/vendor/github.com/nrdcg/namesilo \
		ns1:ns1-go:b51389932cbc:ns1_ns1_go/vendor/gopkg.in/ns1/ns1-go.v2 \
		oracle:oci-go-sdk:v7.0.0:oracle_oci_go_sdk/vendor/github.com/oracle/oci-go-sdk \
		ovh:go-ovh:ba5adb4cf014:ovh_go_ovh/vendor/github.com/ovh/go-ovh \
		pkg:errors:v0.9.1:pkg_errors/vendor/github.com/pkg/errors \
		pmezard:go-difflib:v1.0.0:pmezard_go_difflib/vendor/github.com/pmezard/go-difflib \
		pquerna:otp:v1.2.0:pquerna_otp/vendor/github.com/pquerna/otp \
		rainycape:memcache:1031fa0ce2f2:rainycape_memcache/vendor/github.com/rainycape/memcache \
		russross:blackfriday:v2.0.1:russross_blackfriday_v2/vendor/github.com/russross/blackfriday/v2 \
		sacloud:libsacloud:v1.26.1:sacloud_libsacloud/vendor/github.com/sacloud/libsacloud \
		shurcooL:sanitized_anchor_name:v1.0.0:shurcool_sanitized_anchor_name/vendor/github.com/shurcooL/sanitized_anchor_name \
		sirupsen:logrus:v1.4.2:sirupsen_logrus/vendor/github.com/sirupsen/logrus \
		square:go-jose:v2.3.1:square_go_jose/vendor/gopkg.in/square/go-jose.v2 \
		stretchr:objx:v0.1.1:stretchr_objx/vendor/github.com/stretchr/objx \
		stretchr:testify:v1.5.1:stretchr_testify/vendor/github.com/stretchr/testify \
		timewasted:linode:37e84520dcf7:timewasted_linode/vendor/github.com/timewasted/linode \
		transip:gotransip:v6.0.2:transip_gotransip_v6/vendor/github.com/transip/gotransip/v6 \
		uber-go:ratelimit:c15da0234277:uber_go_ratelimit/vendor/go.uber.org/ratelimit \
		urfave:cli:v1.22.1:urfave_cli/vendor/github.com/urfave/cli \
		vultr:govultr:v0.4.2:vultr_govultr/vendor/github.com/vultr/govultr

SAMPLE_FILES=	deploy.sh.sample lego.sh.sample
SUB_FILES=	${SAMPLE_FILES} 604.lego pkg-message
SUB_LIST=	LEGO_USER=${LEGO_USER} \
		PORTNAME=${PORTNAME}

PERIODIC_DIRS=	etc/periodic/weekly
PERIODIC_FILES=	604.lego

LEGO_USER?=	_lego

USERS=		${LEGO_USER}
GROUPS=		${LEGO_USER}

post-extract:
	@${RMDIR} ${WRKSRC}/vendor/gopkg.in/ini.v1 \
		${WRKSRC}/vendor/github.com/go-ini/ini 2>/dev/null || :
	@${MKDIR} ${WRKSRC}/vendor/gopkg.in \
		${WRKSRC}/vendor/github.com/go-ini 2>/dev/null || :
	@${LN} -s ${WRKSRC_go_ini_ini} ${WRKSRC}/vendor/gopkg.in/ini.v1
	@${LN} -s ${WRKSRC_go_ini_ini} ${WRKSRC}/vendor/github.com/go-ini/ini

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/${PERIODIC_DIRS}
	${INSTALL_SCRIPT} ${WRKDIR}/${PERIODIC_FILES} ${STAGEDIR}${PREFIX}/${PERIODIC_DIRS}/${PERIODIC_FILES}
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/ssl/lego \
		${STAGEDIR}${ETCDIR} ${STAGEDIR}${WWWDIR}
.	for d in ${SAMPLE_FILES}
		${INSTALL_SCRIPT} ${WRKDIR}/${d} ${STAGEDIR}${ETCDIR}/${d}
.	endfor

.include <bsd.port.mk>
