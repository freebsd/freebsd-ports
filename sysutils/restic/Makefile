# $FreeBSD$

PORTNAME=	restic
DISTVERSIONPREFIX=	v
DISTVERSION=	0.12.0
CATEGORIES=	sysutils
MASTER_SITES=	https://github.com/restic/restic/releases/download/${DISTVERSIONPREFIX}${DISTVERSION}/
DISTNAME=	${PORTNAME}-${DISTVERSION}

MAINTAINER=	gregf@beastie.tech
COMMENT=	Fast, secure, efficient backup program

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
USE_GITHUB=	yes
GH_TUPLE=	\
		Azure:azure-sdk-for-go:v46.1.0:azure_azure_sdk_for_go/vendor/github.com/Azure/azure-sdk-for-go \
		Azure:go-autorest:9d0c31cec0a7:azure_go_autorest_adal \
		Azure:go-autorest:autorest/v0.11.6:azure_go_autorest_autorest \
		Azure:go-autorest:b3a0b30a7423:azure_go_autorest_date \
		Azure:go-autorest:logger/v0.2.0:azure_go_autorest_logger \
		Azure:go-autorest:tracing/v0.6.0:azure_go_autorest_tracing \
		Azure:go-autorest:v14.2.0:azure_go_autorest/vendor/github.com/Azure/go-autorest \
		bazil:fuse:5883e5a4b512:bazil_fuse/vendor/bazil.org/fuse \
		cenkalti:backoff:v4.0.2:cenkalti_backoff_v4/vendor/github.com/cenkalti/backoff/v4 \
		census-instrumentation:opencensus-go:v0.22.4:census_instrumentation_opencensus_go/vendor/go.opencensus.io \
		cespare:xxhash:v2.1.1:cespare_xxhash_v2/vendor/github.com/cespare/xxhash/v2 \
		cpuguy83:go-md2man:v1.0.10:cpuguy83_go_md2man/vendor/github.com/cpuguy83/go-md2man \
		dchest:siphash:v1.2.2:dchest_siphash/vendor/github.com/dchest/siphash \
		dgrijalva:jwt-go:v3.2.0:dgrijalva_jwt_go/vendor/github.com/dgrijalva/jwt-go \
		elithrar:simple-scrypt:v1.3.0:elithrar_simple_scrypt/vendor/github.com/elithrar/simple-scrypt \
		go-ini:ini:v1.61.0:go_ini_ini/vendor/gopkg.in/ini.v1 \
		go-ole:go-ole:v1.2.4:go_ole_go_ole/vendor/github.com/go-ole/go-ole \
		go-tomb:tomb:d5d1b5820637:go_tomb_tomb/vendor/gopkg.in/tomb.v2 \
		go-yaml:yaml:v2.3.0:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		golang:appengine:v1.6.6:golang_appengine/vendor/google.golang.org/appengine \
		golang:crypto:5c72a883971a:golang_crypto/vendor/golang.org/x/crypto \
		golang:groupcache:8c9f03a8e57e:golang_groupcache/vendor/github.com/golang/groupcache \
		golang:lint:738671d3881b:golang_lint/vendor/golang.org/x/lint \
		golang:mod:v0.3.0:golang_mod/vendor/golang.org/x/mod \
		golang:net:62affa334b73:golang_net/vendor/golang.org/x/net \
		golang:oauth2:5d25da1a8d43:golang_oauth2/vendor/golang.org/x/oauth2 \
		golang:protobuf:v1.4.2:golang_protobuf/vendor/github.com/golang/protobuf \
		golang:sync:6e8e738ad208:golang_sync/vendor/golang.org/x/sync \
		golang:sys:da207088b7d1:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.3.4:golang_text/vendor/golang.org/x/text \
		golang:tools:d647fc253266:golang_tools/vendor/golang.org/x/tools \
		golang:xerrors:5ec99f83aff1:golang_xerrors/vendor/golang.org/x/xerrors \
		google:go-cmp:v0.5.2:google_go_cmp/vendor/github.com/google/go-cmp \
		google:go-genproto:7abf4a1a14d5:google_go_genproto/vendor/google.golang.org/genproto \
		google:uuid:v1.1.2:google_uuid/vendor/github.com/google/uuid \
		googleapis:gax-go:v2.0.5:googleapis_gax_go_v2/vendor/github.com/googleapis/gax-go \
		googleapis:google-api-go-client:v0.32.0:googleapis_google_api_go_client/vendor/google.golang.org/api \
		googleapis:google-cloud-go:storage/v1.12.0:googleapis_google_cloud_go_storage \
		googleapis:google-cloud-go:v0.66.0:googleapis_google_cloud_go/vendor/cloud.google.com/go \
		grpc:grpc-go:v1.32.0:grpc_grpc_go/vendor/google.golang.org/grpc \
		hashicorp:golang-lru:v0.5.4:hashicorp_golang_lru/vendor/github.com/hashicorp/golang-lru \
		inconshreveable:mousetrap:v1.0.0:inconshreveable_mousetrap/vendor/github.com/inconshreveable/mousetrap \
		json-iterator:go:v1.1.10:json_iterator_go/vendor/github.com/json-iterator/go \
		jstemmer:go-junit-report:v0.9.1:jstemmer_go_junit_report/vendor/github.com/jstemmer/go-junit-report \
		juju:ratelimit:v1.0.1:juju_ratelimit/vendor/github.com/juju/ratelimit \
		klauspost:cpuid:v1.3.1:klauspost_cpuid/vendor/github.com/klauspost/cpuid \
		kr:fs:v0.1.0:kr_fs/vendor/github.com/kr/fs \
		kurin:blazer:v0.5.3:kurin_blazer/vendor/github.com/kurin/blazer \
		minio:md5-simd:v1.1.0:minio_md5_simd/vendor/github.com/minio/md5-simd \
		minio:minio-go:v7.0.5:minio_minio_go_v7/vendor/github.com/minio/minio-go/v7 \
		minio:sha256-simd:v0.1.1:minio_sha256_simd/vendor/github.com/minio/sha256-simd \
		mitchellh:go-homedir:v1.1.0:mitchellh_go_homedir/vendor/github.com/mitchellh/go-homedir \
		modern-go:concurrent:bacd9c7ef1dd:modern_go_concurrent/vendor/github.com/modern-go/concurrent \
		modern-go:reflect2:v1.0.1:modern_go_reflect2/vendor/github.com/modern-go/reflect2 \
		ncw:swift:v1.0.52:ncw_swift/vendor/github.com/ncw/swift \
		pkg:errors:v0.9.1:pkg_errors/vendor/github.com/pkg/errors \
		pkg:profile:v1.5.0:pkg_profile/vendor/github.com/pkg/profile \
		pkg:sftp:v1.12.0:pkg_sftp/vendor/github.com/pkg/sftp \
		pkg:xattr:v0.4.2:pkg_xattr/vendor/github.com/pkg/xattr \
		protocolbuffers:protobuf-go:v1.25.0:protocolbuffers_protobuf_go/vendor/google.golang.org/protobuf \
		restic:chunker:v0.4.0:restic_chunker/vendor/github.com/restic/chunker \
		rs:xid:v1.2.1:rs_xid/vendor/github.com/rs/xid \
		russross:blackfriday:v1.5.2:russross_blackfriday/vendor/github.com/russross/blackfriday \
		satori:go.uuid:v1.2.0:satori_go_uuid/vendor/github.com/satori/go.uuid \
		spf13:cobra:v0.0.5:spf13_cobra/vendor/github.com/spf13/cobra \
		spf13:pflag:v1.0.5:spf13_pflag/vendor/github.com/spf13/pflag

GO_TARGET=	./cmd/${PORTNAME}

PLIST_SUB=	PORTNAME=${PORTNAME}

post-extract:
	@${RM} -r ${WRKSRC}/vendor/cloud.google.com/go/storage
	@${RLN} ${WRKSRC_googleapis_google_cloud_go_storage}/storage ${WRKSRC}/vendor/cloud.google.com/go/storage
	@${RM} -r ${WRKSRC}/vendor/github.com/Azure/go-autorest/autorest
	@${RLN} ${WRKSRC_azure_go_autorest_autorest}/autorest ${WRKSRC}/vendor/github.com/Azure/go-autorest/autorest
	@${RM} -r ${WRKSRC}/vendor/github.com/Azure/go-autorest/autorest/adal
	@${RLN} ${WRKSRC_azure_go_autorest_adal}/autorest/adal ${WRKSRC}/vendor/github.com/Azure/go-autorest/autorest/adal
	@${RM} -r ${WRKSRC}/vendor/github.com/Azure/go-autorest/autorest/date
	@${RLN} ${WRKSRC_azure_go_autorest_date}/autorest/date ${WRKSRC}/vendor/github.com/Azure/go-autorest/autorest/date
	@${RM} -r ${WRKSRC}/vendor/github.com/Azure/go-autorest/logger
	@${RLN} ${WRKSRC_azure_go_autorest_logger}/logger ${WRKSRC}/vendor/github.com/Azure/go-autorest/logger
	@${RM} -r ${WRKSRC}/vendor/github.com/Azure/go-autorest/tracing
	@${RLN} ${WRKSRC_azure_go_autorest_tracing}/tracing ${WRKSRC}/vendor/github.com/Azure/go-autorest/tracing

post-install:
	${INSTALL_MAN} ${WRKSRC}/doc/man/* ${STAGEDIR}${MANPREFIX}/man/man1
	${INSTALL} -d ${STAGEDIR}${PREFIX}/etc/bash_completion.d/
	${INSTALL_SCRIPT} ${WRKSRC}/doc/bash-completion.sh \
		${STAGEDIR}${PREFIX}/etc/bash_completion.d/${PORTNAME}.sh
	${INSTALL} -d ${STAGEDIR}${PREFIX}/share/zsh/site-functions/
	${INSTALL_DATA} ${WRKSRC}/doc/zsh-completion.zsh \
		${STAGEDIR}${PREFIX}/share/zsh/site-functions/_${PORTNAME}

.include <bsd.port.mk>
