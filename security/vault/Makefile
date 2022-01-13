PORTNAME=	vault
PORTVERSION=	1.8.2
DISTVERSIONPREFIX=	v
CATEGORIES=	security

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Tool for securely accessing secrets

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cpe go:modules
CPE_VENDOR=	hashicorp

USE_GITHUB=	yes
GH_TUPLE=	hashicorp:${PORTNAME}:${VAULTTAG}:DEFAULT \
		grembo:vaultui:${VAULTUITAG}:vaultui \
		Azure:azure-pipeline-go:v0.2.3:azure_azure_pipeline_go/vendor/github.com/Azure/azure-pipeline-go \
		Azure:azure-sdk-for-go:v51.1.0:azure_azure_sdk_for_go/vendor/github.com/Azure/azure-sdk-for-go \
		Azure:azure-storage-blob-go:v0.13.0:azure_azure_storage_blob_go/vendor/github.com/Azure/azure-storage-blob-go \
		Azure:go-ansiterm:d6e3b3328b78:azure_go_ansiterm/vendor/github.com/Azure/go-ansiterm \
		Azure:go-autorest:243526fc4739:azure_go_autorest_auth \
		Azure:go-autorest:446f41b7d65b:azure_go_autorest_validation \
		Azure:go-autorest:55c0c4ebc34d:azure_go_autorest_cli \
		Azure:go-autorest:autorest/v0.11.17:azure_go_autorest_autorest \
		Azure:go-autorest:b3a0b30a7423:azure_go_autorest_date \
		Azure:go-autorest:def88ef859fb:azure_go_autorest_adal \
		Azure:go-autorest:logger/v0.2.0:azure_go_autorest_logger \
		Azure:go-autorest:tracing/v0.6.0:azure_go_autorest_tracing \
		Azure:go-autorest:v14.2.0:azure_go_autorest/vendor/github.com/Azure/go-autorest \
		Azure:go-ntlmssp:66371956d46c:azure_go_ntlmssp/vendor/github.com/Azure/go-ntlmssp \
		BurntSushi:toml:v0.3.1:burntsushi_toml/vendor/github.com/BurntSushi/toml \
		DataDog:datadog-go:v3.2.0:datadog_datadog_go/vendor/github.com/DataDog/datadog-go \
		Jeffail:gabs:v1.1.1:jeffail_gabs/vendor/github.com/Jeffail/gabs \
		Masterminds:goutils:v1.1.0:masterminds_goutils/vendor/github.com/Masterminds/goutils \
		Masterminds:semver:v1.5.0:masterminds_semver/vendor/github.com/Masterminds/semver \
		Masterminds:sprig:v2.22.0:masterminds_sprig/vendor/github.com/Masterminds/sprig \
		Microsoft:go-winio:d1ffc52c7331:microsoft_go_winio/vendor/github.com/Microsoft/go-winio \
		Microsoft:hcsshim:v0.8.14:microsoft_hcsshim/vendor/github.com/Microsoft/hcsshim \
		NYTimes:gziphandler:v1.1.1:nytimes_gziphandler/vendor/github.com/NYTimes/gziphandler \
		Nvveen:Gotty:cd527374f1e5:nvveen_gotty/vendor/github.com/Nvveen/Gotty \
		SAP:go-hdb:v0.14.1:sap_go_hdb/vendor/github.com/SAP/go-hdb \
		Sectorbob:mlab-ns2:d3aa0c295a8a:sectorbob_mlab_ns2/vendor/github.com/Sectorbob/mlab-ns2 \
		StackExchange:wmi:cbe66965904d:stackexchange_wmi/vendor/github.com/StackExchange/wmi \
		aerospike:aerospike-client-go:v3.1.1:aerospike_aerospike_client_go/vendor/github.com/aerospike/aerospike-client-go \
		aliyun:alibaba-cloud-sdk-go:9418d7b0cd0f:aliyun_alibaba_cloud_sdk_go/vendor/github.com/aliyun/alibaba-cloud-sdk-go \
		aliyun:aliyun-oss-go-sdk:86c17b95fcd5:aliyun_aliyun_oss_go_sdk/vendor/github.com/aliyun/aliyun-oss-go-sdk \
		apache:arrow:b2287a20f230:apache_arrow_arrow/vendor/github.com/apache/arrow \
		apple:foundationdb:cd5c9d91fad2:apple_foundationdb_go/vendor/github.com/apple/foundationdb \
		armon:go-metrics:v0.3.7:armon_go_metrics/vendor/github.com/armon/go-metrics \
		armon:go-proxyproto:7e956b284f0a:armon_go_proxyproto/vendor/github.com/armon/go-proxyproto \
		armon:go-radix:v1.0.0:armon_go_radix/vendor/github.com/armon/go-radix \
		asaskevich:govalidator:f9ffefc3facf:asaskevich_govalidator/vendor/github.com/asaskevich/govalidator \
		aws:aws-sdk-go-v2:credentials/v1.1.5:aws_aws_sdk_go_v2_credentials \
		aws:aws-sdk-go-v2:fdbaadbce5fd:aws_aws_sdk_go_v2_manager \
		aws:aws-sdk-go-v2:v1.3.2:aws_aws_sdk_go_v2/vendor/github.com/aws/aws-sdk-go-v2 \
		aws:aws-sdk-go-v2:v1.5.0:aws_aws_sdk_go_v2_s3 \
		aws:aws-sdk-go:v1.37.19:aws_aws_sdk_go/vendor/github.com/aws/aws-sdk-go \
		aws:smithy-go:v1.3.1:aws_smithy_go/vendor/github.com/aws/smithy-go \
		beorn7:perks:v1.0.1:beorn7_perks/vendor/github.com/beorn7/perks \
		bgentry:speakeasy:v0.1.0:bgentry_speakeasy/vendor/github.com/bgentry/speakeasy \
		bitly:go-hostpool:v0.1.0:bitly_go_hostpool/vendor/github.com/bitly/go-hostpool \
		boombuler:barcode:6c824513bacc:boombuler_barcode/vendor/github.com/boombuler/barcode \
		briankassouf:jose:d2569464773f:briankassouf_jose/vendor/github.com/briankassouf/jose \
		cenkalti:backoff:v2.2.1:cenkalti_backoff/vendor/github.com/cenkalti/backoff \
		cenkalti:backoff:v3.0.0:cenkalti_backoff_v3/vendor/github.com/cenkalti/backoff/v3 \
		census-instrumentation:opencensus-go:v0.22.3:census_instrumentation_opencensus_go/vendor/go.opencensus.io \
		centrify:cloud-golang-sdk:119110094d0f:centrify_cloud_golang_sdk/vendor/github.com/centrify/cloud-golang-sdk \
		cespare:xxhash:v2.1.1:cespare_xxhash_v2/vendor/github.com/cespare/xxhash/v2 \
		chrismalek:oktasdk-go:3430665dfaa0:chrismalek_oktasdk_go/vendor/github.com/chrismalek/oktasdk-go \
		circonus-labs:circonus-gometrics:v2.3.1:circonus_labs_circonus_gometrics/vendor/github.com/circonus-labs/circonus-gometrics \
		circonus-labs:circonusllhist:v0.1.3:circonus_labs_circonusllhist/vendor/github.com/circonus-labs/circonusllhist \
		client9:misspell:v0.3.4:client9_misspell/vendor/github.com/client9/misspell \
		cloudfoundry-community:go-cfclient:f136f9222381:cloudfoundry_community_go_cfclient/vendor/github.com/cloudfoundry-community/go-cfclient \
		cloudfoundry:gofileutils:4d0c80011a0f:cloudfoundry_gofileutils/vendor/code.cloudfoundry.org/gofileutils \
		cockroachdb:cockroach-go:e0a95dfd547c:cockroachdb_cockroach_go/vendor/github.com/cockroachdb/cockroach-go \
		containerd:containerd:v1.4.3:containerd_containerd/vendor/github.com/containerd/containerd \
		containerd:continuity:efbc4488d8fe:containerd_continuity/vendor/github.com/containerd/continuity \
		coreos:go-oidc:v2.2.1:coreos_go_oidc/vendor/github.com/coreos/go-oidc \
		coreos:go-oidc:v3.0.0:coreos_go_oidc_v3/vendor/github.com/coreos/go-oidc/v3 \
		coreos:go-semver:v0.2.0:coreos_go_semver/vendor/github.com/coreos/go-semver \
		coreos:go-systemd:d3cd4ed1dbcf:coreos_go_systemd/vendor/github.com/coreos/go-systemd \
		coreos:go-systemd:v22.0.0:coreos_go_systemd_v22/vendor/github.com/coreos/go-systemd/v22 \
		couchbase:gocb:v2.1.4:couchbase_gocb_v2/vendor/github.com/couchbase/gocb/v2 \
		couchbase:gocbcore:v9.0.4:couchbase_gocbcore_v9/vendor/github.com/couchbase/gocbcore/v9 \
		davecgh:go-spew:v1.1.1:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		denisenkom:go-mssqldb:06a60b6afbbc:denisenkom_go_mssqldb/vendor/github.com/denisenkom/go-mssqldb \
		denverdino:aliyungo:d3308649c661:denverdino_aliyungo/vendor/github.com/denverdino/aliyungo \
		digitalocean:godo:v1.7.5:digitalocean_godo/vendor/github.com/digitalocean/godo \
		dimchansky:utfbom:v1.1.1:dimchansky_utfbom/vendor/github.com/dimchansky/utfbom \
		docker:distribution:v2.7.1:docker_distribution/vendor/github.com/docker/distribution \
		docker:go-connections:v0.4.0:docker_go_connections/vendor/github.com/docker/go-connections \
		docker:go-units:v0.4.0:docker_go_units/vendor/github.com/docker/go-units \
		dominikh:go-tools:v0.0.1-2020.1.3:dominikh_go_tools/vendor/honnef.co/go/tools \
		dsnet:compress:v0.0.1:dsnet_compress/vendor/github.com/dsnet/compress \
		duosecurity:duo_api_golang:6c680f768e74:duosecurity_duo_api_golang/vendor/github.com/duosecurity/duo_api_golang \
		dustin:go-humanize:v1.0.0:dustin_go_humanize/vendor/github.com/dustin/go-humanize \
		elazarl:go-bindata-assetfs:234c15e7648f:elazarl_go_bindata_assetfs/vendor/github.com/elazarl/go-bindata-assetfs \
		etcd-io:bbolt:v1.3.5:etcd_io_bbolt/vendor/go.etcd.io/bbolt \
		etcd-io:etcd:262c93980547:etcd_io_etcd/vendor/go.etcd.io/etcd \
		fatih:color:v1.11.0:fatih_color/vendor/github.com/fatih/color \
		fatih:structs:v1.1.0:fatih_structs/vendor/github.com/fatih/structs \
		form3tech-oss:jwt-go:v3.2.2:form3tech_oss_jwt_go/vendor/github.com/form3tech-oss/jwt-go \
		gammazero:deque:2afb3858e9c7:gammazero_deque/vendor/github.com/gammazero/deque \
		gammazero:workerpool:88d534f22b56:gammazero_workerpool/vendor/github.com/gammazero/workerpool \
		ghodss:yaml:25d852aebe32:ghodss_yaml/vendor/github.com/ghodss/yaml \
		go-asn1-ber:asn1-ber:v1.5.1:go_asn1_ber_asn1_ber/vendor/github.com/go-asn1-ber/asn1-ber \
		go-errors:errors:v1.0.1:go_errors_errors/vendor/github.com/go-errors/errors \
		go-inf:inf:v0.9.1:go_inf_inf/vendor/gopkg.in/inf.v0 \
		go-ini:ini:v1.42.0:go_ini_ini/vendor/gopkg.in/ini.v1 \
		go-ldap:ldap:v3.2.4:go_ldap_ldap_v3/vendor/github.com/go-ldap/ldap \
		go-ldap:ldif:fd88d9b715b3:go_ldap_ldif/vendor/github.com/go-ldap/ldif \
		go-mgo:mgo:9856a29383ce:go_mgo_mgo/vendor/gopkg.in/mgo.v2 \
		go-ole:go-ole:v1.2.4:go_ole_go_ole/vendor/github.com/go-ole/go-ole \
		go-resty:resty:v1.12.0:go_resty_resty/vendor/gopkg.in/resty.v1 \
		go-sql-driver:mysql:v1.5.0:go_sql_driver_mysql/vendor/github.com/go-sql-driver/mysql \
		go-stack:stack:v1.8.0:go_stack_stack/vendor/github.com/go-stack/stack \
		go-test:deep:v1.0.7:go_test_deep/vendor/github.com/go-test/deep \
		go-yaml:yaml:496545a6307b:go_yaml_yaml_2/vendor/gopkg.in/yaml.v3 \
		go-yaml:yaml:v2.1.0:go_yaml_yaml/vendor/github.com/go-yaml/yaml \
		go-yaml:yaml:v2.3.0:go_yaml_yaml_1/vendor/gopkg.in/yaml.v2 \
		gocql:gocql:80ab1e13e309:gocql_gocql/vendor/github.com/gocql/gocql \
		gogo:protobuf:v1.3.1:gogo_protobuf/vendor/github.com/gogo/protobuf \
		golang-sql:civil:cb61b32ac6fe:golang_sql_civil/vendor/github.com/golang-sql/civil \
		golang:appengine:v1.6.5:golang_appengine/vendor/google.golang.org/appengine \
		golang:crypto:c07d793c2f9a:golang_crypto/vendor/golang.org/x/crypto \
		golang:groupcache:8c9f03a8e57e:golang_groupcache/vendor/github.com/golang/groupcache \
		golang:lint:738671d3881b:golang_lint/vendor/golang.org/x/lint \
		golang:mod:v0.4.0:golang_mod/vendor/golang.org/x/mod \
		golang:net:4163338589ed:golang_net/vendor/golang.org/x/net \
		golang:oauth2:bf48bf16ab8d:golang_oauth2/vendor/golang.org/x/oauth2 \
		golang:protobuf:v1.4.2:golang_protobuf/vendor/github.com/golang/protobuf \
		golang:snappy:v0.0.4:golang_snappy/vendor/github.com/golang/snappy \
		golang:sync:036812b2e83c:golang_sync/vendor/golang.org/x/sync \
		golang:sys:e8d321eab015:golang_sys/vendor/golang.org/x/sys \
		golang:term:7de9c90e9dd1:golang_term/vendor/golang.org/x/term \
		golang:text:v0.3.6:golang_text/vendor/golang.org/x/text \
		golang:time:3af7569d3a1e:golang_time/vendor/golang.org/x/time \
		golang:tools:2dba1e4ea05c:golang_tools/vendor/golang.org/x/tools \
		golang:xerrors:5ec99f83aff1:golang_xerrors/vendor/golang.org/x/xerrors \
		google:flatbuffers:v1.11.0:google_flatbuffers/vendor/github.com/google/flatbuffers \
		google:go-cmp:v0.5.5:google_go_cmp/vendor/github.com/google/go-cmp \
		google:go-genproto:cb27e3aa2013:google_go_genproto/vendor/google.golang.org/genproto \
		google:go-github:v17.0.0:google_go_github/vendor/github.com/google/go-github \
		google:go-metrics-stackdriver:v0.2.0:google_go_metrics_stackdriver/vendor/github.com/google/go-metrics-stackdriver \
		google:go-querystring:v1.0.0:google_go_querystring/vendor/github.com/google/go-querystring \
		google:gofuzz:v1.1.0:google_gofuzz/vendor/github.com/google/gofuzz \
		google:uuid:v1.1.2:google_uuid/vendor/github.com/google/uuid \
		googleapis:gax-go:v2.0.5:googleapis_gax_go_v2/vendor/github.com/googleapis/gax-go \
		googleapis:gnostic:v0.2.0:googleapis_gnostic/vendor/github.com/googleapis/gnostic \
		googleapis:google-api-go-client:v0.29.0:googleapis_google_api_go_client/vendor/google.golang.org/api \
		googleapis:google-cloud-go:spanner/v1.5.1:googleapis_google_cloud_go_spanner \
		googleapis:google-cloud-go:storage/v1.6.0:googleapis_google_cloud_go_storage \
		googleapis:google-cloud-go:v0.56.0:googleapis_google_cloud_go/vendor/cloud.google.com/go \
		gophercloud:gophercloud:v0.1.0:gophercloud_gophercloud/vendor/github.com/gophercloud/gophercloud \
		gorhill:cronexpr:88b0669f7d75:gorhill_cronexpr/vendor/github.com/gorhill/cronexpr \
		gorilla:websocket:v1.4.1:gorilla_websocket/vendor/github.com/gorilla/websocket \
		grpc:grpc-go:v1.29.1:grpc_grpc_go/vendor/google.golang.org/grpc \
		hailocab:go-hostpool:e80d13ce29ed:hailocab_go_hostpool/vendor/github.com/hailocab/go-hostpool \
		hashicorp:cap:v0.1.0:hashicorp_cap/vendor/github.com/hashicorp/cap \
		hashicorp:consul-template:v0.26.0:hashicorp_consul_template/vendor/github.com/hashicorp/consul-template \
		hashicorp:consul:api/v1.4.0:hashicorp_consul_api/vendor/github.com/hashicorp/consul \
		hashicorp:errwrap:v1.1.0:hashicorp_errwrap/vendor/github.com/hashicorp/errwrap \
		hashicorp:go-bindata:bf7910af8997:hashicorp_go_bindata/vendor/github.com/hashicorp/go-bindata \
		hashicorp:go-cleanhttp:v0.5.2:hashicorp_go_cleanhttp/vendor/github.com/hashicorp/go-cleanhttp \
		hashicorp:go-discover:738cb3105cd0:hashicorp_go_discover/vendor/github.com/hashicorp/go-discover \
		hashicorp:go-gcp-common:v0.7.0:hashicorp_go_gcp_common/vendor/github.com/hashicorp/go-gcp-common \
		hashicorp:go-hclog:v0.16.1:hashicorp_go_hclog/vendor/github.com/hashicorp/go-hclog \
		hashicorp:go-immutable-radix:v1.3.0:hashicorp_go_immutable_radix/vendor/github.com/hashicorp/go-immutable-radix \
		hashicorp:go-kms-wrapping:entropy/v0.1.0:hashicorp_go_kms_wrapping_entropy \
		hashicorp:go-kms-wrapping:v0.5.16:hashicorp_go_kms_wrapping/vendor/github.com/hashicorp/go-kms-wrapping \
		hashicorp:go-memdb:v1.0.2:hashicorp_go_memdb/vendor/github.com/hashicorp/go-memdb \
		hashicorp:go-msgpack:v1.1.5:hashicorp_go_msgpack/vendor/github.com/hashicorp/go-msgpack \
		hashicorp:go-multierror:v1.1.1:hashicorp_go_multierror/vendor/github.com/hashicorp/go-multierror \
		hashicorp:go-plugin:v1.0.1:hashicorp_go_plugin/vendor/github.com/hashicorp/go-plugin \
		hashicorp:go-raftchunking:7e9e8525653a:hashicorp_go_raftchunking/vendor/github.com/hashicorp/go-raftchunking \
		hashicorp:go-retryablehttp:v0.6.7:hashicorp_go_retryablehttp/vendor/github.com/hashicorp/go-retryablehttp \
		hashicorp:go-rootcerts:v1.0.2:hashicorp_go_rootcerts/vendor/github.com/hashicorp/go-rootcerts \
		hashicorp:go-secure-stdlib:strutil/v0.1.1:hashicorp_go_secure_stdlib_strutil/vendor/github.com/hashicorp/go-secure-stdlib \
		hashicorp:go-slug:v0.4.1:hashicorp_go_slug/vendor/github.com/hashicorp/go-slug \
		hashicorp:go-sockaddr:v1.0.2:hashicorp_go_sockaddr/vendor/github.com/hashicorp/go-sockaddr \
		hashicorp:go-syslog:v1.0.0:hashicorp_go_syslog/vendor/github.com/hashicorp/go-syslog \
		hashicorp:go-tfe:v0.12.0:hashicorp_go_tfe/vendor/github.com/hashicorp/go-tfe \
		hashicorp:go-uuid:v1.0.2:hashicorp_go_uuid/vendor/github.com/hashicorp/go-uuid \
		hashicorp:go-version:v1.2.1:hashicorp_go_version/vendor/github.com/hashicorp/go-version \
		hashicorp:golang-lru:v0.5.4:hashicorp_golang_lru/vendor/github.com/hashicorp/golang-lru \
		hashicorp:hcl:v1.0.1-vault-3:hashicorp_hcl/vendor/github.com/hashicorp/hcl \
		hashicorp:logutils:v1.0.0:hashicorp_logutils/vendor/github.com/hashicorp/logutils \
		hashicorp:mdns:v1.0.1:hashicorp_mdns/vendor/github.com/hashicorp/mdns \
		hashicorp:nomad:edc62acd919d:hashicorp_nomad_api/vendor/github.com/hashicorp/nomad \
		hashicorp:raft-autopilot:v0.1.3:hashicorp_raft_autopilot/vendor/github.com/hashicorp/raft-autopilot \
		hashicorp:raft-boltdb:a7e34179d62c:hashicorp_raft_boltdb_v2/vendor/github.com/hashicorp/raft-boltdb \
		hashicorp:raft-snapshot:v1.0.3:hashicorp_raft_snapshot/vendor/github.com/hashicorp/raft-snapshot \
		hashicorp:raft:v1.3.0:hashicorp_raft/vendor/github.com/hashicorp/raft \
		hashicorp:serf:v0.9.5:hashicorp_serf/vendor/github.com/hashicorp/serf \
		hashicorp:vault-plugin-auth-alicloud:v0.9.0:hashicorp_vault_plugin_auth_alicloud/vendor/github.com/hashicorp/vault-plugin-auth-alicloud \
		hashicorp:vault-plugin-auth-azure:v0.8.0:hashicorp_vault_plugin_auth_azure/vendor/github.com/hashicorp/vault-plugin-auth-azure \
		hashicorp:vault-plugin-auth-centrify:v0.9.0:hashicorp_vault_plugin_auth_centrify/vendor/github.com/hashicorp/vault-plugin-auth-centrify \
		hashicorp:vault-plugin-auth-cf:v0.9.0:hashicorp_vault_plugin_auth_cf/vendor/github.com/hashicorp/vault-plugin-auth-cf \
		hashicorp:vault-plugin-auth-gcp:v0.10.0:hashicorp_vault_plugin_auth_gcp/vendor/github.com/hashicorp/vault-plugin-auth-gcp \
		hashicorp:vault-plugin-auth-jwt:v0.10.1:hashicorp_vault_plugin_auth_jwt/vendor/github.com/hashicorp/vault-plugin-auth-jwt \
		hashicorp:vault-plugin-auth-kerberos:v0.4.0:hashicorp_vault_plugin_auth_kerberos/vendor/github.com/hashicorp/vault-plugin-auth-kerberos \
		hashicorp:vault-plugin-auth-kubernetes:v0.10.1:hashicorp_vault_plugin_auth_kubernetes/vendor/github.com/hashicorp/vault-plugin-auth-kubernetes \
		hashicorp:vault-plugin-auth-oci:v0.8.0:hashicorp_vault_plugin_auth_oci/vendor/github.com/hashicorp/vault-plugin-auth-oci \
		hashicorp:vault-plugin-database-couchbase:v0.4.1:hashicorp_vault_plugin_database_couchbase/vendor/github.com/hashicorp/vault-plugin-database-couchbase \
		hashicorp:vault-plugin-database-elasticsearch:v0.8.0:hashicorp_vault_plugin_database_elasticsearch/vendor/github.com/hashicorp/vault-plugin-database-elasticsearch \
		hashicorp:vault-plugin-database-mongodbatlas:v0.4.0:hashicorp_vault_plugin_database_mongodbatlas/vendor/github.com/hashicorp/vault-plugin-database-mongodbatlas \
		hashicorp:vault-plugin-database-snowflake:v0.2.1:hashicorp_vault_plugin_database_snowflake/vendor/github.com/hashicorp/vault-plugin-database-snowflake \
		hashicorp:vault-plugin-mock:v0.16.1:hashicorp_vault_plugin_mock/vendor/github.com/hashicorp/vault-plugin-mock \
		hashicorp:vault-plugin-secrets-ad:v0.10.0:hashicorp_vault_plugin_secrets_ad/vendor/github.com/hashicorp/vault-plugin-secrets-ad \
		hashicorp:vault-plugin-secrets-alicloud:v0.9.0:hashicorp_vault_plugin_secrets_alicloud/vendor/github.com/hashicorp/vault-plugin-secrets-alicloud \
		hashicorp:vault-plugin-secrets-azure:v0.10.0:hashicorp_vault_plugin_secrets_azure/vendor/github.com/hashicorp/vault-plugin-secrets-azure \
		hashicorp:vault-plugin-secrets-gcp:v0.10.2:hashicorp_vault_plugin_secrets_gcp/vendor/github.com/hashicorp/vault-plugin-secrets-gcp \
		hashicorp:vault-plugin-secrets-gcpkms:v0.9.0:hashicorp_vault_plugin_secrets_gcpkms/vendor/github.com/hashicorp/vault-plugin-secrets-gcpkms \
		hashicorp:vault-plugin-secrets-kv:v0.9.0:hashicorp_vault_plugin_secrets_kv/vendor/github.com/hashicorp/vault-plugin-secrets-kv \
		hashicorp:vault-plugin-secrets-mongodbatlas:v0.4.0:hashicorp_vault_plugin_secrets_mongodbatlas/vendor/github.com/hashicorp/vault-plugin-secrets-mongodbatlas \
		hashicorp:vault-plugin-secrets-openldap:v0.5.1:hashicorp_vault_plugin_secrets_openldap/vendor/github.com/hashicorp/vault-plugin-secrets-openldap \
		hashicorp:vault-plugin-secrets-terraform:v0.2.0:hashicorp_vault_plugin_secrets_terraform/vendor/github.com/hashicorp/vault-plugin-secrets-terraform \
		hashicorp:vic:bbfe86ec9443:hashicorp_vic/vendor/github.com/hashicorp/vic \
		hashicorp:yamux:2f1d1f20f75d:hashicorp_yamux/vendor/github.com/hashicorp/yamux \
		huandu:xstrings:v1.3.2:huandu_xstrings/vendor/github.com/huandu/xstrings \
		imdario:mergo:v0.3.11:imdario_mergo/vendor/github.com/imdario/mergo \
		influxdata:influxdb:d24b7ba8c4c4:influxdata_influxdb/vendor/github.com/influxdata/influxdb \
		jackc:pgx:v3.3.0:jackc_pgx/vendor/github.com/jackc/pgx \
		jcmturner:aescts:v1.0.1:jcmturner_aescts/vendor/github.com/jcmturner/aescts \
		jcmturner:dnsutils:v1.0.1:jcmturner_dnsutils/vendor/github.com/jcmturner/dnsutils \
		jcmturner:gofork:v1.0.0:jcmturner_gofork/vendor/github.com/jcmturner/gofork \
		jcmturner:goidentity:v3.0.0:jcmturner_goidentity/vendor/gopkg.in/jcmturner/goidentity.v3 \
		jcmturner:goidentity:v6.0.1:jcmturner_goidentity_v6/vendor/github.com/jcmturner/goidentity \
		jcmturner:gokrb5:v8.0.0:jcmturner_gokrb5_v8/vendor/github.com/jcmturner/gokrb5 \
		jcmturner:rpc:v2.0.2:jcmturner_rpc_v2/vendor/github.com/jcmturner/rpc \
		jeffchao:backoff:9d7fd7aa17f2:jeffchao_backoff/vendor/github.com/jeffchao/backoff \
		jefferai:isbadcipher:51d2077c035f:jefferai_isbadcipher/vendor/github.com/jefferai/isbadcipher \
		jefferai:jsonx:v1.0.0:jefferai_jsonx/vendor/github.com/jefferai/jsonx \
		jmespath:go-jmespath:v0.4.0:jmespath_go_jmespath/vendor/github.com/jmespath/go-jmespath \
		joyent:triton-go:6801d15b779f:joyent_triton_go/vendor/github.com/joyent/triton-go \
		json-iterator:go:v1.1.10:json_iterator_go/vendor/github.com/json-iterator/go \
		jstemmer:go-junit-report:v0.9.1:jstemmer_go_junit_report/vendor/github.com/jstemmer/go-junit-report \
		kelseyhightower:envconfig:v1.4.0:kelseyhightower_envconfig/vendor/github.com/kelseyhightower/envconfig \
		keybase:go-crypto:d65b6b94177f:keybase_go_crypto/vendor/github.com/keybase/go-crypto \
		klauspost:compress:v1.9.5:klauspost_compress/vendor/github.com/klauspost/compress \
		kr:pretty:v0.2.1:kr_pretty/vendor/github.com/kr/pretty \
		kr:text:v0.2.0:kr_text/vendor/github.com/kr/text \
		kubernetes-sigs:structured-merge-diff:v3.0.0:kubernetes_sigs_structured_merge_diff/vendor/sigs.k8s.io/structured-merge-diff/v3 \
		kubernetes-sigs:yaml:v1.2.0:kubernetes_sigs_yaml/vendor/sigs.k8s.io/yaml \
		kubernetes:api:v0.18.2:kubernetes_api/vendor/k8s.io/api \
		kubernetes:apimachinery:v0.18.2:kubernetes_apimachinery/vendor/k8s.io/apimachinery \
		kubernetes:client-go:v0.18.2:kubernetes_client_go/vendor/k8s.io/client-go \
		kubernetes:klog:v1.0.0:kubernetes_klog/vendor/k8s.io/klog \
		kubernetes:utils:a9aa75ae1b89:kubernetes_utils/vendor/k8s.io/utils \
		layeh:radius:890bc1058917:layeh_radius/vendor/layeh.com/radius \
		lib:pq:v1.8.0:lib_pq/vendor/github.com/lib/pq \
		linode:linodego:v0.7.1:linode_linodego/vendor/github.com/linode/linodego \
		mattn:go-colorable:v0.1.8:mattn_go_colorable/vendor/github.com/mattn/go-colorable \
		mattn:go-ieproxy:v0.0.1:mattn_go_ieproxy/vendor/github.com/mattn/go-ieproxy \
		mattn:go-isatty:v0.0.12:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		mattn:go-shellwords:v1.0.12:mattn_go_shellwords/vendor/github.com/mattn/go-shellwords \
		matttproud:golang_protobuf_extensions:v1.0.1:matttproud_golang_protobuf_extensions/vendor/github.com/matttproud/golang_protobuf_extensions \
		mholt:archiver:v3.1.1:mholt_archiver/vendor/github.com/mholt/archiver \
		michaelklishin:rabbit-hole:93d9988f0cd5:michaelklishin_rabbit_hole/vendor/github.com/michaelklishin/rabbit-hole \
		miekg:dns:v1.1.40:miekg_dns/vendor/github.com/miekg/dns \
		mitchellh:cli:v1.1.2:mitchellh_cli/vendor/github.com/mitchellh/cli \
		mitchellh:copystructure:v1.0.0:mitchellh_copystructure/vendor/github.com/mitchellh/copystructure \
		mitchellh:go-homedir:v1.1.0:mitchellh_go_homedir/vendor/github.com/mitchellh/go-homedir \
		mitchellh:go-testing-interface:v1.14.0:mitchellh_go_testing_interface/vendor/github.com/mitchellh/go-testing-interface \
		mitchellh:go-wordwrap:v1.0.0:mitchellh_go_wordwrap/vendor/github.com/mitchellh/go-wordwrap \
		mitchellh:gox:v1.0.1:mitchellh_gox/vendor/github.com/mitchellh/gox \
		mitchellh:hashstructure:v1.0.0:mitchellh_hashstructure/vendor/github.com/mitchellh/hashstructure \
		mitchellh:iochan:v1.0.0:mitchellh_iochan/vendor/github.com/mitchellh/iochan \
		mitchellh:mapstructure:v1.3.3:mitchellh_mapstructure/vendor/github.com/mitchellh/mapstructure \
		mitchellh:pointerstructure:v1.0.0:mitchellh_pointerstructure/vendor/github.com/mitchellh/pointerstructure \
		mitchellh:reflectwalk:v1.0.1:mitchellh_reflectwalk/vendor/github.com/mitchellh/reflectwalk \
		moby:moby:v17.12.0-ce-rc1:moby_moby/vendor/github.com/docker/docker \
		moby:term:7f0af18e79f2:moby_term/vendor/github.com/moby/term \
		modern-go:concurrent:bacd9c7ef1dd:modern_go_concurrent/vendor/github.com/modern-go/concurrent \
		modern-go:reflect2:v1.0.1:modern_go_reflect2/vendor/github.com/modern-go/reflect2 \
		mongodb:go-client-mongodb-atlas:v0.1.2:mongodb_go_client_mongodb_atlas/vendor/github.com/mongodb/go-client-mongodb-atlas \
		mongodb:go-client-mongodb-atlas:v0.7.1:mongodb_go_client_mongodb_atlas_1/vendor/go.mongodb.org/atlas \
		mongodb:mongo-go-driver:v1.4.6:mongodb_mongo_go_driver/vendor/go.mongodb.org/mongo-driver \
		morikuni:aec:v1.0.0:morikuni_aec/vendor/github.com/morikuni/aec \
		mvdan:gofumpt:v0.1.1:mvdan_gofumpt/vendor/mvdan.cc/gofumpt \
		mwielbut:pointy:v1.1.0:mwielbut_pointy/vendor/github.com/mwielbut/pointy \
		natefinch:atomic:a62ce929ffcc:natefinch_atomic/vendor/github.com/natefinch/atomic \
		ncw:swift:v1.0.47:ncw_swift/vendor/github.com/ncw/swift \
		nicolai86:scaleway-sdk:798f60e20bb2:nicolai86_scaleway_sdk/vendor/github.com/nicolai86/scaleway-sdk \
		nwaples:rardecode:v1.1.0:nwaples_rardecode/vendor/github.com/nwaples/rardecode \
		oklog:run:v1.0.0:oklog_run/vendor/github.com/oklog/run \
		okta:okta-sdk-golang:v1.1.0:okta_okta_sdk_golang/vendor/github.com/okta/okta-sdk-golang \
		okta:okta-sdk-golang:v2.0.0:okta_okta_sdk_golang_v2/vendor/github.com/okta/okta-sdk-golang/v2 \
		open-telemetry:opentelemetry-go:v0.20.0:open_telemetry_opentelemetry_go/vendor/go.opentelemetry.io/otel \
		opencontainers:go-digest:v1.0.0-rc1:opencontainers_go_digest/vendor/github.com/opencontainers/go-digest \
		opencontainers:image-spec:v1.0.1:opencontainers_image_spec/vendor/github.com/opencontainers/image-spec \
		opencontainers:runc:v1.0.0-rc9:opencontainers_runc/vendor/github.com/opencontainers/runc \
		openlyinc:pointy:v1.1.2:openlyinc_pointy/vendor/github.com/openlyinc/pointy \
		oracle:oci-go-sdk:v12.5.0:oracle_oci_go_sdk/vendor/github.com/oracle/oci-go-sdk \
		ory-am:dockertest:v3.3.4:ory_am_dockertest/vendor/gopkg.in/ory-am/dockertest.v3 \
		ory:dockertest:v3.3.5:ory_dockertest/vendor/github.com/ory/dockertest \
		ory:dockertest:v3.6.2:ory_dockertest_v3/vendor/github.com/ory/dockertest/v3 \
		packethost:packngo:b9cb5096f54c:packethost_packngo/vendor/github.com/packethost/packngo \
		patrickmn:go-cache:v2.1.0:patrickmn_go_cache/vendor/github.com/patrickmn/go-cache \
		petermattis:goid:b0b1615b78e5:petermattis_goid/vendor/github.com/petermattis/goid \
		pierrec:lz4:v2.5.2:pierrec_lz4/vendor/github.com/pierrec/lz4 \
		pkg:browser:0a3d74bf9ce4:pkg_browser/vendor/github.com/pkg/browser \
		pkg:errors:v0.9.1:pkg_errors/vendor/github.com/pkg/errors \
		pmezard:go-difflib:v1.0.0:pmezard_go_difflib/vendor/github.com/pmezard/go-difflib \
		posener:complete:v1.2.3:posener_complete/vendor/github.com/posener/complete \
		pquerna:cachecontrol:ac21108117ac:pquerna_cachecontrol/vendor/github.com/pquerna/cachecontrol \
		pquerna:otp:468c2dd2b58d:pquerna_otp/vendor/github.com/pquerna/otp \
		prometheus:client_golang:v1.7.1:prometheus_client_golang/vendor/github.com/prometheus/client_golang \
		prometheus:client_model:v0.2.0:prometheus_client_model/vendor/github.com/prometheus/client_model \
		prometheus:common:v0.11.1:prometheus_common/vendor/github.com/prometheus/common \
		prometheus:procfs:v0.1.3:prometheus_procfs/vendor/github.com/prometheus/procfs \
		protocolbuffers:protobuf-go:v1.25.0:protocolbuffers_protobuf_go/vendor/google.golang.org/protobuf \
		rboyer:safeio:v0.2.1:rboyer_safeio/vendor/github.com/rboyer/safeio \
		renier:xmlrpc:ce4a1a486c03:renier_xmlrpc/vendor/github.com/renier/xmlrpc \
		ryanuber:columnize:v2.1.0:ryanuber_columnize/vendor/github.com/ryanuber/columnize \
		ryanuber:go-glob:v1.0.0:ryanuber_go_glob/vendor/github.com/ryanuber/go-glob \
		samuel:go-zookeeper:2cc03de413da:samuel_go_zookeeper/vendor/github.com/samuel/go-zookeeper \
		sasha-s:go-deadlock:v0.2.0:sasha_s_go_deadlock/vendor/github.com/sasha-s/go-deadlock \
		sethvargo:go-limiter:v0.3.0:sethvargo_go_limiter/vendor/github.com/sethvargo/go-limiter \
		shirou:gopsutil:v3.21.5:shirou_gopsutil/vendor/github.com/shirou/gopsutil \
		sirupsen:logrus:v1.7.0:sirupsen_logrus/vendor/github.com/sirupsen/logrus \
		snowflakedb:gosnowflake:v1.6.1:snowflakedb_gosnowflake/vendor/github.com/snowflakedb/gosnowflake \
		softlayer:softlayer-go:260589d94c7d:softlayer_softlayer_go/vendor/github.com/softlayer/softlayer-go \
		spf13:pflag:v1.0.5:spf13_pflag/vendor/github.com/spf13/pflag \
		square:go-jose:v2.5.1:square_go_jose/vendor/gopkg.in/square/go-jose.v2 \
		stretchr:objx:v0.2.0:stretchr_objx/vendor/github.com/stretchr/objx \
		stretchr:testify:v1.7.0:stretchr_testify/vendor/github.com/stretchr/testify \
		svanharmelen:jsonapi:0c0828c3f16d:svanharmelen_jsonapi/vendor/github.com/svanharmelen/jsonapi \
		tencentcloud:tencentcloud-sdk-go:v1.0.162:tencentcloud_tencentcloud_sdk_go/vendor/github.com/tencentcloud/tencentcloud-sdk-go \
		tidwall:pretty:v1.0.1:tidwall_pretty/vendor/github.com/tidwall/pretty \
		tklauser:go-sysconf:v0.3.6:tklauser_go_sysconf/vendor/github.com/tklauser/go-sysconf \
		tklauser:numcpus:v0.2.2:tklauser_numcpus/vendor/github.com/tklauser/numcpus \
		tv42:httpunix:b75d8614f926:tv42_httpunix/vendor/github.com/tv42/httpunix \
		uber-go:atomic:v1.6.0:uber_go_atomic/vendor/go.uber.org/atomic \
		uber-go:goleak:v1.1.10:uber_go_goleak/vendor/go.uber.org/goleak \
		uber-go:multierr:v1.5.0:uber_go_multierr/vendor/go.uber.org/multierr \
		uber-go:zap:v1.14.1:uber_go_zap/vendor/go.uber.org/zap \
		ulikunitz:xz:v0.5.7:ulikunitz_xz/vendor/github.com/ulikunitz/xz \
		vmware:govmomi:v0.18.0:vmware_govmomi/vendor/github.com/vmware/govmomi \
		xdg:scram:7eeb5667e42c:xdg_scram/vendor/github.com/xdg/scram \
		xdg:stringprep:v1.0.0:xdg_stringprep/vendor/github.com/xdg/stringprep \
		xi2:xz:48954b6210f8:xi2_xz/vendor/github.com/xi2/xz \
		yuin:gopher-lua:ee81675732da:yuin_gopher_lua/vendor/github.com/yuin/gopher-lua

post-extract:
	@${RM} -r ${WRKSRC}/vendor/cloud.google.com/go/spanner
	@${RLN} ${WRKSRC_googleapis_google_cloud_go_spanner}/spanner ${WRKSRC}/vendor/cloud.google.com/go/spanner
	@${RM} -r ${WRKSRC}/vendor/cloud.google.com/go/storage
	@${RLN} ${WRKSRC_googleapis_google_cloud_go_storage}/storage ${WRKSRC}/vendor/cloud.google.com/go/storage
	@${RM} -r ${WRKSRC}/vendor/github.com/Azure/go-autorest/autorest
	@${RLN} ${WRKSRC_azure_go_autorest_autorest}/autorest ${WRKSRC}/vendor/github.com/Azure/go-autorest/autorest
	@${RM} -r ${WRKSRC}/vendor/github.com/Azure/go-autorest/autorest/adal
	@${RLN} ${WRKSRC_azure_go_autorest_adal}/autorest/adal ${WRKSRC}/vendor/github.com/Azure/go-autorest/autorest/adal
	@${RM} -r ${WRKSRC}/vendor/github.com/Azure/go-autorest/autorest/azure/auth
	@${RLN} ${WRKSRC_azure_go_autorest_auth}/autorest/azure/auth ${WRKSRC}/vendor/github.com/Azure/go-autorest/autorest/azure/auth
	@${RM} -r ${WRKSRC}/vendor/github.com/Azure/go-autorest/autorest/azure/cli
	@${RLN} ${WRKSRC_azure_go_autorest_cli}/autorest/azure/cli ${WRKSRC}/vendor/github.com/Azure/go-autorest/autorest/azure/cli
	@${RM} -r ${WRKSRC}/vendor/github.com/Azure/go-autorest/autorest/date
	@${RLN} ${WRKSRC_azure_go_autorest_date}/autorest/date ${WRKSRC}/vendor/github.com/Azure/go-autorest/autorest/date
	@${RM} -r ${WRKSRC}/vendor/github.com/Azure/go-autorest/autorest/validation
	@${RLN} ${WRKSRC_azure_go_autorest_validation}/autorest/validation ${WRKSRC}/vendor/github.com/Azure/go-autorest/autorest/validation
	@${RM} -r ${WRKSRC}/vendor/github.com/Azure/go-autorest/logger
	@${RLN} ${WRKSRC_azure_go_autorest_logger}/logger ${WRKSRC}/vendor/github.com/Azure/go-autorest/logger
	@${RM} -r ${WRKSRC}/vendor/github.com/Azure/go-autorest/tracing
	@${RLN} ${WRKSRC_azure_go_autorest_tracing}/tracing ${WRKSRC}/vendor/github.com/Azure/go-autorest/tracing
	@${RM} -r ${WRKSRC}/vendor/github.com/aws/aws-sdk-go-v2/credentials
	@${RLN} ${WRKSRC_aws_aws_sdk_go_v2_credentials}/credentials ${WRKSRC}/vendor/github.com/aws/aws-sdk-go-v2/credentials
	@${RM} -r ${WRKSRC}/vendor/github.com/aws/aws-sdk-go-v2/feature/s3/manager
	@${RLN} ${WRKSRC_aws_aws_sdk_go_v2_manager}/feature/s3/manager ${WRKSRC}/vendor/github.com/aws/aws-sdk-go-v2/feature/s3/manager
	@${RM} -r ${WRKSRC}/vendor/github.com/aws/aws-sdk-go-v2/service/s3
	@${RLN} ${WRKSRC_aws_aws_sdk_go_v2_s3}/service/s3 ${WRKSRC}/vendor/github.com/aws/aws-sdk-go-v2/service/s3
	@${RM} -r ${WRKSRC}/vendor/github.com/hashicorp/go-kms-wrapping/entropy
	@${RLN} ${WRKSRC_hashicorp_go_kms_wrapping_entropy}/entropy ${WRKSRC}/vendor/github.com/hashicorp/go-kms-wrapping/entropy
	@${MKDIR} ${WRKSRC}/vendor/github.com/hashicorp/vault/
	@${RLN} ${WRKSRC}/api ${WRKSRC}/vendor/github.com/hashicorp/vault/api
	@${RLN} ${WRKSRC}/sdk ${WRKSRC}/vendor/github.com/hashicorp/vault/sdk

GO_PKGNAME=	github.com/${GH_ACCOUNT}/${PORTNAME}
COMMIT_ID=	aca76f63357041a43b49f3e8c11d67358496959f
GO_BUILDFLAGS=	-tags=ui \
		-ldflags="\
		-X github.com/hashicorp/vault/sdk/version.Version=${PORTVERSION} \
		-X github.com/hashicorp/vault/sdk/version.VersionPrerelease= \
		-X github.com/hashicorp/vault/sdk/version.VersionMetadata= \
		-X github.com/hashicorp/vault/sdk/version.GitCommit='${COMMIT_ID}'"

VAULTTAG=	${DISTVERSIONPREFIX}${PORTVERSION}
VAULTUITAG=	${DISTVERSIONPREFIX}${PORTVERSION}

USE_RC_SUBR=	vault

USERS=		vault
GROUPS=		vault

PLIST_FILES=	bin/${PORTNAME}
SUB_FILES=	pkg-message

PORTSCOUT=	limit:^(v?)[0-9]+\.[0-9]+\.[0-9]+$

post-patch:
	@${CP} ${WRKDIR}/vaultui-${PORTVERSION}/http/bindata_assetfs.go ${WRKDIR}/vault-${PORTVERSION}/http/bindata_assetfs.go

.include <bsd.port.mk>
