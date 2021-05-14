PORTNAME=	rclone
DISTVERSIONPREFIX=	v
DISTVERSION=	1.55.1
CATEGORIES=	net

MAINTAINER=	brad@facefault.org
COMMENT=	Sync files to and from various cloud services

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	ncw
GH_TUPLE=	Azure:azure-pipeline-go:v0.2.3:azure_azure_pipeline_go/vendor/github.com/Azure/azure-pipeline-go \
		Azure:azure-storage-blob-go:v0.13.0:azure_azure_storage_blob_go/vendor/github.com/Azure/azure-storage-blob-go \
		Azure:go-autorest:9ff0227e2e0b:azure_go_autorest_adal \
		Azure:go-autorest:b3a0b30a7423:azure_go_autorest_date \
		Azure:go-autorest:tracing/v0.6.0:azure_go_autorest_tracing \
		Azure:go-autorest:v14.2.0:azure_go_autorest/vendor/github.com/Azure/go-autorest \
		Azure:go-ntlmssp:66371956d46c:azure_go_ntlmssp/vendor/github.com/Azure/go-ntlmssp \
		Microsoft:go-winio:v0.4.16:microsoft_go_winio/vendor/github.com/Microsoft/go-winio \
		Unknwon:goconfig:df7de6a44db8:unknwon_goconfig/vendor/github.com/Unknwon/goconfig \
		a8m:tree:10a5fd5b637d:a8m_tree/vendor/github.com/a8m/tree \
		aalpar:deheap:9a0c2883bd56:aalpar_deheap/vendor/github.com/aalpar/deheap \
		abbot:go-http-auth:v0.4.0:abbot_go_http_auth/vendor/github.com/abbot/go-http-auth \
		anacrolix:dms:v1.2.0:anacrolix_dms/vendor/github.com/anacrolix/dms \
		atotto:clipboard:v0.1.2:atotto_clipboard/vendor/github.com/atotto/clipboard \
		aws:aws-sdk-go:v1.37.3:aws_aws_sdk_go/vendor/github.com/aws/aws-sdk-go \
		bazil:fuse:fb710f7dfd05:bazil_fuse/vendor/bazil.org/fuse \
		beorn7:perks:v1.0.1:beorn7_perks/vendor/github.com/beorn7/perks \
		billziss-gh:cgofuse:v1.5.0:billziss_gh_cgofuse/vendor/github.com/billziss-gh/cgofuse \
		btcsuite:btcutil:a53e38424cce:btcsuite_btcutil/vendor/github.com/btcsuite/btcutil \
		buengese:sgzip:v0.1.1:buengese_sgzip/vendor/github.com/buengese/sgzip \
		calebcase:tmpfile:v1.0.2:calebcase_tmpfile/vendor/github.com/calebcase/tmpfile \
		census-instrumentation:opencensus-go:v0.22.6:census_instrumentation_opencensus_go/vendor/go.opencensus.io \
		cespare:xxhash:v2.1.1:cespare_xxhash_v2/vendor/github.com/cespare/xxhash/v2 \
		colinmarc:hdfs:v2.2.0:colinmarc_hdfs_v2/vendor/github.com/colinmarc/hdfs/v2 \
		coreos:go-semver:v0.3.0:coreos_go_semver/vendor/github.com/coreos/go-semver \
		cpuguy83:go-md2man:v2.0.0:cpuguy83_go_md2man_v2/vendor/github.com/cpuguy83/go-md2man/v2 \
		davecgh:go-spew:v1.1.1:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		dop251:scsu:8fadfb689669:dop251_scsu/vendor/github.com/dop251/scsu \
		dropbox:dropbox-sdk-go-unofficial:41fdcdae8a53:dropbox_dropbox_sdk_go_unofficial/vendor/github.com/dropbox/dropbox-sdk-go-unofficial \
		etcd-io:bbolt:v1.3.5:etcd_io_bbolt/vendor/go.etcd.io/bbolt \
		form3tech-oss:jwt-go:v3.2.2:form3tech_oss_jwt_go/vendor/github.com/form3tech-oss/jwt-go \
		gabriel-vasile:mimetype:v1.1.2:gabriel_vasile_mimetype/vendor/github.com/gabriel-vasile/mimetype \
		go-yaml:yaml:496545a6307b:go_yaml_yaml_1/vendor/gopkg.in/yaml.v3 \
		go-yaml:yaml:v2.4.0:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		gogo:protobuf:v1.3.2:gogo_protobuf/vendor/github.com/gogo/protobuf \
		golang:appengine:v1.6.7:golang_appengine/vendor/google.golang.org/appengine \
		golang:crypto:5ea612d1eb83:golang_crypto/vendor/golang.org/x/crypto \
		golang:groupcache:8c9f03a8e57e:golang_groupcache/vendor/github.com/golang/groupcache \
		golang:net:5f4716e94777:golang_net/vendor/golang.org/x/net \
		golang:oauth2:010130855d6c:golang_oauth2/vendor/golang.org/x/oauth2 \
		golang:protobuf:v1.4.3:golang_protobuf/vendor/github.com/golang/protobuf \
		golang:sync:09787c993a3a:golang_sync/vendor/golang.org/x/sync \
		golang:sys:8e9fff1a3a18:golang_sys/vendor/golang.org/x/sys \
		golang:term:2321bbc49cbf:golang_term/vendor/golang.org/x/term \
		golang:text:v0.3.5:golang_text/vendor/golang.org/x/text \
		golang:time:7e3f01d25324:golang_time/vendor/golang.org/x/time \
		google:go-genproto:3206188e46ba:google_go_genproto/vendor/google.golang.org/genproto \
		google:go-querystring:v1.0.0:google_go_querystring/vendor/github.com/google/go-querystring \
		google:uuid:v1.2.0:google_uuid/vendor/github.com/google/uuid \
		googleapis:gax-go:v2.0.5:googleapis_gax_go_v2/vendor/github.com/googleapis/gax-go \
		googleapis:google-api-go-client:v0.38.0:googleapis_google_api_go_client/vendor/google.golang.org/api \
		googleapis:google-cloud-go:v0.76.0:googleapis_google_cloud_go/vendor/cloud.google.com/go \
		grpc:grpc-go:v1.35.0:grpc_grpc_go/vendor/google.golang.org/grpc \
		hanwen:go-fuse:v2.0.3:hanwen_go_fuse_v2/vendor/github.com/hanwen/go-fuse/v2 \
		hashicorp:go-uuid:v1.0.2:hashicorp_go_uuid/vendor/github.com/hashicorp/go-uuid \
		iguanesolutions:go-systemd:v5.0.0:iguanesolutions_go_systemd_v5/vendor/github.com/iguanesolutions/go-systemd/v5 \
		inconshreveable:mousetrap:v1.0.0:inconshreveable_mousetrap/vendor/github.com/inconshreveable/mousetrap \
		jcmturner:aescts:v2.0.0:jcmturner_aescts_v2/vendor/github.com/jcmturner/aescts \
		jcmturner:dnsutils:v2.0.0:jcmturner_dnsutils_v2/vendor/github.com/jcmturner/dnsutils \
		jcmturner:gofork:v1.0.0:jcmturner_gofork/vendor/github.com/jcmturner/gofork \
		jcmturner:goidentity:v6.0.1:jcmturner_goidentity_v6/vendor/github.com/jcmturner/goidentity \
		jcmturner:gokrb5:v8.4.2:jcmturner_gokrb5_v8/vendor/github.com/jcmturner/gokrb5 \
		jcmturner:rpc:v2.0.3:jcmturner_rpc_v2/vendor/github.com/jcmturner/rpc \
		jlaffaye:ftp:c3c8c7ac6590:jlaffaye_ftp/vendor/github.com/jlaffaye/ftp \
		jmespath:go-jmespath:v0.4.0:jmespath_go_jmespath/vendor/github.com/jmespath/go-jmespath \
		jzelinskie:whirlpool:0675e54bb004:jzelinskie_whirlpool/vendor/github.com/jzelinskie/whirlpool \
		kardianos:osext:2bc1f35cddc0:kardianos_osext/vendor/github.com/kardianos/osext \
		klauspost:compress:v1.11.7:klauspost_compress/vendor/github.com/klauspost/compress \
		koofr:go-httpclient:93aa7c75b348:koofr_go_httpclient/vendor/github.com/koofr/go-httpclient \
		koofr:go-koofrclient:8e5366da203a:koofr_go_koofrclient/vendor/github.com/koofr/go-koofrclient \
		kr:fs:v0.1.0:kr_fs/vendor/github.com/kr/fs \
		mattn:go-colorable:v0.1.8:mattn_go_colorable/vendor/github.com/mattn/go-colorable \
		mattn:go-ieproxy:v0.0.1:mattn_go_ieproxy/vendor/github.com/mattn/go-ieproxy \
		mattn:go-isatty:v0.0.12:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		mattn:go-runewidth:v0.0.10:mattn_go_runewidth/vendor/github.com/mattn/go-runewidth \
		matttproud:golang_protobuf_extensions:v1.0.1:matttproud_golang_protobuf_extensions/vendor/github.com/matttproud/golang_protobuf_extensions \
		mitchellh:go-homedir:v1.1.0:mitchellh_go_homedir/vendor/github.com/mitchellh/go-homedir \
		ncw:go-acd:fe55f33415b1:ncw_go_acd/vendor/github.com/ncw/go-acd \
		ncw:swift:v2.0.0:ncw_swift_v2/vendor/github.com/ncw/swift/v2 \
		nsf:termbox-go:d04385b850e8:nsf_termbox_go/vendor/github.com/nsf/termbox-go \
		patrickmn:go-cache:v2.1.0:patrickmn_go_cache/vendor/github.com/patrickmn/go-cache \
		pengsrc:go-shared:1999055a4a14:pengsrc_go_shared/vendor/github.com/pengsrc/go-shared \
		pkg:errors:v0.9.1:pkg_errors/vendor/github.com/pkg/errors \
		pkg:sftp:v1.12.0:pkg_sftp/vendor/github.com/pkg/sftp \
		pmezard:go-difflib:v1.0.0:pmezard_go_difflib/vendor/github.com/pmezard/go-difflib \
		prometheus:client_golang:v1.9.0:prometheus_client_golang/vendor/github.com/prometheus/client_golang \
		prometheus:client_model:v0.2.0:prometheus_client_model/vendor/github.com/prometheus/client_model \
		prometheus:common:v0.15.0:prometheus_common/vendor/github.com/prometheus/common \
		prometheus:procfs:v0.3.0:prometheus_procfs/vendor/github.com/prometheus/procfs \
		protocolbuffers:protobuf-go:v1.25.0:protocolbuffers_protobuf_go/vendor/google.golang.org/protobuf \
		putdotio:go-putio:16d982cac2b8:putdotio_go_putio_putio/vendor/github.com/putdotio/go-putio \
		rfjakob:eme:v1.1.1:rfjakob_eme/vendor/github.com/rfjakob/eme \
		rivo:uniseg:v0.2.0:rivo_uniseg/vendor/github.com/rivo/uniseg \
		russross:blackfriday:v2.1.0:russross_blackfriday_v2/vendor/github.com/russross/blackfriday/v2 \
		sevlyar:go-daemon:v0.1.5:sevlyar_go_daemon/vendor/github.com/sevlyar/go-daemon \
		sirupsen:logrus:v1.7.0:sirupsen_logrus/vendor/github.com/sirupsen/logrus \
		skratchdot:open-golang:eef842397966:skratchdot_open_golang/vendor/github.com/skratchdot/open-golang \
		spacemonkeygo:monkit:v3.0.7:spacemonkeygo_monkit_v3/vendor/github.com/spacemonkeygo/monkit/v3 \
		spf13:cobra:v1.1.1:spf13_cobra/vendor/github.com/spf13/cobra \
		spf13:pflag:v1.0.5:spf13_pflag/vendor/github.com/spf13/pflag \
		storj:common:3768017a858e:storj_common/vendor/storj.io/common \
		storj:drpc:v0.0.16:storj_drpc/vendor/storj.io/drpc \
		storj:uplink:v1.4.5:storj_uplink/vendor/storj.io/uplink \
		stretchr:testify:v1.7.0:stretchr_testify/vendor/github.com/stretchr/testify \
		t3rm1n4l:go-mega:ffad7fcb44b8:t3rm1n4l_go_mega/vendor/github.com/t3rm1n4l/go-mega \
		uber-go:atomic:v1.7.0:uber_go_atomic/vendor/go.uber.org/atomic \
		uber-go:multierr:v1.6.0:uber_go_multierr/vendor/go.uber.org/multierr \
		uber-go:zap:v1.16.0:uber_go_zap/vendor/go.uber.org/zap \
		vivint:infectious:25a574ae18a3:vivint_infectious/vendor/github.com/vivint/infectious \
		xanzy:ssh-agent:v0.3.0:xanzy_ssh_agent/vendor/github.com/xanzy/ssh-agent \
		youmark:pkcs8:1326539a0a0a:youmark_pkcs8/vendor/github.com/youmark/pkcs8 \
		yunify:qingstor-sdk-go:v3.2.0:yunify_qingstor_sdk_go_v3/vendor/github.com/yunify/qingstor-sdk-go/v3 \
		zeebo:errs:v1.2.2:zeebo_errs/vendor/github.com/zeebo/errs

_GITEA_TUPLE=	goftp:server:v0.4.1:vendor/goftp.io/server

PLIST_FILES=	bin/rclone

.include <bsd.port.pre.mk>

.for account project tag subdir in ${_GITEA_TUPLE:S/:/ /g}
MASTER_SITES+=	https://gitea.com/${account}/${project}/archive/${tag}${EXTRACT_SUFX}?dummy=/:${account}_${project}
DISTFILES+=	${account}-${project}-${tag}_GITEA0${EXTRACT_SUFX}:${account}_${project}
.endfor

post-extract:
	@${RM} -r ${WRKSRC}/vendor/github.com/Azure/go-autorest/autorest/adal
	@${RLN} ${WRKSRC_azure_go_autorest_adal}/autorest/adal ${WRKSRC}/vendor/github.com/Azure/go-autorest/autorest/adal
	@${RM} -r ${WRKSRC}/vendor/github.com/Azure/go-autorest/autorest/date
	@${RLN} ${WRKSRC_azure_go_autorest_date}/autorest/date ${WRKSRC}/vendor/github.com/Azure/go-autorest/autorest/date
	@${RM} -r ${WRKSRC}/vendor/github.com/Azure/go-autorest/tracing
	@${RLN} ${WRKSRC_azure_go_autorest_tracing}/tracing ${WRKSRC}/vendor/github.com/Azure/go-autorest/tracing
.for account project tag subdir in ${_GITEA_TUPLE:S/:/ /g}
	@${MKDIR} ${WRKSRC}/${subdir:H}
	@${RLN} ${WRKDIR}/${project} ${WRKSRC}/${subdir}
.endfor

.include <bsd.port.post.mk>
