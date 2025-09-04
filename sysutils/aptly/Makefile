PORTNAME=	aptly
PORTVERSION=	1.5.0
DISTVERSIONPREFIX=v
PORTREVISION=	28
CATEGORIES=	sysutils

MAINTAINER=	romain@FreeBSD.org
COMMENT=	Debian repository management tool
WWW=		https://www.aptly.info/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

USE_GITHUB=	yes
GH_ACCOUNT=	aptly-dev

PLIST_FILES=	bin/aptly

GH_TUPLE=	\
		AlekSi:pointer:v1.0.0:aleksi_pointer/vendor/github.com/AlekSi/pointer \
		Azure:azure-pipeline-go:v0.2.3:azure_azure_pipeline_go/vendor/github.com/Azure/azure-pipeline-go \
		Azure:azure-storage-blob-go:v0.15.0:azure_azure_storage_blob_go/vendor/github.com/Azure/azure-storage-blob-go \
		DisposaBoy:JsonConfigReader:33a99fdf1d5e:disposaboy_jsonconfigreader/vendor/github.com/DisposaBoy/JsonConfigReader \
		awalterschulze:gographviz:761fd5fbb34e:awalterschulze_gographviz/vendor/github.com/awalterschulze/gographviz \
		aws:aws-sdk-go:v1.25.0:aws_aws_sdk_go/vendor/github.com/aws/aws-sdk-go \
		beorn7:perks:v1.0.1:beorn7_perks/vendor/github.com/beorn7/perks \
		cavaliergopher:grab:v3.0.1:cavaliergopher_grab_v3/vendor/github.com/cavaliergopher/grab \
		cespare:xxhash:v2.1.2:cespare_xxhash_v2/vendor/github.com/cespare/xxhash/v2 \
		cheggaaa:pb:v1.0.10:cheggaaa_pb/vendor/github.com/cheggaaa/pb \
		cheggaaa:pb:v1.0.28:cheggaaa_pb_1/vendor/gopkg.in/cheggaaa/pb.v1 \
		fatih:color:v1.7.0:fatih_color/vendor/github.com/fatih/color \
		gin-contrib:sse:v0.1.0:gin_contrib_sse/vendor/github.com/gin-contrib/sse \
		gin-gonic:gin:v1.7.7:gin_gonic_gin/vendor/github.com/gin-gonic/gin \
		go-check:check:10cb98267c6c:go_check_check/vendor/gopkg.in/check.v1 \
		go-playground:locales:v0.14.0:go_playground_locales/vendor/github.com/go-playground/locales \
		go-playground:universal-translator:v0.18.0:go_playground_universal_translator/vendor/github.com/go-playground/universal-translator \
		go-playground:validator:v10.10.1:go_playground_validator_v10/vendor/github.com/go-playground/validator/v10 \
		go-yaml:yaml:v2.4.0:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		golang:crypto:ae2d96664a29:golang_crypto/vendor/golang.org/x/crypto \
		golang:net:69e39bad7dc2:golang_net/vendor/golang.org/x/net \
		golang:protobuf:v1.5.2:golang_protobuf/vendor/github.com/golang/protobuf \
		golang:snappy:v0.0.1:golang_snappy/vendor/github.com/golang/snappy \
		golang:sys:v0.6.0:golang_sys/vendor/golang.org/x/sys \
		golang:term:7de9c90e9dd1:golang_term/vendor/golang.org/x/term \
		golang:text:v0.3.7:golang_text/vendor/golang.org/x/text \
		golang:time:f0f3c7e86c11:golang_time/vendor/golang.org/x/time \
		google:uuid:v1.2.0:google_uuid/vendor/github.com/google/uuid \
		h2non:filetype:v1.0.1:h2non_filetype_1/vendor/gopkg.in/h2non/filetype.v1 \
		h2non:filetype:v1.0.5:h2non_filetype/vendor/github.com/h2non/filetype \
		jlaffaye:ftp:2403248fa8cc:jlaffaye_ftp/vendor/github.com/jlaffaye/ftp \
		jmespath:go-jmespath:c2b33e8439af:jmespath_go_jmespath/vendor/github.com/jmespath/go-jmespath \
		json-iterator:go:v1.1.12:json_iterator_go/vendor/github.com/json-iterator/go \
		kjk:lzma:3fd93898850d:kjk_lzma/vendor/github.com/kjk/lzma \
		klauspost:compress:v1.13.6:klauspost_compress/vendor/github.com/klauspost/compress \
		klauspost:pgzip:v1.2.5:klauspost_pgzip/vendor/github.com/klauspost/pgzip \
		kr:pretty:v0.3.0:kr_pretty/vendor/github.com/kr/pretty \
		kr:text:v0.2.0:kr_text/vendor/github.com/kr/text \
		leodido:go-urn:v1.2.1:leodido_go_urn/vendor/github.com/leodido/go-urn \
		mattn:go-colorable:v0.1.2:mattn_go_colorable/vendor/github.com/mattn/go-colorable \
		mattn:go-ieproxy:v0.0.1:mattn_go_ieproxy/vendor/github.com/mattn/go-ieproxy \
		mattn:go-isatty:v0.0.14:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		mattn:go-runewidth:v0.0.2:mattn_go_runewidth/vendor/github.com/mattn/go-runewidth \
		mattn:go-shellwords:v1.0.2:mattn_go_shellwords/vendor/github.com/mattn/go-shellwords \
		matttproud:golang_protobuf_extensions:v1.0.1:matttproud_golang_protobuf_extensions/vendor/github.com/matttproud/golang_protobuf_extensions \
		mkrautz:goar:282caa8bd9da:mkrautz_goar/vendor/github.com/mkrautz/goar \
		modern-go:concurrent:bacd9c7ef1dd:modern_go_concurrent/vendor/github.com/modern-go/concurrent \
		modern-go:reflect2:v1.0.2:modern_go_reflect2/vendor/github.com/modern-go/reflect2 \
		mxk:go-flowrate:cca7078d478f:mxk_go_flowrate/vendor/github.com/mxk/go-flowrate \
		ncw:swift:v1.0.30:ncw_swift/vendor/github.com/ncw/swift \
		pborman:uuid:c65b2f87fee3:pborman_uuid/vendor/github.com/pborman/uuid \
		pkg:errors:v0.9.1:pkg_errors/vendor/github.com/pkg/errors \
		prometheus:client_golang:v1.12.1:prometheus_client_golang/vendor/github.com/prometheus/client_golang \
		prometheus:client_model:v0.2.0:prometheus_client_model/vendor/github.com/prometheus/client_model \
		prometheus:common:v0.32.1:prometheus_common/vendor/github.com/prometheus/common \
		prometheus:procfs:v0.7.3:prometheus_procfs/vendor/github.com/prometheus/procfs \
		protocolbuffers:protobuf-go:v1.28.0:protocolbuffers_protobuf_go/vendor/google.golang.org/protobuf \
		rogpeppe:go-internal:v1.8.0:rogpeppe_go_internal/vendor/github.com/rogpeppe/go-internal \
		smartystreets:gunit:v1.0.4:smartystreets_gunit/vendor/github.com/smartystreets/gunit \
		smira:commander:f408b00e68d5:smira_commander/vendor/github.com/smira/commander \
		smira:flag:695ea5e84e76:smira_flag/vendor/github.com/smira/flag \
		smira:go-aws-auth:8b73995fd8d1:smira_go_aws_auth/vendor/github.com/smira/go-aws-auth \
		smira:go-ftp-protocol:066b75c2b70d:smira_go_ftp_protocol/vendor/github.com/smira/go-ftp-protocol \
		smira:go-xz:0c531f070014:smira_go_xz/vendor/github.com/smira/go-xz \
		syndtr:goleveldb:758128399b1d:syndtr_goleveldb/vendor/github.com/syndtr/goleveldb \
		ugorji:go:v1.2.7:ugorji_go_codec/vendor/github.com/ugorji/go \
		wsxiaoys:terminal:0940f3fc43a0:wsxiaoys_terminal/vendor/github.com/wsxiaoys/terminal

.include <bsd.port.mk>
