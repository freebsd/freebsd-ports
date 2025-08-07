PORTNAME=	bosun
DISTVERSION=	0.9.0
DISTVERSIONSUFFIX=	-preview
PORTREVISION=	29
CATEGORIES=	net-mgmt

MAINTAINER=	langer.markus@gmail.com
COMMENT=	Time series alerting framework developed by Stack Exchange
WWW=		https://bosun.org/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules uidfix

USE_GITHUB=	yes
GH_ACCOUNT=	bosun-monitor
GH_TUPLE=	\
		Azure:azure-sdk-for-go:v21.1.0:azure_azure_sdk_for_go/vendor/github.com/Azure/azure-sdk-for-go \
		Azure:go-autorest:v11.1.0:azure_go_autorest/vendor/github.com/Azure/go-autorest \
		BurntSushi:toml:v0.3.1:burntsushi_toml/vendor/github.com/BurntSushi/toml \
		GROpenSourceDev:go-ntlm-auth:6314d66e1d8f:gropensourcedev_go_ntlm_auth/vendor/github.com/GROpenSourceDev/go-ntlm-auth \
		GaryBoone:GoStats:1993eafbef57:garyboone_gostats/vendor/github.com/GaryBoone/GoStats \
		MiniProfiler:go:3296d396d472:miniprofiler_go/vendor/github.com/MiniProfiler/go \
		NYTimes:gziphandler:63027b26b87e:nytimes_gziphandler/vendor/github.com/NYTimes/gziphandler \
		PuerkitoBio:goquery:417cce822c7b:puerkitobio_goquery/vendor/github.com/PuerkitoBio/goquery \
		StackExchange:httpunit:088c22a5342e:stackexchange_httpunit/vendor/github.com/StackExchange/httpunit \
		StackExchange:mof:cfc83d4047d1:stackexchange_mof/vendor/github.com/StackExchange/mof \
		StackExchange:wmi:b12b22c5341f:stackexchange_wmi/vendor/github.com/StackExchange/wmi \
		ajstarks:svgo:fd2151ebabde:ajstarks_svgo/vendor/github.com/ajstarks/svgo \
		andybalholm:cascadia:3ad29d1ad1c4:andybalholm_cascadia/vendor/github.com/andybalholm/cascadia \
		aws:aws-sdk-go:v1.31.12:aws_aws_sdk_go/vendor/github.com/aws/aws-sdk-go \
		aymerick:douceur:7176f1467381:aymerick_douceur/vendor/github.com/aymerick/douceur \
		beorn7:perks:3a771d992973:beorn7_perks/vendor/github.com/beorn7/perks \
		bosun-monitor:statusio:ab1583139762:bosun_monitor_statusio/vendor/github.com/bosun-monitor/statusio \
		bradfitz:slice:a665b5dbaad5:bradfitz_slice/vendor/github.com/bradfitz/slice \
		captncraig:easyauth:c6de284138cf:captncraig_easyauth/vendor/github.com/captncraig/easyauth \
		cespare:xxhash:v1.1.0:cespare_xxhash/vendor/github.com/cespare/xxhash \
		coreos:go-systemd:7b2428fec400:coreos_go_systemd/vendor/github.com/coreos/go-systemd \
		cupcake:rdb:3454dcabd33c:cupcake_rdb/vendor/github.com/cupcake/rdb \
		davecgh:go-spew:v1.1.1:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		dgrijalva:jwt-go:v3.2.0:dgrijalva_jwt_go/vendor/github.com/dgrijalva/jwt-go \
		dimchansky:utfbom:v1.0.0:dimchansky_utfbom/vendor/github.com/dimchansky/utfbom \
		edsrzf:mmap-go:903d080718bd:edsrzf_mmap_go/vendor/github.com/edsrzf/mmap-go \
		facebookgo:httpcontrol:ccde4420e1fe:facebookgo_httpcontrol/vendor/github.com/facebookgo/httpcontrol \
		fsnotify:fsnotify:v1.4.7:fsnotify_fsnotify/vendor/gopkg.in/fsnotify.v1 \
		garyburd:redigo:836b6e58b335:garyburd_redigo/vendor/github.com/garyburd/redigo \
		glendc:gopher-json:dc4743023d0c:glendc_gopher_json/vendor/github.com/glendc/gopher-json \
		go-asn1-ber:asn1-ber:9eae18c3681a:go_asn1_ber_asn1_ber/vendor/gopkg.in/asn1-ber.v1 \
		go-kit:kit:v0.8.0:go_kit_kit/vendor/github.com/go-kit/kit \
		go-ldap:ldap:0041a4127039:go_ldap_ldap/vendor/gopkg.in/ldap.v1 \
		go-logfmt:logfmt:v0.3.0:go_logfmt_logfmt/vendor/github.com/go-logfmt/logfmt \
		go-ole:go-ole:v1.2.1:go_ole_go_ole/vendor/github.com/go-ole/go-ole \
		go-yaml:yaml:9f9df34309c0:go_yaml_yaml/vendor/gopkg.in/yaml.v1 \
		go-yaml:yaml:v2.2.4:go_yaml_yaml_1/vendor/gopkg.in/yaml.v2 \
		gocarina:gocsv:3ecffd272576:gocarina_gocsv/vendor/github.com/gocarina/gocsv \
		godbus:dbus:7a8c533d28e8:godbus_dbus/vendor/github.com/godbus/dbus \
		gogo:protobuf:v1.1.1:gogo_protobuf/vendor/github.com/gogo/protobuf \
		golang:appengine:v1.4.0:golang_appengine/vendor/google.golang.org/appengine \
		golang:crypto:089bfa567519:golang_crypto/vendor/golang.org/x/crypto \
		golang:freetype:f29eb116deb3:golang_freetype/vendor/github.com/golang/freetype \
		golang:glog:23def4e6c14b:golang_glog/vendor/github.com/golang/glog \
		golang:groupcache:869f871628b6:golang_groupcache/vendor/github.com/golang/groupcache \
		golang:image:baddd3465a05:golang_image/vendor/golang.org/x/image \
		golang:net:v0.8.0:golang_net/vendor/golang.org/x/net \
		golang:oauth2:d2e6202438be:golang_oauth2/vendor/golang.org/x/oauth2 \
		golang:protobuf:v1.3.1:golang_protobuf/vendor/github.com/golang/protobuf \
		golang:snappy:d9eb7a3d35ec:golang_snappy/vendor/github.com/golang/snappy \
		golang:sync:v0.1.0:golang_sync/vendor/golang.org/x/sync \
		golang:sys:v0.6.0:golang_sys/vendor/golang.org/x/sys \
		google:cadvisor:e9739af18411:google_cadvisor/vendor/github.com/google/cadvisor \
		google:go-github:44b1ede22d71:google_go_github/vendor/github.com/google/go-github \
		google:go-querystring:2a60fc2ba6c1:google_go_querystring/vendor/github.com/google/go-querystring \
		googleapis:google-api-go-client:20530fd5d65a:googleapis_google_api_go_client/vendor/google.golang.org/api \
		googleapis:google-cloud-go:v0.26.0:googleapis_google_cloud_go/vendor/cloud.google.com/go \
		gorilla:context:v1.1.1:gorilla_context/vendor/github.com/gorilla/context \
		gorilla:css:a80e24ada269:gorilla_css/vendor/github.com/gorilla/css \
		gorilla:mux:757bef944d0f:gorilla_mux/vendor/github.com/gorilla/mux \
		gorilla:securecookie:fa5329f91370:gorilla_securecookie/vendor/github.com/gorilla/securecookie \
		influxdata:influxdb:v1.6.3:influxdata_influxdb/vendor/github.com/influxdata/influxdb \
		influxdata:influxql:a7267bff5327:influxdata_influxql/vendor/github.com/influxdata/influxql \
		jinzhu:now:ce80572eb55a:jinzhu_now/vendor/github.com/jinzhu/now \
		jmespath:go-jmespath:v0.3.0:jmespath_go_jmespath/vendor/github.com/jmespath/go-jmespath \
		jmoiron:jsonq:e874b168d07e:jmoiron_jsonq/vendor/github.com/jmoiron/jsonq \
		jordan-wright:email:f61123ea07e1:jordan_wright_email/vendor/github.com/jordan-wright/email \
		justinas:alice:1051eaf52fca:justinas_alice/vendor/github.com/justinas/alice \
		kardianos:osext:c2c54e542fb7:kardianos_osext/vendor/github.com/kardianos/osext \
		kr:logfmt:b84e30acd515:kr_logfmt/vendor/github.com/kr/logfmt \
		kylebrandt:boolq:f869a7265c7e:kylebrandt_boolq/vendor/github.com/kylebrandt/boolq \
		kylebrandt:gohop:f6dbeb38f6df:kylebrandt_gohop/vendor/github.com/kylebrandt/gohop \
		llgcode:draw2d:9ffe0e7eb54c:llgcode_draw2d/vendor/github.com/llgcode/draw2d \
		mailru:easyjson:v0.7.1:mailru_easyjson/vendor/github.com/mailru/easyjson \
		matttproud:golang_protobuf_extensions:v1.0.1:matttproud_golang_protobuf_extensions/vendor/github.com/matttproud/golang_protobuf_extensions \
		mhenderson-so:azure-ea-billing:4fd1a790460c:mhenderson_so_azure_ea_billing/vendor/github.com/mhenderson-so/azure-ea-billing \
		mitchellh:go-homedir:v1.0.0:mitchellh_go_homedir/vendor/github.com/mitchellh/go-homedir \
		mjibson:esc:v0.1.0:mjibson_esc/vendor/github.com/mjibson/esc \
		oklog:ulid:v1.3.1:oklog_ulid/vendor/github.com/oklog/ulid \
		olivere:elastic:33ad30f61610:olivere_elastic/vendor/github.com/olivere/elastic \
		olivere:elastic:v3.0.56:olivere_elastic_1/vendor/gopkg.in/olivere/elastic.v3 \
		olivere:elastic:v5.0.48:olivere_elastic_2/vendor/gopkg.in/olivere/elastic.v5 \
		olivere:elastic:v7.0.17:olivere_elastic_v7/vendor/github.com/olivere/elastic/v7 \
		opentracing:opentracing-go:v1.1.0:opentracing_opentracing_go/vendor/github.com/opentracing/opentracing-go \
		pelletier:go-toml:v1.6.0:pelletier_go_toml/vendor/github.com/pelletier/go-toml \
		pkg:errors:v0.9.1:pkg_errors/vendor/github.com/pkg/errors \
		pmezard:go-difflib:v1.0.0:pmezard_go_difflib/vendor/github.com/pmezard/go-difflib \
		prometheus:client_golang:d2ead2588477:prometheus_client_golang/vendor/github.com/prometheus/client_golang \
		prometheus:client_model:5c3871d89910:prometheus_client_model/vendor/github.com/prometheus/client_model \
		prometheus:common:v0.1.0:prometheus_common/vendor/github.com/prometheus/common \
		prometheus:procfs:1dc9a6cbc91a:prometheus_procfs/vendor/github.com/prometheus/procfs \
		prometheus:prometheus:b639fe140c1f:prometheus_prometheus/vendor/github.com/prometheus/prometheus \
		prometheus:tsdb:v0.3.1:prometheus_tsdb/vendor/github.com/prometheus/tsdb \
		ryanuber:go-glob:572520ed46db:ryanuber_go_glob/vendor/github.com/ryanuber/go-glob \
		siddontang:go:b151716326d7:siddontang_go/vendor/github.com/siddontang/go \
		siddontang:goredis:760763f78400:siddontang_goredis/vendor/github.com/siddontang/goredis \
		siddontang:ledisdb:8ceb77e66a92:siddontang_ledisdb/vendor/github.com/siddontang/ledisdb \
		siddontang:rdb:fc89ed2e418d:siddontang_rdb/vendor/github.com/siddontang/rdb \
		stretchr:testify:v1.5.1:stretchr_testify/vendor/github.com/stretchr/testify \
		syndtr:goleveldb:1a9d62f03ea9:syndtr_goleveldb/vendor/github.com/syndtr/goleveldb \
		tatsushid:go-fastping:06cac0fecdc2:tatsushid_go_fastping/vendor/github.com/tatsushid/go-fastping \
		twinj:uuid:89173bcdda19:twinj_uuid/vendor/github.com/twinj/uuid \
		ugorji:go:ea9cd21fa0bc:ugorji_go/vendor/github.com/ugorji/go \
		vdobler:chart:293b01f8b75d:vdobler_chart/vendor/github.com/vdobler/chart \
		vmware:govmomi:a2138329bbd1:vmware_govmomi/vendor/github.com/vmware/govmomi \
		yuin:gopher-lua:1cd887cd7036:yuin_gopher_lua/vendor/github.com/yuin/gopher-lua

USE_RC_SUBR=	bosun

GO_TARGET=	./cmd/bosun

SUB_FILES=	bosun
SUB_LIST=	USERS=${USERS} \
		GROUPS=${GROUPS} \
		BOSUN_CONFDIR=${ETCDIR} \
		BOSUN_LOGDIR=${BOSUN_LOGDIR}
PLIST_SUB=	USERS=${USERS} \
		GROUPS=${GROUPS} \
		BOSUN_CONFDIR=${ETCDIR} \
		BOSUN_LOGDIR=${BOSUN_LOGDIR}

USERS=		bosun
GROUPS=		bosun

BOSUN_LOGDIR=	/var/log/${PORTNAME}

post-install:
	${MKDIR} \
		${STAGEDIR}${BOSUN_LOGDIR} \
		${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} \
		${WRKSRC}/cmd/bosun/bosun.example.toml \
		${STAGEDIR}${ETCDIR}/bosun.conf.sample

.include <bsd.port.mk>
