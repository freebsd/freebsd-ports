PORTNAME=	drive
PORTVERSION=	0.4.0
DISTVERSIONPREFIX=	v
PORTREVISION=	31
CATEGORIES=	net

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Tiny program to pull or push Google Drive files
WWW=		https://github.com/odeke-em/drive

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go

GO_PKGNAME=	github.com/odeke-em/drive
GO_TARGET=	github.com/odeke-em/drive/cmd/drive

PLIST_FILES=	bin/drive

USE_GITHUB=	yes
GH_ACCOUNT=	odeke-em
GH_TUPLE=	boltdb:bolt:v1.3.1:boltdb_bolt/vendor/github.com/boltdb/bolt \
		census-instrumentation:opencensus-go:v0.24.0:census_instrumentation_opencensus/vendor/go.opencensus.io \
		cheggaaa:pb:v3.1.5:cheggaaa_pb/vendor/github.com/cheggaaa/pb \
		felixge:httpsnoop:v1.0.4:felixge_httpsnoop/vendor/github.com/felixge/httpsnoop \
		go-logr:logr:v1.4.2:go_logr_logr/vendor/github.com/go-logr/logr \
		go-logr:stdr:v1.2.2:go_logr_stdr/vendor/github.com/go-logr/stdr \
		golang:crypto:v0.25.0:golang_crypto/vendor/golang.org/x/crypto \
		golang:groupcache:41bb18b:golang_groupcache/vendor/github.com/golang/groupcache \
		golang:net:v0.27.0:golang_net/vendor/golang.org/x/net \
		golang:oauth2:v0.21.0:golang_oauth2/vendor/golang.org/x/oauth2 \
		golang:protobuf:v1.5.4:golang_protobuf/vendor/github.com/golang/protobuf \
		golang:sys:v0.22.0:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.16.0:golang_text/vendor/golang.org/x/text \
		google:go-genproto:e6d459c:google_go_genproto/vendor/google.golang.org/genproto \
		google:s2a-go:v0.1.8:google_s2a_go/vendor/github.com/google/s2a-go \
		google:uuid:v1.6.0:google_uuid/vendor/github.com/google/uuid \
		googleapis:enterprise-certificate-proxy:v0.3.2:googleapis_enterprise_certificate_proxy/vendor/github.com/googleapis/enterprise-certificate-proxy \
		googleapis:google-api-go-client:v0.189.0:google_googleapigoclient/vendor/google.golang.org/api \
		googleapis:google-cloud-go:v0.115.0:googleapis_googlecloudgo/vendor/cloud.google.com/go \
		googleapis:gax-go:v2.13.0:googleapis_gaxgo/vendor/github.com/googleapis/gax-go \
		grpc:grpc-go:v1.65.0:grpc_grpc_go/vendor/google.golang.org/grpc \
		mattn:go-isatty:v0.0.20:mattn_goisatty/vendor/github.com/mattn/go-isatty \
		mattn:go-runewidth:v0.0.16:mattn_gorunewidth/vendor/github.com/mattn/go-runewidth \
		mxk:go-flowrate:cca7078:mxk_goflowrate/vendor/github.com/mxk/go-flowrate \
		odeke-em:cache:baf8e43:odekeem_cache/vendor/github.com/odeke-em/cache \
		odeke-em:cli-spinner:610063b:odekeem_clispinner/vendor/github.com/odeke-em/cli-spinner \
		odeke-em:command:91ca5ec:odekeem_command/vendor/github.com/odeke-em/command \
		odeke-em:exponential-backoff:96e25d3:odekeem_exponential_backoff/vendor/github.com/odeke-em/exponential-backoff \
		odeke-em:extractor:801861a:odekeem_extractor/vendor/github.com/odeke-em/extractor \
		odeke-em:go-utils:e8ebaed:odekeem_go_utils/vendor/github.com/odeke-em/go-utils \
		odeke-em:go-uuid:b211d76:odekeem_gouuid/vendor/github.com/odeke-em/go-uuid \
		odeke-em:log:8d60a69:odekeem_log/vendor/github.com/odeke-em/log \
		odeke-em:meddler:d2b51d2:odekeem_meddler/vendor/github.com/odeke-em/meddler \
		odeke-em:namespace:0ab79ba:odekeem_namespace/vendor/github.com/odeke-em/namespace \
		odeke-em:pretty-words:9d37a7f:odekeem_prettywords/vendor/github.com/odeke-em/pretty-words \
		odeke-em:semalim:9c88bf5:odekeem_semalim/vendor/github.com/odeke-em/semalim \
		odeke-em:statos:292960a:odekeem_statos/vendor/github.com/odeke-em/statos \
		open-telemetry:opentelemetry-go:v1.28.0:open_telemetry_opentelemetry_go/vendor/go.opentelemetry.io/otel \
		open-telemetry:opentelemetry-go-contrib:v1.28.0:open_telemetry_opentelemetry_go_contrib/vendor/go.opentelemetry.io/contrib \
		protocolbuffers:protobuf-go:v1.34.2:protocolbuffers_protobuf_go/vendor/google.golang.org/protobuf \
		rivo:uniseg:v0.4.7:rivo_uniseg/vendor/github.com/rivo/uniseg \
		skratchdot:open-golang:eef8423:skratchdot_opengolang/vendor/github.com/skratchdot/open-golang

.include <bsd.port.mk>
