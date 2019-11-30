# $FreeBSD$

PORTNAME=	perkeep
DISTVERSION=	0.10.20190926
CATEGORIES=	misc

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Storage system: Storing, syncing, sharing, modelling, backing up files

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		go:modules
USE_GITHUB=	yes
GH_TAGNAME=	d342b0e # master branch doesn't contain 0.10
GH_TUPLE=	\
		FiloSottile:b2:b197f7a2c317:filosottile_b2/vendor/github.com/FiloSottile/b2 \
		aws:aws-sdk-go:v1.14.31:aws_aws_sdk_go/vendor/github.com/aws/aws-sdk-go \
		bradfitz:latlong:b74550508561:bradfitz_latlong/vendor/github.com/bradfitz/latlong \
		census-instrumentation:opencensus-go:v0.21.0:census_instrumentation_opencensus_go/vendor/go.opencensus.io \
		cznic:fileutil:6a051e75936f:cznic_fileutil/vendor/github.com/cznic/fileutil \
		cznic:internal:4747030f7cf2:cznic_internal/vendor/github.com/cznic/internal \
		cznic:kv:892ccf731fb7:cznic_kv/vendor/github.com/cznic/kv \
		cznic:lldb:v1.1.0:cznic_lldb/vendor/github.com/cznic/lldb \
		cznic:mathutil:5455a562bccb:cznic_mathutil/vendor/github.com/cznic/mathutil \
		cznic:sortutil:4c7342852e65:cznic_sortutil/vendor/github.com/cznic/sortutil \
		cznic:zappy:2533cb5b45cc:cznic_zappy/vendor/github.com/cznic/zappy \
		edsrzf:mmap-go:0bce6a688712:edsrzf_mmap_go/vendor/github.com/edsrzf/mmap-go \
		garyburd:go-oauth:bca2e7f09a17:garyburd_go_oauth/vendor/github.com/garyburd/go-oauth \
		go-ini:ini:v1.38.1:go_ini_ini/vendor/github.com/go-ini/ini \
		go-mgo:mgo:3f83fa500528:go_mgo_mgo/vendor/gopkg.in/mgo.v2 \
		go-sql-driver:mysql:99ff426eb706:go_sql_driver_mysql/vendor/github.com/go-sql-driver/mysql \
		go4org:go4:ce4c26f7be8e:go4org_go4/vendor/go4.org \
		golang:appengine:v1.6.0:golang_appengine/vendor/google.golang.org/appengine \
		golang:crypto:22d7a77e9e5f:golang_crypto/vendor/golang.org/x/crypto \
		golang:image:f03afa92d3ff:golang_image/vendor/golang.org/x/image \
		golang:net:f3200d17e092:golang_net/vendor/golang.org/x/net \
		golang:oauth2:aaccbc9213b0:golang_oauth2/vendor/golang.org/x/oauth2 \
		golang:protobuf:v1.3.1:golang_protobuf/vendor/github.com/golang/protobuf \
		golang:snappy:553a64147049:golang_snappy/vendor/github.com/golang/snappy \
		golang:sync:112230192c58:golang_sync/vendor/golang.org/x/sync \
		golang:sys:3626398d7749:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.3.2:golang_text/vendor/golang.org/x/text \
		golang:time:9d24e82272b4:golang_time/vendor/golang.org/x/time \
		google:go-genproto:c2c4e71fbf69:google_go_genproto/vendor/google.golang.org/genproto \
		googleapis:gax-go:v2.0.4:googleapis_gax_go/vendor/github.com/googleapis/gax-go/v2 \
		googleapis:google-api-go-client:v0.5.0:googleapis_google_api_go_client/vendor/google.golang.org/api \
		googleapis:google-cloud-go:v0.39.0:googleapis_google_cloud_go/vendor/cloud.google.com/go \
		gopherjs:gopherjs:0766667cb4d1:gopherjs_gopherjs/vendor/github.com/gopherjs/gopherjs \
		gopherjs:jquery:3ba2b901425e:gopherjs_jquery/vendor/github.com/gopherjs/jquery \
		gorilla:websocket:v1.4.0:gorilla_websocket/vendor/github.com/gorilla/websocket \
		grpc:grpc-go:v1.21.0:grpc_grpc_go/vendor/google.golang.org/grpc \
		hashicorp:golang-lru:v0.5.1:hashicorp_golang_lru/vendor/github.com/hashicorp/golang-lru \
		hjfreyer:taglib-go:0ef8bba9c41b:hjfreyer_taglib_go/vendor/github.com/hjfreyer/taglib-go \
		jmespath:go-jmespath:0b12d6b521d8:jmespath_go_jmespath/vendor/github.com/jmespath/go-jmespath \
		kr:fs:v0.1.0:kr_fs/vendor/github.com/kr/fs \
		lib:pq:v1.1.1:lib_pq/vendor/github.com/lib/pq \
		mailgun:mailgun-go:17e8bd11e87c:mailgun_mailgun_go/vendor/github.com/mailgun/mailgun-go \
		mattn:go-mastodon:8f6192e26b66:mattn_go_mastodon/vendor/github.com/mattn/go-mastodon \
		mattn:go-sqlite3:v1.6.0:mattn_go_sqlite3/vendor/github.com/mattn/go-sqlite3 \
		miekg:dns:3f1f7c8ec9ea:miekg_dns/vendor/github.com/miekg/dns \
		nf:cr2:05d46fef4f2f:nf_cr2/vendor/github.com/nf/cr2 \
		pkg:errors:v0.8.0:pkg_errors/vendor/github.com/pkg/errors \
		pkg:sftp:5bf2a174b604:pkg_sftp/vendor/github.com/pkg/sftp \
		plaid:plaid-go:02b6af68061b:plaid_plaid_go/vendor/github.com/plaid/plaid-go \
		russross:blackfriday:v2.0.0:russross_blackfriday/vendor/github.com/russross/blackfriday \
		rwcarlsen:goexif:8d986c03457a:rwcarlsen_goexif/vendor/github.com/rwcarlsen/goexif \
		shurcooL:sanitized_anchor_name:11a20b799bf2:shurcool_sanitized_anchor_name/vendor/github.com/shurcooL/sanitized_anchor_name \
		syndtr:goleveldb:db3ee9ee8931:syndtr_goleveldb/vendor/github.com/syndtr/goleveldb \
		tgulacsi:picago:9e1ac2306c70:tgulacsi_picago/vendor/github.com/tgulacsi/picago \
		tomnomnom:linkheader:02ca5825eb80:tomnomnom_linkheader/vendor/github.com/tomnomnom/linkheader
		#	::1d34785eb915:group_name/vendor/rsc.io/pdf
		#	::371fbbdaa898:group_name/vendor/bazil.org/fuse
		#	::v0.1.0:group_name/vendor/rsc.io/qr
GO_TARGET=	${EXES:S/^/.\/cmd\//}

EXES=		pk pk-deploy pk-devimport pk-get pk-mount pk-put

PLIST_FILES=	${EXES:S/^/bin\//}

.include <bsd.port.mk>
