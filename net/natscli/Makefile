PORTNAME=	natscli
PORTVERSION=	0.0.35
PORTREVISION=	1
DISTVERSIONPREFIX=	v
CATEGORIES=	net

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Command line utility to interact with and manage NATS
WWW=		https://github.com/nats-io/natscli

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	nats-io
GH_TUPLE=	AlecAivazis:survey:v2.3.6:alecaivazis_survey_v2/vendor/github.com/AlecAivazis/survey/v2 \
		HdrHistogram:hdrhistogram-go:v1.1.2:hdrhistogram_hdrhistogram_go/vendor/github.com/HdrHistogram/hdrhistogram-go \
		beorn7:perks:v1.0.1:beorn7_perks/vendor/github.com/beorn7/perks \
		cespare:xxhash:v2.1.2:cespare_xxhash_v2/vendor/github.com/cespare/xxhash/v2 \
		choria-io:fisk:v0.2.1:choria_io_fisk/vendor/github.com/choria-io/fisk \
		dustin:go-humanize:v1.0.0:dustin_go_humanize/vendor/github.com/dustin/go-humanize \
		emicklei:dot:v1.0.0:emicklei_dot/vendor/github.com/emicklei/dot \
		fatih:color:v1.13.0:fatih_color/vendor/github.com/fatih/color \
		ghodss:yaml:v1.0.0:ghodss_yaml/vendor/github.com/ghodss/yaml \
		go-yaml:yaml:496545a6307b:go_yaml_yaml_1/vendor/gopkg.in/yaml.v3 \
		go-yaml:yaml:v2.4.0:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		golang:crypto:v0.1.0:golang_crypto/vendor/golang.org/x/crypto \
		golang:protobuf:v1.5.2:golang_protobuf/vendor/github.com/golang/protobuf \
		golang:sys:v0.1.0:golang_sys/vendor/golang.org/x/sys \
		golang:term:v0.1.0:golang_term/vendor/golang.org/x/term \
		golang:text:v0.4.0:golang_text/vendor/golang.org/x/text \
		golang:time:v0.1.0:golang_time/vendor/golang.org/x/time \
		google:go-cmp:v0.5.9:google_go_cmp/vendor/github.com/google/go-cmp \
		gosuri:uilive:v0.0.4:gosuri_uilive/vendor/github.com/gosuri/uilive \
		gosuri:uiprogress:v0.0.1:gosuri_uiprogress/vendor/github.com/gosuri/uiprogress \
		guptarohit:asciigraph:v0.5.5:guptarohit_asciigraph/vendor/github.com/guptarohit/asciigraph \
		kballard:go-shellquote:95032a82bc51:kballard_go_shellquote/vendor/github.com/kballard/go-shellquote \
		klauspost:compress:v1.15.12:klauspost_compress/vendor/github.com/klauspost/compress \
		mattn:go-colorable:v0.1.13:mattn_go_colorable/vendor/github.com/mattn/go-colorable \
		mattn:go-isatty:v0.0.16:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		matttproud:golang_protobuf_extensions:v1.0.1:matttproud_golang_protobuf_extensions/vendor/github.com/matttproud/golang_protobuf_extensions \
		mgutz:ansi:d51e80ef957d:mgutz_ansi/vendor/github.com/mgutz/ansi \
		minio:highwayhash:v1.0.2:minio_highwayhash/vendor/github.com/minio/highwayhash \
		nats-io:jsm.go:v0.0.35:nats_io_jsm_go/vendor/github.com/nats-io/jsm.go \
		nats-io:jwt:v2.3.0:nats_io_jwt_v2/vendor/github.com/nats-io/jwt \
		nats-io:nats-server:v2.9.6:nats_io_nats_server_v2/vendor/github.com/nats-io/nats-server/v2 \
		nats-io:nats.go:v1.19.0:nats_io_nats_go/vendor/github.com/nats-io/nats.go \
		nats-io:nkeys:v0.3.0:nats_io_nkeys/vendor/github.com/nats-io/nkeys \
		nats-io:nuid:v1.0.1:nats_io_nuid/vendor/github.com/nats-io/nuid \
		prometheus:client_golang:v1.13.1:prometheus_client_golang/vendor/github.com/prometheus/client_golang \
		prometheus:client_model:v0.2.0:prometheus_client_model/vendor/github.com/prometheus/client_model \
		prometheus:common:v0.37.0:prometheus_common/vendor/github.com/prometheus/common \
		prometheus:procfs:v0.8.0:prometheus_procfs/vendor/github.com/prometheus/procfs \
		protocolbuffers:protobuf-go:v1.28.1:protocolbuffers_protobuf_go/vendor/google.golang.org/protobuf \
		santhosh-tekuri:jsonschema:v5.0.2:santhosh_tekuri_jsonschema_v5/vendor/github.com/santhosh-tekuri/jsonschema/v5 \
		tylertreat:hdrhistogram-writer:2e440612a39f:tylertreat_hdrhistogram_writer/vendor/github.com/tylertreat/hdrhistogram-writer \
		xlab:tablewriter:80b567a11ad5:xlab_tablewriter/vendor/github.com/xlab/tablewriter

GO_PKGNAME=	github.com/${GH_ACCOUNT}/${PORTNAME}
GO_TARGET=	./nats
GO_BUILDFLAGS=	-buildvcs=false

PLIST_FILES=	bin/nats \
		share/doc/${PORTNAME}/README.md

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
