# $FreeBSD$

PORTNAME=	minio-client
PORTVERSION=	${GH_TAGNAME:S/RELEASE.//:S/Z//:S/T/-/:S/-/./g}
CATEGORIES=	www

MAINTAINER=	jhixson@FreeBSD.org
COMMENT=	Replacement for ls, cp, mkdir, diff and rsync commands for filesystems

LICENSE=	APACHE20

BUILD_DEPENDS=	bash:shells/bash

USES=		go:modules

OPTIONS_DEFINE=	MC

MC_DESC=	Install as mc

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MMC}
MC=	mc
.else
MC=	${PORTNAME}
.endif

USE_GITHUB=	yes
GHTAG=		RELEASE.2019-10-09T22-54-57Z
COMMIT_ID=	f93fe1330a3647b1afaff0ed8c188d2897bf391e
GH_TUPLE=	minio:mc:${GHTAG}:DEFAULT \
		cheggaaa:pb:v1.0.28:cheggaaa_pb/vendor/github.com/cheggaaa/pb \
		coreos:etcd:v3.3.12:coreos_etcd/vendor/github.com/coreos/etcd \
		dgrijalva:jwt-go:v3.2.0:dgrijalva_jwt_go/vendor/github.com/dgrijalva/jwt-go \
		dustin:go-humanize:v1.0.0:dustin_go_humanize/vendor/github.com/dustin/go-humanize \
		fatih:color:v1.7.0:fatih_color/vendor/github.com/fatih/color \
		fatih:structs:v1.1.0:fatih_structs/vendor/github.com/fatih/structs \
		go-check:check:788fd7840127:go_check_check/vendor/gopkg.in/check.v1 \
		go-ini:ini:v1.42.0:go_ini_ini/vendor/gopkg.in/ini.v1 \
		go-yaml:yaml:v2.2.2:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		gogo:protobuf:v1.2.1:gogo_protobuf/vendor/github.com/gogo/protobuf \
		golang:crypto:60c769a6c586:golang_crypto/vendor/golang.org/x/crypto \
		golang:net:74dc4d7220e7:golang_net/vendor/golang.org/x/net \
		golang:protobuf:v1.3.1:golang_protobuf/vendor/github.com/golang/protobuf \
		golang:sys:fde4db37ae7a:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.3.2:golang_text/vendor/golang.org/x/text \
		google:go-genproto:5fe7a883aa19:google_go_genproto/vendor/google.golang.org/genproto \
		grpc:grpc-go:v1.20.1:grpc_grpc_go/vendor/google.golang.org/grpc \
		h2non:filetype:v1.0.5:h2non_filetype/vendor/gopkg.in/h2non/filetype.v1 \
		hashicorp:errwrap:v1.0.0:hashicorp_errwrap/vendor/github.com/hashicorp/errwrap \
		hashicorp:go-multierror:v1.0.0:hashicorp_go_multierror/vendor/github.com/hashicorp/go-multierror \
		howeyc:gopass:bf9dde6d0d2c:howeyc_gopass/vendor/github.com/howeyc/gopass \
		inconshreveable:go-update:8152e7eb6ccf:inconshreveable_go_update/vendor/github.com/inconshreveable/go-update \
		kr:pretty:v0.1.0:kr_pretty/vendor/github.com/kr/pretty \
		kr:text:v0.1.0:kr_text/vendor/github.com/kr/text \
		mattn:go-colorable:v0.1.1:mattn_go_colorable/vendor/github.com/mattn/go-colorable \
		mattn:go-isatty:v0.0.7:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		mattn:go-runewidth:v0.0.4:mattn_go_runewidth/vendor/github.com/mattn/go-runewidth \
		minio:cli:v1.22.0:minio_cli/vendor/github.com/minio/cli \
		minio:minio-go:v6.0.38:minio_minio_go/vendor/github.com/minio/minio-go/v6 \
		minio:minio:1c5b05c130fa:minio_minio/vendor/github.com/minio/minio \
		minio:sha256-simd:v0.1.1:minio_sha256_simd/vendor/github.com/minio/sha256-simd \
		minio:sio:v0.2.0:minio_sio/vendor/github.com/minio/sio \
		mitchellh:go-homedir:v1.1.0:mitchellh_go_homedir/vendor/github.com/mitchellh/go-homedir \
		ncw:directio:v1.0.5:ncw_directio/vendor/github.com/ncw/directio \
		pkg:profile:v1.3.0:pkg_profile/vendor/github.com/pkg/profile \
		pkg:xattr:v0.4.1:pkg_xattr/vendor/github.com/pkg/xattr \
		posener:complete:6ffe496ea953:posener_complete/vendor/github.com/posener/complete \
		rjeczalik:notify:v0.9.2:rjeczalik_notify/vendor/github.com/rjeczalik/notify \
		segmentio:go-prompt:f0d19b6901ad:segmentio_go_prompt/vendor/github.com/segmentio/go-prompt \
		tidwall:gjson:v1.2.1:tidwall_gjson/vendor/github.com/tidwall/gjson \
		tidwall:match:v1.0.1:tidwall_match/vendor/github.com/tidwall/match \
		tidwall:pretty:v1.0.0:tidwall_pretty/vendor/github.com/tidwall/pretty

PLIST_FILES=	bin/${MC}
GO_BUILDFLAGS=	--ldflags='\
		-X github.com/minio/mc/cmd.Version=${GH_TAGNAME:C/RELEASE\.//:C|(..)-(..)-(..)Z|\1:\2:\3Z|} \
		-X github.com/minio/mc/cmd.ReleaseTag=${GH_TAGNAME} \
		-X github.com/minio/mc/cmd.CommitID=${COMMIT_ID} \
		-X github.com/minio/mc/cmd.GOPATH=${WRKSRC} -s -w'
GO_TARGET=	:${MC}

.include <bsd.port.mk>
